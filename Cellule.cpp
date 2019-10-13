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

Cellule::Cellule() : bruit_(1), n_('R'), inv_(Inventaire(999)){}

Cellule::Cellule(int c) : inv_(Inventaire(999)){
	int d1 = 0, d2 = 0;

	switch(c){
		case 4: n_ = 'V'; d1 = 20; d2 = 5; 
			break;
		case 3: n_ = 'A'; d1 = 15; d2 = 3;
			break;
		case 2: n_ = 'C'; d1 = 5; d2 = 2;
			break;
		case 1: n_ = 'F'; d1 = 6; d2 = 1;
			break;
		default: n_ = 'R'; d1 = 0; d2 = 0;
			break;
	}

	genererSprite(c);


	for (int i = 0; i < d1; ++i){
		densiteH_.push_back(make_shared<Humain>());
		densiteH_.at(i)->set_pos(pos_);
		densiteH_.at(i)->set_direction(pos_);
		densiteH_.at(i)->set_wMonde(wMonde_);
	}

	for (int i = 0; i < d2; ++i){
		densiteZ_.push_back(make_shared<Zombie>());
		densiteZ_.at(i)->set_pos(pos_);
		densiteZ_.at(i)->set_direction(pos_);
		densiteZ_.at(i)->set_wMonde(wMonde_);
	}

	actualiser_bruit();
}


void Cellule::genererSprite(int c){
	sprite_[0] = "~~~~~~";

	if(c == 4){
		sprite_[1] = "~City~";
	}
	else if (c == 3){
		sprite_[1] = "~Town~";

	}
	else if (c == 2){

		sprite_[1] = "~Near~";		
		
	}
	else if (c == 1){
		sprite_[1] = "~Farm~";
		
	}
	else{
		sprite_[1] = "~None~";		
	}
	sprite_[2] = "~Z=";
	sprite_[3] = "~H=";
	sprite_[4] = "~~~~~~";

}



Cellule::~Cellule(){}

//-------------------------------------------------------------------------------------------------- Setters
void Cellule::actualiser_bruit(){
	bruit_ = densiteH_.size()*2 + (densiteZ_.size()*0.50);
}

void Cellule::actualiser_dir_zomb(int d){

	for (int i = 0; i < densiteZ_.size(); ++i){
		float nb = nbRand(10);
		if (nb <= 8)
			densiteZ_.at(i)->set_direction(d);
		else if(nb > 8 && nb <= 9)
			densiteZ_.at(i)->set_direction(pos_);
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

void Cellule::set_pos(int p){
	pos_ = p;
}

void Cellule::set_wMonde(int w){
	wMonde_ = w;
}

//-------------------------------------------------------------------------------------------------- Getters

int Cellule::densiteH() const{
	return densiteH_.size();
}

int Cellule::densiteZ() const{
	return densiteZ_.size();
}

int Cellule::get_bruit() const{
	return bruit_;
}

vectPtrHumain Cellule::get_liste_humain() const{
	return densiteH_;
}

vectPtrZombie Cellule::get_liste_zombie() const{
	return densiteZ_;
}

int Cellule::get_pos() const{
	return pos_;
}

int Cellule::get_wMonde() const{
	return wMonde_;
}

shared_ptr<Humain> Cellule::get_humain(int ind) const{
	return densiteH_.at(ind);
}

shared_ptr<Zombie> Cellule::get_zombie(int ind) const{
	return densiteZ_.at(ind);
}

Inventaire Cellule::get_inv(){
	return inv_;
}

int Cellule::get_taille_inv(){
	return inv_.nb_objets();
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

    /*if(densiteZ() > 9){
    	cout << densiteZ();
    }
    else{
    	cout << '0' << densiteZ();
    }*/

    //cout << "_" << n_;
    cout << pos_;
}

void Cellule::afficher(int i){
	if (i < 2 || i == 4){
		cout << sprite_[i];
	}
    else if(i == 2){
    	cout << sprite_[i];
    	if(densiteZ() < 9)
    		cout << " ";

    	cout << densiteZ() << "~"; 
    }
    else if(i == 3){
        cout << sprite_[i];
    	if(densiteH() < 9)
    		cout << " ";

    	cout << densiteH() << "~"; 
    }
}



void Cellule::afficherInv(){

    inv_.liste_obj();
}


