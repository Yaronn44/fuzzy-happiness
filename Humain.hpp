//! \file Humain.hpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Header de Humain.cpp


#ifndef HUMAIN_H
#define HUMAIN_H

#include "Chose.hpp"
#include "Sujet.hpp"

//class Observer;

//! \class Humain
//! \brief Sous classe représentant des choses peuplant le monde
class Humain : public Chose, public SujetObs {

private:

	Inventaire inventaire_;
	Arme *arme_;
	bool vaRevenir_;
	int contamination_;


//	Observer *obs_;

public:
	
	//! \brief Constructeur
	Humain(int p);

	//! \brief Destructeur
	~Humain();

	// Méthodes d'interaction

	//! \brief La chose perd de la vie
	//! \param i : le nombre de point de vie perdu
	void recevoir_degat(int d);

    //! \brief La chose fait perdre de la vie à une autre chose
    //! \param cible : la chose attaqué
	void attaquer(Chose &cible) const;

    //! \brief La chose se déplace
	void mouvement();

	//! \brief La chose ramasse un objet et l'ajoute à son inventaire
    //! \param obj : l'objet ramassé
	void prendre_objet(Stuff obj);

	//! \brief La chose mange un aliment afin de se soigner
	//! \param a : l'aliment ingéré 
	void manger(Aliment a);

	//! \brief Méthode de changement d'étât 
	virtual void fuire();
	//! \brief Méthode de changement d'étât 
	virtual void en_securite();
	//! \brief Méthode de changement d'étât 
	virtual void explore();
	//! \brief Méthode de changement d'étât 
	virtual void pourchasser();

	// Getteur / Setteur
	Arme get_arme() const;
	void set_arme(Arme& a);
	bool be_zombie();
	int get_contamination();
	
	void set_pdv(int pdv);
	std::string get_nom_arme();
};




#endif // HUMAIN_H

