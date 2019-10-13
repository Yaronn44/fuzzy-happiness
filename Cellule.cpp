//! \file Cellule.cpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Fichier d'implémentation des cellules du monde


 // Header implémenté
#include "Cellule.hpp"

 // Lib.
#include <iostream>


using namespace std;


//-------------------------------------------------------------------------------------------------- Constructeur / Destructeur

Cellule::Cellule() : bruit_(1), n_('R'), inv_(Inventaire(999), pos_(0)){}

Cellule::Cellule(int c, int p) : inv_(Inventaire(999), pos_(p)){
	int d1 = 0;

	switch(c){
		case 4: n_ = 'V'; d1 = 15; bruit_ = 50;
			break;
		case 3: n_ = 'A'; d1 = 10; bruit_ = 35;
			break;
		case 2: n_ = 'C'; d1 = 5; bruit_ = 25;
			break;
		case 1: n_ = 'F'; d1 = 2; bruit_ = 10;
			break;
		default: n_ = 'R'; d1= 0; bruit_ = 1;
			break;
	}


	for (int i = 0; i < d1; ++i){
		densiteH_.push_back(make_shared<Humain>(p));
	}
}

Cellule::~Cellule(){}

//-------------------------------------------------------------------------------------------------- Setters
void Cellule::actualiser_bruit(){
	bruit_ = densiteH_.size() + (densiteZ_.size()*0.50);
}

void Cellule::actualiser_dir_zomb(int d){
	srand(time(NULL));
	for (int i = 0; i < densiteZ_.size(); ++i){
		float nb = rand();
		if (nb <= 0.75)
			densiteZ_.at(i)->set_direction(d);
	}
}

void Cellule::set_bruit(int b){
	bruit_ = b;
}

void Cellule::add_arme(int x){
	for (int i = 0; i < x; ++i){
		inv_.ajouter_objet(make_shared<Arme>("Piste-aux-laids", 10, 35));
	}
}

void Cellule::add_vehicule(int x){
	for (int i = 0; i < x; ++i){
		inv_.ajouter_objet(make_shared<Vehicule>("Velo", 10, 2));
	}
}

void Cellule::add_nourriture(int x){
	for (int i = 0; i < x; ++i){
		inv_.ajouter_objet(make_shared<Aliment>("Substance enrichie en vitamine D", 1, 15));
	}
}

void Cellule::add_metal(int x){
	for (int i = 0; i < x; ++i){
		inv_.ajouter_objet(make_shared<Stuff>("Divers", 1));
	}
}

//-------------------------------------------------------------------------------------------------- Getters

int Cellule::densiteH(){
	return densiteH_.size();
}

int Cellule::densiteZ(){
	return densiteZ_.size();
}

int Cellule::get_bruit(){
	return bruit_;
}

vectPtrHumain Cellule::getListeHumain(){
	return densiteH_;
}

vectPtrZombie Cellule::getListeZombie(){
	return densiteZ_;
}

//-------------------------------------------------------------------------------------------------- Affichage

void Cellule::afficher(){

    //cout << n_;

    /*if(densiteH() > 9){
    	cout << densiteH();
    }
    else{
    	cout << '0' << densiteH();
    }*/

    if(densiteZ() > 9){
    	cout << densiteZ();
    }
    else{
    	cout << '0' << densiteZ();
    }
}


void Cellule::afficherInv(){

    inv_.liste_obj();
}

