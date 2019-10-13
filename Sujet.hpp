//! \file Sujet.hpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Header de Sujet.cpp


#ifndef SUJET_H
#define SUJET_H

 // Lib.
#include <iostream>
 // Proj.
#include "UniquePointer.hpp"

class Observer;

class SujetObs{

protected:
	//std::shared_ptr<Observer> obs_;
	Observer *obs_;

public:

        // Constructeur / Destructeur
    SujetObs();
    ~SujetObs();

    virtual void enregistrer_obs(Observer *o);//std::shared_ptr<Observer> o);
    virtual void supprimer_obs();
    virtual void notifier_obs();

};


/*
class SujetHumain : public SujetObs{

private:
	ObserverHumain obs_;
	Humain donnee_;

public:
	SujetHumain();
	~SujetHumain();

	void enregister_obs(ObserverHumain o);
	void supprimer_obs();
	void notifier_obs();
	Humain get_donnee();
	void set_donnee(Humain d);
};


class SujetCellule : public SujetObs{

private:
	ObserverCellule obs_;
	Cellule donnee_;

public:
	SujetCellule();
	~SujetCellule();

	void enregister_obs(ObserverCellule o);
	void supprimer_obs();
	void notifier_obs();
	Cellule get_donnee();
	void set_donnee(Cellule d);
};
//*/

#endif // SUJET_H