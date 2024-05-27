#include"header.h"






LocationANdPrice locationANDprice(int select_From_to_IUT )
{
    LocationANdPrice var;
     int dest;

   while(true)
   {
            printf("\n\nLocations:\n\n");  /*        1.Uttora\n2.Airport\n3.Bashundhora\n4.Mirpur\n5.Farmgate\n6.Savar\n7.Tongi\n8.Gulshan\n9.Paltan\n10.Mohakhali\n
                                                    10        20          30             40        50         60        15         25       35           70       */
            
            if(select_From_to_IUT==1)
            {
                printf("From : IUT \n");
                                            
                printf("\n\nTo:\n\n");
                printf("1.Uttora\n2.Airport\n3.Bashundhora\n4.Mirpur\n5.Farmgate\n6.Savar\n7.Tongi\n8.Gulshan\n9.Paltan\n10.Mohakhali\n ");
            }
            else
            {
               
                                            
                printf("\n\nFrom:\n\n");
                printf("1.Uttora\n2.Airport\n3.Bashundhora\n4.Mirpur\n5.Farmgate\n6.Savar\n7.Tongi\n8.Gulshan\n9.Paltan\n10.Mohakhali\n ");

                 printf("\n\nTo : IUT \n");
            }



            printf("\nEnter your Destination:\n");
           
            scanf("%d",&dest);

            if(dest>=1 && dest<=10)
             break;
            else
            {
                system("cls");
                printf("\nWrong Destination Chosen\nTry Again...\n");

                printf("\nPress any key to continue");
                getch();
            }
   }




















    //return dest;
    switch(dest)
    {
        case 1: 
                strcpy(var.location,"Uttara");
                var.price=10.0;        
                return var;

        case 2:    
                    strcpy(var.location,"Airport");
                    var.price=20.0;        
                    return var;
        case 3:   
                    strcpy(var.location,"Bashundhara");
                    var.price=30.0;        
                    return var;
        case 4:    
                    strcpy(var.location,"Mirpur");
                    var.price=40.0;        
                    return var;
        case 5:    
                    strcpy(var.location,"Farmgate");
                    var.price=50.0;        
                    return var;
        case 6:    
                    strcpy(var.location,"Savar");
                    var.price=60.0;        
                    return var;
        case 7:   
                    strcpy(var.location,"Tongi");
                    var.price=15.0;        
                    return var;
        case 8:    
                    strcpy(var.location,"Gulshan");
                    var.price=35.0;        
                    return var;
        case 9:    
                    strcpy(var.location,"Paltan");
                    var.price=55.0;        
                    return var;
        case 10:   
                    strcpy(var.location,"Mohakhali");
                    var.price=65.0;        
                    return var;
        
    }

}
