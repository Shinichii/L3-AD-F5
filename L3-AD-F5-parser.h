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

bool ouvrirFichier(const std::string chemin, std::fstream &F);
bool fermerFichier(std::fstream &F);
std::vector<std::string> importerFichier(std::fstream &F);
bool sauvegarderDansFichier(std::vector<std::string> vect, std::string nomFichier);