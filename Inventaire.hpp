//! \file Inventaire.hpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Header de Inventaire.cpp

#ifndef INVENTAIRE_H
#define INVENTAIRE_H

 // Lib.
#include <iostream>
#include <vector>
#include <memory>
 // Proj.
#include "Stuff.hpp"
//#include "UniquePointer.hpp"


typedef std::vector<std::shared_ptr<Stuff>> vectPtrStuff;


//! \class Inventaire
//! \brief Classe des inventaires des chose leur permettant de porter des objets
class Inventaire{

private:
    unsigned int taille_;
    vectPtrStuff inventaire_;
    //vectPtrStuff inventaire_;

public:
    //! Constructeur
    Inventaire(int t);

    //! Destructeur
    ~Inventaire();

    //! \brief Ajoute un objet à l'inventaire
    //! \param o : l'objet ajouté 
    void ajouter_objet(std::shared_ptr<Stuff> o);

    //! \brief Retire un objet de l'inventaire
    //! \param o : l'objet retiré 
    void retirer_objet(std::shared_ptr<Stuff> o);

    //! \brief Permet de vérifier si un objet appartient bien à l'inventaire
    //! \param o : l'objet testé
    //! \return un \e bool 
    bool obj_appartient(std::shared_ptr<Stuff> o);

    //! \brief Ecrit dans le terminal la liste des objets présent dans l'inventaire
    void liste_obj();
};

#endif // INVENTAIRE_H
