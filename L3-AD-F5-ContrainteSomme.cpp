#include "L3-AD-F5-ContrainteSomme.h"


ContrainteSomme::ContrainteSomme()
{
}
/*
Fonction : contrainteRespectee (heritee de la classe Contrainte)
Parametres : Aucun
Renvoie : Un booleen true ou false indiquant si la contrainte est bien respectee
Explication: Cette fonction verifie que chaque valeur est bien unique.
Si cela n'est pas le cas la fonction renverra false
*/
int ContrainteSomme::getValeurAttendue()
{
	return valeurAttendue;
}

void ContrainteSomme::setValeurAttendue(int valeur)
{
	this->valeurAttendue = valeur;
}

