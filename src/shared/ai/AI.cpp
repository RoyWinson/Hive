#include "AI.hpp";


ai::AI::AI (state::Game& game, std::string color){
this->ai=&game;
this->player_a=true;
this->color = color;
}

std::vector<int> ai::AI::runAI() {
    return {0};
}

