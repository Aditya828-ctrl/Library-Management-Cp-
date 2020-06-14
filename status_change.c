#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
void statusfn(int sta,int ordid);
int main()
{
        int a=2,b=5;
        statusfn(a,b);
}

void statusfn(int sta,int ordid)
{
        FILE *orderid;
        FILE *orderstatus;
        FILE *rep;
        orderid=fopen("orderid.txt","r");
        orderstatus=fopen("status.txt","r");
        int Nl = 0,var2=0,imp=0;
        char line[1024],input[255],cmp=9,ch;
        while( fgets(line,1023,orderid) != NULL)
        {
                Nl++;
        }
        printf("%d\n",Nl );
        rewind(orderid);
        fscanf(orderid,"%s",input);
        int input1=atoi(input);
        printf("%d\n",input1);
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
                        //printf(">>%d\t",var2);
                        cmp=9;
                        imp++;
                }

                printf("%d: ",input1);
                printf("<%d>_<%d>\n",cmp,var2);
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
                printf("jg\n" );
                temp =1;
                rep = fopen("rep1.txt", "w");
                ch = getc(orderstatus);
                while (ch != EOF)
                {
                        if(temp != var2)
                                putc(ch, rep);
                        //printf("%c",ch );
                        if(ch == '\n' && temp==var2) {
                                fputs("PENDING\n",rep);
                                //fprintf(rep,"%d\n",beta);
                                //printf("PENDING\n");
                        }
                        if (ch == '\n') {
                                temp++;
                                //printf("\n");
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
                        //printf("%c",ch );
                        if(ch == '\n' && temp==var2) {
                                fputs("RECEIVED\n",rep);
                                //fprintf(rep,"%d\n",beta);
                                //printf("PENDING\n");
                        }
                        if (ch == '\n') {
                                temp++;
                                //printf("\n");
                        }
                        ch = getc(orderstatus);
                }
                break;

        case 3:
                temp =1;
                rep = fopen("rep1.txt", "w");
                ch = getc(orderstatus);
                while (ch != EOF)
                {
                        if(temp != var2)
                                putc(ch, rep);
                        //printf("%c",ch );
                        if(ch == '\n' && temp==var2) {
                                fputs("CANCELLED\n",rep);
                                //fprintf(rep,"%d\n",beta);
                                //printf("PENDING\n");
                        }
                        if (ch == '\n') {
                                temp++;
                                //printf("\n");
                        }
                        ch = getc(orderstatus);
                }
                break;
        }
fclose(orderid);
fclose(orderstatus);
fclose(rep);
remove("status.txt");
rename("rep1.txt","status.txt");

}
