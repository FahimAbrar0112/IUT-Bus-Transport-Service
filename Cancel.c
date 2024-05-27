#include"header.h"

 /*
    This Actually helps to cancel a ticket


 */

User CancelTicket( User user1)
{
   char BUS[5][130]={"BUS 1","BUS 2","BUS 3","BUS 4","BUS 5"} ;
   
    // printf("%s",BUS[0]);
    // printf("%s",BUS[4]);

    int  bus_track,seat_track,location_track;

    //Per user has 4 tickets => he can buy ane of them
    /*
        now which ticket he has bought is
        and which bus,seat and location etc 
        will be displayed here.
        THen the user can easily choose which ticket he need to cancel 
    */

    printf("\nTickets you have bought : \n");

    for(int i=0 ; i<4 ; i++) 
    {
        if(user1.ticket[i].BusSelection==0)
         continue;
        else
        printf("\nBus No: %d    Seat No: %d     Location: %s",user1.ticket[i].BusSelection,user1.ticket[i].SeatNumber,user1.ticket[i].Location);


        


    }



    printf("\n\n\nEnter Bus Number: \n");
    scanf("%d", &bus_track);


    printf("\nEnter Seat Number : \n");
    scanf("%d", &seat_track);

    
    // system("cls");

    // printf("\n\nLocations:\n\n");  /*        1.Uttora\n2.Airport\n3.Bashundhora\n4.Mirpur\n5.Farmgate\n6.Savar\n7.Tongi\n8.Gulshan\n9.Paltan\n10.Mohakhali\n
    //                                                 10        20          30             40        50         60        15         25       35           70       */
    //         printf("From : IUT \n");
                                        
    //         printf("\n\nTo:\n\n");
    //         printf("1.Uttora\n2.Airport\n3.Bashundhora\n4.Mirpur\n5.Farmgate\n6.Savar\n7.Tongi\n8.Gulshan\n9.Paltan\n10.Mohakhali\n ");

    // printf("\nEnter Location : \n");
    // scanf("%d", &location_track) ;









    int targetTicket=-1;


    for(int i=0 ; i<4 ; i++)
    {
        if(user1.ticket[i].BusSelection==bus_track && user1.ticket[i].SeatNumber==seat_track)
         {
             targetTicket=i;
             break;
         }
    }



   //Price decrease kor:
   double taka_j_amount_ta_kombe=0;

   taka_j_amount_ta_kombe=locationANDpriceForCanel();



    


   




    //After Cancelling updating the ticket info:

    user1.ticket[targetTicket].BusSelection=0;
    user1.ticket[targetTicket].SeatNumber=0;
    user1.price -= taka_j_amount_ta_kombe;
    strcpy(user1.ticket[targetTicket].Location,"NULL");
    user1.TicketCOunt--;






    char filename[100];
    strcpy(filename,user1.UserName);
    strcat(filename,".txt");


    //Updating the user.txt File:


    FILE *fp = fopen(filename,"w");
   
    fprintf(fp,"First Name : %s\nLast Name : %s\nUsername : %s\nPassword : %s\nMobile Number : %s\nTicket Count: %d\nPrice : %lf\n\nTicket 1 : \n   BusSelected : %d \n   SeatNumber : %d\n     Location : %s\nTicket 2 : \n   BusSelected : %d \n   SeatNumber : %d\n      Location : %s\nTicket 3 : \n   BusSelected : %d \n   SeatNumber : %d\n      Location : %s\nTicket 4 : \n   BusSelected : %d \n   SeatNumber : %d\n      Location : %s",user1.FirstName,user1.LastName,user1.UserName,user1.Password,user1.MobileNo,user1.TicketCOunt,user1.price,user1.ticket[0].BusSelection,user1.ticket[0].SeatNumber,user1.ticket[0].Location,user1.ticket[1].BusSelection,user1.ticket[1].SeatNumber,user1.ticket[1].Location,user1.ticket[2].BusSelection,user1.ticket[2].SeatNumber,user1.ticket[2].Location,user1.ticket[3].BusSelection,user1.ticket[3].SeatNumber,user1.ticket[3].Location);
   
   
    fclose(fp);


    // char BusVar[100] ;
    // int temp=user1.ticket[targetTicket].BusSelection - 1 ;
     
    //  printf(">>>%d<<\n\n",user1.ticket[targetTicket].BusSelection);

    
        


        //Updating the seats in the BUS File:

     int seats[20];

   //  printf(" >>%s<<",BUS[bus_track-1]);

     fp =  fopen(BUS[bus_track-1], "r");

    //  if(fp==NULL)
    //    printf("\nBokchodAgasin\n");
     
     for(int i=0;i<20;i++)
     {
         fscanf(fp,"%d",&seats[i]);
      //  printf("\n%d",seats[i]);
     }
     
     fclose(fp);

     fp =  fopen(BUS[bus_track-1], "w");

    //  if(fp==NULL)
    //    printf("Bokchod");


     seats[seat_track-1] = 1 ;

        // printf("Yoooooooo\n");
        // printf(" \n%d",seats[4]);

     for(int i=0;i<20;i++)
     {
      //printf("\nTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT\n");

      fprintf(fp,"%d\n",seats[i]);

      //printf(" \n%d",seats[i]);

     } 
    // printf("\nBuuuuu");
    
    
    fclose(fp) ;


    printf("\nTicket Cancalation Done\n");


    //printf("")


    return user1 ;


    //After Modification returning the modified data.



    








}

double locationANDpriceForCanel()
{   

    int dest;
    
    while(true)
    {
        
            system("cls");
            printf("\n\nLocations:\n\n");  /*        1.Uttora\n2.Airport\n3.Bashundhora\n4.Mirpur\n5.Farmgate\n6.Savar\n7.Tongi\n8.Gulshan\n9.Paltan\n10.Mohakhali\n
                                                    10        20          30             40        50         60        15         25       35           70       */
        // printf("From : IUT \n");
                                        
        // printf("\n\nTo:\n\n");
            printf("\n\n1.Uttora\n2.Airport\n3.Bashundhora\n4.Mirpur\n5.Farmgate\n6.Savar\n7.Tongi\n8.Gulshan\n9.Paltan\n10.Mohakhali\n ");

            printf("\nEnter your Destination:\n");
            
            scanf("%d",&dest);
            //return dest;
   
            if(dest>=1 && dest<=10)
            {
                break;
            }
            else
            {
                printf("\n\n\nYou have Entered Wrong Destination\nTry Again by pressing any key..............");

                getch();


            }
   
   
    }






    switch(dest)
    {
        case 1: return 10.0;
        case 2: return 20.0;
        case 3: return 30.0;
        case 4: return 40.0;
        case 5: return 50.0;
        case 6: return 60.0;
        case 7: return 15.0;
        case 8: return 25.0;
        case 9: return 35.0;
        case 10:return 70.0;
       
       
        //default: return 0.00;
    }

}