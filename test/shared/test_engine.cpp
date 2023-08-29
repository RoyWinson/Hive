#include <boost/test/unit_test.hpp>

#include "../../src/shared/state/Game.hpp"
#include "../../src/shared/state/Case.hpp"
#include "../../src/shared/state/Map.hpp"
#include "../../src/shared/state/GameStatus.hpp"
#include "../../src/shared/state/Insect.hpp"
#include "../../src/shared/state/Player.hpp"
#include "../../src/shared/engine/Command.hpp"
#include "../../src/shared/engine/Engine.hpp"

#include "vector"

using namespace state;
using namespace std;
using namespace engine;


BOOST_AUTO_TEST_CASE(TestEngine)
    {

        {
            Game game1 = Game();

            Player player1 = Player("Giroud","White");
            Insect insect1 = Insect("Bee","White",{0,0},0);


            Command command1 = Command();
            Command command2 = Command();


            Engine engine1 = Engine(game1);

            BOOST_CHECK_EQUAL(engine1.getState(),&game1);

            command1.setCommandTypeId(engine::DEPLACEMENT);
            engine1.addCommand(command1);
            engine1.addCommand(command2);

            BOOST_CHECK_EQUAL(engine1.listCommands.size(), 2);

            /*engine1.UpdateState(game1,0,insect1,{5,5},player1);

             BOOST_CHECK_EQUAL(insect1.Get_i(), 1);

             engine1.UpdateState(game1,1,insect1,{1,2},player1);

             BOOST_CHECK_EQUAL(insect1.Get_j(), 2); */


        }






    }