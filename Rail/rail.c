#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main()
{
        int i=0;
        printf("\t\t\t\t\t\t\t\t\t\t\t       --------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t       Railway Reservation System\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t       --------------------------\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t     =============================================\n");
        printf("\t\t\t\t\t\t\t\t\t\t     |                                           |\n");
        printf("\t\t\t\t\t\t\t\t\t\t     |          1. Seat Booking                  |\n");
        printf("\t\t\t\t\t\t\t\t\t\t     |                                           |\n");
        printf("\t\t\t\t\t\t\t\t\t\t     |          2. Seat Cancellation             |\n");
        printf("\t\t\t\t\t\t\t\t\t\t     |                                           |\n");
        printf("\t\t\t\t\t\t\t\t\t\t     |          3. Enquiry                       |\n");
        printf("\t\t\t\t\t\t\t\t\t\t     |                                           |\n");
        printf("\t\t\t\t\t\t\t\t\t\t     |          4. Ticket Detail                 |\n");
        printf("\t\t\t\t\t\t\t\t\t\t     |                                           |\n");
        printf("\t\t\t\t\t\t\t\t\t\t     =============================================\n");
        printf("\n\n\t=>Enter your choice:\t");
        int choice;
        char *choi;
        choi=(char*)malloc(10);
        scanf("%s",choi);
        choice=atoi(choi);
        printf("%d\n",choice );
        switch (choice) {
        default:
                printf("Not a valid input, try again" );
                setvbuf(stdout, NULL, _IONBF, 0);
                while (i<3) {
                        sleep(1);
                        printf(".");
                        i++;
                }
                printf("\e[1;1H\e[2J\n");
                main();
                break;

        case 1:
                printf("d");//a function of seatbooking;
                break;
        case 2:
                printf("f");//a function of seat Cancellation;
                break;
        case 3:
                printf("g");//a function of Enquiry;
                break;
        case 4:
                printf("h");//a function of Ticket Detail;
                break;

        }
}
