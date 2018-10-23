#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;

#include "Panneau.h"
#include "PanneauImage.h"
#include "Bouton.h"
#include "BoutonImage.h"
#include "Fraction.h"

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();
void Essai5();

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
      default : fini = true ; break;
    }
  }

  return 0;
}

int Menu()
{
  cout << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 5 ---------------------------------------------------------" << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << " 1. Test de setNom() de Panneau, PanneauImage, Bouton et BoutonImage" << endl;
  cout << " 2. Test des constructeurs de Panneau, PanneauImage, Bouton et BoutonImage" << endl;
  cout << " 3. Test des constructeurs de la classe Fraction" << endl;
  cout << " 4. Test de cin et de l'operateur / de la classe Fraction" << endl;
  cout << " 5. Gestion de plusieurs exceptions simultanement" << endl;
  cout << " 6. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

//**********************************************************************************************
// ATTENTION !!!!
// Les methodes de vos classes NE doivent PAS contenir de TRY{...} CATCH{...} mais
// uniquement des THROW !!! Donc, votre classe lance une exception (une erreur) mais
// ce n'est pas elle qui la traite. C'est l'application qui utilise votre classe
// qui doit traiter les exceptions. C'est donc uniquement dans le main (ou les fonctions appelees)
// que l'on trouve des try...catch 
//**********************************************************************************************
void Essai1()
{

  cout << "----- 1. Test de setNom() de Panneau, PanneauImage, Bouton et BoutonImage ---------------" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : afficher le message de l'exception lancee

  // ... à compléter
  {
    Panneau *p;
    int n = rand()%4;
    switch(n)
    {
      case 0 : p = new Panneau();
               cout << "Creation d'un Panneau par defaut..." << endl;
               break;

      case 1 : p = new PanneauImage();
               cout << "Creation d'un PanneauImage par defaut..." << endl;
               break;

      case 2 : p = new Bouton();
               cout << "Creation d'un Bouton par defaut..." << endl;
               break;

      case 3 : p = new BoutonImage();
               cout << "Creation d'un BoutonImage par defaut..." << endl;
               break;
    }

    char txt[80];
    cout << "Encodez son nom : "; cin.getline(txt,80);
    p->setNom(txt);  // !!!
    cout << "Nom encode = " << p->getNom() << endl << endl;
  }
  // ... à compléter

  cout << endl;
}

//**********************************************************************************************
void Essai2()
{
  cout << "----- 2. Test des constructeurs de Panneau, PanneauImage, Bouton et BoutonImage --------------" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : afficher le message de l'exception lancee

  // ... à compléter
  {
    char txt[80];
    cout << "Creation d'un Panneau..." << endl;
    cout << "Encodez son nom : "; cin.getline(txt,80);
    Panneau p(txt,100,30,50,80,Couleur::ARGENT);
    cout << "Panneau cree : " << p << endl << endl;

    cout << "Creation d'un PanneauImage..." << endl;
    cout << "Encodez son nom : "; cin.getline(txt,80);
    PanneauImage pi(txt,100,30,"Photo1.bmp");
    cout << "PanneauImage cree : " << pi << endl << endl;

    cout << "Creation d'un Bouton..." << endl;
    cout << "Encodez son nom : "; cin.getline(txt,80);
    Bouton b(txt,100,30,45,45,Couleur(120,120,70));
    cout << "Bouton cree : " << b << endl << endl;

    cout << "Creation d'un BoutonImage..." << endl;
    cout << "Encodez son nom : "; cin.getline(txt,80);
    BoutonImage bi(txt,100,30,"boutonPlus.bmp");
    cout << "BoutonImage cree : " << bi << endl << endl;
  }
  // ... à compléter
  
  cout << endl;
}

//**********************************************************************************************
void Essai3()
{

  cout << "----- 3. Test des constructeurs de la classe Fraction -------------------------------" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : afficher le message de l'exception lancee

  // ... à compléter
  {
    int num,den;
    cout << "Creation d'une fraction..." << endl;
    cout << "Numerateur : "; cin >> num; cin.ignore();
    cout << "Denominateur : "; cin >> den; cin.ignore();
    Fraction f1(num,den);
    cout << "Fraction encodee = " << f1 << endl << endl;

    unsigned int n,d;
    int s;
    cout << "Creation d'une fraction avec signe..." << endl;
    cout << "Signe (+1/-1) : "; cin >> s; cin.ignore();
    cout << "Numerateur : "; cin >> num; cin.ignore();
    cout << "Denominateur : "; cin >> den; cin.ignore();
    Fraction::Signe signe;
    if (s > 0) signe = Fraction::positif;
    else signe = Fraction::negatif;
    Fraction f2(num,den,signe);
    cout << "Fraction encodee = " << f2 << endl;
  }
  // ... à compléter
  
  cout << endl;
}

//**********************************************************************************************
void Essai4()
{

  cout << "----- 4. Test de cin et de l'operateur / de la classe Fraction -----------------------------" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : afficher le message de l'exception lancee

  // ... à compléter
  {
    Fraction f1,f2,f3;
    cout << "Encodez f1 : " << endl; cin >> f1;
    cout << "Encodez f2 : " << endl; cin >> f2;
    f3 = f1 / f2;
    cout << "f3 = f1 / f2 = " << f3 << endl << endl;
  }
  // ... à compléter
  
  cout << endl;
}

//**********************************************************************************************/
void Essai5()
{
  cout << "----- 5. Gestion de plusieurs exceptions simultanement ------------------------------" << endl;
  // A COMPLETER : Traitez TOUTES les exceptions susceptible d'etre lancee par le bloc de code suivant (try...catch)

  // ... à compléter
  {
    char txt[80];
    cout << "Creation d'un Bouton..." << endl;
    cout << "Encodez son nom : "; cin.getline(txt,80);
    Bouton b(txt,100,30,45,45,Couleur(120,120,70));
    cout << "Bouton cree : " << b << endl << endl;

    int num,den;
    cout << "Creation d'une fraction..." << endl;
    cout << "Numerateur : "; cin >> num; cin.ignore();
    cout << "Denominateur : "; cin >> den; cin.ignore();
    Fraction f1(num,den);
    cout << "Fraction encodee = " << f1 << endl << endl;
  }
  // ... à compléter

}


