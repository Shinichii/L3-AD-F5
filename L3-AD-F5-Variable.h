//
// Created by mathieu on 26/02/2017.
// Revised by Aurelien on 11/03/2017

#ifndef L3_AD_F5_VARIABLE_H
#define L3_AD_F5_VARIABLE_H
#define VALEUR_NON_DEFINIE -2147483648 

#include <vector>
#include <string>
#include "L3-AD-F5-include.h"

class Variable {
public :
   string nom;
   vector<int> domaine;
   int valeur;
public:

	Variable();
	string getNom();
	void setNom(string nom);
	int getValeur();
	void setValeur(int valeur);
   void affichage();
   friend bool operator==(Variable &v1, Variable &v2);
   friend bool operator!=(Variable &v1, Variable &v2);

};


#endif //L3_AD_F5_VARIABLE_H
