//
// Created by mathieu on 26/02/2017.
//

#ifndef L3_AD_F5_VARIABLE_H
#define L3_AD_F5_VARIABLE_H

#include <vector>
#include <string>
#include "L3-AD-F5-include.h"

class Variable {
public :
   string nom;
   vector<int> domaine;
   int valeur;
public:

    Variable()
    {nom="vide";}
	string getNom();
	void setNom(string nom);
	int getValeur();
	void setValeur(int valeur);
   void affichage();

};


#endif //L3_AD_F5_VARIABLE_H
