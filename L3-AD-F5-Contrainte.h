//
// Created by mathieu on 26/02/2017.
// Revised by Aurelien on 11/03/2017

#ifndef L3_AD_F5_CONTRAINTE_H
#define L3_AD_F5_CONTRAINTE_H

#include "L3-AD-F5-Variable.h"
#include "L3-AD-F5-debug.h"
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <iostream>

#define CONTRAINTE_EGALITE 0
#define CONTRAINTE_DIFFERENTE 1
#define	CONTRAINTE_INFERIEURE 2
#define CONTRAINTE_SUPERIEURE 3
#define CONTRAINTE_SOMME_EXACTE 4
#define CONTRAINTE_SOMME_INFERIEURE 5
#define CONTRAINTE_SOMME_SUPERIEURE 6
#define CONTRAINTE_SOMME_PONDEREE 7
#define CONTRAINTE_SOMME_INFERIEURE_EGALE 8
#define CONTRAINTE_SOMME_SUPERIEURE_EGALE 9
#define CONTRAINTE_INFERIEURE_EGALE 10
#define CONTRAINTE_SUPERIEURE_EGALE 11

class Contrainte {

protected:
	std::list<Variable*> variables;
	int nbVariablesNonAssignees;
	/*
		Variables a mettre ici
	*/

public:
	Contrainte();
	virtual bool contrainteRespectee() = 0;
	bool ajouterVariable(Variable* var);
	bool retirerVariable(int nom);
	bool retirerVariable(Variable* var);
	bool contient(Variable* var);
	virtual bool reduireDomaines(Variable* var) = 0;
	void remettreDomaines(Variable* var);
	virtual std::ostream& afficherCaracteristiques(std::ostream& os)const = 0;


	friend std::ostream& operator<<(std::ostream& os, const Contrainte &c);
	void incrementerNbVariablesNonAssignees();
	void remettreAZeroVariablesNonAssignees();
	int const& getNbVariablesNonAssignees() const;
};

#endif //L3_AD_F5_CONTRAINTE_H
