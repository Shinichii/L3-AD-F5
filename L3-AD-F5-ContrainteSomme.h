#include "L3-AD-F5-Contrainte.h"
class ContrainteSomme : public Contrainte
{
protected:
	int seuil;
public:
	ContrainteSomme();
	virtual bool contrainteRespectee()=0;

	int getSeuil();
	void setSeuil(int valeur);
};