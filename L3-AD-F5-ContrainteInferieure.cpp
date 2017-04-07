#include "L3-AD-F5-ContrainteInferieure.h"

ContrainteInferieure::ContrainteInferieure()
{
}
/*
Fonction : contrainteRespectee (heritee de la classe Contrainte)
Parametres : Aucun
Renvoie : Un booleen true ou false indiquant si la contrainte est bien respectee
Explication: Cette fonction verifie que toutes les valeurs soient égales les unes aux autres.
Si cela n'est pas le cas où qu'une valeur est non definie alors elle renverra false
*/
bool ContrainteInferieure::contrainteRespectee()
{
	this->remettreAZeroVariablesNonAssignees();
	std::list<Variable*>::iterator it = variables.begin();
	
	while(it != variables.end())
		{
			std::list<Variable*>::iterator it2 = it;
			if ((*it)->getValeur() != VALEUR_NON_DEFINIE)
			{
				while (it2 != variables.end())
				{
					if ((*it)->getValeur() == VALEUR_NON_DEFINIE || (*it2)->getValeur() == VALEUR_NON_DEFINIE)
					{
						DEBUG_MSG("[INFO] : Valeur non definie, Ignoree pour la suite de la contrainte.");
					}
					else if ((*it)->getValeur() >= (*it2)->getValeur() && it != it2)
					{
						DEBUG_MSG("[INFO] : Valeurs superieure a la valeur suivante, Contrainte non respectee.");
						return false;
					}
					it2++;
				}
			}
			else
			{
				this->incrementerNbVariablesNonAssignees();
			}
			it++;
		}
	return true;
}

bool ContrainteInferieure::reduireDomaines(Variable * var)
{
	bool reduire = false;
	for (std::list<Variable*>::iterator it = variables.begin(); it != variables.end(); it++)
	{
		if ((*it) == var) // Protection pour ne pas reduire la variable qui est reduite à une valeur
		{
			reduire = true;
		}
		else if (reduire)
		{
			for (int valeur : (*it)->getDomaine())
			{
				if (valeur <= var->getValeur())
				{
					(*it)->reduireDomaine(valeur);
					int s = (*it)->getDomaine().size();
					if (s == 0)
					{
						DEBUG_MSG("[INFO] : Domaine vide, solution non viable");
						return false;
					}
				}
			}
		}
		else
		{
			for (int valeur : (*it)->getDomaine())
			{
				if (valeur >= var->getValeur())
				{
					(*it)->reduireDomaine(valeur);
					int s = (*it)->getDomaine().size();
					if (s == 0)
					{
						DEBUG_MSG("[INFO] : Domaine vide, solution non viable");
						return false;
					}
				}
			}
		}
	}
	return true;
}


std::ostream & ContrainteInferieure::afficherCaracteristiques(std::ostream & os)const
{
	os << "Contrainte Inferieure" << std::endl;
	for (Variable* var : variables)
	{
		os << "x" << var->getNom();
		if (var != variables.back())
		{
			os << " < ";
		}
	}
	os << std::endl;
	return os;
}
