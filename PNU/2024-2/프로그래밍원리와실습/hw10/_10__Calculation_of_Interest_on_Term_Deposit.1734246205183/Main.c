#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define	DEF_RATE	1.8 // default rate (%)
#define	DEF_TERM 	1 // default term (yr)

double inter_calc(int dep, double rate, int yrs) {
	if(yrs < 1) {
		return 0;
	}
	
 	double total = dep * (pow(rate + 1.0,yrs)-1);
	return total;
}

int main(int argc, char *argv[]) {
	int myargc = 1, i;
	char my_cmd_line[1000]; 
	char *myargv[20]={"bankint", NULL};
	char *token = NULL;

	gets(my_cmd_line);
	
	token = strtok(my_cmd_line, " ");
	
	while (token) {
		myargv[myargc++] = token;
		token = strtok(NULL, " ");
	}

	return mymain(myargc, myargv);
}

int mymain(int argc, char *argv[]) {

	int deposit;
	double rate = DEF_RATE/100;
	int term = DEF_TERM;
  
	if(argv[1] == NULL){
		puts("Usage: bankint <deposit_money> <interest_rate(%)> <term(year(s))>");
		puts("Default interest = 1.8%, Default term = 1 year");
		return 0;
	}
	deposit = atoi(argv[1]);
  rate = (argc >= 3) ? atof(argv[2])/100 : rate;
	term = (argc >= 4) ? atoi(argv[3]) : term;
  
	//printf("test: %f %d\n",rate,term);
	printf("Total Interest = KRW %.0lf\n", inter_calc(deposit, rate, term));
	
	return 0;
}