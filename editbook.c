#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct bklis{
  char auth[50];
  char Title[60];
  char Genre[30];
  int issue;
  int count;
  struct bklis *next;

}bklist;
bklist *loaddatabase();
int menucall(int max,char *str)
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

bklist booksearch(char *z){
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
 printf("no of matching results%d  \n\n ",po);
 printf(" serial no.\u2006\u2006\n");
 for(int cnt1=0;cnt1<po;cnt1++)
 {
   printf("     -------------------------------------------------------------------------------\n");
   printf("%03d | Author      \t %s    | Title\t         %s    | Genre\t         %s",cnt1+1,checkray[cnt1][0],checkray[cnt1][1],checkray[cnt1][2]);
   printf("     -------------------------------------------------------------------------------\n");

 }

printf("\n\nplease select any one of the following books -  ");

int sel;
sel = menucall(po,selected_bk);
strcpy(str_final.auth,checkray[sel-1][0]);
strcpy(str_final.Title,checkray[sel-1][1]);
strcpy(str_final.Genre,checkray[sel-1][2]);
return str_final;
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
   // //               header
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

bklist *editbook(bklist* z, int i)
{
//so a is the header pointer passed from the loaddatabase function and z is the book info to be deleted or added in the database,
// and i defines the operation you wanna perform with the book info you passed
bklist *temp; int str1,str2,str3;
bklist *prev;
bklist *a;
bklist *finedit;
int cnt5=1,issre;
a = loaddatabase();
temp = a->next;
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
      finedit = temp;
      break;
    }
    else if(i == 2)
    { cnt5 = 0;
      if(temp->count)
      {
      temp->count--;
      printf("\n %d \n\n\n\n\n\n\n",temp->count);
      finedit = temp;
      }
      if(temp->count == 0)
      {

      prev->next = temp->next;
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
  finedit = z;
}
// printf("%s  %d %d",temp->next->auth,temp->next->count,temp->next->issue);
return finedit;
}

int dumpfile();

int main(void)
{
 int oper;
 char str[50];
 bklist a,*returnedbook;
 bklist *b;
 printf("search for book you want to delete - ");
 gets(str);

 a = booksearch(strupr(str));
 printf(" %s %s %s",a.auth,a.Title,a.Genre);
 // scanf("%s %s %s",a.auth,a.Title,a.Genre);
 b = &a;
 printf("operation you want to perform");//1 for adding a book 2 for deleting a book
 scanf("%d",&oper);
 printf(" %s %s %s",b->auth,b->Title,b->Genre);
 returnedbook = editbook(b,oper);
 printf("\n %d  %d",returnedbook->issue,returnedbook->count);
 z = dumpfile();
}
