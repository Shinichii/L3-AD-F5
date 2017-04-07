#pragma once
#include "L3-AD-F5-Contrainte.h"

class ContrainteInferieureEgale : public Contrainte
{

public:
	ContrainteInferieureEgale();
	bool contrainteRespectee();
	bool reduireDomaines(Variable* var);

	std::ostream& afficherCaracteristiques(std::ostream& os)const;
};

