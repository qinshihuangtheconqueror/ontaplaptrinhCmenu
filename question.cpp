#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define max 20


typedef struct{
long id;
int chapter;
char content[51];
}question;
void nhap1(question *x){
	printf("Enter question: ");
	scanf("%d %[^\n]”", &x->chapter,x->content);
	getchar();
}
void xuat1(question x){
	printf("%-6d%-6d%-8s\n",x.id,x.chapter,x.content);
}
void search(question a[],int n, int tmp){
	int find=0;
	 for(int i=0;i<n;i++){
	 	if(a[i].id== tmp){
		  printf("%-6s%-6s%-8s\n","ID","Chap","Content");
		 xuat1(a[i]);
	 		find=1;
		 }
	 }
	 if(!find){
	 	printf("Error, find again !\n");
	 }
}
void add(question x[], int n)
{
    n++;
    printf("\nEnter the question to add:");
    x[n-1].id = n;
    scanf("%d %[^\n]", &x[n-1].chapter, x[n-1].content);
    getchar();
    printf("\nQuestion list:\n");
    printf("%-6s%-6s%-8s\n","ID","Chap","Content");
    for(int i=0; i<n ; i++)
    {
        xuat1(x[i]);
    }
}
void count(question a[], int n){
    int count[max] = {0};
    for(int i=0;i<n;i++){
        count[a[i].chapter]++;
    }
    printf("%-6s%-6s\n","Chap","Count");
    for(int i=1;i<=max;i++){
        if(count[i]>0){
            printf("%-6d%-6d\n",i,count[i]);
        }
    }
}
void check(question x[], int n){
    printf("%-6s%-6s%-8s\n","ID","Chap","Content");
    for(int i=0; i<n ; i++){
        if(isupper(x[i].content[0]) && !strchr(x[i].content,'*') && !strchr(x[i].content,'$') && !strchr(x[i].content,'\\')){
            xuat1(x[i]);
        }
    }
}
int main(){
	question x[1000];
int n;
int cnt=0;
int choice;
do {
printf("Question Menu\n");
printf("1.Read\n");
printf("2. Search\n");
printf("3. Add\n");
printf("4.Count\n");
printf("5.Check\n");
printf("6.Exit\n");
printf("Enter your choice:");
scanf("%d",&choice);
switch (choice){
case 1:
	int tmp;
 		
            do{
                printf("Enter the number for questions: ");
                scanf("%i",&n);
                tmp=cnt+n;
                if(n<=0||n>100){
                	printf("Must be >0 and <=100 !\n");
				}
            }while(tmp<0||tmp>20);
            for(int i=cnt;i<tmp;i++)
                {
                    x[i].id=i+1;
					nhap1(&x[i]);
                }
                cnt=tmp;
                    printf("%-6s%-6s%-8s\n","ID","Chap","Content");
					 for(int i=0;i<tmp;i++)
                {
                    
					xuat1(x[i]);
                }
                cnt=tmp;
              break;
              
	case 2:
		int s;
		printf("Enter the id to search:");
		scanf("%d",&s);
		
		search(x, cnt, s );
		
	break;
	case 3:
		add(x,cnt);
    
	

    break;

		case 4:
				count(x, cnt);
		break;
			case 5:;
		check(x,cnt);
		break;
			break;
			case 6:
				 printf("Thanks for using our menu !\n");
				 exit (0);
			break;
default:
printf("Invalid options, please enter between 1 and 6 !\n");  
}
}while (choice != 6);
return 0;
}


