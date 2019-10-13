//! \file Humain.cpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Fichier d'implémentation d'une des sous classe de Chose

 // Header implémenté
#include "Zombie.hpp"

 // Lib.
#include <iostream>


using namespace std;


//-------------------------------------------------------------------------------------------------- Constructeur / Destructeur

Zombie::Zombie() : Chose(130, 10, 5)/*, inventaire_(Inventaire(1))*/{}

Zombie::~Zombie(){}


//-------------------------------------------------------------------------------------------------- Méthodes d'interaction

void Zombie::recevoir_degat(int d){
	pdv_ -= d;
}

void Zombie::attaquer(Chose &cible) const{
	cible.recevoir_degat(attaque_);
}

/*
void Zombie::prendre_objet(Stuff obj){
	inventaire_.ajouter_objet(obj);
}
*/
//void Zombie::rentrer_bat(){}

void Zombie::manger(Aliment a){
	set_pdv(a.get_soin()+get_pdv());

}



/*
void Zombie::fuire(){}

void Zombie::en_securite(){
	etat_->en_securite();
}

void Zombie::explore(){
	etat_->explore();
}

void Zombie::pourchasser(){
	etat_->pourchasser();
}
*/

//-------------------------------------------------------------------------------------------------- Getteur / Setteur

void Zombie::set_pdv(int pdv){
	pdv_ = (pdv > maxPdvH) ? maxPdvH : pdv;
}