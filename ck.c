#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

typedef struct group{
  char groupID;
  char teamName[4][20];
  int points[4];
  int goals[4];
} group;
int option;
int number_group=0;
group group_infor[8];

int check(char name){
  for(int i=0;i<number_group;i++){
    if(group_infor[i].groupID == name){
      return 0;
    }
    return 1;
  }
}
    

group input(int i){
  group tmp;
  do{
  printf("Enter the name of the group : ");
  scanf("%*c%c",&tmp.groupID);
  }while(((int)tmp.groupID < 64 ||(int)tmp.groupID > 90) && check(tmp.groupID));
  for(int j=0;j<4;j++){
  printf("Enter the name of the team: ");
  char c;
  while((c = getchar()) != '\n');
  gets(tmp.teamName[j]);
  do{
  printf("Enter the points of the team: ");
  scanf("%i",&tmp.points[j]);
  }while(tmp.points[j] < 0);
  printf("Enter the goals of the team: ");
  scanf("%i",&tmp.goals[j]);
  }
    return tmp;
}
  


int main(){
  int current_number = number_group;
  do{
    current_number = number_group;
  printf("-------------------MENU------------------------\n");
  printf("1.Add group \n");
  printf("2.Print all group information \n");
  printf("3.Find a team information \n");
  printf("4.Input match result \n");
  printf("5.Sort order and print group information \n");
  printf("Enter your option: ");
  scanf("%i",&option);
  switch(option){
  case 1:
    int add;
    do{
    printf("Enter the number of group you want to add: ");
    scanf("%i",&add);
    if((number_group + add ) > 8){
      printf("Valid the number of team exceeded the limit \n");
    }else{
    number_group += add;
    }
    }while((number_group ) > 8);

    for(int i=current_number;i<number_group;i++){
      group_infor[i] = input(i);
    }
    break;
  case 2:
   
    for(int i=0;i<number_group;i++){
       printf("%s %c\n","Group: ",group_infor[i].groupID);
              printf("%-20s%-20s%-20s\n","Name","Point","Goal Different");
	      for(int j=0;j<4;j++){
       printf("%-20s%-20i%-20i\n",group_infor[i].teamName[j],group_infor[i].points[j],group_infor[i].goals[j]);
	      }
      
    }
    break;
  case 3:
    char findName[20]; int cnt =0;
    printf("Enter the team name you want to find: \n");
    char c;
    while( (c=getchar()) != '\n');
    gets(findName);
    for(int i=0;i<number_group;i++){
      for(int j=0;j<4;j++){
	if(strcmp(group_infor[i].teamName[j],findName)==0){
	   printf("%-20s%-20s%-20s\n","Name","Point","Goal Different");
	   printf("%-20s%-20i%-20i\n",group_infor[i].teamName[j],group_infor[i].points[j],group_infor[i].goals[j]);
	   ++cnt;
	}
      }
    }
    if(cnt==0){
      printf("The team is not exist \n");
      printf("%s\n",findName);
    }
    break;
  case 4:
    char team1[20],team2[20];
    int goal1,goal2;
    int cnt1 =0;
    int a,b,x,y;
    printf("Input the match result: ");
    scanf("%s",team1);
    scanf("%s",team2);
    scanf("%i",&goal1);
    scanf("%i",&goal2);
     for(int i=0;i<number_group;i++){
       cnt1 =0;
      for(int j=0;j<4;j++){
        if((strcmp(group_infor[i].teamName[j],team1)==0)){
	   ++cnt1;
	   a=i;
	   b=j;
	}
	if((strcmp( group_infor[i].teamName[j],team2)==0)){
	  ++cnt1;
	  x=i;
	  y=j;
	}
		  
      }
		
      if(cnt1 == 2){
		if(goal1 > goal2){
		  group_infor[a].points[b] +=3;
		  group_infor[a].goals[b] += abs(goal1 - goal2);
		   group_infor[x].goals[y] -= abs(goal1 - goal2);
		}
		else if(goal1 == goal2){
		  group_infor[a].points[b] +=1;
		    group_infor[x].points[y] +=1;
		}
		else {
		  group_infor[x].points[y] +=3;
		   group_infor[x].goals[y] += abs(goal1 - goal2);
		   group_infor[a].goals[b] -= abs(goal1 - goal2);
		    }
       printf("%s %c\n","Group: ",group_infor[i].groupID);
              printf("%-20s%-20s%-20s\n","Name","Point","Goal Different");
	      for(int j=0;j<4;j++){
       printf("%-20s%-20i%-20i\n",group_infor[i].teamName[j],group_infor[i].points[j],group_infor[i].goals[j]);
	      }
      
      }
      else printf("Two team are not in the same group \n");
     }
    break;
  case 5:
    for(int a=0;a<number_group;a++){
      for(int i=0;i<3;i++){
      for(int j=i+1;j<4;j++){
	if(group_infor[a].points[i] < group_infor[a].points[j]){
	  int tmp = group_infor[a].points[i];
	  group_infor[a].points[i] = group_infor[a].points[j];
	  group_infor[a].points[j] = tmp;
	  int tmp2 = group_infor[a].goals[i];
	  group_infor[a].goals[i] = group_infor[a].goals[j];
	  group_infor[a].goals[j] = tmp;
	  char name2[20];
	  strcpy(name2,group_infor[a].teamName[i]);
	  strcpy(group_infor[a].teamName[i],group_infor[a].teamName[j]);
	  strcpy(group_infor[a].teamName[j],name2);
	      
	}
	else if(group_infor[a].points[i] ==  group_infor[a].points[j]){
	  if(group_infor[a].goals[i] < group_infor[a].goals[j]){
	     int tmp = group_infor[a].points[i];
	  group_infor[a].points[i] = group_infor[a].points[j];
	  group_infor[a].points[j] = tmp;
	  int tmp2 = group_infor[a].goals[i];
	  group_infor[a].goals[i] = group_infor[a].goals[j];
	  group_infor[a].goals[j] = tmp;
	  char name2[20];
	  strcpy(name2,group_infor[a].teamName[i]);
	  strcpy(group_infor[a].teamName[i],group_infor[a].teamName[j]);
	  strcpy(group_infor[a].teamName[j],name2);
	  }
	  else if(group_infor[a].goals[i] == group_infor[a].goals[j]){
	    if(strcmp(group_infor[a].teamName[i],group_infor[a].teamName[j])==1){
	         int tmp = group_infor[a].points[i];
	  group_infor[a].points[i] = group_infor[a].points[j];
	  group_infor[a].points[j] = tmp;
	  int tmp2 = group_infor[a].goals[i];
	  group_infor[a].goals[i] = group_infor[a].goals[j];
	  group_infor[a].goals[j] = tmp;
	  char name2[20];
	  strcpy(name2,group_infor[a].teamName[i]);
	  strcpy(group_infor[a].teamName[i],group_infor[a].teamName[j]);
	  strcpy(group_infor[a].teamName[j],name2);
	    }
	  }
	}
	     
	    
      }
      }
  }
     for(int i=0;i<number_group;i++){
       printf("%s %c\n","Group: ",group_infor[i].groupID);
              printf("%-20s%-20s%-20s\n","Name","Point","Goal Different");
	      for(int j=0;j<4;j++){
       printf("%-20s%-20i%-20i\n",group_infor[i].teamName[j],group_infor[i].points[j],group_infor[i].goals[j]);
	      }
      
    }
     break;
  default:
    printf("Invalid- Reenter the value from(1-6) \n");
    break;
  }	      
	  
	  
	  
  }while(option != 6);
  return 0;
}
