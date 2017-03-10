#include <iostream>


using namespace std;


#include <vector>
#include "L3-AD-F5-Probleme.h"



int main() {

    vector<string> tester;
    tester.emplace_back((string)"# X { L , C }");
    tester.emplace_back((string)"L [ 1 , 9 ]");
    tester.emplace_back((string)"C [ 1 , 9 ]");
    Utilitaire::affichageln(tester);

    vector<vector<Variable>> variable;

    for(string Liste:tester)
    {
        variable.push_back(Variable::decomposer(Liste));
    }

    vector<Variable> decomposer=Variable::assembler(variable);
    vector<Variable> mischemin=Variable::remplacement( decomposer);

    for(Variable  az:mischemin)    { az.affichage(); }






    //Utilitaire::affichageln(decomposer(tester));



    return 0;
}
