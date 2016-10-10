/** 
 * @file Inventaire.hpp
 * @author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
 * @date 06/10/2016
 * @brief Header de Inventaire.tpp
 *  
**/

#include "Inventaire.hpp"
#include "Stuff.hpp"


 using namespace std;


Inventaire::Inventaire(int t) : taille_(t){}

Inventaire::~Inventaire(){}

void Inventaire::ajouter_objet(Stuff o){
	if (inventaire_.size() < taille_)
		inventaire_.push_back(o);
}

void Inventaire::retirer_objet(Stuff o){

	if (!obj_appartient(o))
		return;
	else{
		int i = 0;
		
		while(inventaire_[i].get_nom() != o.get_nom()){
			i++;
		}
		inventaire_.erase(inventaire_.begin()+i);
	}
}

bool Inventaire::obj_appartient(Stuff o){

	for (unsigned int i = 0; i < inventaire_.size(); ++i){
		if (inventaire_[i].get_nom() == o.get_nom()){
			return true;
		}
	}
	return false;
}