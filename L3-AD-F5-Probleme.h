

#ifndef L3_AD_F5_PROBLEME_H
#define L3_AD_F5_PROBLEME_H


#include "L3-AD-F5-Variable.h"
#include "L3-AD-F5-Contrainte.h"
#include <vector>

#include <string>

class Probleme {

public:

     std::string nom_Probleme;
     int nb_variable;
      Variable Variables;
      std::vector<Contrainte*> Contraintes;


    std::vector<std::string> getFichier_brut();// temporaire pour les test en attendant

    //constructeur
    Probleme();


    Probleme(std::string Nom_Probleme);

    //affichage
    void afficher();





    //autre


};


#endif //L3_AD_F5_PROBLEME_H
