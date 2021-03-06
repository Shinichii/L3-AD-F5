/*
	@Auteur : Aurelien DENIS
	@Groupe : F5
*/

#include "L3-AD-F5-parser.h"


std::vector<std::string> importerFichier(std::fstream & F)
{
	std::string d;
	std::vector<std::string> imported;
	while (F.peek() != EOF)
	{
		std::getline(F, d);
		if (d.find_first_not_of(' ') != std::string::npos) // Si ce n'est pas une ligne vide
		{
			std::cout << d << std::endl;
			imported.push_back(d);
		}
	}
	return std::vector<std::string>(imported);
}

bool sauvegarderDansFichier(std::vector<std::string> vect, std::string nomFichier)
{
	std::fstream F;
	F.open("L3-AD-F5-" + nomFichier + ".txt", std::ios::out);
	if (!F.is_open())
	{
		std::cout << "[ERREUR] Le fichier ne peut etre cree" << std::endl;
		exit(EXIT_FAILURE);
	}
	for (std::vector<std::string>::iterator it = vect.begin(); it != vect.end(); it++)
	{
		F << *it << std::endl;
	}
	fermerFichier(F);

	return false;
}

//Lecture du fichier selon le modele du prof.
void lectureFichier(std::fstream & F, Probleme &p)
{
	if (!F.is_open())
	{
		std::cout << "[ERREUR] : Le fichier n'a pas pu etre ouvert !" << std::endl;
		std::cout << "Le programme va desormais quitter";
		exit(EXIT_FAILURE);
	}
	std::vector<std::string> lignes = importerFichier(F);
	std::vector<std::string>::iterator it = lignes.begin(); //Les lignes sont stockees de maniere contigues;
	
	it = traitementVariables(it, p);
	traitementContraintes(it, p);
}

std::vector<std::string>::iterator traitementVariables(std::vector<std::string>::iterator it, Probleme & p)
{
	int nbVariables = std::stoi(*it);
	for (int i = 0; i < nbVariables; i++)
	{
		it++;
		std::string domaineVariable = *it;
		char c = ' ';
		int nomVariable = 0;
		std::vector<int> domaineVariableTraduit;
		std::string bufferNomVariable;
		bufferNomVariable += domaineVariable[0];
		int k = 1;
		while(domaineVariable[k] != ' '){
			bufferNomVariable += domaineVariable[k];
			k++;
		}
		nomVariable = std::stoi(bufferNomVariable);
		do
		{
			std::string buffer;
			k++;
			c = domaineVariable[k];
			if (c != ' ' && c != '\n' && k < domaineVariable.length())
			{
				do
				{
					buffer += c;
					k++;
					c = domaineVariable[k];
				} while (c != ' ' && k < domaineVariable.length());
				domaineVariableTraduit.push_back(std::stoi(buffer));
			}
			else
			{
				domaineVariableTraduit.push_back(c - '0');
			}
		} while (k < domaineVariable.length());
		p.ajouterVariable(nomVariable, domaineVariableTraduit);
	}
	return ++it;
}

void traitementContraintes(std::vector<std::string>::iterator it, Probleme & p)
{
	while (*it != "-1")
	{
		std::string ligne = *it;
		char c = ligne[0];
		std::string code;
		code += (c);
		int i = 1;
		while (ligne[i] != ' ' && i < ligne.length())
		{
			code += ligne[i];
			i++;
		}
		Contrainte *nouvelleContrainte = p.ajouterContrainte(std::stoi(code));
		if (nouvelleContrainte != NULL)
		{
			ContrainteSeuil* casted = (ContrainteSeuil*)nouvelleContrainte;
			if (std::stoi(code) >= CONTRAINTE_SOMME_EXACTE && std::stoi(code) <= CONTRAINTE_SOMME_PONDEREE)
			{
				std::string tmp;
				while (ligne[i] == ' ' && i < ligne.length())
				{
					i++;
				}
				while (ligne[i] != ' ' && i < ligne.length())
				{
					tmp += ligne[i];
					i++;
				}
				casted->setSeuil(std::stoi(tmp));
			}
			if (std::stoi(code) == CONTRAINTE_SOMME_PONDEREE)
			{
				ContrainteSommePonderee* casted = (ContrainteSommePonderee*)nouvelleContrainte;
				bool ponderation = true;
				while (i < ligne.length())
				{
					std::string tmp;
					c = ligne[i];
					while (c != ' ' && c != '\n' && c != '\0' && i < ligne.length())
					{
						tmp += c;
						i++;
						c = ligne[i];
					}
					if (tmp != "")
					{
						if (ponderation)
						{
							casted->ajouterPonderationVariable(std::stoi(tmp));
							ponderation = false;
						}
						else
						{
							casted->ajouterVariable(p.chercherVariable(std::stoi(tmp)));
							ponderation = true;
						}
					}
					i++;
				}
			}
			while (i < ligne.length())
			{
				std::string tmp;
				c = ligne[i];
				while (c != ' ' && c != '\n' && c != '\0' && c != '-' && i < ligne.length())
				{
					tmp += c;
					i++;
					c = ligne[i];
				}
				if (tmp != "")
				{
					nouvelleContrainte->ajouterVariable(p.chercherVariable(std::stoi(tmp)));
				}
				if (c == '-')
				{
					i = ligne.length();
				}
				i++;
			}
		}
		it++;
	}
}

