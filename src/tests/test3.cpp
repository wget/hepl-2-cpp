#include <stdlib.h>
#include <iostream>
using namespace std;
#include "Couleur.h"
#include "Panneau.h"
#include "Fraction.h"

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

//******************************************************************************************************
int Menu()
{
  cout << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TESTS 3 -------------------------------------------------------------------" << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << " 1. Tests de l'operateur = de la classe Couleur" << endl;
  cout << " 2. Tests des operateurs << et >> de la classe Couleur" << endl;
  cout << " 3. Tests de l'operateur = de la classe Panneau" << endl;
  cout << " 4. Tests des operateurs << et >> de la classe Panneau" << endl;
  cout << " 5. Tests de base de la classe Fraction" << endl;
  cout << " 6. Tests des operateurs + de la classe Fraction" << endl;
  cout << " 7. Tests de l'operateur - de la classe Fraction" << endl;
  cout << " 8. Tests de l'operateur * de la classe Fraction" << endl;
  cout << " 9. Tests de l'operateur / de la classe Fraction" << endl;
  cout << " 10. Tests des opérateurs < > et == de la classe Fraction" << endl;
  cout << " 11. Tests des operateurs ++ de la classe Fraction" << endl;
  cout << " 12. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

//*******************************************************************************************************
//*** Tests de l'operateur = de la classe Couleur *******************************************************
//*******************************************************************************************************
void Essai1()
{ 
  cout << "********************************************************************" << endl;
  cout << "(1) ***** Test de l'operateur d'affectation de Couleur *************" << endl;
  cout << "********************************************************************" << endl;
  {
    Couleur c;
    {
      Couleur c1(112,141,35,"Olive");
      cout << "c1 : "; c1.Affiche();

      cout << endl << ">>>>> c = c1;" << endl;
      c = c1;
      cout << ">>>>> Destruction de c1" << endl << endl;
    }
    cout << "c : "; c.Affiche();

    cout << endl << ">>>>> c2 = c3 = Couleur(145);" << endl;
    Couleur c2,c3;
    c2 = c3 = Couleur(145);
    cout << "c2 : "; c2.Affiche();
    cout << "c3 : "; c3.Affiche();
  }
}

//*******************************************************************************************************
//*** Tests des operateurs << et >> de la classe Couleur ************************************************
//*******************************************************************************************************
void Essai2()
{
  cout << "**************************************************************************" << endl;
  cout << "(2) ********* Tests des operateurs << et >> de Couleur *******************" << endl;
  cout << "**************************************************************************" << endl;
  Couleur c1(127,0,255,"Violet");
  cout << "c1 = " << c1 << endl;
  cout << "Nouvelle valeur pour c1 = ";
  cin >> c1;
  cout << c1 << endl << endl;
}

//*******************************************************************************************************
//*** Tests de l'operateur = de la classe Panneay *******************************************************
//*******************************************************************************************************
void Essai3()
{ 
  cout << "********************************************************************" << endl;
  cout << "(3) ***** Test de l'operateur d'affectation de Panneau *************" << endl;
  cout << "********************************************************************" << endl;
  {
    Panneau p;
    {
      Panneau p1("P01",20,30,300,180,Couleur(158));
      cout << "p1 : "; p1.Affiche();

      cout << endl << ">>>>> p = p1;" << endl;
      p = p1;
      cout << ">>>>> Destruction de p1" << endl << endl;
    }
    cout << "p : "; p.Affiche();

    cout << endl << ">>>>> p2 = p3 = Panneau(\"P02\",30,30,400,300);" << endl;
    Panneau p2,p3;
    p2 = p3 = Panneau("P02",30,30,400,300);
    cout << "p2 : "; p2.Affiche();
    cout << "p3 : "; p3.Affiche();
  }
}

//*******************************************************************************************************
//*** Tests des operateurs << et >> de la classe Panneau ************************************************
//*******************************************************************************************************
void Essai4()
{
  cout << "**************************************************************************" << endl;
  cout << "(4) ********* Tests des operateurs << et >> de Panneau *******************" << endl;
  cout << "**************************************************************************" << endl;
  Panneau p1("P01",20,30,300,180,Couleur::ARGENT);
  cout << "p1 = " << p1 << endl;
  cout << "Nouvelle valeur pour p1 = " << endl;
  cin >> p1;
  cout << p1 << endl << endl;
}

//*******************************************************************************************************
//*** Tests de base de la classe Fraction ***************************************************************
//*******************************************************************************************************
void Essai5()
{
  cout << "****************************************************************************************" << endl;
  cout << "(5) ********* Tests de base de la classe Fraction **************************************" << endl;
  cout << "****************************************************************************************" << endl;

  cout << endl << "***** Tests des constructeurs et operateur << ******************" << endl;
  Fraction f1, f2(2,3,Fraction::negatif), f3(5,-6), f4(-2), f5(f2);
  cout << "f1 = " << f1 << endl; // --> 1
  cout << "f2 = " << f2 << endl; // --> -2/3
  cout << "f3 = " << f3 << endl; // --> -5/6
  cout << "f4 = " << f4 << endl; // --> -2
  cout << "f5 = " << f5 << endl; // --> -2/3

  cout << endl << "***** Test des getters/setters *********************************" << endl;
  f1.setNumerateur(5);
  f1.setDenominateur(8);
  f1.setSigne(Fraction::positif);
  cout << "f1 = " << f1 << endl; // --> 5/8
  cout << "Numerateur de f1   = " << f1.getNumerateur() << endl;
  cout << "Denominateur de f1 = " << f1.getDenominateur() << endl;
  cout << "Signe de f1        = " << f1.getSigne() << endl;

  cout << endl << "***** Test des variables membres statiques *********************" << endl;
  Fraction f6(Fraction::ZERO);
  cout << "Fraction::UN = " << Fraction::UN << endl;        // --> 1
  cout << "f6 (copie de Fraction::ZERO) = " << f6 << endl;  // --> 0

  cout << endl << "***** Test des methodes concernant le signe ********************" << endl;
  Fraction f7(4,9);
  int n = rand()%3;
  if (n == 0) f7.setNumerateur(0); // --> la fraction est nulle
  if (n == 1) f7.setSigne(Fraction::positif);
  if (n == 2) f7.setSigne(Fraction::negatif);
  cout << "f7 = " << f7 << endl;
  if (f7.estNul()) cout << "f7 est nulle" << endl;
  if (f7.estPositif()) cout << "f7 est positive" << endl;
  if (f7.estNegatif()) cout << "f7 est negative" << endl;
}

//*******************************************************************************************************
//*** Tests des operateurs + de la classe Fraction ******************************************************
//*******************************************************************************************************
void Essai6()
{
  cout << "****************************************************************************************" << endl;
  cout << "(6) ********* Tests des operateurs + de la classe Fraction *****************************" << endl;
  cout << "****************************************************************************************" << endl;

  cout << endl << "***** Tests preliminaires de la methode statique PGCD **************************" << endl;
  cout << "PGCD de 1 et 8   = " << Fraction::PGCD(1,8) << endl;     // --> 1
  cout << "PGCD de 5 et 10  = " << Fraction::PGCD(5,10) << endl;    // --> 5
  cout << "PGCD de 18 et 24 = " << Fraction::PGCD(18,24) << endl;   // --> 6
  cout << "PGCD de 13 et 20 = " << Fraction::PGCD(13,20) << endl;   // --> 1

  cout << endl << "***** Tests de la methode d'instance simplifie *********************************" << endl;
  Fraction f1(7,9), f2(8,12,Fraction::negatif), f3(10,5);
  cout << "Avant : " << endl;
  cout << "f1 = " << f1 << endl; // --> 7/9
  cout << "f2 = " << f2 << endl; // --> -8/12
  cout << "f3 = " << f3 << endl; // --> 10/5
  f1.simplifie(); f2.simplifie(); f3.simplifie();
  cout << "Apres : " << endl;
  cout << "f1 = " << f1 << endl; // --> 7/9
  cout << "f2 = " << f2 << endl; // --> -2/3
  cout << "f3 = " << f3 << endl; // --> 2

  cout << endl << "***** Tests de Fraction + Fraction *********************************************" << endl;
  Fraction f4(3,10), f5(4,15), f6;
  cout << "Avant :" << endl;
  cout << "f4 = " << f4 << endl; // --> 3/10
  cout << "f5 = " << f5 << endl; // --> 4/15
  f6 = f4 + f5; // n'oubliez pas l'operateur = !!!
  cout << "f6 = f4 + f5 = " << f6 << endl;    // --> 17/30
  cout << "Apres :" << endl;
  cout << "f4 = " << f4 << endl; // --> 3/10
  cout << "f5 = " << f5 << endl << endl; // --> 4/15

  Fraction f7(2), f8(2,3,Fraction::negatif), f9;
  cout << "f7 = " << f7 << endl; // --> 2
  cout << "f8 = " << f8 << endl; // --> -2/3
  f9 = f7 + f8;
  cout << "f9 = f7 + f8 = " << f9 << endl;    // --> 4/3

  cout << endl << "***** Tests de Fraction + int **************************************************" << endl;
  Fraction f10(5,9,Fraction::positif), f11;
  cout << "Avant :" << endl;
  cout << "f10 = " << f10 << endl; // --> 5/9
  f11 = f10 + 2;
  cout << "f11 = f10 + 2 = " << f11 << endl;    // --> 23/9
  cout << "Apres :" << endl;
  cout << "f10 = " << f10 << endl; // --> 5/9

  cout << endl << "***** Tests de int + Fraction **************************************************" << endl;
  Fraction f12(2,5,Fraction::positif), f13;
  cout << "Avant :" << endl;
  cout << "f12 = " << f12 << endl; // --> 2/5
  f13 = -3 + f12;
  cout << "f13 = -3 + f12 = " << f13 << endl;    // --> -13/5
  cout << "Apres :" << endl;
  cout << "f12 = " << f12 << endl; // --> 2/5  
}

//*******************************************************************************************************
//*** Tests de l'operateur - de la classe Fraction ******************************************************
//*******************************************************************************************************
void Essai7()
{
  cout << "****************************************************************************************" << endl;
  cout << "(7) ********* Tests de l'operateur - de la classe Fraction *****************************" << endl;
  cout << "****************************************************************************************" << endl;

  Fraction f1(3,10), f2(4,15), f3;
  cout << "Avant :" << endl;
  cout << "f1 = " << f1 << endl; // --> 3/10
  cout << "f2 = " << f2 << endl; // --> 4/15
  f3 = f1 - f2;
  cout << "f3 = f1 - f2 = " << f3 << endl;    // --> 1/30
  cout << "Apres :" << endl;
  cout << "f1 = " << f1 << endl; // --> 3/10
  cout << "f2 = " << f2 << endl << endl; // --> 4/15

  Fraction f4(2,5,Fraction::negatif),f5;
  cout << "f4 = " << f4 << endl; // --> -2/5
  f5 = f4 - Fraction(-2);
  cout << "f5 = f4 - Fraction(-2) = " << f5 << endl << endl; // --> 8/5

  f5 = Fraction(3,10) - Fraction(7,9);
  cout << "f5 = Fraction(3,10) - Fraction(7,9) = " << f5 << endl;  // --> -43/90
}

//*******************************************************************************************************
//*** Tests de l'operateur * de la classe Fraction ******************************************************
//*******************************************************************************************************
void Essai8()
{
  cout << "****************************************************************************************" << endl;
  cout << "(8) ********* Tests de l'operateur * de la classe Fraction *****************************" << endl;
  cout << "****************************************************************************************" << endl;

  Fraction f1(7,36), f2(27,14), f3;
  cout << "Avant :" << endl;
  cout << "f1 = " << f1 << endl; // --> 7/36
  cout << "f2 = " << f2 << endl; // --> 27/14
  f3 = f1 * f2;
  cout << "f3 = f1 * f2 = " << f3 << endl;    // --> 3/8
  cout << "Apres :" << endl;
  cout << "f1 = " << f1 << endl; // --> 7/36
  cout << "f2 = " << f2 << endl << endl; // --> 27/14

  Fraction f4(2,5,Fraction::negatif),f5;
  cout << "f4 = " << f4 << endl; // --> -2/5
  f5 = f4 * Fraction(-2);
  cout << "f5 = f4 * Fraction(-2) = " << f5 << endl << endl; // --> 4/5

  f5 = Fraction(3,10) * Fraction(-7,9);
  cout << "f5 = Fraction(3,10) * Fraction(-7,9) = " << f5 << endl;  // --> -7/30
}

//*******************************************************************************************************
//*** Tests de l'operateur / de la classe Fraction ******************************************************
//*******************************************************************************************************
void Essai9()
{
  cout << "****************************************************************************************" << endl;
  cout << "(9) ********* Tests de l'operateur / de la classe Fraction *****************************" << endl;
  cout << "****************************************************************************************" << endl;

  Fraction f1(14,25), f2(49,-40), f3;
  cout << "Avant :" << endl;
  cout << "f1 = " << f1 << endl; // --> 14/25
  cout << "f2 = " << f2 << endl; // --> -49/40
  f3 = f1 / f2;
  cout << "f3 = f1 / f2 = " << f3 << endl;    // --> -16/35
  cout << "Apres :" << endl;
  cout << "f1 = " << f1 << endl; // --> 14/25
  cout << "f2 = " << f2 << endl << endl; // --> -49/40

  Fraction f4(8,5,Fraction::negatif),f5;
  cout << "f4 = " << f4 << endl; // --> -8/5
  f5 = f4 / Fraction(-2);
  cout << "f5 = f4 / Fraction(-2) = " << f5 << endl << endl; // --> 4/5

  f5 = Fraction(3,10,Fraction::negatif) / Fraction(9,7);
  cout << "f5 = Fraction(3,10,Fraction::negatif) / Fraction(9,7) = " << f5 << endl;  // --> -7/30
}

//*******************************************************************************************************
//*** Tests des operateurs < > et == de la classe Fraction **********************************************
//*******************************************************************************************************
void Essai10()
{
  cout << "****************************************************************************************" << endl;
  cout << "(10) ********* Test des operateurs < > et == de la classe Fraction *********************" << endl;
  cout << "****************************************************************************************" << endl;

  Fraction f1, f2;
  cout << "Encodez une fraction f1 :" << endl;
  cin >> f1;
  cout << "Encodez une fraction f2 :" << endl;
  cin >> f2;
  if (f1 == f2) cout << "--> f1 est egale a f2";
  if (f1 < f2) cout << "--> f1 est plus petite que f2";
  if (f1 > f2) cout << "--> f1 est plus grande que f2";
  cout << endl << endl;
}

//*******************************************************************************************************
//*** Tests des operateurs ++ de la classe Fraction *****************************************************
//*******************************************************************************************************
void Essai11()
{
  cout << "****************************************************************************************" << endl;
  cout << "(11) ********* Test des operateurs ++ de la classe Fraction ****************************" << endl;
  cout << "****************************************************************************************" << endl;

  Fraction f(1,3,Fraction::negatif);
  cout << endl << "***** Test de l'operateur de pre-incrementation **********************" << endl;
  cout << "f   : " << f << endl;
  cout << "++f : " << ++f << endl;  // Si tout va bien, f est incremente avant d'etre affiche !
  cout << "f   : " << f << endl << endl;

  cout << "***** Test de l'operateur de post-incrementation *********************" << endl;
  cout << "f   : " << f << endl;
  cout << "f++ : " << f++ << endl;  // Si tout va bien, f est incremente apres avoir ete affiche !
  cout << "f   : " << f << endl << endl;
}

