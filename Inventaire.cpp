//! \file Inventaire.cpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Fichier d'implémentation des inventaires
 
 // Header implémenté
#include "Inventaire.hpp"
 
 // Proj.
#include "Stuff.hpp"


using namespace std;

//-------------------------------------------------------------------------------------------------- Constructeur / Destructeur

Inventaire::Inventaire(int t) : taille_(t){}

Inventaire::~Inventaire(){}

//-------------------------------------------------------------------------------------------------- Méthodes

void Inventaire::ajouter_objet(shared_ptr<Stuff> o){
	if (inventaire_.size() < taille_)
		inventaire_.push_back(o);
}

void Inventaire::retirer_objet(shared_ptr<Stuff> o){

	if (!obj_appartient(o))
		return;
	else{
		int i = 0;
		
		while(inventaire_[i]->get_id() != o->get_id()){
			i++;
		}
		inventaire_.erase(inventaire_.begin()+i);
	}
}

bool Inventaire::obj_appartient(shared_ptr<Stuff> o){

	for (unsigned int i = 0; i < inventaire_.size(); ++i){
		if (inventaire_[i]->get_id() == o->get_id()){
			return true;
		}
	}
	return false;
}

void Inventaire::liste_obj(){
	for (unsigned int i = 0; i < inventaire_.size(); ++i){
		cout << "id : " << inventaire_[i]->get_id() << " - ";
		inventaire_[i]->afficher();
		cout << endl;
	}
}

