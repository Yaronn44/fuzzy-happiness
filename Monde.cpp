//! \file Monde.cpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Fichier d'implémentation du monde dans lequel les Choses vont évoluer

 // Header implémenté
#include "Monde.hpp"
 
 // Lib.
#include "UniquePointer.hpp"


using namespace std;


//-------------------------------------------------------------------------------------------------- Constructeur / Destructeur

Monde::Monde() :w_(3), h_(2), age_(1), pas_(1){

    for(int i = 0; i < w_*h_; ++i){
        world_.push_back(make_unique<Biome>());
    }
}

Monde::Monde(int w, int h) : w_(w), h_(h), age_(1), pas_(1){

    for(int i = 0; i < w_*h_; ++i){
        world_.push_back(make_unique<Biome>());
    }
}

Monde::~Monde(){}


//-------------------------------------------------------------------------------------------------- Affichage

int Monde::getAge(){
    return age_;
}


//-------------------------------------------------------------------------------------------------- Affichage

void Monde::afficher(){
    for(int i = 0; i < h_; ++i){
        for(int k = 0; k < B_::HEIGHT; ++k){
            for(int j = 0; j < w_; ++j){
                world_.at(j+ i*w_)->afficherLigne(k);
            }
            cout << endl << endl;
        }
        for(int j = 0; j < B_::WIDTH*w_+w_; ++j){
            cout << "--";
        }
        cout << endl << endl;
    }
}

void Monde::afficherStructure(){
    for(int i = 0; i < h_; ++i){
        for(int k = 0; k < B_::HEIGHT; ++k){
            for(int j = 0; j < w_; ++j){
                world_.at(j+ i*w_)->afficherLigneStructure(k);
            }
            cout << endl << endl;
        }
        for(int j = 0; j < B_::WIDTH*w_+w_; ++j){
            cout << "--";
        }
        cout << endl << endl;
    }
}


void Monde::afficherLoot(int i){
    world_.at(i)->afficherLoot();
}

void Monde::afficherInv(){
    world_.at(0)->afficherInv(1);
}


int Monde::densite(int h, int w){
    return world_.at(1)->densiteZ(h,w);
}



void Monde::vieillir(){
    for (int i = 0; i < pas_; ++i)
    {
        ++age_;
    }
}