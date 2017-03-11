#pragma once
#include "L3-AD-F5-Contrainte.h"
class ContrainteEgalite : public Contrainte
{
public:
	ContrainteEgalite();
	bool contrainteRespectee();
};
