#include"header.h"

/*
    How Login in Func works?
    ata akta simple mechanism e kaj kore like the computer works
    jokhon akta movie dekhte chao computer 1st e movie ta ssd theke ram e ane..then movie ta play kore
    dekha hoile then  oitake abar close kore day

    then ota back to ssd chole jay

    so kahini hosse :

    user decide kore ki dekhbe then => ram e load hoy => then dekha hoile close kore => ram theke otake flush kore


*/



/*
    Type defined value use kora hoitese 
    basically agula ascii table theke nisi
    bar bar use korte hobe tai type def use korsi
*/

//For login System:
#define ENTER 13
#define TAB 9
#define BACKSPACE 8
#define SPACE 32


User  Login(void)  /*Login func er kaj hoilo ata basically amader main system e dhukar age check kore authentic user onar profile e dhuktese kina*/
{   

    User user1;
    
    while(true)   /*  ai while ta jotokhon na correct pass and user disso totokhon porjnto repeat korte thakbe */
    {
            printf("\n                                                                                   LOGIN TO YOUR PROFILE \n");
            printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");


        //Username segment:

            char builtin_pass[100]={'\0'};       //hold the correct pass that you have entered while opening an account in the signup func
            char builtin_username[100]={'\0'};   //hold the correct user that you have entered while opening an account in the signup func
            
            int flag1=0;    /*  flag 1 er kaj check kora correct user diso kina*/

            int flag2=0;    /*  flag 2 er kaj checko kora correct pass diso kina*/

            char username[100]={'\0'};
            int j=0;
        
           



            printf("\n\n\n                                                                                    Enter User Name: ");
            fflush(stdin);
            gets(username);
            fflush(stdin);
           

            char inputUser[100],inputPassword[100],mobile[100];
            char nameF[100];
            char nameL[100];

            char filename[100]={'\0'};
            strcpy(filename,username);
            strcat(filename,".txt");

            fflush(stdin);
            
             //File Open korteso to collect the builtin pass and user from the user File:
             //Start:
            FILE *rfp = fopen(filename,"r");

            fscanf(rfp," First Name : %s Last Name : %s Username : %s Password : %s Mobile Number : %s",nameF,nameL,inputUser,inputPassword,mobile);


            
            fclose(rfp);
            //End.


            //Checking user is correct or not: 
            //If correct then flag =1 hobe.
            if(strcmp  (inputUser,username)  ==0 )
            flag1=1;

        
        

        //Password segment:

            char password[100];
            int i=0;
            char ch;
            printf("\n                                                                                    Enter Password: ");
            while(1)
            {
                ch=getch();
                if(ch==ENTER)
                {
                    password[i]='\0' ;  
                                        /*
                                        Enter mane pass jta diso ota r change korte chasso na and login korte  chasso tumi ..so enter chapa matro password[i] e '\0' diye dibe .
                                        ata actuallymean kore string er sesh character 
                                        
                                        ata dissi koran bujh jodi pass ai arr tay last point indicate na koro taile to ar onno element gula garbage val hold korte pare 
                                        taile to pass corrcet dileo bar bar vul val print shuru kori dibe
                                        
                                        
                                        */    


                    break ;
                }
                else if(ch==BACKSPACE)
                {
                    if(i>0)
                    {
                        i--;
                        printf("\b \b"); //Best part...
                         /*
                         say pass hobe 1234  but tumi vule diso 1235  akhon atake fix korar jnno backspace diba right?
                         jei matro back space diba cursor 1235 ..5 er por theke 5 er shamne chole ashbe then akta space dibe but cursor space er age ante chai tai next \b ta space er age cursor k anbe ..taile kahimi hoitese kisuta : 1235 =>  123|   |+>cursor oikhane ase...akhon 4 chaple => 1234 hoilo so pass icca moto dynamically cahnge korte parteso

                         r i-- korsse karon  1235 ..4 ta char.....back space dile akta kome jay tai 3 korte i--- kora lagbe

                         */

                    }
                }   

                else if(ch==TAB||ch==SPACE)
                {
                    continue;  
                    /*
                       pass er moddhe space tab aglak count korte chaini alada or special char hishebe ..
                       just to ignore them tai ai check ta disi
                    */
                }
                else
                {
                    password[i]=ch;
                    i++;            // pass er char or element joto barbe , i o toto barbe 
                                    //cz we need to find the length of pass arr
                    printf("*");  // pass jno onno kau dekhte na pare.
                                  // To maintain privacy ata disi
                                  

                }
                
            }
        
            
            /*
                user corerct pass dise kina ata check korbe ai khane na
                jodi correct pass dao , taile flag 1 hoye jabe 

                ata basically passs check box

            */
            if(strcmp  (inputPassword,password)  ==0 )
            flag2=1;

            
                
                //Flag1 and flag2 =1 mane user correct pass and username dise
                //So he is allowed to proceed:
                if(flag1==1 && flag2==1)   
                {
                    

                        /*
                            User correct pass and usr dise so or shob data j file e ase ota age open korte hobe
                            then shob data oikhan theke scan kore user1 var e load korte hobe 
                            then file ta close kore rakhbe

                            akhon furthermore ticket book koro na cancel koro shob ai user var er data k kaje lagay korba
                            jodi kno update koro tahole 1st e  user1 var er data update korba
                            then seshe jeye shob data user er nijer file a print kore dibe


                        */
                        //Loading user info in structure:
                        fflush(stdin);
                        FILE* fpN = fopen(filename,"r");

                        fscanf(fpN,"First Name : %s\nLast Name : %s\nUsername : %s\nPassword : %s\nMobile Number : %s\nTicket Count: %d\nPrice : %lf\n\nTicket 1 : \n   BusSelected : %d \n   SeatNumber : %d\n     Location : %s\nTicket 2 : \n   BusSelected : %d \n   SeatNumber : %d\n      Location : %s\nTicket 3 : \n   BusSelected : %d \n   SeatNumber : %d\n      Location : %s\nTicket 4 : \n   BusSelected : %d \n   SeatNumber : %d\n      Location : %s",user1.FirstName,user1.LastName,user1.UserName,user1.Password,user1.MobileNo,&user1.TicketCOunt,&user1.price,&user1.ticket[0].BusSelection,&user1.ticket[0].SeatNumber,user1.ticket[0].Location,&user1.ticket[1].BusSelection,&user1.ticket[1].SeatNumber,user1.ticket[1].Location,&user1.ticket[2].BusSelection,&user1.ticket[2].SeatNumber,user1.ticket[2].Location,&user1.ticket[3].BusSelection,&user1.ticket[3].SeatNumber,user1.ticket[3].Location);


                        fclose(fpN);

                        system("cls");
                         printf("\n______________________________________________________________________________________________________________________________________________________________________________________________________________\n");
                            printf("\n                                                                                       LOGIN SUCCESSFULL\n");
                            printf("______________________________________________________________________________________________________________________________________________________________________________________________________________\n");
                        
                            printf("\n\n");

                            
                            printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                            printf("                                                                                 WELCOME TO IUT TRANSPORT SERVICE\n");
                            printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

                            printf("\n\n\n\n\n\n __________________________________________________________________________________Returning to the main menu__________________________________________________________________________________________________\n"); 
                    
                        Sleep(1500);
                             //Freezes the system for 1500 ms 


                        break;
                }
                else
                {  
                    
                     //User vul val pass ba user dile count down hobe then abar scope dibe login korar

                    for(int i=3;i>=1;i--)
                    { 
                    system("cls");   
                    
                    printf("\n______________________________________________________________________________________________________________________________________________________________________________________________________________\n");
                    printf("\n\n\n                                                                                   <Invalid Username Or Password>\n\n\n                                                                                         Try again in [%d]\n",i);
                    printf("\n_______________________________________________________________________________________________________________________________________________________________________________________________________________\n");
                    
                    Sleep(800);
                    }
                system("cls"); 
          
                }
    }


    return user1;

    // Ai j data ta return korbe baki kaj atar opor base kore hobe
    // 
}
