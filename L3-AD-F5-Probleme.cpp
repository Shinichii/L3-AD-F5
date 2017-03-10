#include "L3-AD-F5-Probleme.h"

#include <iostream>


using namespace std;

#include <vector>
#include <cstdlib>

//----------------------------------------------------------------------------------------------------------------------
//------------------------------------------  Constructeur    ----------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------

Probleme::Probleme()
{
    vector<string> entrer=getFichier_brut();
    vector<string> entrer_variable,entrer_contrainte;


    nom_Probleme=entrer[0];
    nb_variable= atoi(Utilitaire::parse(entrer[1])[0].c_str());

  int longueur_declaration_variable=atoi(Utilitaire::parse(entrer[1])[1].c_str());//peut etre different de nb_variable


//---------------------------------------------- affectation des variables et de leur domaine ---------------------------
    for(int i=2;i<longueur_declaration_variable+2;i++)        {  entrer_variable.emplace_back(entrer[i].c_str()); }

    //Variables=Variable(entrer_variable,nb_variable);

// ----------------------------------------------affectation des contraintes --------------------------------------------


    for(int i=longueur_declaration_variable+2;i<entrer.size();i++)        {entrer_contrainte.emplace_back(entrer[i].c_str()); }

cout<<" fin probleme"<<endl;
}



//--------------------------------------------------------------------------------------------------------------
vector<string> Probleme::getFichier_brut() // temporaire pour les test en attendant
{vector<string> retour;
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


    Contraintes.emplace_back(new Contrainte());
    Contraintes.emplace_back(new Contrainte());


}




//----------------------------------------------------------------------------------------------------------------------
//------------------------------------------  Affichage    -------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------

void Probleme::afficher()
{
    cout<<"Le probleme : "+nom_Probleme<<endl;
    cout<<"Il y a "<<nb_variable<<" variables :"<<endl;


    for(Contrainte* contrainte:Contraintes) { contrainte->affichage();}


}