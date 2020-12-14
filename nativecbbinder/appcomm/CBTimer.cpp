#include <iostream>
#include <unistd.h>
#include "CBTimer.h"
#include "android_log.h"

CBTimer::CBTimer() {
    mStarted = false ;
}

CBTimer::~CBTimer() {
    stopTimer();
}

void CBTimer::_run() {
    while(mStarted) {
        sleep(mDelay);
        runTimer();
    }
}

void CBTimer::startTimer(int delaySn) {
    mDelay = delaySn;
    mStarted = true ;
    mThread = std::thread(&CBTimer::_run, this);
    mThread.detach();
    ALOGD("StartTimer");
}

void CBTimer::stopTimer() {
    mStarted = false ;
    ALOGD("StopTimer");
}
