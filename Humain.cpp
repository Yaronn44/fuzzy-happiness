/** 
 * @file Humain.hpp
 * @author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
 * @date 06/10/2016
 * @brief Header de Humain.tpp
 *  
**/
#include <iostream>
#include "Humain.hpp"

using namespace std;




// ---------------------------------------------------------------------------- Constructeur / Destructeur

Humain::Humain() : Chose(), inventaire_(Inventaire(5)){

	arme_ = nullptr;
}

Humain::~Humain(){

	arme_ = nullptr;
}


// ---------------------------------------------------------------------------- Méthodes d'interaction

void Humain::recevoir_degat(int d){
	pdv_ -= d;
}

void Humain::attaquer(Chose &cible) const{
	cible.recevoir_degat(attaque_);
}

void Humain::mouvement(){}

void Humain::prendre_objet(Stuff obj){
	inventaire_.ajouter_objet(obj);
}

void Humain::rentrer_bat(){};

void Humain::manger(Aliment a){
	set_pdv(a.get_soin()+get_pdv());
}

// ---------------------------------------------------------------------------- Getteur / Setteur

Arme Humain::get_arme() const{
	return *arme_;
}

void Humain::set_arme(Arme& a){
	arme_ = &a;
	set_attaque(a.get_deg());
}

void Humain::set_pdv(int pdv){
	pdv_ = (pdv > maxPdvH) ? maxPdvH : pdv;
}