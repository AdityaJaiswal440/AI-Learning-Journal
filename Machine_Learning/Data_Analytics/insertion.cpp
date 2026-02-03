#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[10] = {10,20,30,40,50};
    int numToinsert = 60,size=5;

    //insertion at beginning
    for(int i=size-1;i>=0;i--) {
        arr[i+1] = arr[i];
    }

    arr[0]=numToinsert;
    size++;
    
    for(int i=0;i<size;i++) {
        cout << arr[i] << " ";
    }

    return 0;
}