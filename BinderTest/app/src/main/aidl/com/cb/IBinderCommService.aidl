package com.cb;

import com.cb.IBinderCommCallback;
import com.cb.PackageInfo;

interface IBinderCommService {
    PackageInfo[] getPackageInfo();
    void registerCallback(IBinderCommCallback callback);
}
