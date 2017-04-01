

#ifndef L3_AD_F5_PROBLEME_H
#define L3_AD_F5_PROBLEME_H


#include "L3-AD-F5-Variable.h"
#include "L3-AD-F5-ContrainteEgalite.h"
#include "L3-AD-F5-ContrainteInegalite.h"
#include "L3-AD-F5-ContrainteSommeExacte.h"
#include "L3-AD-F5-ContrainteSommeInferieureEgale.h"
#include "L3-AD-F5-ContrainteSommeSuperieureEgale.h"
#include "L3-AD-F5-ContrainteInferieure.h"
#include "L3-AD-F5-ContrainteSuperieure.h"

#include <vector>

#include <string>

class Probleme {

public:

     std::string nom_Probleme;
     int nb_variable;
     std::vector<Variable*> variables;
	 std::vector<Contrainte*> contraintes;


    std::vector<std::string> getFichier_brut();// temporaire pour les test en attendant

    //constructeur
    Probleme();


    Probleme(std::string Nom_Probleme);

    //affichage
    void afficher();
	void ajouterVariable(int identificateur, std::vector<int> domaine);
	Variable* chercherVariable(int nom);
	Contrainte* ajouterContrainte(int typeContrainte);




    //autre


};


#endif //L3_AD_F5_PROBLEME_H
