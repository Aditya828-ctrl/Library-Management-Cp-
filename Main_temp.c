#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#include<time.h>
#include<ctype.h>

#define MAX_YR 2020
#define MIN_YR 1940
char *datestring;

typedef struct b_detail{
    char *name;
    char *author;
    char *genre_b;
}b_detail;
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
  char id[100];
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
typedef struct bklis1 {
        char auth[50];
        char Title[60];
        char Genre[30];
        int issue;
        int count;
        char qty[10];
        struct bklis1 *next;
}bklist1;

struct member *header[3];
bklist *head;
struct cartbook *headis;//Issue Books
struct cartbook *headrv;//Reserved Books
struct reqbook  *headrq[2];//Requested Books

//order *bk_info(order *z);
void alert();
void funcall1();
void funcall2();
void issuedbokdet();
void alert_id(char *code);
void funcall3();
void funcall4();
void date_diff(char *idr);//AAYUSH
order *loaddatabase1();
void *booksearch1(char *z);
void *booksearchall(char *z);
void *booksearchid(char *z);
void statusfn(int sta,int ordid);
void *bookaddinfo(char *z);
void option();
bklist1 *addabook(bklist1 *z);
int dumpis(cartstruct* a);//TANISH
bklist* issuebookv2(struct reqbook* headodr);//ADITYA
void headrvLoader();//ADITYA
void headisLoader();//ADITYA
void mainMenu();//ADITYA
void bookorder1();//AMAN
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
void inventry();//AAYUSH
void loadMembers();//ADITYA
char *strupp(char *z);
char* libreq();
char* vendor();
int isValidDate(Date *validDate);//AAYUSH
void acpt_decline(int a);//AAYUSH
void pssrqst();//AAYUSH
struct reqbook* nthNode(int n);//ADITYA
int menucallking(int max,char *str);//TANISH
void showBookRequests();//ADITYA
void returnbook(char *isome);
char (*stringsplitter(char *z))[100];//TANISH
bklist *loaddatabase();//TANISH
bklist bookSearch(char *z);//TANISH
int dumpdatabase(bklist* a);//TANISH
void issueBook(char *);//ADITYA
void reserveBook(bklist *,char*);//ADITYA
void requestBook(char *);//ADITYA
bool loadCart(bklist *,char *);//ADITYA
int isReserved(bklist *book,char *id);//ADITYA
char* toUpperCase(char *s);//ADITYA
cartstruct* headLoader2(char *file1,char *file2);//TANISH
void cart(char *id);//TANISH
void headrq1Loader();//ADITYA
void headrq2Loader();//ADITYA
int dumpres(cartstruct* a);//TANISH
int dumpres1(cartstruct* a);//TANISH
void dumpreq();//ADITYA
void dumpreq1();//ADITYA
bklist* getBook(bklist *a);//ADITYA
bklist *nth_link(bklist *head, int i);//TANISH
cartstruct* cartissuelistloader(char *file, char *file1);//TANISH
bklist bookcheck(int i);//TANISH
bklist* issuebook(cartstruct* cartissuehead);//TANISH
cartstruct *specificuserloader(char *s);//TANISH
cartstruct *specificuserloader1(char *s);//TANISH
struct reqbook *specificuserloader2(char *id);//ADITYA
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
        setvbuf(stdin, NULL, _IONBF, 0);
        fgets(p->name,50,fp1);
        setvbuf(stdin, NULL, _IONBF, 0);
        fscanf(fp2,"%s", p->id);
        setvbuf(stdin, NULL, _IONBF, 0);
        fscanf(fp3,"%s", p->pass);
        setvbuf(stdin, NULL, _IONBF, 0);
        fgets(p->dob,12,fp4);
        while(true)
        {
         current=(struct member *)malloc(sizeof(struct member));
         p->next=current;
         prev=p;
         p=current;
         setvbuf(stdin, NULL, _IONBF, 0);
         if(fgets(p->name,50,fp1)==NULL)
         {
           p=NULL;
           current=NULL;
           prev->next=NULL;
           break;
         }
         setvbuf(stdin, NULL, _IONBF, 0);
         fscanf(fp2,"%s", p->id);
         setvbuf(stdin, NULL, _IONBF, 0);
         fscanf(fp3,"%s", p->pass);
         setvbuf(stdin, NULL, _IONBF, 0);
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
  printf("\e[1;1H\e[2J");
        printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        Library Management System\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       ----------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       Add Member\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       ----------\n\n\n\n");
        struct member *current,*p;
        //loadMembers();//to be deleted
        printf("\nEnter the type of member to be added...\n\n1.Student");
        printf("\t2-Faculty\t3-Staff\n\n");
        char ch[2];
        scanf("%s",ch);
        int w=atoi(ch); int i;
        switch(w)
        {
        case 1: i=0; break;
        case 2: i=1; break;
        case 3: i=2; break;
        default: printf("Only 1,2,3 are acceptable values");
                sleep(2);addMember();
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
          setvbuf(stdin, NULL, _IONBF, 0);
                dob=teme();
                var=atoi(dob);

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
        printf("ADDED!\n");
        int xD=0;
                while (xD<3) {
                        sleep(1);
                        printf(".");
                        xD++;
                }
  staffMenu();
}
void signIn()
{
        printf("\t\t\t\t\t\t\t\t\t\t\t       --------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        Library Management System\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t       --------------------------\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t  -------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t  Sign In\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t  -------\n\n\n\n");
        printf("\nChoose the account type:\n\n");
        printf("1.Student\t2.Faculty\t3.Staff\n\n");
        printf("\n0. Main Menu\n\n");
        int i;
        printf("--> ");
        char *cho;
        cho=(char*)malloc(10);
        scanf("%s",cho);
        int vv=9;
        vv=strcmp(cho,"0");

        if(vv==0)
        {
          printf("\e[1;1H\e[2J");
          mainMenu();
        }

  i=atoi(cho);
  if(i!=1 && i!=2 && i!=3)
  {
    printf("Not a valid input, Please try again");
    int ii=0;
                while (ii<3) {
                        sleep(1);
                        printf(".");
                        ii++;
                }
                printf("\e[1;1H\e[2J\n");
                signIn();
  }
  
  i=i-1;
        char id[50],pass[50];
        printf("\nEnter your UserId:\t");
        setvbuf(stdout, NULL, _IONBF, 0);
        fscanf(stdin,"%s", id);
        printf("\nEnter your Password:\t");
        fscanf(stdin,"%s", pass);
        struct member *current;
        current=header[i];
        int cmp1,cmp2;

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
void alert()
{
        FILE *issueno;
        FILE *total;
        FILE *title;
        FILE *author;
        issueno=fopen("issue_no.txt","r");
        title=fopen("TITLE.txt","r");
        author=fopen("AUTHOR.txt","r");
        char line[1024];
        int input;
        char input1[255],input2[255];
        int Nl=0,i=0,j=0;
        while( fgets(line,1023,issueno) != NULL)
        {
                Nl++;
        }

        total=fopen("total.txt","r+");
        fscanf(total,"%d",&input);

                if(input<Nl)
                {
                        for(i=0; i<input; i++)
                        {
                                fgets(input1,254,title);
                                fgets(input2,254,author);
                                input1[strcspn(input1, "\n")] = '\0';
                                input2[strcspn(input2, "\n")] = '\0';

                        }
                        int sub=Nl-input;
                        if(sub>0)
                        {
                                 printf("   \t*----------*\n");
                                 printf("   \t| ALERT!!! |\n");
                                 printf("   \t*----------*\n\n");

                        for(i=0; i<sub; i++)
                        {
                                setvbuf(stdin, NULL, _IONBF, 0);
                                fgets(input1,254,title);
                                setvbuf(stdin, NULL, _IONBF, 0);
                                fgets(input2,254,author);
                                input1[strcspn(input1, "\n")] = '\0';
                                input2[strcspn(input2, "\n")] = '\0';


                                printf("\t--> \"%s\" by author(s) \"%s\" is added to inventory\n",input1,input2 );

                        }

                }

                rewind(total);
                printf("\n\n\n");
                }
}


void mainMenu()
{
  int choice;
  char *cho;
  cho=(char*)malloc(10);
        printf("\e[1;1H\e[2J");
        printf("\t\t\t\t\t\t\t\t\t\t\t         ---------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t          Library Management System\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t         ---------------------------\n\n\n");
        alert();
        printf("\t\t\t\t\t\t\t\t\t\t\t     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t     |                                 |\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t     |            1. Sign In           |\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t     |                                 |\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t     |            2. Sign Up           |\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t     |                                 |\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t     |            3. Exit              |\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t     |                                 |\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
        printf("-->  ");
        setvbuf(stdout, NULL, _IONBF, 0);
  scanf("%s",cho);
  choice=atoi(cho);
  fflush(stdin);
  switch(choice)
  {
    case 1:
            printf("\e[1;1H\e[2J");
            signIn();
            break;
    case 2: signUp();
            break;
    case 3: exit(0);
            break;
    default:
                printf("Not a valid input, try again" );
               setvbuf(stdout, NULL, _IONBF, 0);

               int i=0;
                while (i<3)
                {
                        sleep(1);
                        printf(".");
                        i++;
                }
            printf("\e[1;1H\e[2J\n");
            mainMenu();
            break;
  }
}
void alert_id(char *coding)
{
        FILE *countrs;
        FILE *rstitle;
        FILE *rsid;
        FILE *titlers;
        FILE *authorrs;


        char idi[50];
        int v=9,Nl=0;
        strcpy(idi,coding);
        char line[255],input1[255],input2[255],input3[255],input4[255],input5[255];
        countrs=fopen("Count.txt","r");
        rstitle=fopen("ReservedBooks.txt","r");
        rsid=fopen("ReservedUserId.txt","r");
        titlers=fopen("TITLE.txt","r");
        authorrs=fopen("AUTHOR.txt","r");
        while( fgets(line,1023,rstitle) != NULL)
        {
                Nl++;
        }

        rewind(rsid);
        rewind(rstitle);

        fscanf(rstitle,"%s", input2);
        fscanf(rsid,"%s", input3);


        int cmp1=9,cmp2=9;


        for(int z=0; z<Nl; z++)
        {
                cmp1=strcmp(input3,idi);

                if(cmp1> 0 || cmp1 <0)
                {
                        cmp1=9;
                }
                if(cmp1==0)
                {   int some=0;
                    while(some<atoi(input2))
                    {
                            fgets(input4,254,titlers);
                            fgets(input5,254, authorrs);
                            fscanf(countrs,"%s", input1);
                            input4[strcspn(input4, "\n")] = '\0';
                            input5[strcspn(input5, "\n")] = '\0';

                            some++;
                    }
                    if(atoi(input1)!=0){
                    printf("   \t*----------*\n");
                    printf("   \t| ALERT!!! |\n");
                    printf("   \t*----------*\n\n");
                            printf("-->\t\"%s\" by \"%s\" is available now!\n",input4,input5);
                    }
                    rewind(titlers);
                    rewind(authorrs);
                    rewind(countrs);}
                fscanf(rstitle,"%s", input2);
                fscanf(rsid,"%s", input3);
        }
        fclose(rstitle);
        fclose(titlers);
        fclose(authorrs);
        fclose(countrs);
        fclose(rsid);

        countrs=fopen("Count.txt","r");
        rstitle=fopen("ApprovedRequestTitle.txt","r");
        rsid=fopen("ApprovedRequestUserId.txt","r");
        titlers=fopen("TITLE.txt","r");
        authorrs=fopen("ApprovedRequestAuthor.txt","r");
        Nl=0;
        while( fgets(line,1023,rsid) != NULL)
        {
                Nl++;
        }
        rewind(rsid);
        rewind(rstitle);


        fgets(input2,254, rstitle);
        input2[strcspn(input2, "\n")] = '\0';
        fscanf(rsid,"%s", input3);
        fgets(input5,254, authorrs);
        input5[strcspn(input5, "\n")] = '\0';

        for(int z=0; z<Nl; z++)
        {
                cmp1=strcmp(input3,idi);

                if(cmp1> 0 || cmp1 <0)
                {
                        cmp1=9;
                }
                if(cmp1==0)
                {
                    fgets(input4,254,titlers);
                    input4[strcspn(input4, "\n")] = '\0';
                    fscanf(countrs,"%s", input1);
                    while(strcmp(input4,input2)!=0)
                    {
                            fscanf(countrs,"%s", input1);
                            fgets(input4,254,titlers);
                            input4[strcspn(input4, "\n")] = '\0';

                    }
                    if(atoi(input1)!=0)
                            printf("-->\t\"%s\" by \"%s\" is available now!\n",input4,input5);
                    rewind(titlers);
                    rewind(countrs);}
                fgets(input2,254, rstitle);
                input2[strcspn(input2, "\n")] = '\0';
                fscanf(rsid,"%s", input3);
                fgets(input5,254, authorrs);
                input5[strcspn(input5, "\n")] = '\0';
        }
        date_diff(coding);
}
void student(char *name, char *id)
{
  printf("\n+++++Welcome %s\n+++++",name);
  
  //head=loaddatabase();
  headisLoader();
  headrvLoader();
  headrq1Loader();
  headrq2Loader();
  setvbuf(stdout, NULL, _IONBF, 0);
  printf("Loading your Account");
  int i=0;
                while (i<3) {
                        sleep(1);
                        printf(".");
                        i++;
                }
                printf("\e[1;1H\e[2J\n");
  studentPage(id);

}
void staffPage(char *name,char *id)
{
  printf("\n+++++Welcome %s\n+++++",name);
  printf("Loading your Account");
  int i=0;
  while (i<3) {
                        sleep(1);
                        printf(".");
                        i++;
                }
                printf("\n");
                printf("\e[1;1H\e[2J\n");
  staffMenu();
}
void deleteMember()
{
  printf("\e[1;1H\e[2J");
        printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        Library Management System\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       -------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       Delete Member\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       -------------\n\n\n\n");
  char id[50];
  printf("Enter the UserId of the member to be deleted:\t");
  setvbuf(stdin, NULL, _IONBF, 0);
  fgets(id,50,stdin);
  id[strcspn(id, "\n")] = '\0';
  printf("\nChoose the account type:\n\n");
  printf("1.Student\t2.Faculty\t3.Staff\n\n");
  printf("\n\n#. Previous Menu\t\t0. Main Menu\n\n");
  int i;
  char *cho;
  cho=(char*)malloc(10);
  scanf("%s",cho);
  i=atoi(cho);
  if(strcmp(cho,"0")==0)
  {
    printf("\e[1;1H\e[2J");
    mainMenu();
  }
  if(strcmp(cho,"#")==0)
  {
    printf("\e[1;1H\e[2J");
    staffMenu();
  }
  if(i!=1 && i!=2 && i!=3)
  {
    printf("Not a valid input, Please try again");
    int xD=0;
                while (xD<3) {
                        sleep(1);
                        printf(".");
                        xD++;
                }
                printf("\e[1;1H\e[2J\n");
                deleteMember();
  }
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
    int xD=0;
                while (xD<3) {
                        sleep(1);
                        printf(".");
                        xD++;
                }
  /*  current=head[i];
   while(current->next!=NULL)
    {
      prev=current;
      current=current->next;
    }
    prev->next=NULL;
    current=NULL;*/
  }
  else
  {
          printf("No such member exists.");
          int xD=0;
                while (xD<3) {
                        sleep(1);
                        printf(".");
                        xD++;
                }
                staffMenu();
  }
  uploadMembers();
  staffMenu();
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
 current->name[strcspn(current->name,"\n")]='\0';
    fputs(current->name,fp1);
    putc('\n',fp1);
    current->id[strcspn(current->id,"\n")]='\0';
    fputs(current->id,fp2);
    putc('\n',fp2);
    current->dob[strcspn(current->dob,"\n")]='\0';
    fputs(current->dob,fp3);
    putc('\n',fp3);
    current->pass[strcspn(current->pass,"\n")]='\0';
    fputs(current->pass,fp4);
    putc('\n',fp4);
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
    current->name[strcspn(current->name,"\n")]='\0';
    fputs(current->name,fp1);
    putc('\n',fp1);
    current->id[strcspn(current->id,"\n")]='\0';
    fputs(current->id,fp2);
    putc('\n',fp2);
    current->dob[strcspn(current->dob,"\n")]='\0';
    fputs(current->dob,fp3);
    putc('\n',fp3);
    current->pass[strcspn(current->pass,"\n")]='\0';
    fputs(current->pass,fp4);
    putc('\n',fp4);
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
   current->name[strcspn(current->name,"\n")]='\0';
    fputs(current->name,fp1);
    putc('\n',fp1);
    current->id[strcspn(current->id,"\n")]='\0';
    fputs(current->id,fp2);
    putc('\n',fp2);
    current->dob[strcspn(current->dob,"\n")]='\0';
    fputs(current->dob,fp3);
    putc('\n',fp3);
    current->pass[strcspn(current->pass,"\n")]='\0';
    fputs(current->pass,fp4);
    putc('\n',fp4);
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
        setvbuf(stdin, NULL, _IONBF, 0);//get date year,month and day from user
        printf("\nEnter date in format (day/month/year): ");
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
                //printf("%s\n",dataString );
                return dataString;
        }
        else
        {
               // printf("\n\n Date is valid!\n");
                sprintf(dataString, "%02d-%02d-%04d\n", getDate.dd, getDate.mm, getDate.yyyy);
                //printf("%s\n",dataString );
                return dataString;

        }

}
void passwordChange(int i)//i=0->Student,i=1->Faculty,i=2->Staff
{
        system("clear");
        printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        Library Management System\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        ------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        Password Reset Request(s)\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        ------------------------\n\n\n\n");
        FILE *fp2;
        fp2=fopen("StudentId.txt","r"); if(fp2==NULL) printf("NULL");
        int Nl = 0,ch1,var=0,var2=-1;
        char line[1024],input[255],*ch_;
        ch_= (char*)malloc(sizeof(char));
        while( fgets(line,1023,fp2) != NULL)
        {
                Nl++;
        }
        rewind(fp2);
        char id[50],npass[50],*dob,*nme,*odob;
        dob = (char *)malloc(sizeof(input));
        nme = (char *)malloc(sizeof(Date));
        odob = (char *)malloc(sizeof(Date));
        printf("Enter your UserId:\t");
        setvbuf(stdin, NULL, _IONBF, 0);
        fscanf(stdin,"%s", id);
       setvbuf(stdin, NULL, _IONBF, 0);
        fscanf(fp2,"%s", input);        
        int cmp;
        int i1=strlen(id);
        int i2=strlen(input);


        for(int z=0; z<Nl; z++)
        {
                cmp=strcmp(input,id);
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
        }
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
        while(var==0)
        {
                dob=teme();
                var=atoi(dob);
        }
        printf("%s %d\n",dob,var );
        printf("\nEnter the new password:\t");
        setvbuf(stdin, NULL, _IONBF, 0);
        fgets(npass,49,stdin);
        fclose(fp2);
        FILE *lname;
        FILE *id_;
        FILE *n_pass;
        FILE *n_dob;
        FILE *o_dob;
        FILE *f_nme;
        FILE *o_dob_r;
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
        printf("\n\nYour equest has been saved");
        int  j=0;
         for(int j=0; j<3; j++)
                        {
                                sleep(1);
                                printf(".");
                        }
                        system("clear");
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
                  //to check total numbers of entries

        rewind(id);
       printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        Library Management System\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        ------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        Password Reset Request(s)\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        ------------------------\n\n\n\n");
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
                printf("--------------------------------------------------\n");
        }
        printf("\n\n");
        printf("#. Previous Menu\t\t\t0.Main Menu\n\n");
        fclose(lname);
        fclose(id);
        fclose(n_pass);
        fclose(dob);

        char *choose;
        printf("\n\n-->\t");
        choose = (char*)malloc(sizeof(char));
        scanf("%s",choose);

        int choice=atoi(choose);
        for(int i=0; i<Nl; i++)
        {
                if(choice==(i+1))
                {
                        system("clear");
                        acpt_decline(choice);
                }
                else if (strcmp(choose, "#") == 0)
                {
                        staffMenu();    
                }
                else if (strcmp(choose, "0") == 0)
                {
                        mainMenu();    
                }
                else if(i+1==Nl)
                {
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

       printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        Library Management System\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        ------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        Password Reset Request(s)\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        ------------------------\n\n\n\n");
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
        rewind(studentid);
        fscanf(studentid,"%s", input);
        input[strcspn(input, "\n")] = '\0';
        for(int z=0; z<Nl; z++)
        {
          int as=strlen(input),vvv=strlen(stu->stu_id);
                cmp=strcmp(input,stu->stu_id);
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
        printf("\n\n-->\t");
        scanf("%s",chopt);
        opt=atoi(chopt);
        

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
                
                sprintf(stu->stu_npass, "%s\n",stu->stu_npass);
                rep = fopen("rep.txt", "w");
                ch = getc(pass);
                while (ch != EOF)
                {
                      
                        if(temp != var2)
                                putc(ch, rep);
                       
                        if(ch == '\n' && temp==var2) {
                                fputs(stu->stu_npass,rep);
                        }
                        if (ch == '\n')
                                temp++;
                        ch = getc(pass);
                }
                fclose(pass);
                fclose(rep);

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
                printf("\n\nReturning to Previous Menu");
                for(int j=0; j<3; j++)
                {
                        sleep(1);
                        printf(".");
                }
                system("clear");
                pssrqst();
        }
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
{printf("\n\n");
  headrq1Loader();
  if(headrq[0]->next==NULL)
  {
    printf("No pending book requests.\n");
    printf("Going back to main page...\n");
    staffMenu();
  }
  int j=0;
  struct reqbook *current;
  current=headrq[0]->next;int i=1;
  while(current!=NULL)
  {
    printf("-----------------------------------------------------------------\n");
    printf("%03d | Title of the book: %s\n",i,current->title);
    printf("    | Name of author: %s\n",current->auname);
    printf("    | Requested by Id: %s\n",current->id);
    current=current->next;i++;
  j++;
  }
    printf("-----------------------------------------------------------------");
  printf("\n\n#. Previous Menu\t\t0. Main Menu\n\n");
  printf("\n\nEnter the corresponding option :\t");
  //We may add delete request also..
  i=0;
  char *att;
  att=(char*)malloc(10);
  scanf("%s",att);
  i=atoi(att);
  if(strcmp(att,"#")==0)
  {
    printf("\e[1;1H\e[2J");
    staffMenu();
  }
  if(strcmp(att,"0")==0)
  {
    printf("\e[1;1H\e[2J");
    mainMenu();
  }
  if(i==0 || i>j)
  {
    printf("Not a valid input; Please try again");
   int xD=0;
    while (xD<3) {
                        sleep(1);
                        printf(".");
                        xD++;
                }
                showBookRequests();
  }
  else
  approveRequest(i);
  staffMenu();
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
    fp3=fopen("ApprovedRequestUserId.txt","a");
    fputs(orb->title,fp1);
    putc('\n',fp1);
    fputs(orb->auname,fp2);
    putc('\n',fp2);
    fputs(orb->id,fp3);
    putc('\n',fp3);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    headrq2Loader();
    struct reqbook *current,*prev;
    current=headrq[0]->next;
    prev=headrq[0];
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
    }return true;
  }
  else
  {
    printf("Something went wrong.You may Try again.\n");
    staffMenu();
  }
return false;
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
 printf("\n-->\tNumber of matching result(s) %d  \n\n",po);
 if(po==0)
 {
   strcpy(str_final.auth,"");
   strcpy(str_final.Title,"");
   strcpy(str_final.Genre,"");
   return str_final;
 }
 printf("S No.\n");
 for(int cnt1=0;cnt1<po;cnt1++)
 {
   printf("       -------------------------------------------------------------------------------\n");
   printf("%03d   | Author      \t %s      | Title\t         %s      | Genre\t         %s",cnt1+1,checkray[cnt1][0],checkray[cnt1][1],checkray[cnt1][2]);
   printf("       -------------------------------------------------------------------------------\n");

 }

printf("\n\n-->\tPlease select any one of the following books :\t");

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

        printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        Library Management System\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n\n\n");
        alert_id(id);
        printf("\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t         ========================================\n");
        printf("\t\t\t\t\t\t\t\t\t\t         |                                      |\n");
        printf("\t\t\t\t\t\t\t\t\t\t         |            1. Issue a Book           |\n");
        printf("\t\t\t\t\t\t\t\t\t\t         |                                      |\n");
        printf("\t\t\t\t\t\t\t\t\t\t         |            2. Return a Book          |\n");
        printf("\t\t\t\t\t\t\t\t\t\t         |                                      |\n");
        printf("\t\t\t\t\t\t\t\t\t\t         |            3. Go to Cart             |\n");
        printf("\t\t\t\t\t\t\t\t\t\t         |                                      |\n");
        printf("\t\t\t\t\t\t\t\t\t\t         |            4. Exit                   |\n");
        printf("\t\t\t\t\t\t\t\t\t\t         |                                      |\n");
        printf("\t\t\t\t\t\t\t\t\t\t         ========================================\n");
 int w=0;
 printf("\n\n-->\t");
 char *wchar;
 wchar=(char*)malloc(10);
 scanf("%s",wchar);
 w=atoi(wchar);
 switch(w)
 {
   case 1: issueBook(id);break;
   case 2: returnbook(id);break;
   case 3: //#TANISH
            printf("\e[1;1H\e[2J\n");
            cart(id);break;
   case 4: exit(0);
   default:
            printf("Invalid \nTry Again");
            int i=0;
            while (i<3) {
                        sleep(1);
                        printf(".");
                        i++;
                }
   studentPage(id);
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
 printf("-->\tSearch the book you want to issue:\t");
 char str[100];
 setvbuf(stdin, NULL, _IONBF, 0);
 gets(str);
 strcpy(str,strupp(str));
        setvbuf(stdout, NULL, _IONBF, 0);
 bklist b,*book;
 b=bookSearch(str);
 if((strcmp(b.auth,"")==0)&&(strcmp(b.Title,"")==0)&&(strcmp(b.Genre,"")==0))
 {
   printf("\nSorry, No such book found\n");
   printf("Do you want to place a request of the book with us?\n");
   printf("\n\t1.Yes\t\t2.No\n\nAny other input will be taken as 2\n");
   char *vio;
   vio=(char*)malloc(10);
   int w;
   printf("-->\t");
   scanf("%s",vio);
   w=atoi(vio);
   if(w==1)
   {

     requestBook(id);
   }
   else
   {
     printf("\e[1;1H\e[2J");
     studentPage(id);
   }
 }
 book=getBook(&b);
 if(book->count>0)
 {
   if(book->count>isReserved(book,id))
   {
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
       fp=fopen("IssuedBooks.txt","a");
       fprintf(fp,"%d\n",book->issue);
       fclose(fp);
       fp=fopen("IssuedUserId.txt","a");
       fprintf(fp,"%s\n",id);
       fclose(fp);
       fp=fopen("IssuedOnDate.txt","a");
       fprintf(fp,"%s\n",datestring);
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
     printf("Sorry the book has been reserved and not available for issuing\n");
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
        printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        Library Management System\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n\n\n");
         alert_id(id);
        printf("\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t         ========================================\n");
        printf("\t\t\t\t\t\t\t\t\t\t         |                                      |\n");
        printf("\t\t\t\t\t\t\t\t\t\t         |            1. Issue a Book           |\n");
        printf("\t\t\t\t\t\t\t\t\t\t         |                                      |\n");
        printf("\t\t\t\t\t\t\t\t\t\t         |            2. Return a Book          |\n");
        printf("\t\t\t\t\t\t\t\t\t\t         |                                      |\n");
        printf("\t\t\t\t\t\t\t\t\t\t         |            3. Go to Cart             |\n");
        printf("\t\t\t\t\t\t\t\t\t\t         |                                      |\n");
        printf("\t\t\t\t\t\t\t\t\t\t         |            4. Exit                   |\n");
        printf("\t\t\t\t\t\t\t\t\t\t         |                                      |\n");
        printf("\t\t\t\t\t\t\t\t\t\t         ========================================\n");
 int w=0;
 scanf("%d",&w);
 switch(w)
 {
   case 1: issueBook(id);flag=false;break;
   case 4: exit(0);flag=false;break;
   case 2: returnbook(id);flag=false;break;
 case 3: cart(id);flag=false;break;
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
     flag=false;printf("\nYou have already reserved this book.\n");
     break;
   }
   prev=current;
   current=current->next;
 }
 if(flag)
 {
   prev->next=p;
   printf("\nBook reserved, You will be notified once it is back with us.\n");
 }
 dumpres(headrv);
 studentPage(id);
}
bool loadCart(bklist *book,char *id)
{
        strcat(id,"\n");
 struct cartbook *current,*p;
 current=headis;
 while(current->next!=NULL)
 {
   if(book->issue==current->issue && strcmp(id,current->id)==0) return false;
   current=current->next;
 }
 if(book->issue==current->issue && strcmp(id,current->id)==0) return false;
 p=(struct cartbook*)malloc(sizeof(struct cartbook));
 current->next=p;
 p->next=NULL;
 p->issue=book->issue;
 strcpy(p->id,id);
 strcat(p->id,"\n");
 dumpis(headis);
 return true;
 id[strcspn(id, "\n")] = '\0';
}
void requestBook(char *id)
{
        printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        Library Management System\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       ------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       Request Book\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       ------------\n\n\n\n");
 char title[255],auname[100];
 printf(" Enter the title of the book you want to order:\t ");
 setvbuf(stdin, NULL, _IONBF, 0);
 fgets(title,100,stdin);
 char *tit;
 tit=strupp(title);
 tit[strcspn(tit, "\n")] = '\0';
 printf("<%s>",tit);
 printf(" Enter the name of the author of the book:\t");
 setvbuf(stdin, NULL, _IONBF, 0);
fgets(auname,100,stdin);
char *aun;
 aun=strupp(auname);
 aun[strcspn(aun, "\n")] = '\0';
 printf("<%s>",aun);
 bool flag=true;
 struct reqbook *current,*prev;
 current=headrq[0]->next;
 prev=headrq[0];

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
   prev=current;printf("<hj>");
   current=current->next;printf("<jk>");

 }
 current=headrq[1]->next;
 prev=headrq[1];

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
   prev=current;printf("<hj>");
   current=current->next;printf("<jk>");

 }
 if(flag)
 {
   printf("1");
   current=(struct reqbook*)malloc(sizeof(struct reqbook));printf("2");
   prev->next=current;printf("3");
   strcpy(current->title,tit);printf("4");
   strcpy(current->auname,aun);printf("5");
   strcpy(current->id,id);printf("6");
   current->next=NULL;printf("7");
   printf("Your request has been saved.\n");
 }
 dumpreq();
 printf("Going Back to Main Menu\n");
 int i=0;
                while (i<3) {
                        sleep(1);
                        printf(".");
                        i++;
                }
                printf("\e[1;1H\e[2J\n");
 studentPage(id);
}
int isReserved(bklist *book, char *id)
{
 //bool flag=false;
 int count=0;
 struct cartbook *current,*prev;
 prev=headrv;
 current=headrv->next;
 while(current!=NULL)
 {
   if(current->issue==book->issue)
   {
     count++;
     if(strcmp(id,current->id)==0)
     {
       count=0;
       printf("You had reserved this book.\n");
       printf("Its available now\n");
       prev->next=current->next;
       current=NULL;
       dumpres(headrv);
       break;
     }
   }
   prev=current;
   current=current->next;
 }
 return count;
}
void headrq1Loader()
{
 FILE *fp1,*fp2,*fp3;
 fp1=fopen("RequestedTitle.txt","r");
 fp2=fopen("RequestedAuName.txt","r");
 fp3=fopen("RequestedUserId.txt","r");
 struct reqbook *p,*current,*prev;
 headrq[0]=(struct reqbook*)malloc(sizeof(struct reqbook));
 p=(struct reqbook*)malloc(sizeof(struct reqbook));
 headrq[0]->next=p;
 prev=headrq[0];
 while(true)
 {
   if(fgets(p->title,100,fp1)==NULL)
   {
     p=NULL;
     prev->next=NULL;
     break;
   }
   p->title[strcspn(p->title,"\n")]='\0';
   fgets(p->auname,100,fp2);
   p->auname[strcspn(p->auname,"\n")]='\0';
   fgets(p->id,100,fp3);
   p->id[strcspn(p->id,"\n")]='\0';
   current=(struct reqbook*)malloc(sizeof(struct reqbook));
   p->next=current;
   prev->next=p;
   prev=p;
   p=current;
 }
 fclose(fp1);
 fclose(fp2);
 fclose(fp3);
}
void headrq2Loader()
{
 FILE *fp1,*fp2,*fp3;
 fp1=fopen("ApprovedRequestTitle.txt","r");
 fp2=fopen("ApprovedRequestAuthor.txt","r");
 fp3=fopen("ApprovedRequestUserId.txt","r");
 struct reqbook *p,*current,*prev;
 headrq[1]=(struct reqbook*)malloc(sizeof(struct reqbook));
 p=(struct reqbook*)malloc(sizeof(struct reqbook));
 headrq[1]->next=p;
 prev=headrq[1];
 while(true)
 {
   if(fgets(p->title,100,fp1)==NULL)
   {
     p=NULL;
     prev->next=NULL;
     break;
   }
   p->title[strcspn(p->title,"\n")]='\0';
   fgets(p->auname,100,fp2);
   p->auname[strcspn(p->auname,"\n")]='\0';
   fgets(p->id,100,fp3);
   p->id[strcspn(p->id,"\n")]='\0';
   current=(struct reqbook*)malloc(sizeof(struct reqbook));
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
 current=headrq[0]->next;
 while(current!=NULL)
 {
   fputs(current->title,fp1);
   putc('\n',fp1);
   fputs(current->auname,fp2);
   putc('\n',fp2);
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
void dumpreq1()
{
 FILE *fp1,*fp2,*fp3;
 fp1=fopen("tempTitle.txt","a");
 fp2=fopen("tempAuName.txt","a");
 fp3=fopen("tempId.txt","a");
 struct reqbook *current;
 current=headrq[1]->next;
 while(current!=NULL)
 {
   fputs(current->title,fp1);
   putc('\n',fp1);
   fputs(current->auname,fp2);
   putc('\n',fp2);
    printf("//////%s/////",current->id);
   fputs(current->id,fp3);
   putc('\n',fp3);
   current=current->next;
 }
 fclose(fp1);
 fclose(fp2);
 fclose(fp3);
 remove("ApprovedRequestUserId.txt");

 rename("tempId.txt","ApprovedRequestUserId.txt");

 remove("ApprovedRequestTitle.txt");

 rename("tempTitle.txt","ApprovedRequestTitle.txt");

 remove("ApprovedRequestAuName.txt");

 rename("tempAuName.txt","ApprovedRequestAuName.txt");
}
char* toUpperCase(char *s)
{
 int l=strlen(s);
 char ch,*str;
 str=(char*)malloc(100);
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
 setvbuf(stdout, NULL, _IONBF, 0);
 return str;
}
char *strupp(char *z)
{
    for(int i=0;*(z+i)!='\0';i++)
    {
        *(z + i) = toupper(*(z+i));
    }
    return z;
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

   if(fgets(commit->id,49, userid) == NULL)
   { free(commit);// done to avoid memory leak
     commit = NULL;// to avoid dangling pointer problem
     break;
   }
   fscanf(iss, "%d\n", &commit->issue);

   commit->next = NULL;
   
   temp->next = commit;

 }

 fclose(userid);
 fclose(iss);


}
void headisLoader()
{
  cartstruct *temp, *commit;


 FILE *userid, *iss;
 userid = fopen("CartUserId.txt", "r+");
 iss = fopen("CartBooks.txt", "r+");
 headis = (cartstruct*)malloc(sizeof(cartstruct));
 for(temp = headis;;temp = temp->next)
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

   if(fgets(commit->id,49, userid) == NULL)
   { free(commit);// done to avoid memory leak
     commit = NULL;// to avoid dangling pointer problem
     printf("NULL");
     break;
   }

   fscanf(iss, "%d\n", &commit->issue);
   commit->next = NULL;
   
   temp->next = commit;

 }

 fclose(userid);
 fclose(iss);
return carthead;

}

bklist bookcheck(int i)
{ 
 bklist *temp;
 int iy;
 for(temp = head->next;temp != NULL;temp = temp->next)
 {
   if(temp->issue == i)
   { iy = 1;
     return *temp;
   }
 }
 if(iy != 1)
 {
   exit(0);
 }
 printf("sorry but there no file like that");

}



bklist* issuebook(cartstruct* cartissuehead)
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
   *commit = bookcheck(temp1->next->issue);
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
     
     temp2->next = commit;
    

     temp2 = temp2->next;
   
  }

return book1;
}
bklist* issuebookv2(struct reqbook* headodr)
{
  struct reqbook* currentodr;
  bklist *books,*prevbook;
  bklist *current,*currentbook;
  current=head->next;
  books=(bklist*)malloc(sizeof(bklist));
  currentodr=headodr->next;
  prevbook=books;
  while(currentodr!=NULL)
  {
    while(current!=NULL)
    {
      int cmp1=strcmp(currentodr->title,current->Title);
      int cmp2=strcmp(currentodr->auname,current->auth);
      if(cmp1==0&&cmp2==0)
      {
        currentbook=(bklist*)malloc(sizeof(bklist));
        currentbook=current;
        prevbook->next=currentbook;
        prevbook=currentbook;
      }
      current=current->next;
    }
    currentodr=currentodr->next;
  }
  return books;
}
cartstruct *specificuserloader(char *id)
{
 struct cartbook *currentrv,*head,*current,*prev;
 currentrv=headrv->next;
 head=(struct cartbook*)malloc(sizeof(struct cartbook));
 strcpy(head->id,id);
 prev=head;
 printf("Successful");
 if(currentrv==NULL) return NULL;
 printf("Expected?");
 //strcat(id,"\n");
 while(currentrv!=NULL)
 {
   printf("<<%s>>",id);
   printf("<<%s>>",currentrv->id);
   if(strcmp(currentrv->id,id)==0)
   {printf("In if");
     current=(struct cartbook*)malloc(sizeof(struct cartbook));
     prev->next=current;
     current->issue=currentrv->issue;
     strcpy(current->id,head->id);
     prev=current;
   }
   currentrv=currentrv->next;
 }
 prev->next=NULL;
 return head;
}
struct reqbook *specificuserloader2(char *id)
{
 struct reqbook *currentrq,*head,*current,*prev;
 currentrq=headrq[1]->next;
 head=(struct reqbook*)malloc(sizeof(struct reqbook));
 strcpy(head->id,id);
 prev=head;
 if(currentrq==NULL) return NULL;
 //strcat(id,"\n");
 while(currentrq!=NULL)
 {
   if(strcmp(currentrq->id,id)==0)
   {
     current=(struct reqbook*)malloc(sizeof(struct reqbook));
     prev->next=current;
     strcpy(current->auname,currentrq->auname);
     strcpy(current->title,currentrq->title);
     strcpy(current->id,head->id);
     prev=current;
   }
   currentrq=currentrq->next;
 }
 current->next=NULL;
 return head;
}
cartstruct *specificuserloader1(char *id)
{
  struct cartbook *currentis,*head,*current,*prev;
  currentis=headis->next;
  head=(struct cartbook*)malloc(sizeof(struct cartbook));
  strcpy(head->id,id);
  prev=head;
  if(currentis==NULL) return NULL;
  strcat(id,"\n");
  while(currentis!=NULL)
  {
    if(strcmp(currentis->id,id)==0)
    {
      current=(struct cartbook*)malloc(sizeof(struct cartbook));
      prev->next=current;
      current->issue=currentis->issue;
      strcpy(current->id,head->id);
      prev=current;
    }
    currentis=currentis->next;
  }
  current->next=NULL;
  return head;
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
   else if(i ==3)
   {
     prev->next = temp->next;
     break;
   }
 }
   if (temp->next == NULL)
   {
     break;
   }


 prev = temp;
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
 temp = temp->next;


}

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
remove("ReservedUserId.txt");
remove("ReservedBooks.txt");
rename("tempReservedUserId.txt","ReservedUserId.txt");
rename("tempReservedBooks.txt","ReservedBooks.txt");
return cont;
}
int dumpis(cartstruct* a)
{
cartstruct *temp; int cont;
FILE *iss,*user;
user = fopen("tempCartUserId.txt","w");
iss = fopen("tempCartBooks.txt","w");

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
fclose(user);
fclose(iss);
remove("CartUserId.txt");
remove("CartBooks.txt");
rename("tempCartUserId.txt","CartUserId.txt");
rename("tempCartBooks.txt","CartBooks.txt");
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



void cart(char *id)
{
  printf("Welcome to your cart..\n");
  printf("ISSUE THE REQUESTED AND THE RESERVED BOOKS THAT ARE SHOWN HERE");
  printf(" BECAUSE WE WILL MAKE THEM AVAILABLE FOR OTHERS AFTER THIS SESSION\n ");
  //if(header->next==NULL) printf("Null");
 // printf("which is you want to select:\n1)issue book\n2)reserve book\n3)requested books");
 char w[4];
 int count1, count2, count3,choice;
 cartstruct *issuelisthead, *reservelisthead;struct reqbook *orderlist;
 cartstruct added,delis;
 bklist  *issuehead, *res_head, *orderhead, *book;
 bklist  book1;
 int cnt, cnt2, cnt3;
 char str1[] = "book you want to issue", str2[] = "book you have reserved till now", str3[] = "Requested books that are available so far", str4[] = "---------------------------------------------------\n";
 char str9[] = "file1.txt", str10[] = "file2.txt";
 cartstruct  *isslist;
 char username[30];
 strcpy(username,id);
 //printf("<<<%s>>>",username);
 //header = cartissuelistloader(str5,str6); // this header wll be passed by aditya choraria
 //strcpy(username,header->next->id);
//  cnt7 = dumpadd();
  // a = cartissuelistloader(str5,str6);
  issuelisthead = specificuserloader1(username);
  if(issuelisthead!=NULL)
  {
    issuehead = issuebook(issuelisthead);
    count1 = print(issuehead,1, str1);
  }
   printf("%d",count1);
   reservelisthead = specificuserloader(username);printf("1");
   count2=count1+0;
   if(reservelisthead!=NULL)
   {
     res_head = issuebook(reservelisthead);
     count2 = print(res_head, count1+1, str2);
   }
   orderlist = specificuserloader2(username);printf("2");
   count3=count2+0;
   if(orderlist!=NULL)
   {
     orderhead = issuebookv2(orderlist);
     count3 = print(orderhead, count2+1, str3);
   }
   if(issuelisthead==NULL&&orderlist==NULL&&reservelisthead==NULL)
   {
     printf("The cart is empty\n");
     studentPage(username);
   }
   printf("%d",count3);
   printf("which one you want to choose -  ");
   choice = menucall(count3);
   printf("\n\nyou entered %d\n",choice);
   if(choice <= count1)
   {
     printf("BOOK SELECTED:\n\n");
     book = nth_link(issuehead, choice);
     //printf("%s",str4);
     //printf("    Author  - %s    Title  - %s    Genre  - %s    Issue no - %d\n", book->auth, book->Title, book->Genre, book->issue);
     //printf("%s",str4);
     printf("This is a really a great choice\n");
     //book1 = editbook(book, 2, head);
     //printf("%d",book1.count);
     if(book->count>0)
     {
       bklist *current;
       current=head->next;
       while(current!=NULL)
       {
         if(current->issue==book->issue)
         {
           current->count--;
           break;
         }
         current=current->next;
       }
       FILE *fp;
       fp=fopen("IssuedBooks.txt","a");
       fprintf(fp,"%d\n",book->issue);
       fclose(fp);
       fp=fopen("IssuedUserId.txt","a");
       fprintf(fp,"%s\n",id);
       fclose(fp);
       fp=fopen("IssuedOnDate.txt","a");
       fprintf(fp,"%s\n",datestring);
       fclose(fp);
       dumpdatabase(head);
       printf("Book Issued\n");
       struct cartbook *currentis,*prev;
       currentis=headis->next;
       prev=headis;
       while(currentis!=NULL)
       {
         if(currentis->issue==book->issue)
         {
           prev->next=currentis->next;
           currentis=NULL;
           break;
         }
         prev=currentis;
         currentis=currentis->next;
       }
       dumpis(headis);
       dumpdatabase(head);
       //##askfor going back to cart or studentPage
     }
     else
     {
       printf("This book is not available now..\n");
         printf("\nDo you want to reserve this book(yes/no) - ");
         scanf("%s",w);
         if(strcmp(w,"yes"))
         {
           bklist *current;
           current=head->next;
           while(current!=NULL)
           {
             if(current->issue==book->issue) break;
             current=current->next;
           }
           reserveBook(current,username);
         }
       }
     }
   else if(choice>count1 && choice<=count2)
   {

     printf("BOOK SELECTED:\n\n");
     book = nth_link(res_head, choice-count1);
     //printf("%s",str4);
     //printf("    Author  - %s    Title  - %s    Genre  - %s    Issue no - %d\n", book->auth, book->Title, book->Genre, book->issue);
     //printf("%s",str4);
     if(book->count == 0)
     {
       printf("Sorry, This book is still not available\nPlease check Availability before proceeding\n\n");
     }
     else
     {
       printf("This is a really a great choice\n");
    // book1 = editbook(book, 2, head);
      // printf("\n\n\n\nhi\n\n\n");
     //added = editlist(&book1, 2, username, headrv);// // for now i am adding a just for testing but rather than passing we have to pass a header which cpmes after loading the reserved list
     bklist* current;
     current=head->next;
     while(current!=NULL)
     {
       if(current->issue==book->issue)
       {
         current->count--;
         break;
       }
       current=current->next;
     }
     struct cartbook* currentrv,*prevrv;
     currentrv=headrv->next;
     prevrv=headrv;
     while(currentrv!=NULL)
     {
       if((currentrv->issue==book->issue)&&(strcmp(currentrv->id,username)==0))
       {
         prevrv->next=currentrv->next;
         currentrv=NULL;
         break;
       }
       prevrv=currentrv;
       currentrv=currentrv->next;
     }
     dumpres(headrv);
     dumpdatabase(head);
     FILE *fp;
     fp=fopen("IssuedBooks.txt","a");
     fprintf(fp,"%d\n",book->issue);
     fclose(fp);
     fp=fopen("IssuedUserId.txt","a");
     fprintf(fp,"%s\n",id);
     fclose(fp);
     fp=fopen("IssuedOnDate.txt","a");
     fprintf(fp,"%s\n",datestring);
     fclose(fp);
     dumpdatabase(head);
     printf("Book Issued\n");
   }
 }
   else if(choice>count2 && choice<=count3)
   {
     printf("BOOK SELECTED:\n\n");
     book = nth_link(orderhead, choice-count2);
     //printf("%s",str4);
     //printf("    Author  - %s    Title  - %s    Genre  - %s    Issue no - %d\n", book->auth, book->Title, book->Genre, book->issue);
     //printf("%s",str4);
     if(book->count == 0)
     {
       printf("Sorry, This book is still not available\nPlease check Availability before proceeding\n\n");
     }
     else
     {
       bklist *current;
       current=head->next;
       while(current!=NULL)
       {
         if(current->issue==book->issue)
         {
           current->count--;
           break;
         }
         current=current->next;
       }
       struct reqbook *currentrq,*prevrq;
       currentrq=headrq[1]->next;
       prevrq=headrq[1];
       while(currentrq!=NULL)
       {
         int cmp1=strcmp(currentrq->auname,book->auth);
         int cmp2=strcmp(currentrq->title,book->Title);
         int cmp3=strcmp(currentrq->id,username);
         if(cmp1==0&&cmp2==0&&cmp3==0)
         {
           prevrq->next=currentrq->next;
           currentrq=NULL;
           break;
         }
         currentrq=currentrq->next;
       }
       dumpreq1();
       FILE *fp;
       fp=fopen("IssuedBooks.txt","a");
       fprintf(fp,"%d\n",book->issue);
       fclose(fp);
       fp=fopen("IssuedUserId.txt","a");
       fprintf(fp,"%s\n",id);
       fclose(fp);
       fp=fopen("IssuedOnDate.txt","a");
       fprintf(fp,"%s\n",datestring);
       fclose(fp);
       dumpdatabase(head);
       printf("Book Issued\n");
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
        printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        Library Management System\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       ----------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       Staff Page\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       ----------\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t        ========================================================\n");
        printf("\t\t\t\t\t\t\t\t\t        |                                                      |\n");
        printf("\t\t\t\t\t\t\t\t\t        |            1. Add a Member                           |\n");
        printf("\t\t\t\t\t\t\t\t\t        |                                                      |\n");
        printf("\t\t\t\t\t\t\t\t\t        |            2. Delete a Member                        |\n");
        printf("\t\t\t\t\t\t\t\t\t        |                                                      |\n");
        printf("\t\t\t\t\t\t\t\t\t        |            3. Check Inventory                        |\n");
        printf("\t\t\t\t\t\t\t\t\t        |                                                      |\n");
        printf("\t\t\t\t\t\t\t\t\t        |            4. Check Password Change Request          |\n");
        printf("\t\t\t\t\t\t\t\t\t        |                                                      |\n");
        printf("\t\t\t\t\t\t\t\t\t        |            5. Check Book Requests                    |\n");
        printf("\t\t\t\t\t\t\t\t\t        |                                                      |\n");
        printf("\t\t\t\t\t\t\t\t\t        ========================================================\n");
                int w=0;
                char *cho;
                cho=(char*)malloc(10);
                printf("-->\t");
                scanf("%s",cho);
                w=atoi(cho);
                switch(w)
                {
                case 1: addMember(); flag=false; break;
                case 2: deleteMember(); flag=false; break;
                case 3: inventry();flag=false;break;
                case 4:pssrqst() ; flag=false; break;
                case 5:showBookRequests();flag=false;break;
      default:printf("Invalid option...Try again");int i=0;while (i<3) {
                        sleep(1);
                        printf(".");
                        i++;
                }
                staffMenu();
                break;
    }
  }
}
struct reqbook* nthNode(int n)
{
  bool flag=true;
  struct reqbook *current;
  current=headrq[0];
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
{                                                               printf("In book order");
z->au_name[strcspn(z->au_name,"\n")]='\0';
z->bk_name[strcspn(z->bk_name,"\n")]='\0';
z->qty[strcspn(z->qty,"\n")]='\0';
z->stat[strcspn(z->stat,"\n")]='\0';
z->gen[strcspn(z->gen,"\n")]='\0';
z->vndr[strcspn(z->vndr,"\n")]='\0';
FILE *auth,*bkname,*qty,*odrid,*status,*vndr,*genre;
struct odr *headodr,*current,*prev;
auth = fopen("authorodr.txt","r");
bkname = fopen("booknameodr.txt","r");
qty = fopen("qtyodr.txt","r");
odrid = fopen("orderid.txt","r");
status = fopen("statusodr.txt","r");
vndr = fopen("vendorodr.txt","r");
genre = fopen("genreodr.txt","r");
headodr = (order*) malloc(sizeof(order));printf("all files opened");
prev=headodr;
current=(order*)malloc(sizeof(order));
prev->next=current;printf("much work done");
while(true)
{
  if(fgets(current->au_name,50,auth)==NULL)
  {
    prev->next=NULL;
    current=NULL;
    break;
  }
  current->au_name[strcspn(current->au_name,"\n")]='\0';
  fgets(current->bk_name,60,bkname);
  current->bk_name[strcspn(current->bk_name,"\n")]='\0';
  fgets(current->qty,30,qty);
  current->qty[strcspn(current->qty,"\n")]='\0';
  fgets(current->stat,30,status);
  current->stat[strcspn(current->stat,"\n")]='\0';
  fgets(current->vndr,30,vndr);
  current->vndr[strcspn(current->vndr,"\n")]='\0';
  fgets(current->gen,30,genre);
  current->gen[strcspn(current->gen,"\n")]='\0';
  fscanf(odrid,"%d\n",&current->odrid);
  prev=current;
  current=(order*)malloc(sizeof(order));
  prev->next=current;
}printf("surprised?");
free(prev);
free(current);
fclose(auth);
fclose(bkname);
fclose(qty);
fclose(odrid);
fclose(status);
fclose(vndr);
fclose(genre);
current=headodr->next;
bool found=false;
while(!found&&current!=NULL)
{printf("You are sad");
  int cmp1=strcmp(z->au_name,z->bk_name);
  int cmp2=strcmp(z->bk_name,z->bk_name);
  if(cmp1==0&&cmp2==0)
  {
    found=true;
    break;
  }
  prev=current;
  current=current->next;
}printf("Fuck");
if(found)
{
  printf("There is already an order for this book, with status = %s\n",prev->stat);
  printf("Do you want to continue placing this order?\n");
  printf("1.Yes\n2.No\n");
  printf("Any other input would be taken as 2\n");
  int ch=0;
  scanf("%d",&ch);
  if(ch==1) found =false;
}
if(!found)
{
  z->odrid=prev->odrid+1;
  prev->next=z;
  z->next=NULL;
  auth = fopen("tempauthorodr.txt","w");
  bkname = fopen("tempbooknameodr.txt","w");
  qty = fopen("tempqtyodr.txt","w");
  odrid = fopen("temporderid.txt","w");
  status = fopen("tempstatusodr.txt","w");
  vndr = fopen("tempvendorodr.txt","w");
  genre = fopen("tempgenreodr.txt","w");printf("Done all that again");
  current=headodr->next;
  while(current!=NULL)
  {printf("in while again");
    fputs(current->au_name,auth);
    putc('\n',auth);
    fputs(current->bk_name,bkname);
    putc('\n',bkname);
    fputs(current->qty,qty);
    putc('\n',qty);
    fputs(current->stat,status);
    putc('\n',status);
    fputs(current->gen,genre);
    putc('\n',genre);
    fputs(current->vndr,vndr);
    putc('\n',vndr);
    fprintf(odrid,"%d\n",current->odrid);
    current=current->next;
  }printf("out of while");
  fclose(auth);
  fclose(bkname);
  fclose(qty);
  fclose(odrid);
  fclose(status);
  fclose(vndr);
  fclose(genre);
  remove("authorodr.txt");
  remove("booknameodr.txt");
  remove("qtyodr.txt");
  remove("orderid.txt");
  remove("statusodr.txt");
  remove("vendorodr.txt");
  remove("genreodr.txt");
  rename("tempauthorodr.txt","authorodr.txt");
  rename("tempbooknameodr.txt","booknameodr.txt");
  rename("tempqtyodr.txt","qtyodr.txt");
  rename("temporderid.txt","orderid.txt");
  rename("tempstatusodr.txt","statusodr.txt");
  rename("tempvendorodr.txt","vendorodr.txt");
  rename("tempgenreodr.txt","genreodr.txt");
  printf("\n-----------------------You Have Successfully Placed an Order------------------\n");
}
}
bool approvingRequest(char *str1,char *str2)
{
order *c;
c = (order*)malloc(sizeof(order));
strcpy(c->au_name,str1);
strcpy(c->bk_name,str2);
printf("Enter Quantity = ");
setvbuf(stdin, NULL, _IONBF, 0);
fgets(c->qty,30, stdin);
printf("Enter Vendor Name = ");
setvbuf(stdin, NULL, _IONBF, 0);
fgets(c->vndr,30, stdin);
strcpy(c->vndr,strupp(c->vndr));
printf("Enter Genre = ");
setvbuf(stdin, NULL, _IONBF, 0);
fgets(c->gen,30, stdin);
strcpy(c->gen,strupp(c->gen));
setvbuf(stdout, NULL, _IONBF, 0);
printf("<%s><%s><%s><%s><%s>",c->au_name,c->bk_name,c->qty,c->vndr,c->gen);
strcpy(c->stat,"PENDING");
bookorder(c);// function takes in string pointer as parameter and returns the header which helps in access of the linked list

printf("-----------------------Thank You--------------------");
printf("<%s><%s><%s><%s><%s>",c->au_name,c->bk_name,c->qty,c->vndr,c->gen);
printf("---\n-----------------------Returning Back To Book Requests Page---------");
printf("--------------\n");
return true;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

struct rebk {
        char* bkt;
        char* bka;
        char* bkgnre;
        char* bkcnt;
        char* issno;
        int cc;
};


void returnbook(char *idi) //add a char id;
{
        printf("\e[1;1H\e[2J");
        FILE *issuedid;
        FILE *issueno;
        FILE *issue;
        FILE *author;
        FILE *count;
        FILE *title;
        FILE *genre;
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t --------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t Return Book(s)\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t --------------\n\n\n\n");

        issueno=fopen("IssuedBooks.txt","r");
        issuedid=fopen("IssuedUserId.txt","r");
        issue=fopen("issue_no.txt","r");
        author=fopen("AUTHOR.txt","r");
        title=fopen("TITLE.txt","r");
        genre=fopen("Genre.txt","r");
        count=fopen("Count.txt","r");
        int Nl = 0,var2=-1;
        char line[1024],input[255],input1[255],input2[255],input3[255],input4[255],input5[255];
        char ide[50];
        strcpy(ide,idi);
        int v=strlen(ide);
        while( fgets(line,1023,issuedid) != NULL)
        {
                Nl++;
        }

        rewind(issuedid);
        fscanf(issuedid,"%s", input);
        int cmp;
        int b,i=0,imp=0,var3;
        for(int z=0; z<Nl; z++)
        {
                cmp=strcmp(input,ide);                
                if(cmp> 0 || cmp <0)
                {
                        cmp=9;
                }
                if(cmp==0)
                {
                        var2=z;                
                        cmp++;
                        imp++;
                }
                fscanf(issuedid,"%s", input);
        }
        struct rebk bok[10];
        rewind(issuedid);
        fscanf(issuedid,"%s", input);
        for(int z=0; z<Nl; z++)
        {
                cmp=strcmp(input,ide);
                if(cmp> 0 || cmp <0)
                {
                        cmp=9;
                }
                if(cmp==0)
                {
                        var2=z;
                        cmp++;
                        if(b==var2 || b<var2)
                        {

                                for(b=0; b<var2+1; b++)
                                {
                                        fscanf(issueno,"%s",input);                                
                                        cmp=0;
                                }
                                b=0;
                                fscanf(issue,"%s",input1);
                                fgets(input2,254,author);
                                fgets(input3,254,title);
                                fgets(input4,254,genre);
                                fgets(input5,254,count);
                                input2[strcspn(input2, "\n")] = '\0';
                                input3[strcspn(input3, "\n")] = '\0';
                                input4[strcspn(input4, "\n")] = '\0';
                                input5[strcspn(input5, "\n")] = '\0';
                                int att=atoi(input);
                                for(int x=0; x<att; x++)
                                {
                                        
                                        cmp=strcmp(input,input1);
                                        
                                        if(cmp> 0 || cmp <0)
                                        {
                                                cmp=9;
                                        }
                                        if(cmp==0)
                                        {
                                                var2=z;
                                                cmp++;
                                                
                                                printf("   ---------------------------------------------------------\n");
                                                printf("%02d.| Title : %s\n", i+1,input3);
                                               
                                                bok[i].bkt = strdup(input3);
                                                
                                                printf("   | Author : %s\n", input2);
                                                
                                                bok[i].bka = strdup(input2);
                                               
                                                printf("   | Genre : %s\n", input4);
                                               
                                                bok[i].bkgnre = strdup(input4);
                                                
                                                printf("   | Count : %s\n", input5);
                                                bok[i].bkcnt = strdup(input5);
                                                printf("   | Issue No : %s\n", input1);
                                                bok[i].issno = strdup(input1);
                                                bok[i].cc = var2;
                                                
                                                printf("   ---------------------------------------------------------\n\n");
                                                i=i+1;
                                                
                                                break;
                                        }
                                        fscanf(issue,"%s", input1);

                                        fgets(input2,254,author);
                                        fgets(input3,254,title);
                                        fgets(input4,254,genre);
                                        fgets(input5,254,count);
                                        
                                        input2[strcspn(input2, "\n")] = '\0';
                                        input3[strcspn(input3, "\n")] = '\0';
                                        input4[strcspn(input4, "\n")] = '\0';
                                        input5[strcspn(input5, "\n")] = '\0';


                                }
                                rewind(count);
                                rewind(genre);
                                rewind(title);
                                rewind(issue);
                                rewind(author);
                                rewind(issueno);
                        }
                }
                fscanf(issuedid,"%s", input);
        }
        if(i==0)
        {
          printf("-->\tNo books(s) to return\nGoing back to your account");
          int xx=0;
          while (xx<3) {
                        sleep(1);
                        printf(".");
                        xx++;
                }
                printf("\e[1;1H\e[2J");
                studentPage(idi);
        }
        printf("\n\n#. Previous Menu\t\t0. Main Menu\n\n");
       
        char *choose;
        printf("\n\nSelect one option:\t");
        choose = (char*)malloc(100);
        scanf("%s",choose);
        int choice=atoi(choose);
if(choice<=i)
{
        for(int i=0; i<imp; i++)
        {
                if(choice==(i+1))
                {
                        rewind(count);
                        rewind(issue);
                        Nl=0;
                        while( fgets(line,1023,issue) != NULL)
                        {
                                Nl++;
                               }

                        rewind(issue);
                        fscanf(issue,"%s", input);

                        for(int z=0; z<Nl; z++)
                        {
                                cmp=strcmp(input,bok[choice-1].issno);
                              
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
                                fscanf(issue,"%s", input);
                               
                        }

                        break;

                }
                else if (strcmp(choose, "#") == 0)
                {
                       system("clear");
                        studentPage(idi);
                        break;
                }
                 else if (strcmp(choose, "0") == 0)
                {
                       system("clear");
                        mainMenu();
                        break;
                }
                else if(i+1==imp)
                {
                        
                        printf("Invalid option; Choose again ");
                        for(int j=0; j<3; j++)
                        {
                                sleep(1);
                                printf(".");
                        }
                        system("clear");
                        returnbook(idi);
                        
                }
        }
}
else
{
  {
    printf("Invalid option; Choose again ");
                        for(int j=0; j<3; j++)
                        {
                                sleep(1);
                                printf(".");
                        }
                        
                        returnbook(idi);
  }
}

        
        int temp=1;
        
        int beta=atoi(bok[choice-1].bkcnt)+1;
        FILE *rep;
        rep = fopen("rep.txt", "w");
        char ch;
        ch = getc(count);
        while (ch != EOF)
        {
                if(temp != var2)
                putc(ch, rep);
                
               if(ch == '\n' && temp==var2) {
               fprintf(rep,"%d\n",beta);
                         }
                if (ch == '\n')
                        temp++;
                ch = getc(count);
        }
        fclose(rep);
        rewind(issueno);
        temp=1;
        rep = fopen("rep1.txt", "w");
        ch = getc(issueno);
        while (ch != EOF)
        {
                if(temp != bok[choice-1].cc+1)
                        putc(ch, rep);
                if (ch == '\n'){
                        temp++;
                    }
                ch = getc(issueno);
        }
fclose(rep);
        temp=1;
        rewind(issuedid);
        rep = fopen("rep2.txt", "w");
        ch = getc(issuedid);
        while (ch != EOF)
        {
                if(temp != bok[choice-1].cc+1)
                        putc(ch, rep);
                if (ch == '\n'){
                        temp++;
                    }
                ch = getc(issuedid);
        }
      //  fclose(orgdob);
        fclose(rep);
      //  remove("ps_rqt/StudentDob.txt");
        //rename("ps_rqt/rep.txt","ps_rqt/StudentDob.txt");
        printf("\n\nBook returned successfully");
        printf("\nReturning Back to Previous Menu");
        int xx=0;
        while (xx<3) {
                        sleep(1);
                        printf(".");
                        xx++;
                }
        printf("\e[1;1H\e[2J");
        studentPage(idi);

}
//void inccount()
 void inventry()
  { 
   printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        Library Management System\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       ---------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       Inventory\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       ---------\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t        ========================================================\n");
        printf("\t\t\t\t\t\t\t\t\t        |                                                      |\n");
        printf("\t\t\t\t\t\t\t\t\t        |            1. Add Book(s)                            |\n");
        printf("\t\t\t\t\t\t\t\t\t        |                                                      |\n");
        printf("\t\t\t\t\t\t\t\t\t        |            2. Delete Book(s)                         |\n");
        printf("\t\t\t\t\t\t\t\t\t        |                                                      |\n");
        printf("\t\t\t\t\t\t\t\t\t        |            3. Order(s)                               |\n");
        printf("\t\t\t\t\t\t\t\t\t        |                                                      |\n");
        printf("\t\t\t\t\t\t\t\t\t        |            4. Issued Book(s)                         |\n");
        printf("\t\t\t\t\t\t\t\t\t        |                                                      |\n");
        printf("\t\t\t\t\t\t\t\t\t        |            5. Search Book(s)                         |\n");
        printf("\t\t\t\t\t\t\t\t\t        |                                                      |\n");
        printf("\t\t\t\t\t\t\t\t\t        ========================================================\n");

    printf("\n\n#. Previous Menu");
    printf("\t\t0. Main Menu\n\n");
    option();
  }

void option()
{
  int a;
  char *cho;
  cho=(char*)malloc(10);
  printf("\n-->\t");
  scanf("%s",cho);
  a=atoi(cho);
  setvbuf(stdin, NULL, _IONBF, 0);
  if(strcmp(cho,"#")==0)
        {
        printf("\e[1;1H\e[2J");
        staffMenu();
        }
        if(strcmp(cho,"0")==0)
        {
          printf("\e[1;1H\e[2J");
          mainMenu();

        }
  bklist bookfinded;//bklist *header;
  char str10[40];
  int option4;
  int seliss;

  switch(a)
  {
    default:
            printf("\nInvalid Option\n\nTry Again\n");
            option();
    case 1:
            system("clear");
                 printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        Library Management System\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       ----------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       Add a Book\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       ----------\n\n\n\n");
            printf("How do you want to search book :- \n\n1. Search by Issue No. (select this option only if you want to increase the count of a particular book)\n\n2. Search by Title or Genre or Author (select this option if you want to add a new book to the database)\n\n");

            printf("please enter a valid option:\t");
            char *coi;
            coi=(char*)malloc(10);
            scanf("%s",coi);
            option4=atoi(coi);
            if(option4==0)
            {
                    printf("Invalid Input, Try Again");
                    int ii=0;
                while (ii<3) {
                        sleep(1);
                        printf(".");
                        ii++;
                }
                printf("\e[1;1H\e[2J\n");
                inventry();
            }
            else
            {
            if (option4 == 2)
            {
            printf("Please enter the book you want to search:\t");
            gets(str10);
            scanf("%s",str10);
            bookfinded = bookSearch(strupp(str10));
            if(!(bookfinded.Title && bookfinded.Title[0]))
            {
             printf("\n No such book found please enter the book Title, Genre, Author");

             gets(bookfinded.Title);
             gets(bookfinded.Genre);
             gets(bookfinded.auth);
             strcpy(bookfinded.Title,strupp(bookfinded.Title));
             strcpy(bookfinded.Genre,strupp(bookfinded.Genre));
             strcpy(bookfinded.auth,strupp(bookfinded.auth));

            }
            }
            else if (option4 == 1)
            {
              printf("\nPlease enter the Issue No. of the Book:\t");
              char *cobi;
            cobi=(char*)malloc(10);
            scanf("%s",cobi);
            int seliss;
              seliss=atoi(cobi);
              //header = loaddatabase();
              bookfinded = bookcheck( seliss);
            }

            //header = loaddatabase();
            bookfinded = editbook(&bookfinded,1, head);
            printf("\nbook added\n");
            dumpdatabase(head);
            break;
            }
    case 2:
            system("clear");
            printf("How do you want to search book :- \n\n1. Search by Issue No. (select this option only if you want to decrease the count of a particular book)\n\n2. Search by Title or Genre or Author (select this option if you want to delete a book from the database)\n\n");

            printf("please enter a valid option:\t");
            char *covi;
            covi=(char*)malloc(10);
            scanf("%s",covi);
            option4=atoi(covi);
            if(option4==0)
            {
                    printf("Invalid Input, Try Again");
                    int ii=0;
                while (ii<3) {
                        sleep(1);
                        printf(".");
                        ii++;
                }
                printf("\e[1;1H\e[2J\n");
                inventry();
            }
            else
            {
            if (option4 == 2)
            {
            printf("Please enter the book you want to search:\t");
            gets(str10);
            scanf("%s",str10);
            bookfinded = bookSearch(strupp(str10));
            if(!(bookfinded.Title && bookfinded.Title[0]))
            {
             printf("\n\n No such book found please enter a valid book");

            }
            }
            else if (option4 == 1){
            printf("\nPlease enter the issue no of the book:\t");
            int seliss;
            char *cobji;
            cobji=(char*)malloc(10);
            scanf("%s",cobji);
              seliss=atoi(cobji);
            //scanf("%d",&seliss);
            //header = loaddatabase();
            bookfinded = bookcheck(seliss);
            }

            //header = loaddatabase();
            printf("What operation do you want to perform \n\n1. Reduce Count of a particular book\n\n2. Delete a book permanently");
            int cnt11;
            scanf("%d",&cnt11);
            if(cnt11 == 1)
            {
              bookfinded = editbook(&bookfinded,2, head);
            }
            else if (cnt11 == 2)
            {
              bookfinded = editbook(&bookfinded,3, head);
            }
            dumpdatabase(head);
            printf("\nbook deleted\n");
            break;
            }
    case 3:
            system("clear");
          bookorder1();// function to call request
            break;
    case 4:
            system("clear");
           issuedbokdet();// function to call issue
            break;
    case 5:
            //search book
            break;

  }
}
void issuedbokdet()
{
        FILE *issuedid;
        FILE *issueno;
        FILE *issue;
        FILE *author;
        FILE *count;
        FILE *title;
        FILE *genre;
        FILE *usstnm;
        FILE *usstid;
        FILE *usftid;
        FILE *usftnm;
        printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        Library Management System\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       ----------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       Issued Book(s)\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       ----------\n\n\n\n");

        issueno=fopen("IssuedBooks.txt","r");
        issuedid=fopen("IssuedUserId.txt","r");
        usstnm=fopen("StudentName.txt","r");
        usftnm=fopen("FacultyName.txt","r");
        usstid=fopen("StudentId.txt","r");
        usftid=fopen("FacultyId.txt","r");
        issue=fopen("issue_no.txt","r");
        author=fopen("AUTHOR.txt","r");
        title=fopen("TITLE.txt","r");
        genre=fopen("Genre.txt","r");
        count=fopen("Count.txt","r");
        int Nl = 0,var2=-1;
        char line[1024],input[255],input1[255],input2[255],input3[255],input4[255],input5[255],input6[255];
        char ide[50];
        while( fgets(line,1023,issuedid) != NULL)
        {
                Nl++;
        }
        rewind(issuedid);
        fscanf(issuedid,"%s", input);
        strcpy(ide,input);
        int cmp;
        int b,i=0,imp=0,var3;
        for(int z=0; z<Nl; z++)
        {
                cmp=strcmp(input,ide);
                if(cmp> 0 || cmp <0)
                {
                        cmp=9;
                }
                if(cmp==0)
                {
                        var2=z;
                        cmp++;
                        imp++;
                }
                fscanf(issuedid,"%s", input);
                strcpy(ide,input);

        }
        struct rebk bok[10];
        rewind(issuedid);
        fscanf(issuedid,"%s", input);
        strcpy(ide,input);
        int bb=0,cmpu=0,var7=9;
        for(int z=0; z<Nl; z++)
        {
                cmp=strcmp(input,ide);
                while( fgets(line,1023,usstid) != NULL)
                {
                        bb++;
                }

                rewind(usstid);
                fscanf(usstid,"%s", input6);
                for(int aa=0; aa<bb; aa++)
                {
                        cmpu=strcmp(input6,ide);
                        if(cmpu> 0 || cmpu <0)
                        {
                                cmpu=9;
                        }
                        if(cmpu==0)
                        {
                                var7=aa+1;
                                cmpu++;
                                break;
                        }
                        fscanf(usstid,"%s", input6);


                }
                if(cmpu!=1)
                {
                        while( fgets(line,1023,usftid) != NULL)
                        {
                                bb++;
                        }

                        rewind(usftid);
                        fscanf(usftid,"%s", input6);
                        for(int aa=0; aa<bb; aa++)
                        {
                                cmpu=strcmp(input6,ide);
                                if(cmpu> 0 || cmpu <0)
                                {
                                        cmpu=9;
                                }
                                if(cmpu==0)
                                {
                                        var7=aa+1;
                                        cmpu=cmpu+2;
                                        break;
                                }
                                fscanf(usftid,"%s", input6);


                        }
                        for(int jj=0; jj<var7; jj++)
                        {
                                fgets(input6,249, usftnm);
                        }
                }
                rewind(usftnm);
                if(cmpu!=2)
                {
                        for(int jj=0; jj<var7; jj++)
                        {
                                fgets(input6,249, usstnm);
                        }
                }
                rewind(usstnm);
                if(cmp> 0 || cmp <0)
                {
                        cmp=9;
                }
                if(cmp==0)
                {
                        var2=z;

                        cmp++;

                        if(b==var2 || b<var2)
                        {

                                for(b=0; b<var2+1; b++)
                                {
                                        fscanf(issueno,"%s",input);

                                        cmp=0;
                                }
                                b=0;

                                fscanf(issue,"%s",input1);
                                fgets(input2,254,author);
                                fgets(input3,254,title);
                                fgets(input4,254,genre);
                                fgets(input5,254,count);

                                input2[strcspn(input2, "\n")] = '\0';
                                input3[strcspn(input3, "\n")] = '\0';
                                input4[strcspn(input4, "\n")] = '\0';
                                input5[strcspn(input5, "\n")] = '\0';
                                input6[strcspn(input6, "\r\n")] = '\0';

                                int att=atoi(input);

                                for(int x=0; x<att; x++)
                                {
                                        
                                        cmp=strcmp(input,input1);
                                        
                                        if(cmp> 0 || cmp <0)
                                        {
                                                cmp=9;
                                        }
                                        if(cmp==0)
                                        {
                                                var2=z;
                                                cmp++;
                                                
                                                printf("   ---------------------------------------------------------\n");
                                                printf("%02d.| Title     : %s\n", i+1,input3);
                                                
                                                bok[i].bkt = strdup(input3);
                                               
                                                printf("   | Author    : %s\n", input2);
                                               
                                                bok[i].bka = strdup(input2);
                                               
                                                printf("   | Genre     : %s\n", input4);
                                               
                                                bok[i].bkgnre = strdup(input4);
                                               
                                                printf("   | Count     : %s\n", input5);
                                                bok[i].bkcnt = strdup(input5);
                                                printf("   | Issue No  : %s\n", input1);
                                                bok[i].issno = strdup(input1);
                                                bok[i].cc = var2;
                                                printf("   | Issued By : %s (%s)\n", input6,ide);
                                               
                                                printf("   ---------------------------------------------------------\n\n");
                                                i=i+1;
                                                
                                                break;
                                        }
                                        fscanf(issue,"%s", input1);

                                        fgets(input2,254,author);
                                        fgets(input3,254,title);
                                        fgets(input4,254,genre);
                                        fgets(input5,254,count);
                                        
                                        input2[strcspn(input2, "\n")] = '\0';
                                        input3[strcspn(input3, "\n")] = '\0';
                                        input4[strcspn(input4, "\n")] = '\0';
                                        input5[strcspn(input5, "\n")] = '\0';


                                }
                                rewind(count);
                                rewind(genre);
                                rewind(title);
                                rewind(issue);
                                rewind(author);
                                rewind(issueno);
                        }
                }
                fscanf(issuedid,"%s", input);
                strcpy(ide,input);
        }
        if(i==0)
        {
                printf("-->\tNo books(s) issued\nGoing back");
                int xx=0;
                while (xx<3) {
                        sleep(1);
                        printf(".");
                        xx++;
                }
                printf("\e[1;1H\e[2J");
               
        }
        printf("\n\n#. Previous Menu\t\t0. Main Menu\n\n");

        char *choose;
        printf("\n\nSelect one option:\t");
        choose = (char*)malloc(100);
        scanf("%s",choose);
        int choice=atoi(choose);

        if (strcmp(choose, "#") == 0)
        {
                inventry();
                

        }
        else if (strcmp(choose, "0") == 0)
        {
                staffMenu();
                
        }
        else if(i+1==imp)
        {
                
                printf("Invalid option; Choose again ");
                for(int j=0; j<3; j++)
                {
                        sleep(1);
                        printf(".");
                }
               
                issuedbokdet();
        
        }

        exit(0);
}

void bookorder1()
{
        int k=0,l=0,m=0;/*these variables 'k','l','m' are used below to break the while loop if user input satisfies the condition*/
        char ch1[5],ch3[5],ch4[5];/*these variables 'ch1','ch3','ch4' are used below to get input from the user, here string is used in place of integer as to avoid getting error by user entering invalid input*/
        printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        Library Management System\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       ----------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       Book Order\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       ----------\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t        ========================================================\n");
        printf("\t\t\t\t\t\t\t\t\t        |                                                      |\n");
        printf("\t\t\t\t\t\t\t\t\t        |          1. Place Order for Requested Book(s)        |\n");
        printf("\t\t\t\t\t\t\t\t\t        |                                                      |\n");
        printf("\t\t\t\t\t\t\t\t\t        |          2. View Order(s)                            |\n");
        printf("\t\t\t\t\t\t\t\t\t        |                                                      |\n");
        printf("\t\t\t\t\t\t\t\t\t        |          3. Manage Order(s)                          |\n");
        printf("\t\t\t\t\t\t\t\t\t        |                                                      |\n");
        printf("\t\t\t\t\t\t\t\t\t        ========================================================\n");
        printf("\n\n#. Previous Menu\t\t");
        printf("0. Main Menu");
        printf("\n\n-->\t");
        scanf("%s",ch1);
        if(strcmp(ch1,"#")==0)
        {
        printf("\e[1;1H\e[2J");
        inventry();
        }
        if(strcmp(ch1,"0")==0)
        {
          printf("\e[1;1H\e[2J");
          mainMenu();

        }
        while(k==0)/*Here this while loop is used just to make user enter a valid input,if by mistake he/she entered an invalid input */
        { switch(atoi(ch1))
          {
          case 1: printf("\e[1;1H\e[2J");/*Here I'm using regex to clear console screen*/
                  funcall1();
                  bookorder1();
                  k=1;//breaks while loop
                  break;

          case 2: printf("\e[1;1H\e[2J");/*Here I'm using regex to clear console screen*/
           printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        Library Management System\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       -------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       View Order(s)\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       -------------\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t        =============================================\n");
        printf("\t\t\t\t\t\t\t\t\t\t        |                                           |\n");
        printf("\t\t\t\t\t\t\t\t\t\t        |          1. All Order(s)                  |\n");
        printf("\t\t\t\t\t\t\t\t\t\t        |                                           |\n");
        printf("\t\t\t\t\t\t\t\t\t\t        |          2. Pending Order(s)              |\n");
        printf("\t\t\t\t\t\t\t\t\t\t        |                                           |\n");
        printf("\t\t\t\t\t\t\t\t\t\t        |          3. Cancelled Order(s)            |\n");
        printf("\t\t\t\t\t\t\t\t\t\t        |                                           |\n");
        printf("\t\t\t\t\t\t\t\t\t\t        =============================================\n");
                  printf("\n\n#. Previous Menu\t\t");
                  printf("0. Main Menu\t\t");
                  printf("\n\n-->\t");
                  scanf("%s",ch3);
                  if(strcmp(ch3,"#")==0)
        {
        printf("\e[1;1H\e[2J");
        bookorder1();
        }
        if(strcmp(ch3,"0")==0)
        {
          printf("\e[1;1H\e[2J");
          mainMenu();

        }
                 // if(strcmp())
                  while(l==0)/*Here this while loop is used just to make user enter a valid input,if by mistake he/she entered an invalid input */
                  { switch(atoi(ch3))
            {
            case 1://printf("\e[1;1H\e[2J");/*Here I'm using regex to clear console screen*/
                    funcall4();
                    bookorder1();
                    l=1;//breaks while loop
                    break;

            case 2://printf("\e[1;1H\e[2J");/*Here I'm using regex to clear console screen*/
                    funcall2();
                    bookorder1();
                    l=1;//breaks while loop
                    break;

            case 3://printf("\e[1;1H\e[2J");/*Here I'm using regex to clear console screen*/
                    funcall3();
                    bookorder1();
                    l=1;
                    break;

            case 4: printf("\e[1;1H\e[2J");/*Here I'm using regex to clear console screen*/
                    bookorder1();
                    l=1;
                    break;

            case 5: printf("\e[1;1H\e[2J");/*Here I'm using regex to clear console screen*/
//idhar main menu ka function dalna hai
                    l=1;
                    break;

            case 6: printf("\e[1;1H\e[2J");/*Here I'm using regex to clear console screen*/
                    exit(0);
                    l=1;//breaks while loop
            default: printf("\nPlease enter an valid Input : ");
                    scanf("%s",ch3);
                    continue;//takes control back to the starting of the while loop
            }}
                  k=1;//breaks while loop
                  break;

          case 3: printf("\e[1;1H\e[2J");/*Here I'm using regex to clear console screen*/
                  char str[50]; int num;
                  //order *a;
                      printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        Library Management System\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       -------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       View Order(s)\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       -------------\n\n\n\n");
                  printf("Please enter a valid order id : ");
                  scanf("%d",&num);
                  sprintf(str,"%d",num);
                  booksearchid(str);

                  printf("\n\nPlease select Any one option to change current order status to\n\n");
                  printf("1. Pending\n");
                  printf("2. Received\n");
                  printf("3. Cancelled\n\n");
                  printf("#. Main Menu\t");
                  printf("0. Previous Menu\n\n");
                  printf("-->\t");
                  scanf("%s",ch4);
                  if(strcmp(ch4,"#")==0)
        {
        printf("\e[1;1H\e[2J");
        bookorder1();
        }
        if(strcmp(ch4,"0")==0)
        {
          printf("\e[1;1H\e[2J");
          mainMenu();

        }
                  while(m==0)/*Here this while loop is used just to make user enter a valid input,if by mistake he/she entered an invalid input */
                  { switch(atoi(ch4))
            {
            case 1: printf("\e[1;1H\e[2J");/*Here I'm using regex to clear console screen*/
                    statusfn(atoi(ch4),num);
                    printf("\n\n--------------You have Successfully Changed Current Status To PENDING--------------\n--------------Returning To Previous Menu--------------\n\n");
                    bookorder1();
                    m=1;//breaks while loop
                    break;

            case 2: printf("\e[1;1H\e[2J");/*Here I'm using regex to clear console screen*/
                    /* CHANGE STATUS TO RECEIVED */
                    statusfn(atoi(ch4),num);
                    printf("\n\n--------------You have Successfully Changed Current Status To RECEIVED--------------\n--------------Returning To Previous Menu--------------\n\n");
                    bookorder1();
                    m=1;//breaks while loop
                    break;

            case 3: printf("\e[1;1H\e[2J");/*Here I'm using regex to clear console screen*/
                    /* CHANGE STATUS TO CANCELLED */
                    statusfn(atoi(ch4),num);
                    printf("\n\n--------------You have Successfully Changed Current Status To CANCELLED--------------\n--------------Returning To Previous Menu--------------\n\n");
                    bookorder1();
                    m=1;
                    break;

            default: printf("\nPlease enter an valid Input : ");
                    scanf("%s",ch4);
                    continue;//takes control back to the starting of the while loop
            }}

                  k=1;
                  break;

          default: printf("\nPlease enter an valid Input : ");
          printf("\e[1;1H\e[2J");
                  bookorder1();
                  break;//takes control back to the starting of the while loop
          }}
}
/*order *bk_info(order *z)// declaring  a function of type order which returns a pointer
//this function takes in a string pointer as a paramter
{
        FILE *auth,*bookname,*quantity,*orderid,*status,*vendor,*genre; // declaring file pointer
        order *header,*point,*commit;
        int count,orderidcount;
        auth = fopen("authorodr.txt","r+");
        bookname = fopen("booknameodr.txt","r+");
        quantity = fopen("qtyodr.txt","r+");
        orderid = fopen("orderid.txt","r+");
        status = fopen("statusodr.txt","r+");
        vendor = fopen("vendorodr.txt","r+");
        genre = fopen("genreodr.txt","r+");
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
        //       | stat    |
        //         | vendor  |
        //              | next    | ---pointing to----> NULL
        //              ￣￣￣￣￣￣
        point = header; //assigning header address to point
        for(count =2;; count++) // count is keeping track of no. of nodes
        { commit = (order*)malloc(sizeof(order));
          if(commit == NULL)// if system is not able to allocate memory this condition keeps a check on that
          {
                  printf("memory can't be allocated please delete some memory");
                  break;
          }
          if (fgets(commit->bk_name,59,bookname) == NULL)// fgets reads a new line each time for every iteration of loop
          //and if the new line doesn't points to anything i.e. emptyline then is condition breaks the loop
          { free(commit); // done to avoid memory leak
      commit = NULL;    // to avoid dangling pointer problem
      break;    // breaking loop
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
          //           _______                ➚    _______                ➚   _______                ➚   _______
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
        return header;

}*/
void funcall1()
{
  printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        Library Management System\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t        -------------------------\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       ----------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       Book Order\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t       ----------\n\n\n\n");
        order *c;
        char *u;
        //printf("funcall1");
        u = (char*)malloc(50);
        c = (order*)malloc(sizeof(order));
        printf("\n Select one option :\n\n");
        printf("1. Through Vendors\n\n");
        printf("2. Request from other Libraries\n\n");
        printf("\n9. Previous Menu");
        printf("\t\t0. Main Menu\n\n->\t");
        char *cho;
        int inp=0;
        cho=(char*)malloc(10);
        scanf("%s",cho);
        inp=atoi(cho);
        if(inp==9)
        {
                system("clear");
                bookorder1();
        }
        else if (inp==0)
        {
                system("clear");
                mainMenu();// a function for LMS
        }
        else if(inp==1)
        {
                //system("clear");
                char *vuo;
                vuo=vendor();// a function to call vendors
                
        }
        else if(inp==2)
        {
               // system("clear");
                 char *vuo;
                vuo=libreq();//a function to call libraries
                strcpy(c->vndr,vuo);
        }
        else
        {
                printf("\nInvalid input, Please try agiain");
                int xD=0;
                while (xD<3) {
                        sleep(1);
                        printf(".");
                        xD++;
                }
        }
        u = strupp(c->vndr);
        strcpy(c->vndr,u);
        printf("Enter Author Name :\t");
        setvbuf(stdin, NULL, _IONBF, 0);
        fgets(c->au_name,40, stdin);
        u = strupp(c->au_name);
        strcpy(c->au_name,u);
        setvbuf(stdin, NULL, _IONBF, 0);
        printf("Enter Book Name :\t");
        setvbuf(stdin, NULL, _IONBF, 0);
        fgets(c->bk_name,50, stdin);
        u = strupp(c->bk_name);
        strcpy(c->bk_name,u);
        printf("Enter Quantity :\t");
        setvbuf(stdin, NULL, _IONBF, 0);
        fgets(c->qty,20, stdin);
        printf("Enter Genre :\t");
        setvbuf(stdin, NULL, _IONBF, 0);
        fgets(c->gen,20, stdin);
        u = strupp(c->gen);
        strcpy(c->gen,u);
        strcpy(c->stat,"PENDING");
        bookorder(c);// function takes in string pointer as parameter and returns the header which helps in access of the linked list
// this printf below is just for checking the code
// printf("%s",a->next->au_name);
        printf("\n-----------------------Thank You-----------------------\n");
        printf("-----------------------Returning Back To Previous Menu-----------------------\n");
}

order *loaddatabase1()// declaring  a function of type order which returns a pointer
//this function takes in a string pointer as a paramter
{
        FILE *auth,*bookname,*quantity,*orderid,*status,*vendor,*genre; // declaring file pointer
        order *header,*point,*commit;
        int count,orderidcount=0;
        auth = fopen("authorodr.txt","r+");
        bookname = fopen("booknameodr.txt","r+");
        quantity = fopen("qtyodr.txt","r+");
        orderid = fopen("orderid.txt","r+");
        status = fopen("statusodr.txt","r+");
        vendor = fopen("vendorodr.txt","r+");
        genre = fopen("genreodr.txt","r+");
        header = (order*) malloc(sizeof(order));//allocating dynamic memory of size of order structure
        if(header == NULL) //this checks if malloc is able to allocate  memory or not
        {
                printf("Unable to allocate memory.");
                exit(0);
        }
        // fgets(header->au_name,49,auth); //gets first line from files this "file pointers" are pointing to.
        // fgets(header->bk_name,59,bookname);//gets first line from files this "file pointers" are pointing to.
        // fgets(header->qty,29,quantity);//gets first line from files this "file pointers" are pointing to.
        // fscanf(orderid,"%d\n",&header->odrid);//gets first line from file orderid.txt as an integer
        // fgets(header->stat,29,status);//gets first line from files this "file pointers" are pointing to.
        // fgets(header->vndr,29,vendor);//gets first line from files this "file pointers" are pointing to.
        // fgets(header->gen,29,genre);//gets first line from files this "file pointers" are pointing to.
        // // this printf below is just for checking the code
        //  //printf("%s %s %s %d\n",header->au_name,header->bk_name,header->qty,header->odrid,header->stat);
        // header->next = NULL;
        //               header
        //               _________
        //              | au_name |
        //              | bk_name |
        //              | qty     |
        //              | odrid   |
        //       | stat    |
        //         | vendor  |
        //              | next    | ---pointing to----> NULL
        //              ￣￣￣￣￣￣
        point = header; //assigning header address to point
        for(count =2;; count++) // count is keeping track of no. of nodes
        { commit = (order*)malloc(sizeof(order));

          if(commit == NULL)// if system is not able to allocate memory this condition keeps a check on that
          {
                  printf("memory can't be allocated please delete some memory");
                  break;
          }
          if (fgets(commit->bk_name,59,bookname) == NULL)// fgets reads a new line each time for every iteration of loop
          //and if the new line doesn't points to anything i.e. emptyline then is condition breaks the loop
          { free(commit); // done to avoid memory leak
      commit = NULL;      // to avoid dangling pointer problem
      break;    // breaking loop
          }
          fgets(commit->au_name,49,auth);
          fgets(commit->qty,29,quantity);
          fscanf(orderid,"%d\n",&commit->odrid);
          fgets(commit->stat,29,status);
          fgets(commit->vndr,29,vendor);
          fgets(commit->gen,29,genre);
          orderidcount = commit->odrid;
          commit->next = NULL;
          // if(count == 2)
          // {
          //   orderidcount=0;
          // }
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
          //               _______                 ➚    _______
          //              |au_name|             ➚      | au_name |
          //              | title |          ➚         | title|
          //              | qty   |       ➚            | qty|
          //              | odrid |    ➚               | odrid|
          //              | next  | ➚                   | next | ---pointing to----> NULL
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
        fclose(auth);
        fclose(bookname);
        fclose(quantity);
        fclose(orderid);
        fclose(status);
        fclose(vendor);
        fclose(genre);

        return header;

}

void *booksearch1(char *z){
        char (*buk_arr)[100];
        char buff[50];
        char checkray[1000][6][100];
        buk_arr = z;

        order *a;
        order *temp;
        a = loaddatabase1();
        temp = a;
        int po=0;
        for(; temp != NULL; /*po++*/)
        {
                for(int i=0; **(buk_arr+i)!='\0'; i++)
                {
                        char *sr1;
                        sr1 = strstr(temp->stat,*(buk_arr+i));
                        if(sr1)
                        { sprintf(buff,"%d",temp->odrid);
                          strcpy(checkray[po][0],temp->au_name);
                          
                          strcpy(checkray[po][1],temp->bk_name);
                          strcpy(checkray[po][2],temp->gen);
                          strcpy(checkray[po][3],temp->qty);
                          strcpy(checkray[po][4],temp->vndr);
                          strcpy(checkray[po][5],buff);
                          po++;
                          break;}
                        else
                                continue;
                }

                temp = temp->next;
        }
        printf("no of matching results = %d  \n\n ",po);

        for(int cnt1=0; cnt1<po; cnt1++)
        {
                printf("    --------------------------------------------------------------------------------------------------------------------------------------\n");
                printf("%03d | Author Name      \t %s    | Book Name\t         %s    | Genre\t         %s    | Quantity      \t %s    | Vendor\t         %s    | Order Id\t         %s   \n",cnt1+1,checkray[cnt1][0],checkray[cnt1][1],checkray[cnt1][2],checkray[cnt1][3],checkray[cnt1][4],checkray[cnt1][5]);
                printf("     --------------------------------------------------------------------------------------------------------------------------------------\n");

        }
        return NULL;
}

void funcall2()
{
        char str[50]="PENDING";
        booksearch1(str);
        printf("\n\n-------------------------------------Returning To Previous Menu----------------------------\n\n");
}

void funcall3()
{
        char str1[50]="CANCELLED";
        booksearch1(str1);
        printf("\n\n-------------------------------------Returning To Previous Menu----------------------------\n\n");
}

void funcall4()
{
        char str[50]=" ";
        booksearchall(str);
        printf("\n\n-------------------------------------Returning To Previous Menu----------------------------\n\n");
}

void *booksearchall(char *z)
{
        char (*buk_arr)[100];
//char buff[50];
        char checkray[1000][6][100];
        buk_arr = z;
        order *a;
        order *temp;
        a = loaddatabase1();
        temp = a;
        int po=-1;
        for(; temp != NULL; /*po++*/)
        {
                for(int i=0; **(buk_arr+i)!='\0'; i++)
                {
                        char *sr1;
                        sr1 = strstr(temp->stat,*(buk_arr+i));
                        if(sr1==0)
                        { //itoa(temp->odrid,buff,10);
                                strcpy(checkray[po][0],temp->au_name);
                                
                                strcpy(checkray[po][1],temp->bk_name);
                                strcpy(checkray[po][2],temp->gen);
                                strcpy(checkray[po][3],temp->qty);
                                strcpy(checkray[po][4],temp->vndr);
                                strcpy(checkray[po][5],temp->stat);
                                //strcpy(checkray[po][5],buff);
                                po++;
                                break;
                        }
                        continue;
                }

                temp = temp->next;
        }
        printf("no of matching results = %d  \n\n ",po);

        for(int cnt1=0; cnt1<po; cnt1++)
        {
                printf("    --------------------------------------------------------------------------------------------------------------------------------------\n");
                printf("%03d | Author Name      \t %s    | Book Name\t         %s    | Genre\t         %s    | Quantity      \t %s    | Vendor\t         %s    | Status  \t         %s   ",cnt1+1,checkray[cnt1][0],checkray[cnt1][1],checkray[cnt1][2],checkray[cnt1][3],checkray[cnt1][4],checkray[cnt1][5]);
                printf(" --------------------------------------------------------------------------------------------------------------------------------------\n");

        }
        return NULL;
}

void *booksearchid(char *z){
        char (*buk_arr)[100];
        char buff[50];
        char checkray[1000][6][100];
        buk_arr = z;
// printf("%s",*(buk_arr+1));
        order *a;
        order *temp;
        a = loaddatabase1();
        temp = a;
        int po=0;
        for(; temp != NULL; /*po++*/)
        {
                for(int i=0; **(buk_arr+i)!='\0'; i++)
                {
                        char *sr1;
                        sprintf(buff,"%d",temp->odrid);
                        sr1 = strstr(buff,*(buk_arr+i));
                        if(sr1)
                        {
                                strcpy(checkray[po][0],temp->au_name);                        
                                strcpy(checkray[po][1],temp->bk_name);
                                strcpy(checkray[po][2],temp->gen);
                                strcpy(checkray[po][3],temp->qty);
                                strcpy(checkray[po][4],temp->vndr);
                                strcpy(checkray[po][5],temp->stat);
                                //strcpy(checkray[po][5],buff);
                                po++;
                                break;
                        }
                        else
                                continue;
                }
                temp = temp->next;
        }
        printf("no of matching results = %d  \n\n ",po);

        for(int cnt1=0; cnt1<po; cnt1++)
        {
                printf("    ---------------------------------------------------------------------------------------------------------------------------\n");
                printf("%03d | Author Name :\t %s    | Book Name :\t %s    | Genre :\t         %s    | Quantity :\t %s    | Vendor :\t         %s    | Status :\t         %s     ",cnt1+1,checkray[cnt1][0],checkray[cnt1][1],checkray[cnt1][2],checkray[cnt1][3],checkray[cnt1][4],checkray[cnt1][5]);
                printf("----------------------------------------------------------------------------------------------------------------------------\n");


        }
        return NULL;
}
void statusfn(int sta,int ordid)
{
        FILE *orderid;
        FILE *orderstatus;
        FILE *rep;
        char buff1[5];
        orderid=fopen("orderid.txt","r");
        orderstatus=fopen("statusodr.txt","r");
        int Nl = 0,var2=0,imp=0;
        char line[1024],input[255],cmp=9,ch;
        while( fgets(line,1023,orderid) != NULL)
        {
                Nl++;
        }
        rewind(orderid);
        fscanf(orderid,"%s",input);
        int input1=atoi(input);
        int temp=1;
        for(int z=0; z<Nl; z++)
        {

                if(input1==ordid)
                {
                        cmp=0;
                }

                if(cmp> 0 || cmp <0)
                {
                        cmp=9;
                }

                if(cmp==0)
                {
                        var2=z+1;
                        cmp=9;
                        imp++;
                }

                fscanf(orderid,"%s",input);
                input1=atoi(input);

        }
        rewind(orderid);
        switch (sta) {
        default:
                printf("The status is not changed");
                setvbuf(stdout, NULL, _IONBF, 0);
                for(int j=0; j<3; j++)
                {
                        sleep(1);
                        printf(".");
                }
                break;
        case 1:
                temp =1;
                rep = fopen("rep1.txt", "w");
                ch = getc(orderstatus);
                while (ch != EOF)
                {
                        if(temp != var2)
                                putc(ch, rep);
                        if(ch == '\n' && temp==var2) {
                                fputs("PENDING\n",rep);
                        }
                        if (ch == '\n') {
                                temp++;
                        }
                        ch = getc(orderstatus);
                }
                break;

        case 2:
                temp =1;
                rep = fopen("rep1.txt", "w");
                ch = getc(orderstatus);
                while (ch != EOF)
                {
                        if(temp != var2)
                                putc(ch, rep);
                        if(ch == '\n' && temp==var2) {
                                fputs("RECEIVED\n",rep);
                        }
                        if (ch == '\n') {
                                temp++;
                        }
                        ch = getc(orderstatus);
                }
                sprintf(buff1,"%d",ordid);
                bookaddinfo(buff1);
                break;
        case 3:
                temp =1;
                rep = fopen("rep1.txt", "w");
                ch = getc(orderstatus);
                while (ch != EOF)
                {
                        if(temp != var2)
                                putc(ch, rep);                        
                        if(ch == '\n' && temp==var2) {
                                fputs("CANCELLED\n",rep);
                        }
                        if (ch == '\n') {
                                temp++;                                
                        }
                        ch = getc(orderstatus);
                }
                break;
        }
        fclose(orderid);
        fclose(orderstatus);
        fclose(rep);
        remove("statusodr.txt");
        rename("rep1.txt","statusodr.txt");

}

void *bookaddinfo(char *z){
        char (*buk_arr)[100];
        char buff[50];
        char checkray[10][4][100];
        buk_arr = z;
        bklist1 *u;
        bklist1 *c;
        order *a;
        order *temp;
        a = loaddatabase1();
        temp = a;
        int po=0;
        for(; temp != NULL; /*po++*/)
        {
                for(int i=0; **(buk_arr+i)!='\0'; i++)
                {
                        char *sr1;
                        sprintf(buff,"%d",temp->odrid);
                        sr1 = strstr(buff,*(buk_arr+i));
                        if(sr1)
                        {
                                strcpy(checkray[po][0],temp->au_name);
                                strcpy(checkray[po][1],temp->bk_name);
                                strcpy(checkray[po][2],temp->gen);
                                strcpy(checkray[po][3],temp->qty);
                                po++;
                                break;
                        }
                        else
                                continue;
                }
                temp = temp->next;
        }
        c = (bklist1*)malloc(sizeof(bklist1));
        strcpy(c->auth,checkray[0][0]);
        strcpy(c->Title,checkray[0][1]);
        strcpy(c->Genre,checkray[0][2]);
        strcpy(c->qty,checkray[0][3]);
        u = addabook(c);
        /*printf("no of matching results = %d  \n\n ",po);

           for(int cnt1=0;cnt1<po;cnt1++)
           {
           printf("     --------------------------------------------------------------------------------------------------------------------------------------\n");
           printf("%03d | Author Name      \t %s    | Book Name\t         %s    | Genre\t         %s    | Quantity      \t %s    | Vendor\t         %s    | Status  \t         %s   ",cnt1+1,checkray[cnt1][0],checkray[cnt1][1],checkray[cnt1][2],checkray[cnt1][3],checkray[cnt1][4],checkray[cnt1][5]);
           printf(" --------------------------------------------------------------------------------------------------------------------------------------\n");


           }*/
        return NULL;
}

bklist1 *addabook(bklist1 *z)// declaring  a function of type bklist1 which returns a pointer
//this function takes in a string pointer as a paramter
{
        FILE *aut,*tit,*gen,*iss,*cnt; // declaring file pointer
        bklist1 *header,*point,*commit;
        int count,issre;
        aut = fopen("AUTHOR.txt","r+");
        tit = fopen("TITLE.txt","r+");
        gen = fopen("Genre.txt","r+");
        iss = fopen("issue_no.txt","r+");
        cnt = fopen("Count.txt","r+");
        header = (bklist1*) malloc(sizeof(bklist1));//allocating dynamic memory of size of bklist1 structure
        if(header == NULL) //this checks if malloc is able to allocate  memory or not
        {
                printf("Unable to allocate memory.");
                exit(0);
        }
        fgets(header->auth,49,aut); //gets first line from files this "file pointers" are pointing to.
        fgets(header->Title,59,tit);//gets first line from files this "file pointers" are pointing to.
        fgets(header->Genre,29,gen);//gets first line from files this "file pointers" are pointing to.
        fscanf(iss,"\n%d",&header->issue);//gets first line from file issue_no.txt as an integer
        fscanf(cnt,"\n%d",&header->count);
        // this printf below is just for checking the code
        // printf("%s %s %s %d\n",header->auth,header->Title,header->Genre,header->issue);
        header->next = NULL;
        //               header
        //               _______
        //              | auth |
        //              | title|
        //              | Genre|
        //              | issue|
        //              | next | ---pointing to----> NULL
        //              ￣￣￣￣
        point = header; //assigning header address to point
        for(count =2;; count++) // count is keeping track of no. of nodes
        { commit = (bklist1*)malloc(sizeof(bklist1));
          if(commit == NULL)// if system is not able to allocate memory this condition keeps a check on that
          {
                  printf("memory can't be allocated please delete some memory");
                  break;
          }
          if (fgets(commit->Title,59,tit) == NULL)// fgets reads a new line each time for every iteration of loop
          //and if the new line doesn't points to anything i.e. emptyline then is condition breaks the loop
          { free(commit); // done to avoid memory leak
      commit = NULL;    // to avoid dangling pointer problem
      break;    // breaking loop
          }
          fgets(commit->auth,49,aut);
          fgets(commit->Genre,29,gen);
          fscanf(iss,"%d\n",&commit->issue);
          fscanf(cnt,"%d\n",&commit->count);
          issre = commit->issue;
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

          point = point->next;//now in each iteration of loop point's adress is changed to where point->next is
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
        fprintf(aut,"%s\n",z->auth);
        fprintf(tit,"%s\n",z->Title);
        fprintf(gen,"%s\n",z->Genre);
        fprintf(iss,"%d\n",issre+1);
        fprintf(cnt,"%d\n",atoi(z->qty));
        fclose(aut);
        fclose(tit);
        fclose(gen);
        fclose(iss);
        fclose(cnt);
        return header;

}
void date_diff(char *idr)
 {
     FILE *dd;
     FILE *id;
     FILE *isno;
     FILE *title;
     FILE *author;
    char idi[50];
    int v=9,Nl=0,Ml=0,cmp1=9;
    strcpy(idi,idr);
        char line[255],input1[255],input2[255],input3[255],input4[255],input5[255];
        isno=fopen("IssuedBooks.txt","r");
        id=fopen("IssuedUserId.txt","r");
         title=fopen("TITLE.txt","r");
        author=fopen("AUTHOR.txt","r");
        dd=fopen("IssuedOnDate.txt","r");

  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  int day_diff, mon_diff, year_diff;
  char *datestring5;
  char *datestring6;
  datestring5=(char*)malloc(100);
  datestring6=(char*)malloc(100);
  strcpy(datestring6,datestring);
  //exit(0);
   while( fgets(line,1023,isno) != NULL)
        {
                Nl++;
        }
rewind(isno);

while( fgets(line,1023,title) != NULL)
        {
             Ml++;
        }
rewind(title);
  datestring6[strcspn(datestring6, "\n")] = '\0';
  char delim[4]="-";
  char *ptr = strtok(datestring6, delim);
  int daymax,monmax,yearmax;
	while(ptr != NULL)
	{
		daymax=atoi(ptr);
		ptr = strtok(NULL, delim);
            monmax=atoi(ptr);
		ptr = strtok(NULL, delim);
	        yearmax=atoi(ptr);
		ptr = strtok(NULL, delim);
	}



fscanf(id,"%s",input1);
            fscanf(isno,"%s",input2);
            fscanf(dd,"%s",datestring5);
 for(int z=0; z<Nl; z++)
        {


                cmp1=strcmp(input1,idi);

                if(cmp1> 0 || cmp1 <0)
                {
                        cmp1=9;
                }
                if(cmp1==0)
                {   int some=0;
                    while(some<atoi(input2))
                    {
                            fgets(input3,254,title);
                            fgets(input4,254, author);
                            input3[strcspn(input3, "\n")] = '\0';
                            input4[strcspn(input4, "\n")] = '\0';

                            some++;
                    }
                }


char *ptr1 = strtok(datestring5, delim);

  int daymin,monmin,yearmin;
	while(ptr1 != NULL)
	{
		daymin=atoi(ptr1);
		ptr1 = strtok(NULL, delim);
                monmin=atoi(ptr1);
		ptr1 = strtok(NULL, delim);
	        yearmin=atoi(ptr1);
		ptr1 = strtok(NULL, delim);
	}
if(daymax < daymin)
    {
        // borrow days from february
        if (monmax == 3)
        {
            //  check whether year is a leap year
            if ((yearmax % 4 == 0 && yearmax % 100 != 0) || (yearmax % 400 == 0))
            {
                daymax += 29;
            }

            else
            {
                daymax += 28;
            }
        }

        // borrow days from April or June or September or November
        else if (monmax == 5 || monmax == 7 || monmax == 10 || monmax == 12)
        {
           daymax += 30;
        }

        // borrow days from Jan or Mar or May or July or Aug or Oct or Dec
        else
        {
           daymax += 31;
        }

        monmax = monmax - 1;
    }

    if (monmax < monmin)
    {
        monmax += 12;
        yearmax -= 1;
    }

    day_diff = daymax - daymin;
    mon_diff = monmax - monmin;
    year_diff = yearmax - yearmin;

    int didd=year_diff*366+mon_diff*31+day_diff*1;

    if(didd>=15)
    {
        printf("-->\t\"%s\" by \"%s\" is overdue, Please return it immediately\n",input3,input4);
    }
         fscanf(id,"%s",input1);
            fscanf(isno,"%s",input2);
            fscanf(dd,"%s",datestring5);       }
 }
int main()
{
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  int day_diff, mon_diff, year_diff;
  datestring=(char*)malloc(100);
  sprintf(datestring,"%02d-%02d-%d",tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900);
  loadMembers();
  head=loaddatabase();
  mainMenu();
}
char* vendor()
{
        int input=0,Nl=0;
        char line[1024];
        char vendrname[50],*vendor_select;
        FILE *vendr;
        //int update;
        // a function to return the value of update;if update!=0, an alert loop will run showing list of all previous orders completed
        //loop
        printf("Order the book through :\n\n");
        vendr=fopen("vendor.txt","r");
        while( fgets(line,1023,vendr) != NULL)
        {
                Nl++;
        }
        rewind(vendr);
        for(int i=0; i<Nl; i++)
        {
                printf("%d. ",i+1);
                fgets(vendrname, 80, vendr);
                puts(vendrname);
        }
        printf("\n\n\n9. Previous Menu");
        printf("\t0. Main Menu\n\n");
        char *cho;
        cho=(char*)malloc(10);
        scanf("%s",cho);
        input=atoi(cho);
        fclose(vendr);
        if(input==9)
        {
                system("clear");
                bookorder1();
        }
        if(input==0)
        {
                system("clear");
                mainMenu();
        }
        if(input<=Nl)
        {
                vendr=fopen("vendor.txt","r");
                for(int i=0; i<input; i++)
                {
                        fgets(vendrname, 80, vendr);
                }
                vendor_select=vendrname;
        }
        else
        {
                printf("Not a valid input, Try Again");
                vendor();
        }
        return vendor_select;
}
char* libreq()
{
        int input=0,Nl=0;
        char line[1024];
        char vendrname[50],*vendor_select;
        FILE *vendr;
        //int update;
        // a function to return the value of update;if update!=0, an alert loop will run showing list of all previous orders completed
        //loop
        printf("Order the book through :\n\n");
        vendr=fopen("liblist.txt","r");
        while( fgets(line,1023,vendr) != NULL)
        {
                Nl++;
        }
        rewind(vendr);
        for(int i=0; i<Nl; i++)
        {
                printf("%d. ",i+1);
                fgets(vendrname, 80, vendr);
                puts(vendrname);
        }
        printf("\n\n\n9. Previous Menu");
        printf("\t0. Main Menu\n\n");
        char *cho;
        cho=(char*)malloc(10);
        scanf("%s",cho);
        input=atoi(cho);
        fclose(vendr);
        if(input==9)
        {
                system("clear");
                bookorder1();
        }
        if(input==0)
        {
                system("clear");
                mainMenu();
        }
        if(input<=Nl)
        {
                vendr=fopen("vendor.txt","r");
                for(int i=0; i<input; i++)
                {
                        fgets(vendrname, 80, vendr);
                }
                vendor_select=vendrname;
        }
        else
        {
                printf("Not a valid input, Try Again");
                libreq();
        }
        return vendor_select;
}
