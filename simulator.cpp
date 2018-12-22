//
// Created by duchunhui on 2018-12-22.
//

#include "simulator.h"
#include "linkQueue.hpp"
#include "priorityQueue.hpp"
#include <iostream>
using namespace std;

simulator::simulator() {
    cout << "please enter number of server:";
    cin >> noOfServer;
    cout << "please enter low and high arrival time:";
    cin >> arrivalLow >> arrivalHigh;
    cout << "please enter low and high service time:";
    cin >> serviceTimeLow >> serviceTimeHigh;
    cout << "please enter number of custom:";
    cin >> customNum;

    srand(time(NULL));
}

int simulator::avgWaitTime() {
    int serverBusy = 0;
    int currentTime;
    int totalWaitTime = 0;
    linkQueue<eventT> waitQueue;
    priorityQueue<eventT> eventQueue;

    eventT currentEvent;

    //initialize event queue
    int i;
    currentEvent.time = 0;
    currentEvent.Type = 0;
    for (i = 0; i < customNum; ++i) {
        currentEvent.time += arrivalLow + (arrivalHigh - arrivalLow + 1) * rand() / (RAND_MAX + 1);
        eventQueue.enQueue(currentEvent);
    }
    //simulate
    while(!eventQueue.isEmpty()){
        currentEvent = eventQueue.deQueue();
        currentTime = currentEvent.time;
        switch(currentEvent.Type) {
            case 0://deal witch arrival event
                if (serverBusy != noOfServer) {
                    ++serverBusy;
                    currentEvent.time += serviceTimeLow + (serviceTimeHigh - serviceTimeLow) * rand() / (RAND_MAX + 1);
                    currentEvent.Type = 1;
                    eventQueue.enQueue(currentEvent);
                } else waitQueue.enQueue(currentEvent);
                break;
            case 1://deal with leave event
                if (!waitQueue.isEmpty()) {
                    currentEvent = waitQueue.deQueue();
                    totalWaitTime += currentTime - currentEvent.time;
                    currentEvent.time =
                            currentTime + serviceTimeLow + (serviceTimeHigh - serviceTimeLow) * rand() / (RAND_MAX + 1);
                    currentEvent.Type = 1;
                    eventQueue.enQueue(currentEvent);
                } else --serverBusy;
        }
    }
    return totalWaitTime/customNum;
}
