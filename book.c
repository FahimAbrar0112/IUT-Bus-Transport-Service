

#include"header.h"

LocationANdPrice locationANDprice();
  //Basically  This function   return price of ticket and the location  selected by the user


//seat available or not?
// To check this I am using boolean data 0 & 1 
// 1 represents available 
//0 represents not available or booked 


#define Available 1
#define Booked    0




//it returns the data type of user
//And user is defined in the header file....................

User boookTicket(User user1)
{   
   //Our system works for 5 buses 
   // these 5 bus travel each and every places of our setup or inserted location...........

   //I used 2D array for hold the names of the buses as well  the number of that bus

    char BUS[5][130]={"BUS 1","BUS 2","BUS 3","BUS 4","BUS 5"} ;

    system("cls");
        // this works to refresh the console screen


    //Jodi 4 ta ticket e age buy kora hoy then ja korbe:
            if(user1.TicketCOunt==4)
            {
                printf("\nYou have bought 4 tickets among 4...\nNo Tickets Available yet.\n Can't Book more tickets\n");
                return user1;
            }
    
    //If you buy max tickets 4
    //then the func will return the user val without modifying
    //and it also checks ticketcount is greater than 4 or not


    if(user1.TicketCOunt>4)
    {
        printf("\nSorry You Can't Book Ticket\n");
        printf("\nYou Have Bought Max 4 Tickets...\n");
        printf("\nReturning to the main Menu.......");

        return user1 ;
    }

    int select_From_to_IUT;
        //This var tracks that you are going from IUT
        // or you are coming to iut 

    while(true)
    {
        printf("\nSelect Pickup Location :\n\n\n");
        printf("1.From IUT");
        printf("\n2.To IUT\n\n\n");
        printf("Enter Choice:  ");

        scanf("%d",&select_From_to_IUT);


        //Untill You put the correct Data it itterates
        if(select_From_to_IUT==1 || select_From_to_IUT==2)
         break;
        else
        {
            printf("Wrong Selection.\nPress any key to try again");
            getch();
            system("cls");
        } 
    }
    


        int busSelection  ;

        while(true)
        {
          
        
            printf("\n\n");
            BusList();

            

            printf("\nA.Enter BUS No  ");
            printf("\n\nB.To Go Back To Home Page, Press [0] \n\n\n");
            scanf("%d",&busSelection);


            if(busSelection==0)
            {   
                // printf("\nPress any key to proceed");
                // getch();

                return user1;
            }
            else if(busSelection>=1 && busSelection<=5)
            {
                break;
            }
            else
            {   
                system("cls");
                printf("You have entered wrong Bus Number\n");
                printf("Try Again....\n");

                printf("\n\n\nPress Any Key to Continue...");
                getch();
                system("cls");
            }
        
        
        }

    //Seats is an array of BUS[i] 
    //IT is taken to track which seats have been book of that bus 
    //Opening the Bus file:

    FILE* fp;
    int seats[20];
    fp=fopen(BUS[busSelection-1], "r");

    for(int i=0;i<20;i++)
     {
         fscanf(fp,"%d",&seats[i]);
      //  printf("\n%d",seats[i]);
     }


    //Start 
    //Checking whether the bus is full or not: 
    int Flag_to_see_bus_full_or_not=0; // -1 full ,-2 not Flag_to_see_bus_full_or_not
    int track=0;
    for(int i=0;i<20;i++ )
     {
         if(seats[i]==0)
         track++;

     }
     if(track==20)
      Flag_to_see_bus_full_or_not = -1;
     else
      Flag_to_see_bus_full_or_not =-2;
    
    
    fclose(fp);
   //Closing The BUs File







    //Checking The Bus is full or not

    if(Flag_to_see_bus_full_or_not==-1)
    {
     
     system("cls");
     printf("\n\n\nBUS NUMBER [%d] is Full .. No tickets left . Try Another Bus\n",busSelection);
     printf("\n\n\nPress Any Key to Continue.\n");
     getch();
     boookTicket(user1);
     
    
    }
    //END  
    else
    {
                


            system("cls");
            for(int i=0;i<20;i++) 
            {
                if(i != 0 && i%4==0)
                printf("\n");
                else if(i != 0 && i % 2 == 0)
                printf("\t\t\t");
            if(seats[i]==1)
                printf("%02d.%-10s ",i+1,"Available");
            else
                printf("%02d.%-10s ",i+1,"Booked"); 
            
            

            }



            int ticketCountThatYouWantToBuyNow=0;
            int ticketsThatHasBeenPurchased=user1.TicketCOunt;


            
           
           
            
            while(true)
            {   
                printf("\n\nHow Many  tickets do you want ? (Remember You Can Buy Max 4 tickets)  :");
            
                printf("\nYou Have Bought %d Tickets and Now You can purchase %d Tickets\n",user1.TicketCOunt,4-user1.TicketCOunt);

                 scanf("%d",&ticketCountThatYouWantToBuyNow);

                if(ticketCountThatYouWantToBuyNow>(4-user1.TicketCOunt))
                {
                    printf("\n\nSorry YOu Can't purchase more than %d tickets..",4-user1.TicketCOunt);
                }
                else
                 break;
                 

            }
           

           // TicketCOunt=ticketCountThatYouWantToBuyNow;


            for(int i=1;i<=ticketCountThatYouWantToBuyNow; )
            {   

                //Printing available Seats of chossed BuS:
                //This Part Actually shows which tickets are booked and whick are acvailable:

                //.......Start........  
                    system("cls");
                    for(int j=0;j<20;j++) 
                    {
                        if( j!= 0 && j%4==0)
                        printf("\n");
                        else if(j != 0 && j % 2 == 0)
                        printf("\t\t\t");
                    if(seats[j]==1)
                        printf("%02d.%-10s ",j+1,"Available");
                    else
                        printf("%02d.%-10s ",j+1,"Booked"); 
                    }
            //..........END.........

               
                user1.ticket[user1.TicketCOunt].BusSelection=busSelection;

                printf("\n\n\nEnter Seat NO: ");
                scanf("%d",&user1.ticket[user1.TicketCOunt].SeatNumber);

                


                


                if( (seats[ user1.ticket[user1.TicketCOunt].SeatNumber-1] ) ==0 || user1.ticket[user1.TicketCOunt].SeatNumber>20   )
                {
                    
                    printf("\n%d Seat is Not Available\n",user1.ticket[user1.TicketCOunt].SeatNumber);
                    printf("\nPress any key to continue\n");
                    getch();
                }  
                else
                {
                    seats[user1.ticket[user1.TicketCOunt].SeatNumber -1 ]=0;   
                    i++;
                    system("cls");
                    

                    /*
                        Here LocationANDPrice func returns the user chooseen location and the price of the ticket of that place
                    */
                    LocationANdPrice var;
                    var=locationANDprice(select_From_to_IUT);
                    user1.price+= var.price; 
                        //Sum up the previous price and current price of the ticket that was chooseen

                    strcpy(user1.ticket[user1.TicketCOunt].Location,var.location);
                    user1.TicketCOunt++; 
                        //Incrementing Ticket COunt


                    //USed that while Debugging:

                    // printf("\ncheck1\n");
                    // getch();
                }  
                

            
            }
            system("cls");


            //We know  which ticket of the bus we are gonna Buy
            //So after chooosing the bus  we need to update that the seat of that bus has been boooked after booking or taking all the info of the ticket and bus
            //Thn this part works here
            //It overrites the initial data of the bus and puts new booke and available seats

           fp=fopen(BUS[busSelection-1], "w");

         //USed that while Debugging:
        //    if(fp==NULL) printf("tut\n");
        //     printf("check2\n");


           
        //Printing  updated data into the BuS FIle:   
           
           for(int i=0;i<20;i++)
            {
             
             fprintf(fp,"%d\n",seats[i]);

            } 
            fclose(fp); 


         //USed that while Debugging:
        // printf("USER INFO:\n First Name : %s\nLast Name : %s\nUsername : %s\nPassword : %s\nMobile Number : %s\nTicket Count: %d\nPrice : %lf\nSeat[0] : %d\nSeat[1] : %d\nSeat[2] : %d\nSeat[3] : %d\n",user1.FirstName,user1.LastName,user1.UserName,user1.Password,user1.MobileNo,user1.TicketCOunt,user1.price,user1.SeatNumber[0],user1.SeatNumber[1],user1.SeatNumber[2],user1.SeatNumber[3]);          
           
           
           
          
          /*
             As the user booked some tickets , the info should be updated in the user variable
             so after updating we need to save that data in the user file

             so here I'm printing the data inside User.txt 
        
            
         */
           
           char temporayUser[100];
            strcpy( temporayUser,user1.UserName);
            strcat( temporayUser,".txt");
            FILE* rfp;
            rfp=fopen(temporayUser,"w");

        
            // user1.TicketCOunt+=ticketCountThatYouWantToBuyNow;

            
            
              fprintf(rfp,"First Name : %s\nLast Name : %s\nUsername : %s\nPassword : %s\nMobile Number : %s\nTicket Count: %d\nPrice : %lf\n\nTicket 1 : \n   BusSelected : %d \n   SeatNumber : %d\n     Location : %s\nTicket 2 : \n   BusSelected : %d \n   SeatNumber : %d\n      Location : %s\nTicket 3 : \n   BusSelected : %d \n   SeatNumber : %d\n      Location : %s\nTicket 4 : \n   BusSelected : %d \n   SeatNumber : %d\n      Location : %s",user1.FirstName,user1.LastName,user1.UserName,user1.Password,user1.MobileNo,user1.TicketCOunt,user1.price,user1.ticket[0].BusSelection,user1.ticket[0].SeatNumber,user1.ticket[0].Location,user1.ticket[1].BusSelection,user1.ticket[1].SeatNumber,user1.ticket[1].Location,user1.ticket[2].BusSelection,user1.ticket[2].SeatNumber,user1.ticket[2].Location,user1.ticket[3].BusSelection,user1.ticket[3].SeatNumber,user1.ticket[3].Location);
            
             fclose(rfp);

             printf("\n......................................................................................Ticket Booking DONE.....................................................................................................................\n");
            

         

            

            printf("\nPrice of Tickets Total : %.2lf\n",user1.price);


            return user1;
    }

     
   
}


//After ending the
/*
     This func returns the updated usr data that can be used for future purpose...........
*/
