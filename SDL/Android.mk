LOCAL_PATH := $(call my-dir)
HERE_PATH := $(LOCAL_PATH)
include $(LOCAL_PATH)/SDL3/Android.mk

LOCAL_PATH := $(HERE_PATH)
# This is a modified snippet taken from the sdl2-compat repository
# Licensed under the zlib license: https://www.libsdl.org/license.php
include $(CLEAR_VARS)
LOCAL_MODULE := SDL2
LOCAL_SHARED_LIBRARIES := SDL3
LOCAL_C_INCLUDES := \
    $(LOCAL_PATH)/overrides \
	$(LOCAL_PATH)/sdl2-compat/include.SDL2 \
	$(LOCAL_PATH)/SDL/include
LOCAL_SRC_FILES := sdl2-compat/src/dynapi/SDL_dynapi.c sdl2-compat/src/sdl2_compat.c
LOCAL_CFLAGS += -DGL_GLEXT_PROTOTYPES -DHAVE_ALLOCA -DHAVE_ALLOCA_H -DSDL_INCLUDE_STDBOOL_H
LOCAL_CFLAGS += -Wall -Wextra -Wno-unused-parameter -Wno-unused-local-typedefs
LOCAL_LDLIBS := -ldl -llog
LOCAL_LDFLAGS := -Wl,--no-undefined
ifeq ($(NDK_DEBUG),1)
    cmd-strip :=
endif

include $(BUILD_SHARED_LIBRARY)
# End snippet
