#include <iostream>
#include <chrono>
//Crée par Aurélien DENIS le 18/03/2017

/*
Cette classe a pour but de récupérer des données statistiques lors de la résolution d'un problème.
*/
typedef std::chrono::high_resolution_clock Clock;
class Statistiques
{
private:
	std::string nomMethode;
	std::chrono::high_resolution_clock::time_point debutTimer;
	std::chrono::high_resolution_clock::time_point finTimer;
	int nb_Noeuds;
	int nb_Elagages;
	int profondeur_max_elagage;

public:
	Statistiques();
	int const& getNb_Noeuds() const;
	int const& getNb_Elagages() const;
	int const& getProfondeur_Max_Elagage() const;
	double const& getTemps() const;

	void incrementerNb_Noeuds();
	void incrementerNb_Elagages();
	void mettreAJourValeurProfondeurMaxElagage(int profondeur);

	void remiseAZero();
	void demarrerTimer();
	void terminerTimer();

	void afficherTemps();
	friend std::ostream& operator<<(std::ostream& os,const Statistiques& stats);

};