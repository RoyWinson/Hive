//
// Created by ensea on 14/11/22.
//
#include"TextDraw.hpp"
#include <sstream>

render::TextDraw::TextDraw() {
    font.loadFromFile("./res/arial.ttf");
}

void render::TextDraw::drawText(sf::RenderWindow &window, state::Game state) {

    std::stringstream pname;
    std::stringstream ntour;
    std::stringstream gamestatus;

    this->stateText = sf::Text("",font,20);
    this->nbtour = sf::Text("",font,20);
    nbtour.setFont(font);

    getPlayerName(state);
    this->playerName = sf::Text("",font,20);
    playerName.setFont(font);

    this->nbtour.setCharacterSize(20);
    this->nbtour.setPosition(900,280);
    this->nbtour.setFillColor(sf::Color::Black);

    this->playerName.setCharacterSize(20);
    this->playerName.setPosition(900,200);
    playerName.setFillColor(sf::Color::Black);

    this->stateText.setCharacterSize(20);
    this->stateText.setPosition(900,360);
    this->stateText.setFillColor(sf::Color::Black);

    this->state = getStateString(state);
    gamestatus << this->state;
    stateText.setString(gamestatus.str());

    pname << "P1: " << p1 <<"\n"<<listPlayer[0]->GetColor()<<"\n"
       << "P2: " << p2 <<"\n"<< listPlayer[1]->GetColor()<<"\n";

    playerName.setString(pname.str());

    ntour << "\nTurn: " << state.GetIteration();
    nbtour.setString(ntour.str());


    window.draw(playerName);
    window.draw(nbtour);
    window.draw(stateText);
}

void render::TextDraw::getPlayerName(state::Game state) {
    this->listPlayer = state.GetListPlayer();
    p1 = listPlayer[0]->GetName();
    p2 = listPlayer[1]->GetName();
}

render::TextDraw::TextDraw(state::Game state) {

    //getPlayerName(state);

}

std::string render::TextDraw::getStateString(state::Game state) {
    if(state.GetState() == state::Player_B_playing){
        return state.GetListPlayer()[0]->GetName()+"\nis playing\n";
    }
    else if(state.GetState() == state::Player_A_playing){
        return state.GetListPlayer()[1]->GetName()+"\nis playing\n";
    }
    else{
        return "END GAME";
    }
}
