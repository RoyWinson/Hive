
#include <boost/test/unit_test.hpp>

#include "../../src/shared/state/Map.hpp"
#include "../../src/shared/state/Case.hpp"

using namespace state;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
    BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestMap)
{
    {
        Case case1 = Case({0,0}, true); // cree une case de coordonne {0,0} + voir si elle est vide ou pas
        Map ex = Map(3,3);
        BOOST_CHECK_EQUAL(ex.GetWidth(), 3);
        BOOST_CHECK_EQUAL(ex.GetLength(), 3);
        ex.SetListCase(case1, 2, 2); // cree une case + met dans les coordonne {0,0} jusque les case 2,2
        BOOST_CHECK_EQUAL(ex.GetListCase()[2][2].GetPosition()[0],case1.GetPosition()[0] ); // revoit la valeur position
    }

    {
        Case case1 = Case({0,0}, false); //objet a part de la map
        Map maptest = Map(3,3);

     //  std :: cout << "Get Empty : "<< maptest.GetListCase()[0][0].GetEmpty() << std ::endl;

        maptest.SetEmptyCase(false,0,0);

      //  std :: cout << "Get Empty : "<< maptest.GetListCase()[0][0].GetEmpty() << std :: endl;

        BOOST_CHECK_EQUAL(maptest.GetListCase()[0][0].GetEmpty(), case1.GetEmpty());

    }

}


