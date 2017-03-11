//
// Created by mathieu on 26/02/2017.
// Revised by Aurelien on 11/03/2017

#ifndef L3_AD_F5_CONTRAINTE_H
#define L3_AD_F5_CONTRAINTE_H

#include "L3-AD-F5-include.h"

class Contrainte {

private:
    /*
		Variables a mettre ici 
	*/
public:
    Contrainte();
	virtual bool contrainteRespectee() = 0;
};



#endif //L3_AD_F5_CONTRAINTE_H
