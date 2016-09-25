#include <boost/exception/all.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/test/unit_test.hpp>
#include <algorithm>
#include <limits>
#include <random>
#include <vector>

#include "libA.h"

template <typename T>
std::vector<T> gen_buffer( size_t size )
{
    std::uniform_int_distribution<T> dist( std::numeric_limits<T>::min(),
                                           std::numeric_limits<T>::max() );
    std::default_random_engine gen( time( 0 ) );

    std::vector<T> buff( size );
    std::generate( buff.begin(), buff.end(), [&]() { return dist( gen ); } );

    return buff;
}

BOOST_AUTO_TEST_SUITE( LibATests )

BOOST_AUTO_TEST_CASE( buffer_is_sorted )
{
    auto buff = gen_buffer<int>( 1024 * 1024 );

    LibA::do_sort( buff );

    BOOST_REQUIRE( std::is_sorted( buff.begin(), buff.end() ) );
}

BOOST_AUTO_TEST_SUITE_END()
