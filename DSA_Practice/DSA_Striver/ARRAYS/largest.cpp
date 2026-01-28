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

    int largest = arr[0];
    for(int i=1;i<n;i++) {
        if(arr[i] > largest) largest = arr[i];
    }
    cout << largest << " is the largest element" << endl;
    
}