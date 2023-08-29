#include <boost/test/unit_test.hpp>

#include "../../src/shared/state/Bee.hpp"
#include "../../src/shared/state/Spider.hpp"
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

BOOST_AUTO_TEST_CASE(TestBee)
{
    // Bee test
    {
        Game game;
        Bee bee = Bee("Bee","Black",{0,0},0);
        bee.SetIsPlaced(true);
        BOOST_CHECK_EQUAL(bee.Get_i(),0);
    }

    // Deplacement Possible Bee_A J pair [i-1][j] and [i+1][j-1]
    {
        Map maptest = Map(10,10);

        Player player1 = Player("Giroud", "White");
        Player player2 = Player("Roy", "Black");

        // insect Allie
        Bee bee_A = Bee("Bee","White",{2,2},0);
        player1.Add_Insect_Played(bee_A);

        // Setter
        bee_A.SetIsPlaced(true);
        bee_A.SetPosition({2,2});

        // map update
        maptest.SetEmptyCase(false,bee_A.Get_i(),bee_A.Get_j());

        std::vector<Case> list_case;
        for (int i=0;i<maptest.GetLength();i++){
            for (int j=0;j<maptest.GetWidth();j++){
                list_case.push_back( maptest.GetListCase()[i][j]);
            }
        }

        // insect ennemie
        Bee bee_B = Bee("Bee","Black",{0,0},0);

        bee_B.Possible_Placement_Insect({bee_A},list_case);

        //add Bee_B
        player2.Add_Insect_Played(bee_B);

        //Setter
        bee_B.SetIsPlaced(true);
        bee_B.SetPosition({2,1});

        // map update
        maptest.SetEmptyCase(false,bee_B.Get_i(),bee_B.Get_j());

        std::vector<Case> list_case1;
        for (int i=0;i<maptest.GetLength();i++){
            for (int j=0;j<maptest.GetWidth();j++){
                list_case1.push_back( maptest.GetListCase()[i][j]);
            }
        }

        bee_A.Possible_Deplacement_Insect({bee_B},list_case1);
        //  BOOST_CHECK_EQUAL(bee_A.Possible_Deplacement_Insect({bee_B},list_casem).size(),1); test failed approuved
        BOOST_CHECK_EQUAL(bee_A.Possible_Deplacement_Insect({bee_B},list_case1).size(),2);
    }

    // Deplacement Possible Bee_A J impair [i+1][j] and [i-1][j+1]
    {
        Map maptest = Map(10,10);

        Player player1 = Player("Giroud", "White");
        Player player2 = Player("Roy", "Black");

        // Insect Allie
        Bee bee_A = Bee("Bee","White",{0,0},0);

        // Add Insect
        player1.Add_Insect_Played(bee_A);

        // Setter
        bee_A.SetIsPlaced(true);
        bee_A.SetPosition({3,1});

        // insect ennemie
        Bee bee_B = Bee("Bee","Black",{0,0},0);

        // map update
        maptest.SetEmptyCase(false,bee_A.Get_i(),bee_A.Get_j());

        std::vector<Case> list_case;
        for (int i=0;i<maptest.GetLength();i++){
            for (int j=0;j<maptest.GetWidth();j++){
                list_case.push_back( maptest.GetListCase()[i][j]);
            }
        }

        bee_B.Possible_Placement_Insect({bee_A},list_case);

        //add Bee_B
        player2.Add_Insect_Played(bee_B);
        bee_B.SetIsPlaced(true);
        bee_B.SetPosition({3,2});

        // map update
        maptest.SetEmptyCase(false,bee_B.Get_i(),bee_B.Get_j());

        std::vector<Case> list_casem;
        for (int i=0;i<maptest.GetLength();i++){
            for (int j=0;j<maptest.GetWidth();j++){
                list_casem.push_back( maptest.GetListCase()[i][j]);
            }
        }

        bee_A.Possible_Deplacement_Insect({bee_B},list_casem);
    }

    // Deplacement Possible Bee_A J pair [i-1][j] and [i+1][j+1]
    {
        Map maptest = Map(10,10);

        Player player1 = Player("Giroud", "White");
        Player player2 = Player("Roy", "Black");

        // insect Allie
        Bee bee_A = Bee("Bee","White",{0,0},0);

        // add bee_A
        player1.Add_Insect_Played(bee_A);

        // setter
        bee_A.SetIsPlaced(true);
        bee_A.SetPosition({2,2});

        // insect ennemie
        Bee bee_B = Bee("Bee","White",{0,0},0);

        // map update
        maptest.SetEmptyCase(false,bee_A.Get_i(),bee_A.Get_j());

        std::vector<Case> list_case;
        for (int i=0;i<maptest.GetLength();i++){
            for (int j=0;j<maptest.GetWidth();j++){
                list_case.push_back( maptest.GetListCase()[i][j]);
            }
        }

        bee_B.Possible_Placement_Insect({bee_A},list_case);

        //add Bee_B
        player2.Add_Insect_Played(bee_B);
        bee_B.SetIsPlaced(true);
        bee_B.SetPosition({2,3});

        // map update
        maptest.SetEmptyCase(false,bee_B.Get_i(),bee_B.Get_j());

        std::vector<Case> list_casem;
        for (int i=0;i<maptest.GetLength();i++){
            for (int j=0;j<maptest.GetWidth();j++){
                list_casem.push_back( maptest.GetListCase()[i][j]);
            }
        }


        bee_A.Possible_Deplacement_Insect({bee_B},list_casem);

    }


    {
        /****************************************************************** Deplacement Possible Bee_A J pair [i][j+1] and [i][j-1] ***************************************************/
        Map maptest = Map(10,10);

        Player player1 = Player("Giroud", "White");
        Player player2 = Player("Roy", "Black");

        // insect Allie 1 place
        Spider spider_A = Spider("Spider","White",{0,0},0);

        // Add spider_A
        player1.Add_Insect_Played(spider_A);

        // Setter
        spider_A.SetIsPlaced(true);
        spider_A.SetPosition({3,2});

        // map update
        maptest.SetEmptyCase(false,spider_A.Get_i(),spider_A.Get_j());

        std::vector<Case> list_case;
        for (int i=0;i<maptest.GetLength();i++){
            for (int j=0;j<maptest.GetWidth();j++){
                list_case.push_back( maptest.GetListCase()[i][j]);
            }
        }

        // insect ennemie
        Bee bee_B = Bee("Bee","White",{0,0},0);
        bee_B.Possible_Placement_Insect({spider_A},list_case);

        //add Bee_B
        player2.Add_Insect_Played(bee_B);

        // Setter
        bee_B.SetIsPlaced(true);
        bee_B.SetPosition({3,3});

        // map update
        maptest.SetEmptyCase(false,bee_B.Get_i(),bee_B.Get_j());

        std::vector<Case> list_casem;
        for (int i=0;i<maptest.GetLength();i++){
            for (int j=0;j<maptest.GetWidth();j++){
                list_casem.push_back( maptest.GetListCase()[i][j]);
            }
        }

        // insect Bee_A
        Bee bee_A = Bee("Bee","White",{0,0},0);

        bee_A.Possible_Placement_Insect({spider_A},list_casem);

        // add Bee_A
        player1.Add_Insect_Played(bee_A);

        // Setter
        bee_A.SetIsPlaced(true);
        bee_A.SetPosition({4,2});

        // map update
        maptest.SetEmptyCase(false,bee_A.Get_i(),bee_A.Get_j());

        std::vector<Case> list_case1;
        for (int i=0;i<maptest.GetLength();i++){
            for (int j=0;j<maptest.GetWidth();j++){
                list_case1.push_back( maptest.GetListCase()[i][j]);
            }
        }

        bee_A.Possible_Deplacement_Insect({spider_A,bee_B},list_case1);

        BOOST_CHECK_EQUAL((bee_A.Possible_Deplacement_Insect({spider_A,bee_B},list_case1)).size(),2); // Deux deplacement possible

        /******************************************************************************** J impair [i][j-1] and [i-1][j+1] ***********************************************************/


        // setter new position
        bee_A.SetPosition({4,3});

        maptest.SetEmptyCase(false, bee_A.Get_i(),bee_A.Get_j());

        std::vector<Case> list_case2;
        for (int i=0;i<maptest.GetLength();i++){
            for (int j=0;j<maptest.GetWidth();j++){
                list_case2.push_back( maptest.GetListCase()[i][j]);
            }
        }

        bee_A.Possible_Deplacement_Insect({spider_A,bee_B},list_case2);

        /******************************************************************************** J pair [i-1][j] and [i+1][j-1] ***********************************************************/

        // setter new position
        bee_A.SetPosition({3,4});

        maptest.SetEmptyCase(false, bee_A.Get_i(),bee_A.Get_j());

        std::vector<Case> list_case3;
        for (int i=0;i<maptest.GetLength();i++){
            for (int j=0;j<maptest.GetWidth();j++){
                list_case3.push_back( maptest.GetListCase()[i][j]);
            }
        }

        bee_A.Possible_Deplacement_Insect({spider_A,bee_B},list_case3);

        /******************************************************************************** J pair [i+1][j] and [i][j-1] ***********************************************************/

        // setter new position
        bee_A.SetPosition({2,4});

        maptest.SetEmptyCase(false, bee_A.Get_i(),bee_A.Get_j());

        std::vector<Case> list_case4;
        for (int i=0;i<maptest.GetLength();i++){
            for (int j=0;j<maptest.GetWidth();j++){
                list_case4.push_back( maptest.GetListCase()[i][j]);
            }
        }

        bee_A.Possible_Deplacement_Insect({spider_A,bee_B},list_case4);

    }



    {
        Map maptest = Map(10,10);

        Player player1 = Player("Giroud", "White");
        Player player2 = Player("Roy", "Black");

        // insect Allie
        Bee bee_A = Bee("Bee_A","White",{0,0},0);
        Spider spider_A = Spider("Spider_A","White",{0,0},0);
        Spider spider_A1 = Spider("Spider_A1","White",{0,0},0);

        // add bee_A
        player1.Add_Insect_Played(bee_A);
        player1.Add_Insect_Played(spider_A);
        player1.Add_Insect_Played(spider_A1);

        // setter
        bee_A.SetIsPlaced(true);
        spider_A.SetIsPlaced(true);
        spider_A1.SetIsPlaced(true);

        bee_A.SetPosition({3,2});
        spider_A.SetPosition({4,3});
        spider_A1.SetPosition({3,3});

        // map update
        maptest.SetEmptyCase(false,bee_A.Get_i(),bee_A.Get_j());
        maptest.SetEmptyCase(false,spider_A.Get_i(),spider_A.Get_j());
        maptest.SetEmptyCase(false,spider_A1.Get_i(),spider_A1.Get_j());

        // insect ennemie
        Bee bee_B = Bee("Bee_B","Black",{0,0},0);
        Spider spider_B = Spider("Spider_B","Black",{0,0},0);
        Spider spider_B1 = Spider("Spider_B","Black",{0,0},0);

        // add bee_A
        player2.Add_Insect_Played(bee_B);
        player2.Add_Insect_Played(spider_B);
        player2.Add_Insect_Played(spider_B1);

        // setter
        bee_B.SetIsPlaced(true);
        spider_B.SetIsPlaced(true);
        spider_B1.SetIsPlaced(true);

        bee_B.SetPosition({4,1});
        spider_B.SetPosition({3,1});
        spider_B1.SetPosition({2,2});

        // map update
        maptest.SetEmptyCase(false,bee_B.Get_i(),bee_B.Get_j());
        maptest.SetEmptyCase(false,spider_B.Get_i(),spider_B.Get_j());
        maptest.SetEmptyCase(false,spider_B1.Get_i(),spider_B1.Get_j());


        std::vector<Case> list_case;
        for (int i=0;i<maptest.GetLength();i++){
            for (int j=0;j<maptest.GetWidth();j++){
                list_case.push_back( maptest.GetListCase()[i][j]);
            }
        }
        vector<Insect> list_insect_placed;
        list_insect_placed.push_back(bee_A);
        list_insect_placed.push_back(bee_B);
        list_insect_placed.push_back(spider_A);
        list_insect_placed.push_back(spider_B);
        list_insect_placed.push_back(spider_A1);
        list_insect_placed.push_back(spider_B1);

        cout<<"AVANT TEST"<<endl;
        vector<vector<int>>result= bee_B.Possible_Deplacement_Insect(list_insect_placed,list_case);
        cout<<"APRES TEST"<<endl;
        //BOOST_CHECK_EQUAL(result.size(),2);


    }




}