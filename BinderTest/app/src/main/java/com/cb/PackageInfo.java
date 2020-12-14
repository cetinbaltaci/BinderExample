package com.cb;

import android.os.Parcel;
import android.os.Parcelable;

public class PackageInfo  implements Parcelable {
    public int mID;
    public String mName;

    protected PackageInfo(Parcel in) {
        mID = in.readInt();
        mName = in.readString();
    }

    public static final Creator<PackageInfo> CREATOR = new Creator<PackageInfo>() {
        @Override
        public PackageInfo createFromParcel(Parcel in) {
            return new PackageInfo(in);
        }

        @Override
        public PackageInfo[] newArray(int size) {
            return new PackageInfo[size];
        }
    };

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeInt(mID);
        dest.writeString(mName);
    }
}
