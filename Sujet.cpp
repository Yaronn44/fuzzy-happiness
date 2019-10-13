//! \file Sujet.cpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Fichier d'implémentation des sujet pour le pattern Observer

 // Lib.
#include <iostream>
 // Proj.
#include "Sujet.hpp"
#include "Observer.hpp"

using namespace std;

//-------------------------------------------------------------------------------------------------- Général
SujetObs::SujetObs(){}
SujetObs::~SujetObs(){}

void SujetObs::enregistrer_obs(Observer *o){
	obs_ = o;
}

void SujetObs::supprimer_obs(){
	obs_ = nullptr; 


	/* ATTENTION IL FAUDRAIT
	*  PEUT-ETRE FAIRE EN SORTE
	*  QUE L'OBSERVER SOIT AUSSI
	*  MIS SUR NULL
	*/
}

void SujetObs::notifier_obs(){
	if(obs_ != nullptr)
		obs_->actualiser();
}


//-------------------------------------------------------------------------------------------------- Humain

/*
ObserverHumain obs_;
Humain donnee_;

SujetHumain::SujetHumain() : obs_(NULL){}
SujetHumain::~SujetHumain();

void SujetHumain::enregister_obs(ObserverHumain o){
	obs_ = o;
}

void SujetHumain::supprimer_obs(){
	obs_ = NULL;
}

void SujetHumain::notifier_obs(){
	obs_.actualiser(donne_);
}

Humain SujetHumain::get_donnee(){
	return donnee_;
}

void SujetHumain::set_donnee(Humain d){ 
	donnee_ = d;
	notifierObs();
}


//-------------------------------------------------------------------------------------------------- Cellule
ObserverCellule obs_;
Cellule donnee_;

SujetCellule::SujetCellule():  : obs_(NULL);
SujetCellule::~SujetCellule();

void SujetCellule::enregister_obs(ObserverCellule o){
	obs_ = o;
}

void SujetCellule::supprimer_obs(){
	obs_ = NULL;
}

void SujetCellule::notifier_obs(){
	obs_.actualiser(donne_);
}

Cellule SujetCellule::get_donnee(){
	return donnee_;
}

void SujetCellule::set_donnee(Cellule d){ 
	donnee_ = d;
	notifierObs();
}


//*/

