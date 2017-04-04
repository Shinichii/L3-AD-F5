#pragma once
#include "L3-AD-F5-ContrainteSeuil.h"

class ContrainteInferieure : public ContrainteSeuil
{

public:
	ContrainteInferieure();
	bool contrainteRespectee();
	bool reduireDomaines(Variable* var);
	void remettreDomaines(Variable* var);

};

