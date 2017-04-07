//
// Created by mathieu on 26/02/2017.
// Revised by Aurelien on 11/03/2017

#ifndef L3_AD_F5_VARIABLE_H
#define L3_AD_F5_VARIABLE_H
#define VALEUR_NON_DEFINIE -325687

#include <iostream>

#include <vector>
#include <algorithm>
#include <string>

class Variable {
public :
   int nom;
   std::vector<int> domaine;
   std::vector<int> domaineInitial;
   int valeur;
   int valeurInitiale;

	Variable();
	Variable(int nom, std::vector<int> domaine);

	int const& getNom() const;
	void Variable::setNom(int const& nom);
	int const& getValeur() const;
	void setValeur(int const& valeur);

	void remettreValeursInitiales();
	void remettreDomaineInitial();
	void remettreEtatInitial();

	std::vector<int> getDomaine();
	std::vector<int> getDomaineInitial();

	bool valeurDansLeDomaine(int valeur);
	void reduireDomaine(int valeur);
	void reduireDomaine(std::vector<int> valeurs);
	void reduireDomaineAUneValeur(int valeur);

	void agrandirDomaine(int valeur);
	void agrandirDomaine(std::vector<int> valeurs);

	bool domaineInitialContient(int valeur);
	bool domaineContient(int valeur);

	void remettreDomaine(std::vector<int> valeurs);

	friend std::ostream& operator<<(std::ostream& os, Variable& v1);
	friend bool operator==(const Variable &v1, const Variable &v2);
	friend bool operator==(Variable &v1, int n);
	friend bool operator!=(Variable &v1, Variable &v2);

};


#endif //L3_AD_F5_VARIABLE_H
