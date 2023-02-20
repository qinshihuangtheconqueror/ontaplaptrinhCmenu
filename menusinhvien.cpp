#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct SinhVien{
char ten[100];
char lop[100];
double gpa;
int stt;
};
typedef struct SinhVien SinhVien;
//nhap
void nhap(SinhVien *x){
	getchar();
	printf("Nhap ten:"); gets (x->ten);
	printf("Nhap lop:"); gets (x->lop);
		printf("Nhap gpa:"); scanf("%lf", &x->gpa);
	
}
//in
void xuat(SinhVien x){
printf("Ho ten : %s\n", x.ten);
printf("Lop : %s\n", x.lop);
printf("GPA : %.2lf\n", x.gpa);
}

//tim kiem sinh vien
void timkiem(SinhVien a[],int n, char name[]){
	int find=0;
	 for(int i=0;i<n;i++){
	 	if(strcmp(a[i].ten, name)==0){
		 
		 xuat(a[i]);
	 		find=1;
		 }
	 }
	 if(!find){
	 	printf("Thang ngu nay k ton tai, tim lai di !\n");
	 }
}
//nhung sinh vien co GPA cao nhat

void maxGPA(SinhVien a[],int n){
	double max=0;
	for(int i=0;i<n;i++){
		max=fmax(max,a[i].gpa);
		
	}
	printf("Nhung sinh vien co GPA cao nhat la:\n");
	for(int i=0;i<=n;i++){
		if(max==a[i].gpa){
			xuat(a[i]);
		}
	}
}
//xoa thong tin sinhvien
void xoaThongtin(SinhVien a[],int *n, char name[]){
	for(int i=0;i<*n;i++){
		if(strcmp(a[i].ten, name)==0){
			for (int j=i;j<*n-1;j++){
				a[j]=a[j+1];
			}
			break;
			(*n)--;
		}
	}
}
//sapxeptheoGPA giam dan (code trau)
void sxgp(SinhVien a[], int n){
	for(int i=0;i<n;i++){
		int max=i;
		for(int j=i+1;i<n;j++){
			if(a[max].gpa <a[j].gpa)
			max=j;
		}
		SinhVien tmp=a[max];
		a[max]=a[i];
		a[i]= tmp;
		
	}
}
//sap xep gpa giam dan su dung qsort
int cmp(const void*a,const void*b){
	SinhVien*x=(SinhVien*)a;
	SinhVien*y=(SinhVien*)b;
	if(x->gpa != y->gpa){
		if(x->gpa > y->gpa)
		return -1;
		else
		return 1;
	}
	else
	return x->stt - y->stt;
}
//sap xep gpa tang dan su dung qsort
int cmp1(const void*a,const void*b){
	SinhVien*x=(SinhVien*)a;
	SinhVien*y=(SinhVien*)b;
	if(x->gpa != y->gpa){
		if(x->gpa < y->gpa)
		return -1;
		else
		return 1;
	}
	else
	return x->stt - y->stt;
}

int main(){
 SinhVien a[1000];
 int n;
 while(1){
 	printf("-------------------QLSV-------------------\n");
 	printf("1.Nhap danh sach\n");
 	printf("2.Hien thi danh sach\n");
 	printf("3.Tim kiem theo ten\n");
 	printf("4.Liet ke diem cao nhat\n");
 	printf("5.Xoa theo ten\n");
 	printf("6. Sap xep theo GPA giam dan\n");
 	printf("7. Sap xep theo GPA tang dan\n");
	printf("0- Thoat !\n");
 	printf("--------------------------------------------\n");
 	printf("Xin moi lua chon:");
 	int lc;
 	scanf("%d",&lc);
 	if(lc == 1){
 		printf("Nhap so luong sinh vien:");
 		scanf("%d",&n);
 		for(int i=0;i<n;i++){
 			nhap(&a[i]);
		 }
	 }
	 else if(lc==2){
	 	printf("Danh sach sinh vien:  \n");
	 	for(int i=0;i<n;i++){
	 		xuat(a[i]);
		 }
	 }
	 else if(lc==3){
	 	
		 char name[100];
	 	getchar();
		 printf("May can tim ai ?\n");
	 	gets(name);
	 	timkiem(a,n,name);
	 }
	 else if(lc==4){
	 	maxGPA(a,n);
	 }
	 else if(lc==5){
	 	char name[100];
	 	getchar();
	 	printf("Nhap thang m muon xoa:\n");
	 	gets(name);
	 	xoaThongtin(a,&n,name);
	 }
	 else if(lc==6){
	 	qsort(a,n,sizeof(SinhVien),cmp);
    	
	}
    else if(lc==7){
    	qsort(a,n,sizeof(SinhVien),cmp1);
    	}
	else if(lc==0){
    	printf("Cam on da su dung dich vu nay, cut !");
    	break;
	}
	
	 
 }
 return 0;
}



