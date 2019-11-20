/*
  EXAMPLE : 10.7 -->
            The left-shift operator can be used to pack two character values into a 2-byte unsigned integer variable.
            Write a program that inputs two characters from the keyboard and passes them to function packCharacters.
            To pack two characters into an unsigned integer variable, assign the first character to the unsigned
            variable, shift the unsigned variable left by 8 bit positions and combine the unsigned variable with the
            second character using the bitwise inclusive-OR operator. The program should output the characters in their
            bit format before and after they are packed into the unsigned integer to prove that the characters are in
            fact packed correctly in the unsigned variable.
*/
#include <iostream>
#include <stdio.h>
using namespace std;

void display_bits( unsigned );
unsigned packet( char, char );

int main(){

    char a, b;
    cout << "enter two char : ";
    cin >> a >> b;

    cout << '\'' << a << '\'' << " in bits as an unsigned integers is:\n";
    display_bits( a );

    cout << "\n"<< '\'' << b << '\'' << " in bits as an unsigned integers is:\n";
    display_bits( b );

    unsigned result = packet( a, b );
    cout << "\n\'" << a << '\'' << " and " << '\'' << b << '\''<< " packed in an unsigned integer:\n";
    display_bits( result );

    return 0;
}

unsigned packet( char x, char y ){
    unsigned pack = x;
    pack <<= 8;
    pack |= y;
    return pack;
}

void display_bits( unsigned value ){
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
