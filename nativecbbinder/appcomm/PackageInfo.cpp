#include "PackageInfo.h"

namespace com{
namespace cb {

    PackageInfo::PackageInfo(int id, std::string name) {
        mID = id;
        mName = name;
    }

    android::status_t PackageInfo::writeToParcel(android::Parcel* parcel) const {
        parcel->writeInt32(mID);
        parcel->writeString16(android::String16(android::String8(mName.c_str())));
        return android::OK;
    }

    android::status_t PackageInfo::readFromParcel(const android::Parcel* parcel) {
        android::String16 temp;
        parcel->readInt32(&mID);
        parcel->readString16(&temp);
        mName = std::string( android::String8(temp).string());  
        return android::OK;
    }
}
}