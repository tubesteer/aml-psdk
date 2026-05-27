LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

# Menentukan ekstensi file C++ yang digunakan
LOCAL_CPP_EXTENSION := .cpp .cc

# Nama file .so hasil jadi (Nanti jadinya: libVisualSADox64.so)
LOCAL_MODULE := VisualSADox64

# Pastikan file-file ini ada di dalam folder jni kamu
LOCAL_SRC_FILES := main.cpp mod/logger.cpp mod/config.cpp

# Flag untuk optimasi kode (Menghapus parameter softfp agar aman di 64-bit)
LOCAL_CXXFLAGS += -O3 -DNDEBUG -std=c++17
LOCAL_LDLIBS += -llog

include $(BUILD_SHARED_LIBRARY)
