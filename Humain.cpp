//! \file Humain.cpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Fichier d'implémentation d'une des sous classe de Chose

//#include "Observer.hpp"

#include "Humain.hpp"
#include "EtatHumain.hpp"

using namespace std;


//-------------------------------------------------------------------------------------------------- Constructeur / Destructeur

Humain::Humain() : Chose(100, 1, 8), inventaire_(Inventaire(5)), vaRevenir_(true), contamination_(0){
	obs_ = nullptr;
	arme_ = nullptr;

	fuite_ = make_shared<Etat_Fuite>(this);
	repos_ = make_shared<Etat_Repos>(this);
	explore_ = make_shared<Etat_Explore>(this);
	pourchasse_ = make_shared<Etat_Pourchasse>(this);
	etat_ = repos_;
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

void Humain::prendre_objet(Stuff obj){
	//inventaire_.ajouter_objet(obj);
	notifier_obs();
}


void Humain::manger(Aliment a){
	set_pdv(a.get_soin()+get_pdv());
}


void Humain::changer_etat_fuite(){

	int x = nbRand(3);
	int y = nbRand(3);

	direction_ = x + y*wMonde_;
	etat_= fuite_;
}

void Humain::changer_etat_repos(){
	
	direction_ = pos_;
	etat_ = repos_;
}

void Humain::changer_etat_explore(int dir){

	direction_ = dir;
	etat_ = explore_;
}

void Humain::changer_etat_pourchasse(int dir){

	direction_ = dir;
	etat_ = pourchasse_;
}


void Humain::fuire(){
	etat_->fuire();
}

void Humain::en_securite(){
	etat_->en_securite();
}

void Humain::explore(int dir){
	etat_->explore(dir);
}

void Humain::pourchasser(int dir){
	etat_->pourchasser(dir);
}



//-------------------------------------------------------------------------------------------------- Getteur / Setteur

void Humain::set_arme(Arme& a){
	arme_ = &a;
	set_attaque(a.get_deg());
	notifier_obs();
}

void Humain::set_pdv(int pdv){
	pdv_ = (pdv > maxPdvH) ? maxPdvH : pdv;
	notifier_obs();
}


Arme Humain::get_arme() const{
	return *arme_;
}


std::string Humain::get_nom_arme(){
	if(arme_ != nullptr){
		return arme_->get_nom();
	}
	else return "Pas d'arme !";
}


bool Humain::test_fuite(){
	return etat_ == fuite_;
}

bool Humain::test_repos(){
	return etat_ == repos_;
}

bool Humain::test_pourchasse(){
	return etat_ == pourchasse_;
}

bool Humain::test_explore(){
	return etat_ == explore_;
}

