#include "L3-AD-F5-ContrainteSommeInferieureEgale.h"

ContrainteSommeInferieureEgale::ContrainteSommeInferieureEgale()
{
}
/*
Fonction : contrainteRespectee (heritee de la classe Contrainte)
Parametres : Aucun
Renvoie : Un booleen true ou false indiquant si la contrainte est bien respectee
Explication: Cette fonction verifie que la somme est inférieure ou egale a un seuil
Si cela n'est pas le cas la fonction renverra false
*/
bool ContrainteSommeInferieureEgale::contrainteRespectee()
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
	if ((this->somme <= this->seuil))
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

bool ContrainteSommeInferieureEgale::reduireDomaines(Variable * var)
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
			int tmp = *(std::min_element(domaineTemporaire.begin(), domaineTemporaire.end()));
			sommeIntermediaire -= tmp;
			for (int val : domaineTemporaire)
			{
				if (sommeIntermediaire + val > seuil)
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


std::ostream & ContrainteSommeInferieureEgale::afficherCaracteristiques(std::ostream & os)const
{
	os << "Contrainte Somme Inferieure ou Egale" << std::endl;
	for (Variable* var : variables)
	{
		os << "x" << var->getNom();
		if (var != variables.back())
		{
			os << " + ";
		}
		else
		{
			os << " <= ";
		}
	}
	os << this->seuil;
	os << std::endl;
	return os;

}
