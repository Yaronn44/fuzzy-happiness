//! \file Monde.cpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Fichier d'implémentation du monde dans lequel les Choses vont évoluer

 // Header implémenté
#include "MondeA.hpp"
 
 // Lib.
#include "UniquePointer.hpp"


using namespace std;


//-------------------------------------------------------------------------------------------------- Constructeur / Destructeur

Monde::Monde() :w_(2), h_(2), age_(1){
    
    vectPtrBiome world_;

    for(int i = 0; i < w_*h_; ++i){
        world_.push_back(make_unique<Biome>());
    }

    for(int i = 0; i < h_; ++i){
        for(int k = 0; k < B_::HEIGHT; ++k){
            for(int j = 0; j < w_; ++j){
                vector<Cellule> ligne = world_.at(j+ i*w_)->ligne(k); ;
                for (int e = 0; e < ligne.size(); ++e){
                    monde_.push_back(ligne.at(e));
                }
                
            }
        }
    }
}

Monde::Monde(int w, int h) : w_(w), h_(h), age_(1){
    
    vectPtrBiome world_;

    for(int i = 0; i < w_*h_; ++i){
        world_.push_back(make_unique<Biome>());
    }

    for(int i = 0; i < h_; ++i){
        for(int k = 0; k < B_::HEIGHT; ++k){
            for(int j = 0; j < w_; ++j){
                vector<Cellule> ligne = world_.at(j+ i*w_)->ligne(k); ;
                for (int e = 0; e < ligne.size(); ++e){
                    monde_.push_back(ligne.at(e));
                }
                
            }
        }
    }
}

Monde::~Monde(){}


//-------------------------------------------------------------------------------------------------- Affichage

int Monde::getAge(){
    return age_;
}


//-------------------------------------------------------------------------------------------------- Affichage

void Monde::afficher(){
    for(int i = 0; i < h_; ++i){
        for (int k = 0; k < B_::HEIGHT; ++k)
        {
            for(int j = 0; j < w_; ++j){ 
                for(int l = 0; l < B_::WIDTH; ++l){
                    monde_.at((j+l) + (i+k)*w_).afficher();
                    cout << " ";
                }
                cout << "| ";
            }
            cout << endl; 
        }
        for(int j = 1; j < B_::WIDTH*w_+w_; ++j){
            cout << "-- ";
        }
        cout << endl;
    }
    
    cout << endl << endl;
}

void Monde::afficherInv(int i){
    monde_.at(i).afficherInv();
}

int Monde::densite(int i){
    return monde_.at(i).densiteH();
}


bool valide(int x, int y){
    if (x >= 0 && x <= B_::WIDTH - 1 && y >= 0 && y <= B_::HEIGHT)
        return true;
    else
        return false;
}

void Monde::direction_zombie(){

    for (int i = 0; i < w_*B_::WIDTH; ++i){
        for (int j = 0; j < h_*B_::HEIGHT; ++j){
            int coordRes = 0;
            int maxBruit = 0;

            for (int larg = -3; larg <= 3; ++larg){
                for (int haut = -3; haut <= 3; ++haut){

                    if (valide(i+larg, j+haut) ){
                        if (maxBruit < monde_.at((i+larg) + (j+haut)*B_::WIDTH).get_bruit()){
                            maxBruit = monde_.at((i+larg) + (j+haut)*B_::WIDTH).get_bruit();
                            coordRes = (i+larg) + (j+haut)*B_::WIDTH;
                        }
                    }
                }
            }
            vectPtrZombie zomb = monde_.at(i+j*B_::WIDTH).getListeZombie();
            
            for (int nb = 0; nb < zomb.size(); ++nb){
                zomb.at(nb)->set_direction(coordRes);
            }
        }
    }


}

void Monde::vieillir(){
    ++age_;
}
