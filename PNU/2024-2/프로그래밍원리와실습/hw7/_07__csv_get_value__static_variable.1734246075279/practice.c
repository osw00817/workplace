#include <stdio.h> 
int csv_get_value(char str[]) {
	static int index = 0;
    int num = 0;
    if(str[index] == '\0')
        return -1;

    while(str[index] != ',' && str[index] != '\0') {
        num *= 10;
        num += (str[index++]-'0');
    }
    //printf("%d ",num);
    if(str[index] != '\0') {
        index++;
    }

    return num;
}
int main(void) {
	int num;
	char str[]="123,456,789,305,409,123";

	while ((num=csv_get_value(str))>=0)
		printf("%d\n",num);
	return 0;
}