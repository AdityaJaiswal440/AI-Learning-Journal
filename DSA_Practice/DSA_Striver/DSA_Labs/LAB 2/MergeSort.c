// Merge Sort //
// NOTE:
// a). The user should give input at runtime.
// b). The output should be displayed in the proper format after each iteration and pass.
// c). Display the number of comparisons and number of iterations required to complete the sorting.

// Divide -> Conquer -> Combine Algorithm
// Recurisve Splitting and then combining.

#include<stdio.h>

int comp_count=0,iteration_count=0;

void Merge(int arr[],int beg,int mid,int end,int n) {
    int i=beg,j=mid+1,index=0;
    // j=mid+1 -> first element of 2nd half.
    int k=beg,temp[n];

    // Merging two subarrays

    // Comparing two arrays 
    while(i<=mid && j<=end) {
        comp_count++;
        if(arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        }
        else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copying remaining elements if exists(any)

    while(i<=mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while(j<=end) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copying elements from temp[n] to original array
    for(i=beg;i<=end;i++) {
        arr[i] = temp[i];
    }

    // Printing array after each merge(pass)
    iteration_count++;
    printf("\n After pass %d:\n",iteration_count);
    for(int x=0;x<n;x++) {
        printf("%d\t",arr[x]);
    }

    printf("\n");

}

void Merge_Sort(int arr[],int beg,int end,int n) {
    // Splitting array of size n into n sub-arrays
    if(beg < end) {
        int mid = (beg+end)/2;
        Merge_Sort(arr,beg,mid,n);
        // Sorting left half
        Merge_Sort(arr,mid+1,end,n);
        // sorting right half
        Merge(arr,beg,mid,end,n);
        // combining
    }
}

int main() {
    int n, temp;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int arr[n];

    for(int i=0;i<n;i++){
        printf("Enter the Array element %d:\n",(i+1));
        scanf("%d",&arr[i]);
    }
    printf("\n Unsorted array: \n");
    for(int i=0;i<n;i++) {
        printf("%d\t",arr[i]);
    }
    printf("\n");

    Merge_Sort(arr,0,n-1,n);

    printf("\nFinal Sorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n\nTotal Comparisons: %d", comp_count);
    printf("\nTotal Iterations : %d\n", iteration_count);
    
    return 0;
}
