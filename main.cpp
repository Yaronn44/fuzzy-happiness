
#include <iostream>
#include <memory>


//#include "Stuff.hpp"
//#include "Inventaire.hpp"
#include "Monde.hpp"
//#include "Constante.hpp"
//#include "UniquePointer.hpp"
//#include "EtatChose.hpp"
//#include "Chose.hpp"



#include "Humain.hpp"
#include "Observer.hpp"

using namespace std;

int main(){


	Monde test(2,2);
/*	for (int i = 0; i < 10; ++i)
	{
		cout << "Ligne " << i << endl << endl;
		test.vieillir();
*/		test.afficher();
//	};
/*
	cout << endl;

	test.afficherInv(0);

	cout << endl;

	Humain homme = Humain();
	Arme pistolet = Arme("Revolver R5", 5, 100);
	ObserverHumain obs = ObserverHumain(&homme);

	//obs.actualiser();
	homme.set_arme(pistolet);
	

	shared_ptr<Arme> gun = make_shared<Arme>("Test", 3, 9);
	gun->afficher();

	cout << endl << "Densite : " << test.densite(0) << endl;
	cout << "Densite : " << test.densite(1) << endl;
	cout << "Densite : " << test.densite(2) << endl;
	cout << "Densite : " << test.densite(3) << endl;

	obs.reinit();
	obs.actualiser();
*/

    return 0;
}

