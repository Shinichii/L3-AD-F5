//
// Created by mathieu on 26/02/2017.
// Revised by Aurelien on 11/03/2017

#include "L3-AD-F5-Variable.h"


Variable::Variable()
{
	nom = "Non nommee";
	valeur = VALEUR_NON_DEFINIE;
}

string Variable::getNom()
{
	return string(this->nom);
}

void Variable::setNom(string nom)
{
	this->nom = nom;
}

int Variable::getValeur()
{
	return valeur;
}

void Variable::setValeur(int valeur)
{
	this->valeur = valeur;
}

void Variable::affichage()
{
    std::cout << this->nom << " :";

    for(int valeur:domaine)
    {
        std::cout << valeur<<" ";
    }
    std::cout << std::endl;


}
bool operator==(Variable &v1, Variable &v2)
{
	return v1.getValeur() == v2.getValeur();
}
bool operator!=(Variable &v1, Variable &v2)
{
	return !(v1.getValeur() == v2.getValeur());
}
bool operator==(Variable &v1, int n)
{
	return v1.getValeur() == n;
}