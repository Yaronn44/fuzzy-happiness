//! \file Etat_Humain.hpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Header de EtatHumain.cpp
 
#ifndef ETATHUMAIN_H
#define ETATHUMAIN_H

 // Lib.
#include <iostream>

class Humain;


//------------------------------------------------------------------------------ Général
//! \class Etat_Humain
//! \brief Classe "abstraite" permettant l'implémentation du pattern States

class Etat_Humain{
private:

public:

	//! \brief Constructeur
	Etat_Humain();

	//! \brief Destructeur
	virtual ~Etat_Humain();

	//! \brief Méthode de changement d'étât 
	virtual void fuire();
	//! \brief Méthode de changement d'étât 
	virtual void en_securite();
	//! \brief Méthode de changement d'étât 
	virtual void explore(int dir);
	//! \brief Méthode de changement d'étât 
	virtual void pourchasser(int dir);
	//! \brief Méthode de déplacement des entitées

	virtual void seTapperLAffiche();
};


//-------------------------------------------------------------------------------------------------- Fuite
//! \class Etat_Fuite
//! \brief Classe implémentant la classe Etat_Humain

class Etat_Fuite : public Etat_Humain{

private:
	Humain *chose_;

public:

	//! \brief Constructeur
	Etat_Fuite(Humain *c);

	//! \brief Destructeur
	~Etat_Fuite();
	
	//! \brief Méthode de changement d'étât 
	void fuire();
	//! \brief Méthode de changement d'étât 
	void en_securite();
	//! \brief Méthode de changement d'étât 
	void explore(int dir);
	//! \brief Méthode de changement d'étât 
	void pourchasser(int dir);

	void seTapperLAffiche();

};


//-------------------------------------------------------------------------------------------------- Repos
//! \class Etat_Repos
//! \brief Classe implémentant la classe Etat_Humain

class Etat_Repos : public Etat_Humain{

private:
	Humain *chose_;

public:

	//! \brief Constructeur
	Etat_Repos(Humain *c);

	//! \brief Destructeur
	~Etat_Repos();

	//! \brief Méthode de changement d'étât 
	void fuire();
	//! \brief Méthode de changement d'étât 
	void en_securite();
	//! \brief Méthode de changement d'étât 
	void explore(int dir);
	//! \brief Méthode de changement d'étât 
	void pourchasser(int dir);

	void seTapperLAffiche();

};


//-------------------------------------------------------------------------------------------------- Explore
//! \class Etat_Explore
//! \brief Classe implémentant la classe Etat_Humain

class Etat_Explore : public Etat_Humain{

private:
	Humain *chose_;

public:

	//! \brief Constructeur
	Etat_Explore(Humain *c);

	//! \brief Destructeur
	~Etat_Explore();

	//! \brief Méthode de changement d'étât 
	void fuire();
	//! \brief Méthode de changement d'étât 
	void en_securite();
	//! \brief Méthode de changement d'étât 
	void explore(int dir);
	//! \brief Méthode de changement d'étât 
	void pourchasser(int dir);

	void seTapperLAffiche();

};


//-------------------------------------------------------------------------------------------------- Pourchasse
//! \class Etat_Pourchasse
//! \brief Classe implémentant la classe Etat_Humain

class Etat_Pourchasse : public Etat_Humain{

private:
	Humain *chose_;

public:

	//! \brief Constructeur
	Etat_Pourchasse(Humain *c);

	//! \brief Destructeur
	~Etat_Pourchasse();

	//! \brief Méthode de changement d'étât 
	void fuire();
	//! \brief Méthode de changement d'étât 
	void en_securite();
	//! \brief Méthode de changement d'étât 
	void explore(int dir);
	//! \brief Méthode de changement d'étât 
	void pourchasser(int dir);

	void seTapperLAffiche();
};

#endif // ETATHUMAIN_H