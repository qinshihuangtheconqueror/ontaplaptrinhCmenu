#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct sinhvien{
	char ten[50];
	char ngaysinh[100];
	char diachi[100];
	double gpa;
	int stt;
    
}sinhvien;
void in(sinhvien a){
	printf("%s %s %s %.2lf\n", a.ten, a.ngaysinh, a.diachi, a.gpa);
}
void sxgp(sinhvien a[],int n){
	for(int i=0;i<n;i++){
		int max=i;
		for(int j=i+1;i<n;j++){
			if(a[max].gpa <a[j].gpa)
			max=j;
		}
		sinhvien tmp=a[max];
		a[max]=a[i];
		a[i]= tmp;
		
	}
}
int cmp(const void*a,const void*b){
	sinhvien*x=(sinhvien*)a;
	sinhvien*y=(sinhvien*)b;
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
	int n;
    scanf("%d",&n);
	sinhvien a[n];
	for(int i=0;i<n;i++){
		getchar();
		gets(a[i].ten);
		gets(a[i].ngaysinh);
		gets(a[i].diachi);
		scanf("%lf", &a[i].gpa);
		a[i].stt=i;
	    }
    qsort(a,n,sizeof(sinhvien),cmp);
    for(int i=0;i<n;i++){
    	in(a[i]);
    	
	}
    
}
