#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct SinhVien{
char ten[50];
char ngaysinh[100];
char diachi[100];
char lop[30];
double gpa;
int stt;
};
typedef struct SinhVien SinhVien;
//nhap
void nhap(SinhVien *x){
	getchar();
    printf("Nhap ten:"); gets (x->ten);
	printf("Nhap ngay sinh:"); gets (x->ngaysinh);
	printf("Nhap dia chi:"); gets (x->diachi);
	printf("Nhap lop:");gets (x->lop);
	printf("Nhap gpa:"); scanf("%lf", &x->gpa);
}
//in
void xuat(SinhVien x){
printf("Ho ten : %s\n", x.ten);
printf("Ngay sinh : %s\n", x.ngaysinh);
printf("Dia chi : %s\n", x.diachi);
printf("Lop: %s\n", x.lop);
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
	 	printf("Khong hop le, tim lai !\n");
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
//sap xep theo tu dien
int cmp2(const void*a,const void*b){
	SinhVien*x=(SinhVien*)a;
	SinhVien*y=(SinhVien*)b;
	if(strcmp(x->ten, y->ten) !=0){
			return strcmp(x->ten,y->ten);
}
	else
	return x->stt - y->stt;
}
//loc theo lop va GPA
void locgpa(SinhVien a[],int n, char id[], int m){
	for(int i=0;i<n;i++){
		if(strcmp(a[i].lop, id)==0 && a[i].gpa>=m){
		xuat(a[i]);
	}
}
}
//duoihoc
void duoihoc(SinhVien a[],int n,int z){
	for(int i=0;i<n;i++){
		if(a[i].gpa>=z)
		xuat(a[i]);
	}
}
//sap xep theo dia chi uu tien gpa, qsort
int cmp3(const void*a,const void*b){
	SinhVien*x=(SinhVien*)a;
	SinhVien*y=(SinhVien*)b;
	if(strcmp(x->lop,y->lop) !=0){
			return strcmp(x->lop,y->lop);
}
	else{
		if(x->gpa > y->gpa){
			return -1;
		}
			else return 1;
		}
	}
//loc ra cac ban sinh trong 1 thang xac dinh
int getMonth(char ns[],int n){
	char tmp[100];
	strcpy(tmp, ns);
	char *token = strtok(tmp, "/");
	token= strtok(NULL, "/");
	if(atoi(token)==n)
	return 1;
	else
	return 0;
	
}
// diem trung binh
void diemtb(SinhVien a[], int n){

double dem = 0;
    for (int i = 0; i < n; i++) {
        dem += a[i].gpa;
    }
    printf("diem trung binh: %.1f",dem/n);

}


int main(){
 SinhVien a[1000];
 int n;
 while(1){
 	printf("-------------------QLSV-------------------\n");
 	printf("1.Nhap danh sach.\n");
 	printf("2.Hien thi danh sach.\n");
 	printf("3.Tim kiem theo ten.\n");
 	printf("4.Liet ke diem cao nhat.\n");
 	printf("5.Xoa theo ten.\n");
 	printf("6.Sap xep theo GPA giam dan.\n");
 	printf("7.Sap xep theo GPA tang dan.\n");
 	printf("8.Sap xep theo ten trong bang chu cai.\n");
 	printf("9.Loc sinh vien theo lop va GPA.\n");
 	printf("10.Duoi hoc theo diem.\n");
 	printf("11.Sap xep theo dia chi uu tien GPA\n");
	printf("12.Tim cac ban sinh trong 1 thang.\n");
	printf("13.Tinh diem trung binh:\n");
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
 			a[i].stt=i;
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
		 printf("Nhap nguoi can tim:\n");
	 	gets(name);
	 	timkiem(a,n,name);
	 }
	 else if(lc==4){
	 	maxGPA(a,n);
	 }
	 else if(lc==5){
	 	char name[100];
	 	getchar();
	 	printf("Nhap nguoi muon xoa:\n");
	 	gets(name);
	 	xoaThongtin(a,&n,name);
	 }
	 else if(lc==6){
	 	qsort(a,n,sizeof(SinhVien),cmp);
    	
	}
    else if(lc==7){
    	qsort(a,n,sizeof(SinhVien),cmp1);
    	}
    else if(lc==8){
    	qsort(a,n,sizeof(SinhVien),cmp2);
    	}
    else if(lc==9){
    	char id[100];
    	int m;
		getchar();
		printf("Vui long cho biet lop cua hoc sinh:\n");
    	gets(id);
		printf("Vui long cho biet gpa cua hoc sinh:\n");
    	scanf("%d", &m);
		locgpa(a,n,id,m);
    	}
    else if(lc==10){
    	int z;
		printf("Vui long cho biet gpa can duoi:\n");
    	scanf("%d", &z);
    	printf("Danh sach nhung sinh vien o lai:\n");
		duoihoc(a,n,z);
    	}
    else if(lc==11){
    	qsort(a,n,sizeof(SinhVien),cmp3);
    }
	else if(lc==12){
		 int n;
		 printf("Nhap thang muon tim:");
		 scanf("%d",&n);
		 for(int i=0;i<n;i++){
    	if(getMonth(a[i].ngaysinh, n)){
    		xuat(a[i]);
	}
}
}
else if(lc==13){
	diemtb(a,n);
	}

	else if(lc==0){
    	printf("Cam on da su dung dich vu nay !");
    	break;
	}
	
	 
 }
 return 0;
}



