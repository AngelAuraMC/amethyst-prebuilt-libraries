#include <jni.h>


JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdDirectBufferDecompressingStreamNoFinalizer_freeDStreamNative (JNIEnv *env, jclass obj, jlong stream);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdDirectBufferDecompressingStreamNoFinalizer_initDStreamNative (JNIEnv *env, jclass obj, jlong stream);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdDirectBufferDecompressingStreamNoFinalizer_recommendedDOutSizeNative (JNIEnv *env, jclass obj);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdDirectBufferDecompressingStreamNoFinalizer_decompressStreamNative (JNIEnv *env, jclass obj, jlong stream, jobject dst_buf, jint dst_offset, jint dst_size, jobject src_buf, jint src_offset, jint src_size);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdDirectBufferDecompressingStreamNoFinalizer_createDStreamNative (JNIEnv *env, jclass obj);
