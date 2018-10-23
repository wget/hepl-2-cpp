#include <stdlib.h>
#include <iostream>

#include "../Panel.hpp"

using namespace std;

// Quelques conseils avant de commencer...
// * N'oubliez pas de tracer (cout << ...) tous les constructeurs et le destructeur !!! Ca, c'est pas un conseil,
//   c'est obligatoire :-)
// * N'essayez pas de compiler ce programme entierement immediatement. Mettez tout en commentaires
//   sauf le point (1) et creez votre classe (dans ce fichier pour commencer) afin de compiler et tester 
//   le point (1). Une fois que cela fonctionne, decommentez le point (2) et modifier votre classe en 
//   consequence. Vous developpez, compilez et testez donc etape par etape. N'attendez pas d'avoir encode 
//   300 lignes pour compiler...
// * Une fois que tout le programme compile et fonctionne correctement, creez le .h contenant la declaration
//   de la classe, le .cxx contenant la definition des methodes, et ensuite le makefile permettant de compiler
//   le tout grace a la commande make 

int main()
{

  cout << endl << "(1) ***** Test constructeur par defaut + display *******************************************" << endl;
  {
    Panel panneau;
    panneau.display();
  } // La presence des accolades assure que le destructeur de Joueur sera appele --> a tracer !

  cout << endl << "(2) ***** Test des setters et getters ******************************************************" << endl;
  {
    Panel panneau;
    panneau.setX(10);
    panneau.setY(50);
    panneau.setWidth(150);
    panneau.setHeight(100);
    panneau.setName("P01");
    panneau.display();
    cout << "Nom = " << panneau.getName() << endl;
    cout << "x = " << panneau.getX() << endl;
    cout << "y = " << panneau.getY() << endl;
    cout << "Largeur = " << panneau.getWidth() << endl;
    cout << "Hauteur = " << panneau.getHeight() << endl;
  }

  cout << endl << "(3) ***** Test du constructeur d'initialisation ********************************************" << endl;
  {
    Panel panneau("P02",30,45,300,200);
    panneau.display();
  }

  cout << endl << "(4) ***** Test du constructeur de copie ****************************************************" << endl;
  {
    Panel panneau1("P03",10,10,200,200);
    cout << "panneau1 (AVANT) :" << endl;
    panneau1.display();
    {   
      Panel panneau2(panneau1);
      cout << "panneau2 :" << endl;
      panneau2.display();
      cout << "--> on modifie la copie" << endl;
      panneau2.setX(150);
      panneau2.setName("P04");
      panneau2.display();
      cout << "--> on detruit la copie" << endl;
    } // de nouveau, les {} assurent que panneau2 sera detruit avant la suite
    cout << "panneau1 (APRES) :" << endl;
    panneau1.display();
  }

  cout << endl << "(5) ***** Test d'allocation dynamique ******************************************************" << endl;
  {
    Panel *p = new Panel();
    p->display();
    delete p;
    p = new Panel("P05",0,0,120,70);
    p->setName("P07");
    p->display();
    delete p;
  }

  return 0;
}


