#include<stdio.h>
#include<string.h>
#define max 11
typedef struct mu
{
  int no;
  char name[20];
  char role[5];
  double price;
} manu;

void clear_buffer(){
  int ch;
  while((ch=getchar()) !='\n' && ch!=EOF);
}

int main()
{
  int num,num1;
  printf("Number of official players: ");
  scanf("%d",&num);
  printf("Number of subtitute players: ");
  scanf("%d",&num1);
  manu data[num];
  int i;
  for(i=0;i<num;i++)
    {
      printf("Data management for official player %d\n",i+1);
      printf("Shirt number: ");
      scanf("%d",&data[i].no);
      clear_buffer();
      printf("Name of player: ");
      gets(data[i].name);
      printf("Role of player: ");
      gets(data[i].role);
      printf("Price: ");
      scanf("%lf",&data[i].price);
    }
  manu sub[num1];
  for(i=0;i<num1;i++)
    {
      printf("Data management for reserve player %d\n",i+1);
      printf("Shirt number: ");
      scanf("%d",&sub[i].no);
      clear_buffer();
      printf("Name of player: ");
      gets(sub[i].name);
      printf("Role of player: ");
      gets(sub[i].role);
      printf("Price: ");
      scanf("%lf",&sub[i].price);
    }
  printf("Official team\n");
  printf("%-15s%-15s%-15s%s\n","No","Name","Role","Price");
  for(int i=0;i<num;i++)
    {
      printf("%-15d%-15s%-15s%.0lf$\n",data[i].no,data[i].name,data[i].role,data[i].price);
    }
  printf("\n");
  printf("Reserve team\n");
  printf("%-15s%-15s%-15s%s\n","No","Name","Role","Price");
  for(int i=0;i<num1;i++)
    {
      printf("%-15d%-15s%-15s%.0lf$\n",sub[i].no,sub[i].name,sub[i].role,sub[i].price);
    }

  
  manu tmp;
  int c1,c2;
  printf("Switch player\n");
  printf("Number of player in official team\n");
  scanf("%d",&c1);
  printf("Number of player in reserve team\n");
  scanf("%d",&c2);
  for(i = 0; i < num; i++) {
    if(data[i].no == c1) {
      for(int j = 0; j < num1; j++) {
        if(sub[j].no == c2) {
          manu tmp = data[i];
          data[i] = sub[j];
          sub[j] = tmp;
          break;
        }
      }
      break;
    }
  }
  printf("Official team\n");
  printf("%-15s%-15s%-15s%s\n","No","Name","Role","Price");
  for(int i=0;i<num;i++)
    {
      printf("%-15d%-15s%-15s%.0lf$\n",data[i].no,data[i].name,data[i].role,data[i].price);
    }
  printf("\n");
  printf("Reserve team\n");
  printf("%-15s%-15s%-15s%s\n","No","Name","Role","Price");
  for(int i=0;i<num1;i++)
    {
      printf("%-15d%-15s%-15s%.0lf$\n",sub[i].no,sub[i].name,sub[i].role,sub[i].price);
    }

  printf("\nUpdate position\n");
  int c3,a=0,b=0;
  printf("Shirt number of player to change: ");
  scanf("%d",&c3);
  clear_buffer();
  printf("What is the new position ");
  for(int i=0;i<num+num1;i++)
    {
      if(data[i].no==c3)
	{ gets(data[i].role);
	   printf("Official team\n");
  printf("%-15s%-15s%-15s%s\n","No","Name","Role","Price");
  for(int i=0;i<num;i++)
    {
      printf("%-15d%-15s%-15s%.0lf$\n",data[i].no,data[i].name,data[i].role,data[i].price);
    }
  printf("\n");
	}
	  
      else if(sub[i].no==c3) 
      {
          gets(sub[i].role);
           printf("Reserve team\n");
  printf("%-15s%-15s%-15s%s\n","No","Name","Role","Price");
  for(int i=0;i<num1;i++)
    {
      printf("%-15d%-15s%-15s%.0lf$\n",sub[i].no,sub[i].name,sub[i].role,sub[i].price);
    }
      }
    }

  return 0;
}
