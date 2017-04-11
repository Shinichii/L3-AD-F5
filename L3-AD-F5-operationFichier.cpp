#include "L3-AD-F5-operationFichier.h"

/*
Fonction : ouvrirFichier
Parametre: chemin
Description : Cette fonction tente d'ouvrir en lecture le fichier passé en argument
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
/*
Fonction : ouvrirNouveauFichier
Parametre: chemin
Description : Cette fonction tente d'ouvrir le fichier passé en argument en écriture
Elle renvoie ensuite une valeur booleenne pour indiquer si le fichier est bien ouvert
*/
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
/*
Fonction : fermerFichier
Parametre: Le flux de lecture a fermer F
Description : Cette fonction tente de fermer le flux de lecture passé en argument
Elle renvoie ensuite une valeur booleenne pour indiquer si le flux a bien ete ferme
*/
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
/*
Fonction : fermerFichier
Parametre: Le flux d'ecriture a fermer F
Description : Cette fonction tente de fermer le flux d'ecriture passé en argument
Elle renvoie ensuite une valeur booleenne pour indiquer si le flux a bien ete ferme
*/
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
