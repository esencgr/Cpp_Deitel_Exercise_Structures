#include<stdio.h>

struct adress{
    char *city;
    char *street;
};

struct student{
    char *name;
    int no;    
    struct adress adr;
}; //s1;

void show(struct student s, struct student *s_ptr){
    printf("%s %d %s %s\n", s.name, s.no, s.adr.city, s.adr.street );
    printf("%s %d %s %s\n", s_ptr->name, s_ptr->no, s_ptr->adr.city, s_ptr->adr.street );
    printf("%s %d %s %s\n", (*s_ptr).name, (*s_ptr).no, (*s_ptr).adr.city, (*s_ptr).adr.street );
}

struct student *update(struct student *s_ptr){
    s_ptr->name = "cagri";
    s_ptr->no = 2345;
    s_ptr->adr.city = "Gazi";
    s_ptr->adr.street = "Kemal Atatürk";
    
    return s_ptr;
}

int main(){
    // s1.name = "cgr";
    // s1.no = 123;
    // s1.adr.city = "Manisa";
    // s1.adr.street = "ATATURK";
    
    struct student s1 = {"cgr", 123, {"Manisa", "ATATURK"}};
    struct student *s1_ptr = &s1;
    show(s1,&s1);
    printf("\n");

    // printf("%s %d %s %s\n", s1.name, s1.no, s1.adr.city, s1.adr.street );
    // printf("%s %d %s %s\n", s1_ptr->name, s1_ptr->no, s1_ptr->adr.city, s1_ptr->adr.street );
    // printf("%s %d %s %s\n"  , (*s1_ptr).name, (*s1_ptr).no, (*s1_ptr).adr.city, (*s1_ptr).adr.street );

    s1_ptr = update(&s1);
    printf("\n");

    // printf("%s %d %s %s\n", s1.name, s1.no, s1.adr.city, s1.adr.street );
    // printf("%s %d %s %s\n", s1_ptr->name, s1_ptr->no, s1_ptr->adr.city, s1_ptr->adr.street );
    // printf("%s %d %s %s\n"  , (*s1_ptr).name, (*s1_ptr).no, (*s1_ptr).adr.city, (*s1_ptr).adr.street );

    show(s1, &s1);
    printf("\n");
    
    return 0;
}