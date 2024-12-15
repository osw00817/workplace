#include <stdio.h>
typedef struct student {
	int id;
	char *pname;
	double points;
} STUD;
STUD * stud_get_last(STUD *ps_array) {

	while((ps_array->id) != -1) {
		ps_array++;
	}
	ps_array--;
	return ps_array;
}

double stud_compare_points(STUD *ps1, STUD *ps2) {
	return (ps1->points > ps2->points);
}


int main(void) {
	STUD pnucse[] = { {1, "Choi", 9.9}, {2, "Park", 0.1},
		{3, "Kim", 5.0 }, {4, "Lee", 3.0 }, {5, "Moon", 9.5 },
		{6, "Kang", 7.0 }, {7, "Jeon", 0.9 }, {-1, NULL, 0 } };
	
	STUD pnucse2[] = { {1, "Choi", 9.9}, {2, "Park", 0.1},
		{3, "Kim", 5.0 }, {4, "Lee", 3.0 }, {5, "Moon", 9.5 },
		{-1, "Kang", 7.0 }, {7, "Jeon", 0.9 }, {-1, NULL, 0 } };	

	STUD *ps = pnucse;
	STUD *psend1 = stud_get_last(pnucse);
	STUD *psend2 = stud_get_last(pnucse2);

	if (stud_compare_points(ps,psend1) < 0) 
		printf("%s got a lower points than %s\n", ps->pname, psend1->pname);
	else
		printf("%s got an equal or higher points than %s\n", ps->pname, psend1->pname);

	if (stud_compare_points(ps,psend2) < 0) 
		printf("%s got a lower points than %s\n", ps->pname, psend2->pname);
	else
		printf("%s got an equal or higher points than %s\n", ps->pname, psend2->pname);

	return 0;
}