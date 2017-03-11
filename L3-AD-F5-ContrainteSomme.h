#include "L3-AD-F5-Contrainte.h"
class ContrainteSomme : public Contrainte
{
protected:
	int valeurAttendue;
public:
	ContrainteSomme();
	virtual bool contrainteRespectee()=0;

	int getValeurAttendue();
	void setValeurAttendue(int valeur);
};