#include"header.h"

User Signup()
{   
   User user1;

    system("cls");
    printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("                                                                                        SIGNUP                              \n");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");


    char mobile[100],firstname[100],lastname[100], username[100],password[100];
    printf("\nEnter First name: ");
    scanf("%s",user1.FirstName);

    printf("\nEnter Last name: ");
    scanf("%s",user1.LastName);

    printf("\nEnter Mobile Number: ");
    scanf("%s",user1.MobileNo);

    printf("\nEnter a username : ");
    scanf("%s",user1.UserName);

    printf("Enter a password : ");
    scanf("%s",user1.Password);


    char filename[20];
    strcpy(filename,user1.UserName);
    int len = strlen(user1.UserName);
    strcat(filename,".txt");
    //printf("%s\n",filename);


    //Takingn info to structure:
     user1.TicketCOunt=0;
     user1.price=0.0f;
    
    //1st ticket:
    user1.ticket[0].BusSelection=0;
    user1.ticket[0].SeatNumber=0;
    strcpy(user1.ticket[0].Location,"NULL");

    //2nd ticket :
    user1.ticket[1].BusSelection=0;
    user1.ticket[1].SeatNumber=0;\
    strcpy(user1.ticket[1].Location,"NULL");


    //3rd Ticket:
    user1.ticket[2].BusSelection=0;
    user1.ticket[2].SeatNumber=0;
    strcpy(user1.ticket[2].Location,"NULL");


    //4th ticket :
    user1.ticket[3].BusSelection=0;
    user1.ticket[3].SeatNumber=0;
    strcpy(user1.ticket[3].Location,"NULL");




    FILE *fp = fopen(filename,"w");
   
    fprintf(fp,"First Name : %s\nLast Name : %s\nUsername : %s\nPassword : %s\nMobile Number : %s\nTicket Count: %d\nPrice : %lf\n\nTicket 1 : \n   BusSelected : %d \n   SeatNumber : %d\n     Location : %s\nTicket 2 : \n   BusSelected : %d \n   SeatNumber : %d\n      Location : %s\nTicket 3 : \n   BusSelected : %d \n   SeatNumber : %d\n      Location : %s\nTicket 4 : \n   BusSelected : %d \n   SeatNumber : %d\n      Location : %s",user1.FirstName,user1.LastName,user1.UserName,user1.Password,user1.MobileNo,user1.TicketCOunt,user1.price,user1.ticket[0].BusSelection,user1.ticket[0].SeatNumber,user1.ticket[0].Location,user1.ticket[1].BusSelection,user1.ticket[1].SeatNumber,user1.ticket[1].Location,user1.ticket[2].BusSelection,user1.ticket[2].SeatNumber,user1.ticket[2].Location,user1.ticket[3].BusSelection,user1.ticket[3].SeatNumber,user1.ticket[3].Location);


    

   
    fclose(fp);
   


    system("cls");
    printf("\n\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("                                                                                      Registration Successfull \n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    
    printf("\n\n");
    printf(".....................................................................................Returning to the Home Page................................................................................................\n");Sleep(2000);
    return user1;
}
