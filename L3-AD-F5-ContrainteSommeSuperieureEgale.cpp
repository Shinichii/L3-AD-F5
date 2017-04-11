#include "L3-AD-F5-ContrainteSommeSuperieureEgale.h"

ContrainteSommeSuperieureEgale::ContrainteSommeSuperieureEgale()
{
}
/*
Fonction : contrainteRespectee (heritee de la classe Contrainte)
Parametres : Aucun
Renvoie : Un booleen true ou false indiquant si la contrainte est bien respectee
Explication: Cette fonction verifie que la somme des valeurs est superieure ou egale à un pack.
Si cela n'est pas le cas la fonction renverra false
*/
bool ContrainteSommeSuperieureEgale::contrainteRespectee()
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
			DEBUG_MSG("[INFO] : Ajout de la valeur " << (*it)->getValeur() << "a la somme");
			this->ajouterALaSomme((*it)->getValeur());
		}
	}
	if ((this->somme >= this->seuil && nbVariablesNonAssignees == 0) || (nbVariablesNonAssignees > 0))
	{
		DEBUG_MSG("[INFO] Somme des variables superieure ou egale a la valeur attendue. Contrainte respectee");
		return true;
	}
	else
	{
		DEBUG_MSG("[INFO] Somme des variables differente de la valeure attendue. Contrainte NON RESPECTEE");
		return false;
	}

}
/*
Fonction : reduireDomaines (heritee de la classe Contrainte)
Parametres : Un pointeur vers la variable attribue var
Renvoie : Un booleen true ou false indiquant si la reduction de domaine n'amene pas a une situation bloquante
Explication: Cette fonction parcourt toutes les variables associees a la contrainte.
Si la valeur est definie elle l'ajoute a une somme intermediaire
Sinon elle prend la valeur maximale du domaine
On reitere a nouveau dans les varibles non attribuees, on retire leur valeur max de la somme et on regarde pour chaque
valeur du domaine si l'ajouter a la somme rendra la somme inferieure au seuil
Si c'est le cas on retire la valeur de son domaine
Si un domaine est amene a etre vide apres cette operation, la fonction renverra false
A la fin, puisqu'on a pu terminer l'iteration on renvoie true
*/
bool ContrainteSommeSuperieureEgale::reduireDomaines(Variable * var)
{
	int sommeIntermediaire = 0;
	for (Variable* v : variables)
	{
		if (v->getValeur() == VALEUR_NON_DEFINIE)
		{
			std::vector<int> domaineTemporaire = v->getDomaine();
			if ((std::min_element(domaineTemporaire.begin(), domaineTemporaire.end())) != domaineTemporaire.end())
			{
				int tmp = *(std::min_element(domaineTemporaire.begin(), domaineTemporaire.end()));
				sommeIntermediaire += tmp;
			}
			else
			{
				return false;
			}
		}
		else
		{
			sommeIntermediaire += v->getValeur();
		}
	}
	for (Variable* v : variables)
	{
		if (v->getValeur() == VALEUR_NON_DEFINIE)
		{
			std::vector<int> domaineTemporaire = v->getDomaine();
			int tmp = *(std::max_element(domaineTemporaire.begin(), domaineTemporaire.end()));
			sommeIntermediaire -= tmp;
			for (int val : domaineTemporaire)
			{
				if (sommeIntermediaire + val < seuil)
				{
					v->reduireDomaine(val);
					int s = v->getDomaine().size();
					if (s == 0)
					{
						return false;
					}
				}
			}
			sommeIntermediaire += tmp;
		}
	}
	return true;
}

std::ostream & ContrainteSommeSuperieureEgale::afficherCaracteristiques(std::ostream & os)const
{
	os << "Contrainte Somme Superieure ou Egale" << std::endl;
	for (Variable* var : variables)
	{
		os << "x" << var->getNom();
		if (var != variables.back())
		{
			os << " + ";
		}
		else
		{
			os << " >= ";
		}
	}
	os << this->seuil;
	os << std::endl;
	return os;

}
