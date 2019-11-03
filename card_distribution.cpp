#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

// struct card{
//     const char *side;
//     const char *set;
// };

typedef struct{
    const char *side;
    const char *set;
}card;

void create_deck( card *const, const char *[],  const char *[] );
void shuffle_deck( card *const );
void distribute_deck( const card *const );

int main(){

  card deck[ 52 ];
  const char *side[ 13 ] = { "as", "iki", "uc", "dort", "bes", "alti", "yedi",
                            "sekiz","dokuz","on","vale","kiz","papaz" };
  const char *set[ 4 ] = { "kupa", "karo", "sinek", "maca" };

  srand(time( NULL ));

  create_deck( deck, side, set );
  shuffle_deck( deck );
  distribute_deck( deck );

  return 0;
}

void create_deck( card * const deck, const char *side[], const char *set[] ){
     for (int i = 0; i < 51; i++){
         deck[ i ].side = side[ i % 13 ];
         deck[ i ].set  = set[ i / 13 ];
     }
}

void shuffle_deck( card * const deck ){
     card temp;
     int rnd;
     for (int i = 0; i < 51; i++){
         rnd = rand() % 52;
         temp = deck[ i ];
         deck[ i ] = deck[ rnd ];
         deck[ rnd ] = temp;
     }
}

void distribute_deck( const card * const deck ){
     for (int i = 0; i < 51; i++){
         cout << deck[ i ].set << " - " << deck[ i ].side << endl;
     }
}
