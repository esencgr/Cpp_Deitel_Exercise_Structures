#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void alphabet( string word, char temp ){

    int size = 0;

    while( word[ size ] != '\0')    // size = word.length();
        size++;

    int k = 0, l = 0;
    while( k < size - 1 ){
        l = k + 1;
        while( l < size ){
            if( word[ k ] > word[ l ] ){
                temp = word[ k ];
                word[ k ] = word[ l ];
                word[ l ] = temp;
            }
            l++;
        }
        k++;
    }

    for( int i = 0; i < size; i++ )
        cout << word[ i ];
}

int main(){

    string str;
    cin >> str;
    char temp;

    alphabet ( str, temp );

    cout << endl;
    string word;
    cin >> word;
    int l = word.size( );
    for( int k = 0; k < l; k++ ){
        for( int i = 0; i < l-1; i++ ){
            if( word[ i ] > word[ i + 1 ] ){
                temp = word[ i + 1 ];
                word[ i + 1 ] = word[ i ];
                word[ i ] = temp;
            }
         }
    }

    for( int i = 0; i < l; i++ ){
        cout << word[ i ];
    }

  return 0;
}
