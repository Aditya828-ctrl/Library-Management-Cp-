#include <stdio.h>
#include <stdlib.h>

struct order
{
char bk_name[30];
char au_name[30];
int qty;
int editn;
};
int main()
{
  int j=0,i=0;
  printf("\n\n1. Place an Order for Requested Books\n");
  printf("2. View past orders\n");
  printf("3. Exit");
  printf("\n\nEnter one of the above : ");
  scanf("%d",&j);
conti:
  switch(j)
{
  case 1:
  printf("\nPlease Select a Vendor From The List \n\n");
  printf("1. CHORARIA ENTERPRISE\n");
  printf("2. BANSAL TRADERS\n");
  printf("3. MITTAL BOOK STORE\n");
  printf("4. BITS PILANI LIBRARY\n");
  printf("5. AAYUSH BOOK STORE\n");
  printf("6. Exit\n");
  printf("\nEnter one of the above : ");
  scanf("%d",&i);

  repeat:
    switch(i)
{
    case 1:printf("\nYou are placing an order with CHORARIA ENTERPRISE \n\n");

break;

    case 2:printf("\nYou are placing an order with BANSAL TRADERS \n\n");

break;

    case 3:printf("\nYou are placing an order with MITTAL BOOK STORE \n\n");

break;

    case 4:printf("\nYou are placing an order with BITS PILANI LIBRARY \n\n");

break;

    case 5:printf("\nYou are placing an order with AAYUSH BOOK STORE \n\n");

break;

    case 6:exit(0);

break;

    default :printf("\nPlease enter an valid Input : ");
    scanf("%d",&i);
    goto repeat;
}
break;

  case 2:

break;

  case 3:exit(0);

  default : printf("\nPlease enter an valid Input : ");
  scanf("%d",&j);
  goto conti;
}
return 0;
}
