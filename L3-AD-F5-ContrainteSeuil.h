#pragma once
#include "L3-AD-F5-Contrainte.h"
class ContrainteSeuil : public Contrainte
{
protected:
	int seuil;
public:
	ContrainteSeuil();
	virtual bool contrainteRespectee()=0;
	virtual bool reduireDomaines(Variable* var) = 0;
	virtual void remettreDomaines(Variable* var) = 0;

	int getSeuil();
	void setSeuil(int valeur);
};