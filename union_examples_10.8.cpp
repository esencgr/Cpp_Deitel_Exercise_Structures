#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

union integer{
    char c;
    short s;
    int i;
    long l;
};

int main(){

    union integer number;

    cin >> number.c;
    cin >> number.s;
    cin >> number.i;
    cin >> number.l;

    cout << number.c << endl;
    cout << number.s << endl;
    cout << number.i << endl;
    cout << number.l << endl;

    return 0;
}
