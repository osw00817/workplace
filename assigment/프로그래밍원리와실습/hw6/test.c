#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void mystrcpy(char *dest,char *src) {
    while(*src != '\0') {
        printf("%c ",*src);
        *dest++ = *src++;
    }
}

typedef struct STUD {
    int id;
    char *name;
    double points;
} STUD;

int main(void) {
    /*char mystr1[256];
    char mystr2[256];

    gets(mystr1);
    mystrcpy(mystr2,mystr1);
    puts(mystr2);*/

   STUD pnucse[] = {{1,"choi",9.9},{2,"Park",0.1},{3,"Kim",5.0}};
    STUD* ps = pnucse;
    STUD *PS1 = &pnucse[0];
    STUD *ps2 = &pnucse[2];

    printf("%d ",sizeof(STUD));
    printf("%d ",sizeof(pnucse));

    return 0;
}