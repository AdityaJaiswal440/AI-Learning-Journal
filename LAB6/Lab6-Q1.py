import random

def merge_count(arr, left, mid, right):
    temp = []
    i = left
    j = mid + 1
    inv_count = 0



    while i <= mid and j <= right:
        if arr[i] <= arr[j]:
            temp.append(arr[i])
            i += 1
        else:
            temp.append(arr[j])
            inv_count += (mid - i + 1)
            j += 1

    while i <= mid:
        temp.append(arr[i])
        i += 1

    while j <= right:
        temp.append(arr[j])
        j += 1

    for k in range(len(temp)):
        arr[left + k] = temp[k]

    return inv_count


def count_inversions_dc(arr, left, right):
    inv_count = 0
    if left < right:
        mid = (left + right) // 2

        inv_count += count_inversions_dc(arr, left, mid)
        inv_count += count_inversions_dc(arr, mid + 1, right)
        inv_count += merge_count(arr, left, mid, right)

    return inv_count

def insertion_sort_count(arr):
    count = 0
    a = arr[:]

    for i in range(1, len(a)):
        key = a[i]
        j = i - 1

        while j >= 0 and a[j] > key:
            count += 1
            a[j+1] = a[j]
            j -= 1

        if j >= 0:
            count += 1

        a[j+1] = key

    return count


def selection_sort_count(arr):
    count = 0
    a = arr[:]

    n = len(a)
    for i in range(n):
        min_idx = i

        for j in range(i+1, n):
            count += 1
            if a[j] < a[min_idx]:
                min_idx = j

        a[i], a[min_idx] = a[min_idx], a[i]

    return count


def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    count = 0

    for j in range(low, high):
        count += 1
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i+1], arr[high] = arr[high], arr[i+1]

    return i+1, count


def quick_sort_count(arr, low, high):
    count = 0

    if low < high:
        pi, c = partition(arr, low, high)
        count += c

        count += quick_sort_count(arr, low, pi-1)
        count += quick_sort_count(arr, pi+1, high)

    return count

print("Comparison on 10 Random Arrays\n")

for i in range(10):

    arr = random.sample(range(1, 100), 10)
    inv_arr = arr[:]
    inv_count = count_inversions_dc(inv_arr, 0, len(inv_arr)-1)

    ins_count = insertion_sort_count(arr)
    sel_count = selection_sort_count(arr)

    quick_arr = arr[:]
    quick_count = quick_sort_count(quick_arr, 0, len(quick_arr)-1)

    print(f"Array {i+1}: {arr}")
    print(f"Inversions (D&C) : {inv_count}")
    print(f"Insertion Sort   : {ins_count}")
    print(f"Selection Sort   : {sel_count}")
    print(f"Quick Sort       : {quick_count}")
    print("-"*50)