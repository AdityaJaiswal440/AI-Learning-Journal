// void doesn't returns anything.
#include<bits/stdc++.h>
using namespace std;

void printName(string name) {
    cout << "HII !!" << name << endl;
}
void Sum(int a,int b) {
    int sum = a+b;
    cout << sum;
}
void doSomething(string &name) {
    // example of pass by reference, orig. value of parameter passed changes.
    name[1] = 'a';
    cout << name << endl;
}
int main() {
    string name;
    int a, b;
    cin >> name >> a >> b;
    printName(name);
    Sum(a,b);
    int minimum = min(a,b);
    cout <<" " << minimum << endl;
    doSomething(name);
    cout << name<< endl;
    return 0 ;
}
// funcns modularise,increases readibility,
// - use same code multiple times.
// pass by value : original value of the parameter passed doesn't changes, a copy of original value is passed.
// pass by reference : if we want original value to fluctuate as per execution of program.

// arrays always operates on pass by reference.
// string takes more space ,so if not needed use char.
// getline() function takes whole line as a string input.
// string also stores every ch in terms of array.
// .size() used to find size of the string.