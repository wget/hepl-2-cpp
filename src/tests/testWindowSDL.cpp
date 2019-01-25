#include <iostream>
using namespace std;

#include "../WindowSDL/WindowSDL.hpp"

//************************************************************************************************
int main(int argc,char* argv[])
{
  cout << "Hello WindowSDL !" << endl;

  WindowSDL::open(500,300);
  WindowSDL::setBackground(128,128,128);

  WindowSDL::fillRectangle(200,190,100,10,20,300,100);
  WindowSDL::fillRectangle(0,0,255,270,180,60,100);

  WindowSDLimage un("../images/1.bmp");
  WindowSDLimage deux("../images/2.bmp");
  WindowSDL::drawImage(un,20,170);
  WindowSDL::drawImage(deux,180,230);

  cout << "Cliquez pour quitter..." << endl;
  WindowSDLclick clic = WindowSDL::waitClick();
  if (clic.getX() == -1) cout << "Clic sur la croix..." << endl;
  else cout << "Clic en (" << clic.getX() << "," << clic.getY() << ")" << endl;

  WindowSDL::close();

  return 0;
}


