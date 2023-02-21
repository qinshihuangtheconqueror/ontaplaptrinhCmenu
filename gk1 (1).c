#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
int gcd(int m, int n)
{
    if(n==0)
        return m;
    return gcd(n,m%n);
}
void main1()
{
    int m,n;
    scanf("%i%i",&m,&n);
    int MAX=gcd(m,n);
    printf("%i\n",MAX);

}
void main2()
{
    int n;
    scanf("%i",&n);
    int tmp=n/n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {

            printf("+-----");
            if(j==n-1)
            printf("+");
        }
        printf("\n");
        for(int z=0;z<n+1;z++)
        {
            if(z!=n)
            printf("|   %-2i",tmp++);
            else
            printf("|     ");

        }
        printf("\n");
        if(i==n-1)
            for(int j=0;j<n;j++)
        {

            printf("+-----");
            if(j==n-1)
            printf("+");
        }
    }

}
double calu(double n,double a[])
{
    double u=1/n;
    double sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }
    return (double)u*sum;
}
double calo(double n,double a[])
{
    double sum=0;
    double u= (1/n);
    for(int i=0;i<n;i++)
    {
        sum+=(a[i]-calu(n,a))*(a[i]-calu(n,a));
    }
    return (double)sqrt(sum*u);
}
int main3()
{
    double o;
    double u;
    int n;
    scanf("%i",&n);
    double a[n];
    for(int i=0;i<n;i++)
        scanf("%lf",&a[i]);
    double m=calu(n,a);
    printf("%lf",calo(n,a));
}
char s[100];
int cnt(char n,char s[])
{
    int cnt1=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]==n)
            ++cnt1;
    }
    return cnt1;
}
int main4()
{
    char s[100];
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
    {
       if(i!=0)
       {
           int cnt2=0;
               for(int j=0;j<i;j++)
               {

                   if(s[j]==s[i])
                    ++cnt2;

               }
               if(cnt2==0)
                     printf("%c : %i\n",s[i],cnt(s[i],s));
       }
       else
        printf("%c : %i\n",s[i],cnt(s[i],s));

    }

}


int main()
{
    printf("1.Frequency\n");
    printf("2.Fibonacci\n");
    printf("3.Password\n");
    printf("4.Date\n");
    printf("Enter the option: \n");
    int n;
    scanf("%i",&n);
    if(n==1)
        main1();

    if(n==2)
    main2();
    if(n==3)
    main3();
    if(n==4)
    main4();

}
