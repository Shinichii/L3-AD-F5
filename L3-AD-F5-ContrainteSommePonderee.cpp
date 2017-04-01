#include "L3-AD-F5-ContrainteSommePonderee.h"

void ContrainteSommePonderee::ajouterResultat(Variable * resultat)
{
	this->resultat.push_back(resultat);
}

void ContrainteSommePonderee::ajouterPonderationVariable(int ponderation)
{
	this->ponderation.push_back(ponderation);
}

void ContrainteSommePonderee::ajouterPonderationResultat(int ponderation)
{
	this->ponderationResultat.push_back(ponderation);
}
