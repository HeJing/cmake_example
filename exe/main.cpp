#include <algorithm>
#include <boost/program_options.hpp>
#include <iostream>
#include <limits>
#include <random>
#include <vector>
#include <libA.h>

namespace po = boost::program_options;

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

int main( int argc, char *argv[] )
{
    try
    {
        po::options_description desc( "Options" );
        desc.add_options()( "help", "Show help message" )(
            "size", po::value<size_t>(), "Default buffer size" );

        po::variables_map vm;
        po::store( po::parse_command_line( argc, argv, desc ), vm );
        po::notify( vm );

        if( vm.count( "help" ) || !vm.count( "size" ) )
        {
            std::cout << desc << "\n";
            return 1;
        }

        auto buff = gen_buffer<int>( vm["size"].as<size_t>() );

        std::cout << "is_sorted before: " << std::boolalpha
                  << std::is_sorted( buff.begin(), buff.end() ) << std::endl;

        LibA::do_sort( buff );

        std::cout << "is_sorted after: " << std::boolalpha
                  << std::is_sorted( buff.begin(), buff.end() ) << std::endl;
    }
    catch( const po::error &ex )
    {
        std::cerr << ex.what() << '\n';
    }

    return 0;
}
