#include "HeuristicAI.hpp"
#include "state.hpp"
#include "iostream"
#include "random"
#include <engine.hpp>
#include <cstdlib>

using namespace std;
using namespace state;

ai::HeuristicAI::HeuristicAI(state::Game& game, std::string color) : AI(game,color) {
    this->ai=&game;
    this->player_a=true;
    this->color=color;
}

std::vector<int> ai::HeuristicAI::runAI() {

    std::string myBee;
    std::string notMyBee;
    if(this->color == "White"){
        myBee = "Bee_B";
        notMyBee = "Bee_A";
    }else if(this->color == "Black"){
        myBee = "Bee_A";
        notMyBee = "Bee_B";
    }


    cout<<"L'IA HEURISTIQUE JOUE !"<<endl;

    vector<int> result;

    vector<Case> list_case;
    for (int i = 0; i < ai->GetMap()->GetLength(); i++) {
        for (int j = 0; j < ai->GetMap()->GetWidth(); j++) {
            list_case.push_back(ai->GetMap()->GetListCase()[i][j]);
        }
    }

    //ON PLACE L'ABEILLE AU PREMIER TOUR
    if(this->ai->GetIteration()==0){
        int bee_index=0;
        vector<vector<int>> temp_coord;
        for(auto bee_to_find : this->ai->GetAllInsects()){
            if(bee_to_find->GetName()==myBee){
                cout<<"PREMIER TOUR DONC ON POSE L'ABEILLE"<<endl;

                temp_coord =bee_to_find->Possible_Placement_Insect(ai->GetAllInsect_placed(), list_case);
                int random_coord=rand()%(temp_coord.size()-1);
                auto choice_coord = temp_coord[random_coord];

                result.push_back(0);
                result.push_back(choice_coord[0]);
                result.push_back(choice_coord[1]);
                result.push_back(bee_index);
                cout<<"L'IA HEURISTIQUE A FAIT SON CHOIX !"<<endl;
                return result;
            }
        bee_index++;
        }
    }


    //DEPLACEMENT DE L'ABEILLE SI ELLE A 5 VOISINS
    if(BeeNeighbour()==5){
        int bee_index=0;
        vector<vector<int>> temp_coord;
        for(auto bee_to_find : this->ai->GetAllInsects()){
            if(bee_to_find->GetName()=="myBee"){
                srand((unsigned int)time(0));


                temp_coord =bee_to_find->Possible_Deplacement_Insect(ai->GetAllInsect_placed(), list_case);
                int random_coord=rand()%(temp_coord.size());
                auto choice_coord = temp_coord[random_coord];

                result.push_back(1);
                result.push_back(choice_coord[0]);
                result.push_back(choice_coord[1]);
                result.push_back(bee_index);
                cout<<"L'IA HEURISTIQUE A FAIT SON CHOIX !"<<endl;
                return result;
            }
            bee_index++;
        }

    }


    //ON PLACE UN PION SI L'ABEILLE ADVERSE N'EST PAS PLACEE
    int bee_index=0;
    vector<vector<int>> temp_coord;
    for(auto bee_to_find : this->ai->GetAllInsects()){
        if((bee_to_find->GetName()==notMyBee)&&(!bee_to_find->GetIsPlaced())){

            vector<int> list_choice_insect;
            int i = 0;
            int index_insect;


            for (auto &ins: this->ai->GetAllInsects()) {
                if ((ins->GetColor() == this->color)&&(ins->GetIsPlaced()==0)) {
                    list_choice_insect.push_back(i);
                }
                i++;
            }


            vector<vector<int>> temp_coord;

            while (temp_coord.size() == 0) {

                srand((unsigned int)time(0));
                int random_choice_insect=rand()%(list_choice_insect.size());
                index_insect=list_choice_insect[random_choice_insect];

                auto choice_insect = ai->GetAllInsects()[list_choice_insect[random_choice_insect]];

                temp_coord = choice_insect->Possible_Placement_Insect(ai->GetAllInsect_placed(), list_case);

            }

            int random_coord=rand()%(temp_coord.size());
            auto choice_coord = temp_coord[random_coord];

            result.push_back(0);
            result.push_back(choice_coord[0]);
            result.push_back(choice_coord[1]);
            result.push_back(index_insect);
            cout<<"L'IA HEURISTIQUE A FAIT SON CHOIX !"<<endl;
            return result;
        }
    }


    //TENTATIVE D'ATTEINDRE L'ABEILLE ADVERSE
    //On liste d'abord les insectes qui ne sont pas adjacents à l'abeille adverse

    vector<Insect> InsectsToMove = GetInsectsToMove();
    int index_insect;
    if(InsectsToMove.size()==0){
        //ON PLACE UN PION AU HASARD

        cout<<"Aucun insecte n'est pas lié à l'abeille adv"<<endl;
        int bee_index=0;
                vector<int> list_choice_insect;
                int i = 0;
                int index_insect;


                for (auto &ins: this->ai->GetAllInsects()) {
                    if ((ins->GetColor() == this->color)&&(ins->GetIsPlaced()==0)) {
                        list_choice_insect.push_back(i);
                    }
                    i++;
                }


                vector<vector<int>> temp_coord;

                while (temp_coord.size() == 0) {

                    srand((unsigned int)time(0));
                    int random_choice_insect=rand()%(list_choice_insect.size());
                    index_insect=list_choice_insect[random_choice_insect];

                    auto choice_insect = ai->GetAllInsects()[list_choice_insect[random_choice_insect]];

                    temp_coord = choice_insect->Possible_Placement_Insect(ai->GetAllInsect_placed(), list_case);

                }

                int random_coord=rand()%(temp_coord.size());
                auto choice_coord = temp_coord[random_coord];

                result.push_back(0);
                result.push_back(choice_coord[0]);
                result.push_back(choice_coord[1]);
                result.push_back(index_insect);
        cout<<"L'IA HEURISTIQUE A FAIT SON CHOIX !"<<endl;
                return result;
            }

    else {
        //ON DOIT COMPARER QUEL DEPLACEMENT EST MEILLEUR QUE LES AUTRES
        cout << "COMPARAISON DES COUPS" << endl;

        //Recuperation des coordonnes à combler autour de l'abeille adverse
        cout << "COORD AUTOUR DE BEE_B" << endl;
        vector<vector<int>> coord_neigh_bee_white;
        for (auto bee_adv: ai->GetAllInsect_placed()) {
            if (bee_adv.GetName() == notMyBee) {
                int i_bee = bee_adv.Get_i();
                int j_bee = bee_adv.Get_j();

                if (j_bee % 2 == 0) {
                    for (Case casetemp: list_case) {
                        if ((casetemp.GetPosition()[0] == i_bee) && (casetemp.GetPosition()[1] == j_bee - 1) &&
                            (casetemp.GetEmpty() == true)) {
                            coord_neigh_bee_white.push_back(casetemp.GetPosition());

                        } else if ((casetemp.GetPosition()[0] == i_bee) && (casetemp.GetPosition()[1] == j_bee + 1) &&
                                   (casetemp.GetEmpty() == true)) {
                            coord_neigh_bee_white.push_back(casetemp.GetPosition());

                        } else if ((casetemp.GetPosition()[0] == i_bee - 1) && (casetemp.GetPosition()[1] == j_bee) &&
                                   (casetemp.GetEmpty() == true)) {
                            coord_neigh_bee_white.push_back(casetemp.GetPosition());

                        } else if ((casetemp.GetPosition()[0] == i_bee + 1) &&
                                   (casetemp.GetPosition()[1] == j_bee - 1) && (casetemp.GetEmpty() == true)) {
                            coord_neigh_bee_white.push_back(casetemp.GetPosition());

                        } else if ((casetemp.GetPosition()[0] == i_bee + 1) && (casetemp.GetPosition()[1] == j_bee) &&
                                   (casetemp.GetEmpty() == true)) {
                            coord_neigh_bee_white.push_back(casetemp.GetPosition());

                        } else if ((casetemp.GetPosition()[0] == i_bee + 1) &&
                                   (casetemp.GetPosition()[1] == j_bee + 1) && (casetemp.GetEmpty() == true)) {
                            coord_neigh_bee_white.push_back(casetemp.GetPosition());

                        }
                    }
                } else {
                    for (Case casetemp: list_case) {
                        if ((casetemp.GetPosition()[0] == i_bee - 1) && (casetemp.GetPosition()[1] == j_bee) &&
                            (casetemp.GetEmpty() == true)) {
                            coord_neigh_bee_white.push_back(casetemp.GetPosition());

                        } else if ((casetemp.GetPosition()[0] == i_bee - 1) &&
                                   (casetemp.GetPosition()[1] == j_bee + 1) && (casetemp.GetEmpty() == true)) {
                            coord_neigh_bee_white.push_back(casetemp.GetPosition());

                        } else if ((casetemp.GetPosition()[0] == i_bee) && (casetemp.GetPosition()[1] == j_bee - 1) &&
                                   (casetemp.GetEmpty() == true)) {
                            coord_neigh_bee_white.push_back(casetemp.GetPosition());

                        } else if ((casetemp.GetPosition()[0] == i_bee) && (casetemp.GetPosition()[1] == j_bee + 1) &&
                                   (casetemp.GetEmpty() == true)) {
                            coord_neigh_bee_white.push_back(casetemp.GetPosition());

                        } else if ((casetemp.GetPosition()[0] == i_bee + 1) && (casetemp.GetPosition()[1] == j_bee) &&
                                   (casetemp.GetEmpty() == true)) {
                            coord_neigh_bee_white.push_back(casetemp.GetPosition());

                        } else if ((casetemp.GetPosition()[0] == i_bee - 1) &&
                                   (casetemp.GetPosition()[1] == j_bee - 1) && (casetemp.GetEmpty() == true)) {
                            coord_neigh_bee_white.push_back(casetemp.GetPosition());

                        }
                    }
                }

            }
        }

        cout << "FIN DE COORD AUTOUR DE BEE_B" << endl;

        vector<vector<int>> list_coord_to_test;
        vector<Insect> list_ins_placed = ai->GetAllInsect_placed();
        for (auto ins_moving: InsectsToMove) {
            for (auto choice_ins: ai->GetAllInsects()) {

                if (choice_ins->GetName() == ins_moving.GetName()){

                    cout << "[AI HEURI] TEST POUR L'INSECTE :" << choice_ins->GetName() << endl;


                cout << "Calcul des coords pour l'insecte à bouger" << endl;
                list_coord_to_test = choice_ins->Possible_Deplacement_Insect(list_ins_placed, list_case);
                cout << "Fin des calculs des coords pour l'insecte à bouger" << endl;

                if (list_coord_to_test.size() == 0) { cout << "LISTE VIDE" << endl; }
                else {

                    cout << "ON ETUDIE LES CAS OU L'ABEILLE PEUT ETRE TOUCHEE" << endl;
                    for (auto coord_to_test: list_coord_to_test) {
                        cout << "Coord à test : [ " << coord_to_test[0] << " , " << coord_to_test[1] << " ]" << endl;
                        for (auto neigh_bee: coord_neigh_bee_white) {
                            cout << "Voisin d'abeille dispo : [ " << neigh_bee[0] << " , " << neigh_bee[1] << " ]"
                                 << endl;
                            //Si l'insecte qui bouge peut aller à cote de l'abeille adv, on déplace
                            if ((coord_to_test[0] == neigh_bee[0]) && (coord_to_test[1] == neigh_bee[1])) {
                                cout << "UN CAS MATCH !" << endl;

                                int insect_index = 0;
                                for (auto ins: this->ai->GetAllInsects()) {
                                    if (ins->GetName() == ins_moving.GetName()) {
                                        break;
                                    }
                                    insect_index++;
                                }


                                result.push_back(1);
                                result.push_back(coord_to_test[0]);
                                result.push_back(coord_to_test[1]);
                                result.push_back(insect_index);
                                cout << "L'IA HEURISTIQUE A FAIT SON CHOIX !" << endl;
                                return result;
                            }
                        }

                    }

                }
            }
        }
    }

        //Si on arrive ici, c'est qu'aucun insecte ne peut aller à coté de l'abeille adverse. Donc on va faire un random


        cout<<"AUCUN INSECTE NE PEUT ALLER AUTOUR DE L'ABEILLE WHITE"<<endl;
        vector<int> list_insect_remaining;
        int index_remain = 0;

        for (auto ins: this->ai->GetAllInsects()) {
            if ((ins->GetColor() == this->color)&&(ins->GetIsPlaced()==0)) {
                list_insect_remaining.push_back(index_remain);
            }
            index_remain++;
        }

        if(list_insect_remaining.size()!=0){
            //PLACEMENT
            cout<<"PLACEMENT"<<endl;

            while (temp_coord.size() == 0) {

                srand((unsigned int)time(0));
                int random_choice_insect=rand()%(list_insect_remaining.size());
                index_insect=list_insect_remaining[random_choice_insect];

                auto choice_insect = ai->GetAllInsects()[list_insect_remaining[random_choice_insect]];

                temp_coord = choice_insect->Possible_Placement_Insect(ai->GetAllInsect_placed(),list_case);

            }


            int random_coord=rand()%(temp_coord.size());
            auto choice_coord = temp_coord[random_coord];

            result.push_back(0);
            result.push_back(choice_coord[0]);
            result.push_back(choice_coord[1]);
            result.push_back(index_insect);
            cout<<"L'IA HEURISTIQUE A FAIT SON CHOIX !"<<endl;
            return result;

        }

        else{
            //DEPLACEMENT
            cout<<"DEPLACEMENT"<<endl;
            vector<int> list_choice_insect;
            int i = 0;


            for (auto &ins: this->ai->GetAllInsects()) {
                for (auto ins_to_test: InsectsToMove) {
                    if ((ins->GetColor() == this->color)&&(ins->GetName()==ins_to_test.GetName())) {
                        list_choice_insect.push_back(i);
                        break;
                    }
                }
                i++;
            }

            while (temp_coord.size() == 0) {

                srand((unsigned int)time(0));
                int random_choice_insect=rand()%(list_choice_insect.size());
                index_insect=list_choice_insect[random_choice_insect];

                auto choice_insect = ai->GetAllInsects()[list_choice_insect[random_choice_insect]];

                vector<Case> list_case;
                for (int i = 0; i < ai->GetMap()->GetLength(); i++) {
                    for (int j = 0; j < ai->GetMap()->GetWidth(); j++) {
                        list_case.push_back(ai->GetMap()->GetListCase()[i][j]);
                    }
                }

                temp_coord = choice_insect->Possible_Deplacement_Insect(ai->GetAllInsect_placed(),list_case);

            }


            int random_coord=rand()%(temp_coord.size());
            auto choice_coord = temp_coord[random_coord];

            result.push_back(1);
            result.push_back(choice_coord[0]);
            result.push_back(choice_coord[1]);
            result.push_back(index_insect);
            cout<<"L'IA HEURISTIQUE A FAIT SON CHOIX !"<<endl;
            return result;

        }
        }


    return result;
}

int ai::HeuristicAI::BeeNeighbour() {

    std::string myBee;
    std::string notMyBee;
    if(this->color == "White"){
        myBee = "Bee_B";
        notMyBee = "Bee_A";
    }else if(this->color == "Black"){
        myBee = "Bee_A";
        notMyBee = "Bee_B";
    }

    std::cout<<"ENTREE DANS BEENEIGHBOUR!"<<endl;
    int neighbour=0;

    vector<Case> list_case;
    for (int i = 0; i < ai->GetMap()->GetLength(); i++) {
        for (int j = 0; j < ai->GetMap()->GetWidth(); j++) {
            list_case.push_back(ai->GetMap()->GetListCase()[i][j]);
        }
    }


    for(auto bee_to_find : this->ai->GetAllInsects()){
        if(bee_to_find->GetName()== myBee) {
            int i_depart = bee_to_find->Get_i();
            int j_depart = bee_to_find->Get_j();
            //Parité de la colonne
            if (j_depart % 2 == 0) {

                for (Case casetemp: list_case) {

                    if ((casetemp.GetPosition()[0] == i_depart) && (casetemp.GetPosition()[1] == j_depart - 1) &&
                        (casetemp.GetEmpty() == false)) {

                        neighbour++;
                    }
                    if ((casetemp.GetPosition()[0] == i_depart) && (casetemp.GetPosition()[1] == j_depart + 1) &&
                        (casetemp.GetEmpty() == false)) {


                        neighbour++;
                    }
                    if ((casetemp.GetPosition()[0] == i_depart - 1) && (casetemp.GetPosition()[1] == j_depart) &&
                        (casetemp.GetEmpty() == false)) {


                        neighbour++;
                    }
                    if ((casetemp.GetPosition()[0] == i_depart + 1) && (casetemp.GetPosition()[1] == j_depart - 1) &&
                        (casetemp.GetEmpty() == false)) {


                        neighbour++;
                    }
                    if ((casetemp.GetPosition()[0] == i_depart + 1) && (casetemp.GetPosition()[1] == j_depart) &&
                        (casetemp.GetEmpty() == false)) {


                        neighbour++;
                    }
                    if ((casetemp.GetPosition()[0] == i_depart + 1) && (casetemp.GetPosition()[1] == j_depart + 1) &&
                        (casetemp.GetEmpty() == false)) {


                        neighbour++;
                    }
                }
            }
            else {

                for (Case casetemp: list_case) {

                    if ((casetemp.GetPosition()[0] == i_depart - 1) && (casetemp.GetPosition()[1] == j_depart - 1) &&
                        (casetemp.GetEmpty() == false)) {

                        neighbour++;
                    }
                    if ((casetemp.GetPosition()[0] == i_depart - 1) && (casetemp.GetPosition()[1] == j_depart) &&
                        (casetemp.GetEmpty() == false)) {

                        neighbour++;
                    }
                    if ((casetemp.GetPosition()[0] == i_depart - 1) && (casetemp.GetPosition()[1] == j_depart + 1) &&
                        (casetemp.GetEmpty() == false)) {

                        neighbour++;
                    }
                    if ((casetemp.GetPosition()[0] == i_depart) && (casetemp.GetPosition()[1] == j_depart - 1) &&
                        (casetemp.GetEmpty() == false)) {

                        neighbour++;
                    }
                    if ((casetemp.GetPosition()[0] == i_depart) && (casetemp.GetPosition()[1] == j_depart + 1) &&
                        (casetemp.GetEmpty() == false)) {

                        neighbour++;
                    }
                    if ((casetemp.GetPosition()[0] == i_depart + 1) && (casetemp.GetPosition()[1] == j_depart) &&
                        (casetemp.GetEmpty() == false)) {

                        neighbour++;
                    }
                }
            }
        }
    }


    cout<<"SORTIE DE BEENEIGHBOUR avec le résultat : "<<neighbour<<endl;
    return neighbour;
}



std::vector<state::Insect> ai::HeuristicAI::GetInsectsToMove() {

    std::string myBee;
    std::string notMyBee;
    if(this->color == "White"){
        myBee = "Bee_B";
        notMyBee = "Bee_A";
    }else if(this->color == "Black"){
        myBee = "Bee_A";
        notMyBee = "Bee_B";
    }


    cout<<"ENTREE DANS GETINSECTSTOMOVE!"<<endl;
    vector<Insect> result;
    vector<vector<int>> coord_neigh_bee_white;


    vector<Case> list_case;
    for (int i = 0; i < ai->GetMap()->GetLength(); i++) {
        for (int j = 0; j < ai->GetMap()->GetWidth(); j++) {
            list_case.push_back(ai->GetMap()->GetListCase()[i][j]);
        }
    }


    for(auto bee_adv : ai->GetAllInsect_placed()){
        if(bee_adv.GetName()== notMyBee){
            int i_bee = bee_adv.Get_i();
            int j_bee = bee_adv.Get_j();

            if (j_bee%2==0){
                for (Case casetemp:list_case){
                    if((casetemp.GetPosition()[0]==i_bee)&&(casetemp.GetPosition()[1]==j_bee-1)&&(casetemp.GetEmpty()== false)){
                        coord_neigh_bee_white.push_back(casetemp.GetPosition());

                    }
                    else if((casetemp.GetPosition()[0]==i_bee)&&(casetemp.GetPosition()[1]==j_bee+1)&&(casetemp.GetEmpty()== false)){
                        coord_neigh_bee_white.push_back(casetemp.GetPosition());
                    }
                    else if ((casetemp.GetPosition()[0]==i_bee-1)&&(casetemp.GetPosition()[1]==j_bee)&&(casetemp.GetEmpty()== false)){
                        coord_neigh_bee_white.push_back(casetemp.GetPosition());
                    }
                    else if ((casetemp.GetPosition()[0]==i_bee+1)&&(casetemp.GetPosition()[1]==j_bee-1)&&(casetemp.GetEmpty()== false)){
                        coord_neigh_bee_white.push_back(casetemp.GetPosition());
                    }
                    else if ((casetemp.GetPosition()[0]==i_bee+1)&&(casetemp.GetPosition()[1]==j_bee)&&(casetemp.GetEmpty()== false)){
                        coord_neigh_bee_white.push_back(casetemp.GetPosition());
                    }
                    else if ((casetemp.GetPosition()[0]==i_bee+1)&&(casetemp.GetPosition()[1]==j_bee+1)&&(casetemp.GetEmpty()== false)){
                        coord_neigh_bee_white.push_back(casetemp.GetPosition());
                    }
                }
            }
            else {
                for (Case casetemp:list_case){
                    if((casetemp.GetPosition()[0]==i_bee-1)&&(casetemp.GetPosition()[1]==j_bee)&&(casetemp.GetEmpty()== false)){
                        coord_neigh_bee_white.push_back(casetemp.GetPosition());
                    }
                    else if((casetemp.GetPosition()[0]==i_bee-1)&&(casetemp.GetPosition()[1]==j_bee+1)&&(casetemp.GetEmpty()== false)){
                        coord_neigh_bee_white.push_back(casetemp.GetPosition());
                    }
                    else if ((casetemp.GetPosition()[0]==i_bee)&&(casetemp.GetPosition()[1]==j_bee-1)&&(casetemp.GetEmpty()== false)){
                        coord_neigh_bee_white.push_back(casetemp.GetPosition());
                    }
                    else if ((casetemp.GetPosition()[0]==i_bee)&&(casetemp.GetPosition()[1]==j_bee+1)&&(casetemp.GetEmpty()== false)){
                        coord_neigh_bee_white.push_back(casetemp.GetPosition());
                    }
                    else if ((casetemp.GetPosition()[0]==i_bee+1)&&(casetemp.GetPosition()[1]==j_bee)&&(casetemp.GetEmpty()== false)){
                        coord_neigh_bee_white.push_back(casetemp.GetPosition());
                    }
                    else if ((casetemp.GetPosition()[0]==i_bee-1)&&(casetemp.GetPosition()[1]==j_bee-1)&&(casetemp.GetEmpty()== false)){
                        coord_neigh_bee_white.push_back(casetemp.GetPosition());
                    }
                }
            }

        }
    }

    cout<<"Coord à éviter : "<<endl;
    for(auto coord:coord_neigh_bee_white){
        cout<<"[ "<<coord[0]<<" , "<<coord[1]<<" ]"<<endl;
    }


    for(auto ins : ai->GetAllInsect_placed()){
        if(ins.GetColor()==this->color){
            cout << "[FTC] test pour : "<<ins.GetName()<<" [ "<<ins.Get_i()<<" , "<<ins.Get_j()<<" ]" << endl;
            int occur=0;
            for(auto coord_to_avoid : coord_neigh_bee_white){
                cout << "[FTC] [ "<<coord_to_avoid[0]<<" , "<<coord_to_avoid[1]<<" ]" << endl;
                if((ins.Get_i()==coord_to_avoid[0])&&(ins.Get_j()==coord_to_avoid[1])){
                    cout<<"On l'évite du coup"<<endl;
                    occur++;
                    break;
                }
            }
            if(occur==0){result.push_back(ins);}
        }


    }
    cout<<"SORTIE DE GETINSECTSTOMOVE! et le résultat :"<<endl;

    for(auto ins : result){
        cout<<ins.GetName()<<endl;
    }


    return result;
}

