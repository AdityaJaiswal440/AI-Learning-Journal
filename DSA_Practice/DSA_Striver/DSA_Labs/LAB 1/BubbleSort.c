// Bubble Sorting // 
#include<stdio.h>

int main() {
    int n,temp,comp_count=0;
    printf("Enter array size :");
    scanf("%d",&n);
    int arr[n];

    printf("Enter the array elements upto : %d\n",n);
    for(int i=0;i<n;i++) {
        printf("Enter the element %d : \t\n",(i+1));
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i-1;j++) {
            // Sorting in ascending order
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            comp_count++;
        }
        // Representing array after each pass.
        printf("\n Pass %d\n",(i+1));
        for(int i=0;i<n;i++) {
        printf("%d\t",arr[i]);
        }
    }
    
    printf("\nBubble Sorted array is: \n");
    for(int i=0;i<n;i++) {
        printf("%d\t",arr[i]);
    }
    printf("\n The total no. of comparisons are : %d",comp_count);

    return 0;
}

// Optimized Bubble Sort //
//     for(int i=0;i<n;i++) {
//         int flag = 0; 
//         for(int j=0;j<n-i-1;j++) {
//             // Sorting in ascending order
//             if (arr[j+1] < arr[j]) {
//                 temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//                 flag = 1; 
//             }
//             comp_count++;
//         }
//         // Representing array after each pass.
//         printf("\n Pass %d\n",(i+1));
//         for(int i=0;i<n;i++) {
//         printf("%d\t",arr[i]);
//         }
//     }
//     if(flag = 0) {
//     printf("Array has now become already sorted . Now stopping early at Pass %d\n",(i+1));
//      break;
//     }
    