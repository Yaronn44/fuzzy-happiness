/** 
 * @file Etat_chose.cpp
 * @author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
 * @date 06/10/2016
 * @brief EtatChose.cpp, contient également les différents états
 *  
**/

#include <iostream>
#include "EtatChose.hpp"
#include "Chose.hpp"

using namespace std;


//------------------------------------------------------------------------------ Général

Etat_Chose::Etat_Chose(){}

Etat_Chose::~Etat_Chose(){}
void Etat_Chose::fuire(){}
void Etat_Chose::en_securite(){}
void Etat_Chose::explore(){}
void Etat_Chose::pourchasser(){}
void Etat_Chose::seTapperLAffiche(){}


//------------------------------------------------------------------------------ Fuite

Etat_Fuite::Etat_Fuite(Chose *c) : chose_(c){}

Etat_Fuite::~Etat_Fuite(){}

void Etat_Fuite::fuire(){}

void Etat_Fuite::en_securite(){
	chose_->changer_etat_repos();
}

void Etat_Fuite::explore(){}

void Etat_Fuite::pourchasser(){}

void Etat_Fuite::seTapperLAffiche(){
	cout << "MAMENE je me fais victime boloss frangin ! :o " << endl;
}


//------------------------------------------------------------------------------ Repos

Etat_Repos::Etat_Repos(Chose *c) : chose_(c){}

Etat_Repos::~Etat_Repos(){}

void Etat_Repos::fuire(){
	chose_->changer_etat_fuite();
}

void Etat_Repos::en_securite(){}

void Etat_Repos::explore(){
	chose_->changer_etat_explore();
}

void Etat_Repos::pourchasser(){}

void Etat_Repos::seTapperLAffiche(){
	cout << "Je suis dans mon jacuzzi, t'es dans ta jalousie ! " << endl;
}


//------------------------------------------------------------------------------ Explore

Etat_Explore::Etat_Explore(Chose *c) : chose_(c){}

Etat_Explore::~Etat_Explore(){}

void Etat_Explore::fuire(){
	chose_->changer_etat_fuite();
}

void Etat_Explore::en_securite(){
	chose_->changer_etat_repos();
}

void Etat_Explore::explore(){}

void Etat_Explore::pourchasser(){
	chose_->changer_etat_pourchasse();
}

void Etat_Explore::seTapperLAffiche(){
	cout << "Il va faire tout noir ! TAGGLE " << endl;
}


//------------------------------------------------------------------------------ Pourchase

Etat_Pourchasse::Etat_Pourchasse(Chose *c) : chose_(c){}

Etat_Pourchasse::~Etat_Pourchasse(){}

void Etat_Pourchasse::fuire(){
	chose_->changer_etat_fuite();
}

void Etat_Pourchasse::en_securite(){}

void Etat_Pourchasse::explore(){
	chose_->changer_etat_explore();
}

void Etat_Pourchasse::pourchasser(){}

void Etat_Pourchasse::seTapperLAffiche(){
	cout << "PHILIPPE § JE SAIS OU TU TE CACHES §§§§§§§§ " << endl;
}

