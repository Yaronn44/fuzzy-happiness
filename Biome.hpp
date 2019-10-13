//! \file Biome.hpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Header de Biome.cpp

#ifndef BIOME_H
#define BIOME_H

 // Lib.
#include <vector>
#include <memory>
 // Proj.
#include "Cellule.hpp"
#include "Constante.hpp"
#include "Inventaire.hpp"
#include "AbsF.hpp"
#include "Loot.hpp"



class Biome{

protected:

    std::vector<Cellule> biome_;
    std::vector<int> structure_;
    std::unique_ptr<TableLoot> tableLoot_;

public:

    //! \brief Constructeur
    Biome();
    //! \brief Destructeur
    ~Biome();

        // Méthodes d'affichage
    void afficherLigne(int);
    void afficherLigneStructure(int);
    void afficherLoot();
    void afficherInv(int);

    vectPtrHumain getHumains(int indiceCel);

    std::vector<Cellule> getListeCell();
    std::vector<Cellule> ligne(int);
    Cellule getCellule(int x);
    Cellule getCellule(int x, int y);
    int densite(int h, int w);
};

#endif // BIOME_H
