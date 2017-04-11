#pragma once
#include "L3-AD-F5-Contrainte.h"

class ContrainteSuperieureEgale : public Contrainte
{

public:
	ContrainteSuperieureEgale();
	bool contrainteRespectee();
	bool reduireDomaines(Variable* var);

	std::ostream& afficherCaracteristiques(std::ostream& os)const;
};