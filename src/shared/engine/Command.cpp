//
// Created by Alith on 25/11/2022.
//
#include "Command.hpp"

engine::Command::Command() {
    this->player;
    this->playing=state::Player_A_playing;
    this->commandTypeId=PLACEMENT;

}

engine::CommandTypeId engine::Command::getCommandTypeId() {
    return this->commandTypeId;
}

void engine::Command::setCommandTypeId(engine::CommandTypeId commandTypeId) {
    this->commandTypeId=commandTypeId;

}

state::GameStatus engine::Command::getPlaying() const {
    return this->playing;
}

void engine::Command::setPlaying(state::GameStatus playing) {
this->playing=playing;
}





bool engine::Command::execute() {
    return false;
}






