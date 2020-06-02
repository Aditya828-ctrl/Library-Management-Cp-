#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int check(char*,char*);
int user_verified(int);
int	staff_feature();
int user_n=1,nthuser;
typedef struct{
	int issue_no;
	char auth_name[25];
	char title[30];
}Book;
typedef struct{
	int user_no;
	char username[30];
	char pass[30];
}Login;
Login staff_login[100] = {1,"tanish","tanish4067"};


int check1(char *str_username,char *str_pass)
{
	int z = 0,t;
	for(int count = 0 ; count < user_n ; count++ )
	{
		// printf("%d %d\n",strcmp(str_username,staff_login[count].username),~strcmp(str_pass,staff_login[count].pass) );
		t = ((strcmp(str_username,staff_login[count].username) ) || (strcmp(str_pass,staff_login[count].pass)));
		if (t==0)
		{nthuser = count +1;}
		z+=t;
	}
	return z;
}

int user_verified(int result)
{	int count;
	for(count =0;;)
	{
		if (result == user_n-1)
		{
			printf("Welcome ");
			printf("%s",staff_login[user_n-1].username);
			count++;
			break;
		}
		else
		{
			printf("Sorry but the login details are invalid\n");
			printf("\nplease enter your login details again\n");
			break;
		}

	}
	return count;
	/* code */
}

int staff_feature()
{ int option;
	printf("select any one of the following action:\n(1)add a member\n (2)delete a member\n(3)add a book\n(4)delete a book\n(5)order a book\n(6)check status of a member");
	scanf("%d",&option);

	if (option == 1)
	{ int account_type;
		printf("what type of account do you want to create-\n(1)student or faculty\n(2)staff");
		scanf("%d",&account_type);
		if (account_type == 2)
		{
			printf("Enter a new username and password");
			scanf("\n%s  %s\n",staff_login[user_n].username,staff_login[user_n].pass);
			printf("Retype the new password");
			char temp[30];
			scanf("%s",temp);
			if (~(strcmp(staff_login[user_n].pass,temp)))
			{
				user_n++;
				printf("user added");
			}

		}
		else if (account_type == 1)
		{

		}
	}
}


int main()
{
	int i,check_result,z=0;
	Book b[100];
	Login check;
	/*array of book struct*/
	// Book *p = b;
	printf("welcome to library management portal");
	for (i = 0; i<=0 || i>=4;)
	{
		printf("what do you want to do? (please select any one of these)\n1)Issue by book\n2)Return a book\n3)for staff use\n\n");
	  printf("please select the serial no. of the operation that you want to do - ");
		scanf("%d",&i);
		if (i <= 0 || i>=4)
		{
			printf("\n*************please enter 1 or 2 or 3*************\n\n");
		}
		continue;
	}
	if (i == 1)
	{
		for (i = 0; i != 2 && i != 1;)
		{
			printf("\nhow do you want to search books:\n1)by Author\n2)by Issue no.\n3)by Title\n\nEnter the serial no of the opertion you want to perform - ");
			scanf("%d",&i);
			if (i != 2 && i != 1)
			{
					printf("\n*************please enter 1 or 2 or 3*************\n\n");
			}
			continue;
	  }
	}
	else if (i == 2)
	{

	}
	else if (i == 3)
	{ for(;z == 0;)
		{
			printf("Enter your username and password with a space in b/w-");
			scanf("%s \t %s",check.username,check.pass);
			// printf("Enter password\n");
			// scanf("%s ",check.pass);
			// printf("%s",)
		 	check_result = check1(check.username,check.pass);
			// printf("%d",check_result);
			z = user_verified(check_result);
		}
		if (z==1)
		{
			printf("\t\t\tuser number: %d ",nthuser);
			staff_feature();
		}

	}

	return 0;
}
