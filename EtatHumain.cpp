//! \file Etat_Humain.cpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Permet l'implémentation du pattern States, contient également les différents états

 // Header implémenté
#include "EtatHumain.hpp"

 // Lib.
#include <iostream>
 // Proj.
#include "Humain.hpp"

using namespace std;


//-------------------------------------------------------------------------------------------------- Général

Etat_Humain::Etat_Humain(){}

Etat_Humain::~Etat_Humain(){}
void Etat_Humain::fuire(){}
void Etat_Humain::en_securite(){}
void Etat_Humain::explore(int dir){}
void Etat_Humain::pourchasser(int dir){}

void Etat_Humain::seTapperLAffiche(){}


//-------------------------------------------------------------------------------------------------- Fuite

Etat_Fuite::Etat_Fuite(Humain *c) : chose_(c){}

Etat_Fuite::~Etat_Fuite(){}

void Etat_Fuite::fuire(){}

void Etat_Fuite::en_securite(){
	chose_->changer_etat_repos();
}

void Etat_Fuite::explore(int dir){}

void Etat_Fuite::pourchasser(int dir){}


void Etat_Fuite::seTapperLAffiche(){
	cout << "MAMENE je me fais victime boloss frangin ! :o " << endl;
}


//-------------------------------------------------------------------------------------------------- Repos

Etat_Repos::Etat_Repos(Humain *c) : chose_(c){}

Etat_Repos::~Etat_Repos(){}

void Etat_Repos::fuire(){
	chose_->changer_etat_fuite();
}

void Etat_Repos::en_securite(){}

void Etat_Repos::explore(int dir){
	chose_->changer_etat_explore(dir);
}

void Etat_Repos::pourchasser(int dir){}

void Etat_Repos::seTapperLAffiche(){
	cout << "Je suis dans mon jacuzzi, t'es dans ta jalousie ! " << endl;
}


//-------------------------------------------------------------------------------------------------- Explore

Etat_Explore::Etat_Explore(Humain *c) : chose_(c){}

Etat_Explore::~Etat_Explore(){}

void Etat_Explore::fuire(){
	chose_->changer_etat_fuite();
}

void Etat_Explore::en_securite(){
	chose_->changer_etat_repos();
}

void Etat_Explore::explore(int dir){}

void Etat_Explore::pourchasser(int dir){
	chose_->changer_etat_pourchasse(dir);
}


void Etat_Explore::seTapperLAffiche(){
	cout << "Il va faire tout noir ! TAGGLE " << endl;
}


//-------------------------------------------------------------------------------------------------- Pourchasse

Etat_Pourchasse::Etat_Pourchasse(Humain *c) : chose_(c){}

Etat_Pourchasse::~Etat_Pourchasse(){}

void Etat_Pourchasse::fuire(){
	chose_->changer_etat_fuite();
}

void Etat_Pourchasse::en_securite(){}

void Etat_Pourchasse::explore(int dir){
	chose_->changer_etat_explore(dir);
}

void Etat_Pourchasse::pourchasser(int dir){}


void Etat_Pourchasse::seTapperLAffiche(){
	cout << "PHILIPPE § JE SAIS OU TU TE CACHES §§§§§§§§ " << endl;
}

