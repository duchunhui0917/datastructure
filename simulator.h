//
// Created by duchunhui on 2018-12-22.
//

#ifndef DATASTRUCTURE_SIMULATOR_H
#define DATASTRUCTURE_SIMULATOR_H


class simulator{
    int noOfServer;//number of server
    int arrivalLow;
    int arrivalHigh;
    int serviceTimeLow;
    int serviceTimeHigh;
    int customNum;//number of custom

    struct eventT{
        int time;
        int Type;
        bool operator<(const eventT &e) const { return time<e.time;}
    };

public:
    simulator();
    int avgWaitTime();
};


#endif //DATASTRUCTURE_SIMULATOR_H
