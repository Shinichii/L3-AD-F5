#pragma once
#include "L3-AD-F5-ContrainteSeuil.h"

class ContrainteSommeSuperieure : public ContrainteSeuil
{

public:
	ContrainteSommeSuperieure();
	bool contrainteRespectee();
	bool reduireDomaines(Variable* var);

	std::ostream& afficherCaracteristiques(std::ostream& os)const;
};

