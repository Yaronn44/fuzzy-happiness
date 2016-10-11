/** 
 * @file Humain.hpp
 * @author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
 * @date 06/10/2016
 * @brief Header de Humain.tpp
 *  
**/
#pragma once
#include <iostream>
#include "Chose.hpp"

const int maxPdvH = 100;

class Humain : public Chose{

private:

	Inventaire inventaire_;
	Arme *arme_;

public:
		// Constructeur / Destructeur
	Humain();
	~Humain();

		// Méthodes d'interaction
	void recevoir_degat(int d);
	void attaquer(Chose &cible) const;
	void mouvement();
	void prendre_objet(Stuff obj);
	void rentrer_bat();
	void manger(Aliment a);

		// Getteur / Setteur
	Arme get_arme() const;
	void set_arme(Arme& a);
	
	void set_pdv(int pdv);
};


