#include <stdio.h>
#include <time.h>

void print_local_time_after_kdays(time_t t, int k) {
	
    t += k * 24 *3600;

    struct tm *local = localtime(&t);

    const char *days[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

    printf("%d/%d/%d, %02d:%02d:%02d, %s\n",
    local->tm_year + 1900,
    local->tm_mon+1,
    local->tm_mday,
    local->tm_mday,
    local->tm_min,
    local->tm_sec,
    days[local->tm_wday]);

	return;
}

int main(void) {
	int k=0;
	time_t now = 1669856792; // 2022/12/01 01:06:32
	
	scanf("%d", &k);
	
	print_local_time_after_kdays(now, k);

	return 0;
}