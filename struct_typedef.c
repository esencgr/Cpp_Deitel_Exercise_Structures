#include <stdlib.h> // for malloc
#include <stdio.h>

typedef struct{
    char *g; 
}gender;

typedef struct{
    int age;
    char *name;
    //enum{ male, female } gender;
    gender gen;
}person;

int check (person *p){
    if (p->gen.g == "male" && p->age > 55)
        return 1;
    if (p->gen.g == "female" && p->age > 50)
        return 1;
    return 0;
}

int main(){
    
    person p;
    p.age = 80;
    p.name = "cgr";
    p.gen.g = "male";
    printf ("\n%d %s %s \n", p.age, p.name, p.gen.g);

    person *ptr;
    ptr = &p;//(person*) malloc(sizeof(person));
    ptr->age = 0;
    ptr->name = "esen";
    ptr->gen.g = "female";
    printf ("\n%d %s %s\n", ptr->age, ptr->name, ptr->gen.g);
    
    // for cgr person
    printf ("\ncheck result : %d\n", check (&p));

    // for esen person
    printf ("\ncheck result : %d\n", check (ptr)); 

    printf ("\n");
    return 0;
}
