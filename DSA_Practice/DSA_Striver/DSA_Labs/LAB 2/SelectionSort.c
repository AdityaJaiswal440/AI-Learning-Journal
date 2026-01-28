// Unstable, notOnline ,Inplace

#include<stdio.h>

int main() {
    int n,temp,comp_count=0,iterations=0;
    printf("Enter size of array : \n");
    scanf("%d",&n);
    int arr[n];

    printf("Enter the array elements upto : %d\n",n);
    for(int i=0;i<n;i++) {
        printf("Enter the element %d : \t\n",(i+1));
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n-1;i++) { 
        iterations++;
        int smallestIdx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[smallestIdx]) {
                smallestIdx = j; 
            }
            comp_count++;
        }
        int temp = arr[i];
        arr[i] = arr[smallestIdx];
        arr[smallestIdx] = temp;

        printf("\nPass %d\n",(i+1));
        for(int j=0;j<n;j++) {
            printf("%d\t",arr[j]);
        }
    }
    printf("\n The Sorted Array is : \n");
    for(int j=0;j<n;j++) {
        printf("%d\t",arr[j]);
    }
    printf("\n The total no. of comparisons are : %d\t",comp_count);
    printf("\n The total no. of iterations are : %d \t",iterations);
}