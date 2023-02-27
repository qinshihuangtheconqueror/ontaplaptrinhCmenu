#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define max 30


typedef struct{
	int id;
	char nation[4];
	char name[max];
	float results[3];
	float final;
	int stt;
}vdv;
void nhap1(vdv *x){
	printf("Enter the ID: ");
	scanf("%d", &x->id);
	getchar();
	printf("Enter the Nation: ");
	gets(x->nation);
	printf("Enter the name: ");
	gets(x->name);
	
}
void xuat1(vdv x){
	printf("%-10d%-16s%-16s\n",x.id, x.nation, x.name);
}
void xuat2(vdv x){
	printf("%-10d%-16s%-16s%4.2f%10.2f%10.2f%10.2f\n", x.id, x.nation, x.name, x.results[0], x.results[1], x.results[2], x.final);    
	
}
void xuat21(vdv x){
	printf("%-10d%-16s%-16s%4.2f\n", x.id, x.nation, x.name, x.results[0]);    
	
}
void xuat22(vdv x){
	printf("%-10d%-16s%-16s%4.2f%10.2f\n", x.id, x.nation, x.name, x.results[0], x.results[1]);    
	
}


int cmp1(const void*a,const void*b){
	vdv*x=(vdv*)a;
	vdv*y=(vdv*)b;
	if(x->final != y->final){
		if(x->final < y->final)
		return -1;
		else
		return 1;
	}
	else
	return x->stt - y->stt;
}

void timkiem1(vdv a[],int n, char room[]){
	int find=0;
	 for(int i=0;i<n;i++){
	 	if(strcmp(a[i].nation, room)==0){
		 
		 xuat2(a[i]);
	 		find=1;
		 }
	 }
	 if(!find){
	 	printf("Error, find again !\n");
	 }
}
void timkiem2(vdv a[],int n, char room[]){
	int find=0;
	 for(int i=0;i<n;i++){
	 	if(strcmp(a[i].name, room)==0){
		 
		 xuat2(a[i]);
	 		find=1;
		 }
	 }
	 if(!find){
	 	printf("Error, find again !\n");
	 }
}
void sapxep(vdv a[], int n) {
    vdv tmp;
    for(int i = 0;i < n;i++){
        for(int j = i+1; j < n;j++){
            if(a[i].final < a[j].final){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

int main(){
	vdv x[1000];
int n;
int cnt=0;
int choice;
do {
printf("Olympic Menu\n");
printf("1.Enter the informations.\n");
printf("2. Print\n");
printf("3. Battle.\n");
printf("4.Find.\n");
printf("5.Print result.\n");
printf("6.Quit.\n");
printf("Enter your choice:");
scanf("%d",&choice);
switch (choice){
case 1:
	int tmp;
 		
            do{
                printf("Enter the number for teams: ");
                scanf("%i",&n);
                tmp=cnt+n;
                if(n<0||n>20){
                	printf("Invalid, enter between 1 and 20 !\n");
				}
            }while(tmp<0||tmp>20);
            for(int i=cnt;i<tmp;i++)
                {
                    nhap1(&x[i]);
                }
                cnt=tmp;
                     
              break;
	case 2:
		printf("%-10s%-16s%-16s%-10s%-10s%-10s%-10s\n","ID","Nation","Name","R1","R2","R3","FR");
		for(int i=0;i<cnt;i++)
                {
                    xuat1(x[i]);
                }
		break;
	case 3:
    
	int i;
    for (i = 0; i < cnt; i++) {
        printf("Enter results for athlete %d (%s %s):\n", x[i].id,
            x[i].nation, x[i].name);
        printf("R1: ");
        scanf("%f", &x[i].results[0]);
        getchar();
    }
    printf("%-10s%-16s%-16s%-10s%-10s%-10s%-10s\n","ID","Nation","Name","R1","R2","R3","FR");
    for(int i=0;i<cnt;i++)
    {
        xuat21(x[i]);
    }

    for (i = 0; i < cnt; i++) {
        printf("Enter results for athlete %d (%s %s):\n", x[i].id,
            x[i].nation, x[i].name);
        printf("R2: ");
        scanf("%f", &x[i].results[1]);
        getchar();
    }
    printf("%-10s%-16s%-16s%-10s%-10s%-10s%-10s\n","ID","Nation","Name","R1","R2","R3","FR");
    for(int i=0;i<cnt;i++)
    {
        xuat22(x[i]);
    }

    for (i = 0; i < cnt; i++) {
        printf("Enter results for athlete %d (%s %s):\n", x[i].id,
            x[i].nation, x[i].name);
        printf("R3: ");
        scanf("%f", &x[i].results[2]);
        getchar();
        float max_result = x[i].results[0];
        if (x[i].results[1] > max_result) {
            max_result =x[i].results[1];
        }
        if (x[i].results[2] > max_result) {
            max_result =x[i].results[2];
        }
       x[i].final = max_result;
    }
    

    printf("%-10s%-16s%-16s%-10s%-10s%-10s%-10s\n","ID","Nation","Name","R1","R2","R3","FR");
    for(int i=0;i<cnt;i++)
    {
        xuat2(x[i]);
    }

    break;

			case 4:;
			 do {
printf("Mini menu:\n");
printf("1.Find according to nations\n");
printf("2.Find according to name\n");
			 int choice1;
			 scanf("%d",&choice1);
switch (choice1){
        case 1:
		char name[100];
	 	getchar();
		 printf("Enter the name of the nation:\n");
	 	gets(name);
	 	timkiem1(x,n,name);
        break;
		case 2:
			 char name1[100];
	 	getchar();
		 printf("Enter the name of the player:\n");
	 	gets(name1);
	 	timkiem2(x,n,name1);
			 break;}
			 }while(choice != 2);
			break;
			case 5:;
			sapxep(x,cnt);
				printf("%-10s%-16s%-16s%-10s%-10s%-10s%-10s\n","ID","Nation","Name","R1","R2","R3","FR");
		for(int i=0;i<cnt;i++)
                {
                    xuat2(x[i]);
                }
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


