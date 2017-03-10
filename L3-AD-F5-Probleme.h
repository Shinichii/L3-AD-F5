

#ifndef L3_AD_F5_PROBLEME_H
#define L3_AD_F5_PROBLEME_H

#include "L3-AD-F5-include.h"
#include "L3-AD-F5-Variable.h"
#include "L3-AD-F5-Contrainte.h"
#include <vector>

class Probleme {

public:

      string nom_Probleme;
      vector<Variable*> Variables;
      vector<Contrainte*> Contraintes;



    //constructeur
    Probleme();
    Probleme(string Nom_Probleme);

    //affichage
    void afficher();


    //autre


};


#endif //L3_AD_F5_PROBLEME_H
