#include "booksearch.h"
#include <stdbool.h>
void issueBook(char *);
void reserveBook(bklist *,char*);
void requestBook(char *);
bool loadCart(bklist *,char *);

struct cartbook
{
  int issue;
  char *id;
  struct cartbook *next;
};

bklist *head;
struct cartbook *headcb;

extern void studentPage(char *id)
{
  head=loaddatabase();
  headcb=(struct cartbook*)malloc(sizeof(struct cartbook));
  headcb->next=NULL;
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
  //  case 3: cart(headcb);break;
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
    if(w==1);// requestBook(id);
    else issueBook(id);
  }
  book=getBook(&b);
  if(book->count>0)
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
      fp=fopen("issuedBooks.txt","a");
      fprintf(fp,"%d\n",book->issue);
      fclose(fp);
      fp=fopen("issuedUserId.txt","a");
      fputs(id,fp);
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
  //  case 3: cart(headcb);flag=false;break;
    default:printf("Invalid \nTry Again\n");
  }
}
}
void reserveBook(bklist *book,char *id)
{
  FILE *fp;
  fp=fopen("reservedBooks.txt","a");
  fprintf(fp,"%d\n",book->issue);
  fclose(fp);
  fp=fopen("reservedUserId.txt","a");
  fputs(id,fp);
  fclose(fp);
  printf("The Book has been reserved for you\n");
  printf("It will be available in your cart for");
  printf(" >>>>three days<<<<< once it is back with us.\n");
  //Aayush would do the coding for three days.
  printf("ThankYou\n");
  exit(0);
}
bool loadCart(bklist *book,char *id)
{
  struct cartbook *current,*p;
  current=headcb->next;
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
void requestBook(char *c)
{
  char title[100],auname[100],genre[45];
  printf("Enter the full name of the book you want to request:\n");
  gets(title);
  printf("Enter the author's name of the book:\n");
  gets(auname);


}
