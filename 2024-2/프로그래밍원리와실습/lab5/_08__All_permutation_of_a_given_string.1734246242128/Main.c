#include <stdio.h>
#include <stdlib.h>

void permutation(char *str,int *visited,char *output,int depth,int n) {
	if(depth == n) {
		output[depth] = '\0';
		puts(output);
		return;
	}
	
	for(int i = 0;i<n;i++) {
		if(!visited[i]){
			visited[i] = 1;
			output[depth] = str[i];
			permutation(str,visited,output,depth+1,n);
			visited[i] = 0;
		}
	}
}

void print_all_permutations(char *str) {
	int n = 0;
	while(*str) {
		str++;
		n++;
	}
	str -= n;
	int *visited = (int*)calloc(n,sizeof(int));
	char *output = (char*)malloc(sizeof(char)*(n+1));
	permutation(str,visited,output,0,n);
	
	free(visited);
	free(output);
	return;
}

int main(void) { 
	char str[256] = "ABC";

	print_all_permutations(str);
	return 0; 
} 