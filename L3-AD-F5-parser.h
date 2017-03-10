 /*
	@Auteur : Aurélien DENIS
	@Groupe : F5
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
#include <string>
#include "L3-AD-F5-debug.h"

bool openFile(const std::string chemin, std::fstream &F);
bool closeFile(std::fstream &F);
std::vector<std::string> importFile(std::fstream &F);
bool saveToFile(std::vector<std::string> vect, std::string nomFichier);