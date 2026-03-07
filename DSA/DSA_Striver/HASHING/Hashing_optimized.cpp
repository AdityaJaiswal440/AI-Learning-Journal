// #include<bits/stdc++.h>
// using namespace std;

// int freq_counter(int number, int arr[], int size) {
//     int count=0;
//     for(int i=0;i<size;i++) {
//         if(arr[i] == number) {
//             count += 1;
//         }
//     }
//     return count;
// }

// int main() {
//     int arr[] = {1,3,4,6,4,3,7,9,2};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     for(int i=0;i<n;i++) {
//         cout << "The Frequency of number: " <<arr[i]<<" is = "<< freq_counter(arr[i],arr,n)<< endl;
//     }

// } - Basic approach

// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     cout << "Enter the size of the array :" << endl;
//     cin >> n;

//     int arr[n];
//     for(int i=0;i<n;i++) {
//         cout << "Enter the " << i << "th element : ";
//         cin >> arr[i];
//     }

//     int hash[13] = {0};
//     for(int i=0;i<n;i++) {
//         hash[arr[i]] += 1;
//     }

//     int q;
//     cout << "Enter the no.of element you want to see the frequency of : " ;
//     cin >> q;

//     while(q--) {
//         int number;
//         cout <<"Enter the no. to see the frequency of it : "<< endl;
//         cin >> number;
//         // fetch
//         cout << "The frequency is : ";
//         cout << hash[number] << endl;
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cout << i << "th element : ";
        cin >> arr[i];
    }
    
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++) {
        mpp[arr[i]]++ ;
        // if key is not present, creates the key and maps the value corresponding to it.
    }

    // iterate in the map
    for(auto it: mpp) {
        cout << it.first << "->" << it.second << endl;
    }

    int q;
    cout << "No. of elements to be checked for: ";
    cin >> q;
    while(q--) {
        int number;
        cout<<"Enter the no. to be checked- ";
        cin >> number;
        cout <<"the frequency of no. is = "<< mpp[number] << endl;
    }
    return 0;
} 

// time complexity - takes O(log n) for best,avg and worst cases for an ordered map 
// but for an unordered map,best and avg cases -O(1) , worst case(Sorted sequence)  - O(n)