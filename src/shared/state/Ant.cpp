
#include "Ant.hpp"
#include "BrokenChain.hpp"
#include "LinkedCase.hpp"

using namespace std;


Ant::Ant(std::string name, std::string color, std::vector<int> coord, int level) : Insect(name, color, coord, level) {
    Insect(this->Name = name, this->Color = color, this->Coord = coord, this->Level= level );
}

std::vector<std::vector<int>>
Ant::Possible_Deplacement_Insect(std::vector<Insect> list_insect_placed, std::vector<Case> list_case) {

    if(list_insect_placed.size()>=7){
                int neighbour=0;
                int i_to_avoid=this->Get_i(),j_to_avoid=this->Get_j();

                if (j_to_avoid % 2 == 0) {
                    for (Case casetemp: list_case) {

                        if (((casetemp.GetPosition()[0] == i_to_avoid) && (casetemp.GetPosition()[1] == j_to_avoid - 1) &&
                             (casetemp.GetEmpty() == false))) {
                            neighbour++;
                        }
                        else if (((casetemp.GetPosition()[0] == i_to_avoid) && (casetemp.GetPosition()[1] == j_to_avoid + 1) &&
                                  (casetemp.GetEmpty() == false))) {
                            neighbour++;                        }
                        else if (((casetemp.GetPosition()[0] == i_to_avoid - 1) && (casetemp.GetPosition()[1] == j_to_avoid) &&
                                  (casetemp.GetEmpty() == false))) {
                            neighbour++;                        }
                        else if (((casetemp.GetPosition()[0] == i_to_avoid + 1) && (casetemp.GetPosition()[1] == j_to_avoid - 1) &&
                                  (casetemp.GetEmpty() == false))) {
                            neighbour++;                        }
                        else if (((casetemp.GetPosition()[0] == i_to_avoid + 1) && (casetemp.GetPosition()[1] == j_to_avoid) &&
                                  (casetemp.GetEmpty() == false))) {
                            neighbour++;                        }
                        else if (((casetemp.GetPosition()[0] == i_to_avoid + 1) && (casetemp.GetPosition()[1] == j_to_avoid + 1) &&
                                  (casetemp.GetEmpty() == false))) {
                            neighbour++;                        }

                    }
                }
                else {
                    for (Case casetemp: list_case) {

                        if (((casetemp.GetPosition()[0] == i_to_avoid - 1) && (casetemp.GetPosition()[1] == j_to_avoid - 1) &&
                             (casetemp.GetEmpty() == false))) {
                            neighbour++;                        }
                        else if (((casetemp.GetPosition()[0] == i_to_avoid - 1) && (casetemp.GetPosition()[1] == j_to_avoid) &&
                                  (casetemp.GetEmpty() == false))) {
                            neighbour++;                        }
                        else if (((casetemp.GetPosition()[0] == i_to_avoid - 1) && (casetemp.GetPosition()[1] == j_to_avoid + 1) &&
                                  (casetemp.GetEmpty() == false))) {
                            neighbour++;                        }
                        else if (((casetemp.GetPosition()[0] == i_to_avoid) && (casetemp.GetPosition()[1] == j_to_avoid - 1) &&
                                  (casetemp.GetEmpty() == false))) {
                            neighbour++;                        }
                        else if (((casetemp.GetPosition()[0] == i_to_avoid) && (casetemp.GetPosition()[1] == j_to_avoid + 1) &&
                                  (casetemp.GetEmpty() == false))) {
                            neighbour++;                        }
                        else if (((casetemp.GetPosition()[0] == i_to_avoid + 1) && (casetemp.GetPosition()[1] == j_to_avoid) &&
                                  (casetemp.GetEmpty() == false))) {
                            neighbour++;                        }
                    }
                }

                if(neighbour==6){
                    return {};
                }


            }



    std::vector<std::vector<int>> list_possible_placement;
    for(auto tmp : list_insect_placed) {
        if (tmp.GetName() != this->GetName()) {


            int i_depart = tmp.Get_i(), j_depart = tmp.Get_j(),i_to_avoid=this->Get_i(),j_to_avoid=this->Get_j();

            if (j_depart % 2 == 0) {
                for (Case casetemp: list_case) {

                    if (((casetemp.GetPosition()[0] == i_depart) && (casetemp.GetPosition()[1] == j_depart - 1) &&
                        (casetemp.GetEmpty() == true))) {
                        list_possible_placement.push_back(casetemp.GetPosition());
                    }
                    else if (((casetemp.GetPosition()[0] == i_depart) && (casetemp.GetPosition()[1] == j_depart + 1) &&
                        (casetemp.GetEmpty() == true))) {
                        list_possible_placement.push_back(casetemp.GetPosition());
                    }
                    else if (((casetemp.GetPosition()[0] == i_depart - 1) && (casetemp.GetPosition()[1] == j_depart) &&
                        (casetemp.GetEmpty() == true))) {
                        list_possible_placement.push_back(casetemp.GetPosition());
                    }
                    else if (((casetemp.GetPosition()[0] == i_depart + 1) && (casetemp.GetPosition()[1] == j_depart - 1) &&
                        (casetemp.GetEmpty() == true))) {
                        list_possible_placement.push_back(casetemp.GetPosition());
                    }
                    else if (((casetemp.GetPosition()[0] == i_depart + 1) && (casetemp.GetPosition()[1] == j_depart) &&
                        (casetemp.GetEmpty() == true))) {
                        list_possible_placement.push_back(casetemp.GetPosition());
                    }
                    else if (((casetemp.GetPosition()[0] == i_depart + 1) && (casetemp.GetPosition()[1] == j_depart + 1) &&
                        (casetemp.GetEmpty() == true))) {
                        list_possible_placement.push_back(casetemp.GetPosition());
                    }

                }
            }
            else {
                for (Case casetemp: list_case) {

                    if (((casetemp.GetPosition()[0] == i_depart - 1) && (casetemp.GetPosition()[1] == j_depart - 1) &&
                        (casetemp.GetEmpty() == true))) {
                        list_possible_placement.push_back(casetemp.GetPosition());
                    }
                    else if (((casetemp.GetPosition()[0] == i_depart - 1) && (casetemp.GetPosition()[1] == j_depart) &&
                        (casetemp.GetEmpty() == true))) {
                        list_possible_placement.push_back(casetemp.GetPosition());
                    }
                    else if (((casetemp.GetPosition()[0] == i_depart - 1) && (casetemp.GetPosition()[1] == j_depart + 1) &&
                        (casetemp.GetEmpty() == true))) {
                        list_possible_placement.push_back(casetemp.GetPosition());
                    }
                    else if (((casetemp.GetPosition()[0] == i_depart) && (casetemp.GetPosition()[1] == j_depart - 1) &&
                        (casetemp.GetEmpty() == true))) {
                        list_possible_placement.push_back(casetemp.GetPosition());
                    }
                    else if (((casetemp.GetPosition()[0] == i_depart) && (casetemp.GetPosition()[1] == j_depart + 1) &&
                        (casetemp.GetEmpty() == true))) {
                        list_possible_placement.push_back(casetemp.GetPosition());
                    }
                    else if (((casetemp.GetPosition()[0] == i_depart + 1) && (casetemp.GetPosition()[1] == j_depart) &&
                        (casetemp.GetEmpty() == true))) {
                        list_possible_placement.push_back(casetemp.GetPosition());
                    }


                }
            }

        }
    }


    if(list_possible_placement.size()==0){cout<<"AUCUNE POSSIBILITE"<<endl;return list_possible_placement;}


    //RECHERCHE DES DOUBLONS DANS LA LISTES DES COORDONNEES POSSIBLES
    vector<int> indicetosup;
    vector<vector<int>> list_possible_placement_unique=list_possible_placement;
    for (int i=0;i<list_possible_placement.size()-1;i++){
        for (int j=i+1;j<list_possible_placement.size();j++){
            auto temp = list_possible_placement[i];
            auto candidat = list_possible_placement[j];
            if ((temp[0] == candidat[0]) && (temp[1] == candidat[1])){
                indicetosup.push_back(j);
            }
        }
    }


    std::sort(indicetosup.begin(), indicetosup.end());

    auto listo=std::unique(indicetosup.begin(), indicetosup.end());
    indicetosup.resize(distance(indicetosup.begin(),listo));

    for (int i=0;i<indicetosup.size();i++){
        list_possible_placement_unique.erase(list_possible_placement_unique.begin()+indicetosup[i]-i);
    }


    list_possible_placement_unique= Linked_To_Ant(list_possible_placement_unique,{this->Get_i(),this->Get_j()});

//VERIFICATION DE CASSAGE DE CHAINE
    vector<int> index_chain;
    int ind=0;
    for (vector<int> pos_to_test: list_possible_placement_unique){

        vector<Insect> list_insect_placed_modified = list_insect_placed;


        int index_ins=0;
        for(Insect tmp : list_insect_placed_modified){
            if(tmp.GetName()==this->GetName()){
                break;
            }
            index_ins++;
        }

        list_insect_placed_modified[index_ins].SetPosition({pos_to_test[0],pos_to_test[1]});


        int ind_generic=0;
        int ind_old;
        int ind_new;


        vector<Case> list_case_modified = list_case;
        for(Case tmp : list_case_modified){
            if((tmp.Get_i()==this->Get_i())&&(tmp.Get_j()==this->Get_j())){
                ind_old=ind_generic;
            }
            else if((tmp.Get_i()==pos_to_test[0])&&(tmp.Get_j()==pos_to_test[1])){
                ind_new=ind_generic;
            }
            ind_generic++;
        }
        list_case_modified[ind_new].SetEmpty(false);
        list_case_modified[ind_old].SetEmpty(true);

        bool resultat_chain = Test_Broken_Chain(list_insect_placed_modified,list_case_modified);
        if(resultat_chain){
            index_chain.push_back(ind);
        }
        ind++;
    }

    std::sort(index_chain.begin(), index_chain.end());
    std::unique(index_chain.begin(), index_chain.end());
    for (int i=0;i<index_chain.size();i++){
        list_possible_placement_unique.erase(list_possible_placement_unique.begin()+index_chain[i]-i);
    }




    return list_possible_placement_unique;

}
