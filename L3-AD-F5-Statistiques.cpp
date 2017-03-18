#include "L3-AD-F5-Statistiques.h"

//Crée par Aurélien DENIS le 18/03/2017

Statistiques::Statistiques()
{
	this->nb_Noeuds = 0;
	this->nb_Elagages = 0;
	this->profondeur_max_elagage = 0;
}

int const & Statistiques::getNb_Noeuds() const
{
	return this->nb_Noeuds;
}

int const & Statistiques::getNb_Elagages() const
{
	return this->nb_Elagages;
}

int const & Statistiques::getProfondeur_Max_Elagage() const
{
	return this->profondeur_max_elagage;
}

void Statistiques::incrementerNb_Noeuds()
{
	this->nb_Noeuds++;
}

void Statistiques::incrementerNb_Elagages()
{
	this->nb_Elagages++;
}

void Statistiques::incrementerProfondeur_Max_Elagages()
{
	this->profondeur_max_elagage++;
}

void Statistiques::remiseAZero()
{
	this->nb_Elagages = 0;
	this->nb_Noeuds = 0;
	this->profondeur_max_elagage = 0;
}

ostream& operator<<(ostream& os, const Statistiques& stats)
{
	os << "[STATISTIQUES POUR LA RESOLUTION]" << endl;
	os << "=================================" << endl;
	os << "Nombre de noeuds crees : " << stats.getNb_Noeuds() << endl;
	os << "Nombre d'elagages effectues : " << stats.getNb_Elagages() << endl;
	os << "Profondeur max d'elagage : " << stats.getProfondeur_Max_Elagage() << endl;
	os << "=================================" << endl;
	return os;
}