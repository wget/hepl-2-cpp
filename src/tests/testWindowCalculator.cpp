#include <iostream>
using namespace std;

#include "../WindowCalculator.hpp"
#include "../WindowSDL/WindowSDL.hpp"

//************************************************************************************************
int main(int argc,char* argv[])
{
  WindowCalculator fenetre;

  fenetre.setVisible(true);
  fenetre.draw();
  WindowSDL::waitClick();
  fenetre.setVisible(false);

  return 0;
}

