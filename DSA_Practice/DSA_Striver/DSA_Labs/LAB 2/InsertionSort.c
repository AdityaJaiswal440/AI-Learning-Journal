#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, j, temp;
    int comp_count = 0; 

    for (int key = 1; k < n; k++) {
        temp = arr[key];
        j = key - 1;
        while (j >= 0 && temp < arr[j]) {
            comp_count++; 
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        if (j >= 0) {
            comp_count++;
        }
        arr[j + 1] = temp;

        printf("\n Pass %d: ", k);
        for(int m=0; m<n; m++) {
            printf("%d\t", arr[m]);
        }
    }
    printf("\n\nTotal Comparisons: %d\n", comp_count);
}

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the array elements:\n");
    for(int i=0; i<n; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    printf("\nFinal Sorted Array:\n");
    for(int i=0; i<n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    return 0;
}