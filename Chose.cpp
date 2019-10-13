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

Chose::Chose(int pos) : pdv_(100), attaque_(1), vitesse_(1), fatigue_(0), x_(5), y_(5), direction_(0), posCel_(pos){

    fuite_ = Etat_Fuite(this);
	repos_ = Etat_Repos(this);
	explore_ = Etat_Explore(this);
	pourchasse_ = Etat_Pourchasse(this);
	etat_ = repos_;
}

Chose::~Chose(){}

//-------------------------------------------------------------------------------------------------- Changement d'Etats

void Chose::changer_etat_fuite(){

	etat_ = fuite_;
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

void Chose::en_securite(){}

void Chose::explore(){}

void Chose::pourchasser(){}


//-------------------------------------------------------------------------------------------------- Méthodes d'interaction

void Chose::recevoir_degat(int d){}

void Chose::attaquer(Chose &cible) const{}

void Chose::mouvement(){}

void Chose::prendre_objet(Stuff obj){}

//void Chose::rentrer_bat(){}

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

Etat_Chose Chose::get_etat() const{
	return etat_;
}

int Chose::get_dir() const{
	return direction_;
}

int Chose::get_pos() const{
	return posCel_;
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
	fatigue_ = fatigue;
}

void Chose::set_direction(int d){
	direction_ = d;
}

void Chose::set_pos(int p){
	posCel_ = p;
}

//-------------------------------------------------------------------------------------------------- Debug

void Chose::seTapperLAffiche(){

	cout << "Bonjou' mon g'and maît'e !";
	etat_.seTapperLAffiche();
}



