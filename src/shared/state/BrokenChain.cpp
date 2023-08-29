#include "BrokenChain.hpp"



vector<Insect> List_X_Neighbour(vector<Insect> list_insect_placed, vector<Case> list_case,int X){

    vector<Insect> list_to_return;

    for (Insect tmp : list_insect_placed){

        int neighbour=0;
        int i_depart = tmp.Get_i();
        int j_depart = tmp.Get_j();

        //Parité de la colonne
        if (j_depart%2==0){

            for (Case casetemp:list_case){

                if((casetemp.GetPosition()[0]==i_depart)&&(casetemp.GetPosition()[1]==j_depart-1)&&(casetemp.GetEmpty()== false)) {

                    neighbour++;
                }
                 if((casetemp.GetPosition()[0]==i_depart)&&(casetemp.GetPosition()[1]==j_depart+1)&&(casetemp.GetEmpty()== false)){


                     neighbour++;
                }
                 if ((casetemp.GetPosition()[0]==i_depart-1)&&(casetemp.GetPosition()[1]==j_depart)&&(casetemp.GetEmpty()== false)){


                     neighbour++;
                }
                 if ((casetemp.GetPosition()[0]==i_depart+1)&&(casetemp.GetPosition()[1]==j_depart-1)&&(casetemp.GetEmpty()== false)) {


                     neighbour++;
                }
                 if ((casetemp.GetPosition()[0]==i_depart+1)&&(casetemp.GetPosition()[1]==j_depart)&&(casetemp.GetEmpty()== false)){


                     neighbour++;
                }
                 if ((casetemp.GetPosition()[0]==i_depart+1)&&(casetemp.GetPosition()[1]==j_depart+1)&&(casetemp.GetEmpty()== false)){


                     neighbour++;
                }
            }
        }
        else{

            for (Case casetemp:list_case){

                if((casetemp.GetPosition()[0]==i_depart-1)&&(casetemp.GetPosition()[1]==j_depart-1)&&(casetemp.GetEmpty()== false)) {

                    neighbour++;
                }
                 if((casetemp.GetPosition()[0]==i_depart-1)&&(casetemp.GetPosition()[1]==j_depart)&&(casetemp.GetEmpty()== false)){

                     neighbour++;
                }
                 if ((casetemp.GetPosition()[0]==i_depart-1)&&(casetemp.GetPosition()[1]==j_depart+1)&&(casetemp.GetEmpty()== false)){

                     neighbour++;
                }
                 if ((casetemp.GetPosition()[0]==i_depart)&&(casetemp.GetPosition()[1]==j_depart-1)&&(casetemp.GetEmpty()== false)){

                     neighbour++;
                }
                 if ((casetemp.GetPosition()[0]==i_depart)&&(casetemp.GetPosition()[1]==j_depart+1)&&(casetemp.GetEmpty()== false)){

                     neighbour++;
                }
                 if ((casetemp.GetPosition()[0]==i_depart+1)&&(casetemp.GetPosition()[1]==j_depart)&&(casetemp.GetEmpty()== false)){

                     neighbour++;
                }
            }
        }


        if (neighbour==X){
            list_to_return.push_back(tmp);
        }

    }

    return list_to_return;
}


vector<Insect> Look_For_Neighbour(vector<Insect> list_insect_placed, vector<Case> list_case,Insect insect_to_start){
    vector<Insect> list_to_return;


    for (Insect tmp : list_insect_placed){
        if (tmp.GetName()==insect_to_start.GetName()){

            int i_depart = tmp.Get_i();
            int j_depart = tmp.Get_j();

            //Parité de la colonne
            if (j_depart%2==0){
                for (Insect insect_to_test : list_insect_placed){

                    if((insect_to_test.Get_i()==i_depart)&&(insect_to_test.Get_j()==j_depart-1)&&(insect_to_test.GetIsPlaced())) {
                        list_to_return.push_back(insect_to_test);
                    }
                    else if((insect_to_test.Get_i()==i_depart)&&(insect_to_test.Get_j()==j_depart+1)&&(insect_to_test.GetIsPlaced())){
                        list_to_return.push_back(insect_to_test);
                    }
                    else if ((insect_to_test.Get_i()==i_depart-1)&&(insect_to_test.Get_j()==j_depart)&&(insect_to_test.GetIsPlaced())){
                        list_to_return.push_back(insect_to_test);
                    }
                    else if ((insect_to_test.Get_i()==i_depart+1)&&(insect_to_test.Get_j()==j_depart-1)&&(insect_to_test.GetIsPlaced())) {
                        list_to_return.push_back(insect_to_test);
                    }
                    else if ((insect_to_test.Get_i()==i_depart+1)&&(insect_to_test.Get_j()==j_depart)&&(insect_to_test.GetIsPlaced())){
                        list_to_return.push_back(insect_to_test);
                    }
                    else if ((insect_to_test.Get_i()==i_depart+1)&&(insect_to_test.Get_j()==j_depart+1)&&(insect_to_test.GetIsPlaced())){
                        list_to_return.push_back(insect_to_test);
                    }
                }
            }
            else{
                for (Insect insect_to_test : list_insect_placed){

                    if((insect_to_test.Get_i()==i_depart-1)&&(insect_to_test.Get_j()==j_depart-1)&&(insect_to_test.GetIsPlaced())) {
                        list_to_return.push_back(insect_to_test);
                    }
                    else if((insect_to_test.Get_i()==i_depart-1)&&(insect_to_test.Get_j()==j_depart)&&(insect_to_test.GetIsPlaced())){
                        list_to_return.push_back(insect_to_test);
                    }
                    else if ((insect_to_test.Get_i()==i_depart-1)&&(insect_to_test.Get_j()==j_depart+1)&&(insect_to_test.GetIsPlaced())){
                        list_to_return.push_back(insect_to_test);
                    }
                    else if ((insect_to_test.Get_i()==i_depart)&&(insect_to_test.Get_j()==j_depart-1)&&(insect_to_test.GetIsPlaced())){
                        list_to_return.push_back(insect_to_test);
                    }
                    else if ((insect_to_test.Get_i()==i_depart)&&(insect_to_test.Get_j()==j_depart+1)&&(insect_to_test.GetIsPlaced())){
                        list_to_return.push_back(insect_to_test);
                    }
                    else if ((insect_to_test.Get_i()==i_depart+1)&&(insect_to_test.Get_j()==j_depart)&&(insect_to_test.GetIsPlaced())){
                        list_to_return.push_back(insect_to_test);
                    }
                }
            }

        }
    }





    return list_to_return;
}



bool Test_Broken_Chain(vector<Insect> list_insect_placed, vector<Case> list_case){

    vector<Insect> result_neighbour;
    vector<Insect> insect_passed;


    for(Insect insect_to_test : list_insect_placed){

        result_neighbour= Look_For_Neighbour(list_insect_placed,list_case,insect_to_test);

        if((result_neighbour.size()==0)&&(list_insect_placed.size()>1)){
            return true;
        }
        if (insect_passed.size()==0){
            insect_passed.push_back(insect_to_test);
        }
        else {
            int occur=0;
            for(Insect tmp : insect_passed){
                if(tmp.GetName()==insect_to_test.GetName()){
                    occur++;
                }
            }
            if (occur==0){
                insect_passed.push_back(insect_to_test);
            }
        }


    }


    vector<Insect> insect_treated;
    vector<Insect> insect_queue;
    vector<Insect> insect_to_add_to_queue;


    insect_queue.push_back(list_insect_placed[0]);




    while(insect_queue.size()!=0){


        for(Insect test : insect_queue){


            vector<Insect> neighbours = Look_For_Neighbour(list_insect_placed,list_case,test);
                for(Insect next : neighbours){
                    int occur=0;
                    for (Insect queuing : insect_queue){
                        if(queuing.GetName()==next.GetName()){
                            occur++;
                        }
                    }
                    if(insect_treated.size()!=0) {
                        for (Insect treated: insect_treated) {
                            if (treated.GetName() == next.GetName()) {
                                occur++;
                            }
                        }
                    }
                    if (occur==0){
                        insect_to_add_to_queue.push_back(next);
                    }
                }
                    insect_treated.push_back(test);
        }

        insect_queue.clear();

    for(Insect insect_need_queuing : insect_to_add_to_queue){
        insect_queue.push_back(insect_need_queuing);
    }
    insect_to_add_to_queue.clear();

    }


    //RECHERCHE DES DOUBLONS DANS LA LISTES DES TREATED
    vector<int> indicetosup;
    vector<Insect> insect_treated_unique=insect_treated;
    for (int i=0;i<insect_treated.size()-1;i++){
        for (int j=i+1;j<insect_treated.size();j++){
            auto temp = insect_treated[i];
            auto candidat = insect_treated[j];
            if ((temp.GetName() == candidat.GetName())){
                indicetosup.push_back(j);
            }
        }
    }


    std::sort(indicetosup.begin(), indicetosup.end());

    auto listo=std::unique(indicetosup.begin(), indicetosup.end());
    indicetosup.resize(distance(indicetosup.begin(),listo));

    for (int i=0;i<indicetosup.size();i++){
        insect_treated_unique.erase(insect_treated_unique.begin()+indicetosup[i]-i);
    }

    insect_treated=insect_treated_unique;


    if (insect_treated.size()!=list_insect_placed.size()){
        return true;
    }
    else{

        return false;
}


}