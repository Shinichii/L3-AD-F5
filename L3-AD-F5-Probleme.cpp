#include "L3-AD-F5-Probleme.h"

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
//------------------------------------------  Constructeur    ----------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------

Probleme::Probleme()
{  
}

Statistiques Probleme::getStatistiques() 
{
	return this->stats;
}



//----------------------------------------------------------------------------------------------------------------------
//------------------------------------------  Affichage    -------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------

void Probleme::afficher()
{
	std::cout << "===========[VARIABLES]===========" << std::endl;
	for (Variable* variable : variables)
	{
		std::cout << *variable;
	}
	std::cout << "===========[CONTRAINTES]===========" << std::endl;
	for (int i = 0; i < contraintes.size(); i++)
	{
		std::cout << "Contrainte n° " << i + 1 << std::endl;
		std::cout << *(contraintes.at(i)) << std::endl;
	}

}

void Probleme::ajouterVariable(int identificateur, std::vector<int> domaine)
{
	variables.push_back(new Variable(identificateur, domaine));
}

Variable * Probleme::chercherVariable(int nom)
{
	for (std::vector<Variable*>::iterator it = variables.begin(); it != variables.end(); it++)
	{
		if ((*it)->getNom() == nom)
		{
			return (*it);
		}
	}
	return nullptr;
}

Contrainte* Probleme::ajouterContrainte(int typeContrainte)
{
	Contrainte* c = NULL;
	switch (typeContrainte) {
	case CONTRAINTE_EGALITE:
		c = new ContrainteEgalite();
		contraintes.push_back(c);
		break;
	case CONTRAINTE_DIFFERENTE:
		c = new ContrainteInegalite();
		contraintes.push_back(c);
		break;
	case CONTRAINTE_INFERIEURE:
		c = new ContrainteInferieure();
		contraintes.push_back(c);
		break;
	case CONTRAINTE_SUPERIEURE:
		c = new ContrainteSuperieure();
		contraintes.push_back(c);
		break;
	case CONTRAINTE_SOMME_EXACTE:
		c = new ContrainteSommeExacte();
		contraintes.push_back(c);
		break;
	case CONTRAINTE_SOMME_INFERIEURE:
		c = new ContrainteSommeInferieure();
		contraintes.push_back(c);
		break;
	case CONTRAINTE_SOMME_SUPERIEURE:
		c = new ContrainteSommeSuperieure();
		contraintes.push_back(c);
		break;
	case CONTRAINTE_INFERIEURE_EGALE:
		c = new ContrainteInferieureEgale();
		contraintes.push_back(c);
		break;
	case CONTRAINTE_SUPERIEURE_EGALE:
		c = new ContrainteSuperieureEgale();
		contraintes.push_back(c);
		break;
	case CONTRAINTE_SOMME_INFERIEURE_EGALE:
		c = new ContrainteSommeInferieureEgale();
		contraintes.push_back(c);
		break;
	case CONTRAINTE_SOMME_SUPERIEURE_EGALE:
		c = new ContrainteSommeSuperieureEgale();
		contraintes.push_back(c);
		break;
	case CONTRAINTE_SOMME_PONDEREE:
		c = new ContrainteSommePonderee();
		contraintes.push_back(c);
		break;
	default:
		std::cout << "[ERREUR] Code Contrainte non reconnue" << std::endl;
	}
	return c;
}
/*
Fonction	: resoudreProbleme
Parametre	: Aucun
Renvoie		: Rien
Description : Fonction IHM qui permet a l'utilisateur de choisir la facon de resoudre le probleme
Une fois la resolution terminee, la fonction lance la sauvegarde des donnees.
*/
void Probleme::resoudreProbleme()
{
	int choixUtilisateur;
	std::cout << "Choisissez votre methode de resolution : " << std::endl;
	std::cout << "[1] : Resolution par recherche en profondeur (methode naive)"<<std::endl;
	std::cout << "[2] : Resolution avec reduction des domaines de valeurs (RDV)" << std::endl;
	std::cout << "[3] : Resolution avec RDV en choississant la variable la plus contrainte" << std::endl;
	std::cout << "[4] : Resolution avec RDV en choississant la variable la moins contrainte" << std::endl;
	std::cout << "[5] : Resolution avec RDV en choississant la variable la plus contraignante" << std::endl;
	std::cout << "[6] : Resolution avec RDV en choississant la variable la moins contraignante" << std::endl;
	while (!(cin >> choixUtilisateur) || choixUtilisateur < 1 || choixUtilisateur > 6)
	{
		if (cin.fail())
		{
			std::cout << "Erreur de saisie, veuillez recommencer" << std::endl;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	Etat e;
	switch (choixUtilisateur)
	{
	case 1:
		stats.demarrerTimer();
		e = resolutionProblemeRechercheProfondeurDAbord(constructionEtatInitial());
		stats.terminerTimer();
		if (e.etat == echec)
		{
			std::cout << "Pas de solution trouvee" << std::endl;
			sauverResultat(false, "Recherche en Profondeur d'abord");
		}
		if (e.etat == succes)
		{
			afficherSolution();
			sauverResultat(true, "Recherche en Profondeur d'abord");
		}
		break;
	case 2:
		stats.demarrerTimer();
		e = resolutionProblemeReductionValeur(constructionEtatInitialReductionDomaineValeurs());
		stats.terminerTimer();
		if (e.etat == echec)
		{
			std::cout << "Pas de solution trouvee" << std::endl;
			sauverResultat(false, "Reduction des domaines de valeurs");
		}
		if (e.etat == succes)
		{
			afficherSolution();
			sauverResultat(true, "Reduction des domaines de valeurs");
		}
		break;
	case 3:
		stats.demarrerTimer();
		e = resolutionProblemeVariablePlusContrainte(constructionEtatInitialReductionDomaineValeurs());
		stats.terminerTimer();
		if (e.etat == echec)
		{
			std::cout << "Pas de solution trouvee" << std::endl;
			sauverResultat(false, "Reduction des domaines de valeurs en choisisant la variable la plus contrainte");
		}
		if (e.etat == succes)
		{
			afficherSolution();
			sauverResultat(true, "Reduction des domaines de valeurs en choisissant la variable la plus contrainte");
		}
		break;
	case 4:
		stats.demarrerTimer();
		e = resolutionProblemeVariableMoinsContrainte(constructionEtatInitialReductionDomaineValeurs());
		stats.terminerTimer();
		if (e.etat == echec)
		{
			std::cout << "Pas de solution trouvee" << std::endl;
			sauverResultat(false, "Reduction des domaines de valeurs en choisisant la variable la moins contrainte");
		}
		if (e.etat == succes)
		{
			afficherSolution();
			sauverResultat(true, "Reduction des domaines de valeurs en choisissant la variable la moins contrainte");
		}
		break;
	case 5:
		stats.demarrerTimer();
		e = resolutionProblemeVariableLaPlusContraignante(constructionEtatInitialReductionDomaineValeurs());
		stats.terminerTimer();
		if (e.etat == echec)
		{
			std::cout << "Pas de solution trouvee" << std::endl;
			sauverResultat(false, "Reduction des domaines de valeurs en choisissant la variable la plus contraignante");
		}
		if (e.etat == succes)
		{
			afficherSolution();
			sauverResultat(true, "Reduction des domaines de valeurs en choisissant la variable la plus contraignante");
		}
		break;
	case 6:
		stats.demarrerTimer();
		e = resolutionProblemeVariableLaMoinsContraignante(constructionEtatInitialReductionDomaineValeurs());
		stats.terminerTimer();
		if (e.etat == echec)
		{
			std::cout << "Pas de solution trouvee" << std::endl;
			sauverResultat(false, "Reduction des domaines de valeurs en choisissant la variable la moins contraignante");
		}
		if (e.etat == succes)
		{
			afficherSolution();
			sauverResultat(true, "Reduction des domaines de valeurs en choisissant la variable la moins contraignante");
		}
		break;
	default:
		std::cout << "Erreur dans la saisie";
			return;
	}
	return;
}
/*
Fonction	: constructionEtatInitial
Parametre	: Aucun
Renvoie		: L'etat de base e
Description : Cette fonction cree un premier etat pour la recherche de solution
Il cree l'ensemble XA des valeurs assignees pour la resolution du probleme.
*/
Etat Probleme::constructionEtatInitial()
{
	Etat e;
	for (Variable* variable : variables)
	{
		if (variable->getValeur() != VALEUR_NON_DEFINIE)
		{
			e.variablesAssignees.push_back(variable);
		}
	}
	e.etat = indetermine;
	return Etat(e);
}
/*
Fonction	: constructionEtatInitialReductionDomaineValeurs
Parametre	: Aucun
Renvoie		: L'etat de base e
Description : Cette fonction cree un premier etat pour la recherche de solution avec reduction des domaines de valeurs
Il cree l'ensemble XA des valeurs assignees pour la resolution du probleme et fait une premiere reduction de valeurs.
*/
Etat Probleme::constructionEtatInitialReductionDomaineValeurs()
{
	Etat e = this->constructionEtatInitial();
	for (Variable* var : e.variablesAssignees)
	{
		this->reductionDomaineValeurs(var);
	}
	e.variablesAssignees.clear();
	for (Variable* var : this->variables)
	{
		if (var->getDomaine().size() == 1)
		{
			var->setValeur(var->getDomaine().at(0));
			e.variablesAssignees.push_back(var);
		}
	}
	return Etat(e);
}
/*
Fonction	: resolutionProblemeRechercheProfondeurDAbord
Parametre	: L'etat initial e
Renvoie		: L'etat e avec e.etat = succes si une solution a ete trouvee, e.etat = echec sinon
Description : Cet algorithme implemente la resolution du probleme par la methode naive
Cette methode est plus longue a l'execution que les autres et ne devrait etre utilisee que pour souligner cet aspect.
On deduit de l'ensemble variableAssignees les variables non assignees 
Si l'ensemble est vide c'est qu'on a atteint une feuille de l'arbre, que toutes les valeurs sont assignees et qu'on a donc une solution
De ce fait on renvoie succes.
Sinon on prend la premiere variable non assignee
Ensuite pour chaque valeur de son domaine on assigne a la variable cette valeur
Puis on verifie si ce choix est consistant avec les contraintes
Si c'est le cas on fait un appel recursif de la fonction avec cette variable dans l'ensemble assigne
Si la valeur renvoyee est succes alors on remonte la valeur dans les appels recursifs
A la fin si aucune solution n'a ete deduite on remet la variable a sa valeur initiale (NON_ASSIGNEE) et on renvoie echec
*/
Etat Probleme::resolutionProblemeRechercheProfondeurDAbord(Etat e)
{
	std::vector<Variable*> nonAssignees = fusionExclusive(this->variables, e.variablesAssignees);
	if (nonAssignees.size() == 0)
	{
		e.etat = succes;
		return e;
	}
	std::cout << "Variables non assignees : " << nonAssignees.size() << std::endl;
	Variable *variable = nonAssignees.at(0);
	std::vector<int> domaine = variable->getDomaine();
		for (int i = 0; i < domaine.size(); i++)
		{
			std::cout << "[ " << variable->getNom() << " ]" << " = " << "[ "<< domaine.at(i) << " ]" << std::endl;
			int valeur = domaine.at(i);
			variable->setValeur(valeur);
			if (this->estConsistant())
			{
				Etat e2 = e;
				e2.etat = indetermine;
				e2.variablesAssignees.push_back(variable);
				stats.incrementerNb_Noeuds();
				e2 = resolutionProblemeRechercheProfondeurDAbord(e2);
				if (e2.etat == succes)
				{
					return e2;
				}
			}
		}
		variable->remettreValeursInitiales();
		e.etat = echec;
		return e;
}
/*
Fonction	: reductionDomaineValeurs
Parametre	: Variable assignee v
Renvoie		: Booleen vrai ou faux qui indique si la reduction des domaines laisse la possibilite d'une solution
Description	: La fonction verifie pour chaque contrainte si elle contient la variable, si c'est le cas
elle appelle la methode de reduction des domaines de la contrainte et garde son resulat en memoire dans la variable change.
A la fin du parcours des contraintes elle renverra change.
*/
bool Probleme::reductionDomaineValeurs(Variable * v)
{
	bool change = true;
	for (Contrainte* c : this->contraintes)
	{
		if (c->contient(v))
		{
			if (c->reduireDomaines(v) == false)
				change = false;
		}
	}
	return change;
}
/*
Fonction	: remettreDomaineValeurs
Parametre	: Variable v
Renvoie		: Rien
Description	: Fonction qui n'est plus utilisee
Elle etait censee a la base remettre la valeur de la variable v dans les domaines des variables qui avaient ete reduites.
*/
void Probleme::remettreDomaineValeurs(Variable * v)
{
	for (Contrainte* c : this->contraintes)
	{
		c->remettreDomaines(v);
	}
}

/*
Fonction	: resolutionProblemeReductionValeur
Parametre	: L'etat initial avec une premiere reduction des valeurs e
Renvoie		: L'etat e avec e.etat = succes si une solution a ete trouvee, e.etat = echec sinon
Description : Cet algorithme implemente la resolution du probleme par la methode de reduction des valeurs
On deduit de l'ensemble e.variableAssignees les variables non assignees
Si l'ensemble est vide c'est qu'on a atteint une feuille de l'arbre, que toutes les valeurs sont assignees et qu'on a donc une solution
De ce fait on renvoie succes.
Sinon on prend la premiere variable non assignee
Ensuite pour chaque valeur de son domaine on assigne a la variable cette valeur
Puis on verifie si ce choix est consistant avec les contraintes
Si c'est le cas on fait une reduction des domaines des variables avec la variable assignee en argument et on verifie que ce choix est possible
Si c'est le cas on procede a un appel recursif de la fonction avec cette variable dans l'ensemble assigne
Si la valeur renvoyee est succes alors on remonte la valeur dans les appels recursifs
Sinon on retablit les domaines avant l'appel et la reduction
A la fin si aucune solution n'a ete deduite on remet la variable a sa valeur initiale (NON_ASSIGNEE) et on renvoie echec
*/
Etat Probleme::resolutionProblemeReductionValeur(Etat e)
{
	std::vector<Variable*> nonAssignees = fusionExclusive(this->variables, e.variablesAssignees);
	std::cout << "Variables non assignees : " << nonAssignees.size() << std::endl;
	if (nonAssignees.size() == 0)
	{
		e.etat = succes;
		return e;
	}
	Variable* variable = nonAssignees.at(0);
	std::vector<int> domaineTemporaire = variable->getDomaine();
		for (int valeur : domaineTemporaire)
		{
			std::cout << "[ " << variable->getNom() << " ]" << " = " << "[ " << valeur << " ]" << std::endl;
			variable->setValeur(valeur);
			if (this->estConsistant())
			{
				stats.incrementerNb_Noeuds();
				Etat e2 = e;
				std::vector < std::vector<int>> domaines;
				e2.variablesAssignees.push_back(variable);
				for (Variable* var : nonAssignees)
				{
					domaines.push_back(var->getDomaine());
				}
				variable->reduireDomaineAUneValeur(variable->getValeur());
				bool resultatReduction = this->reductionDomaineValeurs(variable);
				if (resultatReduction == true)
				{
					e2 = this->resolutionProblemeReductionValeur(e2);
					if (e2.etat == succes)
					{
						return e2;
					}
					else
					{
						for (int i = 0; i < nonAssignees.size(); i++)
						{
							nonAssignees.at(i)->remettreDomaine(domaines.at(i));
						}
						domaines.clear();
					}
				}
				else
				{
					stats.incrementerNb_Elagages();
					stats.mettreAJourValeurProfondeurMaxElagage(nonAssignees.size());
					for (int i = 0; i < nonAssignees.size(); i++)
					{
						nonAssignees.at(i)->remettreDomaine(domaines.at(i));
					}
					variable->remettreValeursInitiales();
				}
			}
		}
	variable->remettreValeursInitiales();
	e.etat = echec;
	return Etat(e);
}
/*
Fonction	: resolutionProblemeReductionVariablePlusContrainte
Parametre	: L'etat initial avec une premiere reduction des valeurs e
Renvoie		: L'etat e avec e.etat = succes si une solution a ete trouvee, e.etat = echec sinon
Description : Cet algorithme implemente la resolution du probleme par la methode de reduction des valeurs avec une stratégie dans le choix des valeurs
On deduit de l'ensemble e.variableAssignees les variables non assignees
Si l'ensemble est vide c'est qu'on a atteint une feuille de l'arbre, que toutes les valeurs sont assignees et qu'on a donc une solution
De ce fait on renvoie succes.
Sinon on prend la variable la plus contrainte (renvoyee par chercherVariableLaPlusContrainte)
Ensuite pour chaque valeur de son domaine on assigne a la variable cette valeur
Puis on verifie si ce choix est consistant avec les contraintes
Si c'est le cas on fait une reduction des domaines des variables avec la variable assignee en argument et on verifie que ce choix est possible
Si c'est le cas on procede a un appel recursif de la fonction avec cette variable dans l'ensemble assigne
Si la valeur renvoyee est succes alors on remonte la valeur dans les appels recursifs
Sinon on retablit les domaines avant l'appel et la reduction
A la fin si aucune solution n'a ete deduite on remet la variable a sa valeur initiale (NON_ASSIGNEE) et on renvoie echec
*/
Etat Probleme::resolutionProblemeVariablePlusContrainte(Etat e)
{
	std::vector<Variable*> nonAssignees = fusionExclusive(this->variables, e.variablesAssignees);
	std::cout << "Variables non assignees : " << nonAssignees.size() << std::endl;
	if (nonAssignees.size() == 0)
	{
		e.etat = succes;
		return e;
	}
	Variable* variable = this->chercherVariableLaPlusContrainte(nonAssignees);
	std::vector<int> domaineTemporaire = variable->getDomaine();
	for (int valeur : domaineTemporaire)
	{
		std::cout << "[ " << variable->getNom() << " ]" << " = " << "[ " << valeur << " ]" << std::endl;
		variable->setValeur(valeur);
		if (this->estConsistant())
		{
			Etat e2 = e;
			std::vector < std::vector<int>> domaines;
			e2.variablesAssignees.push_back(variable);
			for (Variable* var : nonAssignees)
			{
				domaines.push_back(var->getDomaine());
			}
			variable->reduireDomaineAUneValeur(variable->getValeur());
			bool resultatReduction = this->reductionDomaineValeurs(variable);
			if (resultatReduction == true)
			{
				stats.incrementerNb_Noeuds();
				e2 = this->resolutionProblemeVariablePlusContrainte(e2);
				if (e2.etat == succes)
				{
					return e2;
				}
				else
				{
					for (int i = 0; i < nonAssignees.size(); i++)
					{
						nonAssignees.at(i)->remettreDomaine(domaines.at(i));
					}
					domaines.clear();
				}
			}
			else
			{
				stats.incrementerNb_Elagages();
				stats.mettreAJourValeurProfondeurMaxElagage(nonAssignees.size());
				for (int i = 0; i < nonAssignees.size(); i++)
				{
					nonAssignees.at(i)->remettreDomaine(domaines.at(i));
				}
				variable->remettreValeursInitiales();
			}
		}
	}
	variable->remettreValeursInitiales();
	e.etat = echec;
	return Etat(e);
}
/*
Fonction	: chercherVariableLaPlusContrainte
Parametre	: L'ensemble des variables non assignees 
Renvoie		: Pointeur sur la variable la plus contrainte
Description : Cette fonction prend le premier element de nonAssignees comme variable la plus contrainte
Pour chaque element suivant il verifie si la taille du domaine est moins grande que celle de la variable la plus contrainte actuelle
Si c'est le cas alors variableLaPlusContrainte pointe desormais sur cet element
A la fin la fonction retourne variableLaPlusContrainte
*/
Variable * Probleme::chercherVariableLaPlusContrainte(std::vector<Variable*> nonAssignees)
{
	if (nonAssignees.size() <= 0)
	{
		DEBUG_MSG("[ERREUR] : Vecteur nonAssignees n'a pas d'element");
		return NULL;
	}
	Variable* variableLaPlusContrainte = nonAssignees.at(0);
	for (int i = 1; i < nonAssignees.size(); i++)
	{
		if (variableLaPlusContrainte->getDomaine().size() > nonAssignees.at(i)->getDomaine().size())
		{
			variableLaPlusContrainte = nonAssignees.at(i);
		}
	}
	return variableLaPlusContrainte;
}
/*
Fonction	: resolutionProblemeReductionVariableMoinsContrainte
Parametre	: L'etat initial avec une premiere reduction des valeurs e
Renvoie		: L'etat e avec e.etat = succes si une solution a ete trouvee, e.etat = echec sinon
Description : Cet algorithme implemente la resolution du probleme par la methode de reduction des valeurs avec une stratégie dans le choix des variables de la variable la moins contrainte
On deduit de l'ensemble e.variableAssignees les variables non assignees
Si l'ensemble est vide c'est qu'on a atteint une feuille de l'arbre, que toutes les valeurs sont assignees et qu'on a donc une solution
De ce fait on renvoie succes.
Sinon on prend la variable la moins contrainte (renvoyee par chercherVariableLaMoinsContrainte)
Ensuite pour chaque valeur de son domaine on assigne a la variable cette valeur
Puis on verifie si ce choix est consistant avec les contraintes
Si c'est le cas on fait une reduction des domaines des variables avec la variable assignee en argument et on verifie que ce choix est possible
Si c'est le cas on procede a un appel recursif de la fonction avec cette variable dans l'ensemble assigne
Si la valeur renvoyee est succes alors on remonte la valeur dans les appels recursifs
Sinon on retablit les domaines avant l'appel et la reduction
A la fin si aucune solution n'a ete deduite on remet la variable a sa valeur initiale (NON_ASSIGNEE) et on renvoie echec
*/
Etat Probleme::resolutionProblemeVariableMoinsContrainte(Etat e)
{
	std::vector<Variable*> nonAssignees = fusionExclusive(this->variables, e.variablesAssignees);
	std::cout << "Variables non assignees : " << nonAssignees.size() << std::endl;
	if (nonAssignees.size() == 0)
	{
		e.etat = succes;
		return e;
	}
	Variable* variable = this->chercherVariableLaMoinsContrainte(nonAssignees);
	std::vector<int> domaineTemporaire = variable->getDomaine();
	for (int valeur : domaineTemporaire)
	{
		std::cout << "[ " << variable->getNom() << " ]" << " = " << "[ " << valeur << " ]" << std::endl;
		variable->setValeur(valeur);
		if (this->estConsistant())
		{
			Etat e2 = e;
			std::vector < std::vector<int>> domaines;
			e2.variablesAssignees.push_back(variable);
			for (Variable* var : nonAssignees)
			{
				domaines.push_back(var->getDomaine());
			}
			variable->reduireDomaineAUneValeur(variable->getValeur());
			bool resultatReduction = this->reductionDomaineValeurs(variable);
			if (resultatReduction == true)
			{
				stats.incrementerNb_Noeuds();
				e2 = this->resolutionProblemeVariableMoinsContrainte(e2);
				if (e2.etat == succes)
				{
					return e2;
				}
				else
				{
					for (int i = 0; i < nonAssignees.size(); i++)
					{
						nonAssignees.at(i)->remettreDomaine(domaines.at(i));
					}
					domaines.clear();
				}
			}
			else
			{
				stats.incrementerNb_Elagages();
				stats.mettreAJourValeurProfondeurMaxElagage(nonAssignees.size());
				for (int i = 0; i < nonAssignees.size(); i++)
				{
					nonAssignees.at(i)->remettreDomaine(domaines.at(i));
				}
				variable->remettreValeursInitiales();
			}
		}
	}
	variable->remettreValeursInitiales();
	e.etat = echec;
	return Etat(e);
}
/*
Fonction	: chercherVariableLaMoinsContrainte
Parametre	: L'ensemble des variables non assignees
Renvoie		: Pointeur sur la variable la moins contrainte
Description : Cette fonction prend le premier element de nonAssignees comme variable la plus contrainte
Pour chaque element suivant il verifie si la taille du domaine est plus grande que celle de la variable la moins contrainte actuelle
Si c'est le cas alors variableLaMoinsContrainte pointe desormais sur cet element
A la fin la fonction retourne variableLaMoinsContrainte
*/
Variable * Probleme::chercherVariableLaMoinsContrainte(std::vector<Variable*> nonAssignees)
{
	if (nonAssignees.size() <= 0)
	{
		DEBUG_MSG("[ERREUR] : Vecteur nonAssignees n'a pas d'element");
		return NULL;
	}
	Variable* variableLaMoinsContrainte = nonAssignees.at(0);
	for (int i = 1; i < nonAssignees.size(); i++)
	{
		if (variableLaMoinsContrainte->getDomaine().size() > nonAssignees.at(i)->getDomaine().size())
		{
			variableLaMoinsContrainte = nonAssignees.at(i);
		}
	}
	return variableLaMoinsContrainte;
}
/*
Fonction	: resolutionProblemeReductionVariablePlusContraignante
Parametre	: L'etat initial avec une premiere reduction des valeurs e
Renvoie		: L'etat e avec e.etat = succes si une solution a ete trouvee, e.etat = echec sinon
Description : Cet algorithme implemente la resolution du probleme par la methode de reduction des valeurs avec une stratégie dans le choix des variables de la variable la plus contraignante
On deduit de l'ensemble e.variableAssignees les variables non assignees
Si l'ensemble est vide c'est qu'on a atteint une feuille de l'arbre, que toutes les valeurs sont assignees et qu'on a donc une solution
De ce fait on renvoie succes.
Sinon on prend la variable la plus contrainte (renvoyee par chercherVariableLaPlusContraignante)
Ensuite pour chaque valeur de son domaine on assigne a la variable cette valeur
Puis on verifie si ce choix est consistant avec les contraintes
Si c'est le cas on fait une reduction des domaines des variables avec la variable assignee en argument et on verifie que ce choix est possible
Si c'est le cas on procede a un appel recursif de la fonction avec cette variable dans l'ensemble assigne
Si la valeur renvoyee est succes alors on remonte la valeur dans les appels recursifs
Sinon on retablit les domaines avant l'appel et la reduction
A la fin si aucune solution n'a ete deduite on remet la variable a sa valeur initiale (NON_ASSIGNEE) et on renvoie echec
*/
Etat Probleme::resolutionProblemeVariableLaPlusContraignante(Etat e)
{
	std::vector<Variable*> nonAssignees = fusionExclusive(this->variables, e.variablesAssignees);
	std::cout << "Variables non assignees : " << nonAssignees.size() << std::endl;
	if (nonAssignees.size() == 0)
	{
		e.etat = succes;
		return e;
	}
	Variable* variable = this->chercherVariableLaPlusContraignante(nonAssignees);
	std::vector<int> domaineTemporaire = variable->getDomaine();
	for (int valeur : domaineTemporaire)
	{
		std::cout << "[ " << variable->getNom() << " ]" << " = " << "[ " << valeur << " ]" << std::endl;
		variable->setValeur(valeur);
		if (this->estConsistant())
		{
			Etat e2 = e;
			std::vector < std::vector<int>> domaines;
			e2.variablesAssignees.push_back(variable);
			for (Variable* var : nonAssignees)
			{
				domaines.push_back(var->getDomaine());
			}
			variable->reduireDomaineAUneValeur(variable->getValeur());
			bool resultatReduction = this->reductionDomaineValeurs(variable);
			if (resultatReduction == true)
			{
				stats.incrementerNb_Noeuds();
				e2 = this->resolutionProblemeVariableLaPlusContraignante(e2);
				if (e2.etat == succes)
				{
					return e2;
				}
				else
				{
					for (int i = 0; i < nonAssignees.size(); i++)
					{
						nonAssignees.at(i)->remettreDomaine(domaines.at(i));
					}
					domaines.clear();
				}
			}
			else
			{
				stats.incrementerNb_Elagages();
				stats.mettreAJourValeurProfondeurMaxElagage(nonAssignees.size());
				for (int i = 0; i < nonAssignees.size(); i++)
				{
					nonAssignees.at(i)->remettreDomaine(domaines.at(i));
				}
				variable->remettreValeursInitiales();
			}
		}
	}
	variable->remettreValeursInitiales();
	e.etat = echec;
	return Etat(e);
}
/*
Fonction	: chercherVariableLaPlusContraignante
Parametre	: L'ensemble des variables non assignees
Renvoie		: Pointeur sur la variable la plus contraignante
Description : On initialise un tableau d'entier correspondant au nombre de fois que la variable en i de nonAssignees est presente dans une contrainte ayant au moins une variable sans valeur assignee
On parcourt toutes les variables
Pour chaque variable on parcourt toutes les contraintes
Si elles contiennent la variable et que le nombre de variables non assignees est superieure a 0 on incremente un compteur
Apres avoir parcouru les contraintes on ajoute cette valeur au tableau d'entiers
A la fin de ce parcours on obtient un tableau et on renvoie la variable a la position de l'element maximum du tableau d'entier
*/
Variable * Probleme::chercherVariableLaPlusContraignante(std::vector<Variable*> nonAssignees)
{
	std::vector<int> coeffContraignante;
	for (int i = 0; i < nonAssignees.size(); i++)
	{
		Variable* var = nonAssignees.at(i);
		int compteurContraignante = 0;
		for (Contrainte* c : this->contraintes)
		{
			if (c->contient(var) && c->getNbVariablesNonAssignees() > 0)
			{
				compteurContraignante++;
			}
		}
		coeffContraignante.push_back(compteurContraignante);
	}
	return nonAssignees.at(std::distance(coeffContraignante.begin(),
		std::max_element(coeffContraignante.begin(), coeffContraignante.end())));
}
/*
Fonction	: resolutionProblemeReductionVariableMoinsContraignante
Parametre	: L'etat initial avec une premiere reduction des valeurs e
Renvoie		: L'etat e avec e.etat = succes si une solution a ete trouvee, e.etat = echec sinon
Description : Cet algorithme implemente la resolution du probleme par la methode de reduction des valeurs avec une stratégie dans le choix des variables de la variable la moins contraignante
On deduit de l'ensemble e.variableAssignees les variables non assignees
Si l'ensemble est vide c'est qu'on a atteint une feuille de l'arbre, que toutes les valeurs sont assignees et qu'on a donc une solution
De ce fait on renvoie succes.
Sinon on prend la variable la moins contraignante (renvoyee par chercherVariableLaMoinsContraignante)
Ensuite pour chaque valeur de son domaine on assigne a la variable cette valeur
Puis on verifie si ce choix est consistant avec les contraintes
Si c'est le cas on fait une reduction des domaines des variables avec la variable assignee en argument et on verifie que ce choix est possible
Si c'est le cas on procede a un appel recursif de la fonction avec cette variable dans l'ensemble assigne
Si la valeur renvoyee est succes alors on remonte la valeur dans les appels recursifs
Sinon on retablit les domaines avant l'appel et la reduction
A la fin si aucune solution n'a ete deduite on remet la variable a sa valeur initiale (NON_ASSIGNEE) et on renvoie echec
*/
Etat Probleme::resolutionProblemeVariableLaMoinsContraignante(Etat e)
{

	std::vector<Variable*> nonAssignees = fusionExclusive(this->variables, e.variablesAssignees);
	std::cout << "Variables non assignees : " << nonAssignees.size() << std::endl;
	if (nonAssignees.size() == 0)
	{
		e.etat = succes;
		return e;
	}
	Variable* variable = this->chercherVariableLaMoinsContraignante(nonAssignees);
	std::vector<int> domaineTemporaire = variable->getDomaine();
	for (int valeur : domaineTemporaire)
	{
		std::cout << "[ " << variable->getNom() << " ]" << " = " << "[ " << valeur << " ]" << std::endl;
		variable->setValeur(valeur);
		if (this->estConsistant())
		{
			Etat e2 = e;
			std::vector < std::vector<int>> domaines;
			e2.variablesAssignees.push_back(variable);
			for (Variable* var : nonAssignees)
			{
				domaines.push_back(var->getDomaine());
			}
			variable->reduireDomaineAUneValeur(variable->getValeur());
			bool resultatReduction = this->reductionDomaineValeurs(variable);
			if (resultatReduction == true)
			{
				stats.incrementerNb_Noeuds();
				e2 = this->resolutionProblemeVariableLaMoinsContraignante(e2);
				if (e2.etat == succes)
				{
					return e2;
				}
				else
				{
					for (int i = 0; i < nonAssignees.size(); i++)
					{
						nonAssignees.at(i)->remettreDomaine(domaines.at(i));
					}
					domaines.clear();
				}
			}
			else
			{
				stats.incrementerNb_Elagages();
				stats.mettreAJourValeurProfondeurMaxElagage(nonAssignees.size());
				for (int i = 0; i < nonAssignees.size(); i++)
				{
					nonAssignees.at(i)->remettreDomaine(domaines.at(i));
				}
				variable->remettreValeursInitiales();
			}
		}
	}
	variable->remettreValeursInitiales();
	e.etat = echec;
	return Etat(e);
}
/*
Fonction	: chercherVariableLaMoinsContraignante
Parametre	: L'ensemble des variables non assignees
Renvoie		: Pointeur sur la variable la moins contraignante
Description : On initialise un tableau d'entier correspondant au nombre de fois que la variable en i de nonAssignees est presente dans une contrainte ayant au moins une variable sans valeur assignee
On parcourt toutes les variables
Pour chaque variable on parcourt toutes les contraintes
Si elles contiennent la variable et que le nombre de variables non assignees est superieure a 0 on incremente un compteur
Apres avoir parcouru les contraintes on ajoute cette valeur au tableau d'entiers
A la fin de ce parcours on obtient un tableau et on renvoie la variable a la position de l'element minimum du tableau d'entier
*/

Variable * Probleme::chercherVariableLaMoinsContraignante(std::vector<Variable*> nonAssignees)
{
	std::vector<int> coeffContraignante;
	for (int i = 0; i < nonAssignees.size(); i++)
	{
		Variable* var = nonAssignees.at(i);
		int compteurContraignante = 0;
		for (Contrainte* c : this->contraintes)
		{
			if (c->contient(var) && c->getNbVariablesNonAssignees() > 0)
			{
				compteurContraignante++;
			}
		}
		coeffContraignante.push_back(compteurContraignante);
	}
	return nonAssignees.at(std::distance(coeffContraignante.begin(),
		std::min_element(coeffContraignante.begin(), coeffContraignante.end())));
}
/*
Fonction	: sauverResultat
Parametre	: Un booleen indiquant si la solution a ete trouvee, une chaine de caracteres indiquant la methode utilisee
Renvoie		: Rien
Description : Cette fonction sauve le resultat de la tentative de résolution du programme dans un fichier texte
Sont inscrits dans le fichier la methode de resolution utilisee, les domaines et valeurs initiales (s'il y en a) des variables
Ainsi que les contraintes du probleme
S'il y a une solution de trouvee, le programme ecrit les valeurs trouvees pour chaque variable
Sinon il indique qu'aucune solution n'a ete trouvee
Dans les deux cas la fonction finit par inscrire les statistiques de la resolution (Se referer a la classe Statistiques)
*/
void Probleme::sauverResultat(bool solutionTrouvee, std::string methodeUtilisee)
{
	char reponse;
	std::cout << "Voulez vous sauvegarder le resume dans un fichier texte ? (O/N)";
	do
	{
		reponse = 'K';
		std::cin >> reponse;
	} while (cin.bad() && reponse != 'O' && reponse != 'o' && reponse != 'n' && reponse != 'N');
	if (reponse != 'o' && reponse != 'O')
	{
		std::cout << "Le fichier ne sera pas sauvegarde." << std::endl;
		return;
	}
	std::string path;
	std::cout << "Entrer le nom du fichier pour sauvegarder" << std::endl;
	std::cin >> path;
	std::ofstream F;
	ouvrirNouveauFichier("./"+path+".txt", F);
	F << "[METHODE UTILISEE POUR LA RESOLUTION] : " << methodeUtilisee << std::endl;
	//Sauver domaines initiaux
	F << "===========[VARIABLES ETAT INITIAL]===========" << std::endl;
	for (Variable *var : variables)
	{
		F << "Variable n " << var->getNom() << std::endl << "Valeurs possibles : " << std::endl;
		for (int val : var->getDomaineInitial())
		{
			F << val << " ";
		}
		F << std::endl;
	}
	//Sauver contraintes
	F << "===========[CONTRAINTES]===========" << std::endl;
	for (int i = 0; i < contraintes.size(); i++)
	{
		F << "Contrainte n° " << i+1 << std::endl;
		F << *(contraintes.at(i))<<std::endl;
	}
	//SI SOLUTION : Indiquer solutions
	if (solutionTrouvee == true)
	{
		F << "===========[SOLUTION TROUVEE]===========" << std::endl;
		for (Variable *var : variables)
		{
			F << "Variable n°" << var->getNom() <<  " = " << var->getValeur() << std::endl;
		}
	}
	//Sinon dire pas de solution trouvee
	else
	{
		F << "Pas de solution trouvee." << std::endl;
	}
	//Afficher les stats
	F << stats;
	fermerNouveauFichier(F);
	std::cout << "[INFO] : Sauvegarde terminee ! Vous pouvez retrouver le resume de la resolution dans le fichier : " << "./" <<path << ".txt"; 

}
/*
Fonction	: estConsistant
Parametre	: Aucun
Renvoie		: Un booleen
Description : Cette fonction verifie que pour les valeurs assignees aux variables toutes les contraintes soient bien respectees
*/
bool Probleme::estConsistant()
{
	for (Contrainte* contrainte : this->contraintes)
	{
		if (!contrainte->contrainteRespectee())
		{
			return false;
		}
	}
	return true;
}
void Probleme::afficherSolution()
{
	std::cout << "===========[SOLUTION TROUVEE]===========" << std::endl;
	for (Variable *var : variables)
	{
		std::cout << "Variable n°" << var->getNom() << " = " << var->getValeur() << std::endl;
	}
}
/*
Fonction	: fusionExclusive
Parametre	: Deux std::vector<Variable*>, un qui contient l'ensemble de base, l'autre l'ensemble a exclure
Renvoie		: Le tableau variables \ aExclure
Description : Cette fonction recupere les valeurs de variables non presentes dans aExclure et les stocke dans un std::vector<Variable*>
fusionne qu'il renvoie a la fin
*/
std::vector<Variable*> fusionExclusive(std::vector<Variable*> variables, std::vector<Variable*> aExclure)
{
	std::vector<Variable*> fusionne;
	for (std::vector<Variable*>::iterator it = variables.begin(); it != variables.end(); it++)
	{
		//Si je trouve it dans aExclure je l'ajoute pas.
		if (std::find(aExclure.begin(), aExclure.end(), *it) == aExclure.end())
		{
			fusionne.push_back(*it);
		}
	}
	return std::vector<Variable*>(fusionne);
}
