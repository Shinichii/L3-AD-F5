//
// Created by mathieu on 26/02/2017.
//

#include "L3-AD-F5-Contrainte.h"

Contrainte::Contrainte()
{ Type='a';
    Cible='a';
    Valeur=1;
    N='d';
    Tableau.emplace_back(42);
    Tableau.emplace_back(41);
}



Contrainte::Contrainte(const Contrainte& entrer)
{ Type=entrer.Type;
    Cible=entrer.Cible;
    Valeur=entrer.Valeur;
    N=entrer.N;
    Tableau=entrer.Tableau;

}

void Contrainte::affichage()
{
 cout <<"a refaire "<<Type<<" "<<Cible<<" "<<Valeur<<" "<<N<<" "<<Type<<" "<<Type<<" ";

     for(int tmp:Tableau){cout<<tmp<<" ";}
    cout<<endl;
}