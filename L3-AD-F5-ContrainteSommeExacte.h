#pragma once
#include "L3-AD-F5-ContrainteSeuil.h"
class ContrainteSommeExacte : public ContrainteSeuil
{

public:
	ContrainteSommeExacte();
	bool contrainteRespectee();
	bool reduireDomaines(Variable* var);


	std::ostream& afficherCaracteristiques(std::ostream& os)const;
};

