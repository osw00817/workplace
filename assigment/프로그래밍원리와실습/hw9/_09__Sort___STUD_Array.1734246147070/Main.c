#include <stdio.h>
typedef struct student {
    int id;
    char *pname;
    double points;
} STUD;

void stud_print(STUD *ps);
void stud_swap(STUD *a, STUD *b);
STUD * stud_get_last(STUD *ps_array);
int stud_compare_points(STUD *ps1, STUD *ps2);
STUD * stud_get_lowest_points(STUD *ps_begin, STUD *ps_end);

void stud_print_array_in_decreasing_order(STUD * pnucse) {
	int n = 0;
	STUD *start = pnucse;
	while((pnucse->id) != -1) {
		n++;
		pnucse++;
	}
	pnucse = start;
	for(int i = 0;i<n;i++) {
		for(int j = i;j<n;j++) {
			if(pnucse[i].points < pnucse[j].points) {
				STUD tmp = pnucse[j];
				pnucse[j] = pnucse[i];
				pnucse[i] = tmp;
			}
		}
	}
	
	for(int i = 0;i<n;i++) {
		printf("[%d:%s] = %06lf\n",pnucse[i].id,pnucse[i].pname,pnucse[i].points);
	}
}
void set_values_of_pnucse(STUD * pnucse, int test) {
	STUD pnucse1[] = { {1, "Choi", 3.9}, {2, "Park", 2.1},
		{3, "Kim", 9.0 }, {4, "Lee", 3.5 }, {5, "Moon", 4.5 },
		{6, "Kang", 2.0 }, {7, "Jeon", 8.9 }, {-1, NULL, 0 } };
	STUD pnucse2[] = { {1, "Choi", 2.5}, {2, "Park", 4.1},
		{3, "Kim", 1.0 }, {4, "Lee", 8.0 }, {5, "Moon", 8.5 },
		{6, "Kang", 5.0 }, {7, "Jeon", 3.9 }, {-1, NULL, 0 } };
	STUD *pnew = (test%2) ? pnucse1 : pnucse2;
	int i=0;
	
	while (i<7) {
		pnucse[i] = pnew[i];
		i++;
	}
}
int main(void) {
    STUD pnucse[] = { {1, "Choi", 9.9}, {2, "Park", 0.1},
		{3, "Kim", 5.0 }, {4, "Lee", 3.0 }, {5, "Moon", 9.5 },
		{6, "Kang", 7.0 }, {7, "Jeon", 0.9 }, {-1, NULL, 0 } };

	int test_id = 0;
	scanf("%d",&test_id);
	if (test_id) set_values_of_pnucse(pnucse, test_id); 
	
	stud_print_array_in_decreasing_order(pnucse);

	return 0;
}
void stud_print(STUD *ps) {
    printf("[%d:%s] = %lf\n", ps->id, ps->pname, ps->points);	
}

void stud_swap(STUD *a, STUD *b) {
    STUD buf;
    buf = *a;
    *a = *b;
    *b = buf;
}

STUD * stud_get_last(STUD *ps_array) {
	while (ps_array->id >= 0) {
		ps_array++;
	}
	return --ps_array;
}

int stud_compare_points(STUD *ps1, STUD *ps2) {
	// Enter your code here
	int ret = 1;
	if (ps1->points < ps2->points)
		ret = -1;
	else if (ps1->points == ps2->points)
		ret = 0;
	return ret;
}

STUD * stud_get_lowest_points(STUD *ps_begin, STUD *ps_end) {
	STUD *plowest = ps_begin++;

	if (ps_end) {	// ps_end is not NULL
		while (ps_begin <= ps_end) {
			if (stud_compare_points(ps_begin, plowest) < 0)
				plowest = ps_begin;
			ps_begin++;
		}
	} else {			// ps_end is NULL
		while (ps_begin->id >= 0) {
			if (stud_compare_points(ps_begin, plowest) < 0)
				plowest = ps_begin;
			ps_begin++;
		}
	}
	return plowest;
}