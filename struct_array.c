#include <stdlib.h>
#include <stdio.h>

struct student{
    char name[20];
    int no;
};

int main(){

    struct student s[2];

    for (int i = 0; i < 2; i++){
        printf("enter %d. student:", i+1);
        scanf("%s %d", s[i].name, &s[i].no);
    }
    for (int i = 0; i < 2; i++){
        printf("enter %d. student: %s %d\n", i+1, s[i].name, s[i].no);
    }
    
    printf("\n");
    return 0;
}
