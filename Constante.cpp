//! \file Constante.cpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Fichier d'implémentation des différentes constantes utilent au projet

 // Header implémenté
#include "Constante.hpp"

 // Lib.
#include <ctime> // time()
#include <cstdlib> // srand(), rand()
#include <cstdio> // NULL
#include <iostream>

using namespace std;


int nbRand(int N){

	static int first = 0;

	if(first == 0){
		srand (time (NULL));
		first = 1;
	}

	int randomValue = (int)(rand() / (double)RAND_MAX * (N));
	
	return randomValue;
}

