//
// Created by mathieu on 26/02/2017.
//

#ifndef L3_AD_F5_CONTRAINTE_H
#define L3_AD_F5_CONTRAINTE_H

#include "include.h"

class Contrainte {

private:
    char Type;

    char Cible;
    int Valeur;
    char N;
    list<int> Tableau;

public:
        Contrainte();

};


#endif //L3_AD_F5_CONTRAINTE_H
