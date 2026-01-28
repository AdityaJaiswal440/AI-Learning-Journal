#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// PARTITION ALGORITHM (Matches Slide 74 logic exactly)
int partition(int arr[], int beg, int end) {
    // Step 1: Initialize variables
    int left = beg;
    int right = end;
    int loc = beg;
    int flag = 0;

    // Step 2: Repeat while FLAG = 0
    while (flag == 0) {
        
        // Step 3: Scan from right to left
        // "While ARR[LOC] <= ARR[RIGHT] AND LOC != RIGHT"
        while (arr[loc] <= arr[right] && loc != right) {
            right = right - 1;
        }

        // Step 4: Check condition after right scan
        if (loc == right) {
            flag = 1;
        } 
        else if (arr[loc] > arr[right]) {
            swap(&arr[loc], &arr[right]);
            loc = right; // Pivot moves to the right index
        }

        // Step 5: If FLAG is still 0, scan from left to right
        if (flag == 0) {
            // "While ARR[LOC] >= ARR[LEFT] AND LOC != LEFT"
            while (arr[loc] >= arr[left] && loc != left) {
                left = left + 1;
            }

            // Step 6: Check condition after left scan
            if (loc == left) {
                flag = 1;
            } 
            else if (arr[loc] < arr[left]) {
                swap(&arr[loc], &arr[left]);
                loc = left; // Pivot moves to the left index
            }
        }
    }
    
    // Return the final position of the pivot (LOC)
    return loc;
}

// QUICK_SORT ALGORITHM (Matches Slide 74 logic)
void quickSort(int arr[], int beg, int end) {
    // Step 1: Check if BEG < END
    if (beg < end) {
        int loc;
        
        // CALL PARTITION (ARR, BEG, END, LOC)
        // In C, we capture the returned 'loc'
        loc = partition(arr, beg, end);
        
        // CALL QUICKSORT (ARR, BEG, LOC - 1)
        quickSort(arr, beg, loc - 1);
        
        // CALL QUICKSORT (ARR, LOC + 1, END)
        quickSort(arr, loc + 1, end);
    }
    // Step 2: END
}

// Helper function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Test with the array we traced: 76, 239, 140, 28, 52
    int arr[] = {76, 239, 140, 28, 52};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: \n");
    printArray(arr, n);

    // Initial Call: BEG = 0, END = n-1
    quickSort(arr, 0, n - 1);

    printf("\nSorted Array: \n");
    printArray(arr, n);

    return 0;
}