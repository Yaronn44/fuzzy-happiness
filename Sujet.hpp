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

#endif //SUJET_H