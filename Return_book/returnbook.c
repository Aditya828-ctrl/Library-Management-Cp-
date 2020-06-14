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

void returnbook(); //add a char id;
int main()
{
        returnbook(); //add a char id;
}
void returnbook() //add a char id;
{
        FILE *issuedid;
        FILE *issueno;
        FILE *issue;
        FILE *author;
        FILE *count;
        FILE *title;
        FILE *genre;
        printf("\t\t\t\t\t\t\t\t --------------\n");
        printf("\t\t\t\t\t\t\t\t Return Book(s)\n");
        printf("\t\t\t\t\t\t\t\t --------------\n\n\n\n");

        issueno=fopen("jkoi/issuedBooks.txt","r");
        issuedid=fopen("jkoi/issuedUserId.txt","r");
        issue=fopen("issue_no.txt","r");
        author=fopen("Author.txt","r");
        title=fopen("Title.txt","r");
        genre=fopen("Genre.txt","r");
        count=fopen("Count.txt","r");
        int Nl = 0,var2=-1;
        char line[1024],input[255],input1[50],input2[255],input3[255],input4[255],input5[255];
        char id[50];
        scanf("%s",id );
        //int v=strlen(id);
        // printf("<%s> <%d>\n",id,v );
        while( fgets(line,1023,issuedid) != NULL)
        {
                Nl++;
        }
        //printf("%d\n",Nl );
        // exit(0);

        rewind(issuedid);
        fscanf(issuedid,"%s", input);
        //  printf("<%s>", input);
        int cmp;
        //int i1=strlen(id);
        //  int i2=strlen(input);
        //printf("<%d> <%d>",v,i2);
        //printf("<%s>\n<%s>\n",input,id );
        int b,i=0,imp=0,var3;
        for(int z=0; z<Nl; z++)
        {
                cmp=strcmp(input,id);
                //printf("<%d>\n",cmp );
                if(cmp> 0 || cmp <0)
                {
                        cmp=9;
                }
                if(cmp==0)
                {
                        var2=z;
                        // printf(">>%d\t",var2);
                        cmp++;
                        imp++;
                }
                fscanf(issuedid,"%s", input);
        }
        printf("%d\n",imp );
        struct rebk bok[10];
        rewind(issuedid);
        fscanf(issuedid,"%s", input);
        for(int z=0; z<Nl; z++)
        {
                cmp=strcmp(input,id);
                //printf("<%d>\n",cmp );
                if(cmp> 0 || cmp <0)
                {
                        cmp=9;
                }
                if(cmp==0)
                {
                        var2=z;
                        //var3=var2;
                        // printf(">>%d\t",var2);
                        cmp++;
                        //imp++;
                        if(b==var2 || b<var2)
                        {

                                for(b=0; b<var2+1; b++)
                                {
                                        fscanf(issueno,"%s",input);
                                        // rewind(issue);
                                        // rewind(author);
                                        cmp=0;
                                }
                                b=0;
                                //printf("_%s_\t",input );
                                fscanf(issue,"%s",input1);
                                fgets(input2,254,author);
                                fgets(input3,254,title);
                                fgets(input4,254,genre);
                                fgets(input5,254,count);
                                //fgets(input6,254,issue);
                                //fscanf(issue,"%d",input6);
                                input2[strcspn(input2, "\n")] = '\0';
                                input3[strcspn(input3, "\n")] = '\0';
                                input4[strcspn(input4, "\n")] = '\0';
                                input5[strcspn(input5, "\n")] = '\0';
                                //input6[strcspn(input6, "\n")] = '\0';
                                //fscanf(author,"%[^\n]",input2);
                                int att=atoi(input);
                                //printf("{%d}\t",att );
                                //  exit(0);
                                for(int x=0; x<att; x++)
                                {
                                        //printf("#%s#\t",input1 );
                                        cmp=strcmp(input,input1);
                                        //  printf("<%d>\t",cmp );
                                        if(cmp> 0 || cmp <0)
                                        {
                                                cmp=9;
                                        }
                                        if(cmp==0)
                                        {
                                                var2=z;
                                                cmp++;
                                                //printf("+%s+\t",input1 );
                                                printf("--------------------------------------------------\n");
                                                printf("%02d.| Title : %s\n", i+1,input3);
                                                //bok[i].bkt=input3;
                                                bok[i].bkt = strdup(input3);
                                                //  printf("%s\n",input3 );
                                                printf("   | Author : %s\n", input2);
                                                //bok[i].bka=input2;
                                                bok[i].bka = strdup(input2);
                                                //printf("+%s+\t",input2 );
                                                printf("   | Genre : %s\n", input4);
                                                //bok[i].bkgnre=input4;
                                                bok[i].bkgnre = strdup(input4);
                                                //printf("+%s+\t",input4 );
                                                printf("   | Count : %s\n", input5);
                                                bok[i].bkcnt = strdup(input5);
                                                printf("   | Issue No : %s\n", input1);
                                                bok[i].issno = strdup(input1);
                                                bok[i].cc = var2;
                                                //bok[i].bkcnt=input5;
                                                printf("--------------------------------------------------\n\n");
                                                i=i+1;
                                                //printf("+%s+\n",input5 );
                                                break;
                                        }
                                        fscanf(issue,"%s", input1);

                                        fgets(input2,254,author);
                                        fgets(input3,254,title);
                                        fgets(input4,254,genre);
                                        fgets(input5,254,count);
                                        //fgets(input6,254,issue);
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
          exit(0);
        }
        printf("\n~%d~\n%d",imp,i );
        for(int z=0;z<i;z++)
        {
          printf("%d\n",z );
          printf("%s\n",bok[z].bkt );
          printf("%s\n",bok[z].bka );
          printf("%s\n",bok[z].bkgnre );
          printf("%s\n",bok[z].bkcnt );
          printf("%s\n",bok[z].issno );
          //printf("|%d|\n",bok[z].cc );
        }
        char *choose;
        printf("\n\nSelect one option:\t");
        choose = (char*)malloc(100);
        scanf("%s",choose);
        int choice=atoi(choose);

        for(int i=0; i<imp; i++)
        {
                if(choice==(i+1))
                {
                        printf("+++++" );

                        printf("%d\n",choice);
                        printf("%s\n",bok[choice-1].bkt );
                        printf("%s\n",bok[choice-1].bka );
                        printf("%s\n",bok[choice-1].bkgnre );
                        printf("%s\n",bok[choice-1].bkcnt );
                        printf("%s\n",bok[choice-1].issno );
                        printf("%d\n",bok[choice-1].cc );
                        rewind(count);
                        rewind(issue);
                        Nl=0;
                        while( fgets(line,1023,issue) != NULL)
                        {
                                Nl++;
                                //         sleep(1);
                        }
                        printf("%d ",Nl );

                        rewind(issue);
                        fscanf(issue,"%s", input);

                        for(int z=0; z<Nl; z++)
                        {
                                cmp=strcmp(input,bok[choice-1].issno);
                                printf("%d <%s> <%s>\n",cmp,input,bok[choice-1].issno);
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
                                // fgets(input,sizeof(input),studentid);
                                //input[strcspn(input, "\n")] = '\0';
                                // printf("%d\n",var2 );
                        }

                        break;//system("clear");
                        //acpt_decline(choice);

                }
                else if (strcmp(choose, "#") == 0)
                {
                        printf("~~~~" );
                        break;//pssrqst();
                }
                else if(i+1==imp)
                {
                        //printf("Enter a valid option:\t");
                        printf("Invalid option; Choose again ");
                        for(int j=0; j<3; j++)
                        {
                                sleep(1);
                                printf(".");
                        }
                        // system("clear");
                        //pssrqst();
                        // scanf("%s",choose);
                        // choice=atoi(choose);
                        //i=-1;
                }
        }
        //printf("%d\n",var3 );
        int temp=1;
        //FILE *rep2;
        int beta=atoi(bok[choice-1].bkcnt)+1;
        printf("<%d>\n",beta );
        //exit(0);
        // //sprintf(bok, "%s\n",stu->stu_npass);
        FILE *rep;
        rep = fopen("rep.txt", "w");
        char ch;
        ch = getc(count);
        while (ch != EOF)
        {
                if(temp != var2)
                putc(ch, rep);
                //printf("%c",ch );
               if(ch == '\n' && temp==var2) {
                //                 //fputs(stu->stu_npass,rep);
               fprintf(rep,"%d\n",beta);
                //printf("%d\n",beta);
                         }
                if (ch == '\n')
                        temp++;
                ch = getc(count);
        }
      //  printf("_________%d\n",var3 );
        rewind(issueno);
        temp=1;
        rep = fopen("jkoi/rep1.txt", "w");
        ch = getc(issueno);
        while (ch != EOF)
        {
                if(temp != bok[choice-1].cc+1)
                        putc(ch, rep);
                        //printf("%c",ch );
                if (ch == '\n'){
                        temp++;
                      //printf("\n");
                    }
                ch = getc(issueno);
        }

        temp=1;
        rewind(issuedid);
        rep = fopen("jkoi/rep2.txt", "w");
        ch = getc(issuedid);
        while (ch != EOF)
        {
                if(temp != bok[choice-1].cc+1)
                        putc(ch, rep);
                        //printf("%c",ch );
                if (ch == '\n'){
                        temp++;
                      //printf("\n");
                    }
                ch = getc(issuedid);
        }
      //  fclose(orgdob);
        fclose(rep);
      //  remove("ps_rqt/StudentDob.txt");
        //rename("ps_rqt/rep.txt","ps_rqt/StudentDob.txt");
        exit(0);
}
//void inccount()
