//
// Created by Mateusz Śliwka on 2019-04-04.
//

#include "Timer.h"
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

void Timer::timerStart() {
    timeStart = high_resolution_clock::now();
}

void Timer::timerStop() {
    timeEnd = high_resolution_clock::now();
}

long Timer::execTime() {
    return duration_cast<nanoseconds>(Timer::timeEnd - Timer::timeStart).count();
}