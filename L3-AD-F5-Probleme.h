#ifndef L3_AD_F5_PROBLEME_H
#define L3_AD_F5_PROBLEME_H


#include "L3-AD-F5-Variable.h"
#include "L3-AD-F5-ContrainteEgalite.h"
#include "L3-AD-F5-ContrainteInegalite.h"
#include "L3-AD-F5-ContrainteInferieure.h"
#include "L3-AD-F5-ContrainteSuperieure.h"
#include "L3-AD-F5-ContrainteInferieureEgale.h"
#include "L3-AD-F5-ContrainteSuperieureEgale.h"

#include "L3-AD-F5-ContrainteSommeExacte.h"
#include "L3-AD-F5-ContrainteSommeInferieureEgale.h"
#include "L3-AD-F5-ContrainteSommeSuperieureEgale.h"
#include "L3-AD-F5-ContrainteSommeInferieure.h"
#include "L3-AD-F5-ContrainteSommeSuperieure.h"
#include "L3-AD-F5-ContrainteSommePonderee.h"

#include "L3-AD-F5-Statistiques.h"
#include "L3-AD-F5-operationFichier.h"

#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include <fstream>
#include <cstdlib>


enum realisation
{
	indetermine = 0x0,
	non_initialise = 0x1,
	succes = 0x2,
	echec = 0x3
};

typedef struct
{
	std::vector<Variable*> variablesAssignees;
	realisation etat = indetermine;
}Etat;

class Probleme {


private:
     std::string nom_Probleme;
     std::vector<Variable*> variables;
	 std::vector<Contrainte*> contraintes;
	 Statistiques stats;

public:
    //constructeur
    Probleme();

	Statistiques getStatistiques();
    Probleme(std::string Nom_Probleme);

    //affichage
    void afficher();
	void ajouterVariable(int identificateur, std::vector<int> domaine);
	Variable* chercherVariable(int nom);
	Contrainte* ajouterContrainte(int typeContrainte);

	//Resolution du probleme
	void resoudreProbleme();
	Etat constructionEtatInitial();
	Etat constructionEtatInitialReductionDomaineValeurs();
	Etat resolutionProblemeRechercheProfondeurDAbord(Etat e);
	bool reductionDomaineValeurs(Variable *v);
	void remettreDomaineValeurs(Variable *v);
	Etat resolutionProblemeReductionValeur(Etat e);

	Etat resolutionProblemeVariablePlusContrainte(Etat e);
	Variable* chercherVariableLaPlusContrainte(std::vector<Variable*> nonAssignees);

	Etat resolutionProblemeVariableMoinsContrainte(Etat e);
	Variable* chercherVariableLaMoinsContrainte(std::vector<Variable*> nonAssignees);

	Etat resolutionProblemeVariableLaPlusContraignante(Etat e);
	Variable* chercherVariableLaPlusContraignante(std::vector<Variable*> nonAssignees);

	Etat resolutionProblemeVariableLaMoinsContraignante(Etat e);
	Variable* chercherVariableLaMoinsContraignante(std::vector<Variable*> nonAssignees);
	//Sauver le resultat dans un fichier c�d Contraintes/Variables et valeurs + stats
	void sauverResultat(bool solutionTrouvee, std::string methodeUtilisee);
	//Avec les contraintes
	bool estConsistant();
	//Fonction pour d�couvrir la variable impliqu�e dans le moins de contraintes portant sur des variables non assignees
};
std::vector<Variable*> fusionExclusive(std::vector<Variable*> variables, std::vector<Variable*> aExclure);


#endif //L3_AD_F5_PROBLEME_H
