//! \file Stuff.hpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Header de Stuff.cpp

#ifndef STUFF_H
#define STUFF_H

 // Lib.
#include <iostream>
#include <string>

#include "Constante.hpp"

//------------------------------------------------------------------------------------------------------------- Général

//! \class Stuff
//! \brief Classe des objets pouvant être utilisé par les différentes choses
class Stuff{

protected:
    unsigned int id_;
    std::string nom_;
    int resistance_;

public:
    //! \brief Constructeur 
    Stuff(std::string nom, int res);

    //! \brief Destructeur
    ~Stuff();

    // Getteur 
    std::string get_nom();
    int get_res();
    int get_id();

    // Setteur
    void set_res(int res);
    void sub_res(int res);

    virtual void afficher();
};

//------------------------------------------------------------------------------------------------------------- Arme

//! \class Arme
//! \brief Classe des sous objet permettant d'augmenter les dégats d'une chose une fois équipé 
class Arme : public Stuff{

private:
    int degat_;

public:
    //! \brief Constructeur 
    Arme(std::string nom, int res, int deg);

    //! \brief Destructeur
    ~Arme();

    // Getteur
    int get_deg();

    virtual void afficher();
};

//------------------------------------------------------------------------------------------------------------- Véhicule

//! \class Arme
//! \brief Classe des sous objet permettant d'augmenter les déplacements d'une chose une fois équipé
class Vehicule : public Stuff{

private:
    int vitesse_;

public:
    //! \brief Constructeur 
    Vehicule(std::string nom, int res, int vit);

    //! \brief Destructeur
    ~Vehicule();

    // Getteur
    int get_vit();

    virtual void afficher();
};

//------------------------------------------------------------------------------------------------------------- Aliment

//! \class Arme
//! \brief Classe des sous objet permettant de soigner une chose une fois utilisé
class Aliment : public Stuff{

private:
    int soin_;

public:
    //! \brief Constructeur 
    Aliment(std::string nom, int res, int soin);

    //! \brief Destructeur
    ~Aliment();

    // Getteur
    int get_soin();

    virtual void afficher();
};

#endif // STUFF_H
