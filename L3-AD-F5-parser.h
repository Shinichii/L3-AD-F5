#pragma once 
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
#include "L3-AD-F5-Probleme.h"
#include "L3-AD-F5-operationFichier.h"

std::vector<std::string> importerFichier(std::fstream &F);
bool sauvegarderDansFichier(std::vector<std::string> vect, std::string nomFichier);

void lectureFichier(std::fstream &F, Probleme &p);
std::vector<std::string>::iterator traitementVariables(std::vector<std::string>::iterator it, Probleme &p);
void traitementContraintes(std::vector<std::string>::iterator it, Probleme &p);