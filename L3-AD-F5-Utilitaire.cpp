//
// Created by mathieu on 26/02/2017.
//

#include <sstream>
#include <iterator>
#include "L3-AD-F5-Utilitaire.h"





    vector<string> Utilitaire::parse(string entrer) {

        vector<string> retour;
        stringstream ss(entrer);
        string tok;

        while(getline(ss, tok, ' ')) {
            retour.push_back(tok);
        }

        return retour;
    }

void Utilitaire::affichageln( vector<string> entrer){ for(string ligne:entrer){cout<<ligne<<endl;}}
void Utilitaire::affichage( vector<string> entrer){ for(string ligne:entrer){cout<<ligne<<" ";}}

string Utilitaire::toString( vector<string> entrer){ string retour="";
    for(string ligne:entrer){retour+=ligne;
        return retour;}}

