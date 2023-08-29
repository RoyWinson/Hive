//
// Created by ali on 26/10/22.
//
#include <vector>
#include "state.hpp"
#include "Map.hpp"

using namespace std;


state::Map::Map(int length, int width) {
    
  this->Length=length;
  this->Width=width;

  vector<vector<Case>> templistcase;


    for (int i=0;i<length;i++){
        vector<Case> temp;
        for(int j=0;j<width;j++) {

            temp.push_back(Case({i,j},true));


        }
        templistcase.push_back(temp);
    }
    this->ListCase=templistcase;
}

int state::Map::GetLength() {
    return this->Length;
}

int state::Map::GetWidth() {
    return this->Width;
}

vector<vector<state::Case>> state::Map::GetListCase() {
    return this->ListCase;
}

void state::Map::SetListCase(state::Case case1, int i, int j) {
    this->ListCase[i][j]= case1;
}

void state::Map::SetEmptyCase(bool empty,int i ,int j) {
this->ListCase[i][j].SetEmpty(empty);
}

