//
// Created by ensea on 13/11/22.
//
#include <iostream>
#include "InsectDraw.hpp"
#include <regex>

render::InsectDraw::InsectDraw() = default;

render::InsectDraw::InsectDraw(std::vector<std::vector<sf::Vector2f>> mapPixel, std::vector<std::vector<sf::Vector2f>> mapPixelRemaining) {
    this->mapPixelPosition = mapPixel; //On recupere la map
    this->mapPixelRemainingPosition = mapPixelRemaining;
}

void render::InsectDraw::drawInsect(sf::RenderWindow &window, state::Game state) { //affichage des pions insects
    for( auto i : state.GetListPlayer()){
        for(auto j : i->Get_List_Insect_Played()){

             this->insectHex[j->GetName()].setPosition(mapPixelPosition[j->Get_Position()[0]][j->Get_Position()[1]].x,
                                                      mapPixelPosition[j->Get_Position()[0]][j->Get_Position()[1]].y);
             window.draw(this->insectHex[j->GetName()]);
         }
        if(i->GetColor() == "White" && state.GetState() == state::Player_A_playing){
            int k = 0;
            for(auto j : i->Get_List_Insect_Remaining()){
                this->insectHex[j->GetName()].setPosition(mapPixelRemainingPosition[k][0].x,
                                                         mapPixelRemainingPosition[k][0].y);
                window.draw(this->insectHex[j->GetName()]);
                k++;
            }
        }
        else if(i->GetColor() == "Black" && state.GetState() == state::Player_B_playing){
            int k = 0;
            for(auto j : i->Get_List_Insect_Remaining()){
                this->insectHex[j->GetName()].setPosition(mapPixelRemainingPosition[k][0].x,
                                                          mapPixelRemainingPosition[k][0].y);
                window.draw(this->insectHex[j->GetName()]);
                k++;
            }
        }
    }
}

void render::InsectDraw::loadInsectTexture() {
    //TEXTURE


    bee_b.loadFromFile("./res/pion/bee_b.png");
    ant_b.loadFromFile("./res/pion/ant_b.png");
    beetle_b.loadFromFile("./res/pion/beetle_b.png");
    grasshopper_b.loadFromFile("./res/pion/grasshopper_b.png");
    ladybug_b.loadFromFile("./res/pion/ladybug_b.png");
    mosquito_b.loadFromFile("./res/pion/moskito_b.png");
    spider_b.loadFromFile("./res/pion/spider_b.png");

    bee_w.loadFromFile("./res/pion/bee_w.png");
    ant_w.loadFromFile("./res/pion/ant_w.png");
    beetle_w.loadFromFile("./res/pion/beetle_w.png");
    grasshopper_w.loadFromFile("./res/pion/grasshopper_w.png");
    ladybug_w.loadFromFile("./res/pion/ladybug_w.png");
    moskito_w.loadFromFile("./res/pion/mosquito_w.png");
    spider_w.loadFromFile("./res/pion/spider_w.png");

    //WHITE TILES
    std::vector<sf::CircleShape*> temp;//Liste permettant d'appliquer les méthodes
    sf::CircleShape Bee_A(24, 6);
    sf::CircleShape Spider_A1(24, 6);
    sf::CircleShape Spider_A2(24, 6);
    sf::CircleShape Beetle_A1(24, 6);
    sf::CircleShape Beetle_A2(24, 6);
    sf::CircleShape Ant_A1(24, 6);
    sf::CircleShape Ant_A2(24, 6);
    sf::CircleShape Ant_A3(24, 6);
    sf::CircleShape Ladybug_A(24, 6);
    sf::CircleShape Mosquito_A(24, 6);
    sf::CircleShape Grasshopper_A1(24, 6);
    sf::CircleShape Grasshopper_A2(24, 6);
    sf::CircleShape Grasshopper_A3(24, 6);
    temp.push_back(&Bee_A);
    temp.push_back(&Spider_A1); temp.push_back(&Spider_A2);
    temp.push_back(&Beetle_A1); temp.push_back(&Beetle_A2);
    temp.push_back(&Ant_A1); temp.push_back(&Ant_A2);
    temp.push_back(&Ant_A3); temp.push_back(&Ladybug_A);
    temp.push_back(&Mosquito_A); temp.push_back(&Grasshopper_A1);
    temp.push_back(&Grasshopper_A2); temp.push_back(&Grasshopper_A3);

    for( auto &i : temp){//Application des méthodes
        i->setOutlineThickness(2);
        i->setOutlineColor(sf::Color:: Black);
        i->setOrigin({ i->getRadius(), i->getRadius() });
       i->rotate(90);
    }

    //Application des textures
    Bee_A.setTexture(&bee_b);
    Spider_A1.setTexture(&spider_b);
    Spider_A2.setTexture(&spider_b);
    Beetle_A1.setTexture(&beetle_b);
    Beetle_A2.setTexture(&beetle_b);
    Ant_A1.setTexture(&ant_b);
    Ant_A2.setTexture(&ant_b);
    Ant_A3.setTexture(&ant_b);
    Ladybug_A.setTexture(&ladybug_b);
    Mosquito_A.setTexture(&mosquito_b);
    Grasshopper_A1.setTexture(&grasshopper_b);
    Grasshopper_A2.setTexture(&grasshopper_b);
    Grasshopper_A3.setTexture(&grasshopper_b);

    //Association d'un string à un pion
    this->insectHex["Bee_A"] = Bee_A;
    this->insectHex["Spider_A1"] = Spider_A1;
    this->insectHex["Spider_A2"] = Spider_A2;
    this->insectHex["Beetle_A1"] = Beetle_A1;
    this->insectHex["Beetle_A2"] = Beetle_A2;
    this->insectHex["Ant_A1"] = Ant_A1;
    this->insectHex["Ant_A2"] = Ant_A2;
    this->insectHex["Ant_A3"] = Ant_A3;
    this->insectHex["Ladybug_A"] = Ladybug_A;
    this->insectHex["Mosquito_A"] = Mosquito_A;
    this->insectHex["Grasshopper_A1"] = Grasshopper_A1;
    this->insectHex["Grasshopper_A2"] = Grasshopper_A2;
    this->insectHex["Grasshopper_A3"] = Grasshopper_A3;

/******************************************************************/
    //BLACK TILES
    std::vector<sf::CircleShape*> temp2;
    sf::CircleShape Bee_B(24, 6);
    sf::CircleShape Spider_B1(24, 6);
    sf::CircleShape Spider_B2(24, 6);
    sf::CircleShape Beetle_B1(24, 6);
    sf::CircleShape Beetle_B2(24, 6);
    sf::CircleShape Ant_B1(24, 6);
    sf::CircleShape Ant_B2(24, 6);
    sf::CircleShape Ant_B3(24, 6);
    sf::CircleShape Ladybug_B(24, 6);
    sf::CircleShape Mosquito_B(24, 6);
    sf::CircleShape Grasshopper_B1(24, 6);
    sf::CircleShape Grasshopper_B2(24, 6);
    sf::CircleShape Grasshopper_B3(24, 6);


    temp2.push_back(&Bee_B);
    temp2.push_back(&Spider_B1); temp2.push_back(&Spider_B2);
    temp2.push_back(&Beetle_B1); temp2.push_back(&Beetle_B2);
    temp2.push_back(&Ant_B1); temp2.push_back(&Ant_B2); temp2.push_back(&Ant_B3);
    temp2.push_back(&Ladybug_B);
    temp2.push_back(&Mosquito_B);
    temp2.push_back(&Grasshopper_B1); temp2.push_back(&Grasshopper_B2);  temp2.push_back(&Grasshopper_B3);


    for( auto &i : temp2){
        i->setOutlineThickness(2);
        i->setOutlineColor(sf::Color:: Black);
        i->setOrigin({ i->getRadius(), i->getRadius()});
        i->rotate(90);
    }

    Bee_B.setTexture(&bee_w);
    Spider_B1.setTexture(&spider_w);
    Spider_B2.setTexture(&spider_w);
    Beetle_B1.setTexture(&beetle_w);
    Beetle_B2.setTexture(&beetle_w);
    Ant_B1.setTexture(&ant_w);
    Ant_B2.setTexture(&ant_w);
    Ant_B3.setTexture(&ant_w);
    Ladybug_B.setTexture(&ladybug_w);
    Mosquito_B.setTexture(&moskito_w);
    Grasshopper_B1.setTexture(&grasshopper_w);
    Grasshopper_B2.setTexture(&grasshopper_w);
    Grasshopper_B3.setTexture(&grasshopper_w);

    this->insectHex["Bee_B"] = Bee_B;
    this->insectHex["Spider_B1"] = Spider_B1;
    this->insectHex["Spider_B2"] = Spider_B2;
    this->insectHex["Beetle_B1"] = Beetle_B1;
    this->insectHex["Beetle_B2"] = Beetle_B2;
    this->insectHex["Ant_B1"] = Ant_B1;
    this->insectHex["Ant_B2"] = Ant_B2;
    this->insectHex["Ant_B3"] = Ant_B3;
    this->insectHex["Ladybug_B"] = Ladybug_B;
    this->insectHex["Mosquito_B"] = Mosquito_B;
    this->insectHex["Grasshopper_B1"] = Grasshopper_B1;
    this->insectHex["Grasshopper_B2"] = Grasshopper_B2;
    this->insectHex["Grasshopper_B3"] = Grasshopper_B3;

}

std::string render::InsectDraw::getPressedInsect(int xt, int yt,state::Game state) {

    auto const regex_B = std::regex("_B");
    auto const regex_A = std::regex("_A");

    for(auto  i : this->insectHex){
            std::string name = i.first;

            if((state.GetState() == state::Player_B_playing && std::regex_search(name,regex_A)) ||
                (state.GetState() == state::Player_A_playing && std::regex_search(name,regex_B))) {
                sf::CircleShape shape = i.second;
                sf::Vector2f pos = shape.getPosition();
                int x = pos.x;
                int y = pos.y;

                //std::cout << pos.x << "-" << pos.y  << std::endl;

                if ((xt < x + 13) && (xt > x - 13) && (yt < y + 13) && (yt > y - 13)) {
                    //std::cout << name << std::endl;
                    return name;
                }
            }
        }

    std::cout<< "test" <<std::endl;
    return std::string{"nothing"};

}

