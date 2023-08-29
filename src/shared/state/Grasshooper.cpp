#include "Grasshooper.hpp"
#include "vector"
#include "BrokenChain.hpp"

#include <iostream>
#include <algorithm>
using namespace std;



state::Grasshooper::Grasshooper(std::string name, std::string color, std::vector<int> coord, int level) : Insect(name, color,
                                                                                                       coord, level) {
    Insect(this->Name = name, this->Color = color, this->Coord = coord, this->Level= level );
}





std::vector<std::vector<int>> state::Grasshooper::Possible_Deplacement_Insect(vector<Insect> list_insect_placed, vector<Case> list_case) {

    vector<int> coord = this->Coord;
    int i_depart = coord[0];
    int j_depart = coord[1];

    std::vector <std::vector<int>> list_possible_placement;

    if (j_depart % 2 == 0) {
        //DEBUT

        for (Case case_premier: list_case) {
            //*****************************************1.1********** I;J-1**********************************************//
            if ((case_premier.GetPosition()[0] == i_depart) && (case_premier.GetPosition()[1] == j_depart - 1) &&
                (case_premier.GetEmpty() == false)) {

                Case next_case = case_premier;
                while (next_case.GetEmpty() == false) {

                    if (next_case.GetPosition()[1]%2==0){

                        if ((next_case.GetPosition()[1]-1<0)||(next_case.GetPosition()[0]-1<0)){

                            break;
                        }
                        else{
                            for (Case casetemp: list_case) {
                                if ((casetemp.GetPosition()[0] == next_case.GetPosition()[0]) &&
                                    (casetemp.GetPosition()[1] == next_case.GetPosition()[1] - 1)) {

                                    next_case = casetemp;
                                    break;
                                }
                            }
                        }
                    }
                    else {

                        if ((next_case.GetPosition()[1]-1<0)||(next_case.GetPosition()[0]-1<0)){

                            break;
                        }
                        else{
                            for (Case casetemp: list_case) {
                                if ((casetemp.GetPosition()[0] == next_case.GetPosition()[0]-1) &&
                                    (casetemp.GetPosition()[1] == next_case.GetPosition()[1] - 1)) {

                                    next_case = casetemp;
                                    break;
                                }
                            }
                        }
                    }
                }
                if (next_case.GetEmpty() != false){
                    list_possible_placement.push_back(next_case.GetPosition());
                }
            }
            //***********************************************FIN 1.1****************************************************//

            //*****************************************1.2********** I;J+1**********************************************//
            if ((case_premier.GetPosition()[0] == i_depart) && (case_premier.GetPosition()[1] == j_depart + 1) &&
                (case_premier.GetEmpty() == false)) {

                Case next_case = case_premier;
                while (next_case.GetEmpty() == false) {

                    if (next_case.GetPosition()[1]%2==0){
                        if ((next_case.GetPosition()[1]+1>16)){

                            break;
                        }
                        else{
                            for (Case casetemp: list_case) {
                                if ((casetemp.GetPosition()[0] == next_case.GetPosition()[0]) &&
                                    (casetemp.GetPosition()[1] == next_case.GetPosition()[1] + 1)) {

                                    next_case = casetemp;
                                    break;
                                }
                            }
                        }
                    }
                    else {

                        if ((next_case.GetPosition()[1]+1>16)||(next_case.GetPosition()[0]-1<0)){

                            break;
                        }
                        else{
                            for (Case casetemp: list_case) {
                                if ((casetemp.GetPosition()[0] == next_case.GetPosition()[0]-1) &&
                                    (casetemp.GetPosition()[1] == next_case.GetPosition()[1]+1)) {

                                    next_case = casetemp;
                                    break;
                                }
                            }
                        }
                    }
                }
                if (next_case.GetEmpty() != false){

                    list_possible_placement.push_back(next_case.GetPosition());
                }
            }
            //***********************************************FIN 1.2****************************************************//

            //*****************************************1.3********** I-1;J**********************************************//
            if ((case_premier.GetPosition()[0] == i_depart - 1) && (case_premier.GetPosition()[1] == j_depart) &&
                (case_premier.GetEmpty() == false)) {

                Case next_case = case_premier;
                while (next_case.GetEmpty() == false) {

                        if ((next_case.GetPosition()[0]-1<0)){

                            break;
                        }
                        else{
                            for (Case casetemp: list_case) {
                                if ((casetemp.GetPosition()[0] == next_case.GetPosition()[0]-1) &&
                                    (casetemp.GetPosition()[1] == next_case.GetPosition()[1])) {

                                    next_case = casetemp;
                                    break;
                                }
                            }
                        }
                }
                if (next_case.GetEmpty() != false){

                    list_possible_placement.push_back(next_case.GetPosition());
                }
            }
            //***********************************************FIN 1.3****************************************************//

            //*****************************************1.4********** I+1;J-1**********************************************//
            if ((case_premier.GetPosition()[0] == i_depart + 1) && (case_premier.GetPosition()[1] == j_depart - 1) &&
                (case_premier.GetEmpty() == false)) {

                Case next_case = case_premier;
                while (next_case.GetEmpty() == false) {

                    if (next_case.GetPosition()[1]%2==0){

                        if ((next_case.GetPosition()[0]+1>16)||(next_case.GetPosition()[1]-1<0)){

                            break;
                        }
                        else{
                            for (Case casetemp: list_case) {
                                if ((casetemp.GetPosition()[0] == next_case.GetPosition()[0]+1) &&
                                    (casetemp.GetPosition()[1] == next_case.GetPosition()[1]-1)) {

                                    next_case = casetemp;
                                    break;
                                }
                            }
                        }
                    }
                    else {

                        if ((next_case.GetPosition()[1]-1<0)){

                            break;
                        }
                        else{
                            for (Case casetemp: list_case) {
                                if ((casetemp.GetPosition()[0] == next_case.GetPosition()[0]) &&
                                    (casetemp.GetPosition()[1] == next_case.GetPosition()[1]-1)) {

                                    next_case = casetemp;
                                    break;
                                }
                            }
                        }
                    }
                }
                if (next_case.GetEmpty() != false){

                    list_possible_placement.push_back(next_case.GetPosition());
                }
            }
            //***********************************************FIN 1.4****************************************************//

            //*****************************************1.5********** I+1;J**********************************************//
            if ((case_premier.GetPosition()[0] == i_depart + 1) && (case_premier.GetPosition()[1] == j_depart) &&
                (case_premier.GetEmpty() == false)) {

                Case next_case = case_premier;
                while (next_case.GetEmpty() == false) {

                    if (next_case.GetPosition()[1]%2==0){
                        if ((next_case.GetPosition()[0]+1>16)){

                            break;
                        }
                        else{
                            for (Case casetemp: list_case) {
                                if ((casetemp.GetPosition()[0] == next_case.GetPosition()[0]+1) &&
                                    (casetemp.GetPosition()[1] == next_case.GetPosition()[1])) {

                                    next_case = casetemp;
                                    break;
                                }
                            }
                        }
                    }
                }
                if (next_case.GetEmpty() != false){

                    list_possible_placement.push_back(next_case.GetPosition());
                }
            }
            //***********************************************FIN 1.5****************************************************//

            //*****************************************1.6********** I+1;J+1**********************************************//
            if ((case_premier.GetPosition()[0] == i_depart + 1) && (case_premier.GetPosition()[1] == j_depart + 1) &&
                (case_premier.GetEmpty() == false)) {

                Case next_case = case_premier;
                while (next_case.GetEmpty() == false) {

                    if (next_case.GetPosition()[1]%2==0){

                        if ((next_case.GetPosition()[0]+1>16)||(next_case.GetPosition()[1]+1>16)){

                            break;
                        }
                        else{
                            for (Case casetemp: list_case) {
                                if ((casetemp.GetPosition()[0] == next_case.GetPosition()[0]+1) &&
                                    (casetemp.GetPosition()[1] == next_case.GetPosition()[1]+1)) {

                                    next_case = casetemp;
                                    break;
                                }
                            }
                        }
                    }
                    else {

                        if ((next_case.GetPosition()[1]+1>16)){

                            break;
                        }
                        else{
                            for (Case casetemp: list_case) {
                                if ((casetemp.GetPosition()[0] == next_case.GetPosition()[0]) &&
                                    (casetemp.GetPosition()[1] == next_case.GetPosition()[1]+1)) {

                                    next_case = casetemp;
                                    break;
                                }
                            }
                        }
                    }
                }
                if (next_case.GetEmpty() != false){

                    list_possible_placement.push_back(next_case.GetPosition());
                }
            }
            //***********************************************FIN 1.6****************************************************//

        }
    }
    else {

        for (Case case_premier: list_case) {
            //*****************************************1.1********** I-1;J-1**********************************************//
            if ((case_premier.GetPosition()[0] == i_depart - 1) && (case_premier.GetPosition()[1] == j_depart - 1)&& (case_premier.GetEmpty() == false)) {
                Case next_case = case_premier;

                while (next_case.GetEmpty() == false) {

                    if (next_case.GetPosition()[1]%2==0){

                        if ((next_case.GetPosition()[1]-1<0)){

                            break;
                        }
                        else{
                            for (Case casetemp: list_case) {
                                if ((casetemp.GetPosition()[0] == next_case.GetPosition()[0]) &&
                                    (casetemp.GetPosition()[1] == next_case.GetPosition()[1]-1)) {

                                    next_case = casetemp;
                                    break;
                                }
                            }
                        }
                    }
                    else {

                        if ((next_case.GetPosition()[0]-1<0)||(next_case.GetPosition()[1]-1<0)){

                            break;
                        }
                        else{
                            for (Case casetemp: list_case) {
                                if ((casetemp.GetPosition()[0] == next_case.GetPosition()[0]-1) &&
                                    (casetemp.GetPosition()[1] == next_case.GetPosition()[1]-1)) {

                                    next_case = casetemp;
                                    break;
                                }
                            }
                        }
                    }
                }

                if (next_case.GetEmpty() != false){

                    list_possible_placement.push_back(next_case.GetPosition());
                }

            }
            //***********************************************FIN 1.1****************************************************//

            //*****************************************1.2********** I-1;J**********************************************//
            if ((case_premier.GetPosition()[0] == i_depart - 1) && (case_premier.GetPosition()[1] == j_depart)&& (case_premier.GetEmpty() == false)) {

                Case next_case = case_premier;
                while (next_case.GetEmpty() == false) {

                    if ((next_case.GetPosition()[0] - 1) < 0) {

                        break;
                    }
                    else {
                        for (Case casetemp: list_case) {
                            if ((casetemp.GetPosition()[0] == next_case.GetPosition()[0] - 1) &&
                                (casetemp.GetPosition()[1] == next_case.GetPosition()[1])) {

                                next_case = casetemp;
                                break;
                            }
                        }
                    }
                }

                if (next_case.GetEmpty() != false){

                    list_possible_placement.push_back(next_case.GetPosition());
                }



            }
            //***********************************************FIN 1.2****************************************************//

            //*****************************************1.3********** I-1;J+1**********************************************//
            if ((case_premier.GetPosition()[0] == i_depart - 1) && (case_premier.GetPosition()[1] == j_depart + 1)&& (case_premier.GetEmpty() == false)) {
                Case next_case = case_premier;

                while (next_case.GetEmpty() == false) {

                    if (next_case.GetPosition()[1]%2==0){

                        if ((next_case.GetPosition()[1]+1>16)){

                            break;
                        }
                        else{
                            for (Case casetemp: list_case) {
                                if ((casetemp.GetPosition()[0] == next_case.GetPosition()[0]) &&
                                    (casetemp.GetPosition()[1] == next_case.GetPosition()[1] + 1)) {

                                    next_case = casetemp;
                                    break;
                                }
                            }
                        }
                    }
                    else {

                        if ((next_case.GetPosition()[0]-1<0)||(next_case.GetPosition()[1]+1>16)){

                            break;
                        }
                        else{
                            for (Case casetemp: list_case) {
                                if ((casetemp.GetPosition()[0] == next_case.GetPosition()[0]-1) &&
                                    (casetemp.GetPosition()[1] == next_case.GetPosition()[1]+1)) {

                                    next_case = casetemp;
                                    break;
                                }
                            }
                        }
                    }
                }
                if (next_case.GetEmpty() != false){

                    list_possible_placement.push_back(next_case.GetPosition());
                }

            }
            //***********************************************FIN 1.3****************************************************//

            //*****************************************1.4********** I;J-1**********************************************//
            if ((case_premier.GetPosition()[0] == i_depart) && (case_premier.GetPosition()[1] == j_depart - 1)&& (case_premier.GetEmpty() == false)) {
                Case next_case = case_premier;

                while (next_case.GetEmpty() == false) {

                    if (next_case.GetPosition()[1]%2==0){

                        if ((next_case.GetPosition()[0]+1>16)||(next_case.GetPosition()[1]-1<0)){

                            break;
                        }
                        else{
                            for (Case casetemp: list_case) {
                                if ((casetemp.GetPosition()[0] == next_case.GetPosition()[0]+1) &&
                                    (casetemp.GetPosition()[1] == next_case.GetPosition()[1]-1)) {

                                    next_case = casetemp;
                                    break;
                                }
                            }
                        }
                    }
                    else {

                        if ((next_case.GetPosition()[1]-1<0)){

                            break;
                        }
                        else{
                            for (Case casetemp: list_case) {
                                if ((casetemp.GetPosition()[0] == next_case.GetPosition()[0]) &&
                                    (casetemp.GetPosition()[1] == next_case.GetPosition()[1]-1)) {

                                    next_case = casetemp;
                                    break;
                                }
                            }
                        }
                    }
                }
                if (next_case.GetEmpty() != false){

                    list_possible_placement.push_back(next_case.GetPosition());
                }
            }
            //***********************************************FIN 1.4****************************************************//

            //*****************************************1.5********** I;J+1**********************************************//
            if ((case_premier.GetPosition()[0] == i_depart) && (case_premier.GetPosition()[1] == j_depart + 1)&& (case_premier.GetEmpty() == false)) {
                Case next_case = case_premier;

                while (next_case.GetEmpty() == false) {

                    if (next_case.GetPosition()[1]%2==0){

                        if ((next_case.GetPosition()[0]+1>16)||(next_case.GetPosition()[1]+1>16)){

                            break;
                        }
                        else{
                            for (Case casetemp: list_case) {
                                if ((casetemp.GetPosition()[0] == next_case.GetPosition()[0]+1) &&
                                    (casetemp.GetPosition()[1] == next_case.GetPosition()[1]+1)) {

                                    next_case = casetemp;
                                    break;
                                }
                            }
                        }
                    }
                    else {

                        if ((next_case.GetPosition()[1]+1>16)){

                            break;
                        }
                        else{
                            for (Case casetemp: list_case) {
                                if ((casetemp.GetPosition()[0] == next_case.GetPosition()[0]) &&
                                    (casetemp.GetPosition()[1] == next_case.GetPosition()[1]+1)) {

                                    next_case = casetemp;
                                    break;
                                }
                            }
                        }
                    }
                }
                if (next_case.GetEmpty() != false){

                    list_possible_placement.push_back(next_case.GetPosition());
                }

            }
            //***********************************************FIN 1.5****************************************************//

            //*****************************************1.6********** I+1;J**********************************************//
            if ((case_premier.GetPosition()[0] == i_depart + 1) && (case_premier.GetPosition()[1] == j_depart)&& (case_premier.GetEmpty() == false)) {
                Case next_case = case_premier;

                while (next_case.GetEmpty() == false) {

                        if ((next_case.GetPosition()[0]+1>16)){

                            break;
                        }
                        else{
                        for (Case casetemp: list_case) {
                            if ((casetemp.GetPosition()[0] == next_case.GetPosition()[0]+1) &&
                                (casetemp.GetPosition()[1] == next_case.GetPosition()[1])) {

                                next_case = casetemp;
                                break;
                            }
                        }
                    }
                }
                if (next_case.GetEmpty() != false){

                    list_possible_placement.push_back(next_case.GetPosition());
                }
            }
            //***********************************************FIN 1.6****************************************************//
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









