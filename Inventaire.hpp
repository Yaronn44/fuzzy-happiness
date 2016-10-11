/** 
 * @file Inventaire.hpp
 * @author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
 * @date 06/10/2016
 * @brief Header de Inventaire.tpp
 *  
**/
#pragma once
#include <iostream>
#include <vector>
#include "Stuff.hpp"


class Inventaire{

private:
	unsigned int taille_;
	std::vector<Stuff> inventaire_;

public:
		// Constructeur / Destructeur
	Inventaire(int t);
	~Inventaire();

		// Méthodes d'interaction
	void ajouter_objet(Stuff o);
	void retirer_objet(Stuff o);	
	bool obj_appartient(Stuff o);
	void liste_obj();
};


