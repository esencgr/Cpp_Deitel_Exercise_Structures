// In this example card distribution algorithm is optimized with memory allocated manage.
#include <stdio.h>
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
void distribute_deck( const card *const );

int main(){

  card deck[ 52 ];
  create_deck( deck );
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

void distribute_deck( const card * const deck ){
     for (int i = 0, j = i + 26; i <= 25; i++, j++){
         cout << "Set:\t" << deck[ i ].set << "\t"
              << "Side:\t" << deck[ i ].side << "\t"
              << "Color:\t" << deck[ i ].color << "\t";
         cout << "Set:\t" << deck[ j ].set << "\t"
              << "Side:\t" << deck[ j ].side << "\t"
              << "Color\t" << deck[ j ].color << endl;
     }
}
