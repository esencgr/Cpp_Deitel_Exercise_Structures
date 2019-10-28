#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct structer{
    int i;          //  +4 byte
    float f;        //  +4 byte
    double d;       //  +8 byte
    char c;         //  +1 byte
    string s;       // +32 byte
};                  //  +7 byte
                    //  total = 56 byte

int main(){

    // total memory allocating of each variables
    cout << "int    -> " << sizeof( int ) << endl;
    cout << "float  -> " << sizeof( float ) << endl;
    cout << "double -> " << sizeof( double ) << endl;
    cout << "char   -> " << sizeof( char ) << endl;
    cout << "string -> " << sizeof( string ) << endl;
    cout << "struct -> " << sizeof( structer )<< endl;

    // new - delete - nullptr for variables

    int *a = new int, *nullptr;         //  allocated 4 bytes memory from RAM
    *a = 100;
    cout << *a << endl;

    delete a;                           //  variable cleared
    a = nullptr;     //  a = 0;
    *a = 200;
    cout << *a << endl;


    // new - delete - nullptr for array

    int size = 3;                       //  array size
    int *array = new int[ size ];       //  allocated 3x4 bytes memory from RAM

    *( array ) = 10;
    *( array + 1 ) = 20;
    *( array + 2 ) = 30;

    for (int i = 0; i < size; i++)
        cout << *( array + i ) << endl;

    delete [ ] array;                   //  array cleared
    array = nullptr;

    for (int i = 0; i < size; i++)
        cout << *( array + i ) << endl;

    return 0;
}
