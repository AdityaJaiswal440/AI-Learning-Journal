# import random
# import time
# import matplotlib.pyplot as plt

# #SELECTION SORT
# def selection_sort(arr):
#     n = len(arr)
#     passes = comparisons = swaps = 0
#     a = arr.copy()

#     for i in range(n - 1):
#         passes += 1
#         min_index = i
#         for j in range(i + 1, n):
#             comparisons += 1
#             if a[j] < a[min_index]:
#                 min_index = j
#         if min_index != i:
#             a[i], a[min_index] = a[min_index], a[i]
#             swaps += 1

#     return passes, comparisons, swaps


# #BUBBLE SORT
# def bubble_sort(arr):
#     n = len(arr)
#     passes = comparisons = swaps = 0
#     a = arr.copy()

#     for i in range(n):
#         passes += 1
#         for j in range(0, n - i - 1):
#             comparisons += 1
#             if a[j] > a[j + 1]:
#                 a[j], a[j + 1] = a[j + 1], a[j]
#                 swaps += 1

#     return passes, comparisons, swaps


# #INSERTION SORT
# def insertion_sort(arr):
#     n = len(arr)
#     passes = comparisons = swaps = 0
#     a = arr.copy()

#     for i in range(1, n):
#         passes += 1
#         key = a[i]
#         j = i - 1

#         while j >= 0:
#             comparisons += 1
#             if a[j] > key:
#                 a[j + 1] = a[j]
#                 swaps += 1
#                 j -= 1
#             else:
#                 break
#         a[j + 1] = key

#     return passes, comparisons, swaps


# #MAIN PROGRAM
# sizes = [10, 100, 1000, 2000, 3000, 4000,5000,6000,8000, 10000]

# results = {
#     "Selection": {"passes": [], "comparisons": [], "swaps": [], "time": []},
#     "Bubble": {"passes": [], "comparisons": [], "swaps": [], "time": []},
#     "Insertion": {"passes": [], "comparisons": [], "swaps": [], "time": []}
# }

# print("\nSORTING ANALYSIS FOR EACH ARRAY\n")
# print("Array Size | Algorithm  | Passes | Comparisons | Swaps | Time (seconds)")
# print("-" * 75)

# for size in sizes:
#     array = [random.randint(1, size * 10) for _ in range(size)]


#     #Selection Sort
#     start = time.time()
#     p, c, s = selection_sort(array)
#     end = time.time()
#     t = end - start

#     results["Selection"]["passes"].append(p)
#     results["Selection"]["comparisons"].append(c)
#     results["Selection"]["swaps"].append(s)
#     results["Selection"]["time"].append(t)

#     print(f"{size:<10} | Selection | {p:<6} | {c:<11} | {s:<5} | {t:.6f}")

#     #Bubble Sort
#     start = time.time()
#     p, c, s = bubble_sort(array)
#     end = time.time()
#     t = end - start

#     results["Bubble"]["passes"].append(p)
#     results["Bubble"]["comparisons"].append(c)
#     results["Bubble"]["swaps"].append(s)
#     results["Bubble"]["time"].append(t)

#     print(f"{size:<10} | Bubble    | {p:<6} | {c:<11} | {s:<5} | {t:.6f}")

#     #Insertion Sort
#     start = time.time()
#     p, c, s = insertion_sort(array)
#     end = time.time()
#     t = end - start

#     results["Insertion"]["passes"].append(p)
#     results["Insertion"]["comparisons"].append(c)
#     results["Insertion"]["swaps"].append(s)
#     results["Insertion"]["time"].append(t)

#     print(f"{size:<10} | Insertion | {p:<6} | {c:<11} | {s:<5} | {t:.6f}")
#     print("-" * 75)


# #GRAPHS
# def plot_graph(metric, ylabel):
#     plt.figure()
#     for algo in results:
#         plt.plot(sizes, results[algo][metric], label=algo)
#     plt.xlabel("Array Size")
#     plt.ylabel(ylabel)
#     plt.legend()
#     plt.show()


# plot_graph("comparisons", "Number of Comparisons")
# plot_graph("swaps", "Number of Swaps")
# plot_graph("passes", "Number of Passes")
# plot_graph("time", "Time Taken (seconds)")

#include<stdio.h>

int iteration = 0;
int comp_count = 0;
int swaps = 0;

void Selection_Sort(int arr[],int n) {
    iteration++;
    int smallestIdx=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[smallestIdx]){
                smallestIdx = j;
            }comp_count++;
        }
    }
    int temp = arr[i];
    arr[i] = arr[smallestIdx];
    arr[smallestIdx] = temp;

    swaps++;
}

void Bubble_Sort(int arr[], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps++;
            }comp_count++;
        }
    }
}

void Insertion_Sort(int arr[],int n){
    int i,j,temp=0;
    int comp_count = 0;

    for(int key = 1;key<n;k++){
        temp = arr[key];
        j=key-1;
        while(j>=0 && temp < arr[j]) {
            comp_count++;
            arr[j+1] = arr[j];
            j=j-1;
        }
        if(j>=0){
            comp_count++;
        }
        arr[j+1] = temp;
    }
}