#pragma once
#include "L3-AD-F5-ContrainteSeuil.h"

class ContrainteSommeInferieureEgale : public ContrainteSeuil
{

public:
	ContrainteSommeInferieureEgale();
	bool contrainteRespectee();
	bool reduireDomaines(Variable* var);
	void remettreDomaines(Variable* var);
};

