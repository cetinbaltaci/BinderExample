LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := nativecbbinder
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_OWNER := CB

LOCAL_AIDL_INCLUDES := $(LOCAL_PATH)/aidl

LOCAL_SRC_FILES :=  main.cpp \
                    appcomm/PackageInfo.cpp \
                    appcomm/BinderCommService.cpp \
                    appcomm/CBTimer.cpp \
                    aidl/com/cb/IBinderCommCallback.aidl aidl/com/cb/IBinderCommService.aidl

LOCAL_INIT_RC := init.nativecbbinder.rc
LOCAL_SHARED_LIBRARIES := libutils libcutils liblog libssl libcrypto libbinder
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include
LOCAL_C_INCLUDES += frameworks/native/include system/core/include
LOCAL_CFLAGS += -Wno-error \
    -Wno-unused-parameter \
    -Wno-format-extra-args
#LOCAL_MULTILIB := 32
include $(BUILD_EXECUTABLE)

include $(call all-makefiles-under,$(LOCAL_PATH))
