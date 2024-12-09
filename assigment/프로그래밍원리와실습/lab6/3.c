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

void stud_bubble_sort(STUD * pnucse) {
    STUD *last = stud_get_last(pnucse);
    STUD *i,*j;

    for(i = pnucse;i<last;++i){
        for(j=pnucse;j<last-(i-pnucse);++j) {
            if(stud_compare_points(j,j+1) < 0) {
                stud_swap(j,j+1);
            }
        }
    }
	return;
}

int main(void) {
	STUD pnucse[] = { {1, "Choi", 9.9}, {2, "Park", 0.1},
		{3, "Kim", 5.0 }, {4, "Lee", 3.0 }, {5, "Moon", 9.5 },
		{6, "Kang", 7.0 }, {7, "Jeon", 0.9 }, {-1, NULL, 0 } };
		
	STUD * ps_cur = pnucse;
	//int test_id = 0;
	//scanf("%d",&test_id);
	//if (test_id) set_values_of_pnucse(pnucse, test_id); 
	
	stud_bubble_sort(pnucse);
	
	while (ps_cur->id > 0)
		stud_print(ps_cur++);	

	return 0;
}

void stud_print(STUD *ps) {
    printf("ID: %d, Name: %s, Points: %.1f\n", ps->id, ps->pname, ps->points);
}

void stud_swap(STUD *a, STUD *b) {
    STUD temp = *a;  // 첫 번째 학생을 임시로 저장
    *a = *b;         // 두 번째 학생 데이터를 첫 번째에 복사
    *b = temp;       // 임시 저장된 첫 번째 데이터를 두 번째에 복사
}

STUD *stud_get_last(STUD *ps_array) {
    STUD *current = ps_array;

    while (current->id != -1) {  // 종료 마커를 만날 때까지 이동
        current++;
    }

    return current - 1;  // 종료 마커 바로 앞의 학생 반환
}
int stud_compare_points(STUD *ps1, STUD *ps2) {
    if (ps1->points > ps2->points) return 1;  // 첫 번째 학생이 점수가 높음
    if (ps1->points < ps2->points) return -1; // 두 번째 학생이 점수가 높음
    return 0;                                // 점수가 같음
}

