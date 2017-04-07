#include "L3-AD-F5-operationFichier.h"

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
	if (F.is_open())
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
bool ouvrirNouveauFichier(const std::string chemin, std::ofstream & F)
{
	DEBUG_MSG("[DEBUG] Ouverture du fichier " << chemin);
	F.open(chemin);
	if (F.is_open())
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
	if (F.is_open())
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

bool fermerNouveauFichier(std::ofstream & F)
{
	DEBUG_MSG("[DEBUG]Fermeture du fichier ");
	F.close();
	if (F.is_open())
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
