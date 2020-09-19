/*
 * @author Anne-Sophie GILLES
 */

#include "Queue.h"

#include <iostream>
using namespace std;

Queue::Queue(Bank & bank) {
    if(bank.getSimulation().DEBUG){
        cout << "> Queue()" << endl;
    }

    this->bank = &bank;
    maxLength = 0;
    integral = 0;
    waitingTime = 0;

    if(bank.getSimulation().DEBUG){
        cout << "< Queue()" << endl;
    }
}

Queue::Queue(const Queue & queue) {
    this->bank = queue.bank;
    this->clientQueue = queue.clientQueue;
    this->integral = queue.integral;
    this->maxLength = queue.maxLength;
    this->waitingTime = queue.waitingTime;
}

double Queue::getAverageLength() {
    return integral/bank->getSimulation().getRealDuration();
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

void Queue::addClient(Client & client) {
    if(bank->getSimulation().DEBUG){
        cout << "> addClient()" << endl;
    }

    clientQueue.push_back(&client);
    int currentSize = clientQueue.size();
    if(currentSize > maxLength){
        maxLength = currentSize;
    }

    if(bank->getSimulation().DEBUG){
        cout << "< addClient()" << endl;
    }
}

Client * Queue::remove() {
    if(bank->getSimulation().DEBUG){
        cout << "- remove()" << endl;
    }

    Client * client = clientQueue.front();

    double clientWaitingTime = bank->getSimulation().getCurrentTime()-client->getArrivalTime();
    waitingTime += clientWaitingTime;
    integral += clientQueue.size()*(clientWaitingTime);

    clientQueue.pop_front();
    return client;
}