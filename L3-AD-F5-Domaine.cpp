#include "L3-AD-F5-Domaine.h"

Domaine::Domaine(std::list<int> st)
{
	for (int i : st)
	{
		valeurs.push_back(i);
	}
}

Domaine::Domaine(std::vector<int> domaine)
{
	for (int i : domaine)
	{
		valeurs.push_back(i);
	}
}

void Domaine::ajouterValeurALaListe(int val)
{
	valeurs.push_back(val);
}

void Domaine::retirerValeurALaListe(int val)
{
	valeurs.remove(val);
}

std::list<int> Domaine::getValeurs()
{
	return std::list<int>(this->valeurs);
}
