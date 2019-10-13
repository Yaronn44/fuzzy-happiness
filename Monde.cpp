//! \file Monde.cpp
//! \author DROMIGNY--CHEVREUIL Ivan, FRETAUD Killian
//! \date 06/10/2016
//! \brief Fichier d'implémentation du monde dans lequel les Choses vont évoluer

 // Header implémenté
#include "Monde.hpp"
 
 // Lib.
#include "UniquePointer.hpp"


using namespace std;


//-------------------------------------------------------------------------------------------------- Constructeur / Destructeur

Monde::Monde() :w_(2), h_(2), age_(1), pas_(1){
    
    vectPtrBiome world_;

    for(int i = 0; i < w_*h_; ++i){
        world_.push_back(make_unique<Biome>());
    }
    int p = 0;
    for(int i = 0; i < h_; ++i){
        for(int k = 0; k < B_::HEIGHT; ++k){
            for(int j = 0; j < w_; ++j){
                vector<Cellule> ligne = world_.at(j+ i*w_)->ligne(k);
                for (int e = 0; e < ligne.size(); ++e){
                    ligne.at(e).set_pos(p);
                    ++p;
                    ligne.at(e).set_wMonde(w_*B_::WIDTH);
                    monde_.push_back(ligne.at(e));
                }
            }
        }
    }
}

Monde::Monde(int w, int h) : w_(w), h_(h), age_(1), pas_(1){
    
    vectPtrBiome world_;

    for(int i = 0; i < w_*h_; ++i){
        world_.push_back(make_unique<Biome>());
    }
    int p = 0;
    for(int i = 0; i < h_; ++i){
        for(int k = 0; k < B_::HEIGHT; ++k){
            for(int j = 0; j < w_; ++j){
                vector<Cellule> ligne = world_.at(j+ i*w_)->ligne(k);
                for (int e = 0; e < ligne.size(); ++e){
                    ligne.at(e).set_pos(p);
                    ++p;
                    ligne.at(e).set_wMonde(w_*B_::WIDTH);
                    monde_.push_back(ligne.at(e));
                }
            }
        }
    }
}

Monde::~Monde(){}


//-------------------------------------------------------------------------------------------------- Affichage

int Monde::get_age(){
    return age_;
}

int Monde::get_taille(){
    return monde_.size();
}


//-------------------------------------------------------------------------------------------------- Affichage
/*
void Monde::afficher(){

    // Pour chaque ligne de biome (5 lignes entières)
    for(int i = 0; i < h_; ++i){
        // Pour chaque ligne dans un biome (1 ligne entière)
        for (int k = 0; k < B_::HEIGHT; ++k){

            // Pour chaque ligne de cellule
            for(int ligneCel = 0; ligneCel < H_CEL; ++ligneCel){

                // Pour chaque biome dans la ligne (1 ligne de 8 cellules)
                for(int j = 0; j < w_; ++j){ 
                    // Pour chaque cellule de la ligne du biome (1 cellule)
                    for(int l = 0; l < B_::WIDTH; ++l){

                        monde_.at((j+l) + (i+k)*w_).afficher(ligneCel);
                        cout << " ";
                    }
                    cout << "| ";
                }
                cout << endl; 
            }
        }

        for(int j = 1; j < B_::WIDTH*w_+w_; ++j){
            cout << "-- ";
        }
        cout << endl;
    }
    
    cout << endl << endl;
}
//*/


void Monde::afficher(){

    // Pour chaque ligne de biome (5 lignes entières)
    for(int i = 0; i < h_; ++i){
        // Pour chaque ligne dans un biome (1 ligne entière)
        for (int k = 0; k < B_::HEIGHT; ++k){

            // Pour chaque biome dans la ligne (1 ligne de 8 cellules)
            for(int j = 0; j < w_; ++j){ 
                // Pour chaque cellule de la ligne du biome (1 cellule)
                for(int l = 0; l < B_::WIDTH; ++l){

                    // Pour chaque ligne de cellule

                    monde_.at((l+j*B_::WIDTH) + (i*B_::HEIGHT*B_::WIDTH + k*B_::WIDTH)*w_).afficher();
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
    if (x >= 0 && x <= B_::WIDTH*w_ - 1 && y >= 0 && y <= B_::HEIGHT*h_ - 1)
        return true;
    else
        return false;
}

int Monde::direction_zombie(){

    int coordRes = 0;

    for (int i = 0; i < w_*B_::WIDTH; ++i){
        for (int j = 0; j < h_*B_::HEIGHT; ++j){

            int maxBruit = 0;

            for (int larg = -3; larg <= 3; ++larg){
                for (int haut = -3; haut <= 3; ++haut){

                    if (valide(i+larg, j+haut*B_::WIDTH*w_)){
                        if (maxBruit < monde_.at((i+larg) + (j+haut)*B_::WIDTH*w_).get_bruit()){

                            maxBruit = monde_.at((i+larg) + (j+haut)*B_::WIDTH*w_).get_bruit();
                            coordRes = (i+larg) + (j+haut)*B_::WIDTH*w_;
                        }
                    }
                }
            }
        }
    }
    return coordRes;
}

void Monde::vieillir(){

    action_humains();
    action_zombies();
    mouvement_choses();
    age_ += pas_;
}

void Monde::mouvement_choses(){

    for (int i = 0; i < monde_.size(); ++i){

        for (int j = 0; j < monde_.at(i).get_liste_humain().size(); ++j){

            int posTmp = monde_.at(i).get_humain(j)->mouvement();

            if (posTmp != i){

                monde_.at(posTmp).get_liste_humain().push_back(monde_.at(i).get_humain(j));
                monde_.at(i).get_liste_humain().erase(monde_.at(i).get_liste_humain().begin() + j);
            }
        }

        for (int j = 0; j < monde_.at(i).get_liste_zombie().size(); ++j){

            int posTmp = monde_.at(i).get_zombie(j)->mouvement();

            if (posTmp != i){

                monde_.at(posTmp).get_liste_zombie().push_back(monde_.at(i).get_zombie(j));
                monde_.at(i).get_liste_zombie().erase(monde_.at(i).get_liste_zombie().begin() + j);
            }
        }

        monde_.at(i).actualiser_bruit();
    }
}

void Monde::action_humains(){

    for (int i = 0; i < monde_.size(); ++i){

        int nbH = monde_.at(i).get_liste_humain().size();
        int nbZ = monde_.at(i).get_liste_zombie().size();

        
        if (nbZ = 0){
            for (int j = 0; j < nbH; ++j){
                // Si l'humain est en train d'explorer
                if (monde_.at(i).get_humain(j).test_explore()){

                    // Sa fatigue augmente
                    monde_.at(i).get_humain(j).set_fatigue(3);

                    // Si sa fatigue est >= 70, il se repose
                    if (monde_.at(i).get_humain(j).get_fatigue() >= 70){
                        monde_.at(i).get_humain(j).en_securite();
                    }
                    // Sinon si il est arrivé à destination
                    else if ( monde_.at(i).get_humain(j).get_dir() == i){
                        int dirX = nbRand(3);
                        int dirY = nbRand(3);

                        while(!valide(i%(wMonde_) + dirX, i/(wMonde_) + dirY)){
                            dirX = nbRand(3);
                            dirY = nbRand(3);
                        }
                        // Il va explorer un nouvelle endroit
                        monde_.at(i).get_humain(j).explore();
                    }
                    // Ramassage d'un objet TODO
                    if (monde_.at(i).get_taille_inv() > 0){
                    
                    }
                }
                // Si l'humain est au repos
                else if (monde_.at(i).get_humain(j).test_repos()){

                    // Sa fatigue diminue
                    monde_.at(i).get_humain(j).set_fatigue(-10);

                    // Si sa fatigue est <= 30
                    if (monde_.at(i).get_humain(j).get_fatigue() <= 30){

                        int action = nbRand(10);

                        // Il y a 8/10 chances que l'humain parte en exploration sinon il continue de se reposer
                        if (action < 8){
                            int dirX = nbRand(3);
                            int dirY = nbRand(3);

                            while(!valide(i%(wMonde_) + dirX, i/(wMonde_) + dirY)){
                                dirX = nbRand(3);
                                dirY = nbRand(3);
                            }

                            monde_.at(i).get_humain(j).explore(dirX + dirY*wMonde_);
                        }
                    }
                }
                // Si l'humain est en train de fuire
                else if(monde_.at(i).get_humain(j).test_fuite()){

                    // Sa fatigue augmente
                    monde_.at(i).get_humain(j).set_fatigue(5);

                    // Si il est arrivé à destination de sa fuite il se repose
                    if ( monde_.at(i).get_humain(j).get_dir() == i){
                        monde_.at(i).get_humain(j).en_securite();
                    }
                    else{
                        int action = nbRand(10);

                        // Sinon il y a 2/10 chances qu'il se repose sinon il continue de fuire jusqu'à sa destination
                        if (action > 8){
                            monde_.at(i).get_humain(j).en_securite();
                        }
                    }
                }
                // Si l'humain est en train de pourchasser
                else if(monde_.at(i).get_humain(j).test_pourchasse()){
                    int dirX = nbRand(3);
                    int dirY = nbRand(3);

                    while(!valide(i%(wMonde_) + dirX, i/(wMonde_) + dirY)){
                        dirX = nbRand(3);
                        dirY = nbRand(3);
                    }
                    if (monde_.at(i).get_humain(j).get_fatigue() >= 70){
                        // On est obligé de passer par un état intermédiaire 
                        monde_.at(i).get_humain(j).explore(dirX + dirY*wMonde_);
                        monde_.at(i).get_humain(j).en_securite();
                    }
                    else{
                        monde_.at(i).get_humain(j).explore(dirX + dirY*wMonde_);
                    }
                }
            }
        }
        else{
            for (int j = 0; j < nbH; ++j){
                // Si l'humain n'est pas en fuite
                if (!monde_.at(i).get_humain(j).test_fuite()){

                    // Si il y a trop de zombie alors
                    if (nbH < nbZ - 5){

                        
                        int action = nbRand(10);

                        // Il y a 9/10 chances que l'humain se mette à fuire
                        if (action < 9){
                            monde_.at(i).get_humain(j).fuire();
                        }
                        // Sinon il combat vaillament les zombies (même en 1 contre 100)
                        else{
                            // Si il est au repos il faut le faire passer par un état intermédiaire
                            if (monde_.at(i).get_humain(j).test_repos())
                                monde_.at(i).get_humain(j).explore(i);

                            int nb = nbRand(nbZ);
                            monde_.at(i).get_humain(j).attaquer(monde_.at(i).get_zombie(nb);
                            monde_.at(i).get_humain(j).pourchasse(i);
                            monde_.at(i).get_humain(j).set_fatigue(5);
                        }
                    }
                    // Sinon le nombre de zombie n'est pas trop important donc
                    else{
                        int action = nbRand(10);

                        // Il y a 9/10 de chance que l'humain ne panique pas et attaque un zombie aléatoirement
                        if (action < 9){
                            // Si il est au repos il faut le faire passer par un état intermédiaire
                            if (monde_.at(i).get_humain(j).test_repos())
                                monde_.at(i).get_humain(j).explore(i);

                            int nb = nbRand(nbZ);
                            monde_.at(i).get_humain(j).attaquer(monde_.at(i).get_zombie(nb);
                            monde_.at(i).get_humain(j).pourchasse(i);
                            monde_.at(i).get_humain(j).set_fatigue(5);
                            // L'état pourchasse ne sert qu'à rester sur la case actuelle pour le moment (les zombies ne fuient pas)
                        }
                        else
                            monde_.at(i).get_humain(j).fuire();
                    }
                }
                // Sinon si il est arrivé à destination il continue de fuire (oui même si il y a des camarades il fait son lache)
                else{
                    if ( monde_.at(i).get_humain(j).get_dir() == i){
                        int dirX = nbRand(3);
                        int dirY = nbRand(3);

                        while(!valide(i%(wMonde_) + dirX, i/(wMonde_) + dirY)){
                            dirX = nbRand(3);
                            dirY = nbRand(3);
                        }
                        monde_.at(i).get_humain(j).set_direction(dirX + dirY*wMonde_);
                    }
                }
            }
        }
    }
}

void Monde::action_zombies(){

    for (int i = 0; i < monde_.size(); ++i){

        int nbH = monde_.at(i).get_liste_humain().size();
        int nbZ = monde_.at(i).get_liste_zombie().size();

        // Si il n'y a pas d'humain sur la case actuelle le zombie se déplace (ou non)
        if (nbH == 0){
            int dir = direction_zombie();
            monde_.at(i).actualiser_dir_zomb(dir);
        }
        // Sinon il attaque un humain aléatoirement sur tous ceux présents
        else{
            for (int j = 0; j < nbZ; ++j){
                int nb = nbRand(nbH);
                monde_.at(i).get_zombie(j).attaquer(monde_.at(i).get_humain(nb));
            }
        }
    }
}

void Monde::mort(){
    for (int i = 0; i < monde_.size(); ++i){

        int nbH = monde_.at(i).get_liste_humain().size();
        int nbZ = monde_.at(i).get_liste_zombie().size();

        for (int j = 0; j < nbZ; ++j){
            if (monde_.at(i).get_zombie(j).get_pdv() <= 0){
                monde_.at(i).get_liste_zombie().erase(monde_.at(i).get_liste_zombie().begin() + j);
            }
        }

        // faire transformation en zombie
        for (int j = 0; j < nbH; ++j){
            if (monde_.at(i).get_humain(j).get_pdv() <= 0 || monde_.at(i).get_humain(j).get_fatigue() >= 100){
                monde_.at(i).get_liste_humain().erase(monde_.at(i).get_liste_humain().begin() + j);
            }
        }
    }
}

/*
//-------------------------------------------------------------------------------------------------- Constructeur / Destructeur

Monde::Monde() :w_(3), h_(2), age_(1), pas_(1){

    for(int i = 0; i < w_*h_; ++i){
        world_.push_back(make_unique<Biome>());
    }
}

Monde::Monde(int w, int h) : w_(w), h_(h), age_(1), pas_(1){

    for(int i = 0; i < w_*h_; ++i){
        world_.push_back(make_unique<Biome>());
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
        for(int k = 0; k < B_::HEIGHT; ++k){
            for(int j = 0; j < w_; ++j){
                world_.at(j+ i*w_)->afficherLigne(k);
            }
            cout << endl << endl;
        }
        for(int j = 0; j < B_::WIDTH*w_+w_; ++j){
            cout << "--";
        }
        cout << endl << endl;
    }
}

void Monde::afficherStructure(){
    for(int i = 0; i < h_; ++i){
        for(int k = 0; k < B_::HEIGHT; ++k){
            for(int j = 0; j < w_; ++j){
                world_.at(j+ i*w_)->afficherLigneStructure(k);
            }
            cout << endl << endl;
        }
        for(int j = 0; j < B_::WIDTH*w_+w_; ++j){
            cout << "--";
        }
        cout << endl << endl;
    }
}


void Monde::afficherLoot(int i){
    world_.at(i)->afficherLoot();
}

void Monde::afficherInv(){
    world_.at(0)->afficherInv(1);
}


int Monde::densite(int h, int w){
    return world_.at(1)->densiteZ(h,w);
}



void Monde::vieillir(){
    for (int i = 0; i < pas_; ++i)
    {
        ++age_;
    }
}*/