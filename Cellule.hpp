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
#include <string>

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
    int wMonde_;
    std::string sprite_[5];

    Inventaire inv_;

	vectPtrHumain densiteH_;
    vectPtrZombie densiteZ_;

public:

    
    //! \brief Constructeur
    Cellule();

    //! \brief Constructeur
    Cellule(int);
    
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
    void set_pos(int p);
    void set_wMonde(int w);

    	// Getters
    int densiteH() const;
    int densiteZ() const;
    int get_bruit() const;
    int get_pos() const;
    int get_wMonde() const;
    std::shared_ptr<Humain> get_humain(int ind) const;
    std::shared_ptr<Zombie> get_zombie(int ind) const;

    vectPtrHumain get_liste_humain() const;
    vectPtrZombie get_liste_zombie() const;

    Inventaire get_inv();
    int get_taille_inv();

        // Méthodes d'affichage
    void afficher();
    void afficher(int);
    void afficherInv();

    void genererSprite(int);

};

#endif // CELLULE_H
