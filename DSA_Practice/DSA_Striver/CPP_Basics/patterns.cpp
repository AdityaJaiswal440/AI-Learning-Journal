// outer loops are specifically for lines , and inner loops are particularly for coloumns
// for inner loops, focus on columns and connect them somehow to rows
// print * inside inner for loop
// observe symmetry in patterns.

#include<bits/stdc++.h>
using namespace std;

void printPattern(int n) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<=i;j++) {
                cout << "* ";
            }cout << endl;
    }
}

void pattern3(int n) {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            cout << j << " ";
        }cout << endl;
    }
}

void pattern4(int n) {
    for(int i = 1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            cout << i << " ";
        }
        cout << endl;
    }
}

void pattern5(int n) {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n-i+1;j++) {
            cout << j << " ";
        }cout << endl;
    }
}

// pyramid.
void pattern6(int n) {
    for(int i=0;i<n;i++) {
        // space
        for(int j=0;j<n-i-1;j++) {
            cout << " ";
        }
        // star
        for(int j=0;j<(2*i + 1);j++) {
            cout << "*";
        }
        for(int j=0;j<n-i-1;j++) {
            cout << " ";
        }
        cout << endl;
    }
}
// pattern7 (inv. pyramid)
void pattern7(int n) {
    for(int i=0;i<n;i++) {
        // space
        for(int j=0;j<i;j++) {
            cout << " ";
        }
        // star
        for(int j=0;j<((2*n)-2*i+1);j++) {
            cout << "*";
        }
        // space
        for(int j=0;j<i;j++) {
            cout << " ";
        }
        cout << endl;
    }
}

    void pattern8(int n) {
        for(int i=1;i<=2*n-1;i++) {
            int stars =i;
            if (i>n) stars = 2*n - i;
            for(int j=1;j<=stars;j++) {
                cout << "*" ;
            }
            cout << endl;
        }
    }

// binary pattern
void pattern9(int n) {
    int start =1;
    for(int i=0;i<n;i++) {
    if (i % 2==0) start = 1;
    else start = 0;
    for(int j =0;j<=i;j++) {
        cout << start ;
        start = 1-start;
        }
        cout << endl;
    }
}

void pattern10(int n) {
    for(int i=1;i<=n;i++) {
        for(int j =1;j<=i;j++) {
            cout << j ;
        }cout << endl;
    }
}

// 1234 valley

void pattern11(int n) {
    for(int i=1;i<=n;i++) {
        // no
        for(int j=1;j<=i;j++) {
            cout << j;
        }
        // space
        for(int j=1;j<2*n-(2*i);j++) {
            cout << " ";
        }
        // no.
        for(int j=i;j>=1;j--) {
            cout << j;
        }
        cout << endl;
    }
}

void pattern12(int n) {
    int num =1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=i;j++) {
            cout << num << " " ;
            num++;
        }cout << endl;
    }
}

void pattern13(int n) {
    for(int i=0;i<n;i++) {
        for(char ch='A';ch<='A'+i;ch++) {
            cout << ch << " " ;
        }cout << endl;
    }
}
void pattern14(int n) {
    for(int i=n-1;i>=0;i--) {
        for(char ch ='A';ch<= 'A'+i;ch++) {
            cout << ch << " ";
        }cout << endl;
    }
}

void pattern15(int n) {
    char ch ='A';
    for(int i=0;i<n;i++) {
        for (int j=0;j<=i;j++) {
            cout << ch << " " ;
        }ch++;
        cout << endl;
    }
}
void pattern16(int n) {
    for(int i=0;i<n;i++) {
        // space 
        for(int j=0;j<n-i-1;j++) {
            cout << " ";
        }
        // Char
        char ch = 'A';
        int breakpoint = ((2*i)+ 1)/2;
        for(int j=1;j<=2*i+1;j++) {
            cout << ch ;
            if(j<=breakpoint) ch++;
            else ch--;
        }
        // space
        for(int j=0;j<n-i-1;j++) {
            cout << " ";
        }cout << endl;
    }
}

void pattern17(int n) {
    for(int i=0;i<n;i++) {
        for(char ch='E'- i;ch<='E';ch++) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

void pattern18(int n) {
    int iNiS = 0;
    for(int i=0;i<n;i++) {
        // stars
        for(int j=1;j<=n-i;j++) {
            cout << "*";
        }
        // spaces
        for(int j=0;j<iNiS;j++) {
            cout << " ";
        }
        // stars
        for(int j=1;j<=n-i;j++) {
            cout << "*";
        }
        iNiS+=2;
        cout << endl;
    }
    iNiS = 2*(n-1);
    for(int i=1;i<=n;i++) {
        // stars
        for(int j=1;j<=i;j++) {
            cout << "*";
        }
        // spaces
        for(int j=1;j<=iNiS;j++) {
            cout << " ";
        }
        // stars
        for(int j=1;j<=i;j++) {
            cout << "*";
        }
        iNiS-=2;
        cout << endl;
    }
}

void pattern19(int n) {
    for (int i=1;i<=n;i++) {
        // stars
        for(int j=0;j<i;j++) {
            cout << "*";
        }
        // spaces
        for(int j=0;j<2*(n-i);j++) {
            cout << " ";
        }
        // stars
        for(int j=0;j<i;j++) {
            cout << "*";
        }cout << endl;
    }
    for(int i=1;i<=n;i++) {
        int stars=n-i;
        int spaces = 2*i;
        // stars
        for (int j=0;j<stars;j++) {
            cout << "*";
        }
        // spaces 
        for(int j=0;j<spaces;j++) {
            cout << " ";
        }
        // stars
        for (int j=0;j<stars;j++) {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern20(int n) {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i==2 and (j==2 or j==3)) cout << " ";
            else if (i==3 and (j==2 or j==3)) cout << " ";
            else cout << "*"; 
        }cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    for (int i =0;i<t;i++) {
        int n;
        cin >> n;
        pattern21(n);
    }cout << endl;
}
