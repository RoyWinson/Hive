//
// Created by ensea on 13/11/22.
//
#include "Game.hpp"
#include "Bee.hpp"
#include <iostream>

using namespace std;
using namespace state;

void state::Game::UpdateState(state::GameStatus state) {
    this->state=state;
}

void state::Game::IncrementIteration() {
    this->nbIteration ++;
}

state::GameStatus state::Game::GetState() {
    return this->state;
}

int state::Game::GetIteration() {
    return this->nbIteration;
}

void state::Game::SetIteration(int param) {

    this->nbIteration=param;

}

std::vector<state::Insect*> state::Game::GetAllInsects() {
    return this->ListeAllInsect;
}

void state::Game::AppendListInsect(state::Insect& insect) {

    this->ListeAllInsect.push_back(&insect);

}



bool state::Game::IsBeeCircled(state::Player player) {
    cout<<"TEST POUR LE JOUEUR DE COULEUR : "<<player.GetColor()<<endl;
    vector<Case> list_case;
    int voisins=0;
    for (int i = 0; i < this->GetMap()->GetLength(); i++) {
        for (int j = 0; j < this->GetMap()->GetWidth(); j++) {
            list_case.push_back(this->GetMap()->GetListCase()[i][j]);
        }
    }
    if(player.Get_List_Insect_Played().size()==0){
        return false;
    }

    cout<<"Liste des insectes joués :"<<endl;
    for(auto bee : player.Get_List_Insect_Played()){

        cout<<bee->GetName()<<" , "<<bee->GetColor()<<" , [ "<<bee->Get_i()<<" , "<<bee->Get_j()<<" ]"<<endl;
    }

        for(auto bee : player.Get_List_Insect_Played()){

            if(((bee->GetName()=="Bee_B")||(bee->GetName()=="Bee_A"))&&(bee->GetColor()==player.GetColor())&&(bee->GetIsPlaced())){
                cout<<"INSECTE TROUVE : "<<bee->GetName() << bee->GetColor()<<endl;
                int x = bee->Get_i();
                int y = bee->Get_j();

                //COMPTAGE DU NOMBRE DE VOISINS
                for(auto casetemp : list_case) {
                    if (y % 2 == 0) {
                        if ((casetemp.GetPosition()[0] == x) && (casetemp.GetPosition()[1] == y - 1) &&
                            (casetemp.GetEmpty() == false)) {
                            voisins++;
                        } else if ((casetemp.GetPosition()[0] == x) && (casetemp.GetPosition()[1] == y + 1) &&
                                  (casetemp.GetEmpty() == false)) {
                            voisins++;
                        } else if ((casetemp.GetPosition()[0] == x - 1) && (casetemp.GetPosition()[1] == y) &&
                                   (casetemp.GetEmpty() == false)) {
                            voisins++;
                        } else if ((casetemp.GetPosition()[0] == x + 1) && (casetemp.GetPosition()[1] == y - 1) &&
                                   (casetemp.GetEmpty() == false)) {
                            voisins++;
                        } else if ((casetemp.GetPosition()[0] == x + 1) && (casetemp.GetPosition()[1] == y) &&
                                   (casetemp.GetEmpty() == false)) {
                            voisins++;
                        } else if ((casetemp.GetPosition()[0] == x + 1) && (casetemp.GetPosition()[1] == y + 1) &&
                                   (casetemp.GetEmpty() == false)) {
                            voisins++;
                        }
                    }
                    else {

                            if ((casetemp.GetPosition()[0] == x - 1) && (casetemp.GetPosition()[1] == y) &&
                               (casetemp.GetEmpty() == false)) {
                                voisins++;
                            } else if ((casetemp.GetPosition()[0] == x - 1) && (casetemp.GetPosition()[1] == y + 1) &&
                                      (casetemp.GetEmpty() == false)) {
                                voisins++;
                            } else if ((casetemp.GetPosition()[0] == x) && (casetemp.GetPosition()[1] == y - 1) &&
                                        (casetemp.GetEmpty() == false)) {
                                voisins++;
                            } else if ((casetemp.GetPosition()[0] == x) && (casetemp.GetPosition()[1] == y + 1) &&
                                       (casetemp.GetEmpty() == false)) {
                                voisins++;
                            } else if ((casetemp.GetPosition()[0] == x + 1) && (casetemp.GetPosition()[1] == y) &&
                                       (casetemp.GetEmpty() == false)) {
                                voisins++;
                            } else if ((casetemp.GetPosition()[0] == x - 1) && (casetemp.GetPosition()[1] == y - 1) &&
                                      (casetemp.GetEmpty() == false)) {
                                voisins++;
                            }

                    }
                }
                cout<<"Voisins pour la couleur : "<<player.GetColor()<<" : "<<voisins<<endl;
                if(y%2==0){
                    if((x==0)&&(y==0)&&(voisins==3)){cout<<"TRUE"<<endl;return true;} //COIN HAUT GAUCHE
                    else if((x==0)&&(y==GameMap->GetWidth()-1)&&(voisins==3)){cout<<"TRUE"<<endl;return true;} // COIN HAUT DROITE
                    else if((x==0)&&(y!=0)&&(y!=GameMap->GetWidth()-1)&&(voisins==5)){cout<<"TRUE"<<endl;return true;}//BORDURE HAUTE
                    else if((x==GameMap->GetLength()-1)&&(y==0)&&(voisins==2)){cout<<"TRUE"<<endl;return true;}//COIN BAS GAUCHE
                    else if((x!=0)&&(x!=GameMap->GetLength()-1)&&(y==0)&&(voisins==4)){cout<<"TRUE"<<endl;return true;}//BORDURE GAUCHE
                    else if((x==GameMap->GetLength()-1)&&(y==GameMap->GetWidth()-1)&&(voisins==2)){cout<<"TRUE"<<endl;return true;}//COIN BAS DROITE
                    else if((x==GameMap->GetLength()-1)&&(y!=0)&&(y!=GameMap->GetWidth()-1)&&(voisins==3)){cout<<"TRUE"<<endl;return true;}//BORDURE BASSE
                    else if((x!=0)&&(x!=GameMap->GetLength()-1)&&(y==GameMap->GetWidth()-1)&&(voisins==4)){cout<<"TRUE"<<endl;return true;}//BORDURE DROITE
                    else if((x!=0)&&(x!=GameMap->GetLength()-1)&&(y!=GameMap->GetWidth()-1)&&(y!=0)&&(voisins==6)){cout<<"TRUE"<<endl;return true;}//CAS QUELCONQUE
                    else {cout<<"FALSE"<<endl;return false;}
                }
                else{
                    if((x==0)&&(y==0)&&(voisins==2)){cout<<"TRUE"<<endl;return true;} //COIN HAUT GAUCHE
                    else if((x==0)&&(y==GameMap->GetWidth()-1)&&(voisins==2)){cout<<"TRUE"<<endl;return true;} // COIN HAUT DROITE
                    else if((x==0)&&(y!=0)&&(y!=GameMap->GetWidth()-1)&&(voisins==3)){cout<<"TRUE"<<endl;return true;}//BORDURE HAUTE
                    else if((x==GameMap->GetLength()-1)&&(y==0)&&(voisins==3)){cout<<"TRUE"<<endl;return true;}//COIN BAS GAUCHE
                    else if((x!=0)&&(x!=GameMap->GetLength()-1)&&(y==0)&&(voisins==4)){cout<<"TRUE"<<endl;return true;}//BORDURE GAUCHE
                    else if((x==GameMap->GetLength()-1)&&(y==GameMap->GetWidth()-1)&&(voisins==3)){cout<<"TRUE"<<endl;return true;}//COIN BAS DROITE
                    else if((x==GameMap->GetLength()-1)&&(y!=0)&&(y!=GameMap->GetWidth()-1)&&(voisins==5)){cout<<"TRUE"<<endl;return true;}//BORDURE BASSE
                    else if((x!=0)&&(x!=GameMap->GetLength()-1)&&(y==GameMap->GetWidth()-1)&&(voisins==4)){cout<<"TRUE"<<endl;return true;}//BORDURE DROITE
                    else if((x!=0)&&(x!=GameMap->GetLength()-1)&&(y!=GameMap->GetWidth()-1)&&(y!=0)&&(voisins==6)){cout<<"TRUE"<<endl;return true;}//CAS QUELCONQUE
                    else {cout<<"FALSE"<<endl;return false;}
                }

                }

        }

        cout<<"Abeille pas placée: return false"<<endl;
        return false;
}


state::Game::Game() {
    this->nbIteration=0; //On commence au tour 0
    this->state=Player_A_playing; //choix arbitraire
    this->GameMap= new Map(10,17); //Map de 10 x 10 cases

}

state::Map* state::Game::GetMap() {
    return this->GameMap;
}


void state::Game::AppendListJoueur(state::Player& player) {
    this->listPlayer.push_back(&player);
}

std::vector<state::Player *> state::Game::GetListPlayer() {
    return this->listPlayer;
}

vector<state::Insect> Game::GetAllInsect_placed() {

    vector<Insect> list_res;

    for (auto ins : this->ListeAllInsect){
        if (ins->GetIsPlaced()){
            list_res.push_back(*ins);
        }
    }


    return list_res;
}





