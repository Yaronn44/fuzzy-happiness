//! \file Cellule.hpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Header de Cellule.cpp


#ifndef CELLULE_H
#define CELLULE_H

 // Lib.
#include <iostream>
#include <memory>
#include <vector>

 // Proj.
#include "Humain.hpp"
#include "Zombie.hpp"


typedef std::vector<std::shared_ptr<Humain>> vectPtrHumain;
typedef std::vector<std::shared_ptr<Zombie>> vectPtrZombie;

class Cellule : public SujetObs{

private:

	int bruit_;
    char n_;
    int pos_;

    Inventaire inv_;

	vectPtrHumain densiteH_;
    vectPtrZombie densiteZ_;

public:

    
    //! \brief Constructeur
    Cellule();

    //! \brief Constructeur
    Cellule(int, int);
    
    //! \brief Destructeur
    ~Cellule();

    	// Setters
    void actualiser_bruit();
    void actualiser_dir_zomb(int d);
    void set_bruit(int);
    void add_arme(int x);
    void add_vehicule(int x);
    void add_nourriture(int x);
    void add_metal(int x);

    	// Getters
    int densiteH();
    int densiteZ();

    int get_bruit();

    vectPtrHumain getListeHumain();
    vectPtrZombie getListeZombie();

        // Méthodes d'affichage
    void afficher();
    void afficherInv();

};

#endif // CELLULE_H
