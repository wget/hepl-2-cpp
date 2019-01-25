#include <stdlib.h>
#include <iostream>
using namespace std;
#include <time.h>

#include "../Panel.hpp"
#include "../ImagePanel.hpp"
#include "../Button.hpp"
#include "../ImageButton.hpp"

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
  cout << " 1. Test de la classe ImagePanel" << endl;
  cout << " 2. Test de la classe Button" << endl;
  cout << " 3. Test de la classe ImageButton" << endl;
  cout << " 4. Heritage et virtualite : Test de la methode NON-VIRTUELLE display()" << endl;
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
// A FAIRE : - la classe ImagePanel qui herite de Panel
//           - qui possede en plus une chaine de caracteres fichier
//           - redefinir les operateurs =, << et >> de ImagePanel
//***********************************************************************************************
//*** Tests de la classe ImagePanel ***********************************************************
//***********************************************************************************************
void Essai1()
{
  cout << "(1.1) ***** Test du constructeur par defaut + setters de ImagePanel ***************" << endl;
  { 
    ImagePanel p;
    cout << "p = " << p << endl;
    cout << "--> modification de p" << endl;
    p.setX(20);
    p.setY(40);
    p.setFilename("fleche.bmp");
    cout << "p = " << p << endl << endl;
  }

  cout << "(1.2) ***** Test du constructeur d'initialisation + getters de ImagePanel *********" << endl;
  { 
    ImagePanel p("P01",30,40,"warning.bmp");
    cout << "p = " << p << endl;
    cout << "Position de p = (" << p.getX() << "," << p.getY() << ")" << endl;
    cout << "Fichier de p  = " << p.getFilename() << endl << endl;
  }

  cout << "(1.3) ***** Test du constructeur de copie de ImagePanel ***************************" << endl;
  {
    ImagePanel *pp = new ImagePanel("P02",45,60,"photoDenys.bmp");
    cout << "Objet de base = " << *pp << endl;

    ImagePanel p(*pp);
    cout << "--> Destruction objet de base" << endl;
    delete pp;
    cout << "Copie = " << p << endl << endl; 
  }

  cout << "(1.4) ***** Test de l'operateur = de ImagePanel ***********************************" << endl;
  {
    ImagePanel *pp = new ImagePanel("P02",45,60,"photoDenys.bmp");
    cout << "Objet de base = " << *pp << endl;

    ImagePanel p;
    p = *pp;
    cout << "--> Destruction objet de base" << endl;
    delete pp;
    cout << "Objet affecte = " << p << endl << endl;     
  }

  cout << "(1.5) ***** Test de l'operateur >> de ImagePanel **********************************" << endl;
  {
    ImagePanel p;
    cin >> p;
    cout << "--> p = " << p << endl << endl;
  }
}

//***********************************************************************************************
// A FAIRE : - la classe Button qui herite de Panel
//           - qui possede en plus une methode d'instance click
//           - redefinir les operateurs =, << et >> de Button
//***********************************************************************************************
//*** Tests de la classe Button *****************************************************************
//***********************************************************************************************
void Essai2()
{
  cout << "(2.1) ***** Test du constructeur par defaut + setters de Button *********************" << endl;
  { 
    Button b;;
    cout << "b = " << b << endl;
    cout << "--> modification de b" << endl;
    b.setX(20);
    b.setY(40);
    b.setColor(Color(120,120,60));
    cout << "b = " << b << endl << endl;
  }

  cout << "(2.2) ***** Test du constructeur d'initialisation complet + getters de Button *******" << endl;
  { 
    Button b("B01",30,40,50,50,Color::SILVER);
    cout << "b = " << b << endl;
    cout << "Position de b = (" << b.getX() << "," << b.getY() << ")" << endl;
    cout << "Color de b  = " << b.getColor() << endl << endl;
  }

  cout << "(2.3) ***** Test du constructeur de copie de Button *********************************" << endl;
  {
    Button *pb = new Button("B02",45,60,50,50);
    cout << "Objet de base = " << *pb << endl;

    Button b(*pb);
    cout << "--> Destruction objet de base" << endl;
    delete pb;
    cout << "Copie = " << b << endl << endl; 
  }

  cout << "(2.4) ***** Test de l'operateur = de Button *****************************************" << endl;
  {
    Button *pb = new Button("B03",10,10,60,60,Color(128,128,128));
    cout << "Objet de base = " << *pb << endl;

    Button b;
    b = *pb;
    cout << "--> Destruction objet de base" << endl;
    delete pb;
    cout << "Objet affecte = " << b << endl << endl;     
  }

  cout << "(2.5) ***** Test de l'operateur >> et de la methode click de Button ******************" << endl;
  {
    Button b;
    cin >> b;
    cout << "--> b = " << b << endl << endl;
    int x,y;
    cout << "click X = "; cin >> x;
    cout << "click Y = "; cin >> y;
    cout << "Test de click : ";
    b.click(x,y);
    cout << endl;
  }
}

//***********************************************************************************************
// A FAIRE : - la classe ImageButton qui herite de ImagePanel ET de Button
//           - redefinir les operateurs =, << et >> de ImageButton
//***********************************************************************************************
//*** Tests de la classe ImageButton ************************************************************
//***********************************************************************************************
void Essai3()
{
  cout << "(3.1) ***** Test du constructeur par defaut + setters de ImageButton *****************" << endl;
  { 
    ImageButton b;
    cout << "b = " << b << endl;
    cout << "--> modification de b" << endl;
    b.setX(20);
    b.setY(40);
    b.setFilename("button_plus.bmp");   // Methode heritee de ImagePanel
    cout << "b = " << b << endl << endl;
  }

  cout << "(3.2) ***** Test du constructeur d'initialisation + getters de ImageButton ***********" << endl;
  { 
    ImageButton b("B01",30,40,"button_minus.bmp");
    cout << "b = " << b << endl;
    cout << "Position de b = (" << b.getX() << "," << b.getY() << ")" << endl;
    cout << "Fichier de b  = " << b.getFilename() << endl << endl;   // Methode heritee de ImagePanel
  }

  cout << "(3.3) ***** Test du constructeur de copie de ImageButton ***************************" << endl;
  {
    ImageButton *pb = new ImageButton("B02",45,60,"boutonCancel.bmp");
    cout << "Objet de base = " << *pb << endl;

    ImageButton b(*pb);
    cout << "--> Destruction objet de base" << endl;
    delete pb;
    cout << "Copie = " << b << endl << endl; 
  }

  cout << "(3.4) ***** Test de l'operateur = de ImageButton ***********************************" << endl;
  {
    ImageButton *pb = new ImageButton("B03",35,70,"boutonQuitter.bmp");
    cout << "Objet de base = " << *pb << endl;

    ImageButton b;
    b = *pb;
    cout << "--> Destruction objet de base" << endl;
    delete pb;
    cout << "Objet affecte = " << b << endl << endl;     
  }

  cout << "(3.5) ***** Test de l'operateur >> et de la methode click de ImageButton ************" << endl;
  {
    ImageButton b;
    cin >> b;
    cout << "--> b = " << b << endl << endl;
    int x,y;
    cout << "click X = "; cin >> x;
    cout << "click Y = "; cin >> y;
    cout << "Test de click : ";
    b.click(x,y);   // Methode heritee de Button
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

  cout << "----- 4.1 Allocation dynamique de Panelx ------------------------------------------------" << endl;
  Panel* panneau[10];

  for (int i=0 ; i<10 ; i++)   // Tracez vos constructeurs !!!
  {
    cout << "panneau[" << i << "] : ";
    int n = rand()%4;
    switch(n)
    {
      case 0 : panneau[i] = new Panel("P01",10,10,300,200,Color::SILVER);
               cout << "Panel" << endl;
               break;

      case 1 : panneau[i] = new ImagePanel("P02",30,30,"PhotoAnne.bmp");
               cout << "ImagePanel" << endl;
               break;

      case 2 : panneau[i] = new Button("B03",40,40,50,50);
               cout << "Button" << endl;
               break;

      case 3 : panneau[i] = new ImageButton("B04",70,70,"boutonClear.bmp");
               cout << "ImageButton" << endl;
               break;
    }
  }
  cout << endl;

  cout << "----- 4.2 Test de la methode NON-VIRTUELLE display() (redefinie dans chaque classe heritee) -------" << endl;
  for (int i=0 ; i<10 ; i++)
  {
    cout << "panneau[" << i << "] : "; // << forme[i]->getInfos() << endl;
    panneau[i]->display();
  }
  cout << endl;


  cout << "----- 4.3 Liberation memoire --------------------------------------------------------------" << endl;
  for (int i=0 ; i<10 ; i++) delete panneau[i];  // Tout se passe-t-il comme vous voulez ?
  // Pour etre plus precis, quid des destructeurs et de la virtualite ?
}

//***********************************************************************************************
// A FAIRE : la methode VIRTUELLE getType() dans Panel, ImagePanel, Button et ImageButton
//***********************************************************************************************
//*** Tests de la virtualite ********************************************************************
//***********************************************************************************************
void Essai5()
{
  srand((unsigned)time(NULL));

  cout << "----- 5.1 Allocation dynamique de Panelx ------------------------------------------------" << endl;
  Panel* panneau[10];

  for (int i=0 ; i<10 ; i++)   // Tracez vos constructeurs !!!
  {
    cout << "panneau[" << i << "] : ";
    int n = rand()%4;
    switch(n)
    {
      case 0 : panneau[i] = new Panel("P01",10,10,300,200,Color::SILVER);
               cout << "Panel" << endl;
               break;

      case 1 : panneau[i] = new ImagePanel("P02",30,30,"PhotoAnne.bmp");
               cout << "ImagePanel" << endl;
               break;

      case 2 : panneau[i] = new Button("B03",40,40,50,50);
               cout << "Button" << endl;
               break;

      case 3 : panneau[i] = new ImageButton("B04",70,70,"boutonClear.bmp");
               cout << "ImageButton" << endl;
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

  cout << "----- 6.1 Allocation dynamique de Panelx -----------------------------------------" << endl;
  Panel* panneau[10];

  for (int i=0 ; i<10 ; i++)   // Tracez vos constructeurs !!!
  {
    cout << "panneau[" << i << "] : ";
    int n = rand()%4;
    switch(n)
    {
      case 0 : panneau[i] = new Panel("P01",10,10,300,200,Color::SILVER);
               cout << "Panel" << endl;
               break;

      case 1 : panneau[i] = new ImagePanel("P02",30,30,"PhotoAnne.bmp");
               cout << "ImagePanel" << endl;
               break;

      case 2 : panneau[i] = new Button("B03",40,40,50,50);
               cout << "Button" << endl;
               break;

      case 3 : panneau[i] = new ImageButton("B04",70,70,"boutonClear.bmp");
               cout << "ImageButton" << endl;
               break;
    }
  }
  cout << endl;

  cout << "----- 6.2 Test du downcasting et dynamic-cast ------------------------------" << endl;
  for (int i=0 ; i<10 ; i++)
  {
    cout << "panneau[" << i << "] ";
    Panel* pp = dynamic_cast<Panel*>(panneau[i]);
    if (pp != NULL) cout << "est un Panel, ";
    ImagePanel* ppi = dynamic_cast<ImagePanel*>(panneau[i]);
    if (ppi != NULL) cout << "est un ImagePanel, ";
    Button* pb = dynamic_cast<Button*>(panneau[i]);
    if (pb != NULL) cout << "est un Button, ";
    ImageButton* pbi = dynamic_cast<ImageButton*>(panneau[i]);
    if (pbi != NULL) cout << "est un ImageButton";
    cout << endl;
  }
  cout << endl;

  cout << "----- 6.3 Liberation memoire ------------------------------------------------" << endl;
  for (int i=0 ; i<10 ; i++) delete panneau[i];
}

