#include <jni.h>


JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdCompressCtx_init (JNIEnv *env, jclass clazz);
JNIEXPORT void JNICALL Java_com_github_luben_zstd_ZstdDictDecompress_free (JNIEnv *env, jobject obj);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_Zstd_compressFastDict0 (JNIEnv *env, jclass obj, jbyteArray dst, jint dst_offset, jbyteArray src, jint src_offset, jint src_length, jobject dict);
JNIEXPORT void JNICALL Java_com_github_luben_zstd_ZstdDictCompress_init (JNIEnv *env, jobject obj, jbyteArray dict, jint dict_offset, jint dict_size, jint level);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_Zstd_decompressDirectByteBufferFastDict0 (JNIEnv *env, jclass obj, jobject dst, jint dst_offset, jint dst_size, jobject src, jint src_offset, jint src_size, jobject dict);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdCompressCtx_loadCDictFast0 (JNIEnv *env, jclass clazz, jlong ptr, jobject dict);
JNIEXPORT void JNICALL Java_com_github_luben_zstd_ZstdCompressCtx_setLevel0 (JNIEnv *env, jclass clazz, jlong ptr, jint level);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdCompressCtx_loadCDict0 (JNIEnv *env, jclass clazz, jlong ptr, jbyteArray dict);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdDecompressCtx_decompressDirectByteBufferToByteArray0 (JNIEnv *env, jclass jclazz, jlong ptr, jbyteArray dst, jint dst_offset, jint dst_size, jobject src, jint src_offset, jint src_size);
JNIEXPORT void JNICALL Java_com_github_luben_zstd_ZstdDecompressCtx_free (JNIEnv *env, jclass clazz, jlong ptr);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdCompressCtx_setPledgedSrcSize0 (JNIEnv *env, jclass jctx, jlong ptr, jlong src_size);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdDecompressCtx_loadDDict0 (JNIEnv *env, jclass clazz, jlong ptr, jbyteArray dict);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_Zstd_decompressFastDict0 (JNIEnv *env, jclass obj, jbyteArray dst, jint dst_offset, jbyteArray src, jint src_offset, jint src_length, jobject dict);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdDecompressCtx_reset0 (JNIEnv *env, jclass clazz, jlong ptr);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdDecompressCtx_decompressByteArrayToDirectByteBuffer0 (JNIEnv *env, jclass jclazz, jlong ptr, jobject dst, jint dst_offset, jint dst_size, jbyteArray src, jint src_offset, jint src_size);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdCompressCtx_compressByteArray0 (JNIEnv *env, jclass jctx, jlong ptr, jbyteArray dst, jint dst_offset, jint dst_size, jbyteArray src, jint src_offset, jint src_size);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdDecompressCtx_decompressByteArray0 (JNIEnv *env, jclass jclazz, jlong ptr, jbyteArray dst, jint dst_offset, jint dst_size, jbyteArray src, jint src_offset, jint src_size);
JNIEXPORT void JNICALL Java_com_github_luben_zstd_ZstdCompressCtx_free (JNIEnv *env, jclass clazz, jlong ptr);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_Zstd_compressDirectByteBufferFastDict0 (JNIEnv *env, jclass obj, jobject dst, jint dst_offset, jint dst_size, jobject src, jint src_offset, jint src_size, jobject dict);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdDecompressCtx_decompressDirectByteBufferStream0 (JNIEnv *env, jclass jclazz, jlong ptr, jobject dst, jint dst_offset, jint dst_size, jobject src, jint src_offset, jint src_size);
JNIEXPORT void JNICALL Java_com_github_luben_zstd_ZstdDictCompress_free (JNIEnv *env, jobject obj);
JNIEXPORT void JNICALL Java_com_github_luben_zstd_ZstdCompressCtx_setChecksum0 (JNIEnv *env, jclass clazz, jlong ptr, jboolean checksumFlag);
JNIEXPORT void JNICALL Java_com_github_luben_zstd_ZstdDictDecompress_init (JNIEnv *env, jobject obj, jbyteArray dict, jint dict_offset, jint dict_size);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdCompressCtx_compressDirectByteBuffer0 (JNIEnv *env, jclass jctx, jlong ptr, jobject dst, jint dst_offset, jint dst_size, jobject src, jint src_offset, jint src_size);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdDecompressCtx_decompressDirectByteBuffer0 (JNIEnv *env, jclass jclazz, jlong ptr, jobject dst, jint dst_offset, jint dst_size, jobject src, jint src_offset, jint src_size);
JNIEXPORT void JNICALL Java_com_github_luben_zstd_ZstdCompressCtx_setContentSize0 (JNIEnv *env, jclass clazz, jlong ptr, jboolean contentSizeFlag);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdDecompressCtx_loadDDictFast0 (JNIEnv *env, jclass clazz, jlong ptr, jobject dict);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdCompressCtx_compressDirectByteBufferStream0 (JNIEnv *env, jclass jctx, jlong ptr, jobject dst, jint dst_offset, jint dst_size, jobject src, jint src_offset, jint src_size, jint end_op);
JNIEXPORT void JNICALL Java_com_github_luben_zstd_ZstdCompressCtx_setDictID0 (JNIEnv *env, jclass clazz, jlong ptr, jboolean dictIDFlag);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdDecompressCtx_init (JNIEnv *env, jclass clazz);
JNIEXPORT void JNICALL Java_com_github_luben_zstd_ZstdDictCompress_initDirect (JNIEnv *env, jobject obj, jobject dict, jint dict_offset, jint dict_size, jint level, jint byReference);
JNIEXPORT jobject JNICALL Java_com_github_luben_zstd_ZstdCompressCtx_getFrameProgression0 (JNIEnv *env, jclass jctx, jlong ptr);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_ZstdCompressCtx_reset0 (JNIEnv *env, jclass jctx, jlong ptr);
JNIEXPORT void JNICALL Java_com_github_luben_zstd_ZstdDictDecompress_initDirect (JNIEnv *env, jobject obj, jobject dict, jint dict_offset, jint dict_size, jint byReference);
