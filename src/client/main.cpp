

#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include <state.hpp>
#include <engine.hpp>
#include <render.hpp>
#include <ai.hpp>

#include <list>
#include <sstream>

#include <unordered_map>


using namespace std;
using namespace state;
using namespace render;
using namespace engine;
using namespace ai;

#define IterationMAX 6

int WIDTH = 1080;
int HEIGHT = 720;


int main(int argc,char* argv[]){
    Game game_test = *new Game();


    Player Benzema = *new Player("Benzema", "White");
    Player Giroud =  *new Player("Giroud", "Black");

    std::vector<Insect *> temp3;
    std::vector<Insect *> temp4;


    Bee Bee_B = Bee("Bee_B", "White", {-99, -99}, 0);
    temp4.push_back(&Bee_B);
    Bee Bee_A = Bee("Bee_A", "Black", {-99, -99}, 0);
    temp3.push_back(&Bee_A);
    Grasshooper Grasshopper_B2 = Grasshooper("Grasshopper_B2", "White", {-99, -99}, 0);
    temp4.push_back(&Grasshopper_B2);
    Grasshooper Grasshopper_A2 = Grasshooper("Grasshopper_A2", "Black", {-99, -99}, 0);
    temp3.push_back(&Grasshopper_A2);
    Grasshooper Grasshopper_B1 = Grasshooper("Grasshopper_B1", "White", {-99, -99}, 0);
    temp4.push_back(&Grasshopper_B1);
    Grasshooper Grasshopper_A1 = Grasshooper("Grasshopper_A1", "Black", {-99, -99}, 0);
    temp3.push_back(&Grasshopper_A1);
    Grasshooper Grasshopper_B3 = Grasshooper("Grasshopper_B3", "White", {-99, -99}, 0);
    temp4.push_back(&Grasshopper_B3);
    Grasshooper Grasshopper_A3 = Grasshooper("Grasshopper_A3", "Black", {-99, -99}, 0);
    temp3.push_back(&Grasshopper_A3);
    Spider Spider_B2 = Spider("Spider_B2", "White", {-99, -99}, 0);
    temp4.push_back(&Spider_B2);
    Spider Spider_B1 = Spider("Spider_B1", "White", {-99, -99}, 0);
    temp4.push_back(&Spider_B1);
    Spider Spider_A2 = Spider("Spider_A2", "Black", {-99, -99}, 0);
    temp3.push_back(&Spider_A2);
    Spider Spider_A1 = Spider("Spider_A1", "Black", {-99, -99}, 0);
    temp3.push_back(&Spider_A1);
    Ant Ant_B2 = Ant("Ant_B2", "White", {-99, -99},0);temp4.push_back(&Ant_B2);
    Ant Ant_B1 = Ant("Ant_B1", "White", {-99, -99},0);temp4.push_back(&Ant_B1);
    Ant Ant_A2 = Ant("Ant_A2", "Black", {-99, -99},0);temp3.push_back(&Ant_A2);
    Ant Ant_A1 = Ant("Ant_A1", "Black", {-99, -99},0);temp3.push_back(&Ant_A1);

    for (auto &i: temp3) {
        Giroud.Add_Insect_Remaining(*i);
    }
    for (auto &j: temp4) {
        Benzema.Add_Insect_Remaining(*j);
    }

    game_test.AppendListJoueur(Giroud);
    game_test.AppendListJoueur(Benzema);


    game_test.AppendListInsect(Bee_B);
    game_test.AppendListInsect(Bee_A);
    game_test.AppendListInsect(Grasshopper_B2);
    game_test.AppendListInsect(Grasshopper_A2);
    game_test.AppendListInsect(Grasshopper_B1);
    game_test.AppendListInsect(Grasshopper_A1);
    game_test.AppendListInsect(Grasshopper_B3);
    game_test.AppendListInsect(Grasshopper_A3);
    game_test.AppendListInsect(Spider_B2);
    game_test.AppendListInsect(Spider_A2);
    game_test.AppendListInsect(Spider_B1);
    game_test.AppendListInsect(Spider_A1);
    game_test.AppendListInsect(Ant_B2);
    game_test.AppendListInsect(Ant_A2);
    game_test.AppendListInsect(Ant_B1);
    game_test.AppendListInsect(Ant_A1);

        sf::CircleShape temphexa(24, 6);
        temphexa.rotate(90);
        temphexa.setOrigin({temphexa.getRadius(), temphexa.getRadius()});
        sf::Color selected(106,13,173);
        temphexa.setFillColor(selected);
        temphexa.setOutlineColor(sf::Color::White);

    if ((string)argv[argc-1]=="hello"){
        cout << "Hello World !" << endl;
    }

    else if ((string)argv[argc-1]=="engine") {

        /*---------------------------------------------RENDER--INIT------------------------------------------------------------------*/
        sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "HIVE",
                                sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
        Scene scene = Scene(game_test);
        sf::Font font; //Police écriture
        if (!font.loadFromFile("./res/arial.ttf"))
            return EXIT_FAILURE;
        sf::Text text("Hello SFML", font, 20);

        float X = window.getSize().x;
        float Y = window.getSize().y;
        float xo = window.getSize().x;
        float yo = window.getSize().y;
        float sx = 1.0, sy = 1.0;
        int posx;
        int posy;
        int etat = 0;
        vector<vector<int>> temp_coord;
        vector<int> temp_selected;
        Insect *insect_moving = nullptr;
        Player *player_temp = &Benzema;

        std::vector<std::vector<sf::Vector2f>> mapPixelPosition;
        mapPixelPosition = scene.mapDraw.mapPixelPosition;

        /*-----------------------------------------------FIN-RENDER---INIT----------------------------------------------------------*/

        Engine engine_test = *new Engine(game_test);

        cout << "---------------------DEBUT DU JEU---------------------" << endl;

        int nbTour = 0;
        while (window.isOpen()) {
            window.clear();

            int xmouse = sf::Mouse::getPosition(window).x;
            int ymouse = sf::Mouse::getPosition(window).y;


            sf::Event event;
            while (window.pollEvent(event)) {

                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::Resized) {
                    X = (window.getSize().x);
                    Y = (window.getSize().y);
                }

                if (event.type == sf::Event::MouseButtonPressed) {

                    if (event.mouseButton.button == sf::Mouse::Left) {

                         posx = int(event.mouseButton.x * (xo / X));
                         posy = int(event.mouseButton.y * (yo / Y));

                        string insect_selected = scene.insectDraw.getPressedInsect(posx, posy,game_test);

                        //scene.mapDraw.getPressedTiles(posx,posy,window);
                        int i = 0;
                        int number = 0;
                        bool found = 0;

                        if (etat == 0) {
                            for (auto &ins: game_test.GetAllInsects()) {
                                if (found == false) {
                                    if (ins->GetName() == insect_selected) {
                                        found = true;
                                        etat = 1;
                                        number = i;
                                    }
                                    ++i;
                                }
                            }
                        }
                        if (etat == 1) {
                            insect_moving = game_test.GetAllInsects()[number];
                            cout << "Vous avez choisi : " << insect_moving->GetName() << "\n";
                            found = false;

                            i = 0;
                            vector<Case> list_case;

                            for (int i = 0; i < game_test.GetMap()->GetLength(); i++) {
                                for (int j = 0; j < game_test.GetMap()->GetWidth(); j++) {
                                    list_case.push_back(game_test.GetMap()->GetListCase()[i][j]);
                                }
                            }
                            if (!insect_moving->GetIsPlaced()) {
                                temp_coord = insect_moving->Possible_Placement_Insect(game_test.GetAllInsect_placed(),
                                                                                      list_case);
                            }
                            else if(insect_moving->GetIsPlaced()){
                                temp_coord = insect_moving->Possible_Deplacement_Insect(game_test.GetAllInsect_placed(),
                                                                                        list_case);
                            }
                            if(temp_coord.size() != 0){
                                etat = 2;
                            }else {
                                etat = 4;
                                cout<<"Aucune solution\n"<<endl;
                            }
                        }
                        else if (etat == 2) {
                            temp_selected = scene.mapDraw.getPressedTiles(posx, posy);
                            if(temp_selected[0]!=-1){etat = 3;cout<<"confirmez\n";} else {etat = 0; cout<<"reselectionnez\n";}
                        }
                        else if (etat == 3) {

                            //cout <<"etat3"<<" "<<temp_selected[0]<<","<<temp_selected[1]<<endl;

                            if (!insect_moving->GetIsPlaced()) {
                                PlacementCommand plac = PlacementCommand(game_test.GetState(), temp_selected, *insect_moving,
                                                                         PLACEMENT, *player_temp, temp_coord);
                                plac.execute(engine_test);
                            }
                            else if(insect_moving->GetIsPlaced()){
                                DeplacementCommand deplac = DeplacementCommand(game_test.GetState(), temp_selected,
                                                                               *insect_moving,
                                                                               DEPLACEMENT, *player_temp, temp_coord);
                                deplac.execute(engine_test);
                            }

                            if(game_test.GetState() == state::Player_A_playing){
                                player_temp = &Benzema;
                            }
                            else if(game_test.GetState() == state::Player_B_playing){
                                player_temp = &Giroud;
                            }

                            etat = 0;
                        }
                        else if(etat == 4){
                            etat = 0;
                        }
                    }
                }

            }
            int xi = int((xmouse) * (xo / X));
            int yi = int((ymouse) * (yo / Y));

            std::stringstream ss;
            ss << "X " << xi << "\n"
               << "Y " << yi << "\n";


            window.clear();
            text.setString(ss.str());
            window.draw(text);

            scene.drawScene(game_test, window);

            if (etat == 2) {
                for (auto i: temp_coord) {
                    temphexa.setPosition(mapPixelPosition[i[0]][i[1]]);
                    window.draw(temphexa);
                }
            }
            if (etat == 3){
                if(!temp_selected.empty()){
                    temphexa.setPosition(mapPixelPosition[temp_selected[0]][temp_selected[1]]);
                    window.draw(temphexa);
                }
            }
            window.display();

            }


        }

    else if ((string)argv[argc-1]=="ai") {

        Engine engine_test = *new Engine(game_test);
        RandomAI ai_test = *new RandomAI(game_test, Giroud.GetColor());


        //AFFICHAGE DE LA MAP
        for (int a = 0; a < game_test.GetMap()->GetLength(); a++) {
            for (int b = 0; b < game_test.GetMap()->GetWidth(); b++) {
                cout << "  [" << game_test.GetMap()->GetListCase()[a][b].Get_i() << "|"
                     << game_test.GetMap()->GetListCase()[a][b].Get_j() << "|"
                     << game_test.GetMap()->GetListCase()[a][b].GetEmpty() << "]";
                if (b == game_test.GetMap()->GetWidth() - 1) {
                    cout << "\n" << endl;
                }
            }
        }


        cout << "---------------------DEBUT DU JEU---------------------" << endl;

        int nbTour = 0;

        while (nbTour < IterationMAX) {
            cout << "---------------------TOUR N." << nbTour << " ---------------------" << endl;


            for (auto player_test: game_test.GetListPlayer()) {

                sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "HIVE",
                                        sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);


                Scene scene = Scene(game_test);

                sf::Font font; //Police écriture
                if (!font.loadFromFile("./res/arial.ttf"))
                    return EXIT_FAILURE;
                sf::Text text("Hello SFML", font, 20);
                scene.drawScene(game_test, window);
                window.display();

                if (player_test->GetColor() == "Black") {

                    vector<vector<int>> temp_coord_AI;
                    vector<int> command_list = ai_test.runAI();
                    cout<<"FIN RUN AI\n"<<endl;


                    cout<<"DEBUT TRAITEMENT RETOURNE PAR AI\n"<<endl;

                    cout<<"Contenu de command list: "<<command_list[0]<<" , "<<command_list[1]<<" , "<<command_list[2]<<" , "<<command_list[3]<<endl;



                    Insect *insect_moving = game_test.GetAllInsects()[command_list[3]];
                    vector<Case> list_case;
                    for (int i = 0; i < game_test.GetMap()->GetLength(); i++) {
                        for (int j = 0; j < game_test.GetMap()->GetWidth(); j++) {
                            list_case.push_back(game_test.GetMap()->GetListCase()[i][j]);
                        }
                    }


                    if (command_list[0] == 0) {
                        cout<<"choix de placement\n"<<endl;
                        temp_coord_AI = insect_moving->Possible_Placement_Insect(game_test.GetAllInsect_placed(),
                                                                                 list_case);
                        PlacementCommand plac = PlacementCommand(game_test.GetState(),
                                                                 {command_list[1], command_list[2]},
                                                                 *insect_moving,
                                                                 PLACEMENT, *player_test, temp_coord_AI);
                        bool resultat = plac.execute(engine_test);
                        if (resultat) { cout << "Placement effectué" << endl; }

                    } else {
                        cout<<"choix de déplacement\n"<<endl;
                        temp_coord_AI = insect_moving->Possible_Deplacement_Insect(game_test.GetAllInsect_placed(),
                                                                                   list_case);


                        DeplacementCommand deplac = DeplacementCommand(game_test.GetState(),
                                                                       {command_list[1], command_list[2]},
                                                                       *insect_moving,
                                                                       DEPLACEMENT, *player_test, temp_coord_AI);
                        bool resultat = deplac.execute(engine_test);
                        if (resultat) { cout << "Déplacement effectué" << endl; }
                    }

                    //AFFICHAGE DE LA MAP
                    for (int a = 0; a < game_test.GetMap()->GetLength(); a++) {
                        for (int b = 0; b < game_test.GetMap()->GetWidth(); b++) {
                            cout << "  [" << game_test.GetMap()->GetListCase()[a][b].Get_i() << "|"
                                 << game_test.GetMap()->GetListCase()[a][b].Get_j() << "|"
                                 << game_test.GetMap()->GetListCase()[a][b].GetEmpty() << "]";
                            if (b == game_test.GetMap()->GetWidth() - 1) {
                                cout << "\n" << endl;
                            }
                        }
                    }

                cout<<"FIN IA\n"<<endl;
                }

                else {


                    cout << "---------------------ETAT DU JEU : " << game_test.GetState() << " ---------------------"
                         << endl;
                    cout << "---------------------C'EST AU TOUR DE : " << player_test->GetName()
                         << " ---------------------" << endl;
                    int choix;
                    int i = 0;
                    int choice_x, choice_y;
                    for (auto &ins: game_test.GetAllInsects()) {

                        if (ins->GetColor() == player_test->GetColor()) {
                            cout << "I= " << i << " -->  " << ins->GetName() << "  |  " << ins->GetColor() << "  |  ["
                                 << ins->Get_Position()[0] << ";" << ins->Get_Position()[1] << "] "
                                 << ins->GetIsPlaced() << " \n";;
                        }
                        i++;
                    }
                    cout << "Choix de l'insecte à modifier :";
                    cin >> i;

                    while ((i > game_test.GetAllInsects().size() - 1) ||
                           (game_test.GetAllInsects()[i]->GetColor() != player_test->GetColor())) {
                        cout << "Choix de l'insecte :";
                        cin >> i;
                    }
                    Insect *insect_moving = game_test.GetAllInsects()[i];
                    cout << "Vous avez choisi : " << insect_moving->GetName() << "\n";

                    vector<vector<int>> temp_coord;

                    vector<Case> list_case;
                    for (int i = 0; i < game_test.GetMap()->GetLength(); i++) {
                        for (int j = 0; j < game_test.GetMap()->GetWidth(); j++) {
                            list_case.push_back(game_test.GetMap()->GetListCase()[i][j]);
                        }
                    }


                    if(insect_moving->GetIsPlaced()==true){
                        choix=1;
                        temp_coord = insect_moving->Possible_Deplacement_Insect(game_test.GetAllInsect_placed(),
                                                                                list_case);
                    }
                    else{
                        choix=0;
                        temp_coord = insect_moving->Possible_Placement_Insect(game_test.GetAllInsect_placed(),
                                                                              list_case);
                    }


                    int h = 0;
                    cout << "Coordonnées possibles :\n " << endl;
                    if (temp_coord.size() == 0) {
                        cout << "Aucune option " << endl;
                    } else {
                        for (auto case_temp: temp_coord) {
                            cout << "I= " << h << " -->  " << " [" << case_temp[0] << ";" << case_temp[1] << "]\n";
                            h++;
                        }
                    }

                    cout << "Coordonnées ?\nx=";
                    cin >> choice_x;
                    cout << "y=";
                    cin >> choice_y;
                    cout << "Vous avez choisi : " << choix << endl;


                    bool resultat;
                    if (choix == 0) {
                        PlacementCommand plac = PlacementCommand(game_test.GetState(), {choice_x, choice_y},
                                                                 *insect_moving,
                                                                 PLACEMENT, *player_test, temp_coord);
                        resultat = plac.execute(engine_test);
                    } else {
                        DeplacementCommand deplac = DeplacementCommand(game_test.GetState(), {choice_x, choice_y},
                                                                       *insect_moving,
                                                                       DEPLACEMENT, *player_test, temp_coord);
                        resultat = deplac.execute(engine_test);
                    }


                    if (resultat) { cout << "Placement effectué" << endl; }
                    else {
                        cout << "Placement non effectué" << endl;
                        while (resultat == false) {
                            cout << "Coordonnées ?\nx=";
                            cin >> choice_x;
                            cout << "y=";
                            cin >> choice_y;
                            cout << "Vous avez choisi : " << choix << endl;


                            PlacementCommand plac = PlacementCommand(game_test.GetState(), {choice_x, choice_y},
                                                                     *insect_moving,
                                                                     PLACEMENT, *player_test, temp_coord);
                            resultat = plac.execute(engine_test);
                        }
                        cout << "Placement effectué" << endl;
                    }


                    i = 0;

                    for (auto &ins: game_test.GetAllInsects()) {
                        cout << "I= " << i << " -->  " << ins->GetName() << "  |  " << ins->GetColor() << "  |  ["
                             << ins->Get_Position()[0] << ";" << ins->Get_Position()[1] << "]\n";
                        i++;
                    }

                    //AFFICHAGE DE LA MAP
                    for (int a = 0; a < game_test.GetMap()->GetLength(); a++) {
                        for (int b = 0; b < game_test.GetMap()->GetWidth(); b++) {
                            cout << "  [" << game_test.GetMap()->GetListCase()[a][b].Get_i() << "|"
                                 << game_test.GetMap()->GetListCase()[a][b].Get_j() << "|"
                                 << game_test.GetMap()->GetListCase()[a][b].GetEmpty() << "]";
                            if (b == game_test.GetMap()->GetWidth() - 1) {
                                cout << "\n" << endl;
                            }
                        }
                    }
                    if (game_test.GetState() == Player_A_playing) {
                        game_test.UpdateState(Player_B_playing);
                    } else {
                        game_test.UpdateState(Player_A_playing);
                    }
                    cout<<"FIN JOUEUR\n"<<endl;
                }
                }
                nbTour++;
            }


        }

    else if ((string)argv[argc-1]=="engine_ai") {

        RandomAI ai_test = *new RandomAI(game_test, Giroud.GetColor());

        /*---------------------------------------------RENDER--INIT------------------------------------------------------------------*/
        sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "HIVE",
                                sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
        Scene scene = Scene(game_test);
        sf::Font font; //Police écriture
        if (!font.loadFromFile("./res/arial.ttf"))
            return EXIT_FAILURE;
        sf::Text text("Hello SFML", font, 20);

        float X = window.getSize().x;
        float Y = window.getSize().y;
        float xo = window.getSize().x;
        float yo = window.getSize().y;
        float sx = 1.0, sy = 1.0;
        int posx;
        int posy;
        int etat = 0;
        vector<vector<int>> temp_coord;
        vector<int> temp_selected;
        Insect *insect_moving = nullptr;
        Player *player_temp = &Benzema;

        std::vector<std::vector<sf::Vector2f>> mapPixelPosition;
        mapPixelPosition = scene.mapDraw.mapPixelPosition;

        /*-----------------------------------------------FIN-RENDER---INIT----------------------------------------------------------*/

        Engine engine_test = *new Engine(game_test);

        cout << "---------------------DEBUT DU JEU---------------------" << endl;

        int nbTour = 0;
        int AI_turn=0;
        while (window.isOpen()) {
            window.clear();


            if(AI_turn==0) {


                int xmouse = sf::Mouse::getPosition(window).x;
                int ymouse = sf::Mouse::getPosition(window).y;


                sf::Event event;
                while (window.pollEvent(event)) {

                    if (event.type == sf::Event::Closed)
                        window.close();
                    if (event.type == sf::Event::Resized) {
                        //sx =   float(WIDTH/window.getSize().x) ;
                        //sy =  float(HEIGHT/window.getSize().y);
                        X = (window.getSize().x);
                        Y = (window.getSize().y);

                    }

                    if (event.type == sf::Event::MouseButtonPressed) {

                        if (event.mouseButton.button == sf::Mouse::Left) {

                            posx = int(event.mouseButton.x * (xo / X));
                            posy = int(event.mouseButton.y * (yo / Y));

                            string insect_selected = scene.insectDraw.getPressedInsect(posx, posy, game_test);

                            int i = 0;
                            int number = 0;
                            bool found = 0;

                            if (etat == 0) {
                                for (auto &ins: game_test.GetAllInsects()) {
                                    if (found == false) {
                                        if (ins->GetName() == insect_selected) {
                                            found = true;
                                            etat = 1;
                                            number = i;
                                        }
                                        ++i;
                                    }
                                }
                            }
                            if (etat == 1) {
                                insect_moving = game_test.GetAllInsects()[number];
                                cout << "Vous avez choisi : " << insect_moving->GetName() << "\n";
                                found = false;

                                i = 0;
                                vector<Case> list_case;

                                for (int i = 0; i < game_test.GetMap()->GetLength(); i++) {
                                    for (int j = 0; j < game_test.GetMap()->GetWidth(); j++) {
                                        list_case.push_back(game_test.GetMap()->GetListCase()[i][j]);
                                    }
                                }
                                if (!insect_moving->GetIsPlaced()) {
                                    temp_coord = insect_moving->Possible_Placement_Insect(
                                            game_test.GetAllInsect_placed(),
                                            list_case);
                                } else if (insect_moving->GetIsPlaced()) {
                                    temp_coord = insect_moving->Possible_Deplacement_Insect(
                                            game_test.GetAllInsect_placed(),
                                            list_case);
                                }
                                if (temp_coord.size() != 0) {
                                    etat = 2;
                                } else {
                                    etat = 4;
                                    cout << "Aucune solution\n" << endl;
                                }
                            }
                            else if (etat == 2) {
                                temp_selected = scene.mapDraw.getPressedTiles(posx, posy);
                                if (temp_selected[0] != -1) {
                                    etat = 3;
                                    cout << "confirmez\n";
                                }
                                else {
                                    etat = 0;
                                    cout << "reselectionnez\n";
                                }
                            }
                            else if (etat == 3) {


                                if (!insect_moving->GetIsPlaced()) {
                                    PlacementCommand plac = PlacementCommand(game_test.GetState(), temp_selected,
                                                                             *insect_moving,
                                                                             PLACEMENT, *player_temp, temp_coord);
                                    plac.execute(engine_test);
                                } else if (insect_moving->GetIsPlaced()) {
                                    DeplacementCommand deplac = DeplacementCommand(game_test.GetState(), temp_selected,
                                                                                   *insect_moving,
                                                                                   DEPLACEMENT, *player_temp,
                                                                                   temp_coord);
                                    deplac.execute(engine_test);
                                }

                                if (game_test.GetState() == state::Player_A_playing) {
                                    player_temp = &Benzema;
                                } else if (game_test.GetState() == state::Player_B_playing) {
                                    player_temp = &Giroud;
                                    AI_turn=1;
                                }

                                etat = 0;
                            }
                            else if (etat == 4) {
                                etat = 0;
                            }
                        }

                    }

                }
                int xi = int((xmouse) * (xo / X));
                int yi = int((ymouse) * (yo / Y));

                std::stringstream ss;
                ss << "X " << xi << "\n"
                   << "Y " << yi << "\n";


                window.clear();
                text.setString(ss.str());
                window.draw(text);

                scene.drawScene(game_test, window);

                if (etat == 2) {
                    for (auto i: temp_coord) {
                        temphexa.setPosition(mapPixelPosition[i[0]][i[1]]);
                        window.draw(temphexa);
                    }
                }
                if (etat == 3) {
                    if (!temp_selected.empty()) {
                        temphexa.setPosition(mapPixelPosition[temp_selected[0]][temp_selected[1]]);
                        window.draw(temphexa);
                    }
                }

                window.display();
            }
            else {

                bool resultat = false;

                while (resultat == false) {
                    vector<vector<int>> temp_coord_AI;
                    vector<int> command_list = ai_test.runAI();
                    cout << "FIN RUN AI\n" << endl;


                    cout << "DEBUT TRAITEMENT RETOURNE PAR AI\n" << endl;

                    cout << "Contenu de command list: " << command_list[0] << " , " << command_list[1] << " , "
                         << command_list[2] << " , " << command_list[3] << endl;


                    Insect *insect_moving = game_test.GetAllInsects()[command_list[3]];
                    vector<Case> list_case;
                    for (int i = 0; i < game_test.GetMap()->GetLength(); i++) {
                        for (int j = 0; j < game_test.GetMap()->GetWidth(); j++) {
                            list_case.push_back(game_test.GetMap()->GetListCase()[i][j]);
                        }
                    }


                    if (command_list[0] == 0) {
                        cout << "choix de placement\n" << endl;
                        temp_coord_AI = insect_moving->Possible_Placement_Insect(game_test.GetAllInsect_placed(),
                                                                                 list_case);
                        PlacementCommand plac = PlacementCommand(game_test.GetState(),
                                                                 {command_list[1], command_list[2]},
                                                                 *insect_moving,
                                                                 PLACEMENT, Giroud, temp_coord_AI);
                        bool resultat = plac.execute(engine_test);
                        if (resultat) {
                            cout << "Placement effectué" << endl;
                            AI_turn = 0;
                            if (game_test.GetState() == state::Player_A_playing) {
                                player_temp = &Benzema;
                            } else if (game_test.GetState() == state::Player_B_playing) {
                                player_temp = &Giroud;
                                AI_turn=1;
                            }
                            cout << "FIN IA\n" << endl;
                            break;
                        }

                    }
                    else {
                        cout << "choix de déplacement\n" << endl;
                        temp_coord_AI = insect_moving->Possible_Deplacement_Insect(game_test.GetAllInsect_placed(),
                                                                                   list_case);


                        DeplacementCommand deplac = DeplacementCommand(game_test.GetState(),
                                                                       {command_list[1], command_list[2]},
                                                                       *insect_moving,
                                                                       DEPLACEMENT, Giroud, temp_coord_AI);
                        resultat = deplac.execute(engine_test);
                        if (resultat) {
                            cout << "Déplacement effectué" << endl;
                            AI_turn = 0;
                            if (game_test.GetState() == state::Player_A_playing) {
                                player_temp = &Benzema;
                            } else if (game_test.GetState() == state::Player_B_playing) {
                                player_temp = &Giroud;
                                AI_turn=1;
                            }
                            cout << "FIN IA\n" << endl;
                            break;
                        }
                    }
                }
            }
        }
    }

    else if ((string)argv[argc-1]=="engine_heur") {


        HeuristicAI ai_test = *new HeuristicAI(game_test, Giroud.GetColor());

        /*---------------------------------------------RENDER--INIT------------------------------------------------------------------*/
        sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "HIVE",
                                sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
        Scene scene = Scene(game_test);
        sf::Font font; //Police écriture
        if (!font.loadFromFile("./res/arial.ttf"))
            return EXIT_FAILURE;
        sf::Text text("Hello SFML", font, 20);


        float X = window.getSize().x;
        float Y = window.getSize().y;
        float xo = window.getSize().x;
        float yo = window.getSize().y;
        float sx = 1.0, sy = 1.0;
        int posx;
        int posy;
        int etat = 0;
        vector<vector<int>> temp_coord;
        vector<int> temp_selected;
        Insect *insect_moving = nullptr;
        Player *player_temp = &Benzema;

        std::vector<std::vector<sf::Vector2f>> mapPixelPosition;
        mapPixelPosition = scene.mapDraw.mapPixelPosition;

        /*-----------------------------------------------FIN-RENDER---INIT----------------------------------------------------------*/

        Engine engine_test = *new Engine(game_test);

        cout << "---------------------DEBUT DU JEU---------------------" << endl;

        int nbTour = 0;
        int AI_turn=0;
        while (window.isOpen()) {
            window.clear();


            if(AI_turn==0) {


                int xmouse = sf::Mouse::getPosition(window).x;
                int ymouse = sf::Mouse::getPosition(window).y;


                sf::Event event;
                while (window.pollEvent(event)) {

                    if (event.type == sf::Event::Closed)
                        window.close();
                    if (event.type == sf::Event::Resized) {
                        //sx =   float(WIDTH/window.getSize().x) ;
                        //sy =  float(HEIGHT/window.getSize().y);
                        X = (window.getSize().x);
                        Y = (window.getSize().y);

                    }

                    if (event.type == sf::Event::MouseButtonPressed) {

                        if (event.mouseButton.button == sf::Mouse::Left) {

                            posx = int(event.mouseButton.x * (xo / X));
                            posy = int(event.mouseButton.y * (yo / Y));

                            string insect_selected = scene.insectDraw.getPressedInsect(posx, posy, game_test);

                            int i = 0;
                            int number = 0;
                            bool found = 0;

                            if (etat == 0) {
                                for (auto &ins: game_test.GetAllInsects()) {
                                    if (found == false) {
                                        if (ins->GetName() == insect_selected) {
                                            found = true;
                                            etat = 1;
                                            number = i;
                                        }
                                        ++i;
                                    }
                                }
                            }
                            if (etat == 1) {
                                insect_moving = game_test.GetAllInsects()[number];
                                cout << "Vous avez choisi : " << insect_moving->GetName() << "\n";
                                found = false;

                                i = 0;
                                vector<Case> list_case;

                                for (int i = 0; i < game_test.GetMap()->GetLength(); i++) {
                                    for (int j = 0; j < game_test.GetMap()->GetWidth(); j++) {
                                        list_case.push_back(game_test.GetMap()->GetListCase()[i][j]);
                                    }
                                }
                                if (!insect_moving->GetIsPlaced()) {
                                    temp_coord = insect_moving->Possible_Placement_Insect(
                                            game_test.GetAllInsect_placed(),
                                            list_case);
                                } else if (insect_moving->GetIsPlaced()) {
                                    temp_coord = insect_moving->Possible_Deplacement_Insect(
                                            game_test.GetAllInsect_placed(),
                                            list_case);
                                }
                                if (temp_coord.size() != 0) {
                                    etat = 2;
                                } else {
                                    etat = 4;
                                    cout << "Aucune solution\n" << endl;
                                }
                            }
                            else if (etat == 2) {
                                temp_selected = scene.mapDraw.getPressedTiles(posx, posy);
                                if (temp_selected[0] != -1) {
                                    etat = 3;
                                    cout << "confirmez\n";
                                }
                                else {
                                    etat = 0;
                                    cout << "reselectionnez\n";
                                }
                            }
                            else if (etat == 3) {


                                if (!insect_moving->GetIsPlaced()) {
                                    PlacementCommand plac = PlacementCommand(game_test.GetState(), temp_selected,
                                                                             *insect_moving,
                                                                             PLACEMENT, *player_temp, temp_coord);
                                    plac.execute(engine_test);
                                } else if (insect_moving->GetIsPlaced()) {
                                    DeplacementCommand deplac = DeplacementCommand(game_test.GetState(), temp_selected,
                                                                                   *insect_moving,
                                                                                   DEPLACEMENT, *player_temp,
                                                                                   temp_coord);
                                    deplac.execute(engine_test);
                                }

                                if (game_test.GetState() == state::Player_A_playing) {
                                    player_temp = &Benzema;
                                } else if (game_test.GetState() == state::Player_B_playing) {
                                    player_temp = &Giroud;
                                    AI_turn=1;
                                }

                                etat = 0;
                            }
                            else if (etat == 4) {
                                etat = 0;
                            }
                        }

                    }

                }
                int xi = int((xmouse) * (xo / X));
                int yi = int((ymouse) * (yo / Y));

                std::stringstream ss;
                ss << "X " << xi << "\n"
                   << "Y " << yi << "\n";


                window.clear();
                text.setString(ss.str());
                window.draw(text);

                scene.drawScene(game_test, window);

                if (etat == 2) {
                    for (auto i: temp_coord) {
                        temphexa.setPosition(mapPixelPosition[i[0]][i[1]]);
                        window.draw(temphexa);
                    }
                }
                if (etat == 3) {
                    if (!temp_selected.empty()) {
                        temphexa.setPosition(mapPixelPosition[temp_selected[0]][temp_selected[1]]);
                        window.draw(temphexa);
                    }
                }

                window.display();
            }
            else {

                bool resultat = false;

                while (resultat == false) {
                    vector<vector<int>> temp_coord_AI;
                    vector<int> command_list = ai_test.runAI();
                    cout << "FIN RUN AI\n" << endl;


                    cout << "DEBUT TRAITEMENT RETOURNE PAR AI\n" << endl;

                    cout << "Contenu de command list: " << command_list[0] << " , " << command_list[1] << " , "
                         << command_list[2] << " , " << command_list[3] << endl;


                    Insect *insect_moving = game_test.GetAllInsects()[command_list[3]];
                    vector<Case> list_case;
                    for (int i = 0; i < game_test.GetMap()->GetLength(); i++) {
                        for (int j = 0; j < game_test.GetMap()->GetWidth(); j++) {
                            list_case.push_back(game_test.GetMap()->GetListCase()[i][j]);
                        }
                    }


                    if (command_list[0] == 0) {
                        cout << "choix de placement\n" << endl;
                        temp_coord_AI = insect_moving->Possible_Placement_Insect(game_test.GetAllInsect_placed(),
                                                                                 list_case);
                        PlacementCommand plac = PlacementCommand(game_test.GetState(),
                                                                 {command_list[1], command_list[2]},
                                                                 *insect_moving,
                                                                 PLACEMENT, Giroud, temp_coord_AI);
                        bool resultat = plac.execute(engine_test);
                        if (resultat) {
                            cout << "Placement effectué" << endl;
                            AI_turn = 0;
                            if (game_test.GetState() == state::Player_A_playing) {
                                player_temp = &Benzema;
                            } else if (game_test.GetState() == state::Player_B_playing) {
                                player_temp = &Giroud;
                                AI_turn=1;
                            }
                            cout << "FIN IA\n" << endl;
                            break;
                        }

                    }
                    else {
                        cout << "choix de déplacement\n" << endl;
                        temp_coord_AI = insect_moving->Possible_Deplacement_Insect(game_test.GetAllInsect_placed(),
                                                                                   list_case);


                        DeplacementCommand deplac = DeplacementCommand(game_test.GetState(),
                                                                       {command_list[1], command_list[2]},
                                                                       *insect_moving,
                                                                       DEPLACEMENT, Giroud, temp_coord_AI);
                        resultat = deplac.execute(engine_test);
                        if (resultat) {
                            cout << "Déplacement effectué" << endl;
                            AI_turn = 0;
                            if (game_test.GetState() == state::Player_A_playing) {
                                player_temp = &Benzema;
                            } else if (game_test.GetState() == state::Player_B_playing) {
                                player_temp = &Giroud;
                                AI_turn=1;
                            }
                            cout << "FIN IA\n" << endl;
                            break;
                        }
                    }
                }
            }
        }
    }

    else if ((string)argv[argc-1]=="randomvsheur") {


        HeuristicAI ai_heur = *new HeuristicAI(game_test, Giroud.GetColor());

        RandomAI ai_rand = *new RandomAI(game_test, Benzema.GetColor());


        /*---------------------------------------------RENDER--INIT------------------------------------------------------------------*/
        sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "HIVE",
                                sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
        Scene scene = Scene(game_test);
        sf::Font font; //Police écriture
        if (!font.loadFromFile("./res/arial.ttf"))
            return EXIT_FAILURE;
        sf::Text text("Hello SFML", font, 20);

    
        float X = window.getSize().x;
        float Y = window.getSize().y;
        float xo = window.getSize().x;
        float yo = window.getSize().y;
        float sx = 1.0, sy = 1.0;
        int posx;
        int posy;
        int etat = 0;
        vector<vector<int>> temp_coord;
        vector<int> temp_selected;
        Insect *insect_moving = nullptr;
        Player *player_temp = &Benzema;

        std::vector<std::vector<sf::Vector2f>> mapPixelPosition;
        mapPixelPosition = scene.mapDraw.mapPixelPosition;

        /*-----------------------------------------------FIN-RENDER---INIT----------------------------------------------------------*/

        Engine engine_test = *new Engine(game_test);

        cout << "---------------------DEBUT DU JEU---------------------" << endl;

        int nbTour = 0;
        int AI_turn=0;
        while (window.isOpen()) {

            window.clear();

            window.draw(text);

            scene.drawScene(game_test, window);

            window.display();

            if(AI_turn==0) {

                bool resultat = false;

                while (resultat == false) {
                    vector<vector<int>> temp_coord_AI;
                    vector<int> command_list = ai_rand.runAI();
                    cout << "FIN RUN AI\n" << endl;


                    cout << "DEBUT TRAITEMENT RETOURNE PAR AI\n" << endl;

                    cout << "Contenu de command list: " << command_list[0] << " , " << command_list[1] << " , "
                         << command_list[2] << " , " << command_list[3] << endl;


                    Insect *insect_moving = game_test.GetAllInsects()[command_list[3]];
                    vector<Case> list_case;
                    for (int i = 0; i < game_test.GetMap()->GetLength(); i++) {
                        for (int j = 0; j < game_test.GetMap()->GetWidth(); j++) {
                            list_case.push_back(game_test.GetMap()->GetListCase()[i][j]);
                        }
                    }


                    if (command_list[0] == 0) {
                        cout << "choix de placement\n" << endl;
                        temp_coord_AI = insect_moving->Possible_Placement_Insect(game_test.GetAllInsect_placed(),
                                                                                 list_case);
                        PlacementCommand plac = PlacementCommand(game_test.GetState(),
                                                                 {command_list[1], command_list[2]},
                                                                 *insect_moving,
                                                                 PLACEMENT, *player_temp, temp_coord_AI);
                        bool resultat = plac.execute(engine_test);
                        if (resultat) {
                            cout << "Placement effectué" << endl;
                            if (game_test.GetState() == state::Player_A_playing) {
                                player_temp = &Benzema;
                                AI_turn=0;
                            } else if (game_test.GetState() == state::Player_B_playing) {
                                player_temp = &Giroud;
                                AI_turn=1;
                            }
                            cout << "FIN IA\n" << endl;
                            break;
                        }

                    }
                    else {
                        cout << "choix de déplacement\n" << endl;
                        temp_coord_AI = insect_moving->Possible_Deplacement_Insect(game_test.GetAllInsect_placed(),
                                                                                   list_case);


                        DeplacementCommand deplac = DeplacementCommand(game_test.GetState(),
                                                                       {command_list[1], command_list[2]},
                                                                       *insect_moving,
                                                                       DEPLACEMENT, *player_temp, temp_coord_AI);
                        resultat = deplac.execute(engine_test);
                        if (resultat) {
                            cout << "Déplacement effectué" << endl;

                            if (game_test.GetState() == state::Player_A_playing) {
                                player_temp = &Giroud;
                                AI_turn=0;
                            } else if (game_test.GetState() == state::Player_B_playing) {
                                player_temp = &Benzema;
                                AI_turn=1;
                            }
                            cout << "FIN IA\n" << endl;
                            break;
                        }
                    }
                }
            }
            else {

                bool resultat = false;

                while (resultat == false) {
                    vector<vector<int>> temp_coord_AI;
                    vector<int> command_list = ai_heur.runAI();
                    cout << "FIN RUN AI\n" << endl;


                    cout << "DEBUT TRAITEMENT RETOURNE PAR AI\n" << endl;

                    cout << "Contenu de command list: " << command_list[0] << " , " << command_list[1] << " , "
                         << command_list[2] << " , " << command_list[3] << endl;


                    Insect *insect_moving = game_test.GetAllInsects()[command_list[3]];
                    vector<Case> list_case;
                    for (int i = 0; i < game_test.GetMap()->GetLength(); i++) {
                        for (int j = 0; j < game_test.GetMap()->GetWidth(); j++) {
                            list_case.push_back(game_test.GetMap()->GetListCase()[i][j]);
                        }
                    }


                    if (command_list[0] == 0) {
                        cout << "choix de placement\n" << endl;
                        temp_coord_AI = insect_moving->Possible_Placement_Insect(game_test.GetAllInsect_placed(),
                                                                                 list_case);
                        PlacementCommand plac = PlacementCommand(game_test.GetState(),
                                                                 {command_list[1], command_list[2]},
                                                                 *insect_moving,
                                                                 PLACEMENT, *player_temp, temp_coord_AI);
                        bool resultat = plac.execute(engine_test);
                        if (resultat) {
                            cout << "Placement effectué" << endl;

                            if (game_test.GetState() == state::Player_A_playing) {
                                player_temp = &Benzema;
                                AI_turn=0;
                            } else if (game_test.GetState() == state::Player_B_playing) {
                                player_temp = &Giroud;
                                AI_turn=1;
                            }
                            cout << "FIN IA\n" << endl;
                            break;
                        }

                    }
                    else {
                        cout << "choix de déplacement\n" << endl;
                        temp_coord_AI = insect_moving->Possible_Deplacement_Insect(game_test.GetAllInsect_placed(),
                                                                                   list_case);


                        DeplacementCommand deplac = DeplacementCommand(game_test.GetState(),
                                                                       {command_list[1], command_list[2]},
                                                                       *insect_moving,
                                                                       DEPLACEMENT, *player_temp, temp_coord_AI);
                        resultat = deplac.execute(engine_test);
                        if (resultat) {
                            cout << "Déplacement effectué" << endl;
                            if (game_test.GetState() == state::Player_A_playing) {
                                player_temp = &Giroud;
                                AI_turn=0;
                            } else if (game_test.GetState() == state::Player_B_playing) {
                                player_temp = &Benzema;
                                AI_turn=1;
                            }
                            cout << "FIN IA\n" << endl;
                            break;
                        }
                    }
                }
            }
        }
    }

    else if((string)argv[argc-1] == "heurvsheur"){

        HeuristicAI ai_heur1 = *new HeuristicAI(game_test, Benzema.GetColor());
        HeuristicAI ai_heur2 = *new HeuristicAI(game_test, Giroud.GetColor());

        /*---------------------------------------------RENDER--INIT------------------------------------------------------------------*/
         sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "HIVE",
                                sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
        Scene scene = Scene(game_test);

        //Pour resize
        float X = window.getSize().x;
        float Y = window.getSize().y;
        float xo = window.getSize().x;
        float yo = window.getSize().y;
        float sx = 1.0, sy = 1.0;
        int posx;
        int posy;

        //init debut du jeu
        int etat = 0;
        vector<vector<int>> temp_coord;
        vector<int> temp_selected;
        Insect *insect_moving = nullptr;
        Player *player_temp = &Benzema;
        AI *ai_temp = &ai_heur1;

        std::vector<std::vector<sf::Vector2f>> mapPixelPosition;
        mapPixelPosition = scene.mapDraw.mapPixelPosition;

        Engine engine_test = *new Engine(game_test);
        bool endgame = false;

        while (window.isOpen()) {

            window.clear();
            scene.drawScene(game_test, window);
            window.display();
            
                    bool resultat = false;

                    while (resultat == false && endgame == false) {
                        vector<vector<int>> temp_coord_AI;
                        vector<int> command_list = ai_temp->runAI();
                        cout << "FIN RUN HEUR\n" << endl;

                        cout << "DEBUT TRAITEMENT RETOURNE PAR HEUR\n" << endl;

                        Insect *insect_moving = game_test.GetAllInsects()[command_list[3]];
                        vector<Case> list_case;
                        for (int i = 0; i < game_test.GetMap()->GetLength(); i++) {
                            for (int j = 0; j < game_test.GetMap()->GetWidth(); j++) {
                                list_case.push_back(game_test.GetMap()->GetListCase()[i][j]);
                            }
                        }


                        if (command_list[0] == 0) {
                            temp_coord_AI = insect_moving->Possible_Placement_Insect(game_test.GetAllInsect_placed(),
                                                                                    list_case);
                            PlacementCommand plac = PlacementCommand(game_test.GetState(),
                                                                    {command_list[1], command_list[2]},
                                                                    *insect_moving,
                                                                    PLACEMENT, *player_temp, temp_coord_AI);
                            bool resultat = plac.execute(engine_test);
                            if (resultat) {
                                cout << "Placement effectué" << endl;

                                if (game_test.GetState() == state::Player_A_playing) {
                                    player_temp = &Benzema;
                                    ai_temp = &ai_heur1;
                                } else if (game_test.GetState() == state::Player_B_playing) {
                                    player_temp = &Giroud;
                                    ai_temp = &ai_heur2;
                                }
                                cout << "FIN HEUR\n" << endl;
                                break;
                            }

                        }
                        else {
                            temp_coord_AI = insect_moving->Possible_Deplacement_Insect(game_test.GetAllInsect_placed(),
                                                                                    list_case);
                            DeplacementCommand deplac = DeplacementCommand(game_test.GetState(),
                                                                        {command_list[1], command_list[2]},
                                                                        *insect_moving,
                                                                        DEPLACEMENT, *player_temp, temp_coord_AI);
                            resultat = deplac.execute(engine_test);
                            if (resultat) {
                                cout << "Déplacement effectué" << endl;
                                if (game_test.GetState() == state::Player_A_playing) {
                                    player_temp = &Benzema;
                                    ai_temp = &ai_heur1;
                                } else if (game_test.GetState() == state::Player_B_playing) {
                                    player_temp = &Giroud;
                                    ai_temp = &ai_heur2;
                                }
                                cout << "FIN HEUR\n" << endl;
                                break;
                            }
                        }
                    
                    if(game_test.GetState() != state::Player_A_playing || game_test.GetState() != state::Player_B_playing){
                        endgame = true;
                        cout << "FIN HEUR\n" << endl;
                        break;
                    }

                 }
        }

    }

    else if ((string)argv[argc-1]=="render"){


        sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "HIVE",sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
        Game state = Game();

        Scene scene = Scene(state);

        Player Benzema = Player("Benzema","White");
        Player Giroud =  Player("Giroud", "Black");

        std::vector<Insect*> temp;
        std::vector<Insect*> temp2;
        Bee Bee_B = Bee("Bee_B", "White", {7,5},0);temp2.push_back(&Bee_B);
        Bee Bee_A = Bee("Bee_A", "Black", {6,5},0); temp.push_back(&Bee_A);
        Bee Ant_B = Bee("Ant_B1", "White", {7,4},0);temp2.push_back(&Ant_B);
        Bee Ant_A = Bee("Ant_A1", "Black", {6,6},0);temp.push_back(&Ant_A);
        Bee Grasshopper_B = Bee("Grasshopper_B1", "White", {6,3},0);temp2.push_back(&Grasshopper_B);
        Bee Grasshopper_A = Bee("Grasshopper_A1", "Black", {6,7},0);temp.push_back(&Grasshopper_A);
        Bee Spider_B = Bee("Spider_B1", "White", {7,3},0);temp2.push_back(&Spider_B);
        Bee Spider_A = Bee("Spider_A1", "Black", {5,7},0);temp.push_back(&Spider_A);

        std::vector<Insect*> temp3;
        std::vector<Insect*> temp4;

        Bee Ant_B2 = Bee("Ant_B2", "White", {7,4},0);temp4.push_back(&Ant_B);
        Bee Ant_A2 = Bee("Ant_A2", "Black", {6,6},0);temp3.push_back(&Ant_A);
        Bee Grasshopper_B2 = Bee("Grasshopper_B2", "White", {6,3},0);temp4.push_back(&Grasshopper_B);
        Bee Grasshopper_A2 = Bee("Grasshopper_A2", "Black", {6,7},0);temp3.push_back(&Grasshopper_A);
        Bee Spider_B2 = Bee("Spider_B2", "White", {7,3},0);temp4.push_back(&Spider_B);
        Bee Spider_A2 = Bee("Spider_A2", "Black", {5,7},0);temp3.push_back(&Spider_A);

        sf::Font font; //Police écriture
        if (!font.loadFromFile("./res/arial.ttf"))
            return EXIT_FAILURE;
        sf::Text text("Hello SFML", font, 20);

        for(auto &i : temp2){
            Giroud.Add_Insect_Played(*i);
        }
        for(auto &j : temp){
            Benzema.Add_Insect_Played(*j);
        }
        for(auto &i : temp4){
            Giroud.Add_Insect_Remaining(*i);
        }
        for(auto &j : temp3){
            Benzema.Add_Insect_Remaining(*j);

        }
        state.AppendListJoueur(Giroud);
        state.AppendListJoueur(Benzema);

        cout<<"AVANT"<<endl;
        cout<<state.GetListPlayer()[0]->GetName() <<"\n"<<endl;
        cout<<"APRES"<<endl;
        state.GetListPlayer()[0]->setName("RONALDO");
        cout<<state.GetListPlayer()[0]->GetName() <<"\n"<<endl;


        float X = window.getSize().x;
        float Y = window.getSize().y;
        float xo = window.getSize().x;
        float yo = window.getSize().y;

        float sx=1.0, sy=1.0;

        while (window.isOpen()) {
            int xmouse = sf::Mouse::getPosition(window).x;
            int ymouse = sf::Mouse::getPosition(window).y;



            sf::Event event;
            while (window.pollEvent(event)) {

                if (event.type == sf::Event::Closed)
                    window.close();
                if(event.type == sf::Event::Resized){
                    //sx =   float(WIDTH/window.getSize().x) ;
                    //sy =  float(HEIGHT/window.getSize().y);
                    X = (window.getSize().x);
                    Y = (window.getSize().y);
                }

                if (event.type == sf::Event::MouseButtonPressed){

                    if(event.mouseButton.button == sf::Mouse::Left){
                        //int posx = event.mouseButton.x * sx;
                        //int posy = event.mouseButton.y * sy;
                        //scene.insectDraw.getPressedInsect(posx,posy);
                        int posx = int(event.mouseButton.x * (xo/X));
                        int posy = int(event.mouseButton.y * (yo/Y));
                        //scene.insectDraw.getPressedInsect(posx,posy);
                        scene.mapDraw.getPressedTiles(posx,posy);
                    }
                    if(event.mouseButton.button == sf::Mouse::Right){

                        for(auto k : state.GetAllInsects()){
                            std::cout<<k->GetName()<<std::endl;
                        }

                        std::cout << "left click\n" << std ::endl;
                        std::vector<state::Player*> tempPlayer;
                        Game stateanother = state;
                        for(auto i : stateanother.GetListPlayer()){
                            for(auto j : i->Get_List_Insect_Played()){
                                j->SetPosition({j->Get_Position()[0]+1,j->Get_Position()[1]+1});
                            }
                            stateanother.AppendListJoueur(*i);
                        }
                        state = stateanother;
                    }
                }
            }

            scene.drawScene(state, window);

            //int xi = int(xmouse * sx);
            //int yi = int(ymouse * sy);

            int xi = int((xmouse) * (xo/X));
            int yi = int((ymouse) * (yo/Y));

            std::stringstream ss;
            ss << "X " << xi <<"\n"
               << "Y " << yi << "\n";

            text.setString(ss.str());
            window.draw(text);
            window.display();

        }


    }


    else {
        cout << "It works !" << endl;
    }

    return 0;
}


