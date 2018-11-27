#include <stdlib.h>
#include <iostream>
using namespace std;

#include "../Color.hpp"
#include "../Panel.hpp"

int  Menu();
void Essai1();
void Essai2();

int main(int argc,char* argv[])
{
  int choix;
  bool fini = false;
  
  while(!fini)
  {
    if (argc == 2) { choix = atoi(argv[1]); fini = true; }
    else choix = Menu();
    switch(choix)
    {
      case 1 : Essai1(); break;
      case 2 : Essai2(); break;
      default : fini = true ; break;
    }
  }

  return 0;
}

//*******************************************************************************************************
int Menu()
{
  cout << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TESTS 2 -------------------------------------------------------------------" << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << " 1. Tests de la classe Color" << endl;
  cout << " 2. Tests de la classe Panel (avec agregation par valeur avec Color)" << endl;
  cout << " 3. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  return ch;
}

//*******************************************************************************************************
//*** Tests de la classe Color ************************************************************************
//*******************************************************************************************************
void Essai1()
{
  cout << endl << "(1) ***** Test constructeur par defaut + display *******************************************" << endl;
  {
    Color couleur;
    couleur.display();
  }

  cout << endl << "(2) ***** Test des setters et getters ******************************************************" << endl;
  {
    Color couleur;
    couleur.setRed(255);
    couleur.setGreen(255);
    couleur.setBlue(0);
    couleur.setName("jaune");
    couleur.display();
    cout << "Rouge = " << couleur.getRed() << endl;
    cout << "Vert = " << couleur.getGreen() << endl;
    cout << "Bleu = " << couleur.getBlue() << endl;
    cout << "Nom = " << couleur.getName() << endl;
  }

  cout << endl << "(3) ***** Test du constructeur d'initialisation complet ************************************" << endl;
  {
    Color couleur(0,0,128,"Navy");
    couleur.display();
  }

  cout << endl << "(4) ***** Test du constructeur d'initialisation partiel ************************************" << endl;
  {
    Color couleur(30,250,5);
    couleur.display();
    couleur.setName("Vert grenouille");
    couleur.display();
  }

  cout << endl << "(5) ***** Test du constructeur d'initialisation + setter pour gris *************************" << endl;
  {
    Color couleur(128);   // Gris : rouge = vert = bleu = 128
    couleur.display();
    couleur.setGrey(192);   // Gris : rouge = vert = bleu = 192
    couleur.display();
  }

  cout << endl << "(6) ***** Test du constructeur de copie ****************************************************" << endl;
  {
    Color couleur1(255,0,0,"rouge");
    cout << "couleur1 (AVANT) :" << endl;
    couleur1.display();
    {   
      Color couleur2(couleur1);
      cout << "couleur2 :" << endl;
      couleur2.display();
      cout << "--> on modifie la copie" << endl;
      couleur2.setBlue(255);
      couleur2.setName("violet");
      couleur2.display();
      cout << "--> on detruit la copie" << endl;
    } // de nouveau, les {} assurent que couleur2 sera detruit avant la suite
    cout << "couleur1 (APRES) :" << endl;
    couleur1.display();
  }

  cout << endl << "(7) ***** Tests de base des objets statiques ***********************************************" << endl;
  Color::SILVER.display(); // ARGENT est un objet de la classe Color, il possede donc la methode display()
  Color::BLUE.display();
  cout << endl;

  //Color::BLUE.setName("Mauve"); // --> ne compile pas car l'objet BLUE est un objet constant (voir enonce) !!!

  cout << endl << "(8) ***** Copie des objets statiques *******************************************************" << endl;
  Color c(Color::BLUE);
  c.display();
  c.setGreen(255);   // compile car c n'est pas un objet constant
  c.setName("Cyan");
  c.display();
  cout << endl;

}

//*************************************************************************************************
//*** Tests de la classe Panel + agregation par valeur avec Color ***************************** 
//*************************************************************************************************
void Essai2()
{
  cout << endl << "(1) ***** Test des anciens constructeurs de Panel *************************************" << endl;
  { // Par defaut, un panneau possede la couleur ARGENT
    // mais les signatures des constructeurs du jeu de tests 1 n'ont pas changé
    Panel p1;
    p1.display();

    Panel p2("P01",20,40,400,200);
    p2.display();
  }

  cout << endl << "(2) ***** Test du nouveau constructeur d'initialisation ********************************" << endl;
  { 
    Color c(255,0,0);
    Panel p1("P02",50,20,150,150,c);
    p1.display();
    
    Panel p2("P03",70,30,300,200,Color::BLUE);
    p2.display();
  }

  cout << endl << "(3) ***** Test du constructeur de copie + setters/getters ******************************" << endl;
  { 
    Panel p("P04",30,30,400,250,Color(160));
    cout << "Voici p : " << endl;
    p.display();
    cout << "Sa couleur est : ";
    p.getColor().display();
    {
      Panel p2(p);
      cout << endl << "Voici la copie p2 : " << endl;
      p2.display();
      cout << "On modifie la couleur et le nom de p2 :" << endl;
      p2.setColor(Color(255,0,0,"Rouge"));
      p2.setName("P05");
      p2.display();
      cout << "La copie p2 est détruite..." << endl;
    }
    cout << endl << "Re-voici p : " << endl;
    p.display();
    cout << "Et sa couleur est : ";
    p.getColor().display();
  }
}

