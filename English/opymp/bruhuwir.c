#include<stdio.h>
char lname[20], fname[15];

int n, god;

int main()
	{
		n = scanf("%s%s%d", lname,fname,&god);
		printf("%d pos %s%s%d", n, fname,lname,god);
}

