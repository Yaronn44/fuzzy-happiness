//! \file Etat_Chose.hpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Header de EtatChose.cpp
 
#ifndef ETATCHOSE_H
#define ETATCHOSE_H

 // Lib.
#include <iostream>

class Chose;


//------------------------------------------------------------------------------ Général
//! \class Etat_Chose
//! \brief Classe "abstraite" permettant l'implémentation du pattern States

class Etat_Chose{
private:

public:

	//! \brief Constructeur
	Etat_Chose();

	//! \brief Destructeur
	virtual ~Etat_Chose();

	//! \brief Méthode de changement d'étât 
	virtual void fuire();
	//! \brief Méthode de changement d'étât 
	virtual void en_securite();
	//! \brief Méthode de changement d'étât 
	virtual void explore();
	//! \brief Méthode de changement d'étât 
	virtual void pourchasser();
	//! \brief Méthode de déplacement des entitées
	void mouvement();

	virtual void seTapperLAffiche();
};


//-------------------------------------------------------------------------------------------------- Fuite
//! \class Etat_Fuite
//! \brief Classe implémentant la classe Etat_Chose

class Etat_Fuite : public Etat_Chose{

private:
	Chose *chose_;

public:

	//! \brief Constructeur
	Etat_Fuite(Chose *c);

	//! \brief Destructeur
	~Etat_Fuite();
	
	//! \brief Méthode de changement d'étât 
	void fuire();
	//! \brief Méthode de changement d'étât 
	void en_securite();
	//! \brief Méthode de changement d'étât 
	void explore();
	//! \brief Méthode de changement d'étât 
	void pourchasser();
	//! \brief Méthode de déplacement des entitées
	void mouvement();

	void seTapperLAffiche();

};


//-------------------------------------------------------------------------------------------------- Repos
//! \class Etat_Repos
//! \brief Classe implémentant la classe Etat_Chose

class Etat_Repos : public Etat_Chose{

private:
	Chose *chose_;

public:

	//! \brief Constructeur
	Etat_Repos(Chose *c);

	//! \brief Destructeur
	~Etat_Repos();

	//! \brief Méthode de changement d'étât 
	void fuire();
	//! \brief Méthode de changement d'étât 
	void en_securite();
	//! \brief Méthode de changement d'étât 
	void explore();
	//! \brief Méthode de changement d'étât 
	void pourchasser();
	//! \brief Méthode de déplacement des entitées
	void mouvement();

	void seTapperLAffiche();

};


//-------------------------------------------------------------------------------------------------- Explore
//! \class Etat_Explore
//! \brief Classe implémentant la classe Etat_Chose

class Etat_Explore : public Etat_Chose{

private:
	Chose *chose_;

public:

	//! \brief Constructeur
	Etat_Explore(Chose *c);

	//! \brief Destructeur
	~Etat_Explore();

	//! \brief Méthode de changement d'étât 
	void fuire();
	//! \brief Méthode de changement d'étât 
	void en_securite();
	//! \brief Méthode de changement d'étât 
	void explore();
	//! \brief Méthode de changement d'étât 
	void pourchasser();
	//! \brief Méthode de déplacement des entitées
	void mouvement();

	void seTapperLAffiche();

};


//-------------------------------------------------------------------------------------------------- Pourchasse
//! \class Etat_Pourchasse
//! \brief Classe implémentant la classe Etat_Chose

class Etat_Pourchasse : public Etat_Chose{

private:
	Chose *chose_;

public:

	//! \brief Constructeur
	Etat_Pourchasse(Chose *c);

	//! \brief Destructeur
	~Etat_Pourchasse();

	//! \brief Méthode de changement d'étât 
	void fuire();
	//! \brief Méthode de changement d'étât 
	void en_securite();
	//! \brief Méthode de changement d'étât 
	void explore();
	//! \brief Méthode de changement d'étât 
	void pourchasser();
	//! \brief Méthode de déplacement des entitées
	void mouvement();

	void seTapperLAffiche();
};

#endif // ETATCHOSE_H