project( graph_utils )
cmake_minimum_required( VERSION 3.0 )

include ( ../cmake_scripts/find_dependencies.cmake )
include ( ../cmake_scripts/compiler_warning.cmake )
set (CMAKE_CXX_STANDARD 14)
include_directories(${GLOG_INCLUDE_DIRS})
set (UITLS_SRC default_dijkstra.h

	)
set (SRC main.cpp ${UTILS_SRC})
add_executable( ${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} ${GLOG_LIBRARIES})
