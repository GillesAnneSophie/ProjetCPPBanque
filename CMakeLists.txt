cmake_minimum_required(VERSION 3.15)
project(Projet)

set(CMAKE_CXX_STANDARD 14)

add_executable(Projet src/main.cpp src/Bank.cpp src/Simulation.cpp src/Client.cpp src/Cashier.cpp src/Queue.cpp src/DiscreteEventSimulation.cpp src/Event.cpp src/Arrival.cpp src/Departure.cpp src/CompareEventPriority.cpp src/Poisson.cpp)