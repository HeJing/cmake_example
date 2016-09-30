#include "helper.hpp"
#include <libA.h>

#include <boost/exception/all.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/test/unit_test.hpp>
#include <algorithm>

BOOST_AUTO_TEST_SUITE( LibATests )

BOOST_AUTO_TEST_CASE( buffer_is_sorted )
{
    auto buff = gen_buffer<int>( 1024 * 1024 );

    LibA::do_sort( buff );

    BOOST_REQUIRE( std::is_sorted( buff.begin(), buff.end() ) );
}

BOOST_AUTO_TEST_SUITE_END()
