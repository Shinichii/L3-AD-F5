//
// Created by mathieu on 26/02/2017.
//

#ifndef L3_AD_F5_VARIABLE_H
#define L3_AD_F5_VARIABLE_H
#include <iostream>


using namespace std;

#include <vector>

class Variable {


    class Domaine
    {
    public:
        string nom;
        vector<string> ensemble_possible;

        Domaine(){}
    };








public :



    string nom;

    vector<int> domaine;

public:






    Variable();
    Variable(vector<string> entrer_variable,int nb_variable);
    Variable(vector<string> entrer_variable);

   void affichage();

};


#endif //L3_AD_F5_VARIABLE_H
