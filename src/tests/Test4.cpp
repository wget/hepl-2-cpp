#include <stdlib.h>
#include <iostream>
using namespace std;
#include <time.h>

#include "Panneau.h"
#include "PanneauImage.h"
#include "Bouton.h"
#include "BoutonImage.h"

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();
void Essai5();
void Essai6();

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
      case 3 : Essai3(); break;
      case 4 : Essai4(); break;
      case 5 : Essai5(); break;
      case 6 : Essai6(); break;
      default : fini = true ; break;
    }
  }

  return 0;
}

int Menu()
{
  cout << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 4 ----------------------------------------------------------" << endl;
  cout << "----------------------------------------------------------------------------" << endl;
  cout << " 1. Test de la classe PanneauImage" << endl;
  cout << " 2. Test de la classe Bouton" << endl;
  cout << " 3. Test de la classe BoutonImage" << endl;
  cout << " 4. Heritage et virtualite : Test de la methode NON-VIRTUELLE Affiche()" << endl;
  cout << " 5. Heritage et virtualite : Test de la methode VIRTUELLE getType()" << endl;
  cout << " 6. Test du downcasting et du dynamic-cast" << endl;
  cout << " 7. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

//***********************************************************************************************
// A FAIRE : - la classe PanneauImage qui herite de Panneau
//           - qui possede en plus une chaine de caracteres fichier
//           - redefinir les operateurs =, << et >> de PanneauImage
//***********************************************************************************************
//*** Tests de la classe PanneauImage ***********************************************************
//***********************************************************************************************
void Essai1()
{
  cout << "(1.1) ***** Test du constructeur par defaut + setters de PanneauImage ***************" << endl;
  { 
    PanneauImage p;
    cout << "p = " << p << endl;
    cout << "--> modification de p" << endl;
    p.setX(20);
    p.setY(40);
    p.setFichier("fleche.bmp");
    cout << "p = " << p << endl << endl;
  }

  cout << "(1.2) ***** Test du constructeur d'initialisation + getters de PanneauImage *********" << endl;
  { 
    PanneauImage p("P01",30,40,"warning.bmp");
    cout << "p = " << p << endl;
    cout << "Position de p = (" << p.getX() << "," << p.getY() << ")" << endl;
    cout << "Fichier de p  = " << p.getFichier() << endl << endl;
  }

  cout << "(1.3) ***** Test du constructeur de copie de PanneauImage ***************************" << endl;
  {
    PanneauImage *pp = new PanneauImage("P02",45,60,"photoDenys.bmp");
    cout << "Objet de base = " << *pp << endl;

    PanneauImage p(*pp);
    cout << "--> Destruction objet de base" << endl;
    delete pp;
    cout << "Copie = " << p << endl << endl; 
  }

  cout << "(1.4) ***** Test de l'operateur = de PanneauImage ***********************************" << endl;
  {
    PanneauImage *pp = new PanneauImage("P02",45,60,"photoDenys.bmp");
    cout << "Objet de base = " << *pp << endl;

    PanneauImage p;
    p = *pp;
    cout << "--> Destruction objet de base" << endl;
    delete pp;
    cout << "Objet affecte = " << p << endl << endl;     
  }

  cout << "(1.5) ***** Test de l'operateur >> de PanneauImage **********************************" << endl;
  {
    PanneauImage p;
    cin >> p;
    cout << "--> p = " << p << endl << endl;
  }
}

//***********************************************************************************************
// A FAIRE : - la classe Bouton qui herite de Panneau
//           - qui possede en plus une methode d'instance clic
//           - redefinir les operateurs =, << et >> de Bouton
//***********************************************************************************************
//*** Tests de la classe Bouton *****************************************************************
//***********************************************************************************************
void Essai2()
{
  cout << "(2.1) ***** Test du constructeur par defaut + setters de Bouton *********************" << endl;
  { 
    Bouton b;;
    cout << "b = " << b << endl;
    cout << "--> modification de b" << endl;
    b.setX(20);
    b.setY(40);
    b.setCouleur(Couleur(120,120,60));
    cout << "b = " << b << endl << endl;
  }

  cout << "(2.2) ***** Test du constructeur d'initialisation complet + getters de Bouton *******" << endl;
  { 
    Bouton b("B01",30,40,50,50,Couleur::ARGENT);
    cout << "b = " << b << endl;
    cout << "Position de b = (" << b.getX() << "," << b.getY() << ")" << endl;
    cout << "Couleur de b  = " << b.getCouleur() << endl << endl;
  }

  cout << "(2.3) ***** Test du constructeur de copie de Bouton *********************************" << endl;
  {
    Bouton *pb = new Bouton("B02",45,60,50,50);
    cout << "Objet de base = " << *pb << endl;

    Bouton b(*pb);
    cout << "--> Destruction objet de base" << endl;
    delete pb;
    cout << "Copie = " << b << endl << endl; 
  }

  cout << "(2.4) ***** Test de l'operateur = de Bouton *****************************************" << endl;
  {
    Bouton *pb = new Bouton("B03",10,10,60,60,Couleur(128,128,128));
    cout << "Objet de base = " << *pb << endl;

    Bouton b;
    b = *pb;
    cout << "--> Destruction objet de base" << endl;
    delete pb;
    cout << "Objet affecte = " << b << endl << endl;     
  }

  cout << "(2.5) ***** Test de l'operateur >> et de la methode clic de Bouton ******************" << endl;
  {
    Bouton b;
    cin >> b;
    cout << "--> b = " << b << endl << endl;
    int x,y;
    cout << "clic X = "; cin >> x;
    cout << "clic Y = "; cin >> y;
    cout << "Test de clic : ";
    b.clic(x,y);
    cout << endl;
  }
}

//***********************************************************************************************
// A FAIRE : - la classe BoutonImage qui herite de PanneauImage ET de Bouton
//           - redefinir les operateurs =, << et >> de BoutonImage
//***********************************************************************************************
//*** Tests de la classe BoutonImage ************************************************************
//***********************************************************************************************
void Essai3()
{
  cout << "(3.1) ***** Test du constructeur par defaut + setters de BoutonImage *****************" << endl;
  { 
    BoutonImage b;
    cout << "b = " << b << endl;
    cout << "--> modification de b" << endl;
    b.setX(20);
    b.setY(40);
    b.setFichier("boutonPlus.bmp");   // Methode heritee de PanneauImage
    cout << "b = " << b << endl << endl;
  }

  cout << "(3.2) ***** Test du constructeur d'initialisation + getters de BoutonImage ***********" << endl;
  { 
    BoutonImage b("B01",30,40,"boutonMoins.bmp");
    cout << "b = " << b << endl;
    cout << "Position de b = (" << b.getX() << "," << b.getY() << ")" << endl;
    cout << "Fichier de b  = " << b.getFichier() << endl << endl;   // Methode heritee de PanneauImage
  }

  cout << "(3.3) ***** Test du constructeur de copie de BoutonImage ***************************" << endl;
  {
    BoutonImage *pb = new BoutonImage("B02",45,60,"boutonCancel.bmp");
    cout << "Objet de base = " << *pb << endl;

    BoutonImage b(*pb);
    cout << "--> Destruction objet de base" << endl;
    delete pb;
    cout << "Copie = " << b << endl << endl; 
  }

  cout << "(3.4) ***** Test de l'operateur = de BoutonImage ***********************************" << endl;
  {
    BoutonImage *pb = new BoutonImage("B03",35,70,"boutonQuitter.bmp");
    cout << "Objet de base = " << *pb << endl;

    BoutonImage b;
    b = *pb;
    cout << "--> Destruction objet de base" << endl;
    delete pb;
    cout << "Objet affecte = " << b << endl << endl;     
  }

  cout << "(3.5) ***** Test de l'operateur >> et de la methode clic de BoutonImage ************" << endl;
  {
    BoutonImage b;
    cin >> b;
    cout << "--> b = " << b << endl << endl;
    int x,y;
    cout << "clic X = "; cin >> x;
    cout << "clic Y = "; cin >> y;
    cout << "Test de clic : ";
    b.clic(x,y);   // Methode heritee de Bouton
    cout << endl;
  }
}

//***********************************************************************************************
// A FAIRE : normalement rien...
//           juste comprendre et tester le code ci-dessous
//***********************************************************************************************
//*** Tests de la non-virtualite ****************************************************************
//***********************************************************************************************
void Essai4()
{
  srand((unsigned)time(NULL));

  cout << "----- 4.1 Allocation dynamique de Panneaux ------------------------------------------------" << endl;
  Panneau* panneau[10];

  for (int i=0 ; i<10 ; i++)   // Tracez vos constructeurs !!!
  {
    cout << "panneau[" << i << "] : ";
    int n = rand()%4;
    switch(n)
    {
      case 0 : panneau[i] = new Panneau("P01",10,10,300,200,Couleur::ARGENT);
               cout << "Panneau" << endl;
               break;

      case 1 : panneau[i] = new PanneauImage("P02",30,30,"PhotoAnne.bmp");
               cout << "PanneauImage" << endl;
               break;

      case 2 : panneau[i] = new Bouton("B03",40,40,50,50);
               cout << "Bouton" << endl;
               break;

      case 3 : panneau[i] = new BoutonImage("B04",70,70,"boutonClear.bmp");
               cout << "BoutonImage" << endl;
               break;
    }
  }
  cout << endl;

  cout << "----- 4.2 Test de la methode NON-VIRTUELLE Affiche() (redefinie dans chaque classe heritee) -------" << endl;
  for (int i=0 ; i<10 ; i++)
  {
    cout << "panneau[" << i << "] : "; // << forme[i]->getInfos() << endl;
    panneau[i]->Affiche();
  }
  cout << endl;

  
  cout << "----- 4.3 Liberation memoire --------------------------------------------------------------" << endl;
  for (int i=0 ; i<10 ; i++) delete panneau[i];  // Tout se passe-t-il comme vous voulez ?
  // Pour etre plus precis, quid des destructeurs et de la virtualite ?
}

//***********************************************************************************************
// A FAIRE : la methode VIRTUELLE getType() dans Panneau, PanneauImage, Bouton et BoutonImage
//***********************************************************************************************
//*** Tests de la virtualite ********************************************************************
//***********************************************************************************************
void Essai5()
{
  srand((unsigned)time(NULL));

  cout << "----- 5.1 Allocation dynamique de Panneaux ------------------------------------------------" << endl;
  Panneau* panneau[10];

  for (int i=0 ; i<10 ; i++)   // Tracez vos constructeurs !!!
  {
    cout << "panneau[" << i << "] : ";
    int n = rand()%4;
    switch(n)
    {
      case 0 : panneau[i] = new Panneau("P01",10,10,300,200,Couleur::ARGENT);
               cout << "Panneau" << endl;
               break;

      case 1 : panneau[i] = new PanneauImage("P02",30,30,"PhotoAnne.bmp");
               cout << "PanneauImage" << endl;
               break;

      case 2 : panneau[i] = new Bouton("B03",40,40,50,50);
               cout << "Bouton" << endl;
               break;

      case 3 : panneau[i] = new BoutonImage("B04",70,70,"boutonClear.bmp");
               cout << "BoutonImage" << endl;
               break;
    }
  }
  cout << endl;

  cout << "----- 5.2 Test de la methode VIRTUELLE getType() (redefinie dans chaque classe heritee) -------" << endl;
  for (int i=0 ; i<10 ; i++)
  {
    cout << "panneau[" << i << "] : " << panneau[i]->getType() << endl;
  }
  cout << endl;

  
  cout << "----- 5.3 Liberation memoire ---------------------------------------------------------------" << endl;
  for (int i=0 ; i<10 ; i++) delete panneau[i];  // Tout se passe-t-il comme vous voulez ?
  // Pour etre plus precis, quid des destructeurs et de la virtualite ?
}

//***********************************************************************************************
// A FAIRE : normalement rien dans vos classes...
//           juste comprendre et tester le code ci-dessous
//***********************************************************************************************
//*** Tests du downcasting et dynamic-cast ******************************************************
//***********************************************************************************************
void Essai6()
{
  srand((unsigned)time(NULL));

  cout << "----- 6.1 Allocation dynamique de Panneaux -----------------------------------------" << endl;
  Panneau* panneau[10];

  for (int i=0 ; i<10 ; i++)   // Tracez vos constructeurs !!!
  {
    cout << "panneau[" << i << "] : ";
    int n = rand()%4;
    switch(n)
    {
      case 0 : panneau[i] = new Panneau("P01",10,10,300,200,Couleur::ARGENT);
               cout << "Panneau" << endl;
               break;

      case 1 : panneau[i] = new PanneauImage("P02",30,30,"PhotoAnne.bmp");
               cout << "PanneauImage" << endl;
               break;

      case 2 : panneau[i] = new Bouton("B03",40,40,50,50);
               cout << "Bouton" << endl;
               break;

      case 3 : panneau[i] = new BoutonImage("B04",70,70,"boutonClear.bmp");
               cout << "BoutonImage" << endl;
               break;
    }
  }
  cout << endl;

  cout << "----- 6.2 Test du downcasting et dynamic-cast ------------------------------" << endl;
  for (int i=0 ; i<10 ; i++)
  {
    cout << "panneau[" << i << "] ";
    Panneau* pp = dynamic_cast<Panneau*>(panneau[i]);
    if (pp != NULL) cout << "est un Panneau, ";
    PanneauImage* ppi = dynamic_cast<PanneauImage*>(panneau[i]);
    if (ppi != NULL) cout << "est un PanneauImage, ";
    Bouton* pb = dynamic_cast<Bouton*>(panneau[i]);
    if (pb != NULL) cout << "est un Bouton, ";
    BoutonImage* pbi = dynamic_cast<BoutonImage*>(panneau[i]);
    if (pbi != NULL) cout << "est un BoutonImage";
    cout << endl;
  }
  cout << endl;

  cout << "----- 6.3 Liberation memoire ------------------------------------------------" << endl;
  for (int i=0 ; i<10 ; i++) delete panneau[i];
}

