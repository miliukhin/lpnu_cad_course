#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(){

char arr[400]=" Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Etiam lobortis facilisis sem. Nullam nec mi et neque pharetra sollicitudin. Praesent imperdiet mi nec ante. Donec ullamcorper, felis non sodales commodo, lectus velit ultrices augue, a dignissim nibh lectus placerat pede. Vivamus nunc nunc, molestie ut, ultricies vel, semper in, velit. Ut porttitor";
int dot=0;

for(int i=0;i<400;i++)
        if( arr[i] =='.'  ){
            dot++;
        }
printf("%d\n",dot);

char *sentence[dot+2];
	sentence[0]=strtok(arr,".");
	printf("%s\n", sentence[0]);

	for(int n=1; n<dot; n++){
		sentence[n]=strtok(NULL,".");
		printf("%s\n", sentence[n]);
	}

	/*------------------------------*/

	for(int j = 0; j < dot; ++j)
		for(int g = 0; g < dot - 1; ++g){
			char *c1 = sentence[g];
			char *c2 = sentence[g + 1];
			int flag;
			for(; *c1 == *c2; ++c1, ++c2)
				if(!*c1)
				{
					flag = 0;
					break;
				}
			flag = *c1 - *c2;
			if(flag > 0){
				char *p = sentence[g];
				sentence[g] = sentence[g + 1];
				sentence[g + 1] = p;
			}
		}
	puts("Sorted:");
	for(int j = 0; j < dot; ++j){
		if(j%2==0){
		puts(sentence[j]);
		}
	}

	return 0;
}

