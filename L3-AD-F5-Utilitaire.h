//
// Created by mathieu on 26/02/2017.
//

#ifndef L3_AD_F5_UTILITAIRE_H
#define L3_AD_F5_UTILITAIRE_H


#include <iostream>


using namespace std;
#include <vector>

class Utilitaire {

public:

    static vector<string> parse(string entrer);
    static void affichageln( vector<string> entrer);
    static void affichage(vector<string> entrer);
    static string toString(vector<string> entrer);
    static bool is_number(const std::string& s);
    static vector<string> parse(vector<string> vecteur,int debut,int fin);

};


#endif //L3_AD_F5_UTILITAIRE_H
