#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
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
     printf("please write a digit which is greater than > 0 - ");
   }

  }
  int sel;
  sel = atoi(str);
  return sel;
}
