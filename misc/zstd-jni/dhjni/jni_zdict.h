#include <jni.h>


JNIEXPORT jlong Java_com_github_luben_zstd_Zstd_trainFromBufferDirect0 (JNIEnv *env, jclass obj, jobject samples, jintArray sampleSizes, jobject dictBuffer, jboolean legacy, jint compressionLevel);
JNIEXPORT jlong Java_com_github_luben_zstd_Zstd_trainFromBuffer0 (JNIEnv *env, jclass obj, jobjectArray samples, jbyteArray dictBuffer, jboolean legacy, jint compressionLevel);
