CC=g++
CFLAGS=-W -Wall -ansi -pedantic -g -std=c++11
LDFLAGS=
EXEC=main
OUTPUT_DIR=objects
MKDIR=mkdir -p

all : $(EXEC)

#md: mkdir $(OUTPUT_DIR)

#${OUT_DIR}: ${OUT_DIR}
#	${MKDIR} ${OUTPUT_DIR}
${OUTPUT_DIR}:
	${MKDIR} $(OUTPUT_DIR)

main: ${OUTPUT_DIR} main.o Bank.o Simulation.o Client.o Poisson.o DiscreteEventSimulation.o Event.o Arrival.o Departure.o Cashier.o Queue.o CompareEventPriority.o
	$(CC) -o $@ $(OUTPUT_DIR)/*.o
	#$(CC) -o $@ $(OUTPUT_DIR)/main.o $(OUTPUT_DIR)/Bank.o $(OUTPUT_DIR)/Simulation.o $(OUTPUT_DIR)/Client.o $(OUTPUT_DIR)/Cashier.o $(OUTPUT_DIR)/Queue.o $(OUTPUT_DIR)/DiscreteEventSimulation.o $(OUTPUT_DIR)/Event.o $(OUTPUT_DIR)/Arrival.o $(OUTPUT_DIR)/Departure.o $(OUTPUT_DIR)/CompareEventPriority.o $(OUTPUT_DIR)/Poisson.o

Queue.o: Queue.cpp Queue.h Client.h Bank.h Poisson.h
	$(CC) -c $< -o $(OUTPUT_DIR)/$@ $(CFLAGS)

Bank.o: Bank.cpp Bank.h Cashier.h Queue.h Simulation.h
	$(CC) -c $< -o $(OUTPUT_DIR)/$@ $(CFLAGS)

Simulation.o: Simulation.cpp Simulation.h Bank.h DiscreteEventSimulation.h Arrival.h
	$(CC) -c $< -o $(OUTPUT_DIR)/$@ $(CFLAGS)

Client.o: Client.cpp Client.h
	$(CC) -c $< -o $(OUTPUT_DIR)/$@ $(CFLAGS)

Cashier.o: Cashier.cpp Poisson.h Departure.h Cashier.h Bank.h Client.h
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

#${MKDIR} ${OUTPUT_DIR}
#$(CC) main.cpp -o $(OUTPUT_DIR)/main.o
main.o: main.cpp *.h 
	$(CC) -o $(OUTPUT_DIR)/$@ -c $<

#clean: rm -f main $(OUTPUT_DIR)/*.o

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)