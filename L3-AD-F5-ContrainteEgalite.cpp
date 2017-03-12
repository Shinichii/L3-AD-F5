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
	Variable reference = variables.front();
	for (std::list<Variable>::iterator it = variables.begin(); it != variables.end(); it++)
	{
		if (*it == VALEUR_NON_DEFINIE)
		{
			DEBUG_MSG("[INFO] : Valeur non definie, Ignoree pour la suite de la contrainte.");
		}
		else if (*it != reference)
		{
			DEBUG_MSG("[INFO] : Valeurs non identiques, Contrainte non respectee.");
			return false;
		}
	}
	return true;
}
