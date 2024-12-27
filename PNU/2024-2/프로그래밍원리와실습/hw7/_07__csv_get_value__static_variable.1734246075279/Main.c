#include <stdio.h> 
int csv_get_value(char str[]) {
	static char *current = NULL;
	int value = 0;
	
	if(current == NULL)
		current = str;
	if(*current == '\0')
		return -1;
	while(*current >= '0' && *current <= '9') {
		value = value * 10 + (*current - '0');
		current++;
	}
	if(*current == ',') current++;
	return value;
}
int main(void) {
	int num;
	char str[]="123,456,789,305,409,123";

	while ((num=csv_get_value(str))>=0)
		printf("%d\n",num);
	return 0;
}