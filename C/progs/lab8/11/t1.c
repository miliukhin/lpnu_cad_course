#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ug{
	int group;
	char fname[12];
	char lname[12];
	int gen;
	int age;
};

void write(int m[4][2]){
	printf("Group containing the most female undergraduates: %d",m[0][0]);
}

struct ug *readstrct(){
	struct ug d[10];
	FILE *fp;
	char str[121];
	char *item;
	int id=0, k;

	fp=fopen("eqr","r");

	while (fgets(str, 120, fp)){

		item=strtok(str,"\t");
		d[id].group=atoi(item);

		item=strtok(NULL,"\t");
		strcpy(d[id].fname, item);

		item=strtok(NULL,"\t");
		strcpy(d[id].lname, item);

		item=strtok(NULL,"\t");
		d[id].gen=atoi(item);

		item=strtok(NULL,"\n");
		d[id].age=atoi(item);

		id++;
	}
	fclose(fp);

	struct ug *p = d;
	return p;
}

void sort(int m[4][2]){
	for(int i=0; i<4; i++){
		int f=0;
		for(int c=0; c<3-i; c++){
			int c1 = m[c][1], c2 = m[c+1][1];
			if(c1==c2) continue;
				if(m[c][1]<m[c+1][1]){
				int ee=m[c][1];
				m[c][1]=m[c+1][1];
				m[c+1][1]=ee;

				int mee=m[c-1][2];
				m[c-1][2]=m[c][2];
				m[c][2]=mee;

				f++;
			}
			if(f==0) break;
		}
	}

/*	printf("----------sorted---------------------\n");
	for(int i=0; i<4; i++){
		for(int j=0; j<2; j++)
			printf("%d\t",m[i][j]);
		printf("\n");
	}*/

	write(m);
	//printf("Group containing the most female undergraduates: %d",m[0][0]);
	//return m[0][0];
}

int femdetect(struct ug *st){
	int e, m[4][2];
	m[0][0]=0;
	for(int k=0; k<10; k++){
		if(st[k].gen==0){
	//		printf("%d\n",d[k].group);
			e = st[k].group;
			m[e-1][1]+=1;
			m[e-1][0]=e;
		}
	}
	sort(m);
}

int main(){
	struct ug *st = readstrct();
	femdetect(st);

	return 0;
}

