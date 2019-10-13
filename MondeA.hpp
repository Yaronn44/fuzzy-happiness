//! \file Monde.hpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Header de Monde.cpp

#ifndef MONDE_H
#define MONDE_H

 // Lib.
#include <iostream>
#include <vector>
#include <memory>
 // Proj.
#include "Biome.hpp"

typedef std::vector<std::unique_ptr<Biome>> vectPtrBiome;

class Monde{

private:

    //vectPtrBiome world_;
    std::vector<Cellule> monde_;
    
    int w_, h_;
    int age_;

public:

        // Constructeur / Destructeur
    Monde();
    Monde(int, int);
    ~Monde();

        // Getters / Setters
    int getAge();


        // Méthodes d'affichage
    void afficher();

    int densite(int );

    void afficherInv(int );

    void direction_zombie();


    void vieillir();

};

#endif // MONDE_H
