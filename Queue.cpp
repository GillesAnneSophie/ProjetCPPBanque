/*
 * @author Anne-Sophie GILLES
 */

#include "Queue.h"

Queue::Queue(Bank bank) {
    this->bank = bank;
    maxLength = 0;
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
    return queue.empty();
}

void Queue::addClient(Client client) {
    queue.push_back(client);
    //TODO
}

Client Queue::remove() {
    Client client = queue.front();
    queue.pop_front();
    return client;
}