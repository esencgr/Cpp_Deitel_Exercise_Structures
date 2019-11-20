/*
  EXAMPLE : 10.12 -->
            Left shifting an unsigned integer by 1 bit is equivalent to multiplying the value by 2.
            Write function power2 that takes two integer arguments number and pow and calculates number * 2pow
            Use a shift operator to calculate the result. The program should print the values as integers and as bits.
*/
#include <iostream>
#include <stdio.h>
using namespace std;

void bits_8( unsigned );
unsigned power_2( unsigned, unsigned );

int main(){

    unsigned base, power, result;
    cout << "enter base and power: ";
    cin >> base >> power;

    cout << "\nbits of base: \n";
    bits_8( base );

    cout << "\nbits of power: \n";
    bits_8( power );

    result = power_2( base, power );

    cout << " \n" <<  base << " * " << "2 ^ " << power << " = " << result << endl;
    bits_8( result );

    return 0;
}
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

unsigned power_2( unsigned val, unsigned p ){
    return ( val << p );
}
