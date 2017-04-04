#pragma once
#include "L3-AD-F5-Contrainte.h"
class ContrainteInegalite : public Contrainte
{
public:
	ContrainteInegalite();
	bool contrainteRespectee();
	bool reduireDomaines(Variable* var);
	void remettreDomaines(Variable* var);
};
