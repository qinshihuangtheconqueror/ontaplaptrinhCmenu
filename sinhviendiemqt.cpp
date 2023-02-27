#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct{
	char tensv[20];
	float diemqt; 
	float diemck;
	float diemtk;
	char diemxl;
} diemsv;
void nhap(diemsv *x){
	printf("Nhap ten sinh vien: ");
	gets(x->tensv);
	do
	{
		printf("Nhap diem qt:");
		scanf("%f", &x->diemqt);
		getchar();
		if(x->diemqt < 0 || x->diemqt > 10){
			printf("Diem phai trong khoang 0 den 10 !\n");
		}
	} while(x->diemqt < 0 || x->diemqt > 10);

	do
	{
		printf("Nhap diem ck:");
		scanf("%f", &x->diemck);
		getchar();
		if(x->diemck < 0 || x->diemck > 10){
			printf("Diem phai trong khoang 0 den 10 !\n");
		}
	} while(x->diemck < 0 || x->diemck > 10);

	x->diemtk = 0.4 * x->diemqt + 0.6 * x->diemck;

	if(x->diemtk < 4){
		x->diemxl = 'F';
	} else if(4 <= x->diemtk && x->diemtk < 5.5){
		x->diemxl = 'D';
	} else if(5.5 <= x->diemtk && x->diemtk < 7){
		x->diemxl = 'C';
	} else if(7 <= x->diemtk && x->diemtk < 8.5){
		x->diemxl = 'B';
	} else {
		x->diemxl = 'A';
	}
}

void xuat(diemsv x){
	printf("%-20s%-10.2f%-10.2f%-10.2f%-10c\n", x.tensv, x.diemqt, x.diemck, x.diemtk, x.diemxl);
}
void sort(diemsv a[], int n) {
    
    diemsv tmp;
    for(int i = 0;i < n;i++){
        for(int j = i+1; j < n;j++){
            if(a[i].diemtk > a[j].diemtk){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}
void sort1(diemsv a[], int n,int l) {
  int find=0;
    for(int i = 0;i < n;i++){
          if (abs(a[i].diemqt-a[i].diemck)>=l){
          printf("%-20s%-10s%-10s%-10s%-10s","Ten SV","Diem QT","Diem CK","Diem TK", "Xep loai");
	     xuat(a[i]);
	     find=1;
		  }
                    
            }
    if(!find){
      printf("Khong ton tai, tim lai !\n");
    }
    
        }
int main(){
	diemsv x[1000];
int n;
int cnt=0;
int choice;
 int tmp;
 int l;
 int add_more;
 do {
  
printf("Student Menu\n");
printf("1. Nhap\n");
printf("2. In\n");
printf("3. Chenh lech\n");
printf("4. Sap xep\n");
printf("5.Thoat\n");
printf("Xin moi lua chon: ");
scanf("%d",&choice);
switch (choice){
case 1:
	
 		
            do{
                printf("Nhap so luong hoc sinh: ");
                scanf("%i",&n);
                getchar();
                tmp=cnt+n;
                if(n<=0||n>40){
                	printf("So sinh vien phai >0 va <=40 !\n");
				}
            }while(tmp<0||tmp>20);
            for(int i=cnt;i<tmp;i++)
                {
                    
					nhap(&x[i]);
					x[i].diemtk=0.4*x[i].diemqt+0.6*x[i].diemck;
					if(x[i].diemtk<4){
						x[i].diemxl= 'F';
					}
					if(4<=x[i].diemtk<5.5){
						x[i].diemxl='D';
					}
					if(5.5<=x[i].diemtk<7){
						x[i].diemxl='C';
					}
					if(7<=x[i].diemtk<8.5){
						x[i].diemxl='B';
					}
					if(x[i].diemtk>=8.5){
						x[i].diemxl='A';
					}
                }
                cnt=tmp;
                    do {
                    printf("Do you want to enter more teams? (1=Yes, 0=No) ");
                    scanf("%d", &add_more);
                    getchar();
                    if (add_more == 1) {
                        nhap(&x[cnt]);
                        cnt++;
                    }
                } while (add_more != 0);
                break;
             
              
	case 2:
	printf("%-20s%-10s%-10s%-10s%-10s\n","Ten SV","Diem QT","Diem CK","Diem TK", "Xep loai");
					 for(int i=0;i<cnt;i++)
                {
                    
					xuat(x[i]);
                }
		
	break;
	case 3:
  
   do{
            
				printf("Nhap L: ");
                scanf("%i",&l);
                getchar();
                if(l<2||l>5){
                	printf("L >1 va <6 !\n");
				}
            }while(l<2||l>5);
            sort1(x,cnt,l);
            
	

    break;

		case 4:
	   sort(x, cnt);
		break;
			
			case 5:
				 printf("Thanks for using our menu !\n");
				 exit (0);
			break;
default:
printf("Invalid options, please enter between 1 and 6 !\n");  
}
}while (choice != 5);
return 0;
}




