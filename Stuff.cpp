//! \file Stuff.cpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Fichier d'implémentation des objets présent dans le monde

 // Header implémenté
#include "Stuff.hpp"

 // Lib.
#include <iostream>


using namespace std;

unsigned int id = 0;

//-------------------------------------------------------------------------------------------------- Général

Stuff::Stuff(string nom, int res) : nom_(nom), resistance_(res){
	id_ = id++;
}

Stuff::~Stuff(){}

string Stuff::get_nom(){return nom_;}

int Stuff::get_res(){return resistance_;}

void Stuff::set_res(int res){resistance_ = res;}

void Stuff::sub_res(int res){
	resistance_ -= res;
	if(resistance_ < 0)
		resistance_ = 0;
}

void Stuff::afficher(){
	cout << nom_ << " (resistance : " <<  resistance_ << ") ";
}

int Stuff::get_id(){
	return id_;
}

//-------------------------------------------------------------------------------------------------- Arme

Arme::Arme(string nom, int res, int deg) : Stuff(nom, res), degat_(deg){}

Arme::~Arme(){}

int Arme::get_deg(){return degat_;}

void Arme::afficher(){
	cout << "Arme : ";
	Stuff::afficher();
	cout << "degat : " << degat_;
}

//-------------------------------------------------------------------------------------------------- Véhicule

Vehicule::Vehicule(string nom, int res, int vit) : Stuff(nom, res), vitesse_(vit){}

Vehicule::~Vehicule(){}

int Vehicule::get_vit(){return vitesse_;}

void Vehicule::afficher(){
	cout << "Vehicule : ";
	Stuff::afficher();
	cout << "vitesse : " << vitesse_;
}


//-------------------------------------------------------------------------------------------------- Aliment

Aliment::Aliment(string nom, int res, int soin) : Stuff(nom, res), soin_(soin){}

Aliment::~Aliment(){}

int Aliment::get_soin(){return soin_;}

void Aliment::afficher(){
	cout << "Aliment : ";
	Stuff::afficher();
	cout << "soin : " << soin_;
}