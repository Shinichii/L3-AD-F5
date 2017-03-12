#pragma once
#include "L3-AD-F5-ContrainteSeuil.h"

class ContrainteInferieure : public ContrainteSeuil
{

public:
	ContrainteInferieure();
	bool contrainteRespectee();

};

