/*
  EXAMPLE : 10.13 -->
            The left-shift operator can be used to pack two character values into a 2-byte unsigned integer variable.
            Write a program that inputs two characters from the keyboard and passes them to function packCharacters.
            To pack two characters into an unsigned integer variable, assign the first character to the unsigned
            variable, shift the unsigned variable left by 8 bit positions and combine the unsigned variable with the
            second character using the bitwise inclusive-OR operator. The program should output the characters in their
            bit format before and after they are packed into the unsigned integer to prove that the characters are in
            fact packed correctly in the unsigned variable.
  EXAMPLE : 10.14 -->
            Using the right-shift operator, the bitwise AND operator and a mask, write function unpackCharacters that
            takes the unsigned integer from Exercise 16.12 and unpacks it into two characters. To unpack two characters
            from an unsigned 2-byte integer, combine the unsigned integer with the mask 65280 (11111111 00000000) and
            right shift the result 8 bits. Assign the resulting value to a char variable. Then, combine the unsigned
            integer with the mask 255 (00000000 11111111). Assign the result to another char variable. The program
            should print the unsigned integer in bits before it is unpacked, and then print the characters in bits to
            confirm that they were unpacked correctly.
*/
#include <iostream>
#include <stdio.h>
using namespace std;

unsigned packet( char, char );
void unpacket( char *, char *, unsigned );
void display_bits( unsigned );

int main(){

    char a, b;
    cout << "enter two char : ";
    cin >> a >> b;

    cout << '\'' << a << '\'' << " in bits as an unsigned integers is:\n";
    display_bits( a );

    cout << "\n"<< '\'' << b << '\'' << " in bits as an unsigned integers is:\n";
    display_bits( b );

    unsigned pack = packet( a, b );
    cout << "\n\'" << a << '\'' << " and " << '\'' << b << '\''<< "The packed character representation is:\n";
    display_bits( pack );

    unpacket( &a, &b, pack );
    cout << "\nThe unpacked characters are \'" << a << "\' and \'" << b << "\'\n";
    display_bits( a );
    display_bits( b );

    return 0;
}

unsigned packet( char x, char y ){
    unsigned pack = x;
    pack <<= 8;
    pack |= y;
    return pack;
}

void unpacket( char *a, char *b, unsigned pack ){
    unsigned mask1 = 65280, mask2 = 255;
    *a = ( char )(( pack & mask1 ) >> 8 );
    *b = ( char )( pack & mask2 );
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
