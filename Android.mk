LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:=       \
        AudioTrackDemoNative.cpp

LOCAL_SHARED_LIBRARIES := \
        libaudioclient libutils libbinder liblog libaudioutils

LOCAL_C_INCLUDES:= \
	system/core/base/include \
	system/media/audio_utils/include

LOCAL_CFLAGS += -Wno-multichar -Werror -Wall

LOCAL_MODULE_TAGS := optional

LOCAL_MODULE:= audiotrackdemonative

include $(BUILD_EXECUTABLE)

