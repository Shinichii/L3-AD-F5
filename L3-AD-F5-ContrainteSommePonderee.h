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
	bool reduireDomaines(Variable* var);
	void remettreDomaines(Variable* var);
	void ajouterResultat(Variable* resultat);
	void ajouterPonderationVariable(int ponderation);
	void ajouterPonderationResultat(int ponderation);
	bool contrainteRespectee();

	std::ostream& afficherCaracteristiques(std::ostream& os)const;
};

