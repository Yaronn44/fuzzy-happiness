//! \file CampagneF.cpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Fichier d'implémentation de la factory pour les campagnes

 // Header implémenté
#include "AbsF.hpp"

// Proj.
#include "Stuff.hpp"

//-------------------------------------------------------------------------------------------------- Plaine

CampagnePlaineF::CampagnePlaineF(){}

CampagnePlaineF::~CampagnePlaineF(){}


std::unique_ptr<TableLoot> CampagnePlaineF::listeLoot(){

    std::unique_ptr<TableLoot> table = std::make_unique<TableLoot>();

    table->set_arme( Loot(0, 4, 0, 9, 6));
    table->set_vehicule( Loot(1, 2, 1, 5, 6));
    table->set_nourriture( Loot(3, 9, 1, 7, 8));
    table->set_metal( Loot(0, 2, 5, 4, 3));
    
    return table;
}

std::vector<int> CampagnePlaineF::structure(){

    std::vector<int> str;

    int tab[] = {
        1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 1, 1, 0,
        0, 0, 0, 0, 0, 0, 1, 0,
        0, 1, 0, 0, 0, 0, 0, 0,
    };

    str.insert(str.end(), tab, tab + B_::WIDTH*B_::HEIGHT);

    return str;
}



//-------------------------------------------------------------------------------------------------- Montagne

CampagneMontF::CampagneMontF(){}

CampagneMontF::~CampagneMontF(){}


std::unique_ptr<TableLoot> CampagneMontF::listeLoot(){

    std::unique_ptr<TableLoot> table = std::make_unique<TableLoot>();

    table->set_arme( Loot(0, 6, 0, 9, 8));
    table->set_vehicule( Loot(0, 3, 0, 4, 3));
    table->set_nourriture( Loot(9, 4, 3, 5, 9));
    table->set_metal( Loot(5, 9, 2, 9, 9));

    return table;
}

std::vector<int> CampagneMontF::structure(){

    std::vector<int> str;

    int tab[] = {
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 1, 0,
    };

    str.insert(str.end(), tab, tab + B_::WIDTH*B_::HEIGHT);

    return str;
}


//-------------------------------------------------------------------------------------------------- Autre

CampagneAutreF::CampagneAutreF(){}

CampagneAutreF::~CampagneAutreF(){}


std::unique_ptr<TableLoot> CampagneAutreF::listeLoot(){

    std::unique_ptr<TableLoot> table = std::make_unique<TableLoot>();

    table->set_arme( Loot(0, 1, 0, 0, 0));
    table->set_vehicule( Loot(1, 1, 0, 0, 0));
    table->set_nourriture( Loot(4, 9, 0, 0, 0));
    table->set_metal( Loot(9, 3, 0, 0, 0));

    return table;
}

std::vector<int> CampagneAutreF::structure(){

    std::vector<int> str;

    int tab[] = {
        0, 1, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 1, 0, 0, 0,
        0, 0, 1, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 1, 0, 0, 0,
        0, 0, 0, 0, 1, 0, 1, 0,
    };

    str.insert(str.end(), tab, tab + B_::WIDTH*B_::HEIGHT);

    return str;
}



//*/

