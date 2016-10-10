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

	TypeZ type_;

public:

		// Constructeur / Destructeur
	Zombie();
	~Zombie();

		// Méthodes d'interaction
	void attaquer(Chose &cible);
	void mouvement();
	void rentrer_bat();
};