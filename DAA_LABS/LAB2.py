import random
import time
import sys
import matplotlib.pyplot as plt

# Increase recursion depth for Quick Sort and Merge Sort on large datasets
sys.setrecursionlimit(2000000)

# --- QUICK SORT ---
def quick_sort_recursive(arr):
    def _quick_sort(items, low, high):
        if low < high:
            p = partition(items, low, high)
            _quick_sort(items, low, p - 1)
            _quick_sort(items, p + 1, high)

    def partition(items, low, high):
        pivot = items[high]
        i = low - 1
        for j in range(low, high):
            if items[j] <= pivot:
                i += 1
                items[i], items[j] = items[j], items[i]
        items[i + 1], items[high] = items[high], items[i + 1]
        return i + 1

    a = arr.copy()
    if len(a) > 0:
        _quick_sort(a, 0, len(a) - 1)
    return a

def quick_sort_iterative(arr):
    a = arr.copy()
    if len(a) <= 1: return a
    stack = [(0, len(a) - 1)]
    while stack:
        low, high = stack.pop()
        if low < high:
            pivot = a[high]
            i = low - 1
            for j in range(low, high):
                if a[j] <= pivot:
                    i += 1
                    a[i], a[j] = a[j], a[i]
            a[i + 1], a[high] = a[high], a[i + 1]
            p = i + 1
            stack.append((low, p - 1))
            stack.append((p + 1, high))
    return a

# --- MERGE SORT ---
def merge_sort_recursive(arr):
    if len(arr) <= 1: return arr
    mid = len(arr) // 2
    left = merge_sort_recursive(arr[:mid])
    right = merge_sort_recursive(arr[mid:])
    
    res, i, j = [], 0, 0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            res.append(left[i]); i += 1
        else:
            res.append(right[j]); j += 1
    res.extend(left[i:]); res.extend(right[j:])
    return res

def merge_sort_iterative(arr):
    a = arr.copy()
    n = len(a)
    curr_size = 1
    while curr_size < n:
        for left in range(0, n, 2 * curr_size):
            mid = min(left + curr_size, n)
            right = min(left + 2 * curr_size, n)
            l_part, r_part = a[left:mid], a[mid:right]
            i = j = 0
            for k in range(left, right):
                if i < len(l_part) and (j >= len(r_part) or l_part[i] <= r_part[j]):
                    a[k] = l_part[i]; i += 1
                else:
                    a[k] = r_part[j]; j += 1
        curr_size *= 2
    return a

# --- BINARY SEARCH ---
def binary_search_recursive(arr, target, low, high):
    if low > high: return -1
    mid = (low + high) // 2
    if arr[mid] == target: return mid
    elif arr[mid] > target: return binary_search_recursive(arr, target, low, mid - 1)
    else: return binary_search_recursive(arr, target, mid + 1, high)

def binary_search_iterative(arr, target):
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target: return mid
        elif arr[mid] < target: low = mid + 1
        else: high = mid - 1
    return -1

# --- EXPERIMENTAL SETUP ---
sizes = [10, 100, 1000, 10000, 100000, 1000000,10000000]
sort_results = {name: [] for name in ["Quick Rec", "Quick Iter", "Merge Rec", "Merge Iter"]}
search_results = {name: [] for name in ["Binary Rec", "Binary Iter"]}

print(f"{'Size':<10} | {'Algorithm':<12} | {'Time (s)':<10}")
print("-" * 40)

for size in sizes:
    # Generate random array for sorting
    base_array = [random.randint(1, size * 10) for _ in range(size)]
    
    # Sorting Tasks
    sorting_algos = [
        ("Quick Rec", quick_sort_recursive),
        ("Quick Iter", quick_sort_iterative),
        ("Merge Rec", merge_sort_recursive),
        ("Merge Iter", merge_sort_iterative)
    ]
    
    last_sorted = []
    for name, func in sorting_algos:
        start = time.perf_counter()
        last_sorted = func(base_array)
        duration = time.perf_counter() - start
        sort_results[name].append(duration)
        print(f"{size:<10} | {name:<12} | {duration:.6f}")

    # Searching Tasks (using the last sorted array)
    target = random.choice(last_sorted)
    
    start = time.perf_counter()
    binary_search_recursive(last_sorted, target, 0, len(last_sorted)-1)
    search_results["Binary Rec"].append(time.perf_counter() - start)
    
    start = time.perf_counter()
    binary_search_iterative(last_sorted, target)
    search_results["Binary Iter"].append(time.perf_counter() - start)

# --- VISUALIZATION ---
plt.figure(figsize=(15, 6))

# Plot 1: Sorting Performance (Log-Log Scale)
plt.subplot(1, 2, 1)
for algo, times in sort_results.items():
    plt.plot(sizes, times, label=algo, marker='o')
plt.xscale('log')
plt.yscale('log')
plt.title('Sorting Performance (Log-Log Scale)')
plt.xlabel('Array Size (n)')
plt.ylabel('Time (seconds)')
plt.legend()
plt.grid(True, which="both", linestyle="--", alpha=0.6)

# Plot 2: Searching Performance (Log-Linear Scale)
plt.subplot(1, 2, 2)
for algo, times in search_results.items():
    plt.plot(sizes, times, label=algo, marker='x')
plt.xscale('log')
# Time for search is so small that we keep Y linear to see the variations
plt.title('Searching Performance (Log-Linear Scale)')
plt.xlabel('Array Size (n)')
plt.ylabel('Time (seconds)')
plt.legend()
plt.grid(True, which="both", linestyle="--", alpha=0.6)

plt.tight_layout()
plt.savefig("Sorting_Searching_Analysis.png", dpi=300)
plt.show()