/*
	@Auteur : Aurelien DENIS
	@Groupe : F5
*/

#include "L3-AD-F5-parser.h"
/*
	Fonction : openFile
	Parametre: chemin
	Description : Cette fonction tente d'ouvrir le fichier passé en argument
	Elle renvoie ensuite une valeur booleenne pour indiquer si le fichier est bien ouvert
*/
bool openFile(const std::string chemin, std::fstream &F)
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
bool closeFile(std::fstream &F)
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

std::vector<std::string> importFile(std::fstream & F)
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

bool saveToFile(std::vector<std::string> vect, std::string nomFichier)
{
	/*@ TO DO
		Creer un cas au cas où le fichier ne peut se creer 
	*/
	std::fstream F;
	F.open("L3-AD-F5-" + nomFichier + ".txt", std::ios::out);
	if (!F.is_open())
	{
		std::cout << "BUG";
	}
	for (std::vector<std::string>::iterator it = vect.begin(); it != vect.end(); it++)
	{
		F << *it << std::endl;
	}
	closeFile(F);

	return false;
}

