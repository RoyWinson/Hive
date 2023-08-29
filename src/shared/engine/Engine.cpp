#include "Engine.hpp"
#include "state/Game.hpp"
#include "iostream"
#include <state.hpp>
using namespace std;
using namespace state;

int tour = 0;

engine::Engine::Engine(state::Game &game) {
    this->currentGame=&game;
}

state::Game *engine::Engine::getState() {
    return this->currentGame;
}

void engine::Engine::addCommand(engine::Command ptr_cmd) {
    this->listCommands.push_back(ptr_cmd);
}


void engine::Engine::UpdateState(state::Game &game, int commandid, state::Insect &insect_moving,std::vector<int> pos_target,state::Player &player) {

    if (commandid==0) {
        //PLACEMENT

        game.GetMap()->SetEmptyCase(0, pos_target[0], pos_target[1]);
        //game.GetMap()->SetEmptyCase(1, insect_moving.Get_i(), insect_moving.Get_j());
        auto *ins = &insect_moving;
        ins->SetPosition(pos_target);
        ins->SetIsPlaced(true);
        auto *play = &player;
        play->Add_Insect_Played(*ins);
        play->Remove_Insect_Remaining(*ins);
        tour+=1;
    }
    else if(commandid==1) {
        //DEPLACEMENT
        game.GetMap()->SetEmptyCase(0, pos_target[0], pos_target[1]);
        game.GetMap()->SetEmptyCase(1, insect_moving.Get_i(), insect_moving.Get_j());
        auto *ins = &insect_moving;
        ins->SetPosition(pos_target);
        tour+=1;
    }
    if(!(tour%2)){
        game.SetIteration(game.GetIteration() + 1);
        tour = 0;
    }

    bool test_white= game.IsBeeCircled(*game.GetListPlayer()[1]);
    bool test_black =game.IsBeeCircled(*game.GetListPlayer()[0]);



    if(test_white){

        game.UpdateState(state::Player_B_won);
        std::string playerB = game.GetListPlayer()[0]->GetName();
        cout<<playerB<<" win \n"<<endl;
    }

    else if(test_black){

        game.UpdateState(state::Player_A_won);
        std::string playerA = game.GetListPlayer()[1]->GetName();
        cout<<playerA<<" win \n"<<endl;
    }
    else if(game.GetState() == state::Player_A_playing){

        game.UpdateState(state::Player_B_playing);
    }
    else if(game.GetState() == state::Player_B_playing){

        game.UpdateState(state::Player_A_playing);
    }

}



