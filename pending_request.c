#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student
{
    char stu_fname[30];
    char stu_lname[40];
    char stu_id[30];
    char stu_npass[30];
    char stu_dob[30];
    char stu_orgdob[30];
}detail;

void acpt_decline(int a);
int main()
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

   fclose(id);
    id = fopen("ps_rqt/id.txt", "r+");

        //printf("%d",Nl);
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
            printf("   | New_Password: %s\n",stu->stu_npass);
            printf("   | DOB : %s\n",stu->stu_dob);
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
    for(int i=0;i<Nl;i++)
    {
        if(choice==(i+1))
        {
            system("clear");
            acpt_decline(choice);
            return 0;
        }
        else if (strcmp(choose, "#") == 0)
        {
            main();
        }
        else if(i+1==Nl)
        {
            printf("Enter a valid option:\t");
            scanf("%s",choose);
            choice=atoi(choose);
            i=-1;
        }

    }
    // printf("%s", choose);
    //     choice = atoi(choose);
    // else if(choice==0)
    // {
    //     int main();
    // }
    // else
    // printf("%d",choice);
    // //system("clear");
    // acpt_decline();
     }

void acpt_decline(int a)
{
  FILE *lname;
  FILE *id;
  FILE *n_pass;
  FILE *dob;
  FILE *rep;
  //FILE *orgdob;
  //orgdob = fopen("ps_rqt/orgdob.txt","r");
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
      //fscanf(orgdob,"%s",stu->stu_orgdob);

  }
    fclose(lname);
    fclose(dob);
    fclose(n_pass);
    fclose(id);

      printf("--------------------------------------------------\n");
      printf("%d. | Name : ", i);
      fputs(stu->stu_lname, stdout);
      printf("   | UserID : %s\n", stu->stu_id);
      printf("   | New_Password: %s\n", stu->stu_npass);
      printf("   | DOB : %s\t\t\tOriginal_DOB:\n", stu->stu_dob);
      printf("--------------------------------------------------\n\n\n");
      printf("1. Accept\t\t\t2. Decline\n\n");
      char *chopt;
      chopt = (char *)malloc(sizeof(char));
      int opt;
    printf("Enter valid option:\t");
      scanf("%s",chopt);
    opt=atoi(chopt);
    //  orgdob = fopen("ps_rqt/orgdob.txt","r");
      //rep = fopen("ps_rqt/rep.txt", "w+");
      if(opt==0){
          system("clear");
          acpt_decline(a);
      }

      lname = fopen("ps_rqt/lname.txt", "r");
      id = fopen("ps_rqt/id.txt", "r");
      n_pass = fopen("ps_rqt/n_pass.txt", "r");
      dob = fopen("ps_rqt/dob.txt", "r");

     if (opt==1)
      {
  ch = getc(lname);

  while (ch != EOF)
  {
      if (ch == '\n')
          temp++;
      //except the line to be deleted
      if(delete_line==1)
      {
      if (temp == 2 && ch == '\n') //making sure to skip a blank line if delete_line=1
          ch = getc(lname);
        }
      if (temp != delete_line)
          putc(ch, rep);

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
      if (ch == '\n')
          temp++;
      //except the line to be deleted
      if(delete_line==1)
      {
      if (temp == 2 && ch == '\n') //making sure to skip a blank line if delete_line=1
          ch = getc(lname);
        }
      if (temp != delete_line)
          putc(ch, rep);

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
      if (ch == '\n')
          temp++;
      //except the line to be deleted
      if(delete_line==1)
      {
      if (temp == 2 && ch == '\n') //making sure to skip a blank line if delete_line=1
          ch = getc(lname);
        }
      if (temp != delete_line)
          putc(ch, rep);

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
      if (ch == '\n')
          temp++;
      //except the line to be deleted
      if(delete_line==1)
      {
      if (temp == 2 && ch == '\n') //making sure to skip a blank line if delete_line=1
          ch = getc(lname);
        }
      if (temp != delete_line)
          putc(ch, rep);

      ch = getc(n_pass);
  }
  fclose(n_pass);
  fclose(rep);
  remove("ps_rqt/n_pass.txt");
  rename("ps_rqt/rep.txt","ps_rqt/n_pass.txt");

}

}
