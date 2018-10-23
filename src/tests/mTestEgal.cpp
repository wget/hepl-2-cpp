#include <stdlib.h>
#include <iostream>
using namespace std;
#include "Couleur.h"
#include "Panneau.h"
#include "Fraction.h"
#include "Bouton.h"
#include "PanneauImage.h"
#include "Liste.h"
#include "ListeBase.h"

#include "Ecran.h"

void ClassCouleur(const char*);
void ClassPanneau(const char*);
void ClassFraction(const char*);
void ClassBouton(const char*);
void ClassPanneauImage(const char*);
void ClassListe(const char*);

int main()
{
ClassCouleur("Couleur : C2 = C1");
ClassPanneau("Panneau : P2 = P1");
ClassFraction("Fraction  : F2 = F1");
ClassBouton("Bouton : B2 = B1");
ClassPanneauImage("PanneauImage : PI2 = PI1");
ClassListe("Liste : Liste2(Liste1)");
exit(0);
}

void ClassCouleur(const char * Texte)
{
EffEcran();
AffChaine(Texte,2,1,GRAS);
cout <<endl;
Couleur	C1(10,20,30,"AuHasard");
Titre("C1 (avant) : ");
C1.Affiche();
{
Titre("C2 : ");
cout <<endl;
Couleur	C2;
C2 = C1;
C2.Affiche();
}
Couleur	CBidon;                // Juste pour decaler la pile
CBidon.setNom("xxxxxxxxxxxxxxxxxxxx");

Titre("C1 : "); 
C1.Affiche();
Pause();
}

void ClassPanneau(const char * Texte)
{
EffEcran();
AffChaine(Texte,2,1,GRAS);
cout <<endl;
Couleur	C1(10,20,30,"AuHasard");
Panneau	P1("P01",5,5,5,5,C1);
Titre("P1 (avant) : ");
P1.Affiche();
{ 
Titre("P2 :");
Panneau	P2;
P2 = P1;
P2.Affiche();
}
//cout << "suite" << endl;
Couleur	CBidon;                // Juste pour decaler la pile
CBidon.setNom("xxxxxxxxxxxxxxxxxxxx");

Titre("P1 : ");
P1.Affiche();

Pause();
}

void ClassFraction(const char * Texte)
{
EffEcran();
AffChaine(Texte,2,1,GRAS);
cout <<endl;
Fraction	F1(11,19,Fraction::negatif);
Titre("F1 (avant) : ");
//F1.Affiche();
cout << F1 << endl;
{ 
Titre("F2 :");
Fraction	F2;
F2 = F1;

//F2.Affiche();
cout << F2 << endl;
}
//Point*	PBidon = new Point();	// Juste pour decaler la pile
//PBidon->setX(5);
Couleur	CBidon;               	// Toujours pour decaler la pile
CBidon.setNom("xxx");

Titre("F1 : ");
//F1.Affiche();
cout << F1 << endl;
Pause();
}

void ClassBouton(const char * Texte)
{
EffEcran();
AffChaine(Texte,2,1,GRAS);
cout <<endl;
Couleur	C1(10,20,30,"AuHasard");
Panneau	P1("P01",5,5,5,5,C1);
Bouton	B1("B01",5,5,5,5,C1);
Titre("B1 (avant) :");
B1.Affiche();
{ 
Bouton	B2;
B2 = B1;
Titre("B2 :");
B2.Affiche();
}
Bouton	BBidon;                // Juste pour decaler la pile
BBidon.setNom("B0000000000000000000000000000000000000000");
Titre("B1 : ");
B1.Affiche();

Pause();
}
void ClassPanneauImage(const char* Texte)
{
EffEcran();
AffChaine(Texte,2,1,GRAS);
cout <<endl;

//Point	P(10,45);
//Panneau	P1("PourTest",5,5,5,5,C1);
Couleur	C1(10,20,30,"AuHasard");
PanneauImage	PI1("P01",5,5,"ToujoursEssai.dat");
Titre("PI1 (avant) : ");
PI1.Affiche();
{
PanneauImage	PI2;
PI2 = PI1;
Titre("PI2 : ");
PI2.Affiche();
//cout << P2.getInfos() << endl;
}
PanneauImage*	PBidon = new PanneauImage();	// Juste pour decaler la pile
PBidon->setFichier("PourDecaler.dat");
//Couleur	CBidon;               	// Toujours pour decaler la pile
//CBidon.setNom("xxx");
Titre("PI1 : ");
PI1.Affiche();
//cout << P1.getInfos() << endl;
Pause();
}

void ClassListe(const char * Texte)
{
EffEcran();
AffChaine(Texte,2,1,GRAS);
cout <<endl;
Liste<PanneauImage> L1;


L1.insere(PanneauImage("P01",20,40,"un.bmp"));
L1.insere(PanneauImage("P02",20,40,"deux.bmp"));
L1.insere(PanneauImage("P03",20,40,"trois.bmp"));
Titre("L1 (avant) : ");
L1.Affiche();
{ 
Liste<PanneauImage> L2;
L2 = L1;
Titre("Liste2 :");
L2.Affiche();
}
PanneauImage*	PBidon = new PanneauImage();	// Juste pour decaler la pile
PBidon->setX(5);
Couleur	CBidon;               	 //Toujours pour decaler la pile
CBidon.setNom("xxxxxxxxxxxxxxxxxxxx");

Titre("Liste1 : ");
L1.Affiche();

Pause();
}
