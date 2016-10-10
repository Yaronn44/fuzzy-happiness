/** 
 * @file Inventaire.hpp
 * @author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
 * @date 06/10/2016
 * @brief Header de Inventaire.tpp
 *  
**/
#pragma once
#include <iostream>
#include <string>



//------------------------------------------------------------------------------------------------------------- Général

class Stuff{

protected:
	std::string nom_;
	int resistance_;

public:
		// Constructeur / Destructeur
	Stuff(std::string nom, int res);
	~Stuff();

		// Getteur / Setteur
	std::string get_nom();
	int get_res();
	void set_res(int res);
};

//------------------------------------------------------------------------------------------------------------- Arme

class Arme : public Stuff{

private:
	int degat_;

public:
		// Constructeur / Destructeur
	Arme(std::string nom, int res, int deg);
	~Arme();
	
		// Getteur / Setteur
	int get_deg();
};

//------------------------------------------------------------------------------------------------------------- Véhicule

class Vehicule : public Stuff{

private:
	int vitesse_;

public:
		// Constructeur / Destructeur
	Vehicule(std::string nom, int res, int vit);
	~Vehicule();

		// Getteur / Setteur
	int get_vit();
};

//------------------------------------------------------------------------------------------------------------- Aliment

class Aliment : public Stuff{

private:
	int soin_;

public:
		// Constructeur / Destructeur
	Aliment(std::string nom, int res, int soin);
	~Aliment();

		// Getteur / Setteur
	int get_soin();
};