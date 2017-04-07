#pragma once
#include "L3-AD-F5-Contrainte.h"

class ContrainteSuperieure : public Contrainte
{

public:
	ContrainteSuperieure();
	bool contrainteRespectee();
	bool reduireDomaines(Variable* var);

	std::ostream& afficherCaracteristiques(std::ostream& os)const;
};