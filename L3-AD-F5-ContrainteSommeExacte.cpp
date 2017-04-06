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
	this->resetSomme();
	this->remettreAZeroVariablesNonAssignees();
	for (std::list<Variable*>::iterator it = variables.begin(); it != variables.end(); it++)
	{
		if ((*it)->getValeur() == VALEUR_NON_DEFINIE)
		{
			DEBUG_MSG("[INFO] : Valeur non definie, Ignoree pour la suite de la contrainte.");
			this->incrementerNbVariablesNonAssignees();
		}
		else 
		{
			DEBUG_MSG("[INFO] : Ajout de la valeur " << (*it)->getValeur() << "a la somme" );
			this->ajouterALaSomme((*it)->getValeur());
		}
	}
	if ((this->somme == this->seuil && nbVariablesNonAssignees == 0) || (nbVariablesNonAssignees > 0 && this->somme < this->seuil))
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

bool ContrainteSommeExacte::reduireDomaines(Variable * var)
{
	//TODO : Rediger la fonction
	for (Variable* v : variables)
	{
		if (v->getValeur() == VALEUR_NON_DEFINIE)
		{
			//Reduction du domaine
			//Regarder si chaque valeur du domaine + somme dépasse le seuil, si c'est le cas on supprime
			//On supprime egalement les valeurs qui donnent la somme egale s'il y a plus d'une valeur non assignee
			for (int valeur : v->getDomaine())
			{
				if ((valeur + this->somme > seuil && this->nbVariablesNonAssignees == 0) ||  (valeur + somme > seuil))
				{
					v->reduireDomaine(valeur);
				}
			}
			int s = v->getDomaine().size();
			if (s == 0)
			{
				DEBUG_MSG("[INFO] : Domaine vide, solution non viable");
				return false;
			}
		}
	}
	return true;
}

std::ostream & ContrainteSommeExacte::afficherCaracteristiques(std::ostream & os)const
{
	os << "Contrainte Somme Exacte" << std::endl;
	for (Variable* var : variables)
	{
		os << "x" << var->getNom();
		if (var != variables.back())
		{
			os << " + ";
		}
		else
		{
			os << " = ";
		}
	}
	os << this->seuil;
	os << std::endl;
	return os;
}
