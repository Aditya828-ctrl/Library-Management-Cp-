#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

void alert();
int main()
{
        alert();
}
void alert()
{
        FILE *issueno;
        FILE *total;
        FILE *title;
        FILE *author;
        issueno=fopen("issue_no.txt","r");
        title=fopen("Title.txt","r");
        author=fopen("Author.txt","r");
        char line[1024];
        int input;
        char input1[255],input2[255];
        int Nl=0,i=0,j=0;
        while( fgets(line,1023,issueno) != NULL)
        {
                Nl++;
        }
        printf("%d\n",Nl );
        //total=fopen("total.txt","w");
        //fclose(total);
        total=fopen("total.txt","r+");
        fscanf(total,"%d",&input);
        printf("%d\n",input );
        //exit(0);

                if(input>Nl)
                {
                        for(i=0; i<Nl; i++)
                        {
                                fgets(input1,254,title);
                                fgets(input2,254,author);
                                input1[strcspn(input1, "\n")] = '\0';
                                input2[strcspn(input2, "\n")] = '\0';
                                //printf("<%s> <%s>\n",input1,input2 );
                        }
                        int sub=input-Nl;
                        printf("\n\n\t\t\t\t\t\t\t*********************************************************************************************************\n\n" );
                        for(i=0; i<sub; i++)
                        {
                                fgets(input1,254,title);
                                fgets(input2,254,author);
                                input1[strcspn(input1, "\n")] = '\0';
                                input2[strcspn(input2, "\n")] = '\0';
                                printf("\t\t\t\t\t\t\t|                                                                                                 \t|\n");
                                //printf("\t\t\t\t\t\t\t|                                                                                                 \t|\n");
                                printf("\t\t\t\t\t\t\t\t-->A book titled \"%s\" by author(s) \"%s\" is now AVAILABLE\n",input1,input2 );
                              //  printf("\t\t\t\t\t\t\t|                                                                                                 \t|\n");
                                printf("\t\t\t\t\t\t\t|                                                                                                 \t|\n");
                                //printf("<%s> <%s>\n",input1,input2 );

                        }
                        printf("\n\t\t\t\t\t\t\t*********************************************************************************************************\n\n" );
                }
                //printf("afe\n");
                rewind(total);
        fprintf(total, "%d",Nl );
}
