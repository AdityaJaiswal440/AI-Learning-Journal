import random
import time
import matplotlib.pyplot as plt
import copy
import sys

sys.setrecursionlimit(200000)

def max_subarray_brute_force(arr):
    n = len(arr)
    max_sum = -float('inf')
    for i in range(n):
        current_sum = 0
        for j in range(i, n):
            current_sum += arr[j]
            if current_sum > max_sum:
                max_sum = current_sum
    return max_sum


def max_crossing_sum(arr, low, mid, high):
    left_sum = -float('inf')
    sum_temp = 0
    for i in range(mid, low - 1, -1):
        sum_temp += arr[i]
        if sum_temp > left_sum:
            left_sum = sum_temp
            
    right_sum = -float('inf')
    sum_temp = 0
    for i in range(mid + 1, high + 1):
        sum_temp += arr[i]
        if sum_temp > right_sum:
            right_sum = sum_temp
            
    return left_sum + right_sum

def max_subarray_divide_and_conquer(arr, low, high):
    if low == high:
        return arr[low]
    
    mid = (low + high) // 2
    
    return max(
        max_subarray_divide_and_conquer(arr, low, mid),
        max_subarray_divide_and_conquer(arr, mid + 1, high),
        max_crossing_sum(arr, low, mid, high)
    )

if __name__ == "__main__":

    test_arr = [-2, -5, 6, -2, -3, 1, 5, -6]
    print(f"Test Array: {test_arr}")
    print(f"Brute Force Result: {max_subarray_brute_force(test_arr)}")
    print(f"Divide & Conquer Result: {max_subarray_divide_and_conquer(test_arr, 0, len(test_arr)-1)}")


    sizes = [10, 100,1000,10000]
    brute_times = []
    dc_times = []

    for n in sizes:

        arr = [random.randint(-100, 100) for _ in range(n)]

        start = time.time()
        max_subarray_brute_force(arr)
        brute_times.append(time.time() - start)
        
 
        start = time.time()
        max_subarray_divide_and_conquer(arr, 0, len(arr) - 1)
        dc_times.append(time.time() - start)
        
        print(f"Completed size: {n}")


    plt.figure(figsize=(12, 8))
    plt.plot(sizes, brute_times, label="Brute Force O(n^2)", marker='o', color='red')
    plt.plot(sizes, dc_times, label="Divide & Conquer O(n log n)", marker='s', color='blue')
    
    plt.xlabel("Array Size (n)")
    plt.ylabel("Time (seconds)")
    plt.title("Maximum Subarray Solution Comparison")
    plt.xscale('log')
    plt.yscale('log')
    plt.legend()
    plt.grid(True, linestyle="--")
    plt.show()