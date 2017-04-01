//
// Created by mathieu on 26/02/2017.
// Revised by Aurelien on 11/03/2017

#include <stdlib.h>
#include "L3-AD-F5-Variable.h"
#include "L3-AD-F5-Utilitaire.h"



int const& Variable::getNom() const
{
	return int(this->nom);
}

void Variable::setNom(int const& nom)
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

std::vector<int> Variable::getDomaine()
{
	return std::vector<int>(this->domaine);
}

bool Variable::valeurDansLeDomaine(int valeur)
{
	return std::find(domaine.begin(), domaine.end(), valeur) - domaine.begin() == domaine.size();
}

void Variable::reduireDomaine(int valeur)
{
}


//----------------------------------------------------------------------------------------------------------------------
//-------------------------------------   Constructeur     -------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
Variable::Variable()
{
	this->nom = -1;
	this->valeur = VALEUR_NON_DEFINIE;
}

Variable::Variable(int nom, std::vector<int> domaine)
{
	this->nom = nom;
	for (std::vector<int>::iterator it = domaine.begin(); it != domaine.end(); it++)
	{
		this->domaine.push_back(*it);
	}
}

//----------------------------------------------------------------------------------------------------------------------
//-------------------------------------   Surchage operateur  ----------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------


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
std::ostream& operator<<(std::ostream& os, Variable& v1)
{
	std::cout << "Variable x" << v1.getNom() << std::endl;
	std::cout << "Domaine = ";
	std::vector<int> domaine = v1.getDomaine();
	for (std::vector<int>::iterator it = domaine.begin(); it != domaine.end(); it++)
	{
		os << *it << " ";
	}
	return os;
}
