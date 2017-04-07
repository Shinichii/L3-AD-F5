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

Probleme::Probleme(string Nom_Probleme)//fonction de test
{
    nom_Probleme=Nom_Probleme;

}


//----------------------------------------------------------------------------------------------------------------------
//------------------------------------------  Affichage    -------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------

void Probleme::afficher()
{
	for (Variable* variable : variables)
	{
		std::cout << *variable;
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
		c = new ContrainteSommeSuperieureEgale();
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
		std::cout << "[INFO] Code Contrainte non reconnue" << std::endl;
	}
	return c;
}

void Probleme::resoudreProbleme()
{
	int choixUtilisateur;
	std::cout << "Choisissez votre methode de resolution : " << std::endl;
	std::cout << "[1] : Resolution par recherche en profondeur (methode naive)"<<std::endl;
	std::cout << "[2] : Resolution avec reduction des domaines de valeurs (RDV)" << std::endl;
	std::cout << "[3] : Resolution avec RDV en choississant la variable la plus contrainte" << std::endl;
	std::cout << "[4] : Resolution avec RDV en choississant la variable la plus contraignante" << std::endl;
	std::cout << "[5] : Resolution avec RDV en choississant la variable la moins contraignante" << std::endl;
	while (!(cin >> choixUtilisateur) || choixUtilisateur < 1 || choixUtilisateur > 5)
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
			sauverResultat(false, "Recherche en Profondeur d'abord");
		}
		if (e.etat == succes)
		{
			sauverResultat(true, "Recherche en Profondeur d'abord");
		}
		break;
	case 2:
		stats.demarrerTimer();
		e = resolutionProblemeReductionValeur(constructionEtatInitialReductionDomaineValeurs());
		stats.terminerTimer();
		if (e.etat == echec)
		{
			sauverResultat(false, "Reduction des domaines de valeurs");
		}
		if (e.etat == succes)
		{
			sauverResultat(true, "Reduction des domaines de valeurs");
		}
		break;
	case 3:
		stats.demarrerTimer();
		e = resolutionProblemeVariablePlusContrainte(constructionEtatInitialReductionDomaineValeurs());
		stats.terminerTimer();
		if (e.etat == echec)
		{
			sauverResultat(false, "Reduction des domaines de valeurs en choisisant la variable la plus contrainte");
		}
		if (e.etat == succes)
		{
			sauverResultat(true, "Reduction des domaines de valeurs en choisissant la variable la plus contrainte");
		}
		break;
	case 4:
		stats.demarrerTimer();
		e = resolutionProblemeVariableLaPlusContraignante(constructionEtatInitialReductionDomaineValeurs());
		stats.terminerTimer();
		if (e.etat == echec)
		{
			sauverResultat(false, "Reduction des domaines de valeurs en choisissant la variable la plus contraignante");
		}
		if (e.etat == succes)
		{
			sauverResultat(true, "Reduction des domaines de valeurs en choisissant la variable la plus contraignante");
		}
		break;
	case 5:
		stats.demarrerTimer();
		e = resolutionProblemeVariableLaMoinsContraignante(constructionEtatInitialReductionDomaineValeurs());
		stats.terminerTimer();
		if (e.etat == echec)
		{
			sauverResultat(false, "Reduction des domaines de valeurs en choisissant la variable la moins contraignante");
		}
		if (e.etat == succes)
		{
			sauverResultat(true, "Reduction des domaines de valeurs en choisissant la variable la moins contraignante");
		}
		break;
	default:
		std::cout << "Erreur dans la saisie";
			return;
	}
	return;
}

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

void Probleme::remettreDomaineValeurs(Variable * v)
{
	for (Contrainte* c : this->contraintes)
	{
		c->remettreDomaines(v);
	}
}

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

void Probleme::sauverResultat(bool solutionTrouvee, std::string methodeUtilisee)
{
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
}

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
