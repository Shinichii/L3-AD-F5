#pragma once
#include "L3-AD-F5-ContrainteSeuil.h"

class ContrainteSuperieure : public ContrainteSeuil
{

public:
	ContrainteSuperieure();
	bool contrainteRespectee();
	bool reduireDomaines(Variable* var);
	void remettreDomaines(Variable* var);

	std::ostream& afficherCaracteristiques(std::ostream& os)const;
};