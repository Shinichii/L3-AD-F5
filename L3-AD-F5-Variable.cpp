//
// Created by mathieu on 26/02/2017.
//

#include "L3-AD-F5-Variable.h"
#include "L3-AD-F5-Utilitaire.h"


Variable::Variable(vector<string> entrer_variable)
{
Utilitaire::affichage(entrer_variable);













}











//-----------------------------------

void Variable::affichage()
{
    cout<<nom<<" :";

    for(int valeur:domaine)
    {
        cout<<valeur<<" ";
    }
    cout<<endl;


}