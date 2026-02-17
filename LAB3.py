import random

def counting_sort(arr):
    print("Input Array:", arr)

    max_val = max(arr)
    count = [0] * (max_val + 1)
    output = [0] * len(arr)

    print("Initial Auxiliary (Count) Array:", count)


    for i in range(len(arr)):
        count[arr[i]] += 1
        print("Updated Count Array:", count)

 
    for i in range(1, len(count)):
        count[i] += count[i - 1]
        print("Cumulative Count Array:", count)

    
    for i in range(len(arr) - 1, -1, -1):
        output[count[arr[i]] - 1] = arr[i]
        count[arr[i]] -= 1
        print("Output Array:", output)
        print("Auxiliary Array:", count)

    print("Final Sorted Output Array:", output)


arr = [random.randint(0, 9) for _ in range(10)]
counting_sort(arr)


import time
import matplotlib.pyplot as plt

def insertion_sort(arr):
    a = arr.copy()
    for i in range(1, len(a)):
        key = a[i]
        j = i - 1
        while j >= 0 and a[j] > key:
            a[j + 1] = a[j]
            j -= 1
        a[j + 1] = key

def bubble_sort(arr):
    a = arr.copy()
    for i in range(len(a)):
        for j in range(0, len(a) - i - 1):
            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]

def selection_sort(arr):
    a = arr.copy()
    for i in range(len(a)):
        min_idx = i
        for j in range(i + 1, len(a)):
            if a[j] < a[min_idx]:
                min_idx = j
        a[i], a[min_idx] = a[min_idx], a[i]

def counting_sort_simple(arr):
    max_val = max(arr)
    count = [0] * (max_val + 1)
    for num in arr:
        count[num] += 1
    idx = 0
    for i in range(len(count)):
        for _ in range(count[i]):
            arr[idx] = i
            idx += 1


sizes = [10, 100, 1000, 2000, 4000, 8000,10000]

insertion_time = []
bubble_time = []
selection_time = []
counting_time = []

for size in sizes:
    arr = [random.randint(0, 100) for _ in range(size)]

    start = time.time()
    insertion_sort(arr)
    insertion_time.append(time.time() - start)

    start = time.time()
    bubble_sort(arr)
    bubble_time.append(time.time() - start)

    start = time.time()
    selection_sort(arr)
    selection_time.append(time.time() - start)

    start = time.time()
    counting_sort_simple(arr.copy())
    counting_time.append(time.time() - start)


# Graph
plt.figure(figsize=(12, 8))

plt.plot(sizes, insertion_time, label="Insertion Sort")
plt.plot(sizes, bubble_time, label="Bubble Sort")
plt.plot(sizes, selection_time, label="Selection Sort")
plt.plot(sizes, counting_time, label="Counting Sort")


plt.xscale('log')
plt.yscale('log')
plt.xlabel("Array Size(n)")
plt.ylabel("Time (seconds)")
plt.title("Sorting Performance : Linear vs Quadratic")
plt.legend()
plt.grid(True, which="both", linestyle="--", alpha=0.4)
plt.tight_layout()
plt.show()