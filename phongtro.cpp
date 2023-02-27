#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#define max 30


typedef struct {
  char name[5];
  int dt;
  int dh;
} tro;

void nhap(tro *x) {
  do {
    printf("Nhap ten phong tro: ");
    
    gets(x->name);
    if (strlen(x->name) != 4) {
      printf("Nhap 4 ki tu !\n");
    }
  } while (strlen(x->name) != 4);

  do {
    printf("Nhap dien tich: ");
    scanf("%d", &x->dt);
    getchar();
    if (x->dt < 10 || x->dt > 40) {
      printf("Trong khoang 10-40 m2!\n");
    }
  } while (x->dt < 10 || x->dt > 40);

  do {
    printf("Nhap dieu hoa (0 hoac 1): ");
    scanf("%d", &x->dh);
    getchar();
  if (x->dh != 0 && x->dh != 1) {
      printf("Chi nhan 0 va 1 !\n");
    }
  
  } while (x->dh != 0 && x->dh != 1);

  }  


void xuat1(tro x) {
  printf("%-20s%-20d%-20s\n", x.name, x.dt, "Co" );
  
}
void xuat2(tro x) {
  printf("%-20s%-20d%-20s\n", x.name, x.dt, "Khong" );
  
}

void find(tro b[], int p, int l) {
	int find=0;
	 for(int i=0;i<p;i++){
	 	if (abs(b[i].dt - l) == 5) {
       if(b[i].dh==1){
					
					xuat1(b[i]);
                }
                else if(b[i].dh==0){
                	xuat2(b[i]);
                }
				
						
		 
		 
	 		find=1;
		 }
	}
	 
	 if(!find){
	 	printf("Khong hop le, tim lai !\n");
	 }
}

void sort(tro z[], int g) {
  tro tmp;
  for (int i = 0; i < g; i++) {
    for (int j = i + 1; j < g; j++) {
      if (z[i].dt > z[j].dt) {
        tmp = z[i];
        z[i] = z[j];
        z[j] = tmp;
      }
    }
  }
}	   

int main(){
	tro  x[1000];
int n;
int cnt=0;
int choice;
 int tmp;
 int l;
 int a;
 int b;
 int c;
 int d;
 int k;
int add_more;
do {
printf("Quan ly phong tro\n");
printf("1. Nhap\n");
printf("2. In\n");
printf("3. Tim kiem\n");
printf("4. Sap xep\n");
printf("5.Bo sung dieu hoa\n");
 printf("6.Thoat\n");
 printf("Xin moi lua chon: ");
scanf("%d",&choice);
switch (choice){
case 1:
       
 		
            do{
                printf("Nhap so luong phong tro: ");
                scanf("%i",&n);
                getchar();
                tmp=cnt+n;
                if(n<=0){
                	printf("So phong tro phai >0 !\n");
				}
            }while(tmp<0);
            for(int i=cnt;i<tmp;i++)
                {
                    
					nhap(&x[i]);
			        
					}
                
                cnt=tmp;
                       do {
                    printf("Ban muon nhap them tro khong ? (1=Yes, 0=No)\n ");
                    scanf("%d", &add_more);
                    getchar();
                    if (add_more == 1) {
                        nhap(&x[cnt]);
                        cnt++;
                    }
                } while (add_more != 0);
                break;
              
              
	case 2:
	  printf("%-20s%-20s%-20s\n","Ten phong","Dien tich","Dieu Hoa");
	  for(int i=0;i<cnt;i++){
                
                    if(x[i].dh==1){
					
					xuat1(x[i]);
                }
                else if(x[i].dh==0){
                	xuat2(x[i]);
				}
			}
		
	break;
	case 3:
 

            
		 printf("Nhap dien tich can tim: ");
                scanf("%i",&l);
                getchar();
                
                find(x,cnt,l);
		
            
	

    break;

		case 4:
	   sort(x, cnt);
		break;
			case 5:
	    for(k=0;k<cnt;k++){
	    	if(x[k].dh==0){
	    			if(x[k].dt<15){
	    				a++;
	    			}
	    				else if(x[k].dt>15&&x[k].dt<22){
                        b++;
					}
					else if(x[k].dt>22&&x[k].dt<30){
                        c++;
					}
					else if(x[k].dt>30&&x[k].dt<40){
                        d++;
					}
			}
		}
		printf("9000BTU: %d\n", a);
		printf("12000BTU: %d\n",b);
		printf("18000BTU: %d\n",c);
		printf("21000BTU: %d\n",d);
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
