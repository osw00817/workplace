#include <stdio.h> 
int hexa2decimal(char hexa_str[]) {
	int decimal = 0;
	int base = 1;
	int i = 1;

	while(hexa_str[i] != '\0') {
		i++;
	}

	for(int j = i - 1;j>=2;j--) {
		char digit = hexa_str[j];
		
		if(digit >= '0' && digit <= '9')
			decimal += (digit -'0')* base;
		else if(digit >= 'A' && digit <= 'F')
			decimal += (digit - 'A' + 10) * base;
		
		base *= 16;
	}

	return decimal;
}

int main(void) {
	char hexa1[] = "0x1F34";
	char hexa2[] = "0x34CD56";
	char hexa3[] = "0x34FD5A";	

	printf("%s = %d\n", hexa1, hexa2decimal(hexa1));
	printf("%s = %d\n", hexa2, hexa2decimal(hexa2));
	printf("%s = %d\n", hexa3, hexa2decimal(hexa3));

	return 0;
}