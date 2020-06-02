#include<stdio.h> //ummh from next line
#include<string.h>
char (*stringsplitter(char *z))[100] // function which returns char(*)[100]
{
  int jm,j,mnm=0,i=0,count =0 ;
  static char cf[100][100] = {0}; // declare a static 2D arr as it has to be returned back
  for (int i = 0; i < 100; i++)
{
  for(int hnm = 0; hnm<100; hnm++)
  {
    cf[i][hnm] = '\0'; //initialising array to be zero
  }

}
  for(jm=0;mnm == 0;jm++) // jm helps to change us rows in 2D array
  {
    for(j=0;count == 0;j++)// j helps in changing columns of 2D array
    {
      if (*(z+i) != '\0' )
      {
        cf[jm][j] = *(z+i); // if there is a string  passed to function then
        //this if helps to use it
        i++;
        if(*(z+i) == '\0') //checks if string is finishes or not
        {
            mnm++; //break first for loop
            count++;// break second loop
        }

      }
    else
      {
      scanf("%c",&cf[jm][j]); // takes input from stdin if empty array is passed and stores in 2D array
      }
      if (cf[jm][j] == ' ') // checks for spaces in input
      {
        cf[jm][j] = '\0'; // escape character at end of a word
        break;
      }
      if(cf[jm][j]=='\n') // terminates input
      {
        cf[jm][j] = '\0';// escape character to last array element before terminating
        mnm++; // helps in getting out from the first for loop
        break; // well, we know it
      }

    }
  }
return cf;//note: this is returning char pointer
}
int main(void)
{
  char (*z)[100],(*h)[100];
  char a[30]= "hello whats'up",b[1] = ""; //if string pointer like a is passed then
  //stringsplitter uses it to split
  //if you want stringsplitter to take stdin as input then, an empty initialised string like
  // b[1] = "" should be used.
  z = stringsplitter(a); //takes input from a and splits it to different rows of array
  // for example:stdin = hello how are you     output= (returns a pointer to array of type
  // char(*)[100])  first row of z = hello
  //                second row of z = how
  //                third row of z = are
  //                fourth row of z = you
  // this can verified by statement given below
  // if there exist multiple spaces in stdin then program converts them to '\0'
  // i.e. multiple spaces doesn't effect
  // NOTE::second time usage only allowed when first time use is completed as function uses
  // deferencing not copying
  for(int i = 0;i<25;i++)
 {
       printf("%s\t",*(z+i));
 }
 printf("\n");
  h = stringsplitter(b);//when B  is initialised to 0  program uses stdin for input
  for(int i = 0;i<25;i++)
{
      printf("%s\t",*(h+i));
}
}
