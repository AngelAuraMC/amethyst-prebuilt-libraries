#include <jni.h>

JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdBufferDecompressingStreamNoFinalizer_decompressStreamNative (JNIEnv *env, jclass obj, jlong stream, jbyteArray dst, jint dst_offset, jint dst_size, jbyteArray src, jint src_offset, jint src_size);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdBufferDecompressingStreamNoFinalizer_freeDStreamNative (JNIEnv *env, jclass obj, jlong stream);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdBufferDecompressingStreamNoFinalizer_createDStreamNative (JNIEnv *env, jclass obj);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdBufferDecompressingStreamNoFinalizer_recommendedDOutSizeNative (JNIEnv *env, jclass obj);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdBufferDecompressingStreamNoFinalizer_initDStreamNative (JNIEnv *env, jclass obj, jlong stream);
