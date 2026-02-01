import random
import time
import matplotlib.pyplot as plt


def Selection_Sort(arr):
    n = len(arr)
    a = arr.copy()
    passes = comparisons = swaps = 0
    for i in range(n - 1):
        passes += 1
        smallestIdx = i
        for j in range(i + 1, n):
            comparisons += 1
            if a[j] < a[smallestIdx]:
                smallestIdx = j
        if smallestIdx != i:
            a[i], a[smallestIdx] = a[smallestIdx], a[i]
            swaps += 1
    return passes, comparisons, swaps

def Bubble_Sort(arr):
    n = len(arr)
    a = arr.copy()
    passes = comparisons = swaps = 0
    for i in range(n):
        passes += 1
        for j in range(0, n - i - 1):
            comparisons += 1
            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]
                swaps += 1
    return passes, comparisons, swaps

def Insertion_Sort(arr):
    n = len(arr)
    a = arr.copy()
    passes = comparisons = swaps = 0
    for key_idx in range(1, n):
        passes += 1
        temp = a[key_idx]
        j = key_idx - 1
        while j >= 0:
            comparisons += 1
            if a[j] > temp:
                a[j + 1] = a[j]
                swaps += 1
                j -= 1
            else:
                break
        a[j + 1] = temp
    return passes, comparisons, swaps

sizes = [10, 100, 1000, 2000, 3000, 4000, 5000, 6000, 8000, 10000,11000,12000]
results = {
    "Selection": {"Passes": [], "Comparisons": [], "Swaps": [], "Time": []},
    "Bubble": {"Passes": [], "Comparisons": [], "Swaps": [], "Time": []},
    "Insertion": {"Passes": [], "Comparisons": [], "Swaps": [], "Time": []}
}

print("\nSORTING ANALYSIS FOR EACH ARRAY\n")
print(f"{'Array Size':<10} | {'Algorithm':<10} | {'Passes':<6} | {'Comparisons':<11} | {'Swaps':<6} | {'Time (s)':<8}")
print("-" * 75)

for size in sizes:
    base_array = [random.randint(1, 100000) for _ in range(size)]
    tasks = [("Selection", Selection_Sort), ("Bubble", Bubble_Sort), ("Insertion", Insertion_Sort)]
    
    for name, func in tasks:
        start_time = time.perf_counter()
        p, c, s = func(base_array)
        end_time = time.perf_counter()
        duration = end_time - start_time
        results[name]["Passes"].append(p)
        results[name]["Comparisons"].append(c)
        results[name]["Swaps"].append(s)
        results[name]["Time"].append(duration)
        print(f"{size:<10} | {name:<10} | {p:<6} | {c:<11} | {s:<6} | {duration:.6f}")
    print("-" * 75)

metrics = ['Passes', 'Comparisons', 'Swaps', 'Time']
fig, axes = plt.subplots(2, 2, figsize=(15, 12))
axes = axes.flatten()

for i, metric in enumerate(metrics):
    for algo in results:
        # Avoid plotting 0 in log scale as log(0) is undefined
        # For size 10, some swaps might be very low
        y_data = [val if val > 0 else 1e-9 for val in results[algo][metric]]
        axes[i].plot(sizes, y_data, label=algo, marker='o')
    
    axes[i].set_title(f'{metric} Comparison')
    axes[i].set_xlabel('Array Size (n)')
    axes[i].grid(True, linestyle='--', alpha=0.7)
    
    if metric == 'Swaps':
        axes[i].set_yscale('log')
        axes[i].set_ylabel('Swaps (Log Scale)')
    else:
        axes[i].set_ylabel(metric)
        
    axes[i].legend()

plt.suptitle('DAA Lab 1: Performance Analysis (Log Scale Applied to Swaps)', fontsize=16)
plt.tight_layout(rect=[0, 0.03, 1, 0.95])
plt.show()