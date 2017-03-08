//
// Created by mathieu on 26/02/2017.
//

#include "L3-AD-F5-Variable.h"
#include "L3-AD-F5-Utilitaire.h"
Variable::Variable()
{nom="vide";
    domaine.emplace_back(1);
    domaine.emplace_back(2);
    domaine.emplace_back(3);
}


Variable::Variable(vector<string> entrer_variable)
{
    cout<<"fail"<<endl;
}

Variable::Variable(vector<string> entrer_variable,int nb_variable)
{
Utilitaire::affichageln(entrer_variable);

    cout<<endl<<"------------------------------------------------------------------------"<<endl;
   // Domaine domaines;
    string ensemble_possible_test="";

    int Ligne=0;

    cout<<"ligne_en_cour :"<<Utilitaire::toString(entrer_variable)<<endl;
    vector<string> ligne_courante=Utilitaire::parse(entrer_variable[0]);


//----------------------------------------------------------------------------------------------------------------------
if(ligne_courante[0]=="#")//si la premiere ligne sapplique a toutes les variables
    {
        if(ligne_courante[2]=="{")
        {
            int i=2;
            while (ligne_courante[i]!="}" && i<ligne_courante.size())
            {

                ensemble_possible_test+=" "+ligne_courante[i];
                i++;

                cout<<"add : "<<ensemble_possible_test<<endl;
            }


            cout<<endl<<"arret ="<<ligne_courante[i]<<endl;




            if(i==ligne_courante.size()){cout<<"erreur Variable(); le crochet n'est pas fermer"<<endl;}
            else if(ligne_courante[i]=="}"){ensemble_possible_test+="}";}
            else {cout<<"erreur variable42";}


           cout<<"add"<<ensemble_possible_test<<endl;

        }
        else if (ligne_courante[1]=="[")
        {
            // a faire apres
            cout <<"a faire apres 1"<<endl;
        }
        else
        {
            cout <<"erreur Variable AZ"<<endl;
        }




    }
//----------------------------------------------------------------------------------------------------------------------
else //aucun rassemblement entre les differentes variables (mal dit)
    {
        cout <<"a faire apres 2"<<endl;

        // a faire apres
    }



    cout<<(ligne_courante[2]=="{")<<" !"<<ligne_courante[2]<<"! "<<endl;

    cout<<"----------------------------------"<<endl;

}


vector<string> Variable::decomposer(string entrer_variable)
{
    vector<string> entrer=Utilitaire::parse(entrer_variable);
    vector<string> retour;
    int i =0;
    string tmp="";
    if(entrer[i]=="#"){cout<<" # detecter"<<endl;i++;}

    while(i<entrer_variable.size())
    {
        if(entrer[i]=="{")
            {tmp="{";
                while(i<entrer_variable.size() && entrer[i]!="}")
                {tmp+=entrer[i]+" ";
                i++;
                }

                if(entrer[i]!="}"){tmp+="}";}
                retour.push_back(tmp);
            }
        else if(entrer[i]=="[")
            {
                tmp="[";
                while(i<entrer_variable.size() && entrer[i]!="]")
                {tmp+=entrer[i]+" ";
                    i++;
                }

                if(entrer[i]!="]"){tmp+="]";}else{cerr<<" [ non refermer";}
                retour.push_back(tmp);
            }
        else
            {
              cout<<" : "<<  entrer[i]<<endl;i++;
            }


    }


}







//-----------------------------------

void Variable::affichage()
{
    cout<<nom<<" :";

    for(int valeur:domaine)
    {
        cout<<valeur<<" ";
    }
    cout<<endl;


}