#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout <<"Enter the size: ";
    cin >> n;

    int size = n;
    int arr[n];

    for(int i=0;i<n;i++) {
        cout << i << "th element: ";
        cin >> arr[i];
        cout << endl;
    }

    int indTodelete;
    cout << endl << "Enter the index to delete : ";
    cin >> indTodelete;

    cout << endl << "Original array: ";
    for(int i=0;i<n;i++) {
        cout << arr[i] << " ";
    }

    // shifting logic
    for(int i=indTodelete;i<n-1;i++) {
        arr[indTodelete] = arr[indTodelete + 1];
    }
    size--;

    cout << "After deleting element at index: " << indTodelete << endl;
    for(int i=0;i<size;i++) {
        cout << arr[i] << " ";
    }

    cout << endl << "New size :" << size << endl;

    // To show what's left in the full array:
    cout << "Full array's memory (for 5 slots) is now: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;

}