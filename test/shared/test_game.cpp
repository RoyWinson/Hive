#include <boost/test/unit_test.hpp>

#include "../../src/shared/state/Game.hpp"
#include "../../src/shared/state/Case.hpp"
#include "../../src/shared/state/Map.hpp"
#include "../../src/shared/state/GameStatus.hpp"
#include "../../src/shared/state/Insect.hpp"
#include "../../src/shared/state/Player.hpp"

#include "vector"

using namespace state;
using namespace std;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
    BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestGame)
{
        {

            // constructor

            Game game;

            BOOST_CHECK_EQUAL(game.GetIteration(), 0); // return le nb de tour
            BOOST_CHECK_EQUAL(game.GetState(), Player_A_playing ); // compare l'etat du joueur qui joue de base

             BOOST_CHECK_EQUAL(game.GetMap()->GetWidth(), 17  ); // compare width de game avec == 10
             BOOST_CHECK_EQUAL(game.GetMap()->GetLength(), 10); // compare Length de game avec == 17

            Player player1 = Player("Roy","Black");
            Player player2 = Player("Giroud","White");
            game.AppendListJoueur(player1);

            // Append list

            BOOST_CHECK_EQUAL(game.GetListPlayer().size(),1);

            //BOOST_CHECK_EQUAL(game.GetListPlayer()[0].GetName(),"Roy");
            // BOOST_CHECK_EQUAL(game.GetListPlayer()[0].GetColor(),"Roy"); OK unpassed

            Insect insect1 = Insect("Spider","Black",{0,0},0);
            Insect insect2 = Insect("Spider","Black",{1,0},0);
            Insect insect3 = Insect("Spider","Black",{2,0},0);

            insect1.SetIsPlaced(true);
            insect2.SetIsPlaced(true);
            insect3.SetIsPlaced(true);


            game.AppendListInsect(insect1);
            game.AppendListInsect(insect2);
            game.AppendListInsect(insect3);

            BOOST_CHECK_EQUAL(game.GetAllInsects()[0]->GetName(), "Spider");
            BOOST_CHECK_EQUAL(game.GetAllInsect_placed().size(), 3);

            //  BOOST_CHECK_EQUAL(game.GetAllInsects()[0].Get_Position()[0],0);
           //  game.IsBeeCircled(player1);
           //  BOOST_CHECK_EQUAL(game.GetState(), Player_B_won);

        }

        {
            Game game;
            game.IncrementIteration(); // increment le nb de tour
            game.UpdateState(state::Player_B_playing); // update le joueur
            BOOST_CHECK_EQUAL(game.GetIteration(), 1); // Tour numero 1 == 1
          // BOOST_CHECK_EQUAL(game.GetState(), Player_B_playing);

            game.SetIteration(3);
            BOOST_CHECK_LE(game.GetIteration(), 4 ); // tour 3 < tour 4

        }

        {
            Game game;
            Player player1 = Player("Roy","Black");
            Player player2 = Player("Giroud","White");

            game.AppendListJoueur(player1);
            game.AppendListJoueur(player2);

            BOOST_CHECK_EQUAL(game.GetListPlayer().size(),2);

            game.SetIteration(5);
            BOOST_CHECK_EQUAL(game.GetIteration(),5);

            Insect insect1 = Insect("Spider","White",{0,0},0);
            Insect insect2 = Insect("Ladybug","White",{1,0},0);
            Insect insect3 = Insect("Mosquito","White",{2,0},0);
            Insect insect4 = Insect("Spider","White",{2,1},0);
            Insect insect5 = Insect("Cricket","White",{1,2},0);
            Insect insect6 = Insect("Spider","White",{0,1},0);

            Insect insect7 = Insect("Bee","Black",{1,1},0);
            Insect insect8 = Insect("Spider","Black",{3,0},0);

            // case not empty
            game.GetMap()->SetEmptyCase(false,0,0);
            game.GetMap()->SetEmptyCase(false,1,0);
            game.GetMap()->SetEmptyCase(false,2,0);
            game.GetMap()->SetEmptyCase(false,0,1);
            game.GetMap()->SetEmptyCase(false,2,1);
            game.GetMap()->SetEmptyCase(false,1,2);

            game.GetMap()->SetEmptyCase(false,1,1);
            game.GetMap()->SetEmptyCase(false,3,0);

            //insect placer
            insect1.SetIsPlaced(true);
            insect2.SetIsPlaced(true);
            insect3.SetIsPlaced(true);
            insect4.SetIsPlaced(true);
            insect5.SetIsPlaced(true);
            insect6.SetIsPlaced(true);

            insect7.SetIsPlaced(true);
            insect8.SetIsPlaced(true);

            //add at list
            game.AppendListInsect(insect1);
            game.AppendListInsect(insect2);
            game.AppendListInsect(insect3);
            game.AppendListInsect(insect4);
            game.AppendListInsect(insect5);
            game.AppendListInsect(insect6);
            game.AppendListInsect(insect7);
            game.AppendListInsect(insect8);

            player1.Add_Insect_Played(insect7);
            player1.Add_Insect_Played(insect8);

            player2.Add_Insect_Played(insect1);
            player2.Add_Insect_Played(insect2);
            player2.Add_Insect_Played(insect3);
            player2.Add_Insect_Played(insect4);
            player2.Add_Insect_Played(insect5);
            player2.Add_Insect_Played(insect6);

            BOOST_CHECK_EQUAL(game.GetAllInsect_placed().size(), 8);
            BOOST_CHECK_EQUAL(game.IsBeeCircled(player1), false);
            BOOST_CHECK_EQUAL(player1.Get_List_Insect_Played().size(),2);
            BOOST_CHECK_EQUAL(player2.Get_List_Insect_Played().size(),6);

            BOOST_CHECK_EQUAL(insect7.Get_Position()[0],1);
            BOOST_CHECK_EQUAL(insect7.Get_i(),1);

            BOOST_CHECK_EQUAL(game.GetMap()->GetListCase()[3][0].GetEmpty(), false);
        }

        {
            Game game;

            Player player1 = Player("Giroud","White");
            Player player2 = Player("Roy","Black");


            game.AppendListJoueur(player1);
            game.AppendListJoueur(player2);

            BOOST_CHECK_EQUAL(game.GetListPlayer().size(),2);

            game.SetIteration(5);
            BOOST_CHECK_EQUAL(game.GetIteration(),5);

            // insect ennemie
            Insect insect1 = Insect("Spider","White",{1,2},0);
            Insect insect2 = Insect("Ladybug","White",{2,1},0);
            Insect insect3 = Insect("Mosquito","White",{3,2},0);
            Insect insect4 = Insect("Spider","White",{3,3},0);
            Insect insect5 = Insect("Cricket","White",{2,3},0);
            Insect insect6 = Insect("Spider","White",{1,3},0);

            // Placer insect general
            game.GetMap()->SetEmptyCase(false,1,2);
            game.GetMap()->SetEmptyCase(false,2,1);
            game.GetMap()->SetEmptyCase(false,3,2);
            game.GetMap()->SetEmptyCase(false,3,3);
            game.GetMap()->SetEmptyCase(false,2,3);
            game.GetMap()->SetEmptyCase(false,1,3);


            insect1.SetIsPlaced(true);
            insect2.SetIsPlaced(true);
            insect3.SetIsPlaced(true);
            insect4.SetIsPlaced(true);
            insect5.SetIsPlaced(true);
            insect6.SetIsPlaced(true);


            // insect allie
            Insect insect7 = Insect("Bee","Black",{2,2},0);

            // Placer insect allie
            insect7.SetIsPlaced(true);

            game.GetMap()->SetEmptyCase(false,2,2);

            // ajout sur toute la liste insect

            game.AppendListInsect(insect1);
            game.AppendListInsect(insect2);
            game.AppendListInsect(insect3);
            game.AppendListInsect(insect4);
            game.AppendListInsect(insect5);
            game.AppendListInsect(insect6);
            game.AppendListInsect(insect7);

            // ajouter un insect avec player 1
            player1.Add_Insect_Played(insect1);
            player1.Add_Insect_Played(insect2);
            player1.Add_Insect_Played(insect3);
            player1.Add_Insect_Played(insect4);
            player1.Add_Insect_Played(insect5);
            player1.Add_Insect_Played(insect6);

            // ajouter un insect avec player 2
            player2.Add_Insect_Played(insect7);


            BOOST_CHECK_EQUAL(game.GetAllInsect_placed().size(), 7);
            BOOST_CHECK_EQUAL(game.IsBeeCircled(player2), false); // methode IsBeeCircled à revoir
            BOOST_CHECK_EQUAL(player1.Get_List_Insect_Played().size(),6);
            BOOST_CHECK_EQUAL(player2.Get_List_Insect_Played().size(),1);

            BOOST_CHECK_EQUAL(insect7.Get_Position()[0],2);
            BOOST_CHECK_EQUAL(insect7.Get_i(),2);
        }



}