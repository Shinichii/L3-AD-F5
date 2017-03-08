#include <iostream>


using namespace std;


#include <vector>
#include "L3-AD-F5-Probleme.h"




class test{
public:
    string nom;
    vector<vector<string>> domaine;

    test(){nom="vide";}
    test(string Nom) { nom=Nom;}

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
};


vector<test> decomposer(string entrer_variable);
int separation(vector<string> entrer,string ouvrante,string fermente,int curseur);

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
        {
            int suivant=separation(entrer,"{","}",i);
            retourned.back().domaine.push_back(Utilitaire::parse(entrer,i,suivant));
            i=suivant;
        }
        else if(entrer[i]=="[")
        {

            int suivant=separation(entrer,"[","]",i);
            retourned.back().domaine.push_back(Utilitaire::parse(entrer,i,suivant));
            i=suivant;

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


int separation(vector<string> entrer,string ouvrante,string fermente,int curseur)
{
    int cmp=0;

    while(curseur+1<entrer.size() && cmp>=0 )
    {
         if(entrer[curseur]==ouvrante){cmp++;}
        else if (entrer[curseur]==fermente){cmp--;}
        cout<<endl;
        curseur++;
    }

    if(curseur-1>0 &&  entrer[curseur-1]!=fermente)
        { cerr<<"Finaux :"<<entrer[curseur]<<": crochet non refermer dans le fichier"<<endl;}

    return curseur;
}