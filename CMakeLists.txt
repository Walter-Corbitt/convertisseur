set(CMAKE_AUTOMOC ON)
cmake_minimum_required(VERSION 3.15)
project(convertisseur)

set(CMAKE_CXX_STANDARD 14)
find_package(Qt5Widgets)
add_executable(convertisseur main.cpp Fenetre.cpp Fenetre.h )
target_link_libraries(convertisseur Qt5::Widgets)