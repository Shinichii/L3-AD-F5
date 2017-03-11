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
	openFile(s, F);
	vc = importFile(F);
	saveToFile(vc, "test");
	closeFile(F);

    return 0;

}
