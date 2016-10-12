#include <iostream>
#include "EtatChose.hpp"
#include "Chose.hpp"
#include "Humain.hpp"
#include "Stuff.hpp"
#include "Inventaire.hpp"

using namespace std;

int main(int argc, char const *argv[]){

	Humain matheux;
	Humain papy;

	Arme couteau("un poireaux", 1000, 45);

	matheux.prendre_objet(couteau);
	matheux.set_arme(couteau);
	cout << "Matheux n'a pour arme qu' " << matheux.get_arme().get_nom() << endl;
	matheux.attaquer(papy);

	cout << "Matheux frappe Papy dans la machoire avec " << matheux.get_arme().get_nom() << ". Il reste " << papy.get_pdv() << " point de vie à Papy" << endl;

	Aliment merde("Merde", 1, 5);

	papy.prendre_objet(merde);
	papy.manger(merde);

	cout << "Papy mange de la merde, cela lui rend " << merde.get_soin() << " pdv. Il a maintenant " << papy.get_pdv() << " pdv." << endl;

	Aliment tiramisu("Gateau de Mamy", 1, 80);

	papy.prendre_objet(tiramisu);
	papy.manger(tiramisu);

	cout << "Papy mange un tiramisu, cela lui rend " << tiramisu.get_soin() << " pdv. Il a maintenant " << papy.get_pdv() << " pdv." << endl;

	return 0;
}