/** 
 * @file Chose.hpp
 * @author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
 * @date 06/10/2016
 * @brief Header de Chose.tpp
 *  
**/

#pragma once
#include <iostream>
#include "EtatChose.hpp"
#include "Inventaire.hpp"
#include "Stuff.hpp"


class Chose{

protected:
	int pdv_;
	int attaque_;
	int vitesse_;
	int fatigue_;

		// Attributs Pattern State
	Etat_Chose fuite_;
	Etat_Chose repos_;
	Etat_Chose explore_;
	Etat_Chose pourchasse_;
	Etat_Chose etat_;

public:
		// Constructeur / Destructeur
	Chose();
	virtual ~Chose();
	
		// Méthodes Pattern State
	void changer_etat_fuite();
	void changer_etat_repos();
	void changer_etat_explore();
	void changer_etat_pourchasse();

		// Méthode débug
	void seTapperLAffiche();
	
		// Méthodes d'interaction
	void recevoir_degat(int d);
	virtual void attaquer(Chose &cible);
	virtual void mouvement();
	virtual void prendre_objet(Stuff obj);
	void rentrer_bat();
	virtual void manger(Aliment a);
	//void afficher(int x, int y);

		// Getteur & Setteur
	int get_pdv() const;
	int get_attaque() const;
	int get_vitesse() const;
	int get_fatigue() const;

	void set_pdv(int pdv);
	void set_attaque(int attaque);
	void set_vitesse(int vitesse);
	void set_fatigue(int fatigue);
};


