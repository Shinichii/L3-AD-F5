#include "L3-AD-F5-Probleme.h"


//----------------------------------------------------------------------------------------------------------------------
//------------------------------------------  Constructeur    ----------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------

Probleme::Probleme()
{
    //ouvrir le fichier

    //§§§§§§§§§§§§§§§§§§§§§ ouverture fichier et stockage dans une variable
    //nom_Probleme on le deff
    int nbVariable,nbContrainte;


    //remplir les variables et leur ensemble de donnees

    for(int i=2;i<nbVariable+2;i++)
    {

    }

    //remplir les contraintes
    for (int i=2+nbVariable;i<2+nbVariable+nbContrainte;i++)
    {


    }


}

Probleme::Probleme(string Nom_Probleme)
{
nom_Probleme=Nom_Probleme;
Variables.emplace_back(new Variable());
    Variables.emplace_back(new Variable());

//Contraintes.emplace_back(new Contrainte());
//Contraintes.emplace_back(new Contrainte());


}

//----------------------------------------------------------------------------------------------------------------------
//------------------------------------------  Affichage    -------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------

void Probleme::afficher()
{
    std::cout << "Le probleme : " << this->nom_Probleme<<std::endl;
    std::cout << "Il y a " <<Variables.size()<<" variables :"<<std::endl;

    for(Variable* variable:Variables) { variable->affichage();}
   // for(Contrainte* contrainte:Contraintes) { contrainte->affichage();}


}