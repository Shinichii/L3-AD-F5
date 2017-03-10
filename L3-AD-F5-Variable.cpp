//
// Created by mathieu on 26/02/2017.
//

#include "L3-AD-F5-Variable.h"




void Variable::affichage()
{
    std::cout << this->nom << " :";

    for(int valeur:domaine)
    {
        std::cout << valeur<<" ";
    }
    std::cout << std::endl;


}