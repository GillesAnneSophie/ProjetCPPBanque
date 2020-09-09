cmake_minimum_required(VERSION 3.15)
project(Projet)

set(CMAKE_CXX_STANDARD 14)

add_executable(Projet main.cpp Bank.cpp Simulation.cpp Client.cpp Cashier.cpp Queue.cpp DiscreteEventSimulation.cpp Event.cpp Arrival.cpp Departure.cpp CompareEventPriority.cpp)