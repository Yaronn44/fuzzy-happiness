//! \file VilleF.cpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Fichier d'implémentation de la factory pour les villes 


 // Header implémenté
#include "AbsF.hpp"

 // Proj.
#include "Stuff.hpp"

//-------------------------------------------------------------------------------------------------- Plaine

VillePlaineF::VillePlaineF(){}

VillePlaineF::~VillePlaineF(){}


std::unique_ptr<TableLoot> VillePlaineF::listeLoot(){

    std::unique_ptr<TableLoot> table = std::make_unique<TableLoot>();

    table->set_arme( Loot(0, 4, 0, 9, 6));
    table->set_vehicule( Loot(1, 2, 1, 5, 6));
    table->set_nourriture( Loot(3, 9, 1, 7, 8));
    table->set_metal( Loot(0, 2, 5, 4, 3));

    return table;
}


std::vector<int> VillePlaineF::structure(){

    std::vector<int> str;

    int tab[] = {
        2, 2, 2, 2, 3, 3, 2, 2,
        2, 3, 2, 3, 3, 4, 3, 3,
        3, 3, 3, 4, 4, 4, 4, 3,
        2, 2, 3, 3, 3, 3, 4, 3,
        2, 2, 2, 2, 2, 2, 3, 2
    };

    str.insert(str.end(), tab, tab + B_::WIDTH*B_::HEIGHT);

    return str;
}


//-------------------------------------------------------------------------------------------------- Montagne

VilleMontF::VilleMontF(){}

VilleMontF::~VilleMontF(){}


//TableLoot 
std::unique_ptr<TableLoot> VilleMontF::listeLoot(){

   //TableLoot 
    std::unique_ptr<TableLoot> table = std::make_unique<TableLoot>();

    table->set_arme( Loot(1, 2, 3, 4, 5));
    table->set_vehicule( Loot(0, 3, 0, 4, 3));
    table->set_nourriture( Loot(9, 4, 3, 5, 9));
    table->set_metal( Loot(5, 9, 2, 9, 9));

    return table;
}


std::vector<int> VilleMontF::structure(){

    std::vector<int> str;

    int tab[] = {
        3, 3, 2, 2, 3, 3, 3, 2,
        2, 3, 3, 3, 3, 4, 3, 2,
        3, 4, 3, 2, 2, 4, 4, 3,
        2, 3, 4, 2, 4, 3, 4, 3,
        2, 2, 3, 3, 3, 2, 3, 2
    };

    str.insert(str.end(), tab, tab + B_::WIDTH*B_::HEIGHT);

    return str;
}
