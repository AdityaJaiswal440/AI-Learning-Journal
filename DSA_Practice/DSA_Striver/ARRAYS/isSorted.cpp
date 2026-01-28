#include<bits/stdc++.h>
using namespace  std;

int main() {
    int n;
    cin >> n;
    int arr[n];

    for(int i=0;i<n;i++) {
        cout << i <<  " element: ";
        cin >> arr[i];
    }
    cout << endl;

    for(int i=1;i<n;i++) {
        if(arr[i] >= arr[i-1]) {
            
        }
        else {
            cout << "Not Sorted !!" << endl;
            return 0;
        }
    }
    cout << "Sorted!!" << endl ;
    return 0;
}