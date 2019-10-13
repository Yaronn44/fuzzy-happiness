//! \file Loot.cpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Fichier d'implémentation des loots des Cellules de la map
 

 // Header implémenté
#include "Loot.hpp"

 // Lib.
#include <iostream>


// Virtual ------> passer par des pointeurs
// Non ici on fera une table de loot et on les fera en copie ensuite


//-------------------------------------------------------------------------------------------------- Loot

Loot::Loot(int i0, int i1, int i2, int i3, int i4){
    coeff_[0] = i0;
    coeff_[1] = i1;
    coeff_[2] = i2;
    coeff_[3] = i3;
    coeff_[4] = i4;
}

Loot::Loot(){
    for (int i = 0; i < 5; ++i)
    {
        coeff_[i] = 0;
    }
}

Loot::~Loot(){}

int Loot::coeff(int indice){
    return coeff_[indice];
}


void Loot::afficher(){
    std::cout << "Les indices : " << coeff_[0];
    for (int i = 1; i < 5; ++i){
        std::cout << ", " << coeff_[i];
    }
}


//-------------------------------------------------------------------------------------------------- Table de Loot

TableLoot::TableLoot(Loot a, Loot v, Loot n, Loot o){
    table_[0] = a;
    table_[1] = v;
    table_[2] = n;
    table_[3] = o;
}

TableLoot::TableLoot(){
    for (int i = 0; i < 4; ++i)
    {
        table_[i] = Loot();
    }
}

TableLoot::~TableLoot(){}

Loot TableLoot::getLoot(int ind){
    return table_[ind];
}

void TableLoot::set_arme(Loot l){table_[0] = l;}
void TableLoot::set_vehicule(Loot l){table_[1] = l;}
void TableLoot::set_nourriture(Loot l){table_[2] = l;}
void TableLoot::set_metal(Loot l){table_[3] = l;}

/*
void TableLoot::set_loot(Loot l, int i){
    table_[i] = l;
}
*/


void TableLoot::afficher(){
    std::cout << "Arme (";
    table_[0].afficher();
    std::cout << ")" << std::endl;

    std::cout << "Vehicule (";
    table_[1].afficher();
    std::cout << ")" << std::endl;

    std::cout << "Nourriture (";
    table_[2].afficher();
    std::cout << ")" << std::endl;

    std::cout << "Autre (";
    table_[3].afficher();
    std::cout << ")" << std::endl;

}