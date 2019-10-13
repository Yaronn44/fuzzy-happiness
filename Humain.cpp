//! \file Humain.cpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Fichier d'implémentation d'une des sous classe de Chose

//#include "Observer.hpp"

#include "Humain.hpp"


//-------------------------------------------------------------------------------------------------- Constructeur / Destructeur

Humain::Humain(int p) : Chose(), inventaire_(Inventaire(5)), vaRevenir_(true), contamination_(0), posCel_(p){
	obs_ = nullptr;
	arme_ = nullptr;
}

Humain::~Humain(){}


//-------------------------------------------------------------------------------------------------- Méthodes d'interaction

void Humain::recevoir_degat(int d){
	pdv_ -= d;
}


void Humain::attaquer(Chose &cible) const{
	cible.recevoir_degat(attaque_);
	if(arme_ != nullptr)
		arme_->sub_res(1);
}

void Humain::mouvement(){
	
}

void Humain::prendre_objet(Stuff obj){
	//inventaire_.ajouter_objet(obj);
	notifier_obs();
}


void Humain::manger(Aliment a){
	set_pdv(a.get_soin()+get_pdv());
}

void Humain::fuire(){
	etat_.fuire();
}

void Humain::en_securite(){
	etat_.en_securite();
}

void Humain::explore(){
	etat_.explore();
}

void Humain::pourchasser(){
	etat_.pourchasser();
}

//-------------------------------------------------------------------------------------------------- Getteur / Setteur

Arme Humain::get_arme() const{
	return *arme_;
}

void Humain::set_arme(Arme& a){
	arme_ = &a;
	set_attaque(a.get_deg());
	notifier_obs();
}

void Humain::set_pdv(int pdv){
	pdv_ = (pdv > maxPdvH) ? maxPdvH : pdv;
	notifier_obs();
}

std::string Humain::get_nom_arme(){
	if(arme_ != nullptr){
		return arme_->get_nom();
	}
	else return "Pas d'arme !";
}



