#include <boost/test/unit_test.hpp>

#include "../../src/shared/state/Beetle.hpp"
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

BOOST_AUTO_TEST_CASE(TestBeetle)

    {
        Game game;
        Beetle beetle1 = Beetle("Beetle","Black",{0,0},1);

        beetle1.SetIsPlaced(true);

        BOOST_CHECK_EQUAL(beetle1.Get_i(),0);
    }
