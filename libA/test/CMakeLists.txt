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

#project(ADASDASDA)
#set(bench_tasks_source
#bench_tests.cpp
#../../externals/hayai/src/hayai_posix_main.cpp
#)

#include_directories(../../externals/hayai/src)

#add_executable(bench_tasks ${bench_tasks_source})
#set_property(TARGET bench_tasks PROPERTY CXX_STANDARD 14)
#set_property(TARGET bench_tasks PROPERTY CXX_STANDARD_REQUIRED ON)
#target_link_libraries(bench_tasks ${Boost_LIBRARIES} task utils)

#add_test(NAME TaskBench COMMAND bench_tasks)
#set_property(TEST TaskBench PROPERTY LABELS "bench")

#set(DATA_FILE data.bin)
#file(COPY ${DATA_FILE} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
#set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES
    #${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${DATA_FILE})
