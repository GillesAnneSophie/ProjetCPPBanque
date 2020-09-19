CC=g++
CFLAGS=-W -Wall -ansi -pedantic -g -std=c++11
LDFLAGS=
EXEC=main
OUTPUT_DIR=objects
MKDIR=mkdir -p

all : $(EXEC)

${OUTPUT_DIR}:
	${MKDIR} $(OUTPUT_DIR)

main: ${OUTPUT_DIR} main.o Bank.o Simulation.o Client.o Poisson.o DiscreteEventSimulation.o Event.o Arrival.o Departure.o Cashier.o Queue.o CompareEventPriority.o
	$(CC) -o $@ $(OUTPUT_DIR)/*.o

Queue.o: Queue.cpp Queue.h Client.h Bank.h
	$(CC) -c $< -o $(OUTPUT_DIR)/$@ $(CFLAGS)

Bank.o: Bank.cpp Bank.h Cashier.h Queue.h Simulation.h
	$(CC) -c $< -o $(OUTPUT_DIR)/$@ $(CFLAGS)

Simulation.o: Simulation.cpp Simulation.h Bank.h DiscreteEventSimulation.h Arrival.h
	$(CC) -c $< -o $(OUTPUT_DIR)/$@ $(CFLAGS)

Client.o: Client.cpp Client.h
	$(CC) -c $< -o $(OUTPUT_DIR)/$@ $(CFLAGS)

Cashier.o: Cashier.cpp Departure.h Cashier.h Bank.h Client.h
	$(CC) -c $< -o $(OUTPUT_DIR)/$@ $(CFLAGS)

DiscreteEventSimulation.o: DiscreteEventSimulation.cpp DiscreteEventSimulation.h Event.h CompareEventPriority.h
	$(CC) -c $< -o $(OUTPUT_DIR)/$@ $(CFLAGS)

Event.o: Event.cpp Event.h
	$(CC) -c $< -o $(OUTPUT_DIR)/$@ $(CFLAGS)

Arrival.o: Arrival.cpp Arrival.h Event.h Cashier.h Client.h Simulation.h Poisson.h
	$(CC) -c $< -o $(OUTPUT_DIR)/$@ $(CFLAGS)

Departure.o: Departure.cpp Departure.h Event.h Simulation.h
	$(CC) -c $< -o $(OUTPUT_DIR)/$@ $(CFLAGS)

CompareEventPriority.o: CompareEventPriority.cpp CompareEventPriority.h Event.h
	$(CC) -c $< -o $(OUTPUT_DIR)/$@ $(CFLAGS)

Poisson.o: Poisson.cpp Poisson.h
	$(CC) -c $< -o $(OUTPUT_DIR)/$@ $(CFLAGS)

main.o: main.cpp *.h 
	$(CC) -o $(OUTPUT_DIR)/$@ -c $<

clean:
	rm -rf $(OUTPUT_DIR) $(EXEC) 

mrproper: clean
	rm -rf $(EXEC)