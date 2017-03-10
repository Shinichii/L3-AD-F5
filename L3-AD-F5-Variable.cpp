//
// Created by mathieu on 26/02/2017.
//

#include <stdlib.h>
#include "L3-AD-F5-Variable.h"
#include "L3-AD-F5-Utilitaire.h"


//----------------------------------------------------------------------------------------------------------------------
//-------------------------------------   Constructeur     -------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------




//----------------------------------------------------------------------------------------------------------------------
//-------------------------------------   Surchage operateur  ----------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------




//----------------------------------------------------------------------------------------------------------------------
//-------------------------------------   test             -------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------

bool Variable::unicite(vector<Variable> Liste)
{
/*
    for (Variable current:Liste)
    {
        for (Variable autre:Liste)
        {
            if(current != autre && current.nom==autre.nom)
            {
                return false;
            }
        }
    }
*/
// A FINIR


    return true;
}

int Variable::exist(vector<Variable> Liste,string nom)
{
    int i=0;
    for (Variable current:Liste)
    {
        if(current.nom==nom)
        {return i;}
        i++;
    }
    return -1;
}
//----------------------------------------------------------------------------------------------------------------------
//-------------------------------------   fonction diverse -------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------

vector<Variable> Variable::decomposer(string entrer_variable)
{ vector<Variable> retourned;


    vector<string> entrer=Utilitaire::parse(entrer_variable);

    cout<<endl<<"-----------------------------"<<endl;
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
        { retourned.push_back(Variable(entrer[i]));
            i++;
        }
    }
    return retourned;

}


int Variable::separation(vector<string> entrer,string ouvrante,string fermente,int curseur)
{
    int debut=curseur;
    int cmp=0;

    do{
        if(entrer[curseur]==ouvrante){cmp++;}
        else if (entrer[curseur]==fermente){cmp--;}

        curseur++;
    }while(curseur<entrer.size() && cmp>0 );


    if(curseur-1>0 &&  entrer[curseur-1]!=fermente)
    { cerr<<"Finaux :"<<entrer[curseur]<<": crochet non refermer dans le fichier"<<endl;}

    return curseur;
}

vector<Variable> Variable::remplacement(vector<Variable> Liste)
{
    vector<Variable> retour;

    cout<<endl<<"Debut remplacement"<<endl;
    for(Variable current:Liste){ current.affichage();}

    cout<<endl<<"------------------------------------------------------"<<endl;
   for(Variable current:Liste)
        {Variable tmp;
            tmp.nom=current.nom;

            vector<vector<string>> tmpdomaine;
            for(vector<string> copyVecteur:current.domaine)
            { vector<string> aa;
                for(int i=0;i<copyVecteur.size();i++)
                {


                    if(copyVecteur[i]=="[")
                    {
                    aa.push_back("{{");
                        cout<<endl;
                        //transformer 1 , 9 en 1, 2 ,3 ,4 ,5 etc

                        for(int k=atoi(copyVecteur[i+1].c_str());k<atoi(copyVecteur[i+3].c_str());k++)
                        {
                            aa.push_back(std::to_string(k));
                        }

                    aa.push_back(copyVecteur[i+2]);
                    aa.push_back(copyVecteur[i+3]);



                    //aa.push_back(copyVecteur[i+4]);cout<<copyVecteur[i+4]<<" ";
                        cout<<endl;
                    aa.push_back("}}");
                      i=i+4;
                    }
                    else
                    {
                        aa.push_back(copyVecteur[i]);
                    }

                }
                tmpdomaine.push_back(aa);
            }
          tmp.domaine=tmpdomaine;
         retour.push_back(tmp);
        }

    cout<<endl<<"------------------------------------------------------"<<endl;
    cout<<endl<<"Fin remplacement"<<endl;

    for(Variable current:retour)        {current.affichage();}


    cout<<endl<<"------------------------------------------------------"<<endl;

// A FINIR
    return retour;
}




vector<Variable> Variable::assembler(vector<vector<Variable>> Liste) {
    vector<Variable> retour;
    for (vector<Variable> aa:Liste) {
        for (Variable current:aa) { retour.push_back(current); }
    }
    return retour;
}

