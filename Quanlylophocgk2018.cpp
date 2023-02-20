#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define max 200
struct TKB{

int classID;
char course[30];

char room[10];
int day;
char slot [7];
int stt;
};
typedef struct TKB TKB;

void nhap(TKB *x){
	printf("Enter the classID: ");
            scanf("%i",&x->classID);
            getchar();
    printf("Enter Course:"); gets (x->course);
	printf("Enter room: "); gets (x->room);
	do{
               printf("Enter the Day: ");
                scanf("%i",&x->day);
            }while(x->day<2||x->day>7);
	printf("Enter slot:");
            getchar();
            gets(x->slot);
            printf("\n");

}


//in
void xuat(TKB x){
printf("%-20d%-40s%-15s%-15i%-15s\n",x.classID,x.course,x.room,x.day,x.slot);
}
//timkiem
void timkiem(TKB a[],int n, char room[]){
	int find=0;
	 for(int i=0;i<n;i++){
	 	if(strcmp(a[i].room, room)==0){
		 
		 xuat(a[i]);
	 		find=1;
		 }
	 }
	 if(!find){
	 	printf("Khong hop le, tim lai !\n");
	 }
}
//sapxep
int cmp1(const void*a,const void*b){
	TKB*x=(TKB*)a;
	TKB*y=(TKB*)b;
	if(x->classID != y->classID){
		if(x->classID < y->classID)
		return -1;
		else
		return 1;
	}
	else
	return x->stt - y->stt;
}
void check(TKB a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
      for(int j=i+1;j<n;j++)
      {
          int num1= atoi(a[i].slot+2);
          int num2= atoi(a[i].slot+0);
          if(strcmp(a[i].room,a[j].room)==0&&a[i].day==a[j].day&&num1>=num2)
          {
              printf("%i\n%i\n",a[i].classID,a[j].classID);

              return;
          }
      }
    }
}
int main(){
 TKB a[1000];
 int n;
 int cnt=0;
 while(1){
 	printf("-------------------Quan ly lop hoc-------------------\n");
 	printf("1.Nhap danh sach.\n");
 	printf("2.Hien thi danh sach.\n");
 	printf("3.Tim kiem theo phong.\n");
 	printf("4.Sap xep.\n");
 	printf("5.Kiem tra trung phong.\n");
	printf("6. Thoat !\n");
 	printf("--------------------------------------------\n");
 	printf("Xin moi lua chon:");
 	int lc;
 	scanf("%d",&lc);
 	if(lc == 1){
 		int tmp;
            do{
                printf("Enter the number of class added: ");
                scanf("%i",&n);
                tmp=cnt+n;
            }while(tmp>max);
            for(int i=cnt;i<tmp;i++)
                {
                    nhap(&a[i]);
                }
                cnt=tmp;
            }
            
	 else if(lc==2){
	 	printf("Thong tin lop hoc:  \n");
	 	printf("%-20s%-40s%-15s%-15s%-15s\n","Ma lop","Ten mon hoc","Ten phong","Thu","Tiet hoc");
		 for(int i=0;i<cnt;i++){
			 xuat(a[i]);
		 }
	 }
	 else if(lc==3){
	 	
		 char name[100];
	 	getchar();
		 printf("Nhap phong can tim:\n");
	 	gets(name);
	 	timkiem(a,n,name);
	 }
	 else if(lc==4){
	 	qsort(a,n,sizeof(TKB),cmp1);
    	
	}
    else if(lc==5){
        check(a,cnt);
    	}
   
	else if(lc==6){
    	printf("Cam on da su dung dich vu nay !");
    	break;
	}
	else printf("Nhap lai !\n");
	 
 }
 return 0;
}

