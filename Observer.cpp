//! \file Observer.cpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Fichier d'implémentation du pattern Observer

 // Header implémenté
#include "Observer.hpp"


 // Lib.
#include <iostream>
 // Proj.
//#include "Humain.hpp"
#include "Cellule.hpp"



using namespace std;


//-------------------------------------------------------------------------------------------------- Général

Observer::Observer(){}

Observer::~Observer(){}

//void Observer::actualiser(){}

//-------------------------------------------------------------------------------------------------- Humain


ObserverHumain::ObserverHumain(Humain *s) : sujet_(s){
	sujet_->enregistrer_obs(this);
}

ObserverHumain::ObserverHumain(){
	sujet_ = nullptr;
}



ObserverHumain::~ObserverHumain(){}

void ObserverHumain::actualiser(){
	afficher();
} 

void ObserverHumain::afficher(){

	if(sujet_ != nullptr){
		cout << "Humain : " << endl;
		cout << "PDV : " << sujet_->get_pdv() << "\t Attaque : " << sujet_->get_attaque() << "\t Vitesse : " << sujet_->get_vitesse() << "\t Fatigue : " << sujet_->get_fatigue() << endl;
		cout << "Arme : " << sujet_->get_nom_arme() << endl;
	
	}else{
		cout << "NO HUMAN OBSERVED YOU FAGGOT" << endl;
	}
}

void ObserverHumain::reinit(){
	sujet_->supprimer_obs();
	sujet_ = nullptr;
}



//-------------------------------------------------------------------------------------------------- Cellule


ObserverCellule::ObserverCellule(Cellule *s) : sujet_(s){
	sujet_->enregistrer_obs(this);
}

ObserverCellule::ObserverCellule(){
	sujet_ = nullptr;
}



ObserverCellule::~ObserverCellule(){}

void ObserverCellule::actualiser(){
	afficher();
} 

void ObserverCellule::afficher(){

	if(sujet_ != nullptr){
		cout << "Cellule : ";
		sujet_-> afficher();
		cout << " (densité : " << sujet_->densiteZ() << ")" << endl;
	
	}else{
		cout << "NO LAND OBSERVED YOU DUMBASS" << endl;
	}
}

void ObserverCellule::reinit(){
	sujet_->supprimer_obs();
	sujet_ = nullptr;
}