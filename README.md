
This is an example of AOSP Native Service and binder.
There are two APIs defined in Native Service. The return value of one is a class. Parcelable is used for this.

> PackageInfo.aidl

    parcelable PackageInfo cpp_header "include/PackageInfo.h";

> PackageInfo.h

    class PackageInfo: public android::Parcelable

The other also uses callback.

> IBinderCommCallback.aidl

    interface IBinderCommCallback {
        void onChangeEvent(int event);
    }

> IBinderCommService.aidl

    void registerCallback(IBinderCommCallback callback);

> BinderCommService.h

    class BinderCommService : public com::cb::BnBinderCommService,...
    {
    ...
    virtual android::binder::Status registerCallback(const android::sp<::com::cb::IBinderCommCallback>& callback) override;
    }

There is also a client application for Android.
