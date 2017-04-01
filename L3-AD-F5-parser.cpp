/*
	@Auteur : Aurelien DENIS
	@Groupe : F5
*/

#include "L3-AD-F5-parser.h"
/*
	Fonction : ouvrirFichier
	Parametre: chemin
	Description : Cette fonction tente d'ouvrir le fichier passé en argument
	Elle renvoie ensuite une valeur booleenne pour indiquer si le fichier est bien ouvert
*/
bool ouvrirFichier(const std::string chemin, std::fstream &F)
{
	DEBUG_MSG("[DEBUG] Ouverture du fichier " << chemin);
	F.open(chemin);
	if(F.is_open())
	{
		DEBUG_MSG("[DEBUG] Succes !");
		return true;
	}
	else
	{
		DEBUG_MSG("[ERROR] Le fichier ne s'est pas ouvert !");
		return false;
	}
}
bool fermerFichier(std::fstream &F)
{
	DEBUG_MSG("[DEBUG]Fermeture du fichier ");
	F.close();
	if(F.is_open())
	{
		DEBUG_MSG("[ERROR] Le fichier ne s'est pas ferme correctement");
		return false;
	}
	else
	{
		DEBUG_MSG("[DEBUG] Le fichier s'est ferme avec succes");
		return true;
	}
}

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
	/*@ TO DO
		Creer un cas au cas où le fichier ne peut se creer 
	*/
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
		return;
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
		c = domaineVariable[0];
		int k = 0;
		nomVariable = c - '0';
		do
		{
			std::string buffer;
			k++;
			c = domaineVariable[k];
			if (c != ' ' && c != '\n')
			{
				do
				{
					buffer += c;
					k++;
					c = domaineVariable[k];
				} while (c != ' ' && k < domaineVariable.length());
				domaineVariableTraduit.push_back(std::stoi(buffer));
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
		int code = c - '0';
		int i = 1;
		Contrainte *nouvelleContrainte = p.ajouterContrainte(code);
		if (nouvelleContrainte != NULL)
		{
			ContrainteSeuil* casted = (ContrainteSeuil*)nouvelleContrainte;
			if (code > 3)
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
			while (i < ligne.length())
			{
				c = ligne[i];
				if (c != ' ' && c != '\n' && c != '\0' && c != '-')
				{
					nouvelleContrainte->ajouterVariable(p.chercherVariable(c - '0'));
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

