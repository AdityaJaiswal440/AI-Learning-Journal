#include<bits/stdc++.h>
using namespace std;
int main() {
    int marks;
    cin >> marks;
    if(marks>80 and marks <=100) {
        cout << "A";
    }
    else if (marks>60 and marks<=80) {
        cout << "B" ;
    }
    else if (marks>50 and marks <=60) {
        cout << "C" ;
    }
    else if (marks>25 and marks<=50) { 
        cout << "D";
    }
    else {
        cout << "Fail";
    }
    return 0;
}