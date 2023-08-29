//
// Created by Alith on 25/11/2022.
//
#include "PlacementCommand.hpp"
#include "iostream"

using namespace std;

int placedA = 0;
int placedB = 0;
int foundA = 0;
int foundB = 0;

engine::PlacementCommand::PlacementCommand(state::GameStatus gamestatus, std::vector<int> position_insect,
                                           state::Insect& insect, CommandTypeId commandId, state::Player& player,vector<vector<int>> placement_possible) {
    this->position=position_insect;
    this->insect=&insect;
    this->player=&player;
    this->playing=gamestatus;
    this->commandTypeId=commandId;
    this->placement_possible=placement_possible;
}

bool engine::PlacementCommand::execute(engine::Engine &engine) {

    //On recupère l'état du jeu, la couleur du joeur et l'objet state
    state::Game game = *engine.getState();
    state::GameStatus state = game.GetState();
    std::string playerColor;
    int tour = game.GetIteration();
    if (state == state::Player_A_playing) {
        playerColor = game.GetListPlayer()[1]->GetColor();
    } else if (state == state::Player_B_playing) {
        playerColor = game.GetListPlayer()[0]->GetColor();
    }

    //Test pour verifier si les pions abeilles sont placés ou pas
    if(!placedB || !placedA) {
        for (auto ins: game.GetAllInsect_placed()) {
            if (playerColor == "White" && ins.GetName() == "Bee_B") {
                placedB = 1;
            } else if (playerColor == "Black" && ins.GetName() == "Bee_A") {
                placedA = 1;
            }
        }
    }


    //Regle : On doit poser les abeilles avant le tour 4
    if ((state==state::Player_A_playing && !placedB && tour == 3 && (this->insect->GetName() != "Bee_B")) ||
        (state==state::Player_B_playing && !placedA && tour == 3 && (this->insect->GetName() != "Bee_A"))){
        cout<<"Erreur : il faut placer l'abeille"<<endl;
        return 0;
    }
    else if (state==state::Player_A_playing ||  state == state::Player_B_playing){
        for (auto cas_temp : this->placement_possible){
            if((this->position[0]==cas_temp[0])&&(this->position[1]==cas_temp[1])&&(this->insect->GetIsPlaced()==false)){

                engine.UpdateState(*engine.getState(), 0, *insect, this->position,*this->player);
                return 1;
            }
        }
    }

    return 0;

}



