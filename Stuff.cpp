/** 
 * @file Stuff.cpp
 * @author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
 * @date 06/10/2016
 * @brief Header de Inventaire.tpp
 *  
**/

#include <iostream>
#include "Stuff.hpp"

using namespace std;


//------------------------------------------------------------------------------------------------------------- Général

Stuff::Stuff(string nom, int res) : nom_(nom), resistance_(res){}

Stuff::~Stuff(){}

string Stuff::get_nom(){return nom_;}

int Stuff::get_res(){return resistance_;}

void Stuff::set_res(int res){resistance_ = res;}

//------------------------------------------------------------------------------------------------------------- Arme

Arme::Arme(string nom, int res, int deg) : Stuff(nom, res), degat_(deg){}

Arme::~Arme(){}

int Arme::get_deg(){return degat_;}

//------------------------------------------------------------------------------------------------------------- Véhicule

Vehicule::Vehicule(string nom, int res, int vit) : Stuff(nom, res), vitesse_(vit){}

Vehicule::~Vehicule(){}

int Vehicule::get_vit(){return vitesse_;}

//------------------------------------------------------------------------------------------------------------- Aliment


Aliment::Aliment(string nom, int res, int soin) : Stuff(nom, res), soin_(soin){}

Aliment::~Aliment(){}

int Aliment::get_soin(){return soin_;}