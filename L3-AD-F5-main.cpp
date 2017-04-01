#include <iostream>
using namespace std;


#include "L3-AD-F5-parser.h"
#include "L3-AD-F5-file_Finder.h"
#include <list>
#include <vector>
#include "L3-AD-F5-Probleme.h"


int main() {
	string s;
	std::vector<std::string> vc;
	std::fstream F;
	s = choisirElement(".txt");

	ouvrirFichier(s, F);
	Probleme p;
	lectureFichier(F, p);
	p.afficher();
	Etat e = p.resolutionProbleme(p.constructionEtatInitial());
	if (e.etat == echec)
	{
		std::cout << "oh oh ";
	}
	if (e.etat == succes)
	{
		std::cout << "CONGRATULATIONS" << std::endl;
		p.afficher();
	}
	fermerFichier(F);
	

    return 0;

}
