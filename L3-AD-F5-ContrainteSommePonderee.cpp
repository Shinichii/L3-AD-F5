#include "L3-AD-F5-ContrainteSommePonderee.h"

bool ContrainteSommePonderee::reduireDomaines(Variable * var)
{
	//TODO : Rediger la fonction
	return false;
}

void ContrainteSommePonderee::remettreDomaines(Variable * var)
{
	//TODO : Rediger la fonction
}

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

std::ostream & ContrainteSommePonderee::afficherCaracteristiques(std::ostream & os)const
{
	// TODO: insérer une instruction return ici+ rediger la fonction
	os << "Pas implemente";
	return os;
}
