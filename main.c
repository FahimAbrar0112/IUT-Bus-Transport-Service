
#include"header.h"

// #include"book.c"
// #include"BusList.c"
// //#include"CancelTicket.c"
// #include"CarRental.c"
// #include"Login.c"
// #include"look_LOGIN_SIGNUP.c"
// #include"look_Menu.c"
// #include"MenuBar.c"
// #include"Signup.c"
// #include"TicketPrice.c"




User user;



int main(void)
{
    
   
   user=look_LOGIN_SIGNUP();
  
   
   MenuBar(user);
    
  
   getch();

    
    return 0;
}