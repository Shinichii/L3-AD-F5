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
	for (std::list<Variable*>::iterator it = variables.begin(); it != variables.end(); it++)
	{
		if ((*it)->getValeur() == VALEUR_NON_DEFINIE)
		{
			DEBUG_MSG("[INFO] : Valeur non definie, Ignoree pour la suite de la contrainte.");
		}
		else if ((*it)->getValeur() > seuil)
		{
			DEBUG_MSG("[INFO] : Valeurs superieure au seuil, Contrainte non respectee.");
			return false;
		}
	}
	return true;
}

bool ContrainteInferieure::reduireDomaines(Variable * var)
{
	//TODO : Rediger la fonction
	return false;
}

void ContrainteInferieure::remettreDomaines(Variable * var)
{
	//TODO : Rediger la fonction
}

std::ostream & ContrainteInferieure::afficherCaracteristiques(std::ostream & os)const
{
	// TODO: insérer une instruction return ici+ rediger la fonction
	os << "Pas implemente";
	return os;
}
