#pragma once
#include "L3-AD-F5-Contrainte.h"

class ContrainteInferieure : public Contrainte
{

public:
	ContrainteInferieure();
	bool contrainteRespectee();
	bool reduireDomaines(Variable* var);

	std::ostream& afficherCaracteristiques(std::ostream& os)const;
};

