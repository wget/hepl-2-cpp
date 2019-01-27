#include <iostream>
using namespace std;

#include "../Window.hpp"
#include "../Panel.hpp"
#include "../Button.hpp"
#include "../ImagePanel.hpp"
#include "../ImageButton.hpp"

#include "../WindowSDL/WindowSDL.hpp" // pour waitClick

int main(int argc,char* argv[])
{
  Window fenetre(600,400,Color(192));

  Panel p1("P01",30,60,120,90,Color(255,0,0));
  Button  b1("B01",200,60,40,40,Color::BLUE);
  ImagePanel p2("P02",40,200,"./images/3.bmp");
  ImageButton b2("B02",210,170,"./images/button_enter.bmp");

  fenetre.setVisible(true);
  fenetre.draw();
  p1.draw();
  b1.draw();
  p2.draw();
  b2.draw();

  cout << "Cliquez dans la fenetre..." << endl;
  WindowSDLclick clic = WindowSDL::waitClick();
  if (clic.getX() == -1) cout << "Clic sur croix de fenetre..." << endl;
  else
  { // A-t-on cliqué sur un bouton ?
    b1.click(clic.getX(),clic.getY());
    b2.click(clic.getX(),clic.getY());
  }

  fenetre.setVisible(false);

  return 0;
}


