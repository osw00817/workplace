#include <stdio.h>
#include <stdlib.h>
#include <time.h>

time_t xtime(int time_index);
void print_local_time(time_t *t) {
	const char* days[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	
	struct tm *pnow;
	pnow = gmtime(&t);
	if(pnow != NULL) {
		printf("%d/%d/%d, %02d:%02d:%02d, %s",pnow->tm_year+1900,(pnow->tm_mon)+1,pnow->tm_mday,pnow->tm_hour,pnow->tm_min,pnow->tm_sec,days[pnow->tm_wday]);
		
	}
}
int main(void) {
	time_t t;
	int tindex;

	srand(0);
	scanf("%d", &tindex);

	t = xtime(tindex);
	print_local_time(t);

	return 0;
}
time_t xtime(int time_index) {
	//struct tm t_begin = {0, 0, 0, 1, 0, 120, };
	time_t xnow = 1577836800; // 2020. 1. 1, 00:00:00
	
	while (time_index-- > 0) 
		rand();
	
	xnow += rand()% 31622399;
	return xnow;	
}
