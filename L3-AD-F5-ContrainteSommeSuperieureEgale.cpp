#include "L3-AD-F5-ContrainteSommeSuperieureEgale.h"

ContrainteSommeSuperieureEgale::ContrainteSommeSuperieureEgale()
{
}
/*
Fonction : contrainteRespectee (heritee de la classe Contrainte)
Parametres : Aucun
Renvoie : Un booleen true ou false indiquant si la contrainte est bien respectee
Explication: Cette fonction verifie que la somme des valeurs est superieure ou egale à un pack.
Si cela n'est pas le cas la fonction renverra false
*/
bool ContrainteSommeSuperieureEgale::contrainteRespectee()
{
	int somme = 0;
	for (std::list<Variable*>::iterator it = variables.begin(); it != variables.end(); it++)
	{
		if ((*it)->getValeur() == VALEUR_NON_DEFINIE)
		{
			DEBUG_MSG("[INFO] : Valeur non definie, Ignoree pour la suite de la contrainte.");
			return true;
		}
		else
		{
			somme += (*it)->getValeur();
			DEBUG_MSG("[INFO] : Ajout de la valeur " << (*it)->getValeur() << "a la somme");
		}
	}
	if (somme >= seuil)
	{
		DEBUG_MSG("[INFO] Somme des variables superieure ou egale a la valeur attendue. Contrainte respectee");
		return true;
	}
	else
	{
		DEBUG_MSG("[INFO] Somme des variables differente de la valeure attendue. Contrainte NON RESPECTEE");
		return false;
	}
}

bool ContrainteSommeSuperieureEgale::reduireDomaines(Variable * var)
{
	//TODO : Rediger la fonction
	return false;
}

std::ostream & ContrainteSommeSuperieureEgale::afficherCaracteristiques(std::ostream & os)const
{
	os << "Contrainte Somme Superieure ou Egale" << std::endl;
	for (Variable* var : variables)
	{
		os << "x" << var->getNom();
		if (var != variables.back())
		{
			os << " + ";
		}
		else
		{
			os << " >= ";
		}
	}
	os << this->seuil;
	os << std::endl;
	return os;

}
