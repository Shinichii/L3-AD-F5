//
// Created by mathieu on 26/02/2017.
// Revised by Aurelien on 11/03/2017

#include "L3-AD-F5-Variable.h"



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
	return this->valeur;
}

void Variable::setValeur(int const& valeur)
{
	this->valeur = valeur;
}

void Variable::remettreValeursInitiales()
{
	this->valeur = this->valeurInitiale;
}

void Variable::remettreDomaineInitial()
{
	this->domaine = this->domaineInitial;
}

void Variable::remettreEtatInitial()
{
	this->remettreDomaineInitial();
	this->remettreValeursInitiales();
}

std::vector<int> Variable::getDomaine()
{
	return std::vector<int>(this->domaine);
}

std::vector<int> Variable::getDomaineInitial()
{
	return std::vector<int>(domaineInitial);
}

bool Variable::valeurDansLeDomaine(int valeur)
{
	return std::find(domaine.begin(), domaine.end(), valeur) - domaine.begin() == domaine.size();
}

void Variable::reduireDomaine(int valeur)
{
	if (domaineContient(valeur))
	{
		this->domaine.erase(std::remove(this->domaine.begin(), this->domaine.end(), valeur), this->domaine.end());
	}
}

void Variable::reduireDomaine(std::vector<int> valeurs)
{
	for (std::vector<int>::iterator it = valeurs.begin(); it != valeurs.end(); it++)
	{
		this->reduireDomaine(*it);
	}
}

void Variable::reduireDomaineAUneValeur(int valeur)
{
	if (valeurDansLeDomaine(valeur))
	{
		this->domaine = std::vector<int>(1, valeur);
	}
}

void Variable::agrandirDomaine(int valeur)
{
	if (!domaineContient(valeur))
	{
		this->domaine.push_back(valeur);
	}
}

bool Variable::domaineInitialContient(int valeur)
{
	return std::find(this->domaineInitial.begin(), this->domaineInitial.end(), valeur) != this->domaineInitial.end();
}

bool Variable::domaineContient(int valeur)
{
	return std::find(this->domaine.begin(), this->domaine.end(), valeur) != this->domaine.end();
}

void Variable::remettreDomaine(std::vector<int> valeurs)
{
	this->domaine.clear();
	for (int i : valeurs)
	{
		this->domaine.push_back(i);
	}
}




//----------------------------------------------------------------------------------------------------------------------
//-------------------------------------   Constructeur     -------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
Variable::Variable()
{
	this->nom = -1;
	this->valeur = VALEUR_NON_DEFINIE;
	this->valeurInitiale = VALEUR_NON_DEFINIE;
}

Variable::Variable(int nom, std::vector<int> domaine)
{
	this->nom = nom;
	for (std::vector<int>::iterator it = domaine.begin(); it != domaine.end(); it++)
	{
		this->domaine.push_back(*it);
	}
	if (this->domaine.size() == 1)
	{
		this->valeur = domaine.at(0);
		this->valeurInitiale = this->valeur;
	}
	else
	{
		this->valeur = VALEUR_NON_DEFINIE;
		this->valeurInitiale = VALEUR_NON_DEFINIE;
	}
	this->domaineInitial = this->domaine;
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
	os << "Variable x" << v1.getNom() << std::endl;
	if (v1.getValeur() == VALEUR_NON_DEFINIE)
	{
		os << "Domaine = ";
		std::vector<int> domaine = v1.getDomaine();
		for (std::vector<int>::iterator it = domaine.begin(); it != domaine.end(); it++)
		{
			os << *it << " ";
		}
	}
	else
	{
		os << "Valeur = " << v1.getValeur();
	}
	os << std::endl;
	return os;
}
