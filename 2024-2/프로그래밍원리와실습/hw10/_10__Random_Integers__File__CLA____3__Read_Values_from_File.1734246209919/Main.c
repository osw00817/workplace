#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int * read_numbers_binary(char *filename) {
	FILE *fp = fopen(filename,"r");
	int tmp,cnt = 1;
	int *list = (int*)malloc(sizeof(int) * 1);
	while(fread(&tmp,sizeof(int),1,fp)) {
		list = (int*)realloc(list,sizeof(int) * cnt);
		list[cnt-1] = tmp;
		//printf("%d ",tmp);
		cnt++;
	}
	list[cnt-1] = -1;
	//printf("\n");
	/*for(int i = 0;i<cnt;i++) {
		printf("%d ",list[i]);
	}*/
	return list;
}

int * read_numbers_csv(char *filename) {
	char buf[100];
	int cnt = 1;
	int *list = (int*)malloc(sizeof(int) * cnt);
	FILE *fp = fopen(filename,"r");
	while(fgets(buf,sizeof(buf),fp)) {
		int num = 0;
		for(int i = 0;buf[i];i++) {
			if(buf[i] == ',' || buf[i] == '\n') {
				// 배열에 추가
				list[cnt-1] = num;
				list = (int*)realloc(list,sizeof(int) * ++cnt);
				num = 0;
			} else {
				num = num * 10 + (buf[i]-'0');
			}
		}
	}
	list[cnt-1] = -1;
	fclose(fp);
	return list;
}
void save_numbers_binary(int *pn, char *filename) {
	FILE *fd = fopen(filename, "wb");
	int *pcur = pn;
	
	if (fd) {
		while (*pcur >= 0) pcur++;
		fwrite(pn, sizeof(int), pcur-pn, fd);
		fclose(fd);
	}
}

void save_numbers_csv(int *pn, char *filename) {
	FILE *fd = fopen(filename, "wt");	// Explicitly specify text mode
	int *pcur = pn;
	
	if (fd) {
		while (*pcur >= 0) {
			fprintf(fd, "%d", *pcur++);	
			while (*pcur >= 0) {
				fprintf(fd, ",%d", *pcur++);
				if ( (pcur-pn) % 8 == 0) {
					fprintf(fd, "\n");
					break;
				}
			}
		}
		fclose(fd);
	}
}

int get_max(int *values) {
	int nmax = 0;
	
	if (values) {
		while (*values >= 0) {
			if (*values > nmax)
				nmax = *values;
			values++;
		}
	}
	return nmax;
}

int * generate_numbers(int nnums) {
	int *pnum = (int *)malloc(sizeof(int)*(nnums+1));
	int *pcur = pnum;

	assert(pnum);	
	
	while (pcur < pnum + nnums) 
		*pcur++ = rand();
	
	*pcur = -1;
	
	return pnum;	
}
int main(void) {
	int testcase = 1, bbinary = 0;
	char *filename = "output"; 
	int test_values1[] = {1, 9, 178, 15, 2345, 2, 2, 34, 12, 5, -1};
	int *values = test_values1;
	
	scanf("%d", &testcase);
	switch (testcase) {
		case 2 :
			bbinary = 1;
		break;				
		case 3 :
			srand(11);
			values = generate_numbers(100);			
			break;
		case 4 :
			bbinary = 1;
			srand(21);
			values = generate_numbers(100);			
			break;			
		case 5 :
			srand(11);
			values = generate_numbers(10000);
			break;
		case 6 :
			srand(21);
			bbinary = 1;
			values = generate_numbers(10000);
			break;
		default :
			break;			
	}
	if (bbinary) {
		save_numbers_binary(values, filename);
		printf("Max : %d\n", get_max(read_numbers_binary(filename)));
	}
	else {
		save_numbers_csv(values, filename);		
		printf("Max : %d\n", get_max(read_numbers_csv(filename)));
	}
	
	return 0;
}