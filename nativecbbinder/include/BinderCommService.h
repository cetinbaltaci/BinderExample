#ifndef __BINDERCOMMSERVICE_H__
#define __BINDERCOMMSERVICE_H__

#include <stdlib.h>

#include <com/cb/BnBinderCommService.h>
#include <com/cb/IBinderCommService.h>

#include <binder/TextOutput.h>
#include <vector>

#include <binder/IInterface.h>
#include <binder/IBinder.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include <binder/IAppOpsCallback.h>
#include <binder/BinderService.h>
#include <binder/AppOpsManager.h>

#include <binder/Status.h>

#include "PackageInfo.h"
#include "CBTimer.h"

class BinderCommService : public com::cb::BnBinderCommService,
                        public android::IBinder::DeathRecipient,
                        public CBTimer
{
private:
    int mEventCount ; 
    android::sp<com::cb::IBinderCommCallback> callback_;
    std::mutex mutex_;
    void binderDied(const android::wp<android::IBinder>& who) override;
    void sendMsgToClient(int event);

    void runTimer() override ;
public:
    BinderCommService();
    ~BinderCommService();
    virtual android::binder::Status getPackageInfo(std::vector<com::cb::PackageInfo>*_aidl_return) override;
    virtual android::binder::Status registerCallback(const android::sp<::com::cb::IBinderCommCallback>& callback) override;
};


#endif // __BINDERCOMMSERVICE_H__