//! \file Humain.hpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Header de Humain.cpp


#ifndef HUMAIN_H
#define HUMAIN_H

#include "Chose.hpp"
#include "Sujet.hpp"
#include "Constante.hpp"

class Etat_Humain;

//! \class Humain
//! \brief Sous classe représentant des choses peuplant le monde
class Humain : public Chose, public SujetObs{

private:

	Inventaire inventaire_;
	Arme *arme_;
	bool vaRevenir_;
	int contamination_;


	std::shared_ptr<Etat_Humain> fuite_;
    std::shared_ptr<Etat_Humain> repos_;
    std::shared_ptr<Etat_Humain> explore_;
    std::shared_ptr<Etat_Humain> pourchasse_;
    std::shared_ptr<Etat_Humain> etat_;


//	Observer *obs_;

public:
	
	//! \brief Constructeur
	Humain();

	//! \brief Destructeur
	~Humain();



	//! Méthodes Pattern State
    void changer_etat_fuite();
    //! Méthodes Pattern State
    void changer_etat_repos();
    //! Méthodes Pattern State
    void changer_etat_explore(int dir);
    //! Méthodes Pattern State
    void changer_etat_pourchasse(int dir);

    //! \brief Méthode de changement d'étât 
    virtual void fuire();
    //! \brief Méthode de changement d'étât 
    virtual void en_securite();
    //! \brief Méthode de changement d'étât 
    virtual void explore(int dir);
    //! \brief Méthode de changement d'étât 
    virtual void pourchasser(int dir);




	// Méthodes d'interaction

	//! \brief La chose perd de la vie
	//! \param i : le nombre de point de vie perdu
	void recevoir_degat(int d);

    //! \brief La chose fait perdre de la vie à une autre chose
    //! \param cible : la chose attaqué
	void attaquer(Chose &cible) const;

	//! \brief La chose ramasse un objet et l'ajoute à son inventaire
    //! \param obj : l'objet ramassé
	void prendre_objet(Stuff obj);

	//! \brief La chose mange un aliment afin de se soigner
	//! \param a : l'aliment ingéré 
	void manger(Aliment a);



	// Getteur / Setteur
	void set_arme(Arme& a);
	bool be_zombie();
	int get_contamination();
	
	void set_pdv(int pdv);
	Arme get_arme() const;
	std::string get_nom_arme();

	bool test_fuite();
	bool test_repos();
	bool test_pourchasse();
	bool test_explore();

};




#endif // HUMAIN_H

