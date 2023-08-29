
#include <boost/test/unit_test.hpp>

#include "../../src/shared/state/Map.hpp"
#include "../../src/shared/state/Player.hpp"
#include "../../src/shared/state/Case.hpp"
#include "../../src/shared/state/Insect.hpp"


using namespace state;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
    BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestPlayer)
{
    {
     Map map1 = Map(4,4);

    Player player1 = Player("Giroud","White");
    Player player2 = Player("Benzema", "Black");
    BOOST_CHECK_EQUAL(player1.GetName(), "Giroud"); // return Name
    BOOST_CHECK_EQUAL(player1.GetColor(), "White"); // return  Color

    Insect insect1 = Insect("Bee","White",{0,0},0);
    Insect insect2 = Insect("Spider","Black",{0,0},0);
    Insect insect3 = Insect("Grasshooper","Black",{0,0},0);

    player1.Add_Insect_Played(insect1);
    BOOST_CHECK_EQUAL(player1.Get_List_Insect_Played().size(), 1);
    BOOST_CHECK_EQUAL(player2.Get_List_Insect_Played().size(), 0);

    //BOOST_CHECK_EQUAL(player1.Get_List_Insect_Played()[0].GetName(), "Bee");

    player2.Add_Insect_Remaining(insect2);
    player2.Add_Insect_Remaining(insect3);

    BOOST_CHECK_EQUAL(player2.Get_List_Insect_Remaining().size(), 2);

    player2.Remove_Insect_Remaining(insect2);

    BOOST_CHECK_EQUAL(player2.Get_List_Insect_Remaining().size(), 1);

  /* player.Remove_Insect_Remaining(insect1);
   BOOST_CHECK_EQUAL(, 0);
*/

    }

    {
        Player player1 = Player("Giroud","White");
        player1.setName("Benzema");

        BOOST_CHECK_EQUAL(player1.GetName(),"Benzema");

    }

}