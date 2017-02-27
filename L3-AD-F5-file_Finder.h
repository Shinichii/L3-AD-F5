/*
	@Auteur : Aurelien DENIS
	@Matiere : Aide a la decision
	@Groupe : F5
*/

#include <iostream>
#include <string>
#include <experimental/filesystem>
#include <vector>

using namespace std;

namespace fs = std::experimental::filesystem;

bool extensionValide(string s, string extension);

void fetchElements(vector<string>& listeFichiers, string extension);

string choisirElement(string extension);

