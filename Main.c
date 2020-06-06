#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<dos.h>
void mainMenu();
void studentPage(char *c, int l);
void staffPage(char *c, int l);
void addMember();
void signIn();
void deleteMember();
int size(FILE *fp);

void signUp()
{
  printf("Ask a staff to add you as a member.\n");
  mainMenu();
}
void addMember()
{
  FILE *fp;
  int w;
  char name[25];
  char id[25],pass[25];
  printf("What member account do you want to add?\nChoose an option:\n1-Student\n2-Staff\n3-Faculty\n4-Back to Main Menu\n");
  scanf("%d",&w);
  switch(w)
  {
     case 1 : fp=fopen("Student.txt","a+");
              break;
     case 2 : fp=fopen("Staff.txt","a+");
              break;
     case 3 : fp=fopen("Faculty.txt","a+");
              break;
     case 4 : mainMenu();
              break;
     default : printf("Invalid Option\nChoose again\n");
              signUp();
  }
  printf("\n");gets(id);
  printf("Enter member's name: \n");
  gets(name);
  printf("Create a user id for member: \n");
  gets(id);
  printf("Create password for member: \n");
  gets(pass);
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
  printf("The member has been added successfully.\nReturning to Sign In page....");
  fclose(fp);
  signIn();
}
void signIn()
{
  int w;
  FILE *fp;
  char id[32]="UserId=",pass[34]="Password=";
  printf("Choose an option:\n1-Student\n2-Faculty\n3-Staff\n4-Back to Main Menu\n");
  scanf("%d",&w);
  switch(w)
  {
     case 1 : fp=fopen("Student.txt","r");
              break;
     case 3 : fp=fopen("Staff.txt","r");
              break;
     case 2 : fp=fopen("Faculty.txt","r");
              break;
     case 4 : mainMenu();
              break;
     default : printf("Invalid Option\nReturning to Main Menu..\n");
               mainMenu();

  }
  char c[25];
  gets(c);
  printf("Enter your UserId: \n");
  gets(c);
  strcat(id,c);
  printf("Enter your Password: \n");
  gets(c);
  strcat(pass,c);
  char rid[32],rpass[34],rname[30];
  int flag=0;
  while(!feof(fp))
  {
   fgets(rname,30,fp);
   fgets(rid,32,fp);
   fgets(rpass,34,fp);
   if(strncmp(rid,id,strlen(rid)-1)==0)
   {
     if(strncmp(rpass,pass,strlen(rpass)-1)==0)
     {
       flag=1;break;
     }
   }
 }
 fclose(fp);
 if (flag==1)
 {
   if((w==1)|(w==2)) studentPage(rname,strlen(rname));
   else if(w==3) staffPage(rname,strlen(rname));
 }
 else{ printf("Incorrect userid or password.\nReturning to Main menu....");
 mainMenu();}
}
void mainMenu()
{
  int choice=0;
  printf("Choose an Option:\n1.Sign In\n2.Sign Up\n3.Exit\n");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1: signIn();
            break;
    case 2: signUp();
            break;
    case 3: exit(0);
            break;
    default: printf("Invalid Option\nChoose again\n");
            mainMenu();
  }
}
void studentPage(char *c, int l)
{
  char name[25];
  for(int i=5;i<=l;i++)
  {
    name[i-5]=c[i];
  }
  printf("Welcome %s",name);
  printf("Newly added books to the library:\n");
}
void staffPage(char *c,int l)
{
  char name[25];
  for(int i=5;i<=l;i++)
  {
    name[i-5]=c[i];
  }
  printf("Welcome %s",name);
  printf("What do you want to do?\nChoose an option.\n");
  bool flag=true;
  while(flag)
  {
    printf("1-Add a member\n2-Delete a member\n3-Add a book\n4-Delete a book\n");
    printf("5-Order a book\n6-Check Inventory\n");
    int w=0;
    scanf("%d",&w);
    switch(w)
    {
      case 1:addMember();flag=false;break;
      case 2:deleteMember();flag=false;break;
      //case 3:addBook();flag=false;break;
      //case 4:deleteBook();flag=false;break;
      //case 5:orderBook();flag=false;break;
      //case 6:inventory();flag=false;break;
      default:printf("Invalid option...Try again\n");
    }
  }
}
void deleteMember()
{
printf("Which member do you want to delete?\n");
int w=0;
FILE *fp1,*fp2,*fp3;
bool flag=true;
while(flag)
{
  printf("Choose an option..\n1-Student\n2-Faculty\n3-Staff\n");
  scanf("%d",&w);
  switch(w)
  {
     case 1 : fp1=fopen("Student.txt","r");fp2=fopen("Student.txt","r");flag=false;
              break;
     case 3 : fp1=fopen("Staff.txt","r");fp2=fopen("Staff.txt","r");flag=false;
              break;
     case 2 : fp1=fopen("Faculty.txt","r");fp2=fopen("Faculty.txt","r");flag=false;
              break;
     default : printf("Invalid Option\nTry again..\n");
  }
}
fp3=fopen("temp.txt","w");
printf("Enter the User Id of the member to be deleted:\n");
char uid[50], name[50],id[50],pass[50];
gets(id);gets(id);
strcpy(uid,"UserId=");
strcat(uid,id);
flag =true;
//check if this user has issued some book if yes flag=false
if(flag)
{
  int i=0;char ch;
  while(!feof(fp1))
  {
    ch=fgetc(fp1);
    for(i=0;ch!='\n';i++)
    {
      ch=fgetc(fp1);
    }
    fgets(name,i+1,fp2);printf("%s\n",uid);
    ch=fgetc(fp1);
    for(i=0;ch!='\n';i++)
    {
      ch=fgetc(fp1);
    }
    fgets(id,i+1,fp2);printf("%s\n",name);
    ch=fgetc(fp1);
    for(i=0;ch!='\n';i++)
    {
      ch=fgetc(fp1);
    }
    fgets(pass,i+1,fp2);printf("%s\n",pass);
    if(strncmp(uid,id,strlen(uid))!=0)
    {
      fputs(name,fp3);
      fputs(uid,fp3);
      fputs(pass,fp3);
    }
  }
printf("HI");
fclose(fp1);
fclose(fp2);
fclose(fp3);
//if(w==1) { remove("Student.txt"); rename("temp.txt","Student.txt");}
//if(w==2) { remove("Faculty.txt"); rename("temp.txt","Faculty.txt");}
//if(w==3) { remove("Staff.txt"); rename("temp.txt", "Staff.txt");}
}
}
int main()
{
  mainMenu();
}
