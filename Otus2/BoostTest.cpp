#define BOOST_TEST_MODULE Otus1BoostTest

#include "QuaterByteAdress.hpp"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(Otus1BoostTest)

BOOST_AUTO_TEST_CASE(versionPatch_valid_version)
{
	BOOST_CHECK(versionPatch() > 0);
	//BOOST_CHECK(versionMin() >= 0);
	//BOOST_CHECK(versionMaj() >= 0);
}

}
