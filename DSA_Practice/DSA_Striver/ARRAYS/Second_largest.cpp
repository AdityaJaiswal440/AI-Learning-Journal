#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array : " << endl;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cout << "Enter the "<<i<<"th element : ";
        cin >> arr[i];
        cout << endl;
    }
    
    for(int i=0;i<n;i++) {
        bool isSwap = false;
        for(int j=0;j<n-i-1;j++) {
            if(arr[j]>arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSwap = true;
            }
            if(!isSwap) break;;
            // already sorted array
        }
    }

    cout << "Sorted array : ";
    for(int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }

    int largest = arr[0], second_largest = INT_MIN;
    for(int i=1;i<n;i++) {
        if(arr[i] > largest ) {
            second_largest = largest;
            largest = arr[i];
        }
        else if(arr[i] < largest && arr[i] > second_largest) second_largest = arr[i];
    }
    
    cout << endl << second_largest << " second largest" << endl;

    return 0;
}