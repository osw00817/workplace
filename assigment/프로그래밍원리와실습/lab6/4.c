#include <stdio.h>
#include <string.h>
#include <time.h>

struct tm parse_datetime(char* datetime_str) {
	// Implement your code
	struct tm datetime = {0};

     sscanf(datetime_str, "%d-%d-%d %d:%d",
           &datetime.tm_year, &datetime.tm_mon, &datetime.tm_mday,
           &datetime.tm_hour, &datetime.tm_min);

    datetime.tm_year -= 1900; // tm_year는 1900년 기준
    datetime.tm_mon -= 1;     // tm_mon은 0부터 시작 (0 = January)

    return datetime;
}

int detect_schedule_conflict(struct tm *start1, struct tm *end1, struct tm *start2, struct tm *end2) {
	// Implement your code
	
    time_t t_start1 = mktime(start1);
    time_t t_end1 = mktime(end1);
    time_t t_start2 = mktime(start2);
    time_t t_end2 = mktime(end2);

    return (t_start1 < t_end2 && t_start2 < t_end1);
}

int main() {
    char start1[20], end1[20], start2[20], end2[20];

    //printf("Enter the first time period (start and end) in the format YYYY-MM-DD HH:MM:\n");
    //printf("Start 1: ");
    fgets(start1, sizeof(start1), stdin);
    start1[strlen(start1) - 1] = '\0';
    //printf("End 1: ");
    fgets(end1, sizeof(end1), stdin);
    end1[strlen(end1) - 1] = '\0';

    //printf("Enter the second time period (start and end) in the format YYYY-MM-DD HH:MM:\n");
    //printf("Start 2: ");
    fgets(start2, sizeof(start2), stdin);
    start2[strlen(start2) - 1] = '\0';
    //printf("End 2: ");
    fgets(end2, sizeof(end2), stdin);
    end2[strlen(end2) - 1] = '\0';

    struct tm t_start1 = parse_datetime(start1);
    struct tm t_end1 = parse_datetime(end1);
    struct tm t_start2 = parse_datetime(start2);
    struct tm t_end2 = parse_datetime(end2);

    if (detect_schedule_conflict(&t_start1, &t_end1, &t_start2, &t_end2)) {
        printf("Schedule conflict detected!\n");
    } else {
        printf("No schedule conflict.\n");
    }

    return 0;
}