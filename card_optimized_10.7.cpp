/* Modify the program of Fig. 16.14 to shuffle the cards using a high-performance shuffle as shown in Fig. 16.2.
   Print the resulting deck in two column format as in Fig. 16.3. Precede each card with its color.*/
// In this example card distribution algorithm is optimized with memory allocated manage.
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/*
   Side  -> 0(as), .. , 12(papaz)
   Set   -> 0(karo), 1(kupa), 2(sinek), 3(maça)
   Color -> 0(kırmızı), 1(siyah)
*/

typedef struct{
    unsigned side : 4;    // side stores between 0 and 12 value. So side must define 4 bit (as a 0 and 15 value)
    unsigned set : 2;     // set stores between 0 and 3 value. So side must define 2 bit (as a 0 and 3 value)
    unsigned color : 1;   // color stores between 0 and 1 value. So side must define 4 bit (as a 0 and 1 value)
}card;

void create_deck( card *const );
void shuffle_deck( card *const);
void distribute_deck( const card *const );

int main(){

  card deck[ 52 ];
  srand( 0 );
  create_deck( deck );
  shuffle_deck( deck );
  distribute_deck( deck );

  return 0;
}

void create_deck( card * const deck ){
     for (int i = 0; i < 51; i++){
         deck[ i ].side = i % 13;
         deck[ i ].set = i / 13;
         deck[ i ].color = i / 26;
     }
}
void shuffle_deck( card * const deck ){
     card temp;
     int rnd;
     for ( int i = 0; i < 51; i++) {
         rnd = rand( ) % 52;
         temp = deck[ i ];
         deck[ i ] = deck[ rnd ];
         deck[ rnd ] = temp;
     }
}

void distribute_deck( const card * const deck ){
     const char *side[ 13 ] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven",
                                "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
     const char *set[ 4 ] = { "Hearts", "Diamonds", "Clubs", "Spades" };
     const char *color[ 2 ] = { "Red", "Black" };

     for ( int i = 0; i <= 51; i++) {
         cout << color[ deck[ i ].color ] << " : "
              << side[ deck[ i ].side ] << " of "
              << set[ deck[ i ].set ];
         cout << (( i + 1 ) % 2 ? '\t' : '\n');
     }
}
