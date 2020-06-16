#include"booksearch.h"
#include<stdio.h>
#include<stdbool.h>

void issueBook(char *);
void reserveBook(bklist *,char*);
void requestBook(char *);
bool loadCart(bklist *,char *);
bool isReserved(bklist *book,char *id);
char* toUpperCase(char *s);

typedef struct cartbook
{
  int issue;
  char *id;
  struct cartbook *next;
}cartstruct;

typedef struct reqbook
{
  char *title;
  char *auname;
  char *id;
  struct reqbook *next;
}reqstruct;

bklist *head;
struct cartbook *headis;//Issue Books
struct cartbook *headrv;//Reserved Books
struct reqbook  *headrq;//Requested Books

cartstruct* headLoader2(char *file1,char *file2);
void cart(cartstruct *header);
void headLoader3(char *file1,char *file2,char *file3);
int dumpres(cartstruct* a);
void dumpreq();

extern void studentPage(char *id)
{
  head=loaddatabase();
  headis=(struct cartbook*)malloc(sizeof(struct cartbook));
  headis->next=NULL;printf("a");
  FILE *fp;
  fp=fopen("ReservedBooks.txt","w");
  headrv=headLoader2("ReservedUserId.txt","ReservedBooks.txt");printf("b");
  headLoader3("RequestedTitle.txt","RequestedAuName.txt","RequestedId.txt");
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
  p->id=id;
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
  p->id=id;
  return true;
}
void requestBook(char *id)
{
  char title[100],auname[100];
  printf("Enter the title of the book you want to order:\n ");
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
  }
  dumpreq();
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
void headLoader3(char* file1,char* file2,char* file3)
{
  FILE *fp1,*fp2,*fp3;
  fp1=fopen(file1,"r");
  fp2=fopen(file2,"r");
  fp3=fopen(file3,"r");
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
  fp1=fopen("tempTitle.txt","w");
  fp2=fopen("tempAuName.txt","w");
  fp3=fopen("tempId.txt","w");
  struct reqbook *current;
  current=headrq->next;
  while(current!=NULL)
  {
    fputs(current->title,fp1);
    fputs(current->auname,fp2);
    fputs(current->id,fp3);
    current=current->next;
  }
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);
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
//
//
//
//Tanish's code from now on...
//
//
//
//
//

cartstruct* headLoader2(char *file1, char *file2)//TANISH
{
   cartstruct *carthead, *temp, *commit;
  FILE *userid, *iss;
  userid = fopen(file1, "r+");
  iss = fopen(file2, "r+");
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
      break;
    }
printf("7");
  fscanf(iss, "%d\n", &commit->issue);printf("8");
    commit->next = NULL;printf("8");
    // printf("\n%s23\n  %d",commit->id, commit->issue);
    temp->next = commit;

  }

  fclose(userid);
  fclose(iss);
return carthead;

}
bklist *nth_link(bklist *head, int i);

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
  userid = fopen("file1.txt", "r+");
  iss = fopen("file2.txt", "r+");
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
