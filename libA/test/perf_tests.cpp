#include "helper.hpp"

#include <libA.h>

#include <hayai.hpp>

class DoTestFixture : public ::hayai::Fixture
{
public:
    virtual void SetUp()
    {
        m_data = std::move( gen_buffer<int>( 1024 * 1024 ) );
    }
    std::vector<int> m_data;
};

BENCHMARK_F( DoTestFixture, CreateTask, 10 /* runs count */,
             1 /* iterations per run */ )
{
    LibA::do_sort( m_data );
}
