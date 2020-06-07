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
void forgotPass(char[35],char[35],char[35]);

void signUp()
{
  printf("Ask a staff to add you as a member.\n");
  mainMenu();
}
void addMember()
{
  FILE *fp1,*fp2,*fp3,*fp4;
  int w;
  char name[35];
  char id[35],pass[35],dob[11];
  printf("What member account do you want to add?\nChoose an option:\n1-Student\n2-Staff\n3-Faculty\n4-Back to Main Menu\n");
  scanf("%d",&w);
  switch(w)
  {
     case 1 : fp1=fopen("StudentName.txt","a+");
              fp2=fopen("StudentId.txt","a+");
              fp3=fopen("StudentPass.txt","a");
              fp4=fopen("StudentDob.txt","a+");
              break;
     case 2 : fp1=fopen("StaffName.txt","a+");
              fp2=fopen("StaffId.txt","a+");
              fp3=fopen("StaffPass.txt","a+");
              fp4=fopen("StaffDob.txt","a+");
              break;
     case 3 : fp1=fopen("FacultyName.txt","a+");
              fp1=fopen("FacultyId.txt","a+");
              fp1=fopen("FacultyPass.txt","a+");
              fp1=fopen("FacultyDob.txt","a+");
              break;
     case 4 : mainMenu();
              break;
     default : printf("Invalid Option\nChoose again\n");
              addMember();
  }
  printf("Enter member's name: \n");
  gets(name);
  gets(name);
  printf("Create a user id for member: \n");
  gets(id);
  printf("Create password for member: \n");
  gets(pass);printf("pass%s\n",pass);
  printf("Enter DateOfBirth of the member in the format DD-MM-YYYY\n");
  gets(dob);
  //A Check is needed to make sure dob is in format
  strcat(name,"\n");
  strcat(id,"\n");
  strcat(pass,"\n");
  strcat(dob,"\n");
  fputs(name,fp1);
  fputs(id,fp2);
  fputs(pass,fp3);
  fputs(dob,fp4);
  printf("The member has been added successfully.\nReturning to Sign In page....");
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);
  fclose(fp4);
  signIn();
}
void signIn()
{
  int w;
  FILE *fp1,*fp2,*fp3,*fp4;
  char rname[35],rid[35],rpass[35],rdob[11];
  char id[35],pass[35];
  printf("Choose an option:\n1-Student\n2-Faculty\n3-Staff\n4-Back to Main Menu\n");
  scanf("%d",&w);
  switch(w)
  {
     case 1 : fp1=fopen("StudentName.txt","r");
              fp2=fopen("StudentId.txt","r");
              fp3=fopen("StudentPass.txt","r");
              fp4=fopen("StudentDob.txt","r");
              break;
     case 3 : fp1=fopen("StaffName.txt","r");
              fp2=fopen("StaffId.txt","r");
              fp3=fopen("StaffPass.txt","r");
              fp4=fopen("StaffDob.txt","r");
              break;
     case 2 : fp1=fopen("FacultyName.txt","r");
              fp2=fopen("FacultyId.txt","r");
              fp3=fopen("FacultyPass.txt","r");
              fp4=fopen("FacultyDob.txt","r");
              break;
     case 4 : mainMenu();
              break;
     default : printf("Invalid Option\nTry again\n");
               signIn();

  }
  printf("Enter your UserId: \n");
  gets(id);
  gets(id);
  printf("Enter your Password: \n");
  gets(pass);
  int flag1=0,flag2=0;
  while(!feof(fp1))
  {
   fgets(rname,35,fp1);
   fgets(rid,35,fp2);
   fgets(rpass,35,fp3);
   fgets(rdob,35,fp4);
   if((strncmp(rid,id,strlen(rid)-1)==0)&&(strncmp(rpass,pass,strlen(rpass)-1)==0))
   {
     flag2=1;flag1=1;break;
   }
   else if(strncmp(rid,id,strlen(rid)-1)==0)
   {
     printf("Id matched\n");
     flag1=1;break;
   }
 }

 fclose(fp1);
 fclose(fp2);
 fclose(fp3);
 fclose(fp4);
 if (flag1==1&&flag2==1)
 {
   if((w==1)|(w==2)) studentPage(rname,strlen(rname));
   else if(w==3) staffPage(rname,strlen(rname));
 }
 else if(flag1==1){
    printf("Incorrect Password.\n");
    printf(" Choose an option \n 1.Try again\n 2.Forgot Password\n Option 1 will be taken by default.\n");
    int ch=0;
    scanf("%d",&ch);
    if(ch==2) forgotPass(rname,rid,rdob);
    else
    {
      printf("Invalid credentials ..Try again\n");
      signIn();
    }
 }
}
void forgotPass(char name[35],char id[35],char dob[35])
{
  printf("Enter your DateOfBirth");
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
  printf("Welcome %s",c);
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
  while(!feof(fp1))
  {
    fgets(name,30,fp2);
    fgets(id,32,fp2);
    fgets(pass,34,fp2);
    if(strncmp(uid,id,strlen(id)-1)==0)
    {
      printf("Found,Deleted");
    }
    else
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
