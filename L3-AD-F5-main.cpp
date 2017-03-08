#include <iostream>


using namespace std;


#include <vector>
#include "L3-AD-F5-Probleme.h"




class test{
public:
    string nom;
    vector<string> domaine;

    test(){nom="vide";}
    test(string Nom) { nom=Nom;}

    void affichage()
    {
        cout<<nom<<" :";
        for (string a:domaine) {cout<<" "<<a;

        }

        cout<<endl;
    }
};


vector<test> decomposer(string entrer_variable);

int main() {



    string tester="A { Z , G } B { { A , c } , c }";

    vector<test> Liste=decomposer(tester);

    for(test az:Liste)
    {
        az.affichage();

    }


    //Utilitaire::affichageln(decomposer(tester));




    return 0;
}


vector<test> decomposer(string entrer_variable)
{ vector<test> retourned;


    vector<string> entrer=Utilitaire::parse(entrer_variable);

    cout<<"-----------------------------"<<endl;
    vector<string> retour;

    int i=0;int cmp=0;
    string tmp="";
    if(entrer[i]=="#"){cout<<" # detecter"<<endl;i++;}

    while(i<entrer.size())
    {
        if(entrer[i]=="{")
        {tmp="{";cmp=0;
            while(i++<entrer.size() && cmp>=0 )
            {tmp+=entrer[i]+" ";
            if(entrer[i]=="{"){cmp++;}
            else if (entrer[i]=="}"){cmp--;}


            }


            retourned.back().domaine.push_back(tmp);
            cout<<" push :"<<tmp<<endl;
        }
        else if(entrer[i]=="[")
        {
            tmp="[";
            while(i++<entrer.size() && entrer[i]!="]")
            {tmp+=entrer[i]+" ";}

            if(entrer[i]=="]"){tmp+="]";i++;}else{cerr<<" [ non refermer";}

            retourned.back().domaine.push_back(tmp);
                    cout<<" push :"<<tmp<<endl;
        }
        else
        {
            retourned.push_back(test(entrer[i]));

            cout<<" : "<<  entrer[i]<<endl;i++;
        }


    }
    cout<<"-----------------------------"<<endl;
    return retourned;

}


string crochet(vector<string> entrer,int * curseur)
{
    string retour="{";
    int cmp=0;


    while(curseur++ &&<entrer.size() && cmp>=0 )
    {tmp+=entrer[i]+" ";
        if(entrer[i]=="{"){cmp++;}
        else if (entrer[i]=="}"){cmp--;}


    }


    retourned.back().domaine.push_back(tmp);
    cout<<" push :"<<tmp<<endl;
    return retour;

}