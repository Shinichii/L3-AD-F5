#include "L3-AD-F5-ContrainteEgalite.h"

ContrainteEgalite::ContrainteEgalite()
{
}
/*
Fonction : contrainteRespectee (heritee de la classe Contrainte)
Parametres : Aucun
Renvoie : Un booleen true ou false indiquant si la contrainte est bien respectee
Explication: Cette fonction verifie que toutes les valeurs soient égales les unes aux autres.
Si cela n'est pas le cas où qu'une valeur est non definie alors elle renverra false
*/
bool ContrainteEgalite::contrainteRespectee()
{
	Variable* reference = variables.front();
	for (std::list<Variable*>::iterator it = variables.begin(); it != variables.end(); it++)
	{
		if ((*it)->getValeur() == VALEUR_NON_DEFINIE)
		{
			DEBUG_MSG("[INFO] : Valeur non definie, Ignoree pour la suite de la contrainte.");
		}
		else if ((*it)->getValeur() != reference->getValeur())
		{
			DEBUG_MSG("[INFO] : Valeurs non identiques, Contrainte non respectee.");
			DEBUG_MSG("[INFO] : Valeurs en question : x" << (*it)->getNom() << "et x" << reference->getNom());
			return false;
		}
	}
	return true;
}
/*
Fonction : reduireDomaines (heritee de la classe Contrainte)
Parametres : Un pointeur vers la variable attribue var
Renvoie : Un booleen true ou false indiquant si la reduction de domaine n'amene pas a une situation bloquante
Explication: Cette fonction parcourt toutes les variables associees a la contrainte.
Pour chaque variable differente de var, on retire de leur domaines toutes les valeurs differentes de var->getValeur()
Si un domaine se retrouve vide, la fonction renverra false
Si elle a fini d'iterer sur les variables de la contrainte elle renverra true
*/
bool ContrainteEgalite::reduireDomaines(Variable * var)
{
	for (Variable* v : variables)
	{
		if (v != var)
		{
			for (int valeur : v->getDomaine())
			{
				if (valeur != var->getValeur())
				{
					v->reduireDomaine(valeur);
				}
			}
			int s = v->getDomaine().size();
			if (s == 0)
			{
				DEBUG_MSG("[INFO] : Domaine non valable, solution non viable");
				return false;
			}
		}
	}
	return true;
}

std::ostream & ContrainteEgalite::afficherCaracteristiques(std::ostream & os)const
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
