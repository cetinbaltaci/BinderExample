#ifndef __ANDROID_LOG_H__
#define __ANDROID_LOG_H__

#include <stdlib.h>
#include <binder/TextOutput.h>

#include <binder/IInterface.h>
#include <binder/IBinder.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#pragma GCC diagnostic ignored "-Wformat-extra-args"

#ifdef LOG_TAG
#undef LOG_TAG
#endif

#define LOG_TAG "CBBinder"

#define INFO(...) \
    do { \
        printf(__VA_ARGS__); \
        printf("\n"); \
        ALOGD(__VA_ARGS__); \
    } while(0)


#define ASSERT(e) \
    do { \
        if (!(e)) \
            INFO("File: %s:%d ", __FILE__, __LINE__, #e); \
    } while(0)
#define PLOG aout

#endif /* __ANDROID_LOG_H__ */