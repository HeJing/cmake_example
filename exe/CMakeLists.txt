cmake_minimum_required(VERSION 3.6)

if ( ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR} )
    message( FATAL_ERROR "In-source builds not allowed. Please make a new directory and run CMake from there. You may need to remove CMakeCache.txt." )
endif()

set(PROJECT_NAME example)
project(${PROJECT_NAME})

set(Boost_USE_STATIC_LIBS TRUE)
find_package(Boost 1.61 REQUIRED
    COMPONENTS program_options)

include_directories(${BOOST_INCLUDE_DIRS} )

set(example_sources main.cpp)

add_executable(${PROJECT_NAME} ${example_sources})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

target_link_libraries(example ${Boost_LIBRARIES} A)
