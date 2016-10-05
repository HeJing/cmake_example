#pragma once

#include <vector>

#ifdef WIN32
	#ifdef A_EXPORTS
		#define A_DECLSPEC    __declspec(dllexport)
	#else
		#define A_DECLSPEC    __declspec(dllimport)
	#endif
#else
	#define A_DECLSPEC
#endif

namespace LibA
{
	A_DECLSPEC void do_sort( std::vector<int> &buff );
}
