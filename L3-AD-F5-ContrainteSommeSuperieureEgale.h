#pragma once
#include "L3-AD-F5-ContrainteSeuil.h"

class ContrainteSommeSuperieureEgale : public ContrainteSeuil
{

public:
	ContrainteSommeSuperieureEgale();
	bool contrainteRespectee();
	bool reduireDomaines(Variable* var);
	void remettreDomaines(Variable* var);
};

