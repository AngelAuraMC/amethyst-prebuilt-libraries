#include <jni.h>


JNIEXPORT jint JNICALL Java_com_github_luben_zstd_ZstdOutputStreamNoFinalizer_resetCStream (JNIEnv *env, jclass obj, jlong stream);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdOutputStreamNoFinalizer_createCStream (JNIEnv *env, jclass obj);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_ZstdOutputStreamNoFinalizer_flushStream (JNIEnv *env, jclass obj, jlong stream, jbyteArray dst, jint dst_size);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_ZstdOutputStreamNoFinalizer_endStream (JNIEnv *env, jclass obj, jlong stream, jbyteArray dst, jint dst_size);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_ZstdOutputStreamNoFinalizer_freeCStream (JNIEnv *env, jclass obj, jlong stream);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_ZstdOutputStreamNoFinalizer_compressStream (JNIEnv *env, jclass obj, jlong stream, jbyteArray dst, jint dst_size, jbyteArray src, jint src_size);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdOutputStreamNoFinalizer_recommendedCOutSize (JNIEnv *env, jclass obj);
