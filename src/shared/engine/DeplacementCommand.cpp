//
// Created by Alith on 25/11/2022.
//
#include "DeplacementCommand.hpp"

engine::DeplacementCommand::DeplacementCommand(state::GameStatus gamestatus, std::vector<int> position_insect,
                                               state::Insect &insect, CommandTypeId commandId, state::Player &player,
                                               std::vector<std::vector<int>> placement_possible) {
    this->position=position_insect;
    this->insect=&insect;
    this->player=&player;
    this->playing=gamestatus;
    this->commandTypeId=commandId;
    this->placement_possible=placement_possible;
}

bool engine::DeplacementCommand::execute(engine::Engine &engine) {

    state::Game game = *engine.getState();
    state::GameStatus state = game.GetState();
    std::string playerColor;
    int placed = 0;

    if(state == state::Player_A_playing){
        playerColor = game.GetListPlayer()[1]->GetColor();
    }else if (state == state::Player_B_playing){
        playerColor = game.GetListPlayer()[0]->GetColor();
    }

    for(auto ins : game.GetAllInsect_placed()){
        if(playerColor == "White" && ins.GetName() == "Bee_B"){
            placed = 1;
        } else if(playerColor == "Black" && ins.GetName() == "Bee_A"){
            placed = 1;
        }
    }

    if(placed && (state==state::Player_A_playing ||  state == state::Player_B_playing)){
        for (auto cas_temp : this->placement_possible){
            if((this->position[0]==cas_temp[0])&&(this->position[1]==cas_temp[1])&&(this->insect->GetIsPlaced()==true)){
                engine.UpdateState(*engine.getState(), 1, *insect, this->position,*this->player);
                return 1;
            }
        }
        placed = 0;
    }

    return 0;

}
