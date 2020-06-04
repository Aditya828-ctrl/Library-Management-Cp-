//a main menu needs to be added in every screen
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct b_detail{
    char *name;
    char *author;
    char *genre_b;
}b_detail;
  void option();//function to choose inventory options
  void adbook();//function to choose from where to add book
  void debook();//function to delete book
  void request();//function to process request
  void issued();//function to see issued books
  void vendor();//function to choose vendor
  void book_det(char *a);//function to add book details
//  void ammend(char *a,char b,char c);
  int main()
  {
    printf("\t\t\t\t\t\t\t\t ---------\n");
    printf("\t\t\t\t\t\t\t\t Inventory\n");
    printf("\t\t\t\t\t\t\t\t ---------\n\n\n");
    printf("\n Select one option :\n\n");
    printf("1. Add Book(s)\n\n");
    printf("2. Delete Book(s)\n\n");
    printf("3. Pending Request(s)\n\n");
    printf("4. Issued Book(s)\n\n");
    printf("\n9. Previous Menu");
    printf("\t0. Main Menu\n\n");
    option();
    return 0;
  }

void option()
{
  int a;
  scanf("%d",&a);
  switch(a)
  {
    default:
            printf("\nInvalid Option\n\nTry Again\n");
            option();
    case 1:
            system("cls");
            adbook();//printf("1\n");// function to call Add
            break;
    case 2:
            system("cls");
            debook();// printf("2\n");// function to call delete
            break;
    case 3:
            system("cls");
            request();// printf("3\n");// function to call request
            break;
    case 4:
            system("cls");
            issued();// printf("4\n");// function to call issue
            break;
    case 9:
            system("cls");
            //printf("5\n");// function to call previous
            break;
    case 0:
            system("cls");
            // printf("6\n");// function to call main
            break;
  }
}

void adbook()
{
  int inp;
  printf("\t\t\t\t\t\t\t\t -----------\n");
  printf("\t\t\t\t\t\t\t\t Add Book(s)\n");
  printf("\t\t\t\t\t\t\t\t -----------\n\n\n");
  printf("\n Select one option :\n\n");
  printf("1. Through Vendors\n\n");
  printf("2. Request from other Libraries\n\n");
  printf("\n9. Previous Menu");
  printf("\t0. Main Menu\n");
  scanf("%d",&inp);
  if(inp==9){
    system("cls");
    main();
  }
  else if (inp==0) {
    system("cls");
    // a function for LMS
  }
  else if(inp==1){
    system("cls");
     vendor();// a function to call vendors
  }
  else if(inp==2){
    system("cls");
    // a function to call libraries
  }
}

void debook()
{
  printf("\t\t\t\t\t\t\t\t -------------\n");
  printf("\t\t\t\t\t\t\t\t Delete Book(s)\n");
  printf("\t\t\t\t\t\t\t\t -------------\n\n\n");
}

void issued()
{
  printf("\t\t\t\t\t\t\t\t -------------\n");
  printf("\t\t\t\t\t\t\t\t Issued Book(s)\n");
  printf("\t\t\t\t\t\t\t\t -------------\n\n\n");
}

void request()
{
  printf("\t\t\t\t\t\t\t\t -----------------\n");
  printf("\t\t\t\t\t\t\t\t Pending Request(s)\n");
  printf("\t\t\t\t\t\t\t\t -----------------\n\n\n");
}

void vendor()
{
  int input;
  char vendrname[50],*vendor_select;
  FILE *vendr;
  //int update;
  // a function to return the value of update;if update!=0, an alert loop will run showing list of all previous orders completed
  //loop
  printf("\t\t\t\t\t\t\t\t -------\n");
  printf("\t\t\t\t\t\t\t\t Vendors\n");
  printf("\t\t\t\t\t\t\t\t -------\n\n\n");
  printf("Order the book through :\n\n");
vendr=fopen("vendor.txt","r");
  for(int i=0;i<8;i++)
  {
    printf("%d. ",i+1);
    fgets(vendrname , 80, vendr);
    puts(vendrname);
    }
    printf("\n\n\n9. Previous Menu");
    printf("\t0. Main Menu\n\n");
    scanf("%d",&input);
fclose(vendr);
if(input==9){
system("cls");
adbook();
}
if(input==1||2||3||4||5||6||7||8){
vendr=fopen("vendor.txt","r");
    for(int i=0;i<input;i++)
    {
      fgets(vendrname , 80, vendr);
      vendor_select=vendrname;
    }
    system("cls");
    book_det(vendor_select);//a function to add book details
  }
}
  void book_det(char *v)
  {
    int sel,copies;//a variable to tackle no of copies is added for future use
    char bname[50],bauthor[50],*gen,*genre[12]={
    "signal_processing",
    "data_science",
    "mathematics",
    "economics",
    "history",
    "science",
    "psychology",
    "fiction",
    "computer_science",
    "nonfiction",
    "philosophy",
    "comic"};
    printf("\t\t\t\t\t\t\t\t ------------\n");
    printf("\t\t\t\t\t\t\t\t Book Details\n");
    printf("\t\t\t\t\t\t\t\t ------------\n\n\n");
    printf("Enter details\n\n\n");
    printf("Name : ");
    fgets(bname,50,stdin);
    fgets(bname,50,stdin);
    printf("\nAuthor : \n");
    fgets(bauthor,50,stdin);
    printf("\nSelect Genre :\n");
    for(int i=0;i<12;i++){
      printf("%d. ",i+1);
      printf("%s\n",genre[i]);
    }
    printf("\n\n" );
    scanf("%d",&sel);
    gen=genre[sel-1];
    //printf("%s\n",gen );
    // b_detail record;
    // strcpy(record.name,b_name);
    // strcpy(record.author,b_author);
    // strcpy(record.genre,gen);
    //printf("%s %s %s",bname,bauthor,gen);
    FILE *gnr;
    gnr=fopen("Genre.txt","a");
    fputs(gen,gnr);
    FILE *nm;
    nm=fopen("Title.txt","a");
    fputs(bname,nm);
    FILE *autr;
    autr=fopen("Author.txt","a");
    fputs(bauthor,autr);
    fclose(gnr);
    fclose(nm);
    fclose(autr);
    printf("\nOrder successfully placed...\n" );
  }
