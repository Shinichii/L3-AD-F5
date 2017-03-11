#include "L3-AD-F5-ContrainteSommeExacte.h"



ContrainteSommeExacte::ContrainteSommeExacte()
{
}
/*
Fonction : contrainteRespectee (heritee de la classe Contrainte)
Parametres : Aucun
Renvoie : Un booleen true ou false indiquant si la contrainte est bien respectee
Explication: Cette fonction verifie que la somme des valeurs est egale exactement a un seuil
Si cela n'est pas le cas la fonction renverra false
*/
bool ContrainteSommeExacte::contrainteRespectee()
{
	int somme;
	for (list<Variable>::iterator it = variables.begin(); it != variables.end(); it++)
	{
		if (*it == VALEUR_NON_DEFINIE)
		{
			DEBUG_MSG("[INFO] : Valeur non definie, Ignoree pour la suite de la contrainte.");
		}
		else 
		{
			DEBUG_MSG("[INFO] : Ajout de la valeur " << it->getValeur() << "a la somme" );
		}
	}
	if (somme == valeurAttendue)
	{
		DEBUG_MSG("[INFO] Somme des variables egale a la valeur attendue. Contrainte respectee");
		return true;
	}
	else
	{
		DEBUG_MSG("[INFO] Somme des variables differente de la valeure attendue. Contrainte NON RESPECTEE");
		return false;
	}

}

