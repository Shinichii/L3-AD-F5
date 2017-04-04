#include "L3-AD-F5-Probleme.h"

#include <iostream>


using namespace std;

#include <vector>
#include <cstdlib>

//----------------------------------------------------------------------------------------------------------------------
//------------------------------------------  Constructeur    ----------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------

Probleme::Probleme()
{  // nb_variable= atoi(Utilitaire::parse(entrer[1])[0].c_str());

//  int longueur_declaration_variable=atoi(Utilitaire::parse(entrer[1])[1].c_str());//peut etre different de nb_variable


//---------------------------------------------- affectation des variables et de leur domaine ---------------------------
//    for(int i=2;i<longueur_declaration_variable+2;i++)        {  entrer_variable.emplace_back(entrer[i].c_str()); }

    //Variables=Variable(entrer_variable,nb_variable);

// ----------------------------------------------affectation des contraintes --------------------------------------------


//    for(int i=longueur_declaration_variable+2;i<entrer.size();i++)        {entrer_contrainte.emplace_back(entrer[i].c_str()); }

cout<<" fin probleme"<<endl;
}



//--------------------------------------------------------------------------------------------------------------
vector<string> Probleme::getFichier_brut() // temporaire pour les test en attendant
{
vector<string> retour;
    retour.emplace_back("8 dames");
    retour.emplace_back("8 3");
    retour.emplace_back("# X { L , C }");
    retour.emplace_back("L [ 1 , 9 ]");
    retour.emplace_back("C [ 1 , 9 ]");

    retour.emplace_back("Unique X");
    retour.emplace_back("L  i != j => L i != L j");
    retour.emplace_back("C  i != j => C i != C j");
    retour.emplace_back("i != j => { { L i , C i } , { L j , C j } , a [ 1 , 8 ] } => X { L i , J i } != X { L j - a , C j - a }");
    retour.emplace_back("i != j => { { L i , C i } , { L j , C j } , a [ 1 , 8 ] } => X { L i , J i } != X { L j - a , C j + a }");
    retour.emplace_back("i != j => { { L i , C i } , { L j , C j } , a [ 1 , 8 ] } => X { L i , J i } != X { L j + a , C j + a }");
    retour.emplace_back("i != j => { { L i , C i } , { L j , C j } , a [ 1 , 8 ] } => X { L i , J i } != X { L j + a , C j - a }");

    return retour;
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
	case CONTRAINTE_INFERIEURE_EGALE:
		c = new ContrainteInferieure();
		contraintes.push_back(c);
		break;
	case CONTRAINTE_SUPERIEURE_EGALE:
		c = new ContrainteSuperieure();
		contraintes.push_back(c);
		break;
	case CONTRAINTE_SOMME_EXACTE:
		c = new ContrainteSommeExacte();
		contraintes.push_back(c);
		break;
	case CONTRAINTE_SOMME_INFERIEURE:
		c = new ContrainteSommeInferieureEgale();
		contraintes.push_back(c);
		break;
	case CONTRAINTE_SOMME_SUPERIEURE:
		c = new ContrainteSommeSuperieureEgale();
		contraintes.push_back(c);
		break;
	default:
		std::cout << "[INFO] Code Contrainte non reconnue" << std::endl;
	}
	return c;
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
				Etat e2 = e;
				std::vector < std::vector<int>> domaines;
				e2.variablesAssignees.push_back(variable);
				for (Variable* var : nonAssignees)
				{
					domaines.push_back(var->getDomaine());
				}
				bool resultatReduction = this->reductionDomaineValeurs(variable);
				if (resultatReduction == true)
				{
					domaines.clear();
					for (Variable* var : nonAssignees)
					{
						domaines.push_back(var->getDomaine());
					}
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
					for (int i = 0; i < domaines.size(); i++)
					{
						nonAssignees.at(i)->remettreDomaine(domaines.at(i));
					}
					variable->remettreValeursInitiales();
					e.etat = echec;
					return e;
				}
			}
		}
	variable->remettreValeursInitiales();
	e.etat = echec;
	return Etat(e);
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
