#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct{
	char hoten[20];
	int cccd; 
	int sdt;
	float nhietdo;
	float ha1;
	float ha2;
} tiem;
void nhap(tiem *x){
	printf("Nhap ten: ");
	gets(x->hoten);
     printf("Nhap cccd:");
		scanf("%d", &x->cccd);
		getchar();
 printf("Nhap sdt:");
		scanf("%d", &x->sdt);
		getchar();
 printf("Nhap nhiet do:");
		scanf("%f", &x->nhietdo);
		getchar();
 printf("Nhap ha1: ");
 	scanf("%f", &x->ha1);
		getchar();
		 printf("Nhap ha2: ");
 	scanf("%f", &x->ha2);
		getchar();
}

void xuat(tiem x, int i){
	printf("%-10d%-20s%-20d%-20d\n", i+1, x.hoten, x.cccd, x.sdt);
}
void check(tiem x[], int n){
    int count = 0;
    printf("Nhung nguoi du dieu kien tiem la:\n");
    printf("%-10s%-20s%-20s%-20s\n", "STT", "Hoten", "CCCD", "SDT");
    printf("---------------------------------------------------------------\n");
    for(int i=0;i<n;i++){
        if (x[i].nhietdo >= 36.8 && x[i].nhietdo <= 38
            && x[i].ha1 > 100 && x[i].ha1 < 130
            && x[i].ha2 > 79 && x[i].ha2 < 89) {
            xuat(x[i], count);
            count++;
        }
    }
    if(count == 0){
        printf("Khong co ai du dieu kien tiem !\n");
    }
}
void timkiem(tiem a[],int n, int m){
	int find=0;
	 for(int i=0;i<n;i++){
	 	if(a[i].sdt==m){
		 
		 printf("%-20s%-20d%-20d%-20f%-20d%-20d\n", a[i].hoten,a[i].cccd,a[i].sdt,a[i].nhietdo,a[i].ha1,a[i].ha2);
	 		find=1;
		 }
	 }
	 if(!find){
	 	printf("Khong hop le, tim lai !\n");
	 }
}
int main(){
	tiem x[1000];
int n;
int cnt=0;
int choice;
int add_more;
int tmp;
int z;
do {
printf("Menu tiem phong\n");
printf("1. Nhap\n");
printf("2. In\n");
printf("3. Kiem tra \n");
printf("4. In du dieu kien\n");
printf("5. Tra cuu\n");
printf("6. Thoat.\n");
printf("Xin moi lua chon: ");
scanf("%d",&choice);
switch (choice){
case 1:
 		
            do{
                printf("Nhap so luong tiem: ");
                scanf("%i",&n);
                getchar();
                tmp=cnt+n;
                if(n<=0||n>200){
                	printf("So nguoi tiem phai >0 va <=200 !\n");
				}
            }while(tmp<=0||tmp>200);
            for(int i=cnt;i<tmp;i++)
                {
                    
					nhap(&x[i]);
				
					}
                
                cnt=tmp;
                do {
                    printf("Ban co muon nhap them khong ? (1= Co, 0= Khong) ");
                    scanf("%d", &add_more);
                    if (add_more == 1) {
                        nhap(&x[cnt]);
                        cnt++;
                    }
                } while (add_more != 0);
            
                    
              break;
              
	case 2:
	printf("%-10s%-20s%-20s%-20s\n", "STT", "Hoten", "CCCD", "SDT");
	printf("---------------------------------------------------------------\n");
					
					 for(int i=0;i<cnt;i++)
                {
                    
					xuat(x[i], i);
                }
		
	break;
	case 3:

      check(x, cnt);
    break;

		case 4:
	  
		break;
			
			case 5:
				printf("Nhap SDT:");
				scanf("%d", &z);
				getchar();
				timkiem(x, cnt,z);
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



