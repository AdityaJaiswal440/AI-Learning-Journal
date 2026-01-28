#include<stdio.h>
// int main() {
//     int n,val;
//     printf("Enter array size :");
//     scanf("%d",&n);
//     int arr[n];

//     printf("Enter the array elements upto : %d\n",n);
//     for(int i=0;i<n;i++) {
//         printf("Enter the element %d : \t",i);
//         scanf("%d",&arr[i]);
//     }
//     printf("Enter the key value you want to search: ");
//     scanf("%d",&val);

//     for(int i=0;i<n;i++) {
//         if(arr[i] == val) {
//             printf("Value found at index %d\t",i);
//             break;
//         }
//         else {
//             printf("No such value found!!");
//         }
//     }

//     return 0;
// }

int linearSearch(int arr[], int size, int target) {
    for(int i=0;i<size;i++) {
        if(arr[i] == target) {
            return i;
        }
    }
    return -1; // not found 
}

int main() {
    int arr[] = {4,2,1,8,7,5};
    int size = 6;
    int target = 8;

    linearSearch(arr,size,target);
    return 0;
}