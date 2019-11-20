/*
  EXAMPLE : 10.10 -->
            Write a program that right shifts an integer variable 4 bits.
            The program should print the integer in bits before and after the shift operation.
            Does your system place zeros or ones in the vacated bits?
  EXAMPLE : 10.11 -->
            If your computer uses 4-byte integers, modify the program of Fig. 16.5
            So that it works with 4-byte integers.
*/
#include <iostream>
#include <stdio.h>
using namespace std;

void bits_8( unsigned value ){
    // const int SHIFT = 8 * sizeof( unsigned ) - 1; // Alocated memory of unsigned variable ( 8*4 - 1 = 31 ) ( 8 bit computer )
    // const unsigned mask = 1 << SHIFT;        // 10000000 00000000 00000000 00000000 -- 32 bit
    unsigned mask = 1 << 31;                    // 10000000 00000000 00000000 00000000 -- 32 bit
    cout << value << " = ";
    for (unsigned c = 1; c <= 32; c++){
        cout << ( value & mask ? '1' : '0' );   // AND operators decides of which bits 1 or 0
        value <<= 1;                            // compares for each bit to 01000000.. and shifted version
        if (c % 8 == 0)                         // each 8 bits uncouple.
            cout << ( ' ' );
    }
    cout << endl;
}

void bits_4( unsigned value ){
    const int SHIFT = 4 * sizeof( unsigned ) - 1; // Alocated memory of unsigned variable ( 4*4 - 1 = 15 )( 4bit computer )
    const unsigned mask = 1 << SHIFT;             // 10000000 00000000 00000000 00000000 -- 32 bit
    // unsigned mask = 1 << 15;                   // 10000000 00000000 00000000 00000000 -- 32 bit
    cout << value << " = ";
    for (unsigned c = 1; c <= SHIFT; c++){
        cout << ( value & mask ? '1' : '0' );   // AND operators decides of which bits 1 or 0
        value <<= 1;                            // compares for each bit to 01000000.. and shifted version
        if (c % 4 == 0)                         // each 8 bits uncouple.
            cout << ( ' ' );
    }
    cout << endl;
}

int main(){

    unsigned value_1;
    cout << "enter an int : ";
    cin >> value_1;

    cout << "before 8 bit shifting : ";
    bits_8( value_1 );

    cout << "after 8 bit shifting : ";
    bits_8( value_1 >> 4 );

    unsigned value_2;
    cout << "enter an int : ";
    cin >> value_2;

    cout << "before 4 bit shifting : ";
    bits_4( value_2 );

    cout << "after 4 bit shifting : ";
    bits_4( value_2 >> 4);

    return 0;
}
