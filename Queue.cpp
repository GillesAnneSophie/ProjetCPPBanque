/*
 * @author Anne-Sophie GILLES
 */

#include "Queue.h"

Queue::Queue(Bank * bank) {
    this->bank = bank;
    maxLength = integral = 0;
}

double Queue::getAverageLength() {
    //TODO intégrale
    return 0;
}

double Queue::getAverageWaitingTime() {
    return waitingTime/bank->getClientsCount();
}

int Queue::getMaxLength() {
    return maxLength;
}

bool Queue::isEmpty() {
    return clientQueue.empty();
}

void Queue::addClient(Client client) {
    clientQueue.push_back(client);
    int currentSize = clientQueue.size();
    if(currentSize > maxLength){
        maxLength = currentSize;
    }
}

Client Queue::remove() {
    Client client = clientQueue.front();
    clientQueue.pop_front();
    return client;
}

void Queue::setWaitingTime(double waitingTime) {
    this->waitingTime = waitingTime;
}

double Queue::getWaitingTime() {
    return waitingTime;
}