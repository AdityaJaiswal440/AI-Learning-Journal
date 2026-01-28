// Binary Searching //
#include<stdio.h>

int main() {
    int n,val,temp,comp_count=0;
    printf("Enter array size :");
    scanf("%d",&n);
    int arr[n];

    printf("Enter the array elements upto : %d\n",n);
    for(int i=0;i<n;i++) {
        printf("Enter the element %d : \t\n",(i+1));
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            // Bubble Sorting in ascending order
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            comp_count++;
        }
        printf("\n Pass %d\n",(i+1));
        for(int i=0;i<n;i++) {
        printf("%d\t",arr[i]);
        }
    }
    
    printf("\n The total no. of comparisons are : %d",comp_count);

    printf("\nSorted array is: ");
    for(int i=0;i<n;i++) {
        printf("%d\t",arr[i]);
    }

    printf("\n Enter value you want to search: \n");
    scanf("%d",&val);


    int mid, beg=0,end=n-1,found=0;
    for(int i=0;i<n;i++) {
        mid=beg+(end-beg)/2;
        if(arr[mid]==val) {
            printf("Value found at index %d \n",mid);
            found = 1;
            break;
        }
        else if(arr[mid] > val) {
            end=mid-1;
        }
        else if(arr[mid] < val) {
            beg = mid+1;
        }
        printf("The mid value is = %d\t for iteration %d\n",arr[mid],i+1);
    }
    if(found == 0) {
        printf("Value not found");
    }
    return 0;
}