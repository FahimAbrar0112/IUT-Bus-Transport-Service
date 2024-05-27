#include"header.h"


void CarRental(User user1)
{
    //system("cls");
    int choice ;
    int driver;
   
    char file[100];
    
    
    char Pickup[100];
    char Drop[100];
    char Time[100];





     strcpy( file,user1.UserName);
     strcat(file,"_CarRentalService_Slip");
     strcat(file,".txt");

    while(true)
    {

            printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf(".......................................................................................WELCOME To CAR RENTAL SERVICE........................................................................................\n");
            printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

            printf("\n\n\n");

            printf("You Can Rent Car here :\n");


            // printf("\nYou can travel to to that places:\n");
            // printf("\n\nLocations:\n\n");  /*        1.Uttora\n2.Airport\n3.Bashundhora\n4.Mirpur\n5.Farmgate\n6.Savar\n7.Tongi\n8.Gulshan\n9.Paltan\n10.Mohakhali\n
            //                                            10        20          30             40        50         60        15         25       35           70       */
            // printf("From : IUT \n");
                                        
            // printf("\n\nTo:\n\n");
            // printf("1.Uttora\n2.Airport\n3.Bashundhora\n4.Mirpur\n5.Farmgate\n6.Savar\n7.Tongi\n8.Gulshan\n9.Paltan\n10.Mohakhali\n ");       

        // printf("\nYou also can go wherever you like && The rent should be paid for per km 25.00 TK\n");
            

            printf("Do you want 4 seater or 6 seater?\n");
            printf("\n\n[1]Press 1 for 4 seater\n[2]Press 2 for 6 seater\n\n\n");

            







            
            scanf("%d",&choice);
            if(choice==1 || choice==2)
             break;
            else
            printf("\nChoosen wrong keyward\nTry again by pressing any key.....");
            getch(); 
    } 

    
            FILE* fp=fopen(file,"w");
                            fprintf(fp,"                                                                                         *******  *   *  ******* \n");
                            fprintf(fp,"                                                                                            *     *   *     *   \n");
                            fprintf(fp,"                                                                                            *     *   *     *   \n");
                            fprintf(fp,"                                                                                            *     *   *     *   \n");
                            fprintf(fp,"                                                                                         *******  *****     *   \n");
                            fprintf(fp,"=============================================================================================CAR RENTAL SERVICE==========================================================================================\n\n\n");


    switch(choice)
    {
        case 1:   
                  while(true)
                  { 
                    system("cls");
                    


                    printf("INFORMATION OF THE DRIVER:\n");
                    printf("Driver 1:\n");
                    printf("Contact Information: \n\n");
                    printf("NAME: Tanbir  Phone: 017123654987");
                    printf("\n\n");


                    printf("Driver 2:\n");
                    printf("Contact Information: \n\n");
                    printf("NAME: Abir  Phone: 017132654987");
                    printf("\n\n");


                    printf("Driver 3:\n");
                    printf("Contact Information: \n\n");
                    printf("NAME: Sakib  Phone: 018132654987");
                    printf("\n\n");

                  
                    printf("\nTo Book , Enter Driver Number:\n");
                    scanf("%d",&driver);

                   
                   //Adding feature for picup and drop:
                   //Start:
                    

                    fflush(stdin);
                    printf("\n\nEnter Pick-up Location:  ");
                    gets(Pickup);
                    fflush(stdin);

                    printf("\n\nEnter Destination:  ");
                    gets(Drop);
                    fflush(stdin);
                   
                    

                    printf("\n\nEnter Time for Pickup: ");
                    gets(Time);  
                    fflush(stdin);
                    //End




                    if(driver>=1&&driver<=3)
                     break;
                    else 
                    printf("Incorrect Driver Chosen\nTry Again by pressing any key....") ;
                    getch();
                  
                  }
                    switch(driver)
                    {
                        case 1: fprintf(fp,"Driver 1 \nContact Information: \n\nNAME: Tanbir  Phone: 017123654987");
                                break;
                        case 2: fprintf(fp,"Driver 2:\nContact Information: \n\nNAME: Abir    Phone: 017132654987");
                                break;
                        case 3: fprintf(fp,"Driver 3:\nContact Information: \n\nNAME: Sakib   Phone: 018132654987");
                                break;
                    } 


                    system("cls");

                    printf("\n\nContact them for Car Rental Service\n");

                    printf("The rent will be 20 tk per km");

                    printf("\n\nA receipt has been printed naming [%s_CarRentalService_Slip.txt]\n",user1.UserName);

                    

                    fprintf(fp,"\n\nPick-Up : %s\nDestination : %s\nTime : %s",Pickup,Drop,Time);

                    fclose(fp);


                    break;
    
        case 2:    
        
                while(true)
                  { 
                    system("cls");
                    printf("=====================================================================================================================================================================================================================\n");
                    printf("INFORMATION OF THE DRIVER:\n\n");

                    printf("Driver 1:\n");
                    printf("Contact Information: \n\n");
                    printf("NAME: Sagor  Phone: 017143654987");
                    printf("\n\n");

                    printf("Driver 2:\n");
                    printf("Contact Information: \n\n");
                    printf("NAME: Mustabshir  Phone: 017132654987");
                    printf("\n\n");

                    printf("Driver 3:\n");
                    printf("Contact Information: \n\n");
                    printf("NAME: Sakif       Phone: 014787496551");
                  

                    printf("\n\n\nTo Book , Enter Driver Number:\n");
                    scanf("%d",&driver);




                   
                    //Adding feature for picup and drop:
                   //Start:
                    
                    fflush(stdin);
                    printf("\n\nEnter Pick-up Location:  ");
                    gets(Pickup);
                    fflush(stdin);

                    printf("\n\nEnter Destination:  ");
                    gets(Drop);
                    fflush(stdin);

                    

                    printf("\n\nEnter Time for Pickup: ");
                    gets(Time);
                    fflush(stdin);
                    //scanf("%s",Time);
                    
                    
                    //End






                    if(driver>=1&&driver<=3)
                     break;
                    else 
                    printf("incorrect Driver Choosen\nTry Again by pressing any key....") ;
                    getch();                
                  }
                    switch(driver)
                    {
                        case 1: fprintf(fp,"Driver 1 \nContact Information: NAME: Sagor       Phone: 017143654987"); 
                                 break;
                        case 2: fprintf(fp,"Driver 2:\nContact Information: NAME: Mustabshir  Phone: 017132654987");
                                 break;
                        case 3: fprintf(fp,"Driver 3:\nContact Information: NAME: Sakif       Phone: 014787496551");
                                 break;
                    }



                    system("cls");
                    
                    printf("\n\nContact them for Car Rental Service\n");

                    printf("The rent will be 35 tk per km");

                    printf("\n\nA receipt has been printed naming [%s_CarRentalService_Slip.txt]\n",user1.UserName);
                    



                    fprintf(fp,"\n\nPick-Up : %s\nDestination : %s\nTime : %s",Pickup,Drop,Time);



                    fclose(fp);

                    break;
        
        
                  }

    
    
                printf("\n\nThanks For Using Car Rental Service\n");
    
    } 






//     printf("=====================================================================================================================================================================================================================\n");
//     printf("INFORMATION OF THE DRIVER:\n");
//     printf("Driver 1:\n");
//     printf("Contact Information: \n\n");
//     printf("NAME: Tanbir  Phone: 017123654987");
//     printf("\n\n");
//     printf("Driver 2:\n");
//     printf("Contact Information: \n\n");
//     printf("NAME: Abir  Phone: 017132654987");
//     printf("\n\n");
//     printf("Driver 3:\n");
//     printf("Contact Information: \n\n");
//     printf("NAME: Sakib  Phone: 018132654987");
//     printf("\n\n");
//     printf("Driver 4:\n");
//     printf("Contact Information: \n\n");
//     printf("NAME: Nirob  Phone: 013132654987");
//     printf("\n\n");
//     printf("Driver 5:\n");
//     printf("Contact Information: \n\n");
//     printf("NAME: Mirza  Phone: 015132654987");

//     printf("\n\nContact them for Car Rental Service\n");

//    // printf("\n\n\nPress Any Key To continue.........\n");
    



