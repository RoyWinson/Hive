#include "RandomAI.hpp"
#include "state.hpp"
#include "iostream"
#include "random"
#include <engine.hpp>
#include <cstdlib>

using namespace std;
using namespace state;
using namespace engine;

ai::RandomAI::RandomAI(state::Game& game, std::string color) : AI(game,color) {
this->ai=&game;
this->player_a=true;
this->color = color;
}

std::vector<int> ai::RandomAI::runAI() {

    vector<int> result;

    srand((unsigned int)time(0));
    int choix_op;
    vector<int> list_choice_insect;
    int i = 0;
    int index_insect;

    cout << "Choix possibles pour l'IA\n" << endl;
    for (auto &ins: this->ai->GetAllInsects()) {

        if (ins->GetColor() == this->color) {
            cout << "I= " << i << " -->  " << ins->GetName() << "  |  " << ins->GetColor() << "  |  ["
                 << ins->Get_Position()[0] << ";" << ins->Get_Position()[1] << "] "
                 << ins->GetIsPlaced() << " \n";
            list_choice_insect.push_back(i);
        }
        i++;
    }

    vector<vector<int>> temp_coord;

    while (temp_coord.size() == 0) {
        cout << "Retirage car pas de coups possibles"<< endl;

        srand((unsigned int)time(0));
        int random_choice_insect=rand()%(list_choice_insect.size());
        index_insect=list_choice_insect[random_choice_insect];
        cout << "Nombre tiré par l'IA : " << index_insect<< endl;
        auto choice_insect = ai->GetAllInsects()[list_choice_insect[random_choice_insect]];

        cout << "INSECTE : L'IA A CHOISI : " << choice_insect->GetName() << endl;

        vector<Case> list_case;
        for (int i = 0; i < ai->GetMap()->GetLength(); i++) {
            for (int j = 0; j < ai->GetMap()->GetWidth(); j++) {
                list_case.push_back(ai->GetMap()->GetListCase()[i][j]);
            }
        }
        if (choice_insect->GetIsPlaced() == 0) {
            temp_coord = choice_insect->Possible_Placement_Insect(ai->GetAllInsect_placed(), list_case);
            choix_op = 0;
        } else {
            temp_coord = choice_insect->Possible_Deplacement_Insect(ai->GetAllInsect_placed(),list_case);
            choix_op = 1;
        }

    }

    cout << "Coordonnées possibles pour l'IA :\n " << endl;
    int h = 0;
    for (auto case_temp: temp_coord) {
        cout << "I= " << h << " -->  " << " [" << case_temp[0] << ";" << case_temp[1] << "]\n";
        h++;
    }

    int random_coord=rand()%(temp_coord.size());
    cout << "Nombre tiré par l'IA : " << random_coord<< endl;
    auto choice_coord = temp_coord[random_coord];

    cout << "POSITION : L'IA A CHOISI : [" << choice_coord[0] << " , " << choice_coord[1] << "]\n" << endl;

    result.push_back(choix_op);
    result.push_back(choice_coord[0]);
    result.push_back(choice_coord[1]);
    result.push_back(index_insect);



    return result;
}
