#pragma once
#include "L3-AD-F5-Contrainte.h"
class ContrainteSeuil : public Contrainte
{
protected:
	int seuil;
	int somme;
public:
	ContrainteSeuil();
	virtual bool contrainteRespectee()=0;
	virtual bool reduireDomaines(Variable* var) = 0;
	virtual void remettreDomaines(Variable* var) = 0;

	int getSeuil() const;
	void setSeuil(int valeur);
	int getSomme();
	void resetSomme();
	void ajouterALaSomme(int valeur);


	virtual std::ostream& afficherCaracteristiques(std::ostream& os)const  =0;
};