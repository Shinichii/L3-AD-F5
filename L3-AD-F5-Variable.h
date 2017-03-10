//
// Created by mathieu on 26/02/2017.
//

#ifndef L3_AD_F5_VARIABLE_H
#define L3_AD_F5_VARIABLE_H
#include <iostream>

using namespace std;

#include <vector>




class Variable {
public:
    string nom;
    vector<vector<string>> domaine;

    Variable(){nom="vide";}
    Variable(string Nom) { nom=Nom;}

    void affichage()
    {
        cout<<nom<<" :";
        for(vector<string> aze:domaine)
        {
            for (string a:aze) {cout<<" "<<a;}
            cout<<"   ";
        }
        cout<<endl;
    }


    bool operator==(Variable const& a)
    {if(a.nom!=nom){return false;}
        for(vector<string> ListeA:a.domaine)
        {for(string currentA:ListeA)
            { for(vector<string> ListeB:domaine)
                {for(string currentB:ListeB)
                    {if(currentA!=currentB){ return false;}
                    }
                }
            }
        }return true;
    }

    bool operator!=(Variable const& a)
    {if(a.nom!=nom){return true;}
        for(vector<string> ListeA:a.domaine)
        {for(string currentA:ListeA)
            { for(vector<string> ListeB:domaine)
                {for(string currentB:ListeB)
                    {if(currentA!=currentB){ return true;}
                    }
                }
            }
        }return false;
    }

public:
    static  vector<Variable> decomposer(string entrer_variable);
    static int separation(vector<string> entrer,string ouvrante,string fermente,int curseur);
    static vector<Variable> assembler(vector<vector<Variable>> Liste);
    static  int exist(vector<Variable> Liste,string nom);
    static vector<Variable> remplacement(vector<Variable> Liste);
    static bool unicite(vector<Variable> Liste);


};


#endif //L3_AD_F5_VARIABLE_H
