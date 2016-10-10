#include <iostream>
#include "EtatChose.hpp"
#include "Chose.hpp"
#include "Humain.hpp"
#include "Stuff.hpp"
#include "Inventaire.hpp"

using namespace std;

int main(int argc, char const *argv[]){

	Humain matheux;
	Humain keupon;

	Arme couteau("sa bite", 1000, 45);

	matheux.prendre_objet(couteau);
	matheux.set_arme(couteau);
	cout << "Matheux n'a pour arme que " << matheux.get_arme().get_nom() << endl;
	matheux.attaquer(keupon);

	cout << "Matheux frappe Keupon dans la bouche avec " << matheux.get_arme().get_nom() << ". Il reste " << keupon.get_pdv() << " point de vie à Keupon" << endl;

	Aliment merde("Merde", 1, 5);

	keupon.prendre_objet(merde);
	keupon.manger(merde);

	cout << "Keupon mange de la merde, cela lui rend " << merde.get_soin() << " pdv. Il a maintenant " << keupon.get_pdv() << " pdv." << endl;

	Aliment tiramisu("Merde survitaminée", 1, 80);

	keupon.prendre_objet(tiramisu);
	keupon.manger(tiramisu);

	cout << "Keupon mange un tiramisu, cela lui rend " << tiramisu.get_soin() << " pdv. Il a maintenant " << keupon.get_pdv() << " pdv." << endl;

	return 0;
}