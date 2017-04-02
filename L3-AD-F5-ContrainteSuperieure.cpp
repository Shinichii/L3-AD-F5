#include "L3-AD-F5-ContrainteSuperieure.h"

ContrainteSuperieure::ContrainteSuperieure()
{
}
/*
Fonction : contrainteRespectee (heritee de la classe Contrainte)
Parametres : Aucun
Renvoie : Un booleen true ou false indiquant si la contrainte est bien respectee
Explication: Cette fonction verifie que toutes les valeurs soient inferieures a un seuil.
Si cela n'est pas le cas où qu'une valeur est non definie alors elle renverra false
*/
bool ContrainteSuperieure::contrainteRespectee()
{
	for (std::list<Variable*>::iterator it = variables.begin(); it != variables.end(); it++)
	{
		if ((*it)->getValeur() == VALEUR_NON_DEFINIE)
		{
			DEBUG_MSG("[INFO] : Valeur non definie, Ignoree pour la suite de la contrainte.");
			return true;
		}
		else if ((*it)->getValeur() < seuil)
		{
			DEBUG_MSG("[INFO] : Valeurs inferieure au seuil, Contrainte non respectee.");
			return false;
		}
	}
	return true;
}

bool ContrainteSuperieure::reduireDomaines(Variable * var)
{
	//TODO : Rediger la fonction
	return false;
}

void ContrainteSuperieure::remettreDomaines(Variable * var)
{
	//TODO : Rediger la fonction
}
