#include "Spider.hpp"
#include "vector"
#include <iostream>
#include <algorithm>
#include "BrokenChain.hpp"

using namespace std;


state::Spider::Spider(std::string name, std::string color, std::vector<int> coord, int level) : Insect(name, color,
                                                                                                       coord, level) {
    Insect(this->Name = name, this->Color = color, this->Coord = coord, this->Level= level );
}


std::vector<int> state::Spider::third_x(std::vector<Case> list_case, int abs_to_look, int ord_to_look,Case case_troisieme, std::vector<std::vector<int>> list_possible_placement, int i_case1, int j_case1, int i_depart, int j_depart) {
    std::vector<int> res;
    if ((case_troisieme.GetPosition()[0] == abs_to_look) &&
        (case_troisieme.GetPosition()[1] == ord_to_look) &&
        ((case_troisieme.GetPosition()[0] != i_depart) || (case_troisieme.GetPosition()[1] != j_depart)) &&
        ((case_troisieme.GetPosition()[0] != i_case1) || (case_troisieme.GetPosition()[1] != j_case1)) &&
        (case_troisieme.GetEmpty() == true)) {

        int x = case_troisieme.GetPosition()[0];
        int y = case_troisieme.GetPosition()[1];

        //cout << "Considération de :" <<x <<" "<<y<< endl;

        if (y % 2 == 0) {
            //*************************************************PRESENCE DE VOISINS**********************************************//
            for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                    ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                    (casetemp2.GetEmpty() == false)) {//cout << "Ajout de :" <<case_troisieme.GetPosition()[0] <<" "<<case_troisieme.GetPosition()[1] << endl;
                    res=case_troisieme.GetPosition();

                } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                           ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                           (casetemp2.GetEmpty() == false)) {//cout << "Ajout de :" <<case_troisieme.GetPosition()[0] <<" "<<case_troisieme.GetPosition()[1] << endl;
                    res=case_troisieme.GetPosition();

                } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                           ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                           (casetemp2.GetEmpty() == false)) {//cout << "Ajout de :" <<case_troisieme.GetPosition()[0] <<" "<<case_troisieme.GetPosition()[1] << endl;
                    res=case_troisieme.GetPosition();

                } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                           ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                           (casetemp2.GetEmpty() == false)) {//cout << "Ajout de :" <<case_troisieme.GetPosition()[0] <<" "<<case_troisieme.GetPosition()[1] << endl;
                    res=case_troisieme.GetPosition();

                } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                           ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                           (casetemp2.GetEmpty() == false)) {//cout << "Ajout de :" <<case_troisieme.GetPosition()[0] <<" "<<case_troisieme.GetPosition()[1] << endl;
                    res=case_troisieme.GetPosition();
                } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                           ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                           (casetemp2.GetEmpty() == false)) {//cout << "Ajout de :" <<case_troisieme.GetPosition()[0] <<" "<<case_troisieme.GetPosition()[1] << endl;
                    res=case_troisieme.GetPosition();
                }
            }
        }
        else {
            //*************************************************PRESENCE DE VOISINS**********************************************//
            for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                    ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                    (casetemp2.GetEmpty() == false)) {//cout << "Ajout de :" <<case_troisieme.GetPosition()[0] <<" "<<case_troisieme.GetPosition()[1] << endl;
                    res=case_troisieme.GetPosition();
                } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                           ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                           (casetemp2.GetEmpty() == false)) {//cout << "Ajout de :" <<case_troisieme.GetPosition()[0] <<" "<<case_troisieme.GetPosition()[1] << endl;
                    res=case_troisieme.GetPosition();
                } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                           ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                           (casetemp2.GetEmpty() == false)) {//cout << "Ajout de :" <<case_troisieme.GetPosition()[0] <<" "<<case_troisieme.GetPosition()[1] << endl;
                    res=case_troisieme.GetPosition();
                } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                           ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                           (casetemp2.GetEmpty() == false)) {//cout << "Ajout de :" <<case_troisieme.GetPosition()[0] <<" "<<case_troisieme.GetPosition()[1] << endl;
                    res=case_troisieme.GetPosition();
                } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                           ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                           (casetemp2.GetEmpty() == false)) {//cout << "Ajout de :" <<case_troisieme.GetPosition()[0] <<" "<<case_troisieme.GetPosition()[1] << endl;
                    res=case_troisieme.GetPosition();
                } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                           ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                           (casetemp2.GetEmpty() == false)) {//cout << "Ajout de :" <<case_troisieme.GetPosition()[0] <<" "<<case_troisieme.GetPosition()[1] << endl;
                    res=case_troisieme.GetPosition();
                }
            }


        }
    }
    return res;
}

std::vector<std::vector<int>> state::Spider::second_x(std::vector<Case> list_case, int abs_to_look, int ord_to_look, Case case_deuxieme, std::vector<std::vector<int>> list_possible_placement,int i_case1, int j_case1, int i_depart, int j_depart) {
    std::vector<std::vector<int>> restoreturn;
    if ((case_deuxieme.GetPosition()[0] == abs_to_look) && (case_deuxieme.GetPosition()[1] == ord_to_look) &&
        ((case_deuxieme.GetPosition()[0] != i_depart) || (case_deuxieme.GetPosition()[1] != j_depart)) &&
        (case_deuxieme.GetEmpty() == true)) {
        int x = case_deuxieme.GetPosition()[0];
        int y = case_deuxieme.GetPosition()[1];

        std::vector <std::vector<int>> list_deuxieme_case;

        if (y % 2 == 0) {
            //*************************************************PRESENCE DE VOISINS**********************************************//
            for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                    ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                    (casetemp2.GetEmpty() == false)) {
                    list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                           ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                           (casetemp2.GetEmpty() == false)) {
                    list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                           ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                           (casetemp2.GetEmpty() == false)) {
                    list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                           ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                           (casetemp2.GetEmpty() == false)) {
                    list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                           ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                           (casetemp2.GetEmpty() == false)) {
                    list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                           ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                           (casetemp2.GetEmpty() == false)) {
                    list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                }
            }
        }
        else {
            for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y - 1) &&
                    ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                    (casetemp2.GetEmpty() == false)) {
                    list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y) &&
                           ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                           (casetemp2.GetEmpty() == false)) {
                    list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x - 1) && (casetemp2.GetPosition()[1] == y + 1) &&
                           ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                           (casetemp2.GetEmpty() == false)) {
                    list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) &&
                           ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                           (casetemp2.GetEmpty() == false)) {
                    list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y + 1) &&
                           ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                           (casetemp2.GetEmpty() == false)) {
                    list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) &&
                           ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) &&
                           (casetemp2.GetEmpty() == false)) {
                    list_deuxieme_case.push_back(case_deuxieme.GetPosition());
                }
            }
        }

        //******************************************PASSAGE A LA TROISIEME CASE**********************//
        if (list_deuxieme_case.size() != 0) {

            vector<int> deuxieme_case = list_deuxieme_case[0];
            int i_case2 = deuxieme_case[0];
            int j_case2 = deuxieme_case[1];

            if (j_case2 % 2 == 0) {
                for (Case case_troisieme: list_case) { //On vérifie les troisiemes cases dispos

                    //*****************************************3.1********** I;J-1**********************************************//
                    std::vector<int> res=this->third_x(list_case, i_case2, j_case2 - 1, case_troisieme, list_possible_placement, i_case1,
                                  j_case1, i_depart, j_depart);
                    if (res.size()!=0){
                        restoreturn.push_back(res);
                    }

                    //*****************************************3.2********** I;J+1**********************************************//
                     res=this->third_x(list_case, i_case2, j_case2 + 1, case_troisieme, list_possible_placement, i_case1,
                                  j_case1, i_depart, j_depart);
                    if (res.size()!=0){
                        restoreturn.push_back(res);
                    }
                    //*****************************************3.3********** I-1;J**********************************************//
                    res=this->third_x(list_case, i_case2 - 1, j_case2, case_troisieme, list_possible_placement, i_case1,
                                  j_case1, i_depart, j_depart);
                    if (res.size()!=0){
                        restoreturn.push_back(res);
                    }
                    //*****************************************3.4********** I+1;J-1**********************************************//
                     res=this->third_x(list_case, i_case2 + 1, j_case2 - 1, case_troisieme, list_possible_placement, i_case1,
                                  j_case1, i_depart, j_depart);
                    if (res.size()!=0){
                        restoreturn.push_back(res);
                    }
                    //*****************************************3.5********** I+1;J**********************************************//
                    res=this->third_x(list_case, i_case2 + 1, j_case2, case_troisieme, list_possible_placement, i_case1,
                                  j_case1, i_depart, j_depart);
                    if (res.size()!=0){
                        restoreturn.push_back(res);
                    }
                    //*****************************************3.6********** I+1;J+1**********************************************//
                     res=this->third_x(list_case, i_case2 + 1, j_case2 + 1, case_troisieme, list_possible_placement, i_case1,
                                  j_case1, i_depart, j_depart);
                    if (res.size()!=0){
                        restoreturn.push_back(res);
                    }
                }
                }
                else {
                    for (Case case_troisieme: list_case) { //On vérifie les troisiemes cases dispos

                        //*****************************************3.1********** I-1;J-1**********************************************//
                        std::vector<int> res=this->third_x(list_case, i_case2 - 1, j_case2 - 1, case_troisieme, list_possible_placement,
                                      i_case1,
                                      j_case1, i_depart, j_depart);
                        if (res.size()!=0){
                            restoreturn.push_back(res);
                        }
                        //*****************************************3.2********** I-1;J**********************************************//
                         res=this->third_x(list_case, i_case2 - 1, j_case2, case_troisieme, list_possible_placement, i_case1,
                                      j_case1, i_depart, j_depart);
                        if (res.size()!=0){
                            restoreturn.push_back(res);
                        }
                        //*****************************************3.3********** I-1;J+1**********************************************//
                        res=this->third_x(list_case, i_case2 - 1, j_case2 + 1, case_troisieme, list_possible_placement,
                                      i_case1,
                                      j_case1, i_depart, j_depart);
                        if (res.size()!=0){
                            restoreturn.push_back(res);
                        }
                        //*****************************************3.4********** I;J-1**********************************************//
                        res=this->third_x(list_case, i_case2, j_case2 - 1, case_troisieme, list_possible_placement, i_case1,
                                      j_case1, i_depart, j_depart);
                        if (res.size()!=0){
                            restoreturn.push_back(res);
                        }
                        //*****************************************3.5********** I;J+1**********************************************//
                         res=this->third_x(list_case, i_case2, j_case2 + 1, case_troisieme, list_possible_placement, i_case1,
                                      j_case1, i_depart, j_depart);
                        if (res.size()!=0){
                            restoreturn.push_back(res);
                        }
                        //*****************************************3.6********** I+1;J**********************************************//
                         res=this->third_x(list_case, i_case2 + 1, j_case2, case_troisieme, list_possible_placement, i_case1,
                                      j_case1, i_depart, j_depart);
                        if (res.size()!=0){
                            restoreturn.push_back(res);
                        }
                    }
                }
            }
        }
        return restoreturn;

    }

std::vector<std::vector<int>> state::Spider::first_x (std::vector<Case> list_case, int abs_to_look, int ord_to_look, Case case_premier, std::vector<std::vector<int>> list_possible_placement, int i_depart, int j_depart){
    std::vector<std::vector<int>> restoreturn;
    if((case_premier.GetPosition()[0]==abs_to_look)&&(case_premier.GetPosition()[1]==ord_to_look)&&(case_premier.GetEmpty()== true)) {
        int x = case_premier.GetPosition()[0];
        int y = case_premier.GetPosition()[1];

        std::vector<std::vector<int>> list_premiere_case;


        if (y%2==0){
            //*************************************************PRESENCE DE VOISINS**********************************************//
            for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y-1) && ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                    list_premiere_case.push_back(case_premier.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x ) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                    list_premiere_case.push_back(case_premier.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x-1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                    list_premiere_case.push_back(case_premier.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x+1) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                    list_premiere_case.push_back(case_premier.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y) && ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                    list_premiere_case.push_back(case_premier.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y + 1) && ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                    list_premiere_case.push_back(case_premier.GetPosition());
                }
            }
        }
        else {

            for (Case casetemp2: list_case) { //On vérifie si la case trouvée est voisine d'un autre insecte
                if ((casetemp2.GetPosition()[0] == x-1) && (casetemp2.GetPosition()[1] == y-1) && ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                    list_premiere_case.push_back(case_premier.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x-1) && (casetemp2.GetPosition()[1] == y ) && ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart)) && (casetemp2.GetEmpty() == false)) {
                    list_premiere_case.push_back(case_premier.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x-1) && (casetemp2.GetPosition()[1] == y+1) && ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                    list_premiere_case.push_back(case_premier.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x) && (casetemp2.GetPosition()[1] == y - 1) && ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                    list_premiere_case.push_back(case_premier.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x ) && (casetemp2.GetPosition()[1] == y+1) && ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                    list_premiere_case.push_back(case_premier.GetPosition());
                } else if ((casetemp2.GetPosition()[0] == x + 1) && (casetemp2.GetPosition()[1] == y ) && ((casetemp2.GetPosition()[0] != i_depart) || (casetemp2.GetPosition()[1] != j_depart))&& (casetemp2.GetEmpty() == false)) {
                    list_premiere_case.push_back(case_premier.GetPosition());
                }
            }

        }


        //******************************************PASSAGE A LA DEUXIEME CASE**********************//
        if (list_premiere_case.size()!=0){

            vector<int> premiere_case=list_premiere_case[0];
            int i_case1=premiere_case[0];
            int j_case1 = premiere_case[1];

            if (j_case1 % 2 ==0){
                for (Case case_deuxieme:list_case) { //On vérifie les deuxièmes cases dispos

                    //*****************************************2.1********** I;J-1**********************************************//
                    std::vector<std::vector<int>> res=this->second_x(list_case,i_case1, j_case1-1,case_deuxieme,list_possible_placement, i_case1, j_case1, i_depart, j_depart);
                    if (res.size()!=0){
                        for (std::vector<int> temp : res){
                            restoreturn.push_back(temp);
                        }
                    }
                    //***********************************************FIN 2.1****************************************************//

                   //*****************************************2.2********** I;J+1**********************************************//
                    res=this->second_x(list_case,i_case1, j_case1+1,case_deuxieme,list_possible_placement, i_case1, j_case1, i_depart, j_depart);
                    if (res.size()!=0){
                        for (std::vector<int> temp : res){
                            restoreturn.push_back(temp);
                        }
                    }
                    //***********************************************FIN 2.2****************************************************//

                   //*****************************************2.3********** I-1;J**********************************************//
                     res=this->second_x(list_case,i_case1-1, j_case1,case_deuxieme,list_possible_placement, i_case1, j_case1, i_depart, j_depart);
                    if (res.size()!=0){
                        for (std::vector<int> temp : res){
                            restoreturn.push_back(temp);
                        }
                    }
                    //***********************************************FIN 2.3****************************************************//

                   //*****************************************2.4********** I+1;J-1**********************************************//
                     res=this->second_x(list_case,i_case1+1, j_case1-1,case_deuxieme,list_possible_placement, i_case1, j_case1, i_depart, j_depart);
                    if (res.size()!=0){
                        for (std::vector<int> temp : res){
                            restoreturn.push_back(temp);
                        }
                    }
                    //***********************************************FIN 2.4****************************************************//

                    //*****************************************2.5********** I+1;J**********************************************//
                     res=this->second_x(list_case,i_case1+1, j_case1,case_deuxieme,list_possible_placement, i_case1, j_case1, i_depart, j_depart);
                    if (res.size()!=0){
                        for (std::vector<int> temp : res){
                            restoreturn.push_back(temp);
                        }
                    }
                    //***********************************************FIN 2.5****************************************************//

                    //*****************************************2.6********** I+1;J+1**********************************************//
                    res=this->second_x(list_case,i_case1+1, j_case1+1,case_deuxieme,list_possible_placement, i_case1, j_case1, i_depart, j_depart);
                    if (res.size()!=0){
                        for (std::vector<int> temp : res){
                            restoreturn.push_back(temp);
                        }
                    }
                    //***********************************************FIN 2.6****************************************************//

                }
            }
            else {
                for (Case case_deuxieme:list_case) { //On vérifie les deuxièmes cases dispos

                    //*****************************************2.1********** I-1;J-1**********************************************//
                    std::vector<std::vector<int>> res=this->second_x(list_case,i_case1-1, j_case1-1,case_deuxieme,list_possible_placement, i_case1, j_case1, i_depart, j_depart);
                    if (res.size()!=0){
                        for (std::vector<int> temp : res){
                            restoreturn.push_back(temp);
                        }
                    }
                    //***********************************************FIN 2.1****************************************************//

                    //*****************************************2.2********** I-1;J**********************************************//
                     res=this->second_x(list_case,i_case1-1, j_case1,case_deuxieme,list_possible_placement, i_case1, j_case1, i_depart, j_depart);
                    if (res.size()!=0){
                        for (std::vector<int> temp : res){
                            restoreturn.push_back(temp);
                        }
                    }//***********************************************FIN 2.2****************************************************//

                    //*****************************************2.3********** I-1;J+1**********************************************//
                     res=this->second_x(list_case,i_case1-1, j_case1+1,case_deuxieme,list_possible_placement, i_case1, j_case1, i_depart, j_depart);
                    if (res.size()!=0){
                        for (std::vector<int> temp : res){
                            restoreturn.push_back(temp);
                        }
                    }//***********************************************FIN 2.3****************************************************//

                    //*****************************************2.4********** I;J-1**********************************************//
                     res=this->second_x(list_case,i_case1, j_case1-1,case_deuxieme,list_possible_placement, i_case1,  j_case1, i_depart, j_depart);
                    if (res.size()!=0){
                        for (std::vector<int> temp : res){
                            restoreturn.push_back(temp);
                        }
                    }//***********************************************FIN 2.4****************************************************//

                    //*****************************************2.5********** I;J+1**********************************************//
                    res=this->second_x(list_case,i_case1, j_case1+1,case_deuxieme,list_possible_placement, i_case1, j_case1, i_depart, j_depart);
                    if (res.size()!=0){
                        for (std::vector<int> temp : res){
                            restoreturn.push_back(temp);
                        }
                    }//***********************************************FIN 2.5****************************************************//

                    //*****************************************2.6********** I+1;J**********************************************//
                    res=this->second_x(list_case,i_case1+1, j_case1,case_deuxieme,list_possible_placement, i_case1, j_case1, i_depart, j_depart);
                    if (res.size()!=0){
                        for (std::vector<int> temp : res){
                            restoreturn.push_back(temp);
                        }
                    }//***********************************************FIN 2.6****************************************************//

                }
            }

        }
    }
    return restoreturn;

}

std::vector<std::vector<int>> state::Spider::Possible_Deplacement_Insect(vector<Insect> list_insect_placed, vector<Case> list_case) {

    vector<int> coord = this->Coord;
    int i_depart = coord[0];
    int j_depart = coord[1];

    std::vector<std::vector<int>> list_possible_placement;
    //cout << "Début : Case de départ :" <<i_depart <<" " << j_depart<< endl;

    if (j_depart%2==0){
        //DEBUT
        for (Case case_premier:list_case) { //On vérifie les premières cases dispos

            //*****************************************1.1********** I;J-1**********************************************//
            std::vector<std::vector<int>> res=this->first_x(list_case,i_depart, j_depart-1,case_premier,list_possible_placement, i_depart, j_depart);
            if (res.size()!=0){
                for (std::vector<int> temp : res){
                    list_possible_placement.push_back(temp);
                }
            }
            //***********************************************FIN 1.1****************************************************//

            //*****************************************1.2********** I;J+1**********************************************//
            res=this->first_x(list_case,i_depart, j_depart+1,case_premier,list_possible_placement, i_depart, j_depart);
            if (res.size()!=0){
                for (std::vector<int> temp : res){
                    list_possible_placement.push_back(temp);
                }
            }
            //***********************************************FIN 1.2****************************************************//

            //*****************************************1.3********** I-1;J**********************************************//
            res=this->first_x(list_case,i_depart-1, j_depart,case_premier,list_possible_placement, i_depart, j_depart);
            if (res.size()!=0){
                for (std::vector<int> temp : res){
                    list_possible_placement.push_back(temp);
                }
            }
            //***********************************************FIN 1.3****************************************************//

            //*****************************************1.4********** I+1;J-1**********************************************//
            res=this->first_x(list_case,i_depart+1, j_depart-1,case_premier,list_possible_placement, i_depart, j_depart);
            if (res.size()!=0){
                for (std::vector<int> temp : res){
                    list_possible_placement.push_back(temp);
                }
            }
            //***********************************************FIN 1.4****************************************************//

            //*****************************************1.5********** I+1;J**********************************************//
            res=this->first_x(list_case,i_depart+1, j_depart,case_premier,list_possible_placement, i_depart, j_depart);
            if (res.size()!=0){
                for (std::vector<int> temp : res){
                    list_possible_placement.push_back(temp);
                }
            }
            //***********************************************FIN 1.5****************************************************//

            //*****************************************1.6********** I+1;J+1**********************************************//
            res=this->first_x(list_case,i_depart+1, j_depart+1,case_premier,list_possible_placement, i_depart, j_depart);
            if (res.size()!=0){
                for (std::vector<int> temp : res){
                    list_possible_placement.push_back(temp);
                }
            }
            //***********************************************FIN 1.6****************************************************//

        }
    }
    else{
        for (Case case_premier:list_case) { //On vérifie les premières cases dispos

            //*****************************************1.1********** I-1;J-1**********************************************//
            std::vector<std::vector<int>> res=this->first_x(list_case,i_depart-1, j_depart-1,case_premier,list_possible_placement, i_depart, j_depart);
            if (res.size()!=0){
                for (std::vector<int> temp : res){
                    list_possible_placement.push_back(temp);
                }
            }
            //***********************************************FIN 1.1****************************************************//

            //*****************************************1.2********** I-1;J**********************************************//
            res=this->first_x(list_case,i_depart-1, j_depart,case_premier,list_possible_placement, i_depart, j_depart);
            if (res.size()!=0){
                for (std::vector<int> temp : res){
                    list_possible_placement.push_back(temp);
                }
            }
            //***********************************************FIN 1.2****************************************************//

            //*****************************************1.3********** I-1;J+1**********************************************//
            res=this->first_x(list_case,i_depart-1, j_depart+1,case_premier,list_possible_placement, i_depart, j_depart);
            if (res.size()!=0){
                for (std::vector<int> temp : res){
                    list_possible_placement.push_back(temp);
                }
            }
            //***********************************************FIN 1.3****************************************************//

            //*****************************************1.4********** I;J-1**********************************************//
            res=this->first_x(list_case,i_depart, j_depart-1,case_premier,list_possible_placement, i_depart, j_depart);
            if (res.size()!=0){
                for (std::vector<int> temp : res){
                    list_possible_placement.push_back(temp);
                }
            }
            //***********************************************FIN 1.4****************************************************//

            //*****************************************1.5********** I;J+1**********************************************//
            res=this->first_x(list_case,i_depart, j_depart+1,case_premier,list_possible_placement, i_depart, j_depart);
            if (res.size()!=0){
                for (std::vector<int> temp : res){
                    list_possible_placement.push_back(temp);
                }
            }
            //***********************************************FIN 1.5****************************************************//

            //*****************************************1.6********** I+1;J**********************************************//
            res=this->first_x(list_case,i_depart+1, j_depart,case_premier,list_possible_placement, i_depart, j_depart);
            if (res.size()!=0){
                for (std::vector<int> temp : res){
                    list_possible_placement.push_back(temp);
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
