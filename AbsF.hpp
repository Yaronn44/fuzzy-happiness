//! \file AbsF.hpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Header de AbsF.cpp


#ifndef ABSF_H
#define ABSF_H

 // Lib.
#include <memory>
#include <vector>
 // Proj.
#include "Inventaire.hpp"
#include "Constante.hpp"
#include "UniquePointer.hpp"
#include "Loot.hpp"


class AbsF{

private:
    static std::unique_ptr<AbsF> CreateVille(V_FACT factory);
    static std::unique_ptr<AbsF> CreateCampagne(C_FACT factory);

public:

    //! \brief Constructeur
    AbsF();
    //! \brief Destructeur
    ~AbsF();

    //! \brief Créer la liste des loots
    virtual std::unique_ptr<TableLoot> listeLoot() = 0;

    //! \brief Retourne un tableau d'entier qui sera le squelette du biome
    //! \return un tableau d'entier
    virtual std::vector<int> structure() = 0;

    static std::unique_ptr<AbsF> CreateFactory(int type);
};


//--------------------------------------------------------------------------------------------------------------------------------------------// 
//--------------------------------------------------------------------------------------------------------------------------------------------// 
//-----------------------------------------------------------               ------------------------------------------------------------------//
//-----------------------------------------------------------   CAMPAGNE    ------------------------------------------------------------------//
//-----------------------------------------------------------               ------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------------------------------------// 


//-------------------------------------------------------------------------------------------------- Plaine


class CampagnePlaineF : public AbsF{

public:

    //! \brief Constructeur
    CampagnePlaineF();
    //! \brief Destructeur
    ~CampagnePlaineF();

    //! \brief Créer la liste des loots
    virtual std::unique_ptr<TableLoot> listeLoot();

    //! \brief Retourne un tableau d'entier qui sera le squelette du biome
    //! \return un tableau d'entier
    virtual std::vector<int> structure();

};

//-------------------------------------------------------------------------------------------------- Mont


class CampagneMontF : public AbsF{

public:

    //! \brief Constructeur
    CampagneMontF();
    //! \brief Destructeur
    ~CampagneMontF();

    //! \brief Créer la liste des loots
    virtual std::unique_ptr<TableLoot> listeLoot();

    //! \brief Retourne un tableau d'entier qui sera le squelette du biome
    //! \return un tableau d'entier
    virtual std::vector<int> structure();

};

//-------------------------------------------------------------------------------------------------- Autre


class CampagneAutreF : public AbsF{

public:

    //! \brief Constructeur
    CampagneAutreF();
    //! \brief Destructeur
    ~CampagneAutreF();

    //! \brief Créer la liste des loots
    virtual std::unique_ptr<TableLoot> listeLoot();

    //! \brief Retourne un tableau d'entier qui sera le squelette du biome
    //! \return un tableau d'entier
    virtual std::vector<int> structure();

};



//--------------------------------------------------------------------------------------------------------------------------------------------// 
//--------------------------------------------------------------------------------------------------------------------------------------------// 
//-----------------------------------------------------------               ------------------------------------------------------------------//
//-----------------------------------------------------------     VILLE     ------------------------------------------------------------------//
//-----------------------------------------------------------               ------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------------------------------------// 



//-------------------------------------------------------------------------------------------------- Plaine


class VillePlaineF : public AbsF{

public:

    //! \brief Constructeur
    VillePlaineF();
    //! \brief Destructeur
    ~VillePlaineF();

    //! \brief Créer la liste des loots
    virtual std::unique_ptr<TableLoot> listeLoot();

    //! \brief Retourne un tableau d'entier qui sera le squelette du biome
    //! \return un tableau d'entier
    virtual std::vector<int> structure();

};

//-------------------------------------------------------------------------------------------------- Mont


class VilleMontF : public AbsF{

public:

    //! \brief Constructeur
    VilleMontF();
    //! \brief Destructeur
    ~VilleMontF();

    //! \brief Créer la liste des loots
    virtual std::unique_ptr<TableLoot> listeLoot();

    //! \brief Retourne un tableau d'entier qui sera le squelette du biome
    //! \return un tableau d'entier
    virtual std::vector<int> structure();

};



#endif // ABSF_H



