#include <stdio.h>
typedef struct student {
    int id;
    char *pname;
    double points;
} STUD;

void stud_printx(STUD s) {
    printf("[%d:%s] = %lf\n", s.id, s.pname, s.points);
}
void stud_print(STUD *ps) {
		printf("[%d:%s] = %lf\n",ps->id,ps->pname,ps->points);
}
void stud_swap(STUD *s1,STUD *s2) {
	STUD tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int main(void) {
	STUD s1 = {1, "Choi", 9.9};
	STUD s2 = {2, "Park", 0.1};

	stud_printx(s1);
	stud_printx(s2);
	stud_swap(&s1,&s2);
	stud_print(&s1);
	stud_print(&s2);

	return 0;
}