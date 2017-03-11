//
// Created by mathieu on 26/02/2017.
//

#ifndef L3_AD_F5_CONTRAINTE_H
#define L3_AD_F5_CONTRAINTE_H

#include <iostream>


using namespace std;

#include <vector>

class Contrainte {

private:
    char Type;

    char Cible;
    int Valeur;
    char N;
    vector<int> Tableau;

public:
    Contrainte();


    Contrainte(const Contrainte& entrer);

    void affichage();

};


#endif //L3_AD_F5_CONTRAINTE_H
