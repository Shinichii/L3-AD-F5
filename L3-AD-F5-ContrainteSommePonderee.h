#pragma once
#include "L3-AD-F5-ContrainteSeuil.h"
#include <vector>
class ContrainteSommePonderee : public ContrainteSeuil
{
private:
	std::vector<int> ponderation;
	std::list<Variable*> resultat;
	std::vector<int> ponderationResultat;
public:
	ContrainteSommePonderee();
	
	void ajouterPonderationVariable(int ponderation);
	void ajouterPonderationResultat(int ponderation);
	bool contrainteRespectee();

};

