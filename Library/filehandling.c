#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct cartbook
{
  int issue;
  char *id;
  struct cartbook *next;
}cartstruct;

struct cartbook *headrv;

void headrvLoader()
{
  FILE *fp1,*fp2;printf("1\n");
  struct cartbook *current,*prev,*p;printf("2\n");
  fp1=fopen("ReservedBooks.txt","r");printf("3\n");
  fp2=fopen("ReservedUserId.txt","r");printf("4\n");
  headrv=(struct cartbook*)malloc(sizeof(struct cartbook));printf("5\n");
  char *str;printf("6\n");
  current=(struct cartbook*)malloc(sizeof(struct cartbook));printf("7\n");
  headrv->next=current;printf("8\n");
  prev=headrv;printf("9\n");
  while(true)
  {
    if(fgets(current->id,50,fp2)==NULL)
    {
      current=NULL;
      prev->next=NULL;
    }
    printf("10\n");
    fgets(str,50,fp1);
    printf("11\n");
  //  str[strcspn(str,"\n")]='\0';
    printf("12\n");
    current->issue=atoi(str);printf("13\n");
    p=(struct cartbook*)malloc(sizeof(struct cartbook));printf("14\n");
    printf("15\n");
    current->next=p;printf("16\n");
    prev=current;printf("17\n");
    current=p;printf("18\n");
    free(p);printf("19\n");
  }
  printf("DONE");
  fclose(fp1);
  fclose(fp2);
  printf("DOOne");
}
int main()
{
  headrvLoader();
  printf("%d",headrv->next->next->issue);
  printf("%s",headrv->next->next->id);
}
