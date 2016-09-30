#include "libA.h"

#include "algorithm"

namespace LibA
{
void do_sort( std::vector<int> &buff )
{
    std::sort( buff.begin(), buff.end() );
}
}
