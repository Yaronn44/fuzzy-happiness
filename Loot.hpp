//! \file Loot.hpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Header de Loot.cpp

#ifndef LOOT_H
#define LOOT_H

 // Lib.
#include <vector>
#include <string>
 // Proj.
#include "Stuff.hpp"


//! \class Loot
//! \brief Classe décrivant, pour un objet spécifique, les chances de présence dans une cellule donnée (indicée de 0 à 5)
class Loot{

private:
    unsigned int coeff_[5];

public:
    //! Constructeur
    Loot(int, int, int, int, int);
    Loot();

    //! Destructeur
    ~Loot();

    //! \brief Retire un objet de l'inventaire
    //! \param indice de la case où l'on veut ajouter obj
    //! \return le coefficient pour l'indice donné
    int coeff(int indice);

    void afficher();

};



//! \class TableLoot
//! \brief Classe tableau de Loot (sert pour un biome particulier)
class TableLoot{

private:
    Loot table_[4];
    /*
        0 arme_;
        1 vehicule_;
        2 nourriture_;
        3 autre_;
    */

public:
    //! Constructeur
    TableLoot(Loot a, Loot v, Loot n, Loot o);
    TableLoot();

    //! Destructeur
    ~TableLoot();

    //! \brief Accesseur du Loot
    //! \return l'objet looté
    Loot getLoot(int ind);

    //! \brief Setteur du Loot
    //! \param le loot a ajouté
    void set_arme(Loot l);
    void set_vehicule(Loot l);
    void set_nourriture(Loot l);
    void set_metal(Loot l);

    //void set_loot(Loot l, int i);


    void afficher();
};

#endif // LOOT_H

