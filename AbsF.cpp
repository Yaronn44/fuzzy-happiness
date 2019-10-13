//! \file AbsF.hpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Fichier d'implémentation de la factory permettant la création du terrain

 // Header implémenté
#include "AbsF.hpp"

//class VillePortF;

using namespace std;


//-------------------------------------------------------------------------------------------------- Constructeur / Destructeur

AbsF::AbsF(){}

AbsF::~AbsF(){}

//-------------------------------------------------------------------------------------------------- Static function : Creation d'une Factory


std::unique_ptr<AbsF> AbsF::CreateFactory(int type){

	//*

	if(type == 0){ //------------------------------------------ Campagne

		int b = nbRand(NB_B_CAMPAGNE);

		if(b == 0){
        	return AbsF::CreateCampagne(C_FACT::CPLAINE);
		}
	    else if(b == 1){
	        return AbsF::CreateCampagne(C_FACT::CMONTAGNE);
	    }
	    else{
	    	return AbsF::CreateCampagne(C_FACT::CAUTRE);
	    }
	}
	else{ //------------------------------------------------------ Ville

 	//*/

		int b = nbRand(NB_B_VILLE);

		if(b == 0){
        	return AbsF::CreateVille(V_FACT::VPLAINE);
		}
	    else{
	        return AbsF::CreateVille(V_FACT::VMONTAGNE);
	    }
	//*
	}

	//*/
}


// Ville
std::unique_ptr<AbsF> AbsF::CreateVille(V_FACT factory){

    if(factory == 0){
        return make_unique<VillePlaineF>();
    }
    else //if(factory == VILLE_FACT::MONTAGNE)
    {
        return make_unique<VilleMontF>();
    }
}

//*
// Campagne
std::unique_ptr<AbsF> AbsF::CreateCampagne(C_FACT factory){

    if(factory == 0){
        return make_unique<CampagnePlaineF>();
    }
    else if(factory == 1)
    {
        return make_unique<CampagneMontF>();
    }
    else{
    	return make_unique<CampagneAutreF>();
    }
}

//*/


