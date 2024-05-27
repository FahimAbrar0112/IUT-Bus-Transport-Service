
#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
#include<conio.h>
#include<math.h>
#include<windows.h>



//For User:
typedef struct seatNo_with_busNo
{
     int SeatNumber;
     int BusSelection;
     char Location[100];
}Ticket;
typedef struct Passeenger 
{
    char FirstName[100];
    char LastName[100];
    char UserName[100];
    char Password[100]; 
    char MobileNo[100];
    int TicketCOunt;
    double price;
    
    Ticket ticket[4];       //Kon kon bus er kon kon seat katbe track korar jnno

    
}User;

//For Location And Price HAndeling:

typedef struct LocationANdPrice
{
    double price;
    char location[100];
}LocationANdPrice;



User look_LOGIN_SIGNUP();
User Signup();
User  Login(void);
void Look_Menu();
User boookTicket(User user1);
LocationANdPrice locationANDprice(int select_From_to_IUT );
void BusList();
void BusLocations();
void MenuBar(User user);
void CarRental(User user1);


//New:
User CancelTicket( User user1);
double locationANDpriceForCanel();