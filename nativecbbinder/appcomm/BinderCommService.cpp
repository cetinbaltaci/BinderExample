#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "android_log.h"
#include "BinderCommService.h"


BinderCommService::BinderCommService() {
    ALOGD("BinderCommService");
    mEventCount = 0 ;
    startTimer(5) ;
}

BinderCommService::~BinderCommService() {

}

void BinderCommService::runTimer() {
    mEventCount++; 
    sendMsgToClient(mEventCount);
}

android::binder::Status BinderCommService::getPackageInfo(std::vector<com::cb::PackageInfo>*_aidl_return) {
    std::lock_guard < std::mutex > guard(mutex_);
    
    com::cb::PackageInfo packageInfo(1, "TEST DATA");
    _aidl_return->push_back(packageInfo);

    return android::binder::Status::ok();
}

android::binder::Status BinderCommService::registerCallback(const android::sp<::com::cb::IBinderCommCallback>& callback) {
    std::lock_guard < std::mutex > guard(mutex_);

    if (callback_.get()) {
        ALOGD("callback is already registered");
        return android::binder::Status::fromStatusT(android::ALREADY_EXISTS);
    }
    callback_ = callback;
    IInterface::asBinder(callback_)->linkToDeath(this);
    return android::binder::Status::ok();
}

void BinderCommService::binderDied(const android::wp<android::IBinder>& who) {
    std::lock_guard < std::mutex > guard(mutex_);
    callback_ = nullptr;
}

void BinderCommService::sendMsgToClient(int event) {
    if (!callback_.get()) {
        ALOGD("callback_ is null");
        return;
    }
    ALOGD("SendMsgToClient %d", event);
    android::binder::Status ret_status = callback_->onChangeEvent(event);
}

