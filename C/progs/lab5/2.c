#include <stdio.h>
#include <string.h>
#include <ctype.h>

char s1[100], s2[100], s1rev[100];

int main()
{
	printf(">");
	fgets(s1, 100, stdin);

	for(int i=0;i<=strlen(s1);i++){
            	s1rev[strlen(s1)-1-i] = s1[i-1];
	}
		s1rev[strlen(s1)-1]=s1[strlen(s1)-1]; // nepeHeceHHR \0

	fputs(s1rev,stdout);

	printf(">");
	fgets(s2, 100, stdin);
	int i=0;
	while(i<strlen(s1)) {
      		putchar (toupper(s2[i]));
      		i++;
   	}
	return 0;
}

