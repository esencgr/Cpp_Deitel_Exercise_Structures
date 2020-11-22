#include <stdlib.h>
#include <stdio.h>

struct student{
    char *name;
    char name[20];
    int no;
};

struct student enter(struct student s){
    // struct student s;
    printf("\n\nEnter student name and no : ");
    scanf("%s %d", s.name, &s.no);
    return s;
}

void print(struct student s){
    printf("%s %d", s.name, s.no);
}

int main(){

    struct student stu = {"cgr esen", 1234};
    // struct student stu;
    // stu.name = "cgr";
    // stu.no = 1234;
    print(stu);

    struct student new_stu;
    new_stu = enter(new_stu);
    print(new_stu);

    printf("\n");
    return 0;
}
