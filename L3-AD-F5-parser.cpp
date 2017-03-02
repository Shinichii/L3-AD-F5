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
bool openFile(const std::string chemin, std::ifstream &F)
{
	DEBUG_MSG("[DEBUG] Ouverture du fichier " << chemin);
	std::ifstream F(chemin);
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
bool closeFile(const std::string chemin, std::ifstream F)
{
	DEBUG_MSG("[DEBUG]Fermeture du fichier " << chemin);
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
