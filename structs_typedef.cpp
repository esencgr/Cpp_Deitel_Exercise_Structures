#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct student{
    int no;
    string name;
    char gender;
};

typedef enum{
    male,female
} gen;

typedef enum{
    sunday,monday,thursday,wednesday,tuesday,friday,saturday
} days;

struct person{
    int age;
    string name;
    char gender;  //gen gender
    days day;
};

// bool control( person p ){
//     if ( p.gender == male && p.age > 60 )
//         return 1;
//     if ( p.gender == female && p.age > 60 )
//         return 1;
//     return 0;
// }

bool control( person p ){
    if ( p.gender == 'M' && p.age > 60 )
        return 1;
    if ( p.gender == 'F' && p.age > 60 )
        return 1;
    return 0;
}

bool control_new( person *p ){
    if ( p -> gender == 'M' && p -> age > 60 )
        return 1;
    if ( p -> gender == 'F' && p -> age > 45 )
        return 1;
    return 0;
}

int main(){

    student s1;
    s1.no = 130208076;
    s1.name = "cagri";
    s1.gender = 'M';
    cout << "\nno : " << s1.no << "\nname : " << s1.name << "\ngender : " << s1.gender << endl;

    person p1;
    cout << "\nname : ";
    cin >> p1.name;
    cout << "age : ";
    cin >> p1.age;
    cout << "gender : ";
    cin >> p1.gender;

    if (control( p1 ))
        cout << "the person is true." << endl;
    else
        cout << "the person is not true." << endl;

    person *p2;
    p2 = ( person* )malloc( sizeof( person ));
    cout << "\nname : ";
    cin >> p2 -> name;
    cout << "age : ";
    cin >> p2 -> age;
    cout << "gender : ";
    cin >> p2 -> gender;

    if (control_new( p2 ))
        cout << "the person is true." << endl;
    else
        cout << "the person is not true." << endl;

    return 0;
}
