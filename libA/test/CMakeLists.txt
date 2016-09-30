set(PROJECT_NAME libA_unit_tests)
project(${PROJECT_NAME})

find_package (Boost COMPONENTS unit_test_framework system filesystem REQUIRED)

set(${PROJECT_NAME}_source
    base_tests.cpp
    main.cpp
    )

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_source})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${Boost_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} A)

add_test(NAME ${PROJECT_NAME}-Tests COMMAND ${PROJECT_NAME})
set_property(TEST ${PROJECT_NAME}-Tests PROPERTY LABELS "unit")

##########################

set(PROJECT_NAME libA_perf_tests)
project(${PROJECT_NAME})

set(${PROJECT_NAME}_source
        perf_tests.cpp
        ../../externals/hayai/src/hayai_posix_main.cpp
    )

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_source})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

target_include_directories(${PROJECT_NAME} PRIVATE
    ../../externals/hayai/src
    ${Boost_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} A)

add_test(NAME ${PROJECT_NAME}-Perf COMMAND ${PROJECT_NAME})
set_property(TEST ${PROJECT_NAME}-Perf PROPERTY LABELS "perf")
