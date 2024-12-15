#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
	int i, ranval, nseed;
	
	scanf("%d", &nseed);
	srand(nseed);

	printf("+----------------------+\n");
	printf("|123456|123456|12345678|\n");
	printf("+----------------------+\n");

	for (i=0; i<10; i=i+1) {
		ranval = rand()%0xFFFF;
	
		printf("|%-6d",ranval); // left-justified
		printf("|0x%04X",ranval); // start with 0x, Hexa(0~9, A~F), minimum field width = 4, leading 0s
		printf("|0o%06o|\n",ranval); // start with 0o, Octa (0~7), minimum field width=6, leading 0s
	}
	printf("+----------------------+\n");

	return 0;
}
