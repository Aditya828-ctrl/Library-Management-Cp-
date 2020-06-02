#include<stdio.h>
char (*stringsplitter(void))[100]
{
  int jm,j,mnm=0;
  static char cf[100][100];
  for(jm=0;mnm == 0;jm++)
  {
    for(j=0;;j++)
    {
      scanf("%c",&cf[jm][j]);
      if (cf[jm][j] == ' ')
      {
        cf[jm][j] = '\0';
        break;
      }
      if(cf[jm][j]=='\n')
      {
        cf[jm][j] = '\0';
        mnm++;
        break;
      }

    }
  }
return cf;
}
int main()
{
  char (*z)[100];
  z = stringsplitter();
  for(int i = 0;i<25;i++)
 {
       printf("%s\n",*(z+i));
 }
}
