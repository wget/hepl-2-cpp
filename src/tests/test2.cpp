#include <stdlib.h>
#include <iostream>
using namespace std;

#include "Couleur.h"
#include "Panneau.h"

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
  cout << " 1. Tests de la classe Couleur" << endl;
  cout << " 2. Tests de la classe Panneau (avec agregation par valeur avec Couleur)" << endl;
  cout << " 3. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  return ch;
}

//*******************************************************************************************************
//*** Tests de la classe Couleur ************************************************************************
//*******************************************************************************************************
void Essai1()
{
  cout << endl << "(1) ***** Test constructeur par defaut + Affiche *******************************************" << endl;
  {
    Couleur couleur;
    couleur.Affiche();
  }

  cout << endl << "(2) ***** Test des setters et getters ******************************************************" << endl;
  {
    Couleur couleur;
    couleur.setRouge(255);
    couleur.setVert(255);
    couleur.setBleu(0);
    couleur.setNom("jaune");
    couleur.Affiche();
    cout << "Rouge = " << couleur.getRouge() << endl;
    cout << "Vert = " << couleur.getVert() << endl;
    cout << "Bleu = " << couleur.getBleu() << endl;
    cout << "Nom = " << couleur.getNom() << endl;
  }

  cout << endl << "(3) ***** Test du constructeur d'initialisation complet ************************************" << endl;
  {
    Couleur couleur(0,0,128,"Navy");
    couleur.Affiche();
  }

  cout << endl << "(4) ***** Test du constructeur d'initialisation partiel ************************************" << endl;
  {
    Couleur couleur(30,250,5);
    couleur.Affiche();
    couleur.setNom("Vert grenouille");
    couleur.Affiche();
  }

  cout << endl << "(5) ***** Test du constructeur d'initialisation + setter pour gris *************************" << endl;
  {
    Couleur couleur(128);   // Gris : rouge = vert = bleu = 128
    couleur.Affiche();
    couleur.setGris(192);   // Gris : rouge = vert = bleu = 192
    couleur.Affiche();
  }

  cout << endl << "(6) ***** Test du constructeur de copie ****************************************************" << endl;
  {
    Couleur couleur1(255,0,0,"rouge");
    cout << "couleur1 (AVANT) :" << endl;
    couleur1.Affiche();
    {   
      Couleur couleur2(couleur1);
      cout << "couleur2 :" << endl;
      couleur2.Affiche();
      cout << "--> on modifie la copie" << endl;
      couleur2.setBleu(255);
      couleur2.setNom("violet");
      couleur2.Affiche();
      cout << "--> on detruit la copie" << endl;
    } // de nouveau, les {} assurent que couleur2 sera detruit avant la suite
    cout << "couleur1 (APRES) :" << endl;
    couleur1.Affiche();
  }

  cout << endl << "(7) ***** Tests de base des objets statiques ***********************************************" << endl;
  Couleur::ARGENT.Affiche(); // ARGENT est un objet de la classe Couleur, il possede donc la methode Affiche()
  Couleur::BLEU.Affiche();
  cout << endl;

  //Couleur::BLEU.setNom("Mauve"); // --> ne compile pas car l'objet BLEU est un objet constant (voir enonce) !!!

  cout << endl << "(8) ***** Copie des objets statiques *******************************************************" << endl;
  Couleur c(Couleur::BLEU);
  c.Affiche();
  c.setVert(255);   // compile car c n'est pas un objet constant
  c.setNom("Cyan");
  c.Affiche();
  cout << endl;

}

//*************************************************************************************************
//*** Tests de la classe Panneau + agregation par valeur avec Couleur ***************************** 
//*************************************************************************************************
void Essai2()
{
  cout << endl << "(1) ***** Test des anciens constructeurs de Panneau *************************************" << endl;
  { // Par defaut, un panneau possede la couleur ARGENT
    // mais les signatures des constructeurs du jeu de tests 1 n'ont pas changé
    Panneau p1;
    p1.Affiche();

    Panneau p2("P01",20,40,400,200);
    p2.Affiche();
  }

  cout << endl << "(2) ***** Test du nouveau constructeur d'initialisation ********************************" << endl;
  { 
    Couleur c(255,0,0);
    Panneau p1("P02",50,20,150,150,c);
    p1.Affiche();
    
    Panneau p2("P03",70,30,300,200,Couleur::BLEU);
    p2.Affiche();
  }

  cout << endl << "(3) ***** Test du constructeur de copie + setters/getters ******************************" << endl;
  { 
    Panneau p("P04",30,30,400,250,Couleur(160));
    cout << "Voici p : " << endl;
    p.Affiche();
    cout << "Sa couleur est : ";
    p.getCouleur().Affiche();
    {
      Panneau p2(p);
      cout << endl << "Voici la copie p2 : " << endl;
      p2.Affiche();
      cout << "On modifie la couleur et le nom de p2 :" << endl;
      p2.setCouleur(Couleur(255,0,0,"Rouge"));
      p2.setNom("P05");
      p2.Affiche();
      cout << "La copie p2 est détruite..." << endl;
    }
    cout << endl << "Re-voici p : " << endl;
    p.Affiche();
    cout << "Et sa couleur est : ";
    p.getCouleur().Affiche();
  }
}

