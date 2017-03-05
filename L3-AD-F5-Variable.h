//
// Created by mathieu on 26/02/2017.
//

#ifndef L3_AD_F5_VARIABLE_H
#define L3_AD_F5_VARIABLE_H

#include <vector>
#include "L3-AD-F5-include.h"

class Variable {
public :
   string nom;
    vector<int> domaine;

public:

    Variable(vector<string> entrer_variable);






    Variable()
    {nom="vide";
    domaine.emplace_back(1);
    domaine.emplace_back(2);
    domaine.emplace_back(3);
    }

   void affichage();

};


#endif //L3_AD_F5_VARIABLE_H
