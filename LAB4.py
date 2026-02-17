import random
import time
import matplotlib.pyplot as plt
import copy

def manual_insertion_sort_for_bucket(bucket):
    for i in range(1, len(bucket)):
        key = bucket[i]
        j = i - 1
        while j >= 0 and bucket[j] > key:
            bucket[j + 1] = bucket[j]
            j -= 1
        bucket[j + 1] = key

def counting_sort_for_radix(arr, exp):
    n = len(arr)
    output = [0] * n
    count = [0] * 10
    for i in range(n):
        index = (arr[i] // exp) % 10
        count[index] += 1
    for i in range(1, 10):
        count[i] += count[i - 1]
    for i in range(n - 1, -1, -1):
        index = (arr[i] // exp) % 10
        output[count[index] - 1] = arr[i]
        count[index] -= 1
    for i in range(n):
        arr[i] = output[i]

def radix_sort_display(arr):
    max_val = max(arr)
    exp = 1
    while max_val // exp > 0:
        print(f"\nProcessing digit place: {exp}")
        print("Input Array:", arr)
        counting_sort_for_radix(arr, exp)
        print("Array after this pass:", arr)
        exp *= 10

def bucket_sort_display(arr):
    n = len(arr)
    buckets = [[] for _ in range(n)]
    print("\nInput Array:", arr)
    for num in arr:
        index = int(num * n)
        buckets[index].append(num)
        print(f"Inserted {num} into bucket {index}")
    
    for i in range(n):
        manual_insertion_sort_for_bucket(buckets[i])
    
    print("Buckets after internal sorting:", buckets)
    k = 0
    for i in range(n):
        for num in buckets[i]:
            arr[k] = num
            k += 1
    print("Final Sorted Array:", arr)


def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def quick_sort(arr):
    if len(arr) <= 1: return arr
    pivot = arr[len(arr)//2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

def radix_sort(arr):
    if not arr: return
    max_val = max(arr)
    exp = 1
    while max_val // exp > 0:
        counting_sort_for_radix(arr, exp)
        exp *= 10

def bucket_sort(arr):
    n = len(arr)
    buckets = [[] for _ in range(n)]
    for num in arr:
        index = int(num * n)
        buckets[index].append(num)
    for i in range(n):
        manual_insertion_sort_for_bucket(buckets[i])
    k = 0
    for i in range(n):
        for num in buckets[i]:
            arr[k] = num
            k += 1

if __name__ == "__main__":
    print("--- RADIX SORT (Size 10) ---")
    arr_radix = [random.randint(1, 999) for _ in range(10)]
    radix_sort_display(arr_radix)

    print("\n--- BUCKET SORT (Size 10) ---")
    arr_bucket = [random.random() for _ in range(10)]
    bucket_sort_display(arr_bucket)

    sizes = [10, 100, 1000, 10000, 100000]
    radix_t, insertion_t, bucket_t, quick_t = [], [], [], []

    for size in sizes:
        print(f"Profiling size {size}...")
        arr_int = [random.randint(1, 100000) for _ in range(size)]
        arr_float = [random.random() for _ in range(size)]

        c1 = copy.deepcopy(arr_int)
        start = time.time(); radix_sort(c1); radix_t.append(time.time() - start)

        c2 = copy.deepcopy(arr_int)
        start = time.time(); insertion_sort(c2); insertion_t.append(time.time() - start)

        c3 = copy.deepcopy(arr_float)
        start = time.time(); bucket_sort(c3); bucket_t.append(time.time() - start)

        c4 = copy.deepcopy(arr_int)
        start = time.time(); quick_sort(c4); quick_t.append(time.time() - start)

    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(16, 6))

    ax1.plot(sizes, radix_t, label="Radix Sort O(dn)", marker='o', color='blue')
    ax1.plot(sizes, insertion_t, label="Insertion Sort O(n^2)", marker='s', color='orange')
    ax1.set_xscale('log'); ax1.set_yscale('log')
    ax1.set_xlabel("Array Size (n)"); ax1.set_ylabel("Time (seconds)")
    ax1.set_title("Radix Sort vs Insertion Sort")
    ax1.legend(); ax1.grid(True, which="both", linestyle="--")

    ax2.plot(sizes, quick_t, label="Quick Sort O(n log n)", marker='x', color='red')
    ax2.plot(sizes, bucket_t, label="Bucket Sort O(n)", marker='^', color='green')
    ax2.set_xscale('log'); ax2.set_yscale('log')
    ax2.set_xlabel("Array Size (n)"); ax2.set_ylabel("Time (seconds)")
    ax2.set_title("Quick Sort vs Bucket Sort")
    ax2.legend(); ax2.grid(True, which="both", linestyle="--")

    plt.tight_layout()
    plt.show()