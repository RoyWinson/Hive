#include "LinkedCase.hpp"


vector<vector<int>> Linked_Cases(vector<vector<int>> list_case_possibilities,vector<int> case_to_test){
    vector<vector<int>> list_to_return;
    list_to_return.push_back(case_to_test);
    int i_depart = case_to_test[0],j_depart=case_to_test[1];

        if (j_depart % 2 == 0) {
            for(auto tmp : list_case_possibilities) {
                if((tmp[0]==i_depart)&&(tmp[1]==j_depart-1)) {
                    list_to_return.push_back(tmp);
                }
                else if((tmp[0]==i_depart)&&(tmp[1]==j_depart+1)){
                    list_to_return.push_back(tmp);
                }
                else if ((tmp[0]==i_depart-1)&&(tmp[1]==j_depart)){
                    list_to_return.push_back(tmp);
                }
                else if ((tmp[0]==i_depart+1)&&(tmp[1]==j_depart-1)) {
                    list_to_return.push_back(tmp);
                }
                else if ((tmp[0]==i_depart+1)&&(tmp[1]==j_depart)){
                    list_to_return.push_back(tmp);
                }
                else if ((tmp[0]==i_depart+1)&&(tmp[1]==j_depart+1)){
                    list_to_return.push_back(tmp);
                }
            }

        }
        else {
            for(auto tmp : list_case_possibilities) {
                if((tmp[0]==i_depart-1)&&(tmp[1]==j_depart-1)) {
                    list_to_return.push_back(tmp);
                }
                else if((tmp[0]==i_depart-1)&&(tmp[1]==j_depart)){
                    list_to_return.push_back(tmp);
                }
                else if ((tmp[0]==i_depart-1)&&(tmp[1]==j_depart+1)){
                    list_to_return.push_back(tmp);
                }
                else if ((tmp[0]==i_depart)&&(tmp[1]==j_depart-1)) {
                    list_to_return.push_back(tmp);
                }
                else if ((tmp[0]==i_depart)&&(tmp[1]==j_depart+1)){
                    list_to_return.push_back(tmp);
                }
                else if ((tmp[0]==i_depart+1)&&(tmp[1]==j_depart)){
                    list_to_return.push_back(tmp);
                }
            }

        }
    return list_to_return;
}
vector<vector<int>> Linked_To_Ant(vector<vector<int>> list_case_possibilities,vector<int> ant_coord){

    vector<vector<int>> coord_treated;
    vector<vector<int>> coord_queue;
    vector<vector<int>> coord_to_add_to_queue;

    if(list_case_possibilities.size()==0){return list_case_possibilities;}


    coord_queue.push_back(ant_coord);



    while(coord_queue.size()!=0){


        for(vector<int> test : coord_queue){

            vector<vector<int>> neighbours = Linked_Cases(list_case_possibilities,test);
            for(vector<int> next : neighbours){
                int occur=0;
                for (vector<int> queuing : coord_queue){
                    if((queuing[0]==next[0])&&(queuing[1]==next[1])){
                        occur++;
                    }
                }
                if(coord_treated.size()!=0) {
                    for (vector<int> treated: coord_treated) {
                        if ((treated[0] == next[0])&&(treated[1]==next[1])) {
                            occur++;
                        }
                    }
                }
                if (occur==0){
                   coord_to_add_to_queue.push_back(next);
                }
            }


            coord_treated.push_back(test);




        }

        coord_queue.clear();

        for(vector<int> coord_need_queuing : coord_to_add_to_queue){
            coord_queue.push_back(coord_need_queuing);
        }
        coord_to_add_to_queue.clear();

    }


    //RECHERCHE DES DOUBLONS DANS LA LISTES DES TREATED
    vector<int> indicetosup;
    vector<vector<int>> coord_treated_unique=coord_treated;
    for (int i=0;i<coord_treated.size()-1;i++){
        for (int j=i+1;j<coord_treated.size();j++){
            auto temp = coord_treated[i];
            auto candidat = coord_treated[j];
            if ((temp[0] == candidat[0])&&(temp[1]==candidat[1])){
                indicetosup.push_back(j);
            }
        }
    }


    std::sort(indicetosup.begin(), indicetosup.end());

    auto listo=std::unique(indicetosup.begin(), indicetosup.end());
    indicetosup.resize(distance(indicetosup.begin(),listo));

    for (int i=0;i<indicetosup.size();i++){
        coord_treated_unique.erase(coord_treated_unique.begin()+indicetosup[i]-i);
    }

    coord_treated=coord_treated_unique;


    indicetosup.clear();
    for (int i=0;i<coord_treated_unique.size()-1;i++){
            auto temp = coord_treated_unique[i];
            if ((temp[0] == ant_coord[0])&&(temp[1]==ant_coord[1])){
                indicetosup.push_back(i);
            }
        }

    std::sort(indicetosup.begin(), indicetosup.end());

    auto listo2=std::unique(indicetosup.begin(), indicetosup.end());
    indicetosup.resize(distance(indicetosup.begin(),listo2));

    for (int i=0;i<indicetosup.size();i++){
        coord_treated_unique.erase(coord_treated_unique.begin()+indicetosup[i]-i);
    }

    coord_treated=coord_treated_unique;


    return coord_treated;
}