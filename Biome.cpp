//! \file Biome.cpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Fichier d'implémentation des biomes permettant la création de la map

 // Header implémenté
#include "Biome.hpp"

 // Lib.
#include <iostream>
 // Proj.
#include "Constante.hpp"


using namespace std;



//-------------------------------------------------------------------------------------------------- Constructeur / Destructeur 

Biome::Biome(){

    int b = nbRand(2);

    biome_ = std::vector<Cellule>();
    std::unique_ptr<AbsF> factory = AbsF::CreateFactory(b);


    // Création

    structure_ = factory->structure();
    tableLoot_ = factory->listeLoot();


    // Cellules

    for(int i = 0; i < B_::HEIGHT*B_::WIDTH; ++i){

        int j = structure_.at(i);
        biome_.push_back(Cellule(j, i));

        int x = 2 + nbRand( tableLoot_->getLoot(0).coeff(j));
        biome_.at(i).add_arme(x);
        
        x = 2 + nbRand( tableLoot_->getLoot(1).coeff(j));
        biome_.at(i).add_vehicule(x);

        x = 2 + nbRand( tableLoot_->getLoot(2).coeff(j));
        biome_.at(i).add_nourriture(x);

        x = 2 + nbRand( tableLoot_->getLoot(3).coeff(j));
        biome_.at(i).add_metal(x);

    }
}

Biome::~Biome(){}


//-------------------------------------------------------------------------------------------------- Affichage

void Biome::afficherLigne(int l){
    for(int i = 0; i < B_::WIDTH; ++i){
        biome_.at(l*B_::WIDTH + i).afficher();
        cout << " ";
    }
    cout << "| ";
}

void Biome::afficherLigneStructure(int l){
    for(int i = 0; i <  B_::WIDTH; ++i){
        cout << structure_.at(l*B_::WIDTH + i) << " ";
    }

    cout << "| ";
}


void Biome::afficherLoot(){
    tableLoot_->afficher();
}

void Biome::afficherInv(int i){
    biome_.at(i).afficherInv();
}

int Biome::densite(int h, int w){
    return biome_.at(h*B_::WIDTH + w).densiteH();
}

vectPtrHumain Biome::getHumains(int indiceCel){
    return biome_.at(indiceCel).getListeHumain();
}

Cellule Biome::getCellule(int x){
    return biome_.at(x);
}

Cellule Biome::getCellule(int x, int y){
    return biome_.at(x+y*B_::WIDTH);
}

vector<Cellule> Biome::getListeCell(){
    return biome_;
}

vector<Cellule> Biome::ligne(int l){
    vector<Cellule> v = vector<Cellule>();

    for (int i = 0; i < B_::WIDTH; ++i)
    {
        v.push_back(biome_.at(l * B_::WIDTH + i));
    }

    return v;
}