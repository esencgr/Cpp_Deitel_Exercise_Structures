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

int main(){


    return 0;
}
