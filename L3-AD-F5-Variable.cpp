//
// Created by mathieu on 26/02/2017.
//

#include "L3-AD-F5-Variable.h"




void Variable::affichage()
{
    cout<<nom<<" :";

    for(int valeur:domaine)
    {
        cout<<valeur<<" ";
    }
    cout<<endl;


}