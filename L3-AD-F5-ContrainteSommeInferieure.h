#pragma once
#include "L3-AD-F5-ContrainteSeuil.h"

class ContrainteSommeInferieure : public ContrainteSeuil
{

public:
	ContrainteSommeInferieure();
	bool contrainteRespectee();
	bool reduireDomaines(Variable* var);


	std::ostream& afficherCaracteristiques(std::ostream& os)const;
};

