//! \file Chose.hpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Header de Chose.cpp

#ifndef CHOSE_H
#define CHOSE_H

#include <QApplication>
#include <iostream>
#include "EtatChose.hpp"
#include "Inventaire.hpp"
#include "Stuff.hpp"


const int maxPdvH = 100;

//! \class Chose
//! \brief Classe "abstraite" représentant les Choses peuplant le monde

class Chose{

protected:
    int pdv_;
    int attaque_;
    int vitesse_;
    int fatigue_;

    //! Attributs d'étât (PAttern Stats)
    Etat_Chose fuite_;
    Etat_Chose repos_;
    Etat_Chose explore_;
    Etat_Chose pourchasse_;
    Etat_Chose etat_;

public:

    //! \brief Constructeur
    Chose();

    //! \brief Destructeur
    virtual ~Chose();

    //! Méthodes Pattern State
    void changer_etat_fuite();
    void changer_etat_repos();
    void changer_etat_explore();
    void changer_etat_pourchasse();
    Etat_Chose get_etat();

    //! Méthode débug
    void seTapperLAffiche();

    //! Méthodes d'interaction

    //! \brief La chose perd de la vie
    //! \param i : le nombre de point de vie perdu
    virtual void recevoir_degat(int d);

    //! \brief La chose fait perdre de la vie à une autre chose
    //! \param cible : la chose attaqué
    virtual void attaquer(Chose &cible);

    //! \brief La chose se déplace
    virtual void mouvement();

    //! \brief La chose ramasse un objet et l'ajoute à son inventaire
    //! \param obj : l'objet ramassé
    virtual void prendre_objet(Stuff obj);

    //! \brief La chose rentre dans un bâtiment
    void rentrer_bat();

    //! \brief La chose mange un aliment afin de se soigner
    //! \param a : l'aliment ingéré 
    virtual void manger(Aliment a);

    //void afficher(int x, int y);

    //! Getteur
    int get_pdv() const;
    int get_attaque() const;
    int get_vitesse() const;
    int get_fatigue() const;

    //! Setteur
    void set_pdv(int pdv);
    void set_attaque(int attaque);
    void set_vitesse(int vitesse);
    void set_fatigue(int fatigue);


signals:

public slots:
};



#endif // CHOSE_H
