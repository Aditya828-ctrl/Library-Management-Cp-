#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void bk_order(); //this is decleration of order function
struct order
{
char bk_name[50];
char au_name[50],qty[5];
};/*this is decleration of order structure which is used to take input from user such as bk_name for 'book name', au_name for 'Author name' and qty for 'Quantity'*/

int main()
{
  int a=0,k=0;/*these variables 'a' and 'k' are used below to break the while loop if user input satisfies the condition*/ 
  char ch1[5],ch2[5];/*these variables 'ch1' and 'ch2' are used below to get input from the user, here string is used in place of integer as to avoid getting error by user entering invalid input*/ 
  printf("\n\n1. Place an Order for Requested Books\n");
  printf("2. View past orders\n");
  printf("3. Exit");
  printf("\n\nEnter one of the above : ");
  scanf("%s",ch1);
  while(k==0)/*Here this while loop is used just to make user enter a valid input,if by mistake he/she entered an invalid input */
    {
      switch(atoi(ch1))/*Here this atoi function is used as to convert user's string input to integer */
        {
          case 1:printf("\e[1;1H\e[2J");/*Here I'm using regex to clear console screen*/
          printf("\nPlease Select a Vendor From The List \n\n");
          printf("1. CHORARIA ENTERPRISE\n");
          printf("2. BANSAL TRADERS\n");
          printf("3. MITTAL BOOK STORE\n");
          printf("4. BITS PILANI LIBRARY\n");
          printf("5. AAYUSH BOOK STORE\n");
          printf("6. Exit\n");
          printf("\nEnter one of the above : ");
          scanf("%s",ch2);
          while(a==0)/*Here this while loop is used just to make user enter a valid input,if by mistake he/she entered an invalid input */
            {
              switch(atoi(ch2))/*Here this atoi function is used as to convert user's string input to integer */
                {
                  case 1:printf("\e[1;1H\e[2J");/*Here I'm using regex to clear console screen*/
	                printf("\nYou are placing an order with 'CHORARIA ENTERPRISE' \n\n");
      	          a=1;//breaks while loop
	                bk_order();
	                {//This block here is just used to append vendor info to the order info
	                  FILE *bo;
	                  bo=fopen("Bookorders.txt","a+");
	                  fputs("Vendor = CHORARIA ENTERPRISE",bo);
 	                  fputs("\n\n",bo);
	                  fclose(bo);
	                 }
                   break;

                  case 2:printf("\e[1;1H\e[2J");/*Here I'm using regex to clear console screen*/
	                printf("\nYou are placing an order with 'BANSAL TRADERS' \n\n");
      	          a=1;//breaks while loop
	                bk_order();
	                {//This block here is just used to append vendor info to the order info
	                  FILE *bo;
	                  bo=fopen("Bookorders.txt","a+");
	                  fputs("Vendor = BANSAL TRADERS",bo);
 	                  fputs("\n\n",bo);
	                  fclose(bo);
	                 }
                   break;

                  case 3:printf("\e[1;1H\e[2J");/*Here I'm using regex to clear console screen*/
	                printf("\nYou are placing an order with 'MITTAL BOOK STORE' \n\n");
      	          a=1;//breaks while loop
	                bk_order();
	                {//This block here is just used to append vendor info to the order info
	                FILE *bo;
	                bo=fopen("Bookorders.txt","a+");
	                fputs("Vendor = MITTAL BOOK STORE",bo);
 	                fputs("\n\n",bo);
	                fclose(bo);
	                }
                   break;

                  case 4:printf("\e[1;1H\e[2J");/*Here I'm using regex to clear console screen*/
	                printf("\nYou are placing an order with 'BITS PILANI LIBRARY' \n\n");
      	          a=1;//breaks while loop
	                bk_order();
	                {//This block here is just used to append vendor info to the order info
	                  FILE *bo;
	                  bo=fopen("Bookorders.txt","a+");
	                  fputs("Vendor = BITS PILANI LIBRARY",bo);
 	                  fputs("\n\n",bo);
	                  fclose(bo);
	                }
                  break;

                case 5:printf("\e[1;1H\e[2J");/*Here I'm using regex to clear console screen*/
	              printf("\nYou are placing an order with 'AAYUSH BOOK STORE' \n\n");
      	        a=1;//breaks while loop
              	bk_order();
	              {//This block here is just used to append vendor info to the order info
	              FILE *bo;
	              bo=fopen("Bookorders.txt","a+");
	              fputs("Vendor = AAYUSH BOOK STORE",bo);
 	              fputs("\n\n",bo);
	              fclose(bo);
	              }
                break;

                case 6:printf("\e[1;1H\e[2J");/*Here I'm using regex to clear console screen*/
	              exit(0);
      	        a=1;//breaks while loop
	              bk_order();
                break;

                default :printf("\nPlease enter an valid Input : ");
                scanf("%s",ch2);
                continue;//takes control back to the starting of the while loop
              }
          }
        k=1;//breaks while loop
        break;

        case 2:printf("\e[1;1H\e[2J");/*Here I'm using regex to clear console screen*/
	      {    	
	        FILE *fptr; 
          char filename[100]="Bookorders.txt", c;
	        fptr = fopen(filename, "r");  // Open file
	        c = fgetc(fptr); // Read contents from file 
	        while (c != EOF) 
	        { 
		        printf ("%c", c); 
		        c = fgetc(fptr); 
	        } 
          fclose(fptr); 
	      }
	      k=1;//breaks while loop
        break;

        case 3:printf("\e[1;1H\e[2J");/*Here I'm using regex to clear console screen*/
        exit(0);
        k=1;//breaks while loop
        
        default : printf("\nPlease enter an valid Input : ");
        scanf("%s",ch1);
	      continue;//takes control back to the starting of the while loop
      }
  }
return 0;
}

void bk_order()/*this function is used to make user enter Books information which are to be ordered*/  
{
  FILE *bo;
  struct order odr;
  //static int count=0;
  //printf("Order Id = %d",++count);
  printf("\nEnter Book Name: ");
  fgets(odr.bk_name,40, stdin);
  scanf("%[^\n]%*c",odr.bk_name);
  printf("\nEnter Author Name: ");
  fgets(odr.au_name,40, stdin);
  //scanf("%[^\n]%*c",odr.au_name);
  printf("\nEnter Quantity: ");
  fgets(odr.qty,4, stdin);
  bo=fopen("Bookorders.txt","a+");//file named Bookorders is created

 char s[40];
 //putw(count,bo);
 strcpy(s,"\nBook Name = ");
 strcat(s,odr.bk_name);
 fputs(s,bo);
 strcpy(s,"\nAuthor Name = ");
 strcat(s,odr.au_name);
 fputs(s,bo);
 strcpy(s,"Quantity = ");
 strcat(s,odr.qty);
 fputs(s,bo);
 printf("\e[1;1H\e[2J");/*Here I'm using regex to clear console screen*/
 printf("\n-----------------------You Have Successfully Placed an Order------------------\n-----------------------Your Order ID = ----------------------- \n-----------------------Thank You-----------------------\n"/*,count*/);
 fclose(bo);
}
