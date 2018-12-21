project( graph_utils )
cmake_minimum_required( VERSION 3.0 )
include ( ../cmake_scripts/find_dependencies.cmake )
set (SRC main.cpp)
add_executable( ${PROJECT_NAME} ${SRC})

