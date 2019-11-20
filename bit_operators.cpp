#include <iostream>
#include <stdio.h>
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

int main(){

    // unsigned a = 1;
    // // unsigned m = 1 << 31;
    // bits( a );

    unsigned num1, num2, mask;

    // AND & OPERATOR USAGE
    num1 = 65535;
    mask = 1;
    bits( num1 );
    bits( mask );
    cout << num1 << " & " << mask << " --> ";
    bits( num1 & mask );
    cout << endl;

    // OR | OPERATOR USAGE
    num1= 15;
    mask = 241;
    bits( num1 );
    bits( mask );
    cout << num1 << " | " << mask << " --> ";
    bits( num1 | mask );
    cout << endl;

    // EXOR ^ OPERATOR USAGE
    num1= 139;
    num2 = 199;
    bits( num1 );
    bits( num2 );
    cout << num1 << " ^ " << num2 << " --> ";
    bits( num1 ^ num2 );
    cout << endl;

    // COMPLEMENT ~ OPERATOR USAGE
    num1= 15;
    bits( num1 );
    cout << "~ " << num1 << " --> ";
    bits( ~num1 );
    cout << endl;

    // LEFT SHIFTING << OPERATOR USAGE
    num1= 960;
    bits( num1 );
    int shift_bit = 8;
    cout << num1 << " << " << shift_bit << " --> ";
    bits( num1 << shift_bit );
    cout << endl;

    // RIGHT SHIFTING >> OPERATOR USAGE
    num1= 960;
    bits( num1 );
    cout << num1 << " >> " << shift_bit << " --> ";
    bits( num1 >> shift_bit );
    cout << endl;

    return 0;
}

// #include <iostream>
// using namespace std;
// int main()
// {
//     cout << "bitwise operatorleri" << endl;
//
//     //sola kaydirma
//
//     int r = 19;
//     cout << r << endl;
//
//     int b = r << 2;
//     cout << b << endl;
//
//     // sag kaydirma
//
//     int g = 18;
//     cout << g << endl;
//
//     int u = g >> 2;
//     cout << u << endl;
//
//     //and ( & ) operatorleri
//
//     int k = 22 & 13 ;
//
//     cout << k << endl;
//
//     // veya ( | ) operatorleri
//
//     int a = 12 | 6;
//
//     cout << a << endl;
//
//     // ya da ( ^ ) operatorleri
//
//     int m = 5 ^ 28;
//
//     cout << m << endl;
//
//     return 0;
// }
