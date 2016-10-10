/** 
 * @file Inventaire.hpp
 * @author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
 * @date 06/10/2016
 * @brief Header de Inventaire.tpp
 *  
**/

#include <iostream>
#include <string>

 using namespace std;

class Stuff{

private:
	string nom_;
	int resistance_;

public:
	Stuff();
	~Stuff();
};


class Arme : public Stuff{

private:
	int degat_;

public:
	Arme();
	~Arme();
};

class Vehicule : public Stuff{

private:
	int vitesse_;

public:
	Vehicule();
	~Vehicule();
};

class Aliment : public Stuff{

private:
	int soin_;

public:
	Aliment();
	~Aliment();
};






