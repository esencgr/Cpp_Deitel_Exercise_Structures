#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

// struct student{
//     int no;
//     string name;
//     char gender;
// };

typedef enum{
    male,female
} gen;

typedef enum{
    sunday,monday,thursday,wednesday,tuesday,friday, saturday
} days;

typedef struct{
    int age;
    string name;
    gen gender;     //char gender;
    days day;
} person;

int main(){

    // student s1;
    // s1.no = 130208076;
    // s1.name = "cagri";
    // s1.gender = 'M';
    // cout << "\nno : " << s1.no << "\nname : " << s1.name << "\ngender : " << s1.gender << endl;

    // person p1;
    // cin >> p1.age >> p1.name;
    // cout << "\nage : " << p1.age << "\nname : " << p1.name  << "\ngender : " << p1.gender << endl;

    person p1;
    p1.age = 30;
    p1.name = " JOHN ";
    p1.gender = male;
    p1.day = monday;
    cout << "\nage : " << p1.age << "\nname : " << p1.name  << "\ngender : " << p1.gender << "\nday : " << p1.day << endl;
  return 0;
}
