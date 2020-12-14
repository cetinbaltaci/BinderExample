#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/mman.h>

#include "android_log.h"
#include "BinderCommService.h"

using namespace std;

#define VER_MAJOR 0
#define VER_MINOR 1
#define VER_BUILD 3

int main(int argc, char *agrv[]) {
    ALOGD("CB BinderCommService v%d.%d.%d", VER_MAJOR, VER_MINOR, VER_BUILD);
/*
    if(mlockall(MCL_FUTURE|MCL_CURRENT) == -1){
        ALOGD("WARNING: Failed to lock memory");
    }
    struct sched_param sp ;
    sp.sched_priority = 30 ;
    pthread_setschedparam(pthread_self(),SCHED_FIFO,  &sp);
*/

	BinderCommService *binderCommService = new BinderCommService();

	android::defaultServiceManager()->addService(android::String16("nativecbbinder"), binderCommService);
	android::ProcessState::self()->startThreadPool();
	android::IPCThreadState::self()->joinThreadPool();

    delete binderCommService;
    return EXIT_SUCCESS;
}
