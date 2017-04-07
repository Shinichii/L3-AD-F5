#include "L3-AD-F5-ContrainteSeuil.h"


ContrainteSeuil::ContrainteSeuil()
{
}
/*
Fonction : contrainteRespectee (heritee de la classe Contrainte)
Parametres : Aucun
Renvoie : Un booleen true ou false indiquant si la contrainte est bien respectee
Explication: Cette fonction verifie que chaque valeur est bien unique.
Si cela n'est pas le cas la fonction renverra false
*/
int ContrainteSeuil::getSeuil() const
{
	return seuil;
}

void ContrainteSeuil::setSeuil(int valeur)
{
	this->seuil = valeur;
}

int ContrainteSeuil::getSomme()
{
	return this->somme;
}

void ContrainteSeuil::resetSomme()
{
	somme = 0;
}

void ContrainteSeuil::ajouterALaSomme(int valeur)
{
	this->somme += valeur;
}

