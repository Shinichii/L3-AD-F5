#include "L3-AD-F5-ContrainteInegalite.h"

ContrainteInegalite::ContrainteInegalite()
{
}
/*
Fonction : contrainteRespectee (heritee de la classe Contrainte)
Parametres : Aucun
Renvoie : Un booleen true ou false indiquant si la contrainte est bien respectee
Explication: Cette fonction verifie que chaque valeur est bien unique.
Si cela n'est pas le cas la fonction renverra false
*/
bool ContrainteInegalite::contrainteRespectee()
{
	this->remettreAZeroVariablesNonAssignees();
	for (std::list<Variable*>::iterator it = variables.begin(); it != variables.end(); it++)
	{
		if ((*it)->getValeur() == VALEUR_NON_DEFINIE)
		{
			DEBUG_MSG("[INFO] : Valeur non definie, Ignoree pour la suite de la contrainte.");
			this->incrementerNbVariablesNonAssignees();
		}
		else
		{
			for (std::list<Variable*>::iterator it2 = it; it2 != variables.end(); it2++)
			{
				if ((*it2)->getValeur() == VALEUR_NON_DEFINIE)
				{
					DEBUG_MSG("[INFO] : Valeur non definie, Ignoree pour la suite de la contrainte.");
				}
				else if ((*it)->getValeur() == (*it2)->getValeur() && it != it2)
				{
					DEBUG_MSG("[INFO] : Valeurs identiques, Contrainte non respectee.");
					DEBUG_MSG("[INFO] : Valeurs en question : x" << (*it)->getNom() << " et x" << (*it2)->getNom());
					return false;
				}
			}
		}
	}
	DEBUG_MSG("[INFO] : Contrainte respectee");
	return true;
}

std::ostream & ContrainteInegalite::afficherCaracteristiques(std::ostream & os)const
{
	os << "Contrainte Inegalite" << std::endl;
	for (Variable* var : variables)
	{
		os << "x" << var->getNom();
		if (var != variables.back())
		{
			os << " != ";
		}
	}
	os << std::endl;
	return os;
}
bool ContrainteInegalite::reduireDomaines(Variable * var)
{
	for (Variable* v : variables)
	{
		if (v != var)
		{
			v->reduireDomaine(var->getValeur());
			int s = v->getDomaine().size();
			if (s == 0)
			{
				DEBUG_MSG("[INFO] : Domaine vide, solution non viable");
				return false;
			}
		}
	}
	return true;
}
