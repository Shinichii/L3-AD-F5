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
	//p.getStatistiques().demarrerTimer();
	//Etat e = p.resolutionProblemeReductionValeur(p.constructionEtatInitialReductionDomaineValeurs());
	p.resoudreProbleme();
	//p.getStatistiques().terminerTimer();
	//Etat e = p.resolutionProblemeRechercheProfondeurDAbord(p.constructionEtatInitial());

	fermerFichier(F);
	std::cout << "Sauvegarde terminee";
	std::cout << "test";
    return 0;

}
