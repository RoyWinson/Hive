
//
// Created by ensea on 28/10/22.
//

#include <iostream>
#include "Player.hpp"


using namespace std;
using namespace state;

Player:: Player(string name, string color) {
    this->Name = name;
    this->Color = color; //couleur de ses pions
}

//Getters
string Player::GetName() {
    return Name;
}

string Player::GetColor() {
    return Color;
}

vector<Insect *> Player::Get_List_Insect_Remaining() {
    return this->ListInsectRemaining;
}

vector<Insect *> Player::Get_List_Insect_Played() {
    return this->ListInsectPlayed;
}

void Player::Add_Insect_Played(Insect &insecte) {
    ListInsectPlayed.push_back(&insecte);//Une fois l'insecte ajoutée à la liste des pions joués
    //Player::Remove_Insect_Remaining(insecte);//on supprime l'insecte de la liste des pions restants
}

void Player::Remove_Insect_Remaining(Insect &insecte) {//Efface
    for (int i = 0; i < ListInsectRemaining.size(); i++) {
        if (ListInsectRemaining[i]->GetName() == insecte.GetName()) {
            ListInsectRemaining.erase(ListInsectRemaining.begin() + i);
        }
    }
}

void Player::Add_Insect_Remaining(Insect &insecte) {
        ListInsectRemaining.push_back(&insecte);//Ajout de l'élément à la dernière place
}

void Player::setName(std::string name) {
    this->Name = name;
}



