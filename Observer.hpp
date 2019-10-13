//! \file Observer.hpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Header de Observer.cpp


#ifndef OBSERVER_H
#define OBSERVER_H



class Humain;
class Cellule;


class Observer{

private:

public:

        // Constructeur / Destructeur
    Observer();
    virtual ~Observer();

    virtual void actualiser() = 0;
    virtual void afficher() = 0;

    virtual void reinit() = 0;

};


class ObserverHumain : public Observer{

private:
	Humain *sujet_;

public:
	ObserverHumain();
	ObserverHumain(Humain *s);
	~ObserverHumain();

	virtual void actualiser();
	virtual void afficher();
	virtual void reinit();
};





class ObserverCellule : public Observer{

private:
	Cellule *sujet_;

public:
	ObserverCellule();
	ObserverCellule(Cellule *s);
	~ObserverCellule();

	virtual void actualiser();
	virtual void afficher();
	virtual void reinit();
};




#endif // OBSERVER_H


