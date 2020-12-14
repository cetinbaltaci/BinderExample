#ifndef __PACKAGEINFO_H__
#define __PACKAGEINFO_H__

#include <binder/Parcel.h>
#include <binder/Parcelable.h>

namespace com{
namespace cb {
    class PackageInfo: public android::Parcelable {
        public:
            PackageInfo() = default;
            PackageInfo(int id,  std::string name);
            android::status_t writeToParcel(android::Parcel* parcel) const override;
            android::status_t readFromParcel(const android::Parcel* parcel) override;
            int mID;
            std::string mName;
    };
}
}

#endif