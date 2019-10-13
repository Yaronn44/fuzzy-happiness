//! \file Zombie.hpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Header de Zombie.cpp

#ifndef ZOMBIE_H
#define ZOMBIE_H

 // Lib.
#include <iostream>
 // Proj.
#include "Chose.hpp"


class Zombie : public Chose{

private:

	//Inventaire inventaire_;

public:

	 //! Constructeur 
	Zombie(int p);
	  //! Destructeur
	~Zombie();

	// Méthodes d'interaction

   //! \brief La chose perd de la vie
   //! \param i : le nombre de point de vie perdu
	void recevoir_degat(int d);

	//! \brief La chose fait perdre de la vie à une autre chose
	//! \param cible : la chose attaqué
	void attaquer(Chose &cible) const;

	//void prendre_objet(Stuff obj);

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
	void set_pdv(int pdv);
};

#endif // ZOMBIE_H



