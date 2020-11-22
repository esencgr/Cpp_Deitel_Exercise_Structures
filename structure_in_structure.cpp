#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

/*

   PARTS           CATEGORIES
food      --->  legumes - macaroni
cosmetic  --->  parfume - makeup
butcher   --->  chicken - and
fruiterer --->  vegetables - fruit

*/

struct categories{
    string name;
    int number_of_products;
};

struct parts{
    string name;
    bool state;          // 1 -> (OPEN) || 0 -> (CLOSE)
    int total_product;
    categories products;
};

struct new_part{
    string name;
    bool state;          // 1 -> (OPEN) || 0 -> (CLOSE)
    int total_product;
    categories *products;
};

void decrease( parts *part, int decrease ){
    cout << "\nENTER THE NUMBER OF PRODUCTS SOLD = ";
    cin >> decrease ;
    part -> products.number_of_products -= decrease;
    part -> total_product -= decrease;

    cout << "NEW TOTAL = " <<  part -> total_product << " ---- "
         << "NEW CATEGORIES = " << part -> products.number_of_products << endl << endl;
}

int main(){

    parts part1 = { "FOOD", true, 200, { "MACARONI", 120 }};

    cout << part1.name << " " << part1.state << " " << part1.total_product << " "
         << part1.products.name << " " << part1.products.number_of_products << endl;

    int decreasing_product;
    decrease( &part1, decreasing_product );

    new_part part2;
    part2.name = "BUTCHER";
    part2.state = true;
    part2.total_product = 300;
    // part2.products -> name = "CHICKEN";
    // part2.products -> number_of_products = 120;

    categories a = { "AND", 150 };
    part2.products = &a;
    cout << part2.name << " " << part2.state << " " << part2.total_product << " "
         << part2.products -> name << " " << part2.products -> number_of_products << endl;

    new_part part3;
    part3 = part2;
    cout << part2.name << " " << part2.state << " " << part2.total_product << " "
         << part2.products -> name << " " << part2.products -> number_of_products << endl;

    categories b = { "CHICKEN", 120 };
    part2.products = &b;
    cout << part2.name << " " << part2.state << " " << part2.total_product << " "
         << part2.products -> name << " " << part2.products -> number_of_products << endl;

    return 0;
}

