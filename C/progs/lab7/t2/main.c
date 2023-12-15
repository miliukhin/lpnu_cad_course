#include <stdio.h>
#include <string.h>

int countsp(char m[]){
		int count=0;

		for(int i=0; m[i]; i++){
			if(m[i]==' ')
				count++;
		}

		int wospaces = strlen(m)-1-count;

		return wospaces;
}

int write(int wsp){
	printf("with spaces: %d\n", wsp);
}

int read(char *arg[]){
	FILE *fp = fopen(arg[1], arg[2]);

		char m[400];
		fgets(m, 400, fp);

	fclose(fp);
	write(countsp(m));
	return strlen(m)-1;
}

int main(int argc, char *argv[]){

	write(read(argv));
	return 0;
}

