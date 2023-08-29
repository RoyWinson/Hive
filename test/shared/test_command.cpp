#include <boost/test/unit_test.hpp>

#include "../../src/shared/state/Game.hpp"
#include "../../src/shared/state/Case.hpp"
#include "../../src/shared/state/Map.hpp"
#include "../../src/shared/state/GameStatus.hpp"
#include "../../src/shared/state/Insect.hpp"
#include "../../src/shared/state/Player.hpp"
#include "../../src/shared/engine/Command.hpp"

#include "vector"

using namespace state;
using namespace std;
using namespace engine;


BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
    BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestCommand){

    {
        Command interact = Command();

        BOOST_CHECK_EQUAL(interact.getPlaying(),Player_A_playing);

        interact.setCommandTypeId(engine::DEPLACEMENT);
        BOOST_CHECK_EQUAL(interact.getCommandTypeId(),DEPLACEMENT);

        interact.setPlaying(state::Player_B_playing);
        BOOST_CHECK_EQUAL(interact.getPlaying(),Player_B_playing);

        BOOST_CHECK_EQUAL(interact.execute(),false);



    }






}