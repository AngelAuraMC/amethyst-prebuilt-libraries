#include <jni.h>


JNIEXPORT jint JNICALL Java_com_github_luben_zstd_ZstdInputStreamNoFinalizer_freeDStream (JNIEnv *env, jclass obj, jlong stream);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_ZstdInputStreamNoFinalizer_decompressStream (JNIEnv *env, jclass obj, jlong stream, jbyteArray dst, jint dst_size, jbyteArray src, jint src_size);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_ZstdInputStreamNoFinalizer_initDStream (JNIEnv *env, jclass obj, jlong stream);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdInputStreamNoFinalizer_recommendedDOutSize (JNIEnv *env, jclass obj);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdInputStreamNoFinalizer_recommendedDInSize (JNIEnv *env, jclass obj);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdInputStreamNoFinalizer_createDStream (JNIEnv *env, jclass obj);
