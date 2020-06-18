#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct tr{
  char dest[20];
  int count;
  char tr_name[30];
  char tr_no[20];
  int cost;
  int ac_cost;
  int ac_count;
  char dep_time[20];
  char arr_time[20];
  struct tr *next;
}train;

struct car{
  train *tr;
  int i;
};

typedef struct user{
  train *a;
  char name[40];
  int pin;
  int PNR;
  struct user *next;
}usr;

char *strupp(char *z)
{   char *m;
    for(int i=0;*(z+i)!='\0';i++)
    {
        *(z + i) = toupper(*(z+i));

    }
    return z;
}

train * loadtrain()
{
FILE *train_dest, *train_count, *train_tr_name, *train_tr_no, *train_cost;
FILE *train_dep_time, *train_arr_time, *train_ac_cost, *train_ac_count;
train *header, *trans, *loader;
train_dest = fopen("Traindes.txt", "r+");
train_count = fopen("Seatcount.txt", "r+");
train_tr_no = fopen("Trainno.txt", "r+");
train_tr_name = fopen("Trainname.txt", "r+");
train_cost = fopen("Seatcost.txt", "r+");
train_dep_time = fopen("Deptime.txt", "r+");
train_arr_time = fopen("Arrtime.txt", "r+");
train_ac_count = fopen("AC_count.txt", "r+");
train_ac_cost = fopen("AC_cost.txt", "r+");

header = (train*)malloc(sizeof(train));

for(trans = header;;trans = trans->next )
{
  loader = (train*)malloc(sizeof(train));
  if(loader == NULL)
  {
    printf("data not available");
    exit(0);
  }
  if(fgets(loader->dest,19,train_dest) == NULL)
  {
    break;
  }
  fgets(loader->tr_name,29,train_tr_name);
  fgets(loader->dep_time,20,train_dep_time);
  fgets(loader->arr_time,20,train_arr_time);
  fgets(loader->tr_no,20,train_tr_no);
  fscanf(train_cost,"%d\n", &loader->cost);
  fscanf(train_count,"%d\n",&loader->count);
  fscanf(train_ac_cost,"%d\n", &loader->ac_cost);
  fscanf(train_ac_count,"%d\n", &loader->ac_count);
  loader->next = NULL;

  trans->next = loader;
}


return header;

}
usr * loaduserlist()
{
FILE *user, *pin, *pnr;
user = fopen("username.txt", "r+");
pin  = fopen("pin.txt", "r+");
pnr = fopen("PNR.txt","r+");
usr *header, *trans, *loader;
header = (usr*)malloc(sizeof(usr));
int cnt;
for(trans = header, cnt =0;;trans = trans->next )
{
  loader = (usr*)malloc(sizeof(usr));
  if(loader == NULL)
  {
    printf("data not available");
    exit(0);
  }
  if(fgets(loader->name,39,user) == NULL)
  {
    // loader->name[strlen(loader->name)] = '\n';
    break;
  }

  if(loader->name[strcspn(loader->name, "\n")+1] == '\n')
  {loader->name[strcspn(loader->name, "\n")+1] = '\0';}
  //printf("\nhi");
  //puts(loader->name);
  //printf("hi\n");
  fscanf(pin,"%d\n", &loader->pin);
  // fscanf(pnr,"%d\n",&loader->PNR);

  loader->next = NULL;

  trans->next = loader;
  cnt++;
}
fclose(user);
fclose(pin);
fclose(pnr);
printf("\nhi");
return header;

}
int checkexistence(char *z)
{
  usr *header,*trans;
  header = loaduserlist();
  for(trans = header->next;trans!=NULL;trans = trans->next)
  {
    if (!strcmp(trans->name,z))
    {
      return 1;
    }
    else{
      continue;
  }
}
return 0;
}
int checkexistence1(int z,char *s)
{
  usr *header,*trans;
  header = loaduserlist();
  for(trans = header->next;trans!=NULL;trans = trans->next)
  {
    if (trans->pin == z&&(strcmp(s,trans->name)==0))
    {
      return 1;
    }
    else{
      continue;
  }
  return 0;
}
}

void dumpdatabase(train* a)
{
train  *temp; int cont;
FILE *train_dest, *train_count, *train_tr_name, *train_tr_no, *train_cost, *train_dep_time, *train_arr_time, *train_ac_cost, *train_ac_count;
train_dest = fopen("Traindes1.txt", "w+");
train_count = fopen("Seatcount1.txt", "w+");
train_tr_no = fopen("Trainno1.txt", "w+");
train_tr_name = fopen("Trainname1.txt", "w+");
train_cost = fopen("Seatcost1.txt", "w+");
train_dep_time = fopen("Deptime1.txt", "w+");
train_arr_time = fopen("Arrtime1.txt", "w+");
train_ac_count = fopen("AC_count1.txt", "w+");
train_ac_cost = fopen("AC_cost1.txt", "w+");

for(temp = a->next, cont=0;;temp = temp->next)
{ fputs(temp->dest,train_dest);
  fputs(temp->tr_name,train_tr_name);
  fputs(temp->dep_time,train_dep_time);
  fputs(temp->arr_time,train_arr_time);
  fputs(temp->tr_no,train_tr_no);
  fprintf(train_cost,"%d\n", temp->cost);
  fprintf(train_count,"%d\n",temp->count);
  fprintf(train_ac_cost,"%d\n", temp->ac_cost);
  fprintf(train_ac_count,"%d\n", temp->ac_count);

  cont++;

  if(temp->next == NULL)
  {
    break;
  }

}
fclose(train_dest);
fclose(train_count);
fclose(train_tr_no);
fclose(train_tr_name);
fclose(train_cost);
fclose(train_ac_cost);
fclose(train_ac_count);
fclose(train_dep_time);
fclose(train_arr_time);

}


struct car print(char*dest, int para, int nth)
{ train *header, *trans;
  int cnt=1;
  struct car cart;
  header = loadtrain();
for(trans = header->next;trans != NULL;trans = trans->next)
{if(!strcmp(trans->dest,dest))
  { cnt++;
  if(para ==1)
  {

    printf("\n%d)   Train name:  %s     Train destination:  %s     Train Arrival time:  %s     Train departure time:  %s     Train number:  %s     Seats Available in NON-AC coach:  %d\n     Cost(in rupees) of NON-AC:  %d\n     Seats Available in AC coach:  %d\n     Cost(in rupees) of AC:  %d\n\n", cnt-1,trans->tr_name, trans->dest, trans->arr_time, trans->dep_time, trans->tr_no, trans->count, trans->cost, trans->ac_count, trans->ac_cost);
  }
  else if(para == 2)
  {
    if(cnt-1 == nth)
    {
      cart.tr = trans;
      break;
    }
  }
  else if(para == 3)
  {
    if(cnt-1 == nth)
    { trans->ac_count--;
      cart.tr = trans;
      break;
    }
  }
  else if(para == 4)
  {
    if(cnt-1 == nth)
    { trans->count--;
      cart.tr = trans;
      break;
    }
  }
  else if(para == 5)
  {
    if(cnt-1 == nth)
    { trans->ac_count++;
      cart.tr = trans;
      break;
    }
  }
  else if(para == 6)
  {
    if(cnt-1 == nth)
    { trans->count++;
      cart.tr = trans;
      break;
    }
  }
  else
  continue;
}
else
continue;
}
dumpdatabase(header);
cart.i = cnt-1;
return cart;
} // if para is 0 then my function in not going to print but if para is 1 then it will print for sure

int yourticket(usr *ab, int m)
{
  FILE *Ticket;
  char z[] = ".txt",nam[40],trn[40],no[4];
  strcpy(nam,ab->name);
  strcpy(trn,ab->a->tr_name);
  int i = ab->a->count + ab->a->ac_count;
  nam[strcspn(nam, "\n")] = '\0';
  trn[strcspn(trn, "\n")] = '\0';
  strcat(nam,trn);
  sprintf(no,"%d",i);
  strcat(nam,no);
  strcat(nam,z);
  char loc[] = "Tickets/";
  strcat(loc,nam);
  Ticket = fopen(loc,"w+");
  fprintf(Ticket, "Name of passenger:  %s\n",ab->name);
  fprintf(Ticket,"Train booked:  %s",ab->a->tr_name);
  fprintf(Ticket,"Train number: %s",ab->a->tr_no);
  fprintf(Ticket,"Train arrival time: %s",ab->a->arr_time);
  fprintf(Ticket,"train departure time: %s", ab->a->dep_time);
  if (m==1){
    fprintf(Ticket,"Ticket cost: %d\n",ab->a->ac_cost);
  }
  else
  {
    fprintf(Ticket,"Ticket cost: %d\n",ab->a->cost);
  }
  fprintf(Ticket, "Seat no. booked :   %d\n",(ab->a->cost+ab->a->ac_cost+atoi(ab->a->tr_no)+ab->pin)/513);
fclose(Ticket);
return 1;
}

void dumpuserlist(usr *headern)
{
  FILE *user, *pin, *pnr;
  user = fopen("username1.txt", "w+");
  pin  = fopen("pin1.txt", "w+");
  pnr = fopen("PNR1.txt", "w+");
 usr *temp;
 for(temp = headern->next;temp != NULL;temp = temp->next)
 {
   fputs(temp->name, user);
   fprintf(pin,"%d\n",temp->pin);
   fprintf(pnr,"%d\n", temp->PNR);
 }
 fclose(user);
 fclose(pin);
 fclose(pnr);
}
int main()//destsearch()
{ train *header, *trans, *header2, *trans2, *loader;
  header = loadtrain();
  char input[20];
  char *inpupp;
  char s[] = "Sorry, but no result found";
  printf("Hi USER, please enter the destination you want to go\n");
  scanf("%s",input);
  // this for loop is helping us in making a linked list which contain the data for different destinations
  header2 = (train*)malloc(sizeof(train));

  for(trans = header->next, trans2 = header2;trans != NULL;trans = trans->next)
  { inpupp = strupp(input);

    inpupp = strstr(trans->dest, inpupp);

    if(inpupp != NULL) // if input = mum then strupp
    // (input) = MUM and strstr will return common string from MUM and trans->dest
    // and then strlen willl count the no. of characters in string returned by
    // strstr in this case it is 3 (MUM)
    {
      if(strcmp(trans->dest, s)) //there is a constraint that all the destination should be written out together
      {
        strcpy(s, trans->dest);

        loader = (train*)malloc(sizeof(train));

        strcpy(loader->dest, trans->dest);

        loader->next = NULL;
        trans2->next = loader;

        trans2 = trans2 ->next;
      }
    }
  }

  int i = 1;
  // this for loop is going to print the header2 linked list obtained above
  for(trans2 = header2->next;trans2 != NULL;trans2 = trans2->next,i++)
  {
    printf("%d. %s",i, trans2->dest);

  }
  int choice;
  printf("\nPlease select a destination\n");
  scanf("%d", &choice);
  int cnt =0;
  for(trans2 = header2->next;cnt<choice-1;cnt++, trans2 = trans2->next);
  printf("hi %d no. of trains are going to  %s",print(trans2->dest,0,0).i,trans2->dest);
  cnt = print(trans2->dest,1,0).i;
  //we are going to choose the nth element which of the linked list using a function
  train *choosedtrain;
  int trainchoosed;
  printf("please enter the serial no. of the train that you want to book:\n");
  scanf("%d",&trainchoosed);
  choosedtrain = print(trans2->dest,2,trainchoosed).tr;
  printf("\nYour choice:\n\n Train name:  %s     Train destination:  %s     Train Arrival time:  %s     Train departure time:  %s     Train number:  %s ",choosedtrain->tr_name, choosedtrain->dest, choosedtrain->arr_time, choosedtrain->dep_time, choosedtrain->tr_no);
  printf("\n1) AC  -  Cost:  %d \n2) NON-AC -  Cost:   %d\n",choosedtrain->ac_cost, choosedtrain->cost);
  int w;
  scanf("%d",&w);
  printf("\nPlease enter your name  - ");
  usr add;
  fgets(add.name,100,stdin);
  fgets(add.name,100,stdin);
  strcpy(add.name,strupp(add.name));
  usr *headern,*temp; int check;
  headern = loaduserlist();
  if(checkexistence(add.name))
  {
    printf("\nplease enter your pin(4 digit only)\n");
    scanf("%d",&check);
    int re;
    re = checkexistence1(check,add.name);
    if(re ==1)
    {
      printf("\nuser verified\n");
      add.a = choosedtrain;
      add.pin = check;
      add.next = NULL;
      for(temp = headern;temp->next!=NULL;temp = temp->next);
      add.PNR = temp->PNR+1;
      temp->next = &add;
    }
    else if(re==0)
    {
      printf("sorry invalid user");
      exit(0);
    }
  }
  else{
    printf("\nhi new user\n");
    printf("Please enter a new PIN");
    scanf("%d",&add.pin);
    add.a = choosedtrain;
    add.next = NULL;
    for(temp = headern;temp->next!=NULL;temp = temp->next);
    add.PNR = temp->PNR+1;
    printf("\n%d\n",add.PNR);
    temp->next = &add;


  }

  if (w==1){
    choosedtrain = print(trans2->dest,3,trainchoosed).tr;

}
else if(w==2){
  choosedtrain = print(trans2->dest,4,trainchoosed).tr;
}
printf("\nTicket's Booked\n");
int ticketresponse;
ticketresponse = yourticket(&add,w);
if (ticketresponse ==1)
{
  printf("\nyour ticket is printed\nplease check it in Tickets folder");
  dumpuserlist(headern);
}
  return 0;
}
