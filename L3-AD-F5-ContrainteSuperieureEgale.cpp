#include "L3-AD-F5-ContrainteSuperieureEgale.h"

ContrainteSuperieureEgale::ContrainteSuperieureEgale()
{
}
/*
Fonction : contrainteRespectee (heritee de la classe Contrainte)
Parametres : Aucun
Renvoie : Un booleen true ou false indiquant si la contrainte est bien respectee
Explication: Cette fonction verifie que toutes les valeurs soient inferieures dans l'ordre croissant
Si cela n'est pas le cas alors elle renverra false
*/
bool ContrainteSuperieureEgale::contrainteRespectee()
{
	this->remettreAZeroVariablesNonAssignees();
	std::list<Variable*>::iterator it = variables.begin();
	while (it != variables.end())
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
				else if ((*it)->getValeur() < (*it2)->getValeur() && it != it2)
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
/*
Fonction : reduireDomaines (heritee de la classe Contrainte)
Parametres : Un pointeur vers la variable attribue var
Renvoie : Un booleen true ou false indiquant si la reduction de domaine n'amene pas a une situation bloquante
Explication: Cette fonction parcourt toutes les variables associees a la contrainte.
Pour toutes les variables avant la variable associee, puisque les variables sont dans un ordre croissant
On retire de leur domaine toutes les valeurs superieures strictement a var->getValeur()
Si un domaine se retrouve vide apres cette operation, la fonction renvoie false
Une fois la variable atteinte, on passe le booleen reduire a vrai
Pour toutes les variables apres la variable associee on retire de leur domaine toutes les valeurs inferieures strictement a var->getValeur()
Si un domaine se retrouve vide apres cette operation, la fonction renverra egalement false
Si on a fini d'iterer alors la reduction de domaines n'entraine pas un etat bloquant et on renvoie true
*/
bool ContrainteSuperieureEgale::reduireDomaines(Variable * var)
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
				if (valeur > var->getValeur())
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
				if (valeur < var->getValeur())
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

std::ostream & ContrainteSuperieureEgale::afficherCaracteristiques(std::ostream & os)const
{
	os << "Contrainte Superieure" << std::endl;
	for (Variable* var : variables)
	{
		os << "x" << var->getNom();
		if (var != variables.back())
		{
			os << " >= ";
		}
	}
	os << std::endl;
	return os;
}
