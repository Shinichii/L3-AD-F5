//
// Created by mathieu on 26/02/2017.
// Revised by Aurelien on 11/03/2017

#include "L3-AD-F5-Contrainte.h"

Contrainte::Contrainte()
{	

}
/*
Fonction : ajouterVariable
Parametres : La variable a ajouter var
Renvoie : true si elle est parvenue a ajouter la variable, false sinon
Explication: La fonction verifie si la variable a deja ete ajoutee � la liste de variables de la contrainte
Si ce n'est pas encore le cas, elle l'ajoute donc.
*/
bool Contrainte::ajouterVariable(Variable var)
{
	if (std::find(variables.begin(), variables.end(), var) != variables.end())
	{
		DEBUG_MSG("[INFO] : La variable a bien ete ajoutee");
		variables.push_back(var);
		return true;
	}
	else
	{
		DEBUG_MSG("[ERROR] La variable est deja presente dans cette contrainte");
		return false;
	}
}
/*
Fonction : retirerVariable
Parametres : Le nom de la variable ou la variable � retirer
Renvoie : true si elle est parvenue � retirer la variable, false sinon.
Explication: La fonction cherche la variable � retirer. Si elle la trouve
*/
bool Contrainte::retirerVariable(std::string nom)
{
	for (std::list<Variable>::iterator it = variables.begin(); it != variables.end(); it++)
	{
		if (it->getNom() == nom)
		{
			variables.erase(it);
			DEBUG_MSG("[INFO] : La variable a bien ete supprimee");
			return true;
		}
	}
	DEBUG_MSG("[ERROR] : Aucune variable de ce nom n'a pu etre trouvee.");
	return false;
}

bool Contrainte::retirerVariable(Variable var)
{
	return retirerVariable(var.getNom());
}

