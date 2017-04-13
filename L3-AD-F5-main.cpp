#include <iostream>
using namespace std;


#include "L3-AD-F5-parser.h"
#include "L3-AD-F5-file_Finder.h"
#include <list>
#include <vector>
#include "L3-AD-F5-Probleme.h"


int main() {
	bool loop = true;
	char reponse = 'n';
	while (loop)
	{
		string s;
		std::vector<std::string> vc;
		std::fstream F;
		s = choisirElement(".txt");

		ouvrirFichier(s, F);
		Probleme p;
		lectureFichier(F, p);
		p.afficher();

		p.resoudreProbleme();

		fermerFichier(F);

		std::cout << "Voulez-vous continuer ? (O/N)" << std::endl;
		do
		{
			reponse = 'K';
			std::cin >> reponse;
		} while (cin.bad() && reponse != 'O' && reponse != 'o' && reponse != 'n' && reponse != 'N');
		if (reponse == 'N' || reponse == 'n')
		{
			loop = false;
		}
	}
    return 0;

}
