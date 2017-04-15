#pragma once
/*
	@Auteur : Aurelien DENIS
	@Groupe : F5
*/

#include <iostream>
#include <string>
#include <experimental/filesystem>
#include <vector>
using namespace std;

#define PATH_PAR_DEFAUT "D:\\AideDecision\\representation"
namespace fs = std::experimental::filesystem;

bool extensionValide(string s, string extension);

void recupererElements(vector<string>& listeFichiers, string extension);

string choisirElement(string extension);

