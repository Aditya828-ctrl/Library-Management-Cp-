#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#include<time.h>

#include"studentPage.h"

#define MAX_YR 2020
#define MIN_YR 1940

typedef struct
{
  int yyyy;
  int mm;
  int dd;
}Date;

struct member
{
  char name[50];
  char id[50];
  char pass[50];
  char dob[50];
  struct member *next;
};
struct member *header[3];

typedef struct
{
        char stu_fname[30];
        char stu_lname[40];
        char stu_id[30];
        char stu_npass[30];
        char stu_dob[30];
        char stu_orgdob[30];
}detail;

void mainMenu();
void student(char *, char *);
void staffPage(char *, char *);
void addMember();
void signIn();
void deleteMember();
void uploadMembers();
char* teme();
void passwordChange(int);
void loadMembers();
int isValidDate(Date *validDate);
void acpt_decline(int a);
void pssrqst();

void loadMembers()
{
        struct member *p,*current,*prev;
        header[0]=(struct member*)malloc(sizeof(struct member));
        p=header[0];
        FILE *fp1,*fp2,*fp3,*fp4;
        fp1=fopen("StudentName.txt","r"); if(fp1==NULL) printf("NULL");
        fp2=fopen("StudentId.txt","r"); if(fp2==NULL) printf("NULL");
        fp3=fopen("StudentPass.txt","r"); if(fp3==NULL) printf("NULL");
        fp4=fopen("StudentDob.txt","r"); if(fp4==NULL) printf("NULL");
        fgets(p->name,50,fp1);
        //f(p->id,50,fp2);
        fscanf(fp2,"%s", p->id);
        fscanf(fp3,"%s", p->pass);
        //fgets(p->pass,50,fp3);
        fgets(p->dob,12,fp4);
        while(true)
        {
         current=(struct member *)malloc(sizeof(struct member));
         p->next=current;
         prev=p;
         p=current;
         if(fgets(p->name,50,fp1)==NULL)
         {
           p=NULL;
           current=NULL;
           prev->next=NULL;
           break;
         }
         fscanf(fp2,"%s", p->id);
         fscanf(fp3,"%s", p->pass);
         fgets(p->dob,12,fp4);
       }
        //free(p);
        //free(current);
        fclose(fp1);
        fclose(fp2);
        fclose(fp3);
        fclose(fp4);
        header[1]=(struct member*)malloc(sizeof(struct member));
        p=header[1];
        fp1=fopen("FacultyName.txt","r"); if(fp1==NULL) printf("NULL");
        fp2=fopen("FacultyId.txt","r"); if(fp2==NULL) printf("NULL");
        fp3=fopen("FacultyPass.txt","r"); if(fp3==NULL) printf("NULL");
        fp4=fopen("FacultyDob.txt","r"); if(fp4==NULL) printf("NULL");
        fgets(p->name,50,fp1);
        fscanf(fp2,"%s", p->id);
        fscanf(fp3,"%s", p->pass);
        fgets(p->dob,12,fp4);
        while(true)
        {
         current=(struct member *)malloc(sizeof(struct member));
         p->next=current;
         prev=p;
         p=current;
         if(fgets(p->name,50,fp1)==NULL)
         {
           p=NULL;
           current=NULL;
           prev->next=NULL;
           break;
         }
         fscanf(fp2,"%s", p->id);
         fscanf(fp3,"%s", p->pass);
         fgets(p->dob,12,fp4);
       }
        //free(p);
        //free(current);
        fclose(fp1);
        fclose(fp2);
        fclose(fp3);
        fclose(fp4);
        header[2]=(struct member*)malloc(sizeof(struct member));
        p=header[2];
        fp1=fopen("StaffName.txt","r"); if(fp1==NULL) printf("NULL");
        fp2=fopen("StaffId.txt","r"); if(fp2==NULL) printf("NULL");
        fp3=fopen("StaffPass.txt","r"); if(fp3==NULL) printf("NULL");
        fp4=fopen("StaffDob.txt","r"); if(fp4==NULL) printf("NULL");
        fgets(p->name,50,fp1);
        fscanf(fp2,"%s", p->id);
        fscanf(fp3,"%s", p->pass);
        fgets(p->dob,12,fp4);
        while(true)
        {
         current=(struct member *)malloc(sizeof(struct member));
         p->next=current;
         prev=p;
         p=current;
         if(fgets(p->name,50,fp1)==NULL)
         {
           p=NULL;
           current=NULL;
           prev->next=NULL;
           break;
         }
         fscanf(fp2,"%s", p->id);
         fscanf(fp3,"%s", p->pass);
         fscanf(fp4,"%s",p->dob);
       }
        //free(p);
        //free(current);
        fclose(fp1);
        fclose(fp2);
        fclose(fp3);
        fclose(fp4);
}
void signUp()
{
  printf("Ask a staff to add you as a member.\n");
  mainMenu();
}
void addMember()
{
        struct member *current,*p;
        //loadMembers();//to be deleted
        printf("Enter the type of member to be added...\n\n1.Student\t2-Faculty\t3-Staff\n\n");
        char ch[2];
        scanf("%s",ch);
        int w=atoi(ch); int i;
        switch(w)
        {
        case 1: i=0; break;
        case 2: i=1; break;
        case 3: i=2; break;
        default: printf("Only 1,2,3 are acceptable values\n"); sleep(2); system("clear"); addMember();
        }
        char name[50],id[50],pass[50],*dob;
        //bool flag1=true,flag2=false;
        printf("Enter member's name:\t");
        fgets(name,50,stdin);
        fgets(name,50,stdin);
        //while(flag1)
        //{
        printf("\nCreate UserId of member:\t");
        fgets(id,50,stdin);
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
        printf("\nCreate a password:\t");
        fgets(pass,50,stdin);
        int var=0;
        while(var==0)
        {
                dob=teme();
                var=atoi(dob);//////////////////////////
        }
        p=(struct member*)malloc(sizeof(struct member));
        current=header[i];
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
        //free(p);
        uploadMembers();
        printf("Uploaded\n");
  signIn();
}
void signIn()
{
        printf("\n\t\t\t\t\t\t\t\t -------\n");
        printf("\t\t\t\t\t\t\t\t Sign In\n");
        printf("\t\t\t\t\t\t\t\t -------\n\n\n\n");
        printf("\nChoose the account type:\n\n");
        printf("1.Student\t2.Faculty\t3.Staff\n\n");
        int i;
        scanf("%d",&i);
        i=i-1;
        char id[50],pass[50];
        printf("\nEnter your UserId:\t");
        setvbuf(stdout, NULL, _IONBF, 0);
        fscanf(stdin,"%s", id);printf("(%s)",id);
        printf("\nEnter your Password:\t");
        fscanf(stdin,"%s", pass);printf("(%s)",pass);
        struct member *current;
        current=header[i];
        int cmp1,cmp2;
        //exit(0);
        bool flag=false;
        while(current!=NULL)
        {
                cmp1=strcmp(current->id,id);
                cmp2=strcmp(current->pass,pass);
                if(cmp1==0&&cmp2==0)
                {
                        flag=true; break;
                }
                current=current->next;
        }
        if(flag)
        {
                printf("\nLogged in successfully...\n");
                if(i==0&&i==1) student(current->name,current->id);
                if(i==2) staffPage(current->name,current->id);
        }
        else
        {
                printf("\nNo such record found\n\n");
                printf("Press 1 to apply for Password Change Request...\n");
                printf("\nPress any other key to try again");
                fflush(stdout);
                for(int j=0; j<2; j++)
                {
                        sleep(1);
                        printf("..");
                }
                printf("\n");
                int w;
                scanf("%d",&w);
                if(w==1) passwordChange(i);
                else
                {
              system("clear");signIn();
        }}
      signIn();
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
void student(char *name, char *id)
{
  printf("Welcome %s",name);
  studentPage(id);

}
void staffPage(char *name,char *id)
{
  //char name[25];
  //for(int i=5;i<=l;i++)
  //{
    //name[i-5]=c[i];
  //}
  printf("Welcome %s",name);
  printf("What do you want to do?\nChoose an option.\n");
  bool flag=true;
  while(flag)
  {
    printf("1-Add a member\n2-Delete a member\n3-Add a book\n4-Delete a book\n");
    printf("5-Order a book\n6-Check Inventory\n7-Check Password Change requests\n");
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
      case 7:pssrqst();flag=false;break;
      default:printf("Invalid option...Try again\n");
    }
  }
}
void deleteMember()
{
  char id[50];
  printf("Enter the UserId of the member to be deleted:\n");
  fgets(id,50,stdin);
  //loadMembers();
  printf("\nChoose the account type:\n\n");
  printf("1.Student\t2.Faculty\t3.Staff\n\n");
  int i;
  scanf("%d",&i);
  i=i-1;
  bool found=false;
  struct member *current,*prev;
  current=header[i];
  if(strcmp(id,header[i]->id)==0)
  {
    header[i]=header[i]->next;
    found=true;
  }
  else
  {
    current=header[i]->next;
    prev=header[i];
  }
  while(!found&&current!=NULL)
  {
    if(strcmp(id,current->id)==0)
    {
      prev->next=current->next;
      current=NULL;
      found=true;
      break;
    }
    prev=current;
    current=current->next;
  }
  if(found)
  {
    printf("Member deleted");
  /*  current=head[i];
   while(current->next!=NULL)
    {
      prev=current;
      current=current->next;
    }
    prev->next=NULL;
    current=NULL;*/
  }
  else printf("No such member exists.\n");
  uploadMembers();
}
void uploadMembers()
{
  struct member *current;
  FILE *fp1,*fp2,*fp3,*fp4;
  fp1=fopen("StudentName1.txt","w+");if(fp1==NULL) printf("NULL");
  fp2=fopen("StudentId1.txt","w+");
  fp3=fopen("StudentDob1.txt","w+");
  fp4=fopen("StudentPass1.txt","w+");
  current=header[0];
  while(current!=NULL)
  {
    fputs(current->name,fp1);
    fputs(current->id,fp2);
    fputs(current->dob,fp3);
    fputs(current->pass,fp4);
    current=current->next;
  }
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);
  fclose(fp4);
  remove("StudentName.txt");
  remove("StudentDob.txt");
  remove("StudentPass.txt");
  remove("StudentId.txt");
  rename("StudentName1.txt","StudentName.txt");
  rename("StudentId1.txt","StudentId.txt");
  rename("StudentPass1.txt","StudentPass.txt");
  rename("StudentDob1.txt","StudentDob.txt");
  fp1=fopen("FacultyName1.txt","w+");
  fp2=fopen("FacultyId1.txt","w+");
  fp3=fopen("FacultyDob1.txt","w+");
  fp4=fopen("FacultyPass1.txt","w+");
  current=header[1];
  while(current!=NULL)
  {
    fputs(current->name,fp1);
    fputs(current->id,fp2);
    fputs(current->dob,fp3);
    fputs(current->pass,fp4);
    current=current->next;
  }
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);
  fclose(fp4);
  remove("FacultyName.txt");
  remove("FacultyDob.txt");
  remove("FacultyPass.txt");
  remove("FacultyId.txt");
  rename("FacultyName1.txt","FacultyName.txt");
  rename("FacultyId1.txt","FacultyId.txt");
  rename("FacultyPass1.txt","FacultyPass.txt");
  rename("FacultyDob1.txt","FacultyDob.txt");
  fp1=fopen("StaffName1.txt","w+");
  fp2=fopen("StaffId1.txt","w+");
  fp3=fopen("StaffDob1.txt","w+");
  fp4=fopen("StaffPass1.txt","w+");
  current=header[2];
  while(current!=NULL)
  {
    fputs(current->name,fp1);
    fputs(current->id,fp2);
    fputs(current->dob,fp3);
    fputs(current->pass,fp4);
    current=current->next;
  }
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);
  fclose(fp4);
  remove("StaffName.txt");
  remove("StaffDob.txt");
  remove("StaffPass.txt");
  remove("StaffId.txt");
  rename("StaffName1.txt","StaffName.txt");
  rename("StaffId1.txt","StaffId.txt");
  rename("StaffPass1.txt","StaffPass.txt");
  rename("StaffDob1.txt","StaffDob.txt");
}
char* teme()
{
        Date getDate = {0}; //variable to store date
        int status = 0; //variable to check status
        setvbuf(stdout, NULL, _IONBF, 0);//get date year,month and day from user
        printf("\n\n Enter date in format (day/month/year): ");
        setvbuf(stdout, NULL, _IONBF, 0);
        scanf("%d/%d/%d",&getDate.dd,&getDate.mm,&getDate.yyyy);
        char *dataString; // Enough space for DD-MM-YYYY plus the required nul-terminator
        dataString = (char *)malloc(sizeof(char));
        //rum = (char *)malloc(sizeof(char));
        //rum="$%^"//check date validity
      //  printf("%s\n",rum );
        status = isValidDate(&getDate);
        if(status !=1)
        {
                printf("\n\nPlease enter a valid date!\n");
                setvbuf(stdout, NULL, _IONBF, 0);
                dataString="0";
                //sprintf(dataString, "%02d-%02d-%04d\n", getDate.dd, getDate.mm, getDate.yyyy);
                printf("%s\n",dataString );
                return dataString;
        }
        else
        {
                printf("\n\n Date is valid!\n");
                sprintf(dataString, "%02d-%02d-%04d\n", getDate.dd, getDate.mm, getDate.yyyy);
                printf("%s\n",dataString );
                return dataString;

        }

}
void passwordChange(int i)//i=0->Student,i=1->Faculty,i=2->Staff
{
        system("clear");
        printf("\t\t\t\t\t\t\t\t ------------------------\n");
        printf("\t\t\t\t\t\t\t\t Password Reset Request(s)\n");
        printf("\t\t\t\t\t\t\t\t ------------------------\n\n\n\n");
        FILE *fp2;
        fp2=fopen("StudentId.txt","r"); if(fp2==NULL) printf("NULL");
        int Nl = 0,ch1,var=0,var2=-1;
        char line[1024],input[255],*ch_;
        ch_= (char*)malloc(sizeof(char));
        while( fgets(line,1023,fp2) != NULL)
        {
                Nl++;
        }
        //  printf("%d\n",Nl );
        rewind(fp2);
        char id[50],npass[50],*dob,*nme,*odob;
        dob = (char *)malloc(sizeof(input));
        nme = (char *)malloc(sizeof(Date));
        odob = (char *)malloc(sizeof(Date));
        //id = (char *)malloc(sizeof(Date));
        printf("Enter your UserId:\t");
        //gets(id);
        //gets(id);
        // scanf("%[^\n]%*c", id);
        fscanf(stdin,"%s", id);
        printf("<%s>", id);

        fscanf(fp2,"%s", input);
        printf("<%s>", input);
        int cmp;
        int i1=strlen(id);
        int i2=strlen(input);


        printf("<%d> <%d>",i1,i2);
        printf("<%s>\n<%s>\n",input,id );
        for(int z=0; z<Nl; z++)
        {
                cmp=strcmp(input,id);
                printf("<%d>\n",cmp );
                if(cmp> 0 || cmp <0)
                {
                        cmp=9;
                }
                if(cmp==0)
                {
                        var2=z;
                        cmp++;
                        break;
                }
                fgets(input, sizeof(input), fp2);
                printf("%d\n %d\n",var2,cmp );
                //input[strcspn(input, "\n")] = '\0';
        }
        printf("<%s>\n<%s>\n",input,id );
        printf("%d\n %d\n",var2,cmp );
        if(cmp!=1)
        {
                printf("No matching UserID found\n\n1. Become a member\t\t2. Try again\n\n");
                scanf("%s",ch_);
                ch1=atoi(ch_);
                //if(ch1==1)    //Aditya ka kaam
                if (ch1==2) {
                        system("clear");
                        passwordChange(i);
                }
                if(ch1==0 || ch1!=2 || ch1!=1)
                {
                        printf("Not a valid option\n\nTry Again");
                        for(int j=0; j<3; j++)
                        {
                                sleep(1);
                                printf(".");
                        }
                        system("clear");
                        passwordChange(i);
                }
        }
        //printf("\nEnter your DateOfBirth in the format DD-MM-YYYY:\n");
        while(var==0)
        {
                dob=teme();
                var=atoi(dob);
                printf("%d\n",var );//////////////////////////
        }
        printf("%s %d\n",dob,var );
        printf("\nEnter the new password:\t");
        gets(npass);
        gets(npass);
        fclose(fp2);
        //Aayush kaa kaam
        FILE *lname;
        FILE *id_;
        FILE *n_pass;
        FILE *n_dob;
        FILE *o_dob;
        FILE *f_nme;
        FILE *o_dob_r;
        //  int count;
        // fname = fopen("ps_rqt/fname.txt", "r+");
        lname = fopen("ps_rqt/lname.txt", "a");
        f_nme = fopen("StudentName.txt", "r");
        o_dob = fopen("StudentDob.txt", "r");
        o_dob_r=fopen("ps_rqt/StudentDob.txt", "a");
        id_ = fopen("ps_rqt/id.txt", "a");
        n_pass = fopen("ps_rqt/n_pass.txt", "a");
        n_dob = fopen("ps_rqt/dob.txt", "a");
        sprintf(id, "%s\n", id);
        sprintf(npass, "%s\n", npass);
        fputs(id,id_);
        fputs(dob,n_dob);
        fputs(npass,n_pass);
        for(int q=0; q<=var2; q++)
        {
                fgets (nme, 60, f_nme);
                fscanf(o_dob,"%s",odob);
        }
        printf("%s_ %s\n",nme,odob );
        sprintf(odob, "%s\n", odob);
        //printf("<%s> <%s> <%s> <%s> <%s>\n",nme,odob,id,npass,dob );
        //sprintf(dataString, "%02d-%02d-%04d\n", getDate.dd, getDate.mm, getDate.yyyy);
        fputs(nme,lname);
        fputs(odob,o_dob_r);
        printf("\n\nYour request saved successfully.\n\nWait for a Staff member to approve it.");
        system("clear");
        fclose(lname);
        fclose(id_);
        fclose(n_dob);
        fclose(n_pass);
        fclose(f_nme);
        fclose(o_dob);
        fclose(o_dob_r);
        signIn();
}
int  IsLeapYear(int year)
{
        return (((year % 4 == 0) &&
                 (year % 100 != 0)) ||
                (year % 400 == 0));
}
// returns 1 if given date is valid.
int isValidDate(Date *validDate)
{
        //check range of year,month and day
        if (validDate->yyyy > MAX_YR ||
            validDate->yyyy < MIN_YR)
                return 0;
        if (validDate->mm < 1 || validDate->mm > 12)
                return 0;
        if (validDate->dd < 1 || validDate->dd > 31)
                return 0;
        //Handle feb days in leap year
        if (validDate->mm == 2)
        {
                if (IsLeapYear(validDate->yyyy))
                        return (validDate->dd <= 29);
                else
                        return (validDate->dd <= 28);
        }
        //handle months which has only 30 days
        if (validDate->mm == 4 || validDate->mm == 6 ||
            validDate->mm == 9 || validDate->mm == 11)
                return (validDate->dd <= 30);
        return 1;
}
void pssrqst()
{
        FILE *lname;
        FILE *id;
        FILE *n_pass;
        FILE *dob;
        //  int count;
        // fname = fopen("ps_rqt/fname.txt", "r+");
        lname = fopen("ps_rqt/lname.txt", "r+");
        id = fopen("ps_rqt/id.txt", "r+");
        n_pass = fopen("ps_rqt/n_pass.txt", "r+");
        dob = fopen("ps_rqt/dob.txt", "r+");

        int Nl = 0;
        char line[1024];
        while( fgets(line,1023,id) != NULL)
        {
                Nl++;
        }

        rewind(id);
        //printf("%d",Nl);          //to check total numbers of entries
        printf("\t\t\t\t\t\t\t\t ------------------------\n");
        printf("\t\t\t\t\t\t\t\t Password Reset Request(s)\n");
        printf("\t\t\t\t\t\t\t\t ------------------------\n\n\n\n");

        detail *stu;
        stu = (detail*)malloc(sizeof(detail));

        for (int i = 0; i < Nl; i++)
        {

                fgets(stu->stu_lname,39,lname);
                fscanf(id, "%s", stu->stu_id);
                fscanf(n_pass, "%s", stu->stu_npass);
                fscanf(dob, "%s", stu->stu_dob);
                printf("--------------------------------------------------\n");
                printf("%d. | Name : ",i+1);
                fputs(stu->stu_lname,stdout);
                printf("   | UserID : %s\n",stu->stu_id);
                // printf("   | New_Password: %s\n",stu->stu_npass);
                // printf("   | DOB : %s\n",stu->stu_dob);
                printf("--------------------------------------------------\n");
        }
        printf("\n\n");
        printf("#. Main Menu\t\t\t0. Previous Menu\n\n");
        fclose(lname);
        fclose(id);
        fclose(n_pass);
        fclose(dob);

        char *choose;
        printf("\n\nSelect one option:\t");
        choose = (char*)malloc(sizeof(char));
        scanf("%s",choose);
        // printf("%s",choose);

        int choice=atoi(choose);
        // printf("%d",choice);
        for(int i=0; i<Nl; i++)
        {
                if(choice==(i+1))
                {
                        system("clear");
                        acpt_decline(choice);
                        //return 0;
                }
                else if (strcmp(choose, "#") == 0)
                {
                        pssrqst();    //need to link to admin home page
                }
                else if(i+1==Nl)
                {
                        //printf("Enter a valid option:\t");
                        printf("Invalid option; Choose again ");
                        for(int j=0; j<3; j++)
                        {
                                sleep(1);
                                printf(".");
                        }
                        system("clear");
                        pssrqst();

                }
        }

}

void acpt_decline(int a)
{
        FILE *lname;
        FILE *id;
        FILE *n_pass;
        FILE *dob;
        FILE *rep;
        FILE *orgdob;
        FILE *pass;
        orgdob = fopen("ps_rqt/StudentDob.txt","r");
        pass = fopen("StudentPass.txt","r");
        rep = fopen("ps_rqt/rep.txt", "w+");
        lname = fopen("ps_rqt/lname.txt", "r");
        id = fopen("ps_rqt/id.txt", "r");
        n_pass = fopen("ps_rqt/n_pass.txt", "r");
        dob = fopen("ps_rqt/dob.txt", "r");

        detail *stu;
        stu = (detail*)malloc(sizeof(detail));

        char ch;
        int delete_line = a, temp = 1;

        printf("\t\t\t\t\t\t\t\t ------------------------\n");
        printf("\t\t\t\t\t\t\t\t Password Reset Request(s)\n");
        printf("\t\t\t\t\t\t\t\t ------------------------\n\n\n\n");
        int i;
        for (i = 0; i < a; i++)
        {

                fgets(stu->stu_lname, 39, lname);
                fscanf(id, "%s", stu->stu_id);
                fscanf(n_pass, "%s", stu->stu_npass);
                fscanf(dob, "%s", stu->stu_dob);
                fscanf(orgdob,"%s",stu->stu_orgdob);

        }
        fclose(lname);
        fclose(dob);
        fclose(n_pass);
        fclose(id);
        fclose(orgdob);


        FILE *studentid;
        char line[1024],input[255];
        int Nl,cmp,var2=-1;
        studentid = fopen("StudentId.txt","r"); if(studentid==NULL) printf("NULL");
        while( fgets(line,1023,studentid) != NULL)
        {
                Nl++;
        }
//printf("%d\n",Nl);
        rewind(studentid);
        fgets(input,sizeof(input),studentid);
        input[strcspn(input, "\n")] = '\0';
        for(int z=0; z<Nl; z++)
        {
                cmp=strcmp(input,stu->stu_id);
                //printf("%d\n",cmp );
                if(cmp==1 || cmp==-1)
                {
                        cmp=9;
                }
                if(cmp==0)
                {
                        var2=z+1;
                        cmp++;
                        break;
                }
                fgets(input,sizeof(input),studentid);
                input[strcspn(input, "\n")] = '\0';
        }
        //printf("%d\n %d\n",var2,cmp );
        //printf("<%s> <%s>\n",stu->stu_id,input);
        //printf("<%s>\n",stu->stu_npass );
//sprintf(stu->stu_npass, "%s\n",stu->stu_npass);
        //printf("<%s>\n",stu->stu_npass );

        printf("--------------------------------------------------\n");
        printf("%d. | Name : ", i);
        fputs(stu->stu_lname, stdout);
        printf("   | UserID : %s\n", stu->stu_id);
        printf("   | New_Password: %s\n", stu->stu_npass);
        printf("   | DOB : %s\n   | Original_DOB: %s\n", stu->stu_dob,stu->stu_orgdob);
        printf("--------------------------------------------------\n\n\n");
        printf("1. Accept\t\t\t2. Decline\n\n");
        char *chopt;
        chopt = (char *)malloc(sizeof(char));
        int opt;
        printf("Enter valid option:\t");
        scanf("%s",chopt);
        opt=atoi(chopt);
        //printf("%d\n",opt);

        lname = fopen("ps_rqt/lname.txt", "r");
        id = fopen("ps_rqt/id.txt", "r");
        n_pass = fopen("ps_rqt/n_pass.txt", "r");
        dob = fopen("ps_rqt/dob.txt", "r");
        orgdob = fopen("ps_rqt/StudentDob.txt","r");

        if (opt==1)
        {
                ch = getc(lname);
                while (ch != EOF)
                {
                        if(temp != delete_line)
                                putc(ch, rep);
                        if (ch == '\n')
                                temp++;
                        ch = getc(lname);
                }
                fclose(lname);
                fclose(rep);
                remove("ps_rqt/lname.txt");
                rename("ps_rqt/rep.txt","ps_rqt/lname.txt");

                temp=1;
                rep = fopen("ps_rqt/rep.txt", "w+");
                ch = getc(id);
                while (ch != EOF)
                {
                        if(temp != delete_line)
                                putc(ch, rep);
                        if (ch == '\n')
                                temp++;
                        ch = getc(id);
                }
                fclose(id);
                fclose(rep);
                remove("ps_rqt/id.txt");
                rename("ps_rqt/rep.txt","ps_rqt/id.txt");

                temp=1;
                rep = fopen("ps_rqt/rep.txt", "w");
                ch = getc(dob);
                while (ch != EOF)
                {
                        if(temp != delete_line)
                                putc(ch, rep);
                        if (ch == '\n')
                                temp++;
                        ch = getc(dob);
                }
                fclose(dob);
                fclose(rep);
                remove("ps_rqt/dob.txt");
                rename("ps_rqt/rep.txt","ps_rqt/dob.txt");

                temp=1;
                rep = fopen("ps_rqt/rep.txt", "w");
                ch = getc(n_pass);
                while (ch != EOF)
                {
                        if(temp != delete_line)
                                putc(ch, rep);
                        if (ch == '\n')
                                temp++;
                        ch = getc(n_pass);
                }
                fclose(n_pass);
                fclose(rep);
                remove("ps_rqt/n_pass.txt");
                rename("ps_rqt/rep.txt","ps_rqt/n_pass.txt");

                temp=1;
                rep = fopen("ps_rqt/rep.txt", "w");
                ch = getc(orgdob);
                while (ch != EOF)
                {
                        if(temp != delete_line)
                                putc(ch, rep);
                        if (ch == '\n')
                                temp++;
                        ch = getc(orgdob);
                }
                fclose(orgdob);
                fclose(rep);
                remove("ps_rqt/StudentDob.txt");
                rename("ps_rqt/rep.txt","ps_rqt/StudentDob.txt");

                temp=1;
                //FILE *rep2;
                sprintf(stu->stu_npass, "%s\n",stu->stu_npass);
                rep = fopen("rep.txt", "w");
                ch = getc(pass);
                while (ch != EOF)
                {
                        if(temp != var2)
                                putc(ch, rep);
                        //printf("%c",ch );
                        if(ch == '\n' && temp==var2) {
                                //fputs(stu->stu_npass,rep);
                                fprintf(rep,"%s",stu->stu_npass);
                                //printf("%s",stu->stu_npass);
                        }
                        if (ch == '\n')
                                temp++;
                        ch = getc(pass);
                }
                fclose(pass);
                fclose(rep);
// sleep(200);
                remove("StudentPass.txt");
                rename("rep.txt","StudentPass.txt");
                printf("Returning to Previous Menu");
                for(int j=0; j<3; j++)
                {
                        sleep(1);
                        printf(".");
                }
                system("clear");
                pssrqst();

        }

        else if (opt==2)
        {
                printf("\n\nReturning to Previous Menu");
                for(int j=0; j<3; j++)
                {
                        sleep(1);
                        printf(".");
                }
                system("clear");
                pssrqst();
        }
        else
        {
                printf("Invalid option; Choose again");
                for(int j=0; j<3; j++)
                {
                        sleep(1);
                        printf(".");
                }
                system("clear");
                acpt_decline(a);
        }

}
int main()
{
  loadMembers();
  mainMenu();
}
