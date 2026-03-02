#include <jni.h>


JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdDirectBufferCompressingStreamNoFinalizer_initCStreamWithFastDict (JNIEnv *env, jclass obj, jlong stream, jobject dict);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdDirectBufferCompressingStreamNoFinalizer_freeCStream (JNIEnv *env, jclass obj, jlong stream);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdDirectBufferCompressingStreamNoFinalizer_compressDirectByteBuffer (JNIEnv *env, jclass obj, jlong stream, jobject dst_buf, jint dst_offset, jint dst_size, jobject src_buf, jint src_offset, jint src_size);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdDirectBufferCompressingStreamNoFinalizer_recommendedCOutSize (JNIEnv *env, jclass obj);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdDirectBufferCompressingStreamNoFinalizer_initCStream (JNIEnv *env, jclass obj, jlong stream, jint level);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdDirectBufferCompressingStreamNoFinalizer_initCStreamWithDict (JNIEnv *env, jclass obj, jlong stream, jbyteArray dict, jint dict_size, jint level);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdDirectBufferCompressingStreamNoFinalizer_endStream (JNIEnv *env, jclass obj, jlong stream, jobject dst_buf, jint dst_offset, jint dst_size);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdDirectBufferCompressingStreamNoFinalizer_createCStream (JNIEnv *env, jclass obj);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdDirectBufferCompressingStreamNoFinalizer_flushStream (JNIEnv *env, jclass obj, jlong stream, jobject dst_buf, jint dst_offset, jint dst_size);
