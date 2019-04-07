//
// Created by Mateusz Śliwka on 2019-04-04.
//
#include <iostream>
#include <chrono>

#ifndef SDIZO_SLIWKA_TIMER_H
#define SDIZO_SLIWKA_TIMER_H
using namespace std;
using namespace std::chrono;

class Timer {
public:
    high_resolution_clock::time_point timeStart;
    high_resolution_clock::time_point timeEnd;

    void timerStart();

    void timerStop();

    long execTime();
};


#endif //SDIZO_SLIWKA_TIMER_H
