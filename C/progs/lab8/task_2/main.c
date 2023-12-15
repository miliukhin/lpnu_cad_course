#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct fruits
{
	int id;
	char name[20];
	char country[20];
	int p1;
};
int getnum()//scan number of fruits
{
	int i;
	FILE *fp=fopen("in.txt","r");
	fscanf(fp,"%d",&i);
	fclose(fp);
	return i;
}
void change_num(int i)//change number of fruits
{
	FILE *fp=fopen("in.txt","w");
	fprintf(fp,"%d",i);
	fclose(fp);
}
struct fruits *read_struct(struct fruits *c)//read arr of structures from file
{
	FILE *fptr = fopen("bin.bin","rb");
	fread(c,sizeof(c[0])*getnum(), 1, fptr);
	fclose(fptr);
	return c;
};
void change_struct(struct fruits *c)//write struct to file
{
	FILE *fptr = fopen("bin.bin","wb");
	fwrite(c,sizeof(c[0])*getnum(), 1, fptr);
	fclose(fptr);
};
void print(struct fruits *c)
{
	int i=getnum();
	//print structure
	for (int j=0;j<i;j++)
		printf("%d)ID=%d\tName=%s\tcountry=%s\tprice=%d\n",j+1, c[j].id,c[j].name,c[j].country,c[j].p1);
}
void add(struct fruits *c)
{
	int i=getnum();
	printf("%d\n",i);
	//adding new structure
	printf("Enter id:");		scanf("%d",  &c[i].id);
	printf("Enter name: ");		scanf("%s", c[i].name);
	printf("Enter country:");	scanf("%s", c[i].country);
	printf("Enter price: ");	scanf("%d", &c[i].p1);
	change_num(++i);

	change_struct(c);
}
void del(struct fruits *c){
	int i=getnum();
	// choosing element
	int a;
	printf("Enter id:");
	scanf("%d", &a);
	for(int j=0;j<i;j++)
	{
		if(c[j].id==a)
		{
			//printf("fruit found\n");
			for(int l=0;l<i-j;l++)
			{
				c[j+l]=c[j+l+1];
			}
			i--;
			change_num(i);
			printf("item deleted\n");
			break;
		}
	}
	change_struct(c);
}
void sort(struct fruits *c, int n)
{
	printf("i - sort by id p - sort by price\n");
	char a[5];
	scanf("%s",&a);
	if(*a=='i' || *a=='p'){
		for(int i=0;i<n;++i){
			int f=0;
			for(int j = 0;j < n-i-1; ++j){
				int dif, c1, c2;
				if(*a=='i')
					c1 = c[j].id, c2 = c[j+1].id;
				if(*a=='p')
					c1 = c[j].p1, c2 = c[j+1].p1;
				if(c1==c2)continue;
				dif = c1 - c2;
				if(dif > 0){
					 struct fruits p = c[j];
					 c[j] = c[j + 1];
					 c[j + 1] = p;
					 f++;
				}
			}
			if(f==0)break;
		}
	}
	change_struct(c);
	print(c);
}
void find(struct fruits *c, int n)
{
	char country_to_find[20];
	printf("Enter country:");
	scanf("%s",country_to_find);
	for(int i=0;i<n;i++)
	{
		int flag=0;
		for(int j=0;j<strlen(c[i].country);j++)
			if(c[i].country[j] == country_to_find[j])
				flag++;

		if(flag==strlen(c[i].country)){
			printf("ID= %d\tName=%s\tcountry=%s\tprice=%d\n", c[i].id,c[i].name,c[i].country,c[i].p1);
			break;
		}
	}

}
void change(struct fruits *c, int n)
{
	printf("i - change id n - change name");
	char a[5];
	int d;//id you are going to find
	int newid;
	char fn[20];//finding name
	char newname[20];
	scanf("%s",a);
	switch ( *a ){
	case 'i':
		scanf("%d",&d);
		for(int i=0;i<n;i++){
			if(c[i].id == d){
				printf("Your id matches name %s\nEnter new id:",c[i].name);
				scanf("%d", &newid);
				c[i].id=newid;
			}
		}
	break;
	case 'n':
		scanf("%s",fn);
		for(int i=0;i<n;i++){
			int flag=0;
			for(int j=0;j<strlen(c[i].name);j++)
				if(c[i].name[j] == fn[j])
					flag++;

			if(flag==strlen(c[i].name)){
				printf("Your name matches id %d\nEnter new name:",c[i].id);
				scanf("%s", newname);
				strcpy(c[i].name,newname);
			}
		}
	}
	change_struct(c);
}
int main()
{
	int i=getnum();
	struct fruits c[i+10];
	read_struct(c);
	char q[5];
	printf("a-append\tc-change\tf-find\tl-list\ts-sort\td-delete\tq-quit\n");
	scanf("%s",q);
	switch ( q[0] ){
		case 'l':print(c); break;
		case 'a':add(c);break;
		case 'd':del(c);break;
		case 's':sort(c,i);break;
		case 'f':find(c,i);break;
		case 'c':change(c,i);break;
		case 'q':return 0;
	}
	main();
}

