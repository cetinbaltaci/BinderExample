#ifndef __CBTIMER_H__
#define __CBTIMER_H__

#include <thread>

class CBTimer {
    public:
        CBTimer();
        virtual ~CBTimer();

        void startTimer(int delaySn);
        void stopTimer();

        virtual void runTimer()=0 ; 
    private:
        std::thread mThread;
        bool mStarted;
        int mDelay;
        void _run();
};

#endif