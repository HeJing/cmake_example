#include <algorithm>
#include <limits>
#include <random>

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
