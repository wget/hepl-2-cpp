#include <iostream>
#include <fstream>
using namespace std;
#include <stdlib.h>

#include "../Color.hpp"
#include "../Panel.hpp"
#include "../ImagePanel.hpp"

int  Menu();
void Essai1();
void Essai2();
void Essai3();

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
      default : fini = true ; break;
    }
  }

  return 0;
}

int Menu()
{
  cout << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 7 ---------------------------------------------------------" << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << " 1. Test des methodes save et load de la classe Color" << endl;
  cout << " 2. Test des mathodes save et load de la classe Panel" << endl;
  cout << " 3. Test des methodes save et load de la classe ImagePanel" << endl;
  cout << " 4. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

//*********************************************************************************************
void Essai1()  // Attention : utilisez les flux bytes (read et write) !!!!
{
  cout << "----- 1. Test des methodes save et load de la classe Color ------" << endl;
  
  Color c1(112,141,35,"Olive");
  cout << "c1 = " << c1 << endl;
  cout << endl;

  cout << "----- Sauvegarde de la couleur dans le fichier C.dat -----" << endl;
  ofstream fichier1("C.dat",ios::out);
  c1.save(fichier1);
  fichier1.close();

  cout << "----- Chargement de la couleur situee dans le fichier C.dat -----" << endl;
  ifstream fichier2("C.dat",ios::in);
  Color c2;
  c2.load(fichier2);
  fichier2.close();
  cout << "c2 = " << c2 << endl;
  cout << endl;
}

//*********************************************************************************************
void Essai2()  // Attention : utilisez les flux bytes (read et write) !!!!
{
  cout << "----- 2. Test des methodes save et load de la classe Panel ------" << endl;
  
  Panel p1("P02",30,45,300,200);
  cout << "p1 = " << p1 << endl;
  cout << endl;

  cout << "----- Sauvegarde du panneau dans le fichier P.dat -----" << endl;
  ofstream fichier1("P.dat",ios::out);
  p1.save(fichier1);
  fichier1.close();

  cout << "----- Chargement du panneau situe dans le fichier P.dat -----" << endl;
  ifstream fichier2("P.dat",ios::in);
  Panel p2;
  p2.load(fichier2);
  fichier2.close();
  cout << "p2 = " << p2 << endl;
  cout << endl;
}

//*********************************************************************************************
void Essai3()  // Attention : utilisez les flux bytes (read et write) !!!!
{
  cout << "----- 3. Test des methodes save et load de la classe ImagePanel ------" << endl;
  
  ImagePanel p1("P05",30,45,"fleur.bmp");
  cout << "p1 = " << p1 << endl;
  cout << endl;

  cout << "----- Sauvegarde du ImagePanel dans le fichier PI.dat -----" << endl;
  ofstream fichier1("PI.dat",ios::out);
  p1.save(fichier1);
  fichier1.close();

  cout << "----- Chargement du ImagePanel situe dans le fichier PI.dat -----" << endl;
  ifstream fichier2("PI.dat",ios::in);
  ImagePanel p2;
  p2.load(fichier2);
  fichier2.close();
  cout << "p2 = " << p2 << endl;
  cout << endl;
}

