
#include <boost/test/unit_test.hpp>

#include "../../src/shared/state/Map.hpp"
#include "../../src/shared/state/Player.hpp"
#include "../../src/shared/state/Case.hpp"
#include "../../src/shared/state/Insect.hpp"
#include "../../src/shared/state/Game.hpp"

#include "vector"

using namespace state;
using namespace std;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
    BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestInsect)
{

        {
            // init
            Insect insect1 = Insect("Bee", "White", {0}, 0);
            BOOST_CHECK_EQUAL(insect1.GetColor(), "White");
            BOOST_CHECK_EQUAL(insect1.GetName(), "Bee");
            BOOST_CHECK_EQUAL(insect1.GetLevel(), 0);
            BOOST_CHECK_EQUAL(insect1.Get_Position()[0], 0);
        }


        {
            Insect insect1 = Insect("Bee", "White", {0,0}, 0);
            Insect insect2 = Insect( "Beetel", "White", {1,0}, 0);

            // coordonnee update

            insect2.SetLevel(1); // scarabee monte
            BOOST_CHECK_EQUAL(insect2.GetLevel(), 1);

            insect1.SetPosition({1,1});
            BOOST_CHECK_EQUAL(insect1.Get_Position()[0], 1);
            insect1.Update_Coord({2,0});
            BOOST_CHECK_EQUAL(insect1.Get_Position()[0], 2);

            // Placed or no

            BOOST_CHECK_EQUAL(insect1.GetIsPlaced(), false);
            //BOOST_CHECK_EQUAL(insect1.GetIsPlaced(), true); impossible deja non place
            insect1.SetIsPlaced(true);
            BOOST_CHECK_EQUAL(insect1.GetIsPlaced(), true);
            BOOST_CHECK_EQUAL(insect2.GetIsPlaced(), false);

            Insect insect3 = Insect("Bee", "White", {0,3}, 0); // {i,j}

            // return coordonne
            BOOST_CHECK_EQUAL(insect3.Get_i(), 0);
            BOOST_CHECK_EQUAL(insect3.Get_j(), 3);

        }

        {
           // Game game;

           Map ex = Map(17,17);

           // liste de case pour insect

            std::vector<Case> list_case;
            for (int i=0;i<ex.GetLength();i++){
                for (int j=0;j<ex.GetWidth();j++){
                    list_case.push_back( ex.GetListCase()[i][j]);
                }
            }

            // insect
            Insect insect1 = Insect("Bee", "White", {0,0}, 0); // pas encore placer
            Insect insect2 = Insect("Spider", "White", {1,1},0); // placer cordonne i = 1; j =1
            Insect insect3 = Insect("Spider", "White", {3,3},0);
            Insect insect4 = Insect("Spider", "White", {},0);

            // placer spider

            insect2.SetIsPlaced(true);
            BOOST_CHECK_EQUAL(insect2.GetIsPlaced(), true);
            BOOST_CHECK_EQUAL(insect2.Get_Position()[0],1);

            // Place Bee avant tour 4
            /*  game.SetIteration(3);
            BOOST_CHECK_EQUAL(game.GetIteration(),3);
            game.GetMap(); */

            // Placement possible insect1 avec insect place

            insect1.Possible_Placement_Insect({insect2},{list_case});
            insect1.Update_Coord({1,2});
            insect1.SetIsPlaced(true);
            BOOST_CHECK_EQUAL(insect1.Get_Position()[0],1);
            BOOST_CHECK_EQUAL(insect1.GetIsPlaced(),true);

            // Placement possible insect4 sans insect

            insect4.Possible_Placement_Insect({insect3},{list_case});
            insect4.SetPosition({2,2});
            BOOST_CHECK_EQUAL(insect4.Get_Position()[1],2);


        }

        {

           Map ex = Map(17,17);

           Player player1 = Player("Roy","Black");
           Player player2 = Player("Giroud","White");

          /* Case case1 = Case({0,0},true);
           Case case2 = Case({1,0},true);
           Case case3 = Case({2,0},true);*/

            // case pour insect 4
/*
           Case case4 = Case({2,1},true);
           Case case5 = Case({1,2},true);
           Case case6 = Case({0,1},true);
           Case case7 = Case({1,1},true);
           Case case8 = Case({3,0},true);
*/
        Case case2 = Case({1,0},true);
        Case case3 = Case({2,0},true);
            Case case6 = Case({0,1},true);
            Case case7 = Case({1,1},true);
           Insect insect1 = Insect("Spider","White",{0,0},0);
           Insect insect2 = Insect("Ladybug","White",{1,0},0);
           Insect insect3 = Insect("Mosquito","White",{2,0},0);
           Insect insect4 = Insect("Spider","White",{2,1},0);
           Insect insect5 = Insect("Cricket","White",{1,2},0);
           Insect insect6 = Insect("Spider","White",{0,1},0);

           Insect insect7 = Insect("Bee","Black",{1,1},0);
           Insect insect8 = Insect("Spider","Black",{3,0},0);

            std::vector<Case> list_case;
            for (int i=0;i<ex.GetLength();i++){
                for (int j=0;j<ex.GetWidth();j++){
                    list_case.push_back( ex.GetListCase()[i][j]);
                }
            }

           /* insect1.SetIsPlaced(true);
            insect2.SetIsPlaced(false);
            insect3.SetIsPlaced(false);
            insect4.SetIsPlaced(false);
            insect5.SetIsPlaced(false);
            insect6.SetIsPlaced(false);
*/
           insect7.SetIsPlaced(false);
           insect8.SetIsPlaced(false);

           player1.Add_Insect_Played(insect7);
           player2.Add_Insect_Played(insect1);

           BOOST_CHECK_EQUAL(insect8.Possible_Placement_Insect({insect7},{case2,case3,case7}).size(),1);

           BOOST_CHECK_EQUAL(player2.Get_List_Insect_Played().size(),1);

           BOOST_CHECK_EQUAL(case6.GetEmpty(), true);
           BOOST_CHECK_EQUAL(case7.GetEmpty(), true);

           insect3.Possible_Placement_Insect({insect1},{list_case});
           insect1.Possible_Placement_Insect({insect7},{list_case});

           insect7.Possible_Deplacement_Insect({insect1},{list_case});

           insect8.Possible_Placement_Insect({insect7},{list_case});
           insect2.Possible_Placement_Insect({insect1},{list_case});
           insect5.Possible_Placement_Insect({insect1},{list_case});

          //  BOOST_CHECK_EQUAL(insect8.Possible_Placement_Insect({},{case1,case2,case3}),3);

        }

        {
            // J impair
            Map maptest = Map(10,10);

            Player player1 = Player("Roy","Black");
            Player player2 = Player("Giroud","White");

            Insect insect1 = Insect("Spider","White",{0,0},0);

            // tableau des case en liste de case

           std::vector<Case> list_case;
            for (int i=0;i<maptest.GetLength();i++){
                for (int j=0;j<maptest.GetWidth();j++){
                    list_case.push_back( maptest.GetListCase()[i][j]);
                }
            }

            insect1.Possible_Placement_Insect({},list_case);


            // insect ennemie

            Insect insect2 = Insect("Spider","White",{1,0},0);
            player2.Add_Insect_Played(insect2);

            Insect insect3 = Insect("Spider","Black",{1,1},0);
            insect3.Possible_Placement_Insect({insect2},list_case);

        }



        { // J paire

            Map maptest = Map(10,10);

            Player player1 = Player("Roy","Black");
            Player player2 = Player("Giroud","White");

            //insect enemie
            Insect insect1 = Insect("Spider","White",{2,1},0);
            Case case1 = Case({2,1},true);
            player2.Add_Insect_Played(insect1);

            //Possible placement j parité pour insect allie

            std::vector<Case> list_case;
            for (int i=0;i<maptest.GetLength();i++){
                for (int j=0;j<maptest.GetWidth();j++){
                    list_case.push_back( maptest.GetListCase()[i][j]);
                }
            }

            Insect insect2 = Insect("Spider","Black",{2,0},0);

            insect2.Possible_Placement_Insect({insect1},{list_case});

        }



        {
            Map maptest = Map(10,10);

            Player player1 = Player("Roy", "Black");
            Player player2 = Player("Giroud", "White");

            // insect ennemie

            Insect insect1 = Insect("Spider","White",{1,6},0);
            player2.Add_Insect_Played(insect1);
            insect1.SetIsPlaced(true);

            // insect alie

            Insect insect2 = Insect("Bee","Black",{0,0},0);
            Insect insect3 = Insect("Spider","Black",{0,0},0);
            Insect insect4 = Insect("Spider","Black",{0,0},0);

            // map update
            maptest.SetEmptyCase(false,insect1.Get_i(),insect1.Get_j());

            std::vector<Case> list_case;
            for (int i=0;i<maptest.GetLength();i++){
                for (int j=0;j<maptest.GetWidth();j++){
                    list_case.push_back( maptest.GetListCase()[i][j]);
                }
            }


            insect2.Possible_Placement_Insect({insect1},list_case);

            //add insect2
            player1.Add_Insect_Played(insect2);
            insect2.SetIsPlaced(true);
            insect2.SetPosition({2,6});
            // map update
            maptest.SetEmptyCase(false,insect2.Get_i(),insect2.Get_j());


            insect3.Possible_Placement_Insect({insect2},{list_case});

            // add insect 3
            player1.Add_Insect_Played(insect3);
            insect2.SetIsPlaced(true);
            insect2.SetPosition({3,6});
            // map update
            maptest.SetEmptyCase(false,insect3.Get_i(),insect3.Get_j());

            insect4.Possible_Placement_Insect({insect1,insect2},{list_case});

        }

        // Placement unique
        {
            Map maptest = Map(10,10);

            Player player1 = Player("Roy", "Black");
            Player player2 = Player("Giroud", "White");

            // insect ennemie

            Insect insect1 = Insect("Bee","White",{1,1},0);
            player2.Add_Insect_Played(insect1);
            insect1.SetIsPlaced(true);

            // insect alie
            Insect insect2 = Insect("Spider","Black",{0,0},0);
            Insect insect3 = Insect("Ladybug","Black",{1,0},0);
            Insect insect4 = Insect("Mosquito","Black",{2,0},0);
            Insect insect5 = Insect("Spider","Black",{2,1},0);
            Insect insect6 = Insect("Cricket","Black",{1,2},0);
            Insect insect7 = Insect("Spider","Black",{0,1},0);

            // map update
            maptest.SetEmptyCase(false,insect1.Get_i(),insect1.Get_j());

            std::vector<Case> list_case;
            for (int i=0;i<maptest.GetLength();i++){
                for (int j=0;j<maptest.GetWidth();j++){
                    list_case.push_back( maptest.GetListCase()[i][j]);
                }
            }

            insect2.Possible_Placement_Insect({insect1},{list_case});

            //add insect2 and map update
            player1.Add_Insect_Played(insect2);
            insect2.SetIsPlaced(true);
            insect2.SetPosition({0,0});
            maptest.SetEmptyCase(false,insect2.Get_i(),insect2.Get_j());
            insect3.Possible_Placement_Insect({insect1,insect2},{list_case});

            // add insect 3
            player1.Add_Insect_Played(insect3);
            insect3.SetIsPlaced(true);
            insect3.SetPosition({1,0});
            maptest.SetEmptyCase(false,insect3.Get_i(),insect3.Get_j());
            insect4.Possible_Placement_Insect({insect1,insect2,insect3},{list_case});

            // add insect 4
            player1.Add_Insect_Played(insect4);
            insect4.SetIsPlaced(true);
            insect4.SetPosition({2,0});
            maptest.SetEmptyCase(false,insect4.Get_i(),insect4.Get_j());
            insect4.Possible_Placement_Insect({insect1,insect2,insect3,insect4},{list_case});

            // add insect 5
            player1.Add_Insect_Played(insect5);
            insect5.SetIsPlaced(true);
            insect5.SetPosition({2,1});
            maptest.SetEmptyCase(false,insect5.Get_i(),insect5.Get_j());
            insect6.Possible_Placement_Insect({insect1,insect2,insect3,insect4,insect5},{list_case});

            // add insect 6
            player1.Add_Insect_Played(insect6);
            insect6.SetIsPlaced(true);
            insect6.SetPosition({1,2});
            maptest.SetEmptyCase(false,insect6.Get_i(),insect6.Get_j());
            insect6.Possible_Placement_Insect({insect1,insect2,insect3,insect4,insect5,insect6},{list_case});

            // add insect 7
            player1.Add_Insect_Played(insect7);
            insect7.SetIsPlaced(true);
            insect7.SetPosition({1,2});
            maptest.SetEmptyCase(false,insect7.Get_i(),insect7.Get_j());
            insect7.Possible_Placement_Insect({insect1,insect2,insect3,insect4,insect5,insect6,insect7},{list_case});

            BOOST_CHECK_EQUAL(insect7.Get_Position()[0],1);
        }

}