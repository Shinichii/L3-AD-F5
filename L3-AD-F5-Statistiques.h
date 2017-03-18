#include <iostream>
//Cr�e par Aur�lien DENIS le 18/03/2017

/*
Cette classe a pour but de r�cup�rer des donn�es statistiques lors de la r�solution d'un probl�me.
*/
using namespace std;
class Statistiques
{
private:
	int nb_Noeuds;
	int nb_Elagages;
	int profondeur_max_elagage;

public:
	Statistiques();
	int const& getNb_Noeuds() const;
	int const& getNb_Elagages() const;
	int const& getProfondeur_Max_Elagage() const;

	void incrementerNb_Noeuds();
	void incrementerNb_Elagages();
	void incrementerProfondeur_Max_Elagages();

	void remiseAZero();

	friend ostream& operator<<(ostream& os,const Statistiques& stats);

};