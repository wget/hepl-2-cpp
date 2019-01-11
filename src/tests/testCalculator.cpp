#include <iostream>
#include <fstream>
using namespace std;
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#include "../Calculator.hpp"

//***** Gestion saisie ********************************************************
#define KEY_DOWN   20
#define KEY_UP     21
#define KEY_LEFT   22
#define KEY_RIGHT  23
#define KEY_ENTER  24

struct termios Term,SaveTerm;
int SortieIoctl(int Code);
int ReadChar();
//*****************************************************************************

int main(int argc,char* argv[])
{
  char tmp[10];
  bool fini = false;

  Calculator calculette;
  
  while(!fini)
  {
    calculette.display();
    cout << "Touches : 0...9    --> saisie chiffre" << endl;
    cout << "          [enter]  --> fin de saisie" << endl;
    cout << "          c        --> clear (vide la saisie --> transfert vers pile)" << endl;
    cout << "          + - * /  --> operations" << endl;
    cout << "          o        --> oppose (+/-)" << endl;
    cout << "          m        --> change mode (Fractionnaire/Numerique)" << endl;
    cout << "          e        --> erase (vide la pile)" << endl;
    cout << "          q        --> quitter" << endl;
    cout << ">>>" << flush;
    char lu = ReadChar();
    switch(lu)
    {
      case 'q' : fini = true;
                 break;

      case '0' :
      case '1' :
      case '2' :
      case '3' :
      case '4' :
      case '5' :
      case '6' :
      case '7' :
      case '8' :
      case '9' : sprintf(tmp,"%c",lu);
                 calculette.inputNumber(atoi(tmp));
                 break;

      case 'c' : calculette.clearInput();
                 break;

      case KEY_ENTER : calculette.enter();
                       break;

      case 'o' : calculette.plusOrMinus();
                 break;

      case '+' : calculette.plus();
                 break;

      case '-' : calculette.minus();
                 break;

      case '*' : calculette.multiply();
                 break;

      case '/' : calculette.divide();
                 break;

      case 'm' : calculette.changeMode();
                 break;

      case 'e' : calculette.erase();
                 break;
    }
  }

  return 0;
}

//***************************************************************************************
int ReadChar()
{
   char ChLu;
   
   if (tcgetattr(0,&Term) == -1) return -1;
   SaveTerm = Term;
   Term.c_lflag &= ~(ICANON | ECHO | ISIG);
   Term.c_cc[VMIN] = 1;
   
   if (tcsetattr(0,TCSANOW,&Term) == -1) return -1;
   
   fflush(stdin);
   
   if (read(0,&ChLu,1) != 1) return SortieIoctl(-1);
   if (ChLu == Term.c_cc[VINTR]) return SortieIoctl(3);
   if (ChLu == 10) return SortieIoctl(KEY_ENTER);
   if (ChLu == '\033')
   {
      if (read(0,&ChLu,1) == 1)
      {
         if ((char)ChLu == '[')
         {
            if (read(0,&ChLu,1) != 1) return SortieIoctl(-1);
            if ((char)ChLu == 'A') return SortieIoctl(KEY_UP);
            if ((char)ChLu == 'B') return SortieIoctl(KEY_DOWN);
            if ((char)ChLu == 'C') return SortieIoctl(KEY_RIGHT);
            if ((char)ChLu == 'D') return SortieIoctl(KEY_LEFT);   
            return SortieIoctl(-1);
         }          
      }
   }
   
   return SortieIoctl(ChLu);
} 

int SortieIoctl(int Code)
{
   if (tcsetattr(0,TCSANOW,&SaveTerm) == -1) return -1;
   return Code;
} 
