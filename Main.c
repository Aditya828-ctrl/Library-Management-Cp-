#include<stdio.h>
#include<string.h>
int signUp()
{
  FILE *fp;
  int w;
  char name[25];
  char id[10],pass[10];
  printf("Enter your name: \n");
  gets(name);
  printf("Create a user id: \n");
  gets(id);
  printf("Enter Password: \n");
  gets(pass);
  printf("Choose an option:\n1-Student\n2-Staff\n");
  scanf("%d",&w);
  switch(w)
  {
     case 1 : fp=fopen("Student.txt","a+");
              break;
     case 2 : fp=fopen("Staff.txt","a+");
              break;
    default : printf("Invalid Option\n");
              return 0;
  }

 char s[30];
 strcpy(s,"Name=");
 strcat(s,name);
 fputs(s,fp);
 strcpy(s,"\nUserId=");
 strcat(s,id);
 fputs(s,fp);
 strcpy(s,"\nPassword=");
 strcat(s,pass);
 strcat(s,"\n");
 fputs(s,fp);
 printf("You have signed up successfully.\nReturning to main menu....");
 fclose(fp);
 return 1;
}
int main()
{
  int a= signUp();
}
