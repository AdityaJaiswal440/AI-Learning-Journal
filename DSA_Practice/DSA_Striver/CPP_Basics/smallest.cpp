#include<bits/stdc++.h>
using namespace std;

int Find_Smallest(int arr[],int n) {
    int smallest = INT32_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<smallest){
        smallest = arr[i];
        }
    }
    cout << "Smallest = " << smallest << endl;
}

int main(){
    int n;
    cout << "Enter the size of array : ";
    cin >> n;

    int arr[n];

    for(int i=0;i<n;i++){
        cout << (i+1) << " " << "element : ";
        cin >> arr[i];
        cout << endl;
    }
    Find_Smallest(arr,n);
    return 0;
}