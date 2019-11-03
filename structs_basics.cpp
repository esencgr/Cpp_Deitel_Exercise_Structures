#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct card{
    string side;
    string set;
};

// struct card{
//     char *side;
//     char *set;
// };

int main(){
    card a;
    card *a_ptr;

    a.side = "AS";
    a.set  = "MACA";
    a_ptr = &a;

    cout << a.side << " " << a.set << endl;
    cout << a_ptr->side << " " << a_ptr->set << endl;
    cout << (*a_ptr).side << " " << (*a_ptr).set << endl;

    return 0;
}
