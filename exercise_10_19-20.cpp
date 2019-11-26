#include <iostream>
using namespace std;

bool function_1( int number ){
    int multi = 1;

    for (int i = 1, mask = 1; i < 10; i++, mask <<= 1){
        if (( number & mask ) != 0){
            multi = false;
            break;
        }
    }

    return multi;
}

int function_2( unsigned bits ){
    unsigned i, mask = 1<<31, sum = 0;

    for (i = 0; i <= 31; i++, bits <<= 1)
        if (( bits & mask ) == mask)
           ++sum;

    return !(sum % 2) ? 1 : 0;
}

int main(){

    int number;
    cout << "enter number between 1-32000: ";
    cin >> number;

    cout << function_2( number ) << endl;

    if (function_1( number ))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
