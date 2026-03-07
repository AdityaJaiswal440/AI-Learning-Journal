#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,number;
    cout << "Enter the size of input array: ";
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cout << "Enter the " << i << " element" << endl;
        cin >> arr[i];
    }

    int hash[13]={0};
    for(int i=0;i<n;i++){
        if(arr[i]<=12){
            hash[arr[i]] += 1;
        }
    }

    cout << "Enter the number you want to check frequency of : " << endl;
    cin >> number;
    
    if(number<=12){
        cout << "Frequency is : " << hash[number] << endl; 
    }
    else {
        cout << "Number exceeds Current hash limit" << endl;
    }

    return 0;
}