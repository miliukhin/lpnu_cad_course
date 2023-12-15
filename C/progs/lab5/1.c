#include <stdio.h>
#include <string.h>

char fns[128];
int n;

int main(){

	printf(">");
	fgets(fns, 128, stdin);
	char* fn = strtok(fns, " ");
	char* mn = strtok(NULL, " ");
	char* ln = strtok(NULL, " ");
	printf("%s\n", fn);
	printf("%d\n", strlen(ln)-1);

	return 0;
}

