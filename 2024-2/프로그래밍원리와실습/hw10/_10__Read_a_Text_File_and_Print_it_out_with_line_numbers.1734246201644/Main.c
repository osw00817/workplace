#include <stdio.h>

int main(void) {
	char *filename = "data/stdint-wrap.h";
	FILE *fp = NULL;
	char buf[256];
	int line_number = 1;
	fp = fopen(filename,"r");
	while(fgets(buf,sizeof(buf),fp) != NULL){
		printf("%2d : %s",line_number++,buf);
	}
	fclose(fp);
	
	return 0;	
}
