cmake_minimum_required(VERSION 3.5)

project(lab06)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_executable(lab06 main.cpp aco.cpp bf.cpp)
target_link_libraries(lab06 ${PTHREAD_LIBRARY})

add_executable(lab06_test test.cpp aco.cpp bf.cpp)
target_link_libraries(lab06_test ${PTHREAD_LIBRARY})
