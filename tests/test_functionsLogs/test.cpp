#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_test_modul
#include <boost/test/unit_test.hpp>
#include "../../resultprinterlib/resultprinter.h"
#include <vector>
using namespace boost::unit_test;

BOOST_AUTO_TEST_CASE(test1)
{

 FunctionLogs f(std::string("AAA"));

 BOOST_CHECK(true);


}	

