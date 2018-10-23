#include <stdlib.h>
#include <iostream>
#include <time.h>

#include "Liste.h"
#include "ListeTriee.h"
#include "Iterateur.h"
#include "Pile.h"

#include "PanneauImage.h"
#include "Fraction.h"

using namespace std;

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();
void Essai5();
void Essai6();
void Essai7();
void Essai8();
void Essai9();
void Essai10();
void Essai11();

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
      case 7 : Essai7(); break;
      case 8 : Essai8(); break;
      case 9 : Essai9(); break;
      case 10 : Essai10(); break;
      case 11 : Essai11(); break;
      default : fini = true ; break;
    }
  }

  return 0;
}

int Menu()
{
  cout << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 6 ---------------------------------------------------------" << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << " 1. Test du template Liste avec des entiers" << endl;
  cout << " 2. Test du template Liste avec des objets de la classe PanneauImage" << endl;
  cout << " 3. Test du template ListeTriee avec des entiers" << endl;
  cout << " 4. Test du template ListeTriee avec des objets de la classe Fraction" << endl;
  cout << " 5. Test de l'iterateur avec une Liste d'entiers" << endl;
  cout << " 6. Test de l'iterateur avec une Liste de PanneauImage" << endl;
  cout << " 7. Test de l'iterateur avec une Liste triee d'entiers" << endl;
  cout << " 8. Test de l'iterateur avec une Liste triee de Fractions" << endl;
  cout << "----> BONUS 1ERE PARTIE (si vous avez le temps) <--------------------------" << endl;
  cout << " 9. Test du template Pile avec des entiers" << endl;
  cout << " 10. Test du template Pile avec des Fractions" << endl;
  cout << " 11. Test de l'iterateur avec une Pile de Fractions" << endl;
  cout << " 12. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

//*******************************************************************************************************
void Essai1()
{
  cout << "----- 1. Test du template Liste avec des entiers --------------------------------------------" << endl;
  cout << "----- 1.1 Creation et gestion d'une Liste ---------------------------------------------------" << endl;

  Liste<int> liste;
  liste.Affiche();                                       // --> ()
  cout << endl;

  cout << "Liste Vide ? " << liste.estVide() << endl;
  cout << "On insere 3,-2,5,-1 et 0..." << endl;
  liste.insere(3);
  liste.insere(-2);
  liste.insere(5);
  liste.insere(-1);
  liste.insere(0);
  cout << "Liste Vide ? " << liste.estVide() << endl;
  liste.Affiche();                                       // --> (3 -2 5 -1 0)
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl << endl;

  cout << "----- 1.2 Test du constructeur de copie -----------------------------------------------------" << endl;
  {
    Liste<int> liste2(liste);
    cout << "----> Voici la copie :" << endl;
    liste2.Affiche();
    cout << "----> On insere 50 dans la copie :" << endl; 
    liste2.insere(50);
    liste2.Affiche();
    cout << "----> Destruction de la copie..." << endl;
  }
  cout << endl << "Et revoici la liste de depart : " << endl;
  liste.Affiche();
  cout << endl << endl;

  cout << "----- 1.3 Test de l'operateur = -------------------------------------------------------------" << endl;
  {
    Liste<int> liste3;
    liste3 = liste;
    cout << "----> Voici le resultat de l'operateur = :" << endl;
    liste3.Affiche();
    cout << "----> On insere 50 dans la nouvelle liste :" << endl; 
    liste3.insere(50);
    liste3.Affiche();
    cout << "----> Destruction de la nouvelle liste..." << endl;
  }
  cout << endl << "Et revoici la liste de depart : " << endl;
  liste.Affiche();
  cout << endl;

  cout << "----- 1.4 Test de l'operateur [] -------------------------------------------------------------" << endl;
  {
    cout << "Entrez un indice : ";
    int i; cin >> i; cin.ignore();
    cout << "Element a l'indice demande = " << liste[i] << endl;
  }
  cout << endl << endl;

}

//*********************************************************************************************
void Essai2()
{
  cout << "----- 2. Test du template Liste avec des objets de la classe PanneauImage --------------" << endl;
  cout << "Creation  d'une Liste..." << endl;
  Liste<PanneauImage> liste;
  liste.Affiche();                                    
  cout << endl;

  cout << "On insere PanneauImage(\"P01\",20,40,\"un.bmp\")..." << endl;
  liste.insere(PanneauImage("P01",20,40,"un.bmp"));
  liste.Affiche();

  cout << "On insere PanneauImage(\"P02\",100,110,\"deux.bmp\")..." << endl;
  liste.insere(PanneauImage("P02",100,110,"deux.bmp"));
  liste.Affiche();

  cout << "On insere PanneauImage(\"P03\",200,10,\"trois.bmp\")..." << endl;
  PanneauImage *p = new PanneauImage("P03",200,10,"trois.bmp");
  liste.insere(*p);
  delete p;
  liste.Affiche();
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl << endl;

  cout << "Entrez un indice : ";
  int i; cin >> i; cin.ignore();
  cout << "Element a l'indice demande = " << liste[i] << endl << endl;
}

//*******************************************************************************************************
void Essai3()
{
  cout << "----- 3. Test du template ListeTriee avec des entiers ------------------------" << endl;
  cout << "----- 3.1 Creation et gestion d'une Liste triee ------------------------------" << endl;
  ListeTriee<int> liste;
  liste.Affiche();                                       // --> ()
  cout << endl;

  cout << "On insere 3,-2,5,-1,0 et -8..." << endl;
  liste.insere(3);
  liste.insere(-2);
  liste.insere(5);
  liste.insere(-1);
  liste.insere(0);
  liste.insere(-8);
  liste.Affiche();                                       // --> (-8 -2 -1 0 3 5)
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl;
  cout << endl;

  cout << "----- 3.2 Test du constructeur de copie ----------------------------------" << endl;
  {
    ListeTriee<int> liste2(liste);
    cout << "----> Voici la copie :" << endl;
    liste2.Affiche();
    cout << "----> On insere 4 dans la copie :" << endl; 
    liste2.insere(4);
    liste2.Affiche();
    cout << "----> Destruction de la copie..." << endl;
  }
  cout << endl << "Et revoici la liste de depart : " << endl;
  liste.Affiche();
  cout << endl;

  cout << "----- 3.3 Test de l'operateur = -------------------------------------------" << endl;
  {
    ListeTriee<int> liste3;
    liste3 = liste;
    cout << "----> Voici le resultat de l'operateur = :" << endl;
    liste3.Affiche();
    cout << "----> On insere 6 dans la nouvelle liste :" << endl; 
    liste3.insere(6);
    liste3.Affiche();
    cout << "----> Destruction de la nouvelle liste..." << endl;
  }
  cout << endl << "Et revoici la liste de depart : " << endl;
  liste.Affiche();
  cout << endl;
}

//*******************************************************************************************************
void Essai4()
{
  cout << "----- 4. Test du template ListeTriee avec des objets de la classe Fraction -------------------" << endl;
  cout << "Creation  d'une Liste triee..." << endl;
  ListeTriee<Fraction> liste;
  liste.Affiche();                                       
  cout << endl;

  cout << "On insere quelques fractions..." << endl;
  liste.insere(Fraction::UN);
  liste.insere(Fraction(-1,2));
  liste.insere(Fraction(7,3));
  liste.insere(Fraction(2,5));
  liste.insere(Fraction(-2));
  liste.Affiche();
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl;
  cout << endl;
}

//*******************************************************************************************************
void Essai5()
{
  cout << "----- 5. Test de l'iterateur avec une Liste d'entiers ------------------------" << endl;
  cout << "Creation  d'une Liste..." << endl;
  Liste<int> liste;
  Iterateur<int> it(liste);

  cout << "On insere 3,-2,5,-1 et 0..." << endl;
  liste.insere(3);
  liste.insere(-2);
  liste.insere(5);
  liste.insere(-1);
  liste.insere(0);

  cout << "On affiche grace a l'iterateur..." << endl;
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (int)it << endl;
  cout << endl;
}

//*******************************************************************************************************
void Essai6()
{
  cout << "----- 6. Test de l'iterateur avec une Liste de PanneauImage ---------------------------------" << endl;
  cout << "Creation  d'une Liste..." << endl;
  Liste<PanneauImage> liste;
  Iterateur<PanneauImage> it(liste);

  cout << "On insere PanneauImage(\"P01\",20,40,\"un.bmp\")..." << endl;
  liste.insere(PanneauImage("P01",20,40,"un.bmp"));
  
  cout << "On insere PanneauImage(\"P02\",100,110,\"deux.bmp\")..." << endl;
  liste.insere(PanneauImage("P02",100,110,"deux.bmp"));
  
  cout << "On insere PanneauImage(\"P03\",200,10,\"trois.bmp\")..." << endl;
  PanneauImage *p = new PanneauImage("P03",200,10,"trois.bmp");
  liste.insere(*p);
  delete p;

  cout << "On affiche grace a l'iterateur..." << endl;
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (PanneauImage)it << endl;
  cout << endl;
}

//*******************************************************************************************************
void Essai7()
{
  cout << "----- 7. Test de l'iterateur avec une Liste triee d'entiers ------------------------" << endl;
  cout << "Creation  d'une ListeTriee..." << endl;
  ListeTriee<int> liste;
  Iterateur<int> it(liste);

  cout << "On insere 3,-2,5,-1 et 0..." << endl;
  liste.insere(3);
  liste.insere(-2);
  liste.insere(5);
  liste.insere(-1);
  liste.insere(0);

  cout << "On affiche grace a l'iterateur..." << endl; // --> (-2 -1 0 3 5)
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (int)it << endl;
  cout << endl;
}

//*******************************************************************************************************
void Essai8()
{
  cout << "----- 8. Test de l'iterateur avec une Liste triee de Fractions ---------------------------" << endl;
  cout << "Creation  d'une ListeTriee..." << endl;
  ListeTriee<Fraction> liste;
  Iterateur<Fraction> it(liste);

  cout << "On insere quelques fractions..." << endl;
  liste.insere(Fraction::UN);
  liste.insere(Fraction(-1,2));
  liste.insere(Fraction(7,3));
  liste.insere(Fraction(2,5));
  liste.insere(Fraction(-2));

  cout << "On affiche grace a l'iterateur..." << endl; 
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (Fraction)it << endl;
  cout << endl;
}

//*******************************************************************************************************
void Essai9()
{
  cout << "----- 9. Test du template Pile avec des entiers ---------------------------------------------" << endl;
  cout << "Creation d'une pile..." << endl;
  Pile<int> pile;
  pile.Affiche();                                       // --> ()
  cout << endl;

  cout << "Pile Vide ? " << pile.estVide() << endl;
  cout << "On empile 3,-2,5,-1 et 0..." << endl;
  pile.push(3);   // ne fait qu'appeler la methode insere
  pile.insere(-2);
  pile.push(5);
  pile.push(-1);
  pile.push(0);
  cout << "Pile Vide ? " << pile.estVide() << endl;
  pile.Affiche();                                       // --> (0 -1 5 -2 3)
  cout << "La pile contient " << pile.getNombreElements() << " elements." << endl << endl;

  cout << "Top = " << pile.top() << endl << endl;
  
  cout << "On depile..." << endl;
  int val = pile.pop();
  cout << "Valeur depilee = " << val << endl;
  cout << "Re-voici la pile : " << endl;
  pile.Affiche();
  cout << endl << endl;
}

//*******************************************************************************************************
void Essai10()
{
  cout << "----- 10. Test du template Pile avec des Fractions ------------------------------------------" << endl;
  cout << "Creation d'une pile..." << endl;
  Pile<Fraction> pile;

  pile.Affiche();                                       
  cout << endl;
  cout << "Pile Vide ? " << pile.estVide() << endl;

  cout << "On empile quelques fractions..." << endl;
  pile.push(Fraction::UN);
  pile.push(Fraction(-1,2));
  pile.insere(Fraction(7,3));
  pile.push(Fraction(2,5));
  pile.push(Fraction(-2));

  pile.Affiche();                                       
  cout << endl;
  cout << "Pile Vide ? " << pile.estVide() << endl;
  cout << "La pile contient " << pile.getNombreElements() << " elements." << endl << endl;

  cout << "Top = " << pile.top() << endl << endl;
  
  cout << "On depile..." << endl;
  Fraction val = pile.pop();
  cout << "Valeur depilee = " << val << endl;
  cout << "Re-voici la pile : " << endl;
  pile.Affiche();
  cout << endl << endl;
}

//*******************************************************************************************************
void Essai11()
{
  cout << "----- 11. Test de l'iterateur avec une Pile de Fractions ---------------------------" << endl;
  cout << "Creation  d'une Pile..." << endl;
  Pile<Fraction> pile;
  Iterateur<Fraction> it(pile);

  cout << "On empile quelques fractions..." << endl;
  pile.push(Fraction::UN);
  pile.push(Fraction(-1,2));
  pile.insere(Fraction(7,3));
  pile.push(Fraction(2,5));
  pile.push(Fraction(-2));

  cout << "On affiche grace a l'iterateur..." << endl; 
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (Fraction)it << endl;
  cout << endl;
}


