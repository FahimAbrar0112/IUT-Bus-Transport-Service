#include"header.h"

/*
        MenuBar this func is the mother of controlling the whole application
        Here we control everything
        It actyually takes user choice
        then accordin to it it call the desired function
        It works some basic purpuse also
*/



void MenuBar(User user)
{

   while(true)
   { 
    
        int choice ;
        
        system("cls");



        //It works for the design of the code:
        Look_Menu();


        //Pinting THe Whole List that this func can perform:

        printf("\n\n\n");
        printf(" 1.Bus List & Timing             [ 1]\n");
        printf(" 2.Bus Fare & Destinations       [ 2]\n");
        printf(" 3.Book Ticket                   [ 3]\n");
        printf(" 4.Cancel Ticket                 [ 4]\n");
        printf(" 5.Show Bill                     [ 5]\n");                                                                    //  
        printf(" 6.Get Printed Copy of Receipt   [ 6]\n");
        printf(" 7.User Status                   [ 7]\n");
        printf(" 8.Pay Bill                      [ 8]\n");
        printf(" 9.Rent a Car                    [ 9]\n");
        printf("10.Logout                        [10]\n");     
        printf("11.Exit                          [ 0]\n");

        /*
                Exit is used to terminate the program

                after using the program we will need to terminate it by our choice

                so this option proovides us that opportunity
        */  

       // printf("12.Exit                          [0]\n");
        
        printf("\n\nEnter an option:  ");

        scanf("%d",&choice);

        switch (choice)
        {
            case 1: /*
                        Bus List & Timing 
                        
                        Different BUs tracvels on different time
                        SO this func shows the timing of departure of the buses

                    */
                    system("cls");
                    BusList();
                    printf("\n\n\nPress Any Key to Continue\n");
                    getch();
                    system("cls");
                    break;

            case 2:
                //This FUnc SHows  The Price of the tickets from iut to that place ||  from that place to iut
                //The price remains the same if you come to iut  from  Uttora
                // Or go uttora from iUT
 
                //Debugging
                //     system("cls");
                //     BusLocations();
                //     printf("\n\n\nPress Any Key to Continue\n");
                //     getch();
                //     system("cls");
                //     break;

                    system("cls");
                    printf("\nPrice of Ticket:\n\n\n");
                    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                    printf(" 1.Uttara       Price : 10 TK\n");
                    printf(" 2.Airport      Price : 20 TK\n");
                    printf(" 3.Bashundhara  Price : 30 TK\n");
                    printf(" 4.Mirpur       Price : 40 TK\n");
                    printf(" 5.Farmgate     Price : 50 TK\n");
                    printf(" 6.Savar        Price : 60 TK\n");
                    printf(" 7.Tongi        Price : 15 TK\n");
                    printf(" 8.Gulshan      Price : 35 TK\n");
                    printf(" 9.Paltan       Price : 55 TK\n");
                    printf("10.Mohakhali    Price : 65 TK\n");
                    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                     printf("\n\n\nPress Any Key to Continue\n");
                     getch();
                     system("cls");
                     break;

                    
            case 3: //THis part calls the book func and user books ticket here:

                    system("cls");
                    user=boookTicket(user);     
                    printf("\n\n\nPress Any Key to Continue\n");
                    getch();
                    system("cls");
                    break;


                    
                    
                    
                    
                    
                   

            case 4:
                   // This func actually works for cancelling ticket
                   //This FUnc is not fully operational till now so becarefUl using this
                   //Update Needed

                   system("cls");
                    user=CancelTicket(user);
                    printf("\n\n\nPress Any Key to Continue\n");
                    getch();
                    system("cls");
                    break; 

            case 5:  
                       /*
                                 If user wants he can see his bill using that funct:
                        */

                        system("cls");
                        printf("                                                                                         *******  *   *  ******* \n");
                        printf("                                                                                            *     *   *     *   \n");
                        printf("                                                                                            *     *   *     *   \n");
                        printf("                                                                                            *     *   *     *   \n");
                        printf("                                                                                         *******  *****     *   \n");
                        printf("\n.........................................................................................BUS RESERVATION SYSTEM.........................................................................................\n");
                        printf("===========================================================================================================================================================================================================\n");
                        printf("\n\n\n\n\n");
                        printf("AMOUNT TO BE PAID: %1lf",user.price);
                        printf("\n\n\n\nPress Any Key to Continue\n");
                        getch();
                        system("cls");
                        break;
                   

        

            case 6:  
                         //Sometimes user needs a printed receipt of the price of the ticket and the info about the tickets
                   //Hew can get it from here........

                    system("cls");

                    char temp[100]={'\0'};
                    int counting=0;
                    strcpy(temp,user.UserName);
                    strcat(temp,"BILL");
                    strcat(temp,".txt");
                    FILE*fp=fopen(temp,"w");


                   system("cls");
                        fprintf(fp,"                                                                                         *******  *   *  ******* \n");
                        fprintf(fp,"                                                                                            *     *   *     *   \n");
                        fprintf(fp,"                                                                                            *     *   *     *   \n");
                        fprintf(fp,"                                                                                            *     *   *     *   \n");
                        fprintf(fp,"                                                                                         *******  *****     *   \n");
                        fprintf(fp,"\n.........................................................................................BUS RESERVATION SYSTEM.........................................................................................\n");
                        fprintf(fp,"===========================================================================================================================================================================================================\n\n\n");



                    fprintf(fp,"Name: %s \nMobile Number: %s\nYOUR BILL: %.1lf TK",user.UserName,user.MobileNo,user.price);
                    fprintf(fp,"\n...........................................................................................\n\n\n");
                    
                    fprintf(fp,"\n\n\nInformation About Bus , Seat and Destinatin: \n\n");
                    
                    
                    for(int i=0;i<4;i++)
                    {
                            if( user.ticket[i].BusSelection==0  )
                            {
                             
                             counting++;
                             continue;
                             
                            }
                            else
                            {
                                    fprintf(fp,"BUS : Bus %d\nSeat Number: %d\nDestination: %s\n\n",user.ticket[i].BusSelection,user.ticket[i].SeatNumber,user.ticket[i].Location);
                                    //printf("\n\n");
                            }
                             
                    }
                    if(counting==4) 
                     fprintf(fp,"\nNo Ticket Has been Purchased\n");

                    fclose(fp);
                    printf("\nYour BIll has been printed on a File Naming [%sBILL.txt]\n",user.UserName);
                    printf("\n\n\n\nPress Any Key to Continue\n");
                    getch();
                    system("cls"); 
                    break;
                        

            case 7:     
                        //USer Stattus
                    //This shows the user the whole info about his profile
                    //How many tickets he has boooked along with the bus and seat number
                    //The pricce of the ticket is
                    //Ticket Count also





                    system("cls");

                    printf("First Name : %s\nLast Name : %s\nUsername : %s\nMobile Number : %s\nTicket Count: %d\nPrice : %lf\n\nTicket 1 : \n   BusSelected : %d \n   SeatNumber : %d\n     Location : %s\nTicket 2 : \n   BusSelected : %d \n   SeatNumber : %d\n      Location : %s\nTicket 3 : \n   BusSelected : %d \n   SeatNumber : %d\n      Location : %s\nTicket 4 : \n   BusSelected : %d \n   SeatNumber : %d\n      Location : %s",user.FirstName,user.LastName,user.UserName,user.MobileNo,user.TicketCOunt,user.price,user.ticket[0].BusSelection,user.ticket[0].SeatNumber,user.ticket[0].Location,user.ticket[1].BusSelection,user.ticket[1].SeatNumber,user.ticket[1].Location,user.ticket[2].BusSelection,user.ticket[2].SeatNumber,user.ticket[2].Location,user.ticket[3].BusSelection,user.ticket[3].SeatNumber,user.ticket[3].Location);
                    
                    
                    getch();
                    system("cls"); 
                    break;
                   
                  

            case 8:   
                     //PAY BILL FUNC
                      //This helps the user to know how to pay his bill

                    system("cls");
                    printf("\n....................................................................PAY BILL..........................................................................................\n");


                    printf("\n\n\n1.Pay Online\n");
                    printf("2.Pay in Cash \n");


                    int paymentOption ;
                    printf("\n\n\nEnter Option: ");
                    scanf("%d",&paymentOption);


                    if(paymentOption==1)  
                    {
                            printf("\nPay the bill to the given agent Number via Bkash :  01797951130\n");
                            printf("\n\n\n");
                            printf("\nAmount to be Paid : %.1lfTk\n",user.price);


                    }
                    else 
                    {
                            printf("\nAmount to be Paid : %.1lfTk\n",user.price);
                            printf("\n\n\nKindly Pay The Bill To The Driver.\n");

                    }
                    printf("\n\n\n\nPress Any Key to Continue\n");
                    getch();
                    system("cls"); 
                    break;  

                      
            
            case 9:  /**
                    * Car rental Service
                    * thie func actually provideas scope to rent a car usingn this application
                    * user can have diffrent flavour using the same app
                    * 
                    * 
                    */
                    system("cls");
                    CarRental(user);
                    printf("\n\n\n\nPress Any Key to Continue\n");
                    getch();
                    system("cls");
                    break;
                            

            case 10:   
                        //Gives scope to login or sign up again:

                        look_LOGIN_SIGNUP();
                        printf("\n\n\n\nPress Any Key to Continue\n");
                        getch();
                        system("cls"); 
                        break;

           

                            


            case 0:   
                        //Terminates the function:


                        system("cls");
                        // printf("\n\n\nPress Any Key to Continue\n");
                        for(int i=3;i>=1;i--)
                        {
                        printf("\nProgram Terminating in %d..........",i);
                        Sleep(1000);
                        system("cls");
                        
                        } 
                        //getch(); 
                        exit(0) ;  
                          

       }
   }

}
