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
<<<<<<< HEAD
	ouvrirFichier(s, F);
	vc = importerFichier(F);
	sauvegarderDansFichier(vc, "test");
	fermerFichier(F);
=======
	openFile(s, F);
	vc = importFile(F);
	saveToFile(vc, "test");
	closeFile(F);

>>>>>>> c05333bbf3ac3086f0f633b3e9f15a9a9a2eca8b
    return 0;

}
