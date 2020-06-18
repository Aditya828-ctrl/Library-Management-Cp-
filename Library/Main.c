#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#include<time.h>
#include<ctype.h>

#define MAX_YR 2020
#define MIN_YR 1940

typedef struct cartbook
{
  int issue;
  char id[50];
  struct cartbook *next;
}cartstruct;
typedef struct odr{
  char au_name[50];
  char bk_name[60];
  char qty[30];
  int odrid;
  char stat[30];
  char vndr[30];
  char gen[30];
  struct odr *next;
}order;//declared a structure of type order
typedef struct reqbook
{
  char title[100];
  char auname[100];
  char id[50];
  struct reqbook *next;
}reqstruct;
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
typedef struct
{
        char stu_fname[30];
        char stu_lname[40];
        char stu_id[30];
        char stu_npass[30];
        char stu_dob[30];
        char stu_orgdob[30];
}detail;
typedef struct bklis{
  char auth[50];
  char Title[60];
  char Genre[30];
  int issue;
  int count;
  struct bklis *next;
}bklist;

struct member *header[3];
bklist *head;
struct cartbook *headis;//Issue Books
struct cartbook *headrv;//Reserved Books
struct reqbook  *headrq;//Requested Books

void headrvLoader();//ADITYA
void mainMenu();//ADITYA
void *bookorder(order *z);//AMAN
bool approvingRequest(char *str1,char *str2);//AMAN
void student(char *, char *);//ADITYA
void studentPage(char *id);//ADITYA
void staffPage(char *, char *);//ADITYA
void staffMenu();//ADITYA
void addMember();//ADITYA
void signIn();//ADITYA
bool approveRequest(int);//ADITYA
void deleteMember();//ADITYA
void uploadMembers();//ADITYA
char* teme();//AAYUSH
void passwordChange(int);//AAYUSH
void loadMembers();//ADITYA
int isValidDate(Date *validDate);//AAYUSH
void acpt_decline(int a);//AAYUSH
void pssrqst();//AAYUSH
struct reqbook* nthNode(int n);//ADITYA
int menucallking(int max,char *str);//TANISH
void showBookRequests();//ADITYA
char (*stringsplitter(char *z))[100];//TANISH
bklist *loaddatabase();//TANISH
bklist bookSearch(char *z);//TANISH
int dumpdatabase(bklist* a);//TANISH
void issueBook(char *);//ADITYA
void reserveBook(bklist *,char*);//ADITYA
void requestBook(char *);//ADITYA
bool loadCart(bklist *,char *);//ADITYA
bool isReserved(bklist *book,char *id);//ADITYA
char* toUpperCase(char *s);//ADITYA
void cart(cartstruct *header);//TANISH
void headrqLoader();//ADITYA
int dumpres(cartstruct* a);//TANISH
int dumpres1(cartstruct* a);//TANISH
void dumpreq();//ADITYA
int dumpadd(cartstruct* a);//TANISH
bklist* getBook(bklist *a);//ADITYA
bklist *nth_link(bklist *head, int i);//TANISH
cartstruct* cartissuelistloader(char *file, char *file1);//TANISH
bklist bookcheck(bklist* a, int i);//TANISH
bklist* issuebook(cartstruct* cartissuehead, bklist* maindatabaseheader);//TANISH
cartstruct *specificuserloader(char *s);//TANISH
cartstruct *specificuserloader1(char *s);//TANISH
int print(bklist *header, int i,char *z);//TANISH
int menucall(int max);//TANISH
bklist editbook(bklist* z, int i, bklist *a);//TANISH
cartstruct editlist(bklist* z, int i, char* str, cartstruct *a);//TANISH
void loadMembers();//ADITYA

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
        printf("Enter the type of member to be added...\n\n1.Student");
        printf("\t2-Faculty\t3-Staff\n\n");
        char ch[2];
        scanf("%s",ch);
        int w=atoi(ch); int i;
        switch(w)
        {
        case 1: i=0; break;
        case 2: i=1; break;
        case 3: i=2; break;
        default: printf("Only 1,2,3 are acceptable values\n");
                sleep(2); system("clear"); addMember();
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
        fscanf(stdin,"%s", id);//printf("(%s)",id);
        printf("\nEnter your Password:\t");
        fscanf(stdin,"%s", pass);//printf("(%s)",pass);
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
                if(i==0||i==1) student(current->name,current->id);
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
  head=loaddatabase();
  headis=(struct cartbook*)malloc(sizeof(struct cartbook));
  headis->next=NULL;
  headrvLoader();
  printf("Done 2");
  headrqLoader();
  printf("Done 3");
  studentPage(id);
}
void staffPage(char *name,char *id)
{
  printf("Welcome %s",name);
  printf("What do you want to do?\nChoose an option.\n");
  staffMenu();
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
                printf("No matching UserID found\n\n1. Become a member\t\t");
                printf("2. Try again\n\n");
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
        printf("\n\nYour request saved successfully.\n\nWait for a");
        printf(" Staff member to approve it.");
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
        //printf("%d",Nl);          //to check total numbers of entries

        rewind(id);
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
        int Nl=0,cmp,var2=-1;
        studentid = fopen("StudentId.txt","r"); if(studentid==NULL) printf("NULL");
        while( fgets(line,1023,studentid) != NULL)
        {
                Nl++;
        }
//printf("%d\n",Nl);
        rewind(studentid);
        fscanf(studentid,"%s", input);
        input[strcspn(input, "\n")] = '\0';
        for(int z=0; z<Nl; z++)
        {
          int as=strlen(input),vvv=strlen(stu->stu_id);
          printf("<%s>-%d   <%s>-%d\n",input,as,stu->stu_id,vvv );
                cmp=strcmp(input,stu->stu_id);
                //printf("%d\n",cmp );
                if(cmp>0 || cmp<0)
                {
                        cmp=9;
                }
                if(cmp==0)
                {
                        var2=z+1;
                        cmp++;
                        break;
                }
               fscanf(studentid,"%s", input);
                input[strcspn(input, "\n")] = '\0';
        }
        printf("%d\n %d\n",var2,cmp );
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
                      //  printf("%d__%d\n",temp,var2);
                        if(temp != var2)
                                putc(ch, rep);
                        //printf("%c",ch );
                        if(ch == '\n' && temp==var2) {
                                fputs(stu->stu_npass,rep);
                                //fprintf(rep,"%s",stu->stu_npass);
                                //printf("%s",stu->stu_npass);
                        }
                        if (ch == '\n')
                                temp++;
                        ch = getc(pass);
                }
                fclose(pass);
                fclose(rep);
// sleep(200);

              //  remove("StudentPass.txt");
                //rename("rep.txt","StudentPass.txt");
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
void showBookRequests()
{
  headrqLoader();
  if(headrq->next==NULL)
  {
    printf("No Pending book requests.\n");
    printf("Going back to main page...\n");
    staffMenu();
  }
  struct reqbook *current;
  current=headrq->next;int i=1;
  while(current!=NULL)
  {
    printf("-----------------------------------------------------------------\n");
    printf("%d. Title of the book: '%s'\n",i,current->title);
    printf("   Name of author: '%s'\n",current->auname);
    printf("   Requested by Id: '%s'\n",current->id);
    current=current->next;i++;
  }
  printf("-----------------------------------------------------------------\n");
  printf("Enter the corresponding no. to approve the request");
  printf(" and order the book.\n");
  //We may add delete request also..
  i=0;
  scanf("%d",&i);
  approveRequest(i);
}
bool approveRequest(int i)
{
  //check if this book has already been ordered ask to order Again
  //if no return false
  //this can be done only after we have all the functions compiled here that AMAN BANSAL made
  struct reqbook *orb;
  orb=nthNode(i);
  if(approvingRequest(orb->auname,orb->title))
  {
    FILE *fp1,*fp2,*fp3;
    fp1=fopen("ApprovedRequestTitle.txt","a");
    fp2=fopen("ApprovedRequestAuthor.txt","a");
    fp3=fopen("ApprovedRequestUserId,txt","a");
    fputs(orb->title,fp1);
    fputs(orb->auname,fp2);
    fputs(orb->id,fp3);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    struct reqbook *current,*prev;
    current=headrq->next;
    prev=headrq;
    while(current!=NULL)
    {
      int cmp1=strcmp(orb->auname,current->auname);
      int cmp2=strcmp(orb->title,current->title);
      int cmp3=strcmp(orb->id,current->id);
      if(cmp1==0&&cmp2==0&&cmp3==0)
      {
        prev->next=current->next;
        current=NULL;
        dumpreq();
        break;
      }
      prev=current;
      current=current->next;
    }
  }
  else
  {
    printf("Something went wrong.You may Try again.\n");
    staffMenu();
  }

}
int menucallking(int max,char *str)
{
  for(int ty = 0;ty ==0;)
  {
    scanf("%s",str);
   if(atoi(str))
   {
     if(atoi(str)<=max && atoi(str)>0  )
     {
       ty =1;
     }
     else
     {
       printf("please write a digit bw 0 and %d- ",max+1);
     }
   }
   else
   {
     printf("please write a digit which is greater than > 0");
   }

  }
  int sel;
  sel = atoi(str);
  return sel;
}
bklist *loaddatabase()// declaring  a function of type bklist which returns a pointer
//this function takes in a string pointer as a paramter
{
 FILE *aut,*tit,*gen,*iss,*cnt;
 bklist *header,*point,*commit;
 int count;
 aut = fopen("AUTHOR.txt","r");
 tit = fopen("TITLE.txt","r");
 gen = fopen("Genre.txt","r");
 iss = fopen("issue_no.txt","r");
 cnt = fopen("Count.txt","r");
 header = (bklist*) malloc(sizeof(bklist));//allocating dynamic memory of size of bklist structure
 if(header == NULL)//this checks if malloc is able to allocate  memory or not
  {
      printf("Unable to allocate memory.");
      exit(0);
  }
  // fgets(header->auth,49,aut);//gets first line from files this "file pointers" are pointing to.
  // fgets(header->Title,59,tit);//gets first line from files this "file pointers" are pointing to.
  // fgets(header->Genre,29,gen);//gets first line from files this "file pointers" are pointing to.
  // fscanf(iss,"%d\n",&header->issue);//gets first line from file issue_no.txt as an integer
  // fscanf(cnt,"%d\n",&header->count);//gets first line from file issue_no.txt as an integer
  // // this printf below is just for checking the code
  // // printf("%s %s %s %d\n",header->auth,header->Title,header->Genre,header->issue);
  // header->next = NULL;
  //               header
  //               _______
  //              | auth |
  //              | title|
  //              | Genre|
  //              | issue|
  //              | next | ---pointing to----> NULL
  //              ￣￣￣￣
  point = header;//assigning header address to point
 for(count =2;;count++)// count is keeping track of no. of nodes
 { commit = (bklist*)malloc(sizeof(bklist));
   if(commit == NULL)// if system is not able to allocate memory this condition keeps a check on that
      {
          printf("memory can't be allocated please free some memory");
          break;
      }
      if (fgets(commit->Title,59,tit) == NULL)// fgets reads a new line each time for every iteration of loop
      //and if the new line doesn't points to anything i.e. emptyline then is condition breaks the loop
      { free(commit);// done to avoid memory leak
        commit = NULL;// to avoid dangling pointer problem
        break;
      }
   fgets(commit->auth,49,aut);
   fgets(commit->Genre,29,gen);
   fscanf(iss,"%d\n",&commit->issue);
   fscanf(cnt,"%d\n",&commit->count);
   commit->next = NULL;
   //all the fgets and fscanf are taking value from newline for every iteration of loop
   //               commit
   //               _______
   //              | auth |
   //              | title|
   //              | Genre|
   //              | issue|
   //              | next | ---pointing to----> NULL
   //              ￣￣￣￣

   point->next = commit;
   //               point                       commit
   //               _______                ➚    _______
   //              | auth |             ➚      | auth |
   //              | title|          ➚         | title|
   //              | Genre|       ➚            | Genre|
   //              | issue|    ➚               | issue|
   //              | next | ➚                  | next | ---pointing to----> NULL
   //              ￣￣￣￣                     ￣￣￣￣
   //              point-> is pointing to commit which links commit to linked list
   //              and now commit->next is pointing to NULL

   point = point->next;
   //now in each iteration of loop point's adress is changed to where point->next is
   //pointing to i.e to commit structure. this helps in adding entire data in linked list format
   //               point                        point(after 1st iteration) point(after 2nd iteration)  commit
   //               _______                ➚    _______                ➚   _______                ➚   _______
   //              | auth |             ➚      | auth |             ➚     | auth |             ➚     | auth |
   //              | title|          ➚         | title|         ➚         | title|         ➚         | title|
   //              | Genre|       ➚            | Genre|      ➚            | Genre|      ➚            | Genre|
   //              | issue|    ➚               | issue|   ➚               | issue|   ➚               | issue|
   //              |*next | ➚                  |*next |➚                  |*next |➚                  |*next |---pointing to----> NULL


   // this printf below is just for checking the code
   // printf("%s %s %s %d\n",point->auth,point->Title,point->Genre,point->issue);


 }
 fclose(aut);
 fclose(tit);
 fclose(gen);
 fclose(iss);
 fclose(cnt);
 return header;

}
char (*stringsplitter(char *z))[100] // function which returns char(*)[100]
{
  int jm,j,mnm=0,i=0,count =0;
  static char cf[100][100] = {0}; // declare a static 2D arr as it has to be returned back
  for (int i = 0; i < 100; i++)
{
  for(int hnm = 0; hnm<100; hnm++)
  {
    cf[i][hnm] = '\0'; //initialising array to be zero
  }

}
  for(jm=0;mnm == 0;jm++) // jm helps to change us rows in 2D array
  {
    for(j=0;count == 0;j++)// j helps in changing columns of 2D array
    {
      if (*(z+i) != '\0' )
      {
        cf[jm][j] = *(z+i); // if there is a string  passed to function then
        //this if helps to use it
        i++;
        if(*(z+i) == '\0') //checks if string is finishes or not
        {
            mnm++; //break first for loop
            count++;// break second loop
        }

      }
    else
      {
      scanf("%c",&cf[jm][j]); // takes input from stdin if empty array is passed and stores in 2D array
      }
      if (cf[jm][j] == ' ') // checks for spaces in input
      {
        if(cf[jm][0]== ' ')
        {
          cf[jm][j] = '\0';
          jm--;
          break;
        }
        else
        {
        cf[jm][j] = '\0'; // escape character at end of a word
        break;
        }
      }

      if(cf[jm][j]=='\n') // terminates input
      {
        cf[jm][j] = '\0';// escape character to last array element before terminating
        mnm++; // helps in getting out from the first for loop
        break; // from second for loop
      }

    }
  }
return cf;//note: this is returning char pointer
}
bklist bookSearch(char *z){
char (*buk_arr)[100];
char checkray[1000][3][100];
buk_arr = stringsplitter(z);
bklist str_final;
char selected_bk[4];
// printf("%s",*(buk_arr+1));
bklist *a;
bklist *temp;
a = loaddatabase();
temp = a;
int po=0;
for(;temp != NULL;/*po++*/)
{
  for(int i=0;**(buk_arr+i)!='\0';i++)
  {
    char *sr1;
    sr1 = strstr(temp->auth,*(buk_arr+i));
    char *sr2;
    sr2 = strstr(temp->Genre,*(buk_arr+i));
    char *sr3;
    sr3 = strstr(temp->Title,*(buk_arr+i));
    if(sr1 || sr2 || sr3)
    {
      strcpy(checkray[po][0],temp->auth);
      // printf("%s",checkray[po]);
      strcpy(checkray[po][1],temp->Title);
      strcpy(checkray[po][2],temp->Genre);
      po++;
      break;
    }
    else
    continue;
  }

  temp = temp->next;
 }
 printf("No. of matching results %d  \n\n",po);
 if(po==0)
 {
   strcpy(str_final.auth,"");
   strcpy(str_final.Title,"");
   strcpy(str_final.Genre,"");
   return str_final;
 }
 printf(" serial no.\u2006\u2006\n");
 for(int cnt1=0;cnt1<po;cnt1++)
 {
   printf("     -------------------------------------------------------------------------------\n");
   printf("%03d | Author      \t %s    | Title\t         %s    | Genre\t         %s",cnt1+1,checkray[cnt1][0],checkray[cnt1][1],checkray[cnt1][2]);
   printf("     -------------------------------------------------------------------------------\n");

 }

printf("\n\nplease select any one of the following books -  ");

int sel;
sel = menucallking(po,selected_bk);
strcpy(str_final.auth,checkray[sel-1][0]);
strcpy(str_final.Title,checkray[sel-1][1]);
strcpy(str_final.Genre,checkray[sel-1][2]);
return str_final;
}
int dumpdatabase(bklist* a)
{
bklist *temp; int cont;
FILE *aut,*tit,*gen,*iss,*cn_t;
aut = fopen("AUTHOR1.txt","w");
tit = fopen("TITLE1.txt","w");
gen = fopen("Genre1.txt","w");
iss = fopen("issue_no1.txt","w");

cn_t = fopen("Count1.txt","w+");

for(temp = a->next, cont=0;;temp = temp->next)
{
 fputs(temp->Title,tit);
 fputs(temp->auth,aut);
 fputs(temp->Genre,gen);
 fprintf(iss,"%d\n",temp->issue);
 //printf("%d\n",temp->count);
 fprintf(cn_t,"%d\n",temp->count);

 cont++;

 if(temp->next == NULL)
 {
   break;
 }
}
fclose(aut);
fclose(tit);
fclose(gen);
fclose(iss);
fclose(cn_t);
return cont;
}
void studentPage(char *id)
{
 printf("Choose an option.\n");
 printf("1.Issue a Book\n");
 printf("2.Return a Book\n");
 printf("3.Go to cart\n");
 printf("4.Exit\n");
 int w=0;
 scanf("%d",&w);
 switch(w)
 {
   case 1: issueBook(id);break;
 //  case 2: returnBook();break;
   case 3: cart(headis);break;
   case 4: exit(0);
   default:printf("Invalid \nTry Again\n");studentPage(id);
 }
}
bklist* getBook(bklist *a)
{
 bool flag=true; int cmp1,cmp2,cmp3;
 bklist *current;
 current=head->next;
 while(flag)
 {
   cmp1=strcmp(current->Title,a->Title);
   cmp2=strcmp(current->auth,a->auth);
   cmp3=strcmp(current->Genre,a->Genre);
   if((cmp1==0)&&(cmp2==0)&&(cmp3==0))
   {
     flag=false;
     break;
   }
   current=current->next;
   if(current==NULL) break;
 }
 if(flag==false) return current;
 else printf("Something went wrong\n");
}
void issueBook(char *id)
{
 printf("Search the book you want to issue.\n");
 char str[100];
 gets(str);
 bklist b,*book;
 b=bookSearch(str);
 if((strcmp(b.auth,"")==0)&&(strcmp(b.Title,"")==0)&&(strcmp(b.Genre,"")==0))
 {
   printf("Sorry, No such book found\n");
   printf("Do you want to place a request of the book with us?\n");
   printf("1.Yes\n2.No\nAny other input will be taken as 2\n");
   int w;
   scanf("%d",&w);
   if(w==1) requestBook(id);
   else issueBook(id);
 }
 book=getBook(&b);
 if(book->count>0)
 {
   (isReserved(book,id));
   printf("Choose an option\n");
   printf("1.Issue the book right away.\n");
   printf("2.Add the book to cart.\n");
   printf("3.Back to main menu\n");
   printf("Any invalid input will be taken as 3\n");
   int w;
   scanf("%d",&w);
   if(w==1)
   {
     book->count=book->count-1;
     FILE *fp;
     fp=fopen("issuedBooks.txt","a");
     fprintf(fp,"%d\n",book->issue);
     fclose(fp);
     fp=fopen("issuedUserId.txt","a");
     fprintf(fp,"%s\n",id);
     fclose(fp);
     dumpdatabase(head);
     printf("Book Issued\n");
   }
   if(w==2)
   {
     if(loadCart(book,id)) printf("Book has been added to the cart\n");
     else printf("The book is already in the cart\n");
   }
 }
else
{
 printf("Sorry the book is not available\n");
 printf("Press 1 to reserve the book");
 printf("and any other integer to go back to main menu.\n");
 int w;
 scanf("%d",&w);
 if (w==1) reserveBook(book,id);
}
bool flag=true;
while(flag)
{
 printf("Choose an option.\n");
 printf("1.Issue a Book\n");
 printf("2.Return a Book\n");
 printf("3.Go to cart\n");
 printf("4.Exit\n");
 int w=0;
 scanf("%d",&w);
 switch(w)
 {
   case 1: issueBook(id);flag=false;break;
   case 4: exit(0);flag=false;break;
 //  case 2: returnBook();flag=false;break;
 case 3: cart(headis);flag=false;break;
   default:printf("Invalid \nTry Again\n");
 }
}
}
void reserveBook(bklist *book,char *id)
{
 struct cartbook *current,*prev,*p;
 bool flag=true;
 p=(struct cartbook*)malloc(sizeof(struct cartbook));
 p->issue=book->issue;
 strcpy(p->id,id);
 prev=headrv;
 current=headrv->next;
 while(current!=NULL&&flag)
 {
   if(p->issue==current->issue)
   {
     flag=false;printf("You have already reserved this book.\n");
     break;
   }
   prev=current;
   current=current->next;
 }
 if(flag)
 {
   prev->next=p;
   printf("Book reserved you will be notified once it is back with us.\n");
 }
 dumpres(headrv);
 studentPage(id);
}
bool loadCart(bklist *book,char *id)
{
 struct cartbook *current,*p;
 current=headis->next;
 while(current->next!=NULL)
 {
   if(book->issue==current->issue) return false;
   current=current->next;
 }
 if(book->issue==current->issue) return false;
 p=(struct cartbook*)malloc(sizeof(struct cartbook));
 current->next=p;
 p->next=NULL;
 p->issue=book->issue;
 strcpy(p->id,id);
 return true;
}
void requestBook(char *id)
{
 char title[100],auname[100];
 printf("Enter the title of the book you want to order:\n ");
 setvbuf(stdout, NULL, _IONBF, 0);
 fgets(title,100,stdin);
 fgets(title,100,stdin);
 char *tit=toUpperCase(title);
 printf("Enter the name of the author of the book:\n");
 fgets(auname,100,stdin);
 char *aun=toUpperCase(auname);
 bool flag=true;
 struct reqbook *current,*prev;
 current=headrq->next;
 prev=headrq;
 while(current!=NULL)
 {
   int cmp1=strcmp(tit,current->title);
   int cmp2=strcmp(aun,current->auname);
   if(cmp1==0&&cmp2==0)
   {
     flag=false;
     printf("This book has already been requested by %s",current->id);
     break;
   }
   prev=current;
   current=current->next;
 }
 if(flag)
 {
   current=(struct reqbook*)malloc(sizeof(struct reqbook));
   prev->next=current;
   strcpy(current->title,tit);
   strcpy(current->auname,aun);
   strcpy(current->id,id);
   current->next=NULL;
   printf("Your request has been saved.\n");
 }
 dumpreq();
 printf("Going Back to Main menu\n");
 studentPage(id);
}
bool isReserved(bklist *book, char *id)
{
 bool flag=false;
 struct cartbook *current,*prev;
 prev=headrv;
 current=headrv->next;
 while(current!=NULL)
 {
   if(current->issue==book->issue)
   {
     flag=true;
     if(strcmp(id,current->id)==0)
     flag=false;
     printf("You had reserved this book.\n");
     printf("Its available now\n");
     prev->next=current->next;
     current=NULL;
     break;
   }
   prev=current;
   current=current->next;
 }
 return flag;
}
void headrqLoader()
{
 FILE *fp1,*fp2,*fp3;
 fp1=fopen("RequestedTitle.txt","r");
 fp2=fopen("RequestedAuName.txt","r");
 fp3=fopen("RequestedUserId.txt","r");
 struct reqbook *p,*current,*prev;
 headrq=(struct reqbook*)malloc(sizeof(struct reqbook));
 p=(struct reqbook*)malloc(sizeof(struct reqbook));
 headrq->next=p;
 prev=headrq;
 while(true)
 {
   if(fgets(p->title,100,fp1)==NULL)
   {
     p=NULL;
     prev->next=NULL;
     break;
   }
   fgets(p->auname,100,fp2);
   fgets(p->id,100,fp3);
   current=(struct reqbook*)malloc(sizeof(struct reqbook*));
   p->next=current;
   prev->next=p;
   prev=p;
   p=current;
 }
 fclose(fp1);
 fclose(fp2);
 fclose(fp3);
}
void dumpreq()
{
 FILE *fp1,*fp2,*fp3;
 fp1=fopen("tempTitle.txt","a");
 fp2=fopen("tempAuName.txt","a");
 fp3=fopen("tempId.txt","a");
 struct reqbook *current;
 current=headrq->next;
 while(current!=NULL)
 {
   fputs(current->title,fp1);
   fputs(current->auname,fp2);
   printf("//////%s/////",current->id);
   fputs(current->id,fp3);
   putc('\n',fp3);
   current=current->next;
 }
 fclose(fp1);
 fclose(fp2);
 fclose(fp3);
 remove("RequestedUserId.txt");
 rename("tempId.txt","RequestedUserId.txt");
 remove("RequestedTitle.txt");
 rename("tempTitle.txt","RequestedTitle.txt");
 remove("RequestedAuName.txt");
 rename("tempAuName.txt","RequestedAuName.txt");
}
char* toUpperCase(char *s)
{
 int l=strlen(s);
 char ch,*str;
 str=(char*)malloc(sizeof(char)*l);
 for(int i=0;i<l;i++)
 {
   ch=s[i];
   int a=(int) ch;
   if(a>=97&&a<=122)
   {
     a=a-32;
   }
   ch=(char)a;
   str[i]=ch;
 }
 return str;
}
void headrvLoader()
{
  cartstruct *temp, *commit;
 FILE *userid, *iss;
 userid = fopen("ReservedUserId.txt", "r+");
 iss = fopen("ReservedBooks.txt", "r+");
 headrv = (cartstruct*)malloc(sizeof(cartstruct));
 for(temp = headrv;;temp = temp->next)
 { commit = (cartstruct*)malloc(sizeof(cartstruct));
   if(commit == NULL)// if system is not able to allocate memory this condition keeps a check on that
      {
          printf("memory can't be allocated please free some memory");
          break;
        }

   if(fgets(commit->id,50, userid) == NULL)
   { free(commit);// done to avoid memory leak
     commit = NULL;// to avoid dangling pointer problem
     break;
   }
   fscanf(iss, "%d\n", &commit->issue);
   commit->next = NULL;
   // printf("\n%s23\n  %d",commit->id, commit->issue);
   temp->next = commit;
 }
 fclose(userid);
 fclose(iss);
}
cartstruct* cartissuelistloader(char *file, char *file1)
{
  cartstruct *carthead, *temp, *commit;
 FILE *userid, *iss;
 userid = fopen(file, "r+");
 iss = fopen(file1, "r+");
 carthead = (cartstruct*)malloc(sizeof(cartstruct));
 for(temp = carthead;;temp = temp->next)
 { commit = (cartstruct*)malloc(sizeof(cartstruct));
   if(commit == NULL)// if system is not able to allocate memory this condition keeps a check on that
      {
          printf("memory can't be allocated please free some memory");
          break;
        }

   if(fgets(commit->id,50, userid) == NULL)
   { free(commit);// done to avoid memory leak
     commit = NULL;// to avoid dangling pointer problem
printf("NULL");
     break;
   }
   fscanf(iss, "%d\n", &commit->issue);
   commit->next = NULL;
   // printf("\n%s23\n  %d",commit->id, commit->issue);
   temp->next = commit;

 }

 fclose(userid);
 fclose(iss);
return carthead;

}

bklist bookcheck(bklist* a, int i)
{ //printf("bookchecked");
 bklist *temp;

 for(temp = a->next;;temp = temp->next)
 {
   if(temp->issue == i)
   {
     return *temp;
   }
 }
 printf("sorry but there no file like that");
}



bklist* issuebook(cartstruct* cartissuehead, bklist* maindatabaseheader)
{
 cartstruct *temp1;
 bklist *temp2;
 bklist *book1, *commit;
 book1 = (bklist*)malloc(sizeof(bklist));
 temp2 = book1;
 for(temp1 = cartissuehead;;temp1 = temp1->next)
 {
   // printf("hi");
   if(temp1->next == NULL)
   {
     break;
   }
   commit = (bklist*)malloc(sizeof(bklist));
   *commit = bookcheck(maindatabaseheader, temp1->next->issue);
   commit->next = NULL;
   // printf("hi");
   // printf("\n%s\n",commit->Title);

   // if(commit->count == 0)
   //  { //printf("\nyeah man 2\n");
   //   free(commit);
   //   commit = NULL;
   //   continue;
   // }
   // else if(commit->count)
   // {
     // printf("\nyeah man 1\n");
     temp2->next = commit;
     // printf("\n%s\n",temp2->next->Genre);

     temp2 = temp2->next;
   // }
  }
// printf("\n%s\n",book1->next->Title);
return book1;
}

cartstruct *specificuserloader(char *s)
{
 cartstruct *carthead, *temp, *commit;
 FILE *userid, *iss;
 userid = fopen("userid1.txt", "r+");
 iss = fopen("sel_issue_no1.txt", "r+");
 carthead = (cartstruct*)malloc(sizeof(cartstruct));
 for(temp = carthead;;)
 { commit = (cartstruct*)malloc(sizeof(cartstruct));
  if(commit == NULL)// if system is not able to allocate memory this condition keeps a check on that
     {
         printf("memory can't be allocated please free some memory");
         break;
       }

  if(fgets(commit->id,49, userid) == NULL)
  { free(commit);// done to avoid memory leak
    commit = NULL;// to avoid dangling pointer problem
    break;
  }

  fscanf(iss, "%d\n", &commit->issue);
  commit->next = NULL;
  // printf("\n%s23\n  %d",commit->id, commit->issue);


  if(!strcmp(commit->id, s))
  { temp->next = commit;
    temp = temp->next;
  }
  else
  continue;
}
fclose(userid);
fclose(iss);
return carthead;
}
cartstruct *specificuserloader1(char *s)
{
 cartstruct *carthead, *temp, *commit;
 FILE *userid, *iss;
 userid = fopen("file1.txt", "w+");
 iss = fopen("file2.txt", "w+");
 carthead = (cartstruct*)malloc(sizeof(cartstruct));
 for(temp = carthead;;)
 { commit = (cartstruct*)malloc(sizeof(cartstruct));
  if(commit == NULL)// if system is not able to allocate memory this condition keeps a check on that
     {
         printf("memory can't be allocated please free some memory");
         break;
       }

  if(fgets(commit->id,49, userid) == NULL)
  { free(commit);// done to avoid memory leak
    commit = NULL;// to avoid dangling pointer problem
    break;
  }

  fscanf(iss, "%d\n", &commit->issue);
  commit->next = NULL;
  // printf("\n%s23\n  %d",commit->id, commit->issue);


  if(!strcmp(commit->id, s))
  { temp->next = commit;
    temp = temp->next;
  }
  else
  continue;
}
fclose(userid);
fclose(iss);
return carthead;
}

int print(bklist *header, int i,char *z)
{
 bklist *temp;
 int j;
 printf("\n---------------------------------------------------\n");
 printf("%s\n",z);
 printf("---------------------------------------------------\n");
 for(temp = header->next ,j=1;temp != NULL;temp= temp->next, j++)
 {
   printf("%d)  Author  - %s    Title  - %s    Genre  - %s    Issue no - %d\n    Availability = %d \n",i, temp->auth, temp->Title, temp->Genre, temp->issue, nth_link(header, j)->count);
   printf("---------------------------------------------------\n");
   i++;

 }
 return --i;
}
int menucall(int max)
{ char str[50];
 for(int ty = 0;ty ==0;)
 {
   scanf("%s",str);
  if(atoi(str))
  {
    if(atoi(str)<=max && atoi(str)>0  )
    {
      ty =1;
    }
    else
    {
      printf("please write a digit bw 0 and %d- ",max+1);
    }
  }
  else
  {
    printf("please write a digit which is greater than > 0 - ");
  }

 }
 int sel;
 sel = atoi(str);
 return sel;
}

bklist editbook(bklist* z, int i, bklist *a)
{
//so a is the header pointer passed from the loaddatabase function and z is the book info to be deleted or added in the database,
// and i defines the operation you wanna perform with the book info you passed
bklist *temp; int str1,str2,str3;
bklist *prev;
bklist finedit;
int cnt5=1,issre;
temp = a->next;
prev = a;
for(;;)
{
 printf("%s %s %s %d %d ",temp->auth,temp->Title,temp->Genre,temp->issue,temp->count);
 str1 = strcmp(temp->auth,z->auth);
 printf("%d",str1);
 str2 = strcmp(temp->Title,z->Title);
 printf("%d",str2);
 str3 = strcmp(temp->Genre,z->Genre);
 printf("%d",str3);
 if(str1 == 0 && str2 == 0 && str3 == 0)
 {
   if(i == 1)
   { cnt5 = 0;
     temp->count++;
     printf("\n %d \n\n\n\n\n\n\n",temp->count);
     finedit = *temp;
     break;
   }
   else if(i == 2)
   { cnt5 = 0;
     if(temp->count)
     {
     temp->count--;
     printf("\n %d \n\n\n\n\n\n\n",temp->count);
     finedit = *temp;
     }
     else if(temp->count == 0)
     {
       printf("\nSorry, but the book count is already zero \n");
       finedit = *temp;
       finedit.count = -1;
     // prev->next = temp->next;
     }
     break;
   }
 }
   if (temp->next == NULL)
   {
     break;
   }


 prev = temp;
 // printf("%s %s %s %d %d ",prev->auth,prev->Title,prev->Genre,prev->issue,prev->count);
 temp = temp->next;


}
if (cnt5)
{ printf("\nyeah man i am in");
 issre = temp->issue;
 temp->next = z;
 z->issue = issre+1;
 z->count = 1;
 z->next = NULL;
 finedit = *z;
}
// printf("%s  %d %d",temp->next->auth,temp->next->count,temp->next->issue);
return finedit;
}

cartstruct editlist(bklist* z, int i, char* str, cartstruct *a)
{
//so a is the header pointer passed from the loaddatabase function and z is the book info to be deleted or added in the database,
// and i defines the operation you wanna perform with the book info you passed
cartstruct *temp, *temp1;
cartstruct *prev;
cartstruct add;
cartstruct finedit;
int cnt5=1;
prev = a;
temp = a->next;
printf("\n%d\n",z->issue);
for(;;)
{
 // printf("%d",strlen(str));
 // printf("%d",strlen(temp->id));
 if((temp->issue == z->issue) && ((strcmp(temp->id, str))==0))
 { printf("hi");
   if(i == 1)
   { cnt5 = 1;
     printf("\nalready in reserve list\n");
     break;
   }
   else if(i == 2)
   {
     cnt5 = 0;
     finedit.issue = temp->issue;
     strcpy(finedit.id,temp->id);
     finedit.next = NULL;
     prev->next = temp->next;
     return finedit;

     }
   }


   if (temp->next == NULL)
   { if(cnt5)
     {

       add.issue = z->issue;
       strcpy(add.id,str);
       add.next = NULL;
       printf("\nhi\n");
       temp->next= &add;
       add.next=NULL; // a little dry run required
         printf("\nyeah man i am in\n");
       return add;
     }
     break;
   }




 prev = temp;

 // printf("%s %s %s %d %d ",prev->auth,prev->Title,prev->Genre,prev->issue,prev->count);
 temp = temp->next;


}

// printf("%s  %d %d",temp->next->auth,temp->next->count,temp->next->issue);

}

bklist *nth_link(bklist *head, int i)
{
 bklist *book, *temp;
 int m;
 for(m=0, temp = head->next;m<i;m++, temp = temp->next)
 { book = (bklist*)malloc(sizeof(bklist));
   strcpy(book->auth, temp->auth);
   strcpy(book->Title, temp->Title);
   strcpy(book->Genre, temp->Genre);
   book->issue  = temp->issue;
   book->count = temp->count;
   book->next = NULL;

 }
 return book;
}




int dumpres(cartstruct* a)
{
cartstruct *temp; int cont;
FILE *iss,*user;
user = fopen("tempReservedUserId.txt","w");
iss = fopen("tempReservedBooks.txt","w");

for(temp = a->next, cont=0;;temp = temp->next)
{
 fputs(temp->id,user);
 fprintf(iss,"%d\n", temp->issue);

 cont++;

 if(temp->next == NULL)
 {
   break;
 }

}

fclose(iss);
fclose(user);
return cont;
}

int dumpres1(cartstruct* a)
{
cartstruct *temp; int cont;
FILE *iss,*user;
user = fopen("file1.txt","w");
iss = fopen("file2.txt","w");

for(temp = a->next, cont=0;;temp = temp->next)
{
 fputs(temp->id,user);
 fprintf(iss,"%d\n", temp->issue);

 cont++;

 if(temp->next == NULL)
 {
   break;
 }

}

fclose(iss);
fclose(user);
return cont;
}


int dumpadd(cartstruct* a)
{
cartstruct *temp; int cont;
FILE *iss,*user;
char ch = 'i';
// char b[] = "i";
// printf("%ld",strlen(z));
// printf("%s",strcat(z,b));

user = fopen("file1.txt","a");
iss = fopen("file2.txt","a");
for(temp = a->next, cont=0;;temp = temp->next)
{
 fputs(temp->id,user);
 fprintf(iss,"%d\n", temp->issue);

 cont++;

 if(temp->next == NULL)
 {
   break;
 }

}

fclose(iss);
fclose(user);
return cont;
}

void cart(cartstruct *header)
{
 // printf("which is you want to select:\n1)issue book\n2)reserve book\n3)requested books");
 char w[4];
 int count1, count2, count3,choice;
 char username[30];
 cartstruct *a, *reservelinklist, *orderlist;
 cartstruct added,delis;
 bklist  *issuehead, *res_head, *orderhead, *book;
 bklist  book1;
 int cnt, cnt2, cnt3;
 char str1[] = "book you want to issue", str2[] = "book you have reserved till now", str3[] = "Requested books that are available so far", str4[] = "---------------------------------------------------\n";
 char str5[]= "userid.txt", str6[]="sel_issue_no.txt", str7[] = "userid1.txt", str8[]= "sel_issue_no1.txt", str9[] = "file1.txt", str10[] = "file2.txt";
 cartstruct  *isslist;

 //header = cartissuelistloader(str5,str6); // this header wll be passed by aditya choraria
 strcpy(username,header->next->id);
  int cnt7;
  cnt7 = dumpadd(header);
  // a = cartissuelistloader(str5,str6);
  a = specificuserloader1(username);
 //a1 = cartissuelistloader(str7,str8);


 // printf("%s",username);
   issuehead = issuebook(a,head);
   count1 = print(issuehead,1, str1);
   // printf("%d",count1);
   reservelinklist = specificuserloader(username);
   res_head = issuebook(reservelinklist, head);
   count2 = print(res_head, count1+1, str2);

   orderlist = specificuserloader(username);
   orderhead = issuebook(orderlist, head);
   count3 = print(orderhead, count2+1, str3);

   printf("which one you want to choose -  ");
   choice = menucall(count3);
   printf("\n\nyou entered %d\n",choice);
   if(choice <= count1)
   {
     printf("BOOK SELECTED:\n\n");
     book = nth_link(issuehead, choice);
     printf("%s",str4);
     printf("    Author  - %s    Title  - %s    Genre  - %s    Issue no - %d\n", book->auth, book->Title, book->Genre, book->issue);
     printf("%s",str4);
     printf("This is a really a great choice\n");
     book1 = editbook(book, 2, head);
     printf("%d",book1.count);
     {
       if(book1.count == -1)
       {
         printf("\nDo you want to reserve this book(yes/no) - ");
         scanf("%s",w);
         if(!strcmp(w,"yes"))
         {
           /*editlist 1*/added = editlist(&book1, 1, username, headrv); // for now i am adding a just for testing but rather than passing we have to pass a header which cpmes after loading the reserved list
           printf("%s",added.id);
           printf("%d",a->next->next->next->next->issue);
         }}
         isslist = cartissuelistloader(str9,str10);
         delis = editlist(&book1, 2, username, isslist);
         cnt3 = dumpres1(isslist);
       }}
   else if(choice>count1 && choice<=count2)
   {

     printf("BOOK SELECTED:\n\n");
     book = nth_link(res_head, choice-count1);
     printf("%s",str4);
     printf("    Author  - %s    Title  - %s    Genre  - %s    Issue no - %d\n", book->auth, book->Title, book->Genre, book->issue);
     printf("%s",str4);
     if(book->count == 0)
     {
       printf("Sorry, This book is still not available\nPlease check Availability before proceeding\n\n");
     }
     else
     {printf("This is a really a great choice\n");
     book1 = editbook(book, 2, head);
       printf("\n\n\n\nhi\n\n\n");
     added = editlist(&book1, 2, username, headrv);// // for now i am adding a just for testing but rather than passing we have to pass a header which cpmes after loading the reserved list

   }
 }
   else if(choice>count2 && choice<=count3)
   {
     printf("BOOK SELECTED:\n\n");
     book = nth_link(orderhead, choice-count2);
     printf("%s",str4);
     printf("    Author  - %s    Title  - %s    Genre  - %s    Issue no - %d\n", book->auth, book->Title, book->Genre, book->issue);
     printf("%s",str4);
     if(book->count == 0)
     {
       printf("Sorry, This book is still not available\nPlease check Availability before proceeding\n\n");
     }
     else
     {printf("This is a really a great choice\n");
     book1 = editbook(book, 2, head);
     added = editlist(&book1, 2, username, headrv);// // for now i am adding a just for testing but rather than passing we have to pass a header which cpmes after loading the reserved list
   }
 }
 printf("\n\n\n\nhi\n\n\n");
 cnt = dumpdatabase(head);

 cnt2 = dumpres(headrv);


}
//edit editlist properly once
void staffMenu()
{
  bool flag=true;
  while(flag)
  {
    printf("1-Add a member\n2-Delete a member\n3-Add a book\n4-Delete a book\n");
    printf("5-Order a book\n6-Check Inventory\n7-Check Password Change requests\n");
    printf("8-Check Pending Book Requests\n");
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
      case 8:showBookRequests();flag=false;break;
      default:printf("Invalid option...Try again\n");
    }
  }
}
struct reqbook* nthNode(int n)
{
  bool flag=true;
  struct reqbook *current;
  current=headrq;
  int i=1;
  for(;i<=n;i++)
  {
    current=current->next;
    if(current==NULL)
    {
      printf("There are only  %d nodes in this list.\n",(i-1));
      flag=false;
      break;
    }
    if(flag)
    {
      return current;
    }
    return NULL;
  }
}
void *bookorder(order *z)// declaring  a function
//this function takes in a string pointer as a paramter
{
  FILE *auth,*bookname,*quantity,*orderid,*status,*vendor,*genre; // declaring file pointer
  order *header,*point,*commit;
  int count,orderidcount;
  auth = fopen("author.txt","r+");
  bookname = fopen("bookname.txt","r+");
  quantity = fopen("qty.txt","r+");
  orderid = fopen("orderid.txt","r+");
  status = fopen("status.txt","r+");
  vendor = fopen("vendor.txt","r+");
  genre = fopen("genre.txt","r+");
  header = (order*) malloc(sizeof(order));//allocating dynamic memory of size of order structure
  if(header == NULL) //this checks if malloc is able to allocate  memory or not
   {
       printf("Unable to allocate memory.");
       exit(0);
   }
   fgets(header->au_name,49,auth); //gets first line from files this "file pointers" are pointing to.
   fgets(header->bk_name,59,bookname);//gets first line from files this "file pointers" are pointing to.
   fgets(header->qty,29,quantity);//gets first line from files this "file pointers" are pointing to.
   fscanf(orderid,"%d\n",&header->odrid);//gets first line from file orderid.txt as an integer
   fgets(header->stat,29,status);//gets first line from files this "file pointers" are pointing to.
   fgets(header->vndr,29,vendor);//gets first line from files this "file pointers" are pointing to.
   fgets(header->gen,29,genre);//gets first line from files this "file pointers" are pointing to.
   // this printf below is just for checking the code
    //printf("%s %s %s %d\n",header->au_name,header->bk_name,header->qty,header->odrid,header->stat);
   header->next = NULL;
   //               header
   //               _________
   //              | au_name |
   //              | bk_name |
   //              | qty     |
   //              | odrid   |
   //   	   | stat    |
   //    	   | vendor  |
   //              | next    | ---pointing to----> NULL
   //              ￣￣￣￣￣￣
  point = header; //assigning header address to point
  for(count =2;;count++) // count is keeping track of no. of nodes
  { commit = (order*)malloc(sizeof(order));
    if(commit == NULL)// if system is not able to allocate memory this condition keeps a check on that
       {
           printf("memory can't be allocated please delete some memory");
           break;
       }
       if (fgets(commit->bk_name,59,bookname) == NULL)// fgets reads a new line each time for every iteration of loop
       //and if the new line doesn't points to anything i.e. emptyline then is condition breaks the loop
       { free(commit); // done to avoid memory leak
         commit = NULL; // to avoid dangling pointer problem
         break; // breaking loop
       }

    fgets(commit->au_name,49,auth);
    fgets(commit->qty,29,quantity);
    fscanf(orderid,"%d\n",&commit->odrid);
    fgets(commit->stat,29,status);
    fgets(commit->vndr,29,vendor);
    fgets(commit->gen,29,genre);
    orderidcount = commit->odrid;
    commit->next = NULL;
    //all the fgets and fscanf are taking value from newline for every iteration of loop
    //               commit
    //               _______
    //              | au_name |
    //              | title|
    //              | qty|
    //              | odrid|
    //              | next | ---pointing to----> NULL
    //              ￣￣￣￣
    point->next = commit;
    //               point                       commit
    //               _______                ➚    _______
    //              | au_name |             ➚      | au_name |
    //              | title|          ➚         | title|
    //              | qty|       ➚            | qty|
    //              | odrid|    ➚               | odrid|
    //              | next | ➚                  | next | ---pointing to----> NULL
    //              ￣￣￣￣                     ￣￣￣￣
    //              point-> is pointing to commit which links commit to linked list
    //              and now commit->next is pointing to NULL

    point = point->next;//now in each iteration of loop point's adress is changed to where point->next is
    //pointing to i.e to commit structure. this helps in adding entire data in linked list format
    //               point                        point(after 1st iteration) point(after 2nd iteration)  commit
    //               _______                ➚    _______                ➚   _______                ➚   _______
    //              | au_name |             ➚      | au_name |             ➚     | au_name |             ➚     | au_name |
    //              | title|          ➚         | title|         ➚         | title|         ➚         | title|
    //              | qty|       ➚            | qty|      ➚            | qty|      ➚            | qty|
    //              | odrid|    ➚               | odrid|   ➚               | odrid|   ➚               | odrid|
    //              |*next | ➚                  |*next |➚                  |*next |➚                  |*next |---pointing to----> NULL


    // this printf below is just for checking the code
     //printf("%s %s %s %d\n",point->au_name,point->bk_name,point->qty,point->odrid);

  }
  fprintf(auth,"%s\n",z->au_name);
  fprintf(bookname,"%s\n",z->bk_name);
  fprintf(quantity,"%s\n",z->qty);
  fprintf(orderid,"%d\n",orderidcount+1);
  fprintf(status,"PENDING\n",z->stat);
  fprintf(vendor,"%s\n",z->vndr);
  fprintf(genre,"%s\n",z->gen);
  // this printf below is just for checking the code
  // printf("%s %s %s %d\n",z->au_name,z->bk_name,z->qty,orderidcount+1);
  fclose(auth);
  fclose(bookname);
  fclose(quantity);
  fclose(orderid);
  fclose(status);
  fclose(vendor);
  fclose(genre);
}
bool approvingRequest(char *str1,char *str2)
{
order *c;
c = (order*)malloc(sizeof(order));
//printf("Enter Author Name = ");
strcpy(c->au_name,str1);
//printf("Enter Book Name = ");
strcpy(c->bk_name,str2);
printf("Enter Quantity = ");
fgets(c->qty,20, stdin);
printf("Enter Vendor Name = ");
fgets(c->vndr,20, stdin);
printf("Enter Genre = ");
fgets(c->gen,20, stdin);
bookorder(c);// function takes in string pointer as parameter and returns the header which helps in access of the linked list
printf("\n-----------------------You Have Successfully Placed an Order---");
printf("---------------\n-----------------------Thank You--------------------");
printf("---\n-----------------------Returning Back To Book Requests Page---------");
printf("--------------\n");
return true;
}

int main()
{
  loadMembers();
  mainMenu();
}
