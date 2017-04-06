#pragma once

#include <iostream>
#include <fstream>
#include "L3-AD-F5-debug.h"

bool ouvrirFichier(const std::string chemin, std::fstream &F);
bool ouvrirNouveauFichier(const std::string chemin, std::ofstream &F);
bool fermerFichier(std::fstream &F);
bool fermerNouveauFichier(std::ofstream &F);