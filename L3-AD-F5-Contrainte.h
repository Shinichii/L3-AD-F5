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
#define	CONTRAINTE_INFERIEURE_EGALE 2
#define CONTRAINTE_SUPERIEURE_EGALE 3
#define CONTRAINTE_SOMME_EXACTE 4
#define CONTRAINTE_SOMME_INFERIEURE 5
#define CONTRAINTE_SOMME_SUPERIEURE 6
#define CONTRAINTE_SOMME_PONDEREE 7

class Contrainte {

protected:
	std::list<Variable*> variables;
	/*
		Variables a mettre ici
	*/

public:
	Contrainte();
	virtual bool contrainteRespectee() = 0;
	bool ajouterVariable(Variable* var);
	bool retirerVariable(int nom);
	bool retirerVariable(Variable* var);

};

#endif //L3_AD_F5_CONTRAINTE_H
