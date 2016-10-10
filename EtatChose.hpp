/** 
 * @file Etat_chose.hpp
 * @author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
 * @date 06/10/2016
 * @brief Header de EtatChose.cpp, contient également les différents états
 *  
**/
#pragma once

#include <iostream>

class Chose;


//------------------------------------------------------------------------------ Général

class Etat_Chose{
private:

public:

		// Constructeur & Destructeur
	Etat_Chose();
	virtual ~Etat_Chose();

	virtual void fuire();
	virtual void en_securite();
	virtual void explore();
	virtual void pourchasser();
	virtual void seTapperLAffiche();
};


//------------------------------------------------------------------------------ Fuite

class Etat_Fuite : public Etat_Chose{

private:
	Chose *chose_;

public:

		// Constructeur & Destructeur
	Etat_Fuite(Chose *c);
	~Etat_Fuite();
	
	void fuire();
	void en_securite();
	void explore();
	void pourchasser();
	void seTapperLAffiche();

};


//------------------------------------------------------------------------------ Repos

class Etat_Repos : public Etat_Chose{

private:
	Chose *chose_;

public:

		// Constructeur & Destructeur
	Etat_Repos(Chose *c);
	~Etat_Repos();

	void fuire();
	void en_securite();
	void explore();
	void pourchasser();
	void seTapperLAffiche();

};


//------------------------------------------------------------------------------ Explore

class Etat_Explore : public Etat_Chose{

private:
	Chose *chose_;

public:

		// Constructeur & Destructeur
	Etat_Explore(Chose *c);
	~Etat_Explore();

	void fuire();
	void en_securite();
	void explore();
	void pourchasser();
	void seTapperLAffiche();

};


//------------------------------------------------------------------------------ Pourchase

class Etat_Pourchasse : public Etat_Chose{

private:
	Chose *chose_;

public:

		// Constructeur & Destructeur
	Etat_Pourchasse(Chose *c);
	~Etat_Pourchasse();

	void fuire();
	void en_securite();
	void explore();
	void pourchasser();
	void seTapperLAffiche();
};