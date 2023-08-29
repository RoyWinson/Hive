
#include <boost/test/unit_test.hpp>

#include "../../src/shared/state/Case.hpp"

using namespace state;


BOOST_AUTO_TEST_CASE(TestCase)
{
    {
        Case ex =Case({1,2},false); // cree une case avec tableau valeur {1, 2}
        BOOST_CHECK_EQUAL(ex.GetEmpty(), 0);
        BOOST_CHECK_EQUAL(ex.GetPosition()[1],2); // return la valeur de la position 1 qui = 2
        ex.SetEmpty(true);
        BOOST_CHECK_EQUAL(ex.GetEmpty(), true );

        BOOST_CHECK_EQUAL(ex.Get_i(), 1);
        BOOST_CHECK_EQUAL(ex.Get_j(), 2);

        //ex.(21);
        //BOOST_CHECK_EQUAL(ex.x, 21);
    }

    {
        Case ex = Case({1, 2}, false);

        BOOST_CHECK_LE(ex.GetEmpty(), 32); // Less than equal - inferieur ou egal
        BOOST_CHECK_LE(ex.GetPosition()[0],3); // compare la valeur à la positionn 0 qui est 1 < 3
        //ex.(21);
        //BOOST_CHECK_EQUAL(ex.x, 21);

    }



}
