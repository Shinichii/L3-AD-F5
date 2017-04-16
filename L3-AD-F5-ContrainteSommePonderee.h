#pragma once
#include "L3-AD-F5-ContrainteSeuil.h"
#include <vector>
#include <cmath>
class ContrainteSommePonderee : public ContrainteSeuil
{
private:
	std::vector<int> ponderation;

public:
	ContrainteSommePonderee();
	bool reduireDomaines(Variable* var);

	void ajouterResultat(Variable* resultat);
	void ajouterPonderationVariable(int ponderation);
	bool contrainteRespectee();


	std::ostream& afficherCaracteristiques(std::ostream& os)const;
};

