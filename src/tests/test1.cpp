#include <stdlib.h>
#include <iostream>
using namespace std;
#include "Panneau.h"

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

  cout << endl << "(1) ***** Test constructeur par defaut + Affiche *******************************************" << endl;
  {
    Panneau panneau;
    panneau.Affiche();
  } // La presence des accolades assure que le destructeur de Joueur sera appele --> a tracer !

  cout << endl << "(2) ***** Test des setters et getters ******************************************************" << endl;
  {
    Panneau panneau;
    panneau.setX(10);
    panneau.setY(50);
    panneau.setLargeur(150);
    panneau.setHauteur(100);
    panneau.setNom("P01");
    panneau.Affiche();
    cout << "Nom = " << panneau.getNom() << endl;
    cout << "x = " << panneau.getX() << endl;
    cout << "y = " << panneau.getY() << endl;
    cout << "Largeur = " << panneau.getLargeur() << endl;
    cout << "Hauteur = " << panneau.getHauteur() << endl;
  }

  cout << endl << "(3) ***** Test du constructeur d'initialisation ********************************************" << endl;
  {
    Panneau panneau("P02",30,45,300,200);
    panneau.Affiche();
  }

  cout << endl << "(4) ***** Test du constructeur de copie ****************************************************" << endl;
  {
    Panneau panneau1("P03",10,10,200,200);
    cout << "panneau1 (AVANT) :" << endl;
    panneau1.Affiche();
    {   
      Panneau panneau2(panneau1);
      cout << "panneau2 :" << endl;
      panneau2.Affiche();
      cout << "--> on modifie la copie" << endl;
      panneau2.setX(150);
      panneau2.setNom("P04");
      panneau2.Affiche();
      cout << "--> on detruit la copie" << endl;
    } // de nouveau, les {} assurent que panneau2 sera detruit avant la suite
    cout << "panneau1 (APRES) :" << endl;
    panneau1.Affiche();
  }

  cout << endl << "(5) ***** Test d'allocation dynamique ******************************************************" << endl;
  {
    Panneau *p = new Panneau();
    p->Affiche();
    delete p;
    p = new Panneau("P05",0,0,120,70);
    p->setNom("P07");
    p->Affiche();
    delete p;
  }

  return 0;
}


