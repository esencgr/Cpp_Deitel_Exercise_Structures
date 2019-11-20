/*
  EXAMPLE : 10.13 -->
            If your system uses 4-byte integers, rewrite the program of Exercise 16.12 to pack 4 characters.

  EXAMPLE : 10.14 -->
            If your system uses 4-byte integers, rewrite the function unpackCharacters of Exercise 16.13 to
            unpack 4 characters. Create the masks you need to unpack the 4 characters by left shifting the
            value 255 in the mask variable by 8 bits 0, 1, 2 or 3 times (depending on the byte you are unpacking).
*/
#include <iostream>
#include <stdio.h>
using namespace std;

unsigned packet( char, char, char, char );
void unpacket( char *, char *, char*, char *, unsigned );
void display_bits( unsigned );

int main(){

    char a, b, c, d;
    cout << "enter four char : ";
    cin >> a >> b >> c >> d;

    cout << "\n" << '\'' << a << '\'' << " in bits as an unsigned integers is:\n";
    display_bits( a );
    cout << "\n" << '\'' << b << '\'' << " in bits as an unsigned integers is:\n";
    display_bits( b );
    cout << "\n" << '\'' << c << '\'' << " in bits as an unsigned integers is:\n";
    display_bits( c );
    cout << "\n" << '\'' << d << '\'' << " in bits as an unsigned integers is:\n";
    display_bits( d );

    unsigned pack = packet( a, b, c, d );
    cout << "\n\n\'" << a << '\'' << " and " << '\'' << b << '\''
         << '\'' << c << '\''<< '\'' << d << '\''
         << "The packed character representation is:\n";
    display_bits( pack );

    cout << "\n\n255 << 24 : ";
    display_bits( 255 << 24 );
    cout << "255 << 16 : ";
    display_bits( 255 << 16 );
    cout << "255 << 8  : ";
    display_bits( 255 << 8 );
    cout << "255       : ";
    display_bits( 255 );




    unpacket( &a, &b, &c, &d, pack );
    cout << "\n\nThe unpacked characters are \'" << a << "\' and \'" << b << '\''
         << '\'' << c << '\''<< '\'' << d << '\'' << endl;

    display_bits( a );
    display_bits( b );
    display_bits( c );
    display_bits( d );

    return 0;
}

unsigned packet( char x, char y, char z, char t ){
    unsigned pack = x;

    pack <<= 8;
    pack |= y;

    pack <<= 8;
    pack |= z;

    pack <<= 8;
    pack |= t;

    return pack;
}

void unpacket( char *a, char *b, char *c, char *d, unsigned pack ){
    unsigned mask = 255;
    *a = ( char )(( pack & ( mask << 24 )) >> 24 );
    *b = ( char )(( pack & ( mask << 16 )) >> 16 );
    *c = ( char )(( pack & ( mask << 8 )) >> 8 );
    *d = ( char )(( pack & mask ));
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
