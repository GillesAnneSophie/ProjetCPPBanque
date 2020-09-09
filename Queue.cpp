/*
 * @author Anne-Sophie GILLES
 */

#include "Queue.h"

Queue::Queue(Bank bank) {
    this->bank = bank;
    maxLength = 0;
    //TODO initialiser queue ?
}

double Queue::getAverageLength() {
    //TODO
}

double Queue::getAverageWaitingTime() {
    //TODO
}

int Queue::getMaxLength() {
    return maxLength;
}

bool Queue::isEmpty() {
    return clientQueue.empty();
}

void Queue::addClient(Client client) {
    clientQueue.push_back(client);
    //TODO
}

Client Queue::remove() {
    Client client = clientQueue.front();
    clientQueue.pop_front();
    return client;
}