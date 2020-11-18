#include<stdio.h>
struct adress{
    char *city;
    char *street;
};

struct student{
    char *name;
    int no;    
    struct adress adr;
}s1;

int main(){
    s1.name = "cgr";
    s1.no = 123;
    s1.adr.city = "Manisa";
    s1.adr.street = "ATATURK";
    printf("%s %d %s %s", s1.name, s1.no, s1.adr.city, s1.adr.street );
    printf("\n");
    return 0;

}