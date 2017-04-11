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

void Statistiques::mettreAJourValeurProfondeurMaxElagage(int profondeur)
{
	if (this->profondeur_max_elagage < profondeur)
	{
		profondeur_max_elagage = profondeur;
	}
	return;
}


double const& Statistiques::getTemps() const
{
	return (double)std::chrono::duration_cast<std::chrono::seconds> (finTimer - debutTimer).count();
}

void Statistiques::afficherTemps()
{
	std::cout << "Resolution effectuee en " << this->getTemps() << "unites de tps";
}
void Statistiques::remiseAZero()
{
	this->nb_Elagages = 0;
	this->nb_Noeuds = 0;
	this->profondeur_max_elagage = 0;
}

void Statistiques::demarrerTimer()
{
	this->debutTimer = Clock::now();
}

void Statistiques::terminerTimer()
{
	this->finTimer = Clock::now();
}

std::ostream& operator<<(std::ostream& os, const Statistiques& stats)
{
	os << "[STATISTIQUES POUR LA RESOLUTION]" << std::endl;
	os << "=================================" << std::endl;
	os << "Nombre de noeuds crees : " << stats.getNb_Noeuds() << std::endl;
	os << "Nombre d'elagages effectues : " << stats.getNb_Elagages() << std::endl;
	os << "Profondeur max d'elagage : " << stats.getProfondeur_Max_Elagage() << std::endl;
	os << "Temps effectue : " << stats.getTemps() << "secondes" << std::endl;
	os << "=================================" << std::endl;
	return os;
}