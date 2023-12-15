#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(){
  	char *buffer;
	int n;
	scanf("%d",&n);
	buffer = (char*)malloc((n+1) * sizeof(char));
	if(buffer == NULL) return -1;
	printf(">");
	scanf("%s",buffer);

	for(int j=0; j<n; j++){

		if(buffer[j]=='5'){
			printf("includes 5\n");
			//break;
		}
		if(buffer[j]=='7'){
			printf("includes 7\n");
			//break;
		}
	}

	free(buffer);
	return 0;
}

