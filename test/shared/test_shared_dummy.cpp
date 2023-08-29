
#include <boost/test/unit_test.hpp>

#include "../../src/shared/state/Case.hpp"

using namespace ::state;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
  BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestExemple)
{
  {
    Case ex =Case({1,2},false);
    BOOST_CHECK_EQUAL(ex.GetEmpty(), 0);
    //ex.(21);
    //BOOST_CHECK_EQUAL(ex.x, 21);
  }

  {
      Case ex =Case({1,2},false);

    BOOST_CHECK_LE(ex.GetEmpty(), 32); // Less than equal

  }
}

/* vim: set sw=2 sts=2 et : */
