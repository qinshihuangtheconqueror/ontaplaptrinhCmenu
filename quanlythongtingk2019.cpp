#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct{
char name[30];
char id[12];
char hometown[30];
float gpa;
int stt;
}quanly;

void nhap(quanly *x){
	getchar();
	printf("Enter the name: "); gets (x->name); 
	printf("Enter id: "); gets (x->id);
	printf("Enter hometown: "); gets (x->hometown);
	do{
               printf("Enter the GPA: ");
                scanf("%f",&x->gpa);
            }while(x->gpa<0||x->gpa>4);
    printf("\n");
}
void xuat(quanly x, int n){
printf("%-20d%-40s%-15s%-15s%-15.1f\n",n,x.name,x.id,x.hometown,x.gpa);
}
void timkiem(quanly a[],int n, char id[]){
	int find=0;
	 for(int i=0;i<n;i++){
	 	if(strcmp(a[i].id, id)==0){
		printf("%-20s%-40s%-15s%-15s%-15s\n","STT","Ten","MSSV","QueQuan","GPA");
		 xuat(a[i],i+1);
	 		find=1;
		 }
	 }
	 if(!find){
	 	printf("Khong hop le, tim lai !\n");
	 }
}
void timkiem2(quanly a[],int n,char hometown[],float tb){
		int find=0;
		printf("Danh sach sinh vien co diem GPA hon trung binh ( %.1f ) la:\n",tb);
		for (int i = 0; i < n; i++) {
        if (a[i].gpa > tb && strcmp(a[i].hometown, hometown)==0 ) {
             	
            	printf("%-20s%-40s%-15s%-15s%-15s\n","STT","Ten","MSSV","QueQuan","GPA");
		 xuat(a[i],i+1);
	 		find=1;
		 }
	 }
	 if(!find){
	 	printf("Khong hop le, tim lai !\n");
	 }
}
int cmp(const void*a,const void*b){
	quanly*x=(quanly*)a;
	quanly*y=(quanly*)b;
	if(x->gpa != y->gpa){
		if(x->gpa > y->gpa)
		return -1;
		else
		return 1;
	}
	else
	return x->stt - y->stt;
}
int main(){
 quanly a[1000];
 int n;
 int cnt=0;
 int tb=0;
 while(1){
 	printf("-------------------Quan ly lop hoc-------------------\n");
 	printf("1.Nhap danh sach.\n");
 	printf("2.Hien thi danh sach.\n");
 	printf("3.Tim kiem theo MSSV.\n");
 	printf("4.Tim kiem theo GPA va que quan.\n");
 	printf("5.Sap xep theo GPA giam dan\n");
	printf("6. Thoat !\n");
 	printf("--------------------------------------------\n");
 	printf("Xin moi lua chon:");
 	int lc;
 	scanf("%d",&lc);
 	if(lc == 1){
 		int tmp;
 		
            do{
                printf("Nhap so luong sinh vien: ");
                scanf("%i",&n);
                tmp=cnt+n;
            }while(tmp<0);
            for(int i=cnt;i<tmp;i++)
                {
                    nhap(&a[i]);
                }
                cnt=tmp;
                     
            }
	 else if(lc==2){
	 	printf("Thong tin lop hoc:  \n");
	 	printf("%-20s%-40s%-15s%-15s%-15s\n","STT","Ten","MSSV","QueQuan","GPA");
		 for(int i=0;i<cnt;i++){
			 xuat(a[i],i+1);
			 tb+=a[i].gpa;
		 }
	 }
	 else if(lc==3){
	 	
		 char name[100];
	 	getchar();
		 printf("Nhap ma so sinh vien can tim:\n");
	 	gets(name);
	 	timkiem(a,cnt,name);
	 }
	 else if(lc==4){
	    printf("Nhap que quan ban muon tim:\n");
		char hometown[100];
	    scanf("%s", &hometown);	  
	double dem = 0;
    for (int i = 0; i < cnt; i++) {
        dem += a[i].gpa;
    }
    double tb= dem/cnt;
    
	 timkiem2(a,cnt,hometown,tb);

}
	 else if(lc==5){
	 	qsort(a,cnt,sizeof(quanly),cmp);
	
}
else if(lc==6){
    	printf("Cam on da su dung dich vu nay !");
    	break;

}
}
}
