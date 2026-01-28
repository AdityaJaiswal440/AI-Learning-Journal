// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     int hash[123] = {0};
//     // max ASCII value of lowercase 'z' is 122 
//     string s;
//     cout << "Enter the string : ";
//     getline(cin,s);

//     // precompute
//     for(int i=0;i<s.length();i++) {
//         hash[(int)s[i]] += 1;
//     }

//     int q;
//     cout << "How many characters freq you want to check for ..? " ;
//     cin >> q;

//     while(q--) {
//         char c;
//         cout << "Enter the character to be checked : ";
//         cin >> c;
//         cout << "The frequency of the character is : " << hash[(int)c] << endl; 
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cout << "Enter the String" << endl;
    getline(cin,s);

    // precompute - <key,value> pair
    map<char,int> mpp;
    for(int i=0;i<s.length();i++) {
        mpp[s[i]]++ ;
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
        char c;
        cout<<"Enter the char to be checked- ";
        cin >> c;
        cout <<"the frequency of no. is = "<< mpp[c] << endl;
    }
    return 0;
}