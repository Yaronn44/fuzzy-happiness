/** 
 * @file Zombie.hpp
 * @author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
 * @date 06/10/2016
 * @brief Header de Zombie.tpp
 *  
**/
#include <iostream>
#include "Zombie.hpp"

using namespace std;




// ---------------------------------------------------------------------------- Constructeur / Destructeur

Zombie::Zombie() : Chose(), inventaire_(Inventaire(1)){}

Zombie::~Zombie(){}


// ---------------------------------------------------------------------------- Méthodes d'interaction

void Zombie::recevoir_degat(int d){
	pdv_ -= d;
}

void Zombie::attaquer(Chose &cible) const{
	cible.recevoir_degat(attaque_);
}

void Zombie::mouvement(){}

void Zombie::prendre_objet(Stuff obj){
	inventaire_.ajouter_objet(obj);
}

void Zombie::rentrer_bat(){};

void Zombie::manger(Aliment a){
	set_pdv(a.get_soin()+get_pdv());

}

// ---------------------------------------------------------------------------- Getteur / Setteur

void Zombie::set_pdv(int pdv){
	pdv_ = (pdv > maxPdvH) ? maxPdvH : pdv;
}