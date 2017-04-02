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
	for (std::list<Variable*>::iterator it = variables.begin(); it != variables.end(); it++)
	{
		if ((*it)->getValeur() == VALEUR_NON_DEFINIE)
		{
			DEBUG_MSG("[INFO] : Valeur non definie, Ignoree pour la suite de la contrainte.");
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
void ContrainteInegalite::remettreDomaines(Variable* var)
{
	for (Variable* variable : this->variables)
	{
		if (variable->domaineInitialContient(var->getValeur()))
		{
			variable->agrandirDomaine(var->getValeur());
		}
	}
}
bool ContrainteInegalite::reduireDomaines(Variable * var)
{
	for (Variable* v : variables)
	{
		if (v != var)
		{
			v->reduireDomaine(var->getValeur());
			if (v->getDomaine().size() == 0)
			{
				DEBUG_MSG("[INFO] : Domaine vide, solution non viable");
				return false;
			}
		}
	}
	return true;
}