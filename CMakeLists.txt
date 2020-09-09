cmake_minimum_required(VERSION 3.15)
project(Projet)

set(CMAKE_CXX_STANDARD 14)

add_executable(Projet Bank.cpp Simulation.cpp Client.cpp Cashier.cpp Queue.cpp)