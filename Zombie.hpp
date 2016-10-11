/** 
 * @file Zombie.hpp
 * @author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
 * @date 06/10/2016
 * @brief Header de Zombie.tpp
 *  
**/
#pragma once
#include <iostream>
#include "Chose.hpp"


class Zombie : public Chose{

private:

	Inventaire inventaire_;

public:

		// Constructeur / Destructeur
	Zombie();
	~Zombie();

		// Méthodes d'interaction
	void recevoir_degat(int d);
	void attaquer(Chose &cible) const;
	void mouvement();
	void prendre_objet(Stuff obj);
	void rentrer_bat();
	void manger(Aliment a);

		// Getteur / Setteur
	void set_pdv(int pdv);
};