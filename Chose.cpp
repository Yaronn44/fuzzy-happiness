//! \file Chose.cpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Fichier d'implémentation des différentes choses peuplant le monde

 // Header implémenté
#include "Chose.hpp"

 // Lib.
#include <iostream>


using namespace std;

//-------------------------------------------------------------------------------------------------- Constructeur / Destructeur

Chose::Chose() : pdv_(100), attaque_(1), vitesse_(1), fatigue_(0), direction_(0), x_(5), y_(5){

    /*fuite_ = make_shared<Etat_Fuite>(this);
	repos_ = make_shared<Etat_Repos>(this);
	explore_ = make_shared<Etat_Explore>(this);
	pourchasse_ = make_shared<Etat_Pourchasse>(this);
	etat_ = repos_;*/
}

Chose::Chose(int pdv, int a, int v) : pdv_(pdv), attaque_(a), vitesse_(v), fatigue_(0), direction_(0), x_(5), y_(5){}

Chose::~Chose(){}

//-------------------------------------------------------------------------------------------------- Changement d'Etats

/*
void Chose::changer_etat_fuite(){

	etat_= fuite_;
}

void Chose::changer_etat_repos(){

	etat_ = repos_;
}

void Chose::changer_etat_explore(){

	etat_ = explore_;
}

void Chose::changer_etat_pourchasse(){

	etat_ = pourchasse_;
}

void Chose::fuire(){}

void Chose::en_securite(){

}

void Chose::explore(){}

void Chose::pourchasser(){}

*/


//-------------------------------------------------------------------------------------------------- Méthodes d'interaction

void Chose::recevoir_degat(int d){}

void Chose::attaquer(Chose &cible) const{}

int Chose::mouvement(){

	int resX = (direction_%wMonde_) - (pos_%wMonde_);
	int resY = (direction_/wMonde_) - (pos_/wMonde_);

	if (resX == 0){
		if (resY == 0){
	 		// La chose ne bouge pas
	 	}
	 	else if(resY > 0){
	 		if (y_ + vitesse_ > 10){
	 			y_ = (y_ + vitesse_)%10;
	 			pos_ += wMonde_;
	 		}
	 		else
	 			y_ += vitesse_;
	 	}
	 	else{
	 		if (y_ - vitesse_ < 0){
	 			y_ = 10 + (y_ - vitesse_);
	 			pos_ -= wMonde_;
	 		}
	 		else
	 			y_ -= vitesse_;
	 	}
	}
	else if(resX > 0){

		if (x_ + vitesse_ > 10){
			x_ = (x_ + vitesse_)%10;
			++pos_;
		}
		else
			x_ += vitesse_;

		if (resY == 0){

	 	}
	 	else if(resY > 0){
	 		if (y_ + vitesse_ > 10){
	 			y_ = (y_ + vitesse_)%10;
	 			pos_ += wMonde_;
	 		}
	 		else
	 			y_ += vitesse_;
	 	}
	 	else{
	 		if (y_ - vitesse_ < 0){
	 			y_ = 10 + (y_ - vitesse_);
	 			pos_ -= wMonde_;
	 		}
	 		else
	 			y_ -= vitesse_;
	 	}
	}
	else{
		if (x_ - vitesse_ < 0){
			x_ = 10 + (x_ - vitesse_);
			--pos_;
		}
		else
			x_ -= vitesse_;

		if (resY == 0){
	 		
	 	}
	 	else if(resY > 0){
	 		if (y_ + vitesse_ > 10){
	 			y_ = (y_ + vitesse_)%10;
	 			pos_ += wMonde_;
	 		}
	 		else
	 			y_ += vitesse_;
	 	}
	 	else{
	 		if (y_ - vitesse_ < 0){
	 			y_ = 10 + (y_ - vitesse_);
	 			pos_ -= wMonde_;
	 		}
	 		else
	 			y_ -= vitesse_;
	 	}
	}
	return pos_;
}

//void Chose::prendre_objet(Stuff obj){}

void Chose::manger(Aliment a){}


//-------------------------------------------------------------------------------------------------- Getteur & Setteur

int Chose::get_pdv() const{
	return pdv_;
}

int Chose::get_attaque() const{
	return attaque_;
}

int Chose::get_vitesse() const{
	return vitesse_;
}

int Chose::get_fatigue() const{
	return fatigue_;
}

/*shared_ptr<Etat_Chose> Chose::get_etat() const{
	return etat_;
}*/

int Chose::get_pos() const{
	return pos_;
}

int Chose::get_dir() const{
	return direction_;
}

int Chose::get_wMonde() const{
	return wMonde_;
}


void Chose::set_pdv(int pdv){
	pdv_ = pdv;
}

void Chose::set_attaque(int attaque){
	attaque_ = attaque;
}

void Chose::set_vitesse(int vitesse){
	vitesse_ = vitesse;
}

void Chose::set_fatigue(int fatigue){
	if (fatigue_ + fatigue < 0){
		fatigue_ = 0
	}
	else{
		fatigue_ += fatigue;
	}
}

void Chose::set_pos(int p){
	pos_ = p;
}

void Chose::set_direction(int d){
	direction_ = d;
}

void Chose::set_wMonde(int w){
	wMonde_ = w;
}


//-------------------------------------------------------------------------------------------------- Debug

void Chose::seTapperLAffiche(){

	cout << "Bonjou' mon g'and maît'e ! Je ne suis qu'une simple chose";
}



