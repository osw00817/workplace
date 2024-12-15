#include <stdio.h> 
void print_menu(void); // Function Declaration

int main(void) {
	double	in, out;
	int nchoice;
	int baserate = 1000;

	do {
		print_menu();
		scanf("%d",&nchoice);
		if (nchoice==0) 	break;
		switch (nchoice) {
			// Enter your code
		case 1:
			printf("Current base exchange rate : %d\nEnter the new base rate : ", baserate);
			scanf("%d", &baserate);
			break;
		case 2:
			printf("Enter the amount of KRW : ");
			scanf("%lf",&in);
			out = in/baserate;
			printf("%.0lf(KRW) == %.6lf(USD)\n",in,out);
			break;
		case 3:
			printf("Enter the amount of USD : ");
			scanf("%lf",&in);
			out = in * baserate;
			printf("%.6lf(USD) == %.0lf(KRW)\n",in,out);
			break;
		default:
			printf("wrong choice !\n");
		}
	} while (1);
	printf("bye bye\n");
	return 0;
}

void print_menu(void) {
	char szmenu1[] ="[1] Set the base KRW-USD exchange rate";
	char szmenu2[] ="[2] Convert [KRW] to [USD]";
	char szmenu3[] ="[3] Convert [USD] to [KRW]";
	char szmenu0[] ="[0] Exit Program";
	char szchoice[]="Enter your choice : ";

	printf("%s\n%s\n%s\n%s\n%s",szmenu1,szmenu2, szmenu3,szmenu0,szchoice);
}
