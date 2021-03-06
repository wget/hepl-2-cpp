#include <stdlib.h>
#include <iostream>
#include <time.h>

#include "../lib/utils/src/HeplList.hpp"
#include "../lib/utils/src/HeplSortedList.hpp"
#include "../lib/utils/src/HeplBaseListIterator.hpp"
#include "../lib/utils/src/HeplStack.hpp"

#include "../ImagePanel.hpp"
#include "../Fraction.hpp"

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
  cout << " 2. Test du template Liste avec des objets de la classe ImagePanel" << endl;
  cout << " 3. Test du template HeplSortedList avec des entiers" << endl;
  cout << " 4. Test du template HeplSortedList avec des objets de la classe Fraction" << endl;
  cout << " 5. Test de l'iterateur avec une Liste d'entiers" << endl;
  cout << " 6. Test de l'iterateur avec une Liste de ImagePanel" << endl;
  cout << " 7. Test de l'iterateur avec une Liste triee d'entiers" << endl;
  cout << " 8. Test de l'iterateur avec une Liste triee de Fractions" << endl;
  cout << "----> BONUS 1ERE PARTIE (si vous avez le temps) <--------------------------" << endl;
  cout << " 9. Test du template HeplStack avec des entiers" << endl;
  cout << " 10. Test du template HeplStack avec des Fractions" << endl;
  cout << " 11. Test de l'iterateur avec une HeplStack de Fractions" << endl;
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

  HeplList<int> liste;
  liste.display();                                       // --> ()
  cout << endl;

  cout << "Liste Vide ? " << liste.isEmpty() << endl;
  cout << "On add 3,-2,5,-1 et 0..." << endl;
  liste.add(3);
  liste.add(-2);
  liste.add(5);
  liste.add(-1);
  liste.add(0);
  cout << "Liste Vide ? " << liste.isEmpty() << endl;
  liste.display();                                       // --> (3 -2 5 -1 0)
  cout << "La liste contient " << liste.getNumberItems() << " elements." << endl << endl;

  cout << "----- 1.2 Test du constructeur de copie -----------------------------------------------------" << endl;
  {
    HeplList<int> liste2(liste);
    cout << "----> Voici la copie :" << endl;
    liste2.display();
    cout << "----> On add 50 dans la copie :" << endl; 
    liste2.add(50);
    liste2.display();
    cout << "----> Destruction de la copie..." << endl;
  }
  cout << endl << "Et revoici la liste de depart : " << endl;
  liste.display();
  cout << endl << endl;

  cout << "----- 1.3 Test de l'operateur = -------------------------------------------------------------" << endl;
  {
    HeplList<int> liste3;
    liste3 = liste;
    cout << "----> Voici le resultat de l'operateur = :" << endl;
    liste3.display();
    cout << "----> On add 50 dans la nouvelle liste :" << endl; 
    liste3.add(50);
    liste3.display();
    cout << "----> Destruction de la nouvelle liste..." << endl;
  }
  cout << endl << "Et revoici la liste de depart : " << endl;
  liste.display();
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
  cout << "----- 2. Test du template Liste avec des objets de la classe ImagePanel --------------" << endl;
  cout << "Creation  d'une Liste..." << endl;
  HeplList<ImagePanel> liste;
  liste.display();                                    
  cout << endl;

  cout << "On add ImagePanel(\"P01\",20,40,\"1.bmp\")..." << endl;
  liste.add(ImagePanel("P01",20,40,"1.bmp"));
  liste.display();

  cout << "On add ImagePanel(\"P02\",100,110,\"2.bmp\")..." << endl;
  liste.add(ImagePanel("P02",100,110,"2.bmp"));
  liste.display();

  cout << "On add ImagePanel(\"P03\",200,10,\"3.bmp\")..." << endl;
  ImagePanel *p = new ImagePanel("P03",200,10,"3.bmp");
  liste.add(*p);
  delete p;
  liste.display();
  cout << "La liste contient " << liste.getNumberItems() << " elements." << endl << endl;

  cout << "Entrez un indice : ";
  int i; cin >> i; cin.ignore();
  cout << "Element a l'indice demande = " << liste[i] << endl << endl;
}

//*******************************************************************************************************
void Essai3()
{
  cout << "----- 3. Test du template HeplSortedList avec des entiers ------------------------" << endl;
  cout << "----- 3.1 Creation et gestion d'une Liste triee ------------------------------" << endl;
  HeplSortedList<int> liste;
  liste.display();                                       // --> ()
  cout << endl;

  cout << "On add 3,-2,5,-1,0 et -8..." << endl;
  liste.add(3);
  liste.add(-2);
  liste.add(5);
  liste.add(-1);
  liste.add(0);
  liste.add(-8);
  liste.display();                                       // --> (-8 -2 -1 0 3 5)
  cout << "La liste contient " << liste.getNumberItems() << " elements." << endl;
  cout << endl;

  cout << "----- 3.2 Test du constructeur de copie ----------------------------------" << endl;
  {
    HeplSortedList<int> liste2(liste);
    cout << "----> Voici la copie :" << endl;
    liste2.display();
    cout << "----> On add 4 dans la copie :" << endl; 
    liste2.add(4);
    liste2.display();
    cout << "----> Destruction de la copie..." << endl;
  }
  cout << endl << "Et revoici la liste de depart : " << endl;
  liste.display();
  cout << endl;

  cout << "----- 3.3 Test de l'operateur = -------------------------------------------" << endl;
  {
    HeplSortedList<int> liste3;
    liste3 = liste;
    cout << "----> Voici le resultat de l'operateur = :" << endl;
    liste3.display();
    cout << "----> On add 6 dans la nouvelle liste :" << endl; 
    liste3.add(6);
    liste3.display();
    cout << "----> Destruction de la nouvelle liste..." << endl;
  }
  cout << endl << "Et revoici la liste de depart : " << endl;
  liste.display();
  cout << endl;
}

//*******************************************************************************************************
void Essai4()
{
  cout << "----- 4. Test du template HeplSortedList avec des objets de la classe Fraction -------------------" << endl;
  cout << "Creation  d'une Liste triee..." << endl;
  HeplSortedList<Fraction> liste;
  liste.display();                                       
  cout << endl;

  cout << "On add quelques fractions..." << endl;
  liste.add(Fraction::ONE);
  liste.add(Fraction(-1,2));
  liste.add(Fraction(7,3));
  liste.add(Fraction(2,5));
  liste.add(Fraction(-2));
  liste.display();
  cout << "La liste contient " << liste.getNumberItems() << " elements." << endl;
  cout << endl;
}

//*******************************************************************************************************
void Essai5()
{
  cout << "----- 5. Test de l'iterateur avec une Liste d'entiers ------------------------" << endl;
  cout << "Creation  d'une Liste..." << endl;
  HeplList<int> liste;
  HeplBaseListIterator<int> it(liste);

  cout << "On add 3,-2,5,-1 et 0..." << endl;
  liste.add(3);
  liste.add(-2);
  liste.add(5);
  liste.add(-1);
  liste.add(0);

  cout << "On affiche grace a l'iterateur..." << endl;
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (int)it << endl;
  cout << endl;
}

//*******************************************************************************************************
void Essai6()
{
  cout << "----- 6. Test de l'iterateur avec une Liste de ImagePanel ---------------------------------" << endl;
  cout << "Creation  d'une Liste..." << endl;
  HeplList<ImagePanel> liste;
  HeplBaseListIterator<ImagePanel> it(liste);

  cout << "On add ImagePanel(\"P01\",20,40,\"1.bmp\")..." << endl;
  liste.add(ImagePanel("P01",20,40,"1.bmp"));

  cout << "On add ImagePanel(\"P02\",100,110,\"2.bmp\")..." << endl;
  liste.add(ImagePanel("P02",100,110,"2.bmp"));

  cout << "On add ImagePanel(\"P03\",200,10,\"3.bmp\")..." << endl;
  ImagePanel *p = new ImagePanel("P03",200,10,"3.bmp");
  liste.add(*p);
  delete p;

  cout << "On affiche grace a l'iterateur..." << endl;
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (ImagePanel)it << endl;
  cout << endl;
}

//*******************************************************************************************************
void Essai7()
{
  cout << "----- 7. Test de l'iterateur avec une Liste triee d'entiers ------------------------" << endl;
  cout << "Creation  d'une HeplSortedList..." << endl;
  HeplSortedList<int> liste;
  HeplBaseListIterator<int> it(liste);

  cout << "On add 3,-2,5,-1 et 0..." << endl;
  liste.add(3);
  liste.add(-2);
  liste.add(5);
  liste.add(-1);
  liste.add(0);

  cout << "On affiche grace a l'iterateur..." << endl; // --> (-2 -1 0 3 5)
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (int)it << endl;
  cout << endl;
}

//*******************************************************************************************************
void Essai8()
{
  cout << "----- 8. Test de l'iterateur avec une Liste triee de Fractions ---------------------------" << endl;
  cout << "Creation  d'une HeplSortedList..." << endl;
  HeplSortedList<Fraction> liste;
  HeplBaseListIterator<Fraction> it(liste);

  cout << "On add quelques fractions..." << endl;
  liste.add(Fraction::ONE);
  liste.add(Fraction(-1,2));
  liste.add(Fraction(7,3));
  liste.add(Fraction(2,5));
  liste.add(Fraction(-2));

  cout << "On affiche grace a l'iterateur..." << endl; 
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (Fraction)it << endl;
  cout << endl;
}

//*******************************************************************************************************
void Essai9()
{
  cout << "----- 9. Test du template HeplStack avec des entiers ---------------------------------------------" << endl;
  cout << "Creation d'une pile..." << endl;
  HeplStack<int> pile;
  pile.display();                                       // --> ()
  cout << endl;

  cout << "HeplStack Vide ? " << pile.isEmpty() << endl;
  cout << "On empile 3,-2,5,-1 et 0..." << endl;
  pile.push(3);   // ne fait qu'appeler la methode add
  pile.add(-2);
  pile.push(5);
  pile.push(-1);
  pile.push(0);
  cout << "HeplStack Vide ? " << pile.isEmpty() << endl;
  pile.display();                                       // --> (0 -1 5 -2 3)
  cout << "La pile contient " << pile.getNumberItems() << " elements." << endl << endl;

  cout << "Top = " << pile.top() << endl << endl;

  cout << "On depile..." << endl;
  int val = pile.pop();
  cout << "Valeur depilee = " << val << endl;
  cout << "Re-voici la pile : " << endl;
  pile.display();
  cout << endl << endl;
}

//*******************************************************************************************************
void Essai10()
{
  cout << "----- 10. Test du template HeplStack avec des Fractions ------------------------------------------" << endl;
  cout << "Creation d'une pile..." << endl;
  HeplStack<Fraction> pile;

  pile.display();
  cout << endl;
  cout << "HeplStack Vide ? " << pile.isEmpty() << endl;

  cout << "On empile quelques fractions..." << endl;
  pile.push(Fraction::ONE);
  pile.push(Fraction(-1,2));
  pile.add(Fraction(7,3));
  pile.push(Fraction(2,5));
  pile.push(Fraction(-2));

  pile.display();
  cout << endl;
  cout << "HeplStack Vide ? " << pile.isEmpty() << endl;
  cout << "La pile contient " << pile.getNumberItems() << " elements." << endl << endl;

  cout << "Top = " << pile.top() << endl << endl;

  cout << "On depile..." << endl;
  Fraction val = pile.pop();
  cout << "Valeur depilee = " << val << endl;
  cout << "Re-voici la pile : " << endl;
  pile.display();
  cout << endl << endl;
}

//*******************************************************************************************************
void Essai11()
{
  cout << "----- 11. Test de l'iterateur avec une HeplStack de Fractions ---------------------------" << endl;
  cout << "Creation  d'une HeplStack..." << endl;
  HeplStack<Fraction> pile;
  HeplBaseListIterator<Fraction> it(pile);

  cout << "On empile quelques fractions..." << endl;
  pile.push(Fraction::ONE);
  pile.push(Fraction(-1,2));
  pile.add(Fraction(7,3));
  pile.push(Fraction(2,5));
  pile.push(Fraction(-2));

  cout << "On affiche grace a l'iterateur..." << endl;
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (Fraction)it << endl;
  cout << endl;
}
