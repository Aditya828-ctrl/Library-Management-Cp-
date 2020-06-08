/*
 * C Program Delete a specific Line from a Text File
 */
#include <stdio.h>

int main()
{
    FILE *lname;                                   //initiating file pointers
    FILE *id;
    FILE *n_pass;
    FILE *dob;
    FILE *rep;
    //FILE *orgdob;                               //original dob file to be linked
    //orgdob = fopen("ps_rqt/orgdob.txt","r");
    rep = fopen("ps_rqt/rep.txt", "w+");
    lname = fopen("ps_rqt/lname.txt", "r");
    id = fopen("ps_rqt/id.txt", "r");
    n_pass = fopen("ps_rqt/n_pass.txt", "r");
    dob = fopen("ps_rqt/dob.txt", "r");

    detail *stu;
    stu = (detail *)malloc(sizeof(detail));     //initiating a struct data pointer and allocating memory to it

    char ch;
    int delete_line = a, temp = 1;              //initiating a char and a delete_line int while takes a value from other funtion to specify the line to be skipped

    printf("\t\t\t\t\t\t\t\t ------------------------\n");
    printf("\t\t\t\t\t\t\t\t Password Reset Request(s)\n");
    printf("\t\t\t\t\t\t\t\t ------------------------\n\n\n\n");
    int i;
    for (i = 0; i < a; i++)
    {

        fgets(stu->stu_lname, 39, lname);
        fscanf(id, "%s", stu->stu_id);                      //taking respective values
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
    chopt = (char *)malloc(sizeof(char));           //making sure that the input is valid
    int opt;
    printf("Enter valid option:\t");
    scanf("%s", chopt);
    opt = atoi(chopt);
    //  orgdob = fopen("ps_rqt/orgdob.txt","r");
    //rep = fopen("ps_rqt/rep.txt", "w+");
    if (opt == 0)
    {
        system("clear");
        acpt_decline(a);
    }

    lname = fopen("ps_rqt/lname.txt", "r");
    id = fopen("ps_rqt/id.txt", "r");
    n_pass = fopen("ps_rqt/n_pass.txt", "r");
    dob = fopen("ps_rqt/dob.txt", "r");

    if (opt == 1)
    {
        ch = getc(lname);

        while (ch != EOF)
        {
            if (ch == '\n')
                temp++;
                                                                //except the line to be deleted
            if (delete_line == 1) //making sure to skip a blank line if delete_line=1
            {
                if (temp == 2 && ch == '\n') 
                    ch = getc(lname);
            }
            if (temp != delete_line)
                putc(ch, rep);

            ch = getc(lname);
        }
        fclose(lname);
        fclose(rep);
        remove("ps_rqt/lname.txt");
        rename("ps_rqt/rep.txt", "ps_rqt/lname.txt");

        temp = 1;
        rep = fopen("ps_rqt/rep.txt", "w+");
        ch = getc(id);
        while (ch != EOF)
        {
            if (ch == '\n')
                temp++;
            //except the line to be deleted
            if (delete_line == 1)
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
        rename("ps_rqt/rep.txt", "ps_rqt/id.txt");

        temp = 1;
        rep = fopen("ps_rqt/rep.txt", "w");
        ch = getc(dob);
        while (ch != EOF)
        {
            if (ch == '\n')
                temp++;
            //except the line to be deleted
            if (delete_line == 1)
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
        rename("ps_rqt/rep.txt", "ps_rqt/dob.txt");

        temp = 1;
        rep = fopen("ps_rqt/rep.txt", "w");
        ch = getc(n_pass);
        while (ch != EOF)
        {
            if (ch == '\n')
                temp++;
            //except the line to be deleted
            if (delete_line == 1)
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
        rename("ps_rqt/rep.txt", "ps_rqt/n_pass.txt");
    }
