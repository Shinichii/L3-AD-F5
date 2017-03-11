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
class Contrainte {

protected:
	list<Variable> variables;
    /*
		Variables a mettre ici 
	*/
	
public:
    Contrainte();
	virtual bool contrainteRespectee() = 0;
	bool ajouterVariable(Variable var);
	bool retirerVariable(string nom);
	bool retirerVariable(Variable var);



#endif //L3_AD_F5_CONTRAINTE_H
