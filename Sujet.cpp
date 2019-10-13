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


