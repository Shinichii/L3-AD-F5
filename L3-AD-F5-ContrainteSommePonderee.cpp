#include "L3-AD-F5-ContrainteSommePonderee.h"

ContrainteSommePonderee::ContrainteSommePonderee()
{
}

bool ContrainteSommePonderee::reduireDomaines(Variable * var)
{
	int i = 0;
	int sommeIntermediaire = 0;
	int coeffMin = 0;
	int coeffMax = 0;
	for (Variable* v : variables)
	{
		if (v->getValeur() == VALEUR_NON_DEFINIE)
		{
			std::vector<int> domaineTemporaire = v->getDomaine();
			if ((std::min_element(domaineTemporaire.begin(), domaineTemporaire.end())) != domaineTemporaire.end())
			{
				int tmp = *(std::min_element(domaineTemporaire.begin(), domaineTemporaire.end()));
				coeffMin += tmp * ponderation[i];
				tmp = *(std::max_element(domaineTemporaire.begin(), domaineTemporaire.end()));
				coeffMax += tmp * ponderation[i];
			}
			else
			{
				return false;
			}
		}
		else
		{
			sommeIntermediaire += v->getValeur()*ponderation[i];
		}
		i++;	
	}
	i = -1;
	for (Variable* v : variables)
	{
		i++;
		if (v->getValeur() == VALEUR_NON_DEFINIE)
		{
			std::vector<int> domaineTemporaire = v->getDomaine();
			for (int val : domaineTemporaire)
			{
				int mintmp = *(std::min_element(domaineTemporaire.begin(), domaineTemporaire.end()));
				coeffMin -= mintmp * ponderation[i];
				int maxtmp = *(std::max_element(domaineTemporaire.begin(), domaineTemporaire.end()));
				coeffMax -= maxtmp * ponderation[i];
				if (sommeIntermediaire + (val * ponderation[i]) + coeffMin > seuil || sommeIntermediaire + (val*ponderation[i]) + coeffMax < seuil)
				{
					v->reduireDomaine(val);
					int s = v->getDomaine().size();
					if (s == 0)
					{
						return false;
					}
				}
				coeffMin += mintmp * ponderation[i];
				coeffMax += maxtmp * ponderation[i];
			}
		}
	}
	return true;
}

void ContrainteSommePonderee::ajouterPonderationVariable(int ponderation)
{
	this->ponderation.push_back(ponderation);
}


bool ContrainteSommePonderee::contrainteRespectee()
{
	this->resetSomme();
	this->remettreAZeroVariablesNonAssignees();
	int i = 0;
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
			this->ajouterALaSomme((*it)->getValeur()*this->ponderation[i]);
		}
		i++;
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

std::ostream & ContrainteSommePonderee::afficherCaracteristiques(std::ostream & os)const
{
	int i = 0;
	os << "Contrainte Somme Ponderee" << std::endl;
	for (Variable* var : variables)
	{
		os << this->ponderation[i] << " * ";
		os << "x" << var->getNom();
		if (var != variables.back())
		{
			os << " + ";
		}
		else
		{
			os << " = ";
		}
		i++;
	}
	os << this->seuil;
	os << std::endl;
	return os;
}
