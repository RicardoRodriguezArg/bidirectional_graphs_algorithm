project( graph_utils_test )
cmake_minimum_required( VERSION 3.0 )
find_package(Threads REQUIRED)
set (CMAKE_CXX_STANDARD 14)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories (../utils/)
set(UTILS_SRC "../utils/graph_utils.cpp" )

add_executable(utils_tests utils_tests.cpp ${UTILS_SRC})
target_link_libraries(utils_tests
	gtest
    ${CMAKE_THREAD_LIBS_INIT}
	)