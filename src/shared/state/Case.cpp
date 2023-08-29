#include "Case.hpp"


std::vector<int> state::Case::GetPosition() {
    return this->position;
}

state::Case::Case(std::vector<int> coord, bool empty) {
    this->position=coord;this->empty=empty;
}

bool state::Case::GetEmpty() {
    return this->empty;
}

void state::Case::SetEmpty(bool state) {
this->empty=state;
}

int state::Case::Get_i() {
    return this->position[0];
}

int state::Case::Get_j() {
    return this->position[1];
}
