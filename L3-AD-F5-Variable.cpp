//
// Created by mathieu on 26/02/2017.
// Revised by Aurelien on 11/03/2017

#include "L3-AD-F5-Variable.h"


Variable::Variable()
{
	nom = "Non nommee";
	valeur = VALEUR_NON_DEFINIE;
}

string const& Variable::getNom() const
{
	return string(this->nom);
}

void Variable::setNom(string const& nom)
{
	this->nom = nom;
}

int const& Variable::getValeur() const
{
	return valeur;
}

void Variable::setValeur(int const& valeur)
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
bool operator==(const Variable &v1, const Variable &v2)
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