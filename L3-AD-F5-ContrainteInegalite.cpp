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
	Variable* reference = variables.front();
	for (std::list<Variable*>::iterator it = variables.begin(); it != variables.end(); it++)
	{
		if ((*it)->getValeur() == VALEUR_NON_DEFINIE)
		{
			DEBUG_MSG("[INFO] : Valeur non definie, Ignoree pour la suite de la contrainte.");
		}
		else
		{
			for (std::list<Variable*>::iterator it2 = it++; it2 != variables.end(); it2++)
			{
				if ((*it2)->getValeur() == VALEUR_NON_DEFINIE)
				{
					DEBUG_MSG("[INFO] : Valeur non definie, Ignoree pour la suite de la contrainte.");
				}
				else if ((*it)->getValeur() == (*it2)->getValeur())
				{
					DEBUG_MSG("[INFO] : Valeurs identiques, Contrainte non respectee.");
					return false;
				}
			}
		}
	}
	return true;
}
