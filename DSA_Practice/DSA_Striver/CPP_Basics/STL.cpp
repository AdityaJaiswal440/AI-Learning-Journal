// Standard Template Library
#include<bits/stdc++.h>
// All the libraries are individually included in this .
using namespace std;

void print() {
    cout << "Aditya";
    cout << endl;
}
// void function doesn't returns anything.

int sum(int a,int b) {
    return a+b;
}

// Pairs
// pairs can be treated as data types,lies inside the utility library.
void explainPair() {
    pair<int, int> p = {7,9};
    cout << p.first << " " << p.second;
    pair<int, pair<int, pair<int, pair<int, int>>>> P = {1,{2,{3,{4,5}}}};
    cout << endl 
    << P.first<< " " 
    << P.second.first <<" " 
    << P.second.second.first << " " 
    << P.second.second.second.first << " "
    << P.second.second.second.second << " ";
    pair < int, int> arr[] = { {3,4},{2,5},{3,8}};
    cout << endl << arr[1].first;
}

// Arryas are constant in size, they can't be modified further executing the program.That's why a new concept vectors came into picture.

// Vector is dynamic in nature, can incrase the size of vector whenever we wish to. So , if we don't know the size of a particular data structure , then we can think of Vector.

void explainVector() {
    vector<int> v;
    v.push_back(1);
    // adds an element at the end of a vector, creates temp obj , then copied into vector.
    v.emplace_back(2);
    // constructs obj directly at the end of vector.
    vector<int> v(5,100);
    // container of size 5 containing 5 instances of 100.
    vector<int> v1(5);
    // container of size 5 with 5 instances of zero.
}

int main() {
    vector<int> v;
    v.push_back(2);
    v.emplace_back(5);
    v.push_back(5,45);

}