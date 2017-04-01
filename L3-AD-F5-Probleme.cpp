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
		std::cout << variable;
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
