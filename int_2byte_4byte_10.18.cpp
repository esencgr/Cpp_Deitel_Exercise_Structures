#include <iostream>
using namespace std;

void display_4bits( unsigned );
void display_2bits( unsigned );

int main(){

    int number;
    cin >> number;

    cout << "4 bits : ";
    display_4bits( number );

    cout << "2 bits : ";
    display_2bits( number );

 return 0;
}

// this function is implemnting for using and working 2 bytes computer
void display_2bits( unsigned value ){

    const int SHIFT = ( 8 * sizeof( unsigned )/2 ) - 1;   // Alocated memory of unsigned variable ( 8*4/2 - 1 = 31 )
    const unsigned mask = 1 << SHIFT;                     // 10000000 00000000 00000000 00000000 -- 32 bit

    cout << value << " = ";
    for (unsigned c = 1; c <= SHIFT; c++){
        cout << ( value & mask ? '1' : '0' );          // AND operators decides of which bits 1 or 0
        value <<= 1;                                   // compares for each bit to 01000000 and shifted version each 8 bits uncouple.
        if (c % 8 == 0)
            cout << ( ' ' );
    }
    cout << endl;

}

// this function is implemnting for using and working 4 bytes computer
void display_4bits( unsigned value ){

    // const int SHIFT = 8 * sizeof( unsigned ) - 1;    // Alocated memory of unsigned variable ( 8*4 - 1 = 31 ) ( 8 bit computer )
    // const unsigned mask = 1 << SHIFT;                // 10000000 00000000 00000000 00000000 -- 32 bit
    const unsigned mask = 1 << 31;

    cout << value << " = ";
    for (unsigned c = 1; c <= 32; c++){
        cout << ( value & mask ? '1' : '0' );           // AND operators decides of which bits 1 or 0
        value <<= 1;                                    // compares for each bit to 01000000 and shifted version each 8 bits uncouple.
        if (c % 8 == 0)
            cout << ( ' ' );
    }
    cout << endl;

}
