#pragma once
#include <iostream>
#include <list>
#include <vector>
class Domaine
{
private:
	std::list<int> valeurs;
public:
	Domaine();
	Domaine(std::list<int> st);
	Domaine(std::vector<int> domaine);
	void ajouterValeurALaListe(int val);
	void retirerValeurALaListe(int val);
	std::list<int> getValeurs();
};