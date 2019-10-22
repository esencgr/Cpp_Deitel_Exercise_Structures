#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct student{
    int no;
    string name;
};

void create_student( student *s ){
    cout << "- create student -" << endl;
    int s_no;
    string s_name;

    cout << " no : ";
    cin >> s_no;
    s -> no = s_no;

    cout << " name : ";
    cin >> s_name;
    s -> name = s_name;
}

void read_student( student s ){
    cout << "- read student -" << endl;
    cout << " no : " << s.no << "\n name : " << s.name << endl;
}

void update_student( student *s ){
    cout << "- update student -" << endl;
    string new_name;
    int new_no;

    cout << " new no : ";
    cin >> new_no;
    cout << " new name : ";
    cin >> new_name;

    s -> no = new_no;
    s -> name = new_name;
}

void delete_student( student *s  ){
   cout << "- delete student -" << endl;
    s -> no = 0;
    s -> name = " this student does not exist. ";
}

int main(){

    student s1;

    create_student( &s1 );
    read_student( s1 );

    update_student( &s1 );
    read_student( s1 );

    delete_student( &s1 );
    read_student( s1 );

    return 0;
}
