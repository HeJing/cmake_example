cmake_minimum_required(VERSION 3.5)

if ( ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR} )
    message( FATAL_ERROR "In-source builds not allowed. Please make a new directory and run CMake from there. You may need to remove CMakeCache.txt." )
endif()

project(ProjectStructureExample)

SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY
    ${PROJECT_BINARY_DIR}/bin
    CACHE PATH
    "Single Directory for all"
    )

SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${PROJECT_BINARY_DIR}/bin
    CACHE PATH
    "Single Directory for all"
    )

SET (CMAKE_ARCHIVE_OUTPUT_DIRECTORY
    ${PROJECT_BINARY_DIR}/lib
    CACHE PATH
    "Single Directory for all"
    )

OPTION (BUILD_SHARED_LIBS "shared" ON)

enable_testing()

add_subdirectory( exe )
add_subdirectory( libA )

set(CPACK_PACKAGE_NAME "TheExample")
set(CPACK_PACKAGE_VERSION "1.0.2")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "CPack Component Example")

include(CPack)
