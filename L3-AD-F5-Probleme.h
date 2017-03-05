

#ifndef L3_AD_F5_PROBLEME_H
#define L3_AD_F5_PROBLEME_H


#include "L3-AD-F5-Variable.h"
#include "L3-AD-F5-Contrainte.h"
#include <vector>
#include "L3-AD-F5-Utilitaire.h"

class Probleme {

public:

      string nom_Probleme;
     int nb_variable;
      Variable Variables;
      vector<Contrainte*> Contraintes;


    vector<string> getFichier_brut();// temporaire pour les test en attendant

    //constructeur
    Probleme();


    Probleme(string Nom_Probleme);

    //affichage
    void afficher();





    //autre


};


#endif //L3_AD_F5_PROBLEME_H
