//! \file Chose.hpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Header de Chose.cpp

#ifndef CHOSE_H
#define CHOSE_H

 // Lib.
#include <iostream>
#include <memory>
 // Proj.
#include "EtatChose.hpp"
#include "Inventaire.hpp"
#include "Stuff.hpp"


// Constantes vie Humain et Zombie
const int maxPdvH = 100;
const int maxPdvZ = 100;

//! \class Chose
//! \brief Classe "abstraite" représentant les Choses peuplant le monde
class Chose{

protected:

    int pdv_;
    int attaque_;
    int vitesse_;
    int fatigue_;
    int direction_;
    int posCel_;

    int x_; int y_;

    //! Attributs d'étât (Pattern Stats)
    std::shared_ptr<Etat_Chose> fuite_;
    std::shared_ptr<Etat_Chose> repos_;
    std::shared_ptr<Etat_Chose> explore_;
    std::shared_ptr<Etat_Chose> pourchasse_;
    std::shared_ptr<Etat_Chose> etat_;

public:

    //! \brief Constructeur
    Chose(int pos);

    //! \brief Destructeur
    virtual ~Chose();

    //! Méthodes Pattern State
    void changer_etat_fuite();
    //! Méthodes Pattern State
    void changer_etat_repos();
    //! Méthodes Pattern State
    void changer_etat_explore();
    //! Méthodes Pattern State
    void changer_etat_pourchasse();

    //! \brief Méthode de changement d'étât 
    virtual void fuire();
    //! \brief Méthode de changement d'étât 
    virtual void en_securite();
    //! \brief Méthode de changement d'étât 
    virtual void explore();
    //! \brief Méthode de changement d'étât 
    virtual void pourchasser();

    //! Méthode débug
    void seTapperLAffiche();

    //! Méthodes d'interaction

    //! \brief La chose perd de la vie
    //! \param i : le nombre de point de vie perdu
    virtual void recevoir_degat(int d);

    //! \brief La chose fait perdre de la vie à une autre chose
    //! \param cible : la chose attaqué
    virtual void attaquer(Chose &cible) const;

    //! \brief La chose se déplace
    virtual void mouvement();

    //! \brief La chose ramasse un objet et l'ajoute à son inventaire
    //! \param obj : l'objet ramassé
    virtual void prendre_objet(Stuff obj);


    //! \brief La chose mange un aliment afin de se soigner
    //! \param a : l'aliment ingéré 
    virtual void manger(Aliment a);

    //void afficher(int x, int y);



    // Getteur
    int get_pdv() const;
    int get_attaque() const;
    int get_vitesse() const;
    int get_fatigue() const;
    std::shared_ptr<Etat_Chose> get_etat() const;
    int get_dir() const;
    int get_pos() const;

    // Setteur
    void set_pdv(int pdv);
    void set_attaque(int attaque);
    void set_vitesse(int vitesse);
    void set_fatigue(int fatigue);

    void set_direction(int d);
    void set_pos(int p);
};



#endif // CHOSE_H



