#include<stdio.h>
#include<stdlib.h>


typedef struct bklis{
  char auth[50];
  char Title[60];
  char Genre[30];
  int issue;
  struct bklis *next;
}bklist;//declared a structure of type bklist
bklist *addabook(bklist *z)// declaring  a function of type bklist which returns a pointer
//this function takes in a string pointer as a paramter
{
  FILE *aut,*tit,*gen,*iss; // declaring file pointer
  bklist *header,*point,*commit;
  int count,issre;
  aut = fopen("AUTHOR.txt","r+");
  tit = fopen("TITLE.txt","r+");
  gen = fopen("Genre.txt","r+");
  iss = fopen("issue_no.txt","r+");
  header = (bklist*) malloc(sizeof(bklist));//allocating dynamic memory of size of bklist structure
  if(header == NULL) //this checks if malloc is able to allocate  memory or not
   {
       printf("Unable to allocate memory.");
       exit(0);
   }
   fgets(header->auth,49,aut); //gets first line from files this "file pointers" are pointing to.
   fgets(header->Title,59,tit);//gets first line from files this "file pointers" are pointing to.
   fgets(header->Genre,29,gen);//gets first line from files this "file pointers" are pointing to.
   fscanf(iss,"%d\n",&header->issue);//gets first line from file issue_no.txt as an integer
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
  for(count =2;;count++) // count is keeping track of no. of nodes
  { commit = (bklist*)malloc(sizeof(bklist));
    if(commit == NULL)// if system is not able to allocate memory this condition keeps a check on that
       {
           printf("memory can't be allocated please delete some memory");
           break;
       }
       if (fgets(commit->Title,59,tit) == NULL)// fgets reads a new line each time for every iteration of loop
       //and if the new line doesn't points to anything i.e. emptyline then is condition breaks the loop
       { free(commit); // done to avoid memory leak
         commit = NULL; // to avoid dangling pointer problem
         break; // breaking loop
       }
    fgets(commit->auth,49,aut);
    fgets(commit->Genre,29,gen);
    fscanf(iss,"%d\n",&commit->issue);
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
  // this printf below is just for checking the code
  // printf("%s %s %s %d\n",z->auth,z->Title,z->Genre,issre+1);
  fclose(aut);
  fclose(tit);
  fclose(gen);
  fclose(iss);
  return header;

}
int main()
{
bklist *a;
bklist *c;
c = (bklist*)malloc(sizeof(bklist));
scanf("%s\n%s\n%s",c->auth,c->Title,c->Genre);
a = addabook(c);// function takes in string pointer as parameter and returns the header which helps in access of the linked list
// this printf below is just for checking the code
// printf("%s",a->next->auth);

}