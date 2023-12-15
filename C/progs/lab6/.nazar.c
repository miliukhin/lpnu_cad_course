#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char arr[300]="Baus Obama Iran Yablonskiy Ivan Behaviour we imady Aaof men had open.To projection considered it precaution an melancholy or. Wound young you thing worse along being ham.Dissimilar of favourable solicitude if sympathize middletons at.";

//спочатку sentence[0]=strtok(arr,".")
//а далі циклом sentense[n]=strtok(NULL,".")
int main(){
    int n=0;
    char *largeW[50];
    for(int i=0;i<300;i++)
        if( arr[i] >= 'A' && arr[i] <= 'Z' ){
            largeW[n] = arr + i;
            printf("%d)%c ",i+1 , *largeW[n]);
            n++;
        }
    printf("\n");
    for(int i=0;i<n;++i){
            int f=0;
        for(int j = 0;j < n-i-1; ++j){
        int dif;
        char *c1 = largeW[j],*c2 = largeW[j+1];
        for( ; *c1 == *c2; ++c1, ++c2) if(!*c1){
        dif = 0;
        break;
        }
        dif = *c1 - *c2;
        if(dif > 0)
            {
             char *p = largeW[j];
             largeW[j] = largeW[j + 1];
             largeW[j + 1] = p;
             f++;
            }
        }
        if(f==0)break;
    }
    puts("Sorted words:");
    for(int i = 0;i < n; ++i) for(int j = 0; ; ++j){
        putchar(*(largeW[i] + j));
        if(*(largeW[i] + j) == ' ' || !*(largeW[i] + j)) break;
    }
    return 0;
}

