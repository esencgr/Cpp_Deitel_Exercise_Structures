#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void bits( unsigned value ){
    unsigned mask = 1 << 31;              // 10000000 00000000 00000000 00000000 -- 32 bit
    cout << value << " = ";

    for (unsigned c = 1; c <= 32; c++){
        putchar( value & mask ? '1' : '0' );  // AND operators decides of which bits 1 or 0
        value <<= 1;                          // compares for each bit to 01000000.. and shifted version
        if (c % 8 == 0)                       // each 8 bits uncouple.
            putchar( ' ' );
    }

    cout << endl;
}

void reverse( unsigned * const vptr ){
     const int SHIFT =  8 * sizeof( unsigned ) - 1;
     const unsigned mask = 1;
     unsigned  value = *vptr;

     for (int i = 0; i <= SHIFT; i++){
         *vptr <<= 1;
         // bits( *vptr );
         *vptr |= ( value & mask );
         // bits( *vptr );
         value >>= 1;
         // bits( value );
         // cout << endl;
     }
}


int main(){
    unsigned a;

    cout << "Enter an unsigned integer: ";
    cin >> a;

    cout << "\nBefore bits are reversed:\n";
    bits( a );
    cout << endl;

    reverse( &a );
    cout << "\nAfter bits are reversed:\n";
    bits( a );

    return 0;
}
