main: main.o Bank.o Simulation.o Client.o Cashier.o Queue.o DiscreteEventSimulation.o Event.o Arrival.o Departure.o CompareEventPriority.o Poisson.o
    g++ -o main objects/main.o objects/Bank.o objects/Simulation.o objects/Client.o objects/Cashier.o objects/Queue.o objects/DiscreteEventSimulation.o objects/Event.o objects/Arrival.o objects/Departure.o objects/CompareEventPriority.o objects/Poisson.o

main.o: main.cpp Simulation.h
    g++ main.cpp -o objects/main.o
Bank.o: Bank.cpp Bank.h Cashier.h Queue.h Simulation.h
    g++ Bank.cpp -o objects/Bank.o
Simulation.o: Simulation.cpp Simulation.h Bank.h DiscreteEventSimulation.h Arrival.h
    g++ Simulation.cpp -o objects/Simulation.o
Client.o: Client.cpp Client.h
    g++ Client.cpp -o objects/Client.o
Cashier.o: Cashier.cpp Cashier.h Bank.h Client.h Departure.h
    g++ Cashier.cpp -o objects/Cashier.o
Queue.o: Queue.cpp Queue.h Client.h Bank.h
    g++ Queue.cpp -o objects/Queue.o
DiscreteEventSimulation.o: DiscreteEventSimulation.cpp DiscreteEventSimulation.h Event.h CompareEventPriority.h
    g++ DiscreteEventSimulation.cpp -o objects/DiscreteEventSimulation.o
Event.o: Event.cpp Event.h
    g++ Event.cpp -o objects/Event.o
Arrival.o: Arrival.cpp Arrival.h Event.h Cashier.h Client.h Simulation.h Poisson.h
    g++ Arrival.cpp -o objects/Arrival.o
Departure.o: Departure.cpp Departure.h Event.h Simulation.h
    g++ Departure.cpp -o objects/Departure.o
CompareEventPriority.o: CompareEventPriority.cpp CompareEventPriority.h Event.h
    g++ CompareEventPriority.cpp -o objects/CompareEventPriority.o
Poisson.o: Poisson.cpp Poisson.h
    g++ Poisson.cpp -o objects/Poisson.o

clean: rm -f main objects/*.o