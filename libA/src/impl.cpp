#include "libA.h"

#include <boost/compute/algorithm/copy.hpp>
#include <boost/compute/algorithm/sort.hpp>
#include <boost/compute/container/vector.hpp>
#include <boost/compute/core.hpp>

namespace compute = boost::compute;

namespace LibA
{
const compute::device select_device()
{
    auto devices = compute::system::devices();
    return *std::find_if( devices.begin(), devices.end(), []( auto const
                                                                  &device ) {
        return device.type() ==
                   compute::device::gpu &&  // we'd like to calculate on GPU
               device.vendor() !=
                   "Intel";  // naive hack for avoiding integrated cards usages
    } );
}

void do_sort( std::vector<int> &buff )
{
    auto                   gpu = select_device();
    compute::context       ctx( gpu );
    compute::command_queue queue( ctx, gpu );

    compute::vector<int> gpu_buff( buff.begin(), buff.end(), queue );

    compute::sort( gpu_buff.begin(), gpu_buff.end(), queue );

    compute::copy( gpu_buff.begin(), gpu_buff.end(), buff.begin(), queue );
}
}
