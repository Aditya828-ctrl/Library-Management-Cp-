#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
struct member
{
  char name[50];
  char id[50];
  char pass[50];
  char dob[11];
  struct member *next;
};
struct member *head[3];

void addMember();
void signIn();
void passwordChange(int );
void loadMembers()
{
  struct member *p,*current;
  head[0]=(struct member*)malloc(sizeof(struct member));
  p=head[0];
  FILE *fp1,*fp2,*fp3,*fp4;
  fp1=fopen("StudentName.txt","r");if(fp1==NULL) printf("NULL");
  fp2=fopen("StudentId.txt","r");if(fp2==NULL) printf("NULL");
  fp3=fopen("StudentPass.txt","r");if(fp3==NULL) printf("NULL");
  fp4=fopen("StudentDob.txt","r");if(fp4==NULL) printf("NULL");
  fgets(p->name,50,fp1);
  fgets(p->id,50,fp2);
  fgets(p->pass,50,fp3);
  fgets(p->dob,11,fp4);
  while(!feof(fp1))
  {printf("in while");
    current=(struct member *)malloc(sizeof(struct member));
    p->next=current;
    p=current;
    fgets(p->name,50,fp1);
    fgets(p->id,50,fp2);
    fgets(p->pass,50,fp3);
    fgets(p->dob,11,fp4);
  }
  p->next=NULL;
  //free(p);
  //free(current);
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);
  fclose(fp4);
  head[1]=(struct member*)malloc(sizeof(struct member));
  p=head[1];
  fp1=fopen("FacultyName.txt","r");if(fp1==NULL) printf("NULL");
  fp2=fopen("FacultyId.txt","r");if(fp2==NULL) printf("NULL");
  fp3=fopen("FacultyPass.txt","r");if(fp3==NULL) printf("NULL");
  fp4=fopen("FacultyDob.txt","r");if(fp4==NULL) printf("NULL");
  fgets(p->name,50,fp1);
  fgets(p->id,50,fp2);
  fgets(p->pass,50,fp3);
  fgets(p->dob,11,fp4);
  while(!feof(fp1))
  {
    current=(struct member *)malloc(sizeof(struct member));
    p->next=current;
    p=current;
    fgets(p->name,50,fp1);
    fgets(p->id,50,fp2);
    fgets(p->pass,50,fp3);
    fgets(p->dob,11,fp4);
  }
  p->next=NULL;
  //free(p);
  //free(current);
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);
  fclose(fp4);
  head[2]=(struct member*)malloc(sizeof(struct member));
  p=head[2];
  fp1=fopen("StaffName.txt","r");if(fp1==NULL) printf("NULL");
  fp2=fopen("StaffId.txt","r");if(fp2==NULL) printf("NULL");
  fp3=fopen("StaffPass.txt","r");if(fp3==NULL) printf("NULL");
  fp4=fopen("StaffDob.txt","r");if(fp4==NULL) printf("NULL");
  fgets(p->name,50,fp1);
  fgets(p->id,50,fp2);
  fgets(p->pass,50,fp3);
  fgets(p->dob,11,fp4);
  while(!feof(fp1))
  {
    current=(struct member *)malloc(sizeof(struct member));
    p->next=current;
    p=current;
    fgets(current->name,50,fp1);
    fgets(current->id,50,fp2);
    fgets(current->pass,50,fp3);
    fgets(current->dob,11,fp4);
  }
  p->next=NULL;
  //free(p);
  //free(current);
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);
  fclose(fp4);
}
void addMember()
{
  struct member *current,*p;
  loadMembers();//to be deleted
  printf("Enter the type of member to be added\n1-Student\n2-Faculty\n3-Staff\n");
  char ch[2];
  scanf("%s",ch);
  int w=atoi(ch);int i;
  switch(w)
  {
    case 1: i=0;break;
    case 2: i=1;break;
    case 3: i=2;break;
    default: printf("Only 1,2,3 are acceptable values\n");addMember();
  }
  char name[50],id[50],pass[50],dob[11];
  //bool flag1=true,flag2=false;
  printf("Enter member's name:\n");
  gets(name);gets(name);
  //while(flag1)
  //{
    printf("Create UserId of member:\n");
    gets(id);
    /*current=head[i]->next;
    while(current->next!=NULL)
  {
    if(strcmp(id,current->id)==0)
    {
      printf("Sorry , The UserId isnt available \nTry something else\n");
      flag2=true;
      break;
    }
  }
  if(flag2==false) flag1=false;
}*/
  printf("Create a password:\n");
  gets(pass);
  printf("Enter member's DateOfBirth in the format DD-MM-YYYY\n");
  gets(dob);//need to check if date of birth is in format
  p=(struct member*)malloc(sizeof(struct member));
  current=head[i]->next;
  while(current->next!=NULL)
  {
    current=current->next;
  }
  current->next=p;
  p->next=NULL;
  strcpy(p->name,name);
  strcpy(p->id,id);
  strcpy(p->pass,pass);
  strcpy(p->dob,dob);
  free(p);
  //uploadMembers();
}
void signIn()
{
  printf("Choose the account type.\n");
  printf("1.Student\n2.Faculty\n3.Staff\n");
  int i;
  scanf("%d",&i);
  i=i-1;
  char id[50],pass[50];
  printf("Enter your UserId\n");
  gets(id);
  gets(id);
  printf("Enter your Password\n");
  gets(pass);
  struct member *current;
  current=head[i];
  int cmp1,cmp2;
  bool flag=false;
  while(current!=NULL)
  {
    cmp1=strcmp(id,current->id);
    cmp2=strcmp(pass,current->pass);
    if(cmp1==0&&cmp2==0)
    {
      flag=true;break;
    }
    current=current->next;
  }
  if(flag)
  {
    printf("Logged in successfully...\n");
  }
  else
  {
    printf("No such record found\n");
    printf("Press 1 to apply for Password change request..\n");
    printf("Press any other integer to try again\n");
    int w;
    scanf("%d",&w);
    if(w==1) passwordChange(i);
    else signIn();
  }
}
void passwordChange(int i)//i=0->Student,i=1->Faculty,i=2->Staff
{
  char id[50],pass[50],dob[50];
  printf("Enter your UserId\n");
  gets(id);
  gets(id);
  printf("Enter your DateOfBirth in the format DD-MM-YYYY\n");
  gets(dob);
  printf("Enter the new password\n");
  gets(pass);
  //Aayush kaa kaam
  printf("Your request saved successfully.\nWait for a Staff member to approve it.\n");
}
int main(void)
{
  loadMembers();
signIn();
}
