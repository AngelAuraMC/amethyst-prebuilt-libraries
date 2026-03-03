#include <jni.h>

JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_setSequenceProducerFallback (JNIEnv *env, jclass obj, jlong stream, jboolean fallbackFlag);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_setCompressionTargetLength (JNIEnv *env, jclass obj, jlong stream, jint targetLength);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_windowLogMin (JNIEnv *env, jclass obj);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_blockSizeMax (JNIEnv *env, jclass obj);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_Zstd_compressBound (JNIEnv *env, jclass obj, jlong size);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_hashLogMin (JNIEnv *env, jclass obj);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_setCompressionOverlapLog (JNIEnv *env, jclass obj, jlong stream, jint overlapLog);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_Zstd_decompressUnsafe (JNIEnv *env, jclass obj, jlong dst_buf_ptr, jlong dst_size, jlong src_buf_ptr, jlong src_size);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_Zstd_findDirectByteBufferFrameCompressedSize (JNIEnv *env, jclass obj, jobject src_buf, jint src_offset, jint src_size);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_maxCompressionLevel (JNIEnv *env, jclass obj);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_Zstd_getBuiltinSequenceProducer (JNIEnv *env, jclass obj);
JNIEXPORT void JNICALL Java_com_github_luben_zstd_Zstd_registerSequenceProducer (JNIEnv *env, jclass obj, jlong stream, jlong seqProdState, jlong seqProdFunction);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_setCompressionSearchLog (JNIEnv *env, jclass obj, jlong stream, jint searchLog);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_setCompressionChainLog (JNIEnv *env, jclass obj, jlong stream, jint chainLog);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_setCompressionHashLog (JNIEnv *env, jclass obj, jlong stream, jint hashLog);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_setEnableLongDistanceMatching (JNIEnv *env, jclass obj, jlong stream, jint enableLDM);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_defaultCompressionLevel (JNIEnv *env, jclass obj);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_setCompressionMinMatch (JNIEnv *env, jclass obj, jlong stream, jint minMatch);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_Zstd_getErrorCode (JNIEnv *env, jclass obj, jlong code);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_Zstd_decompressedSize0 (JNIEnv *env, jclass obj, jbyteArray src, jint offset, jint limit, jboolean magicless);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_setCompressionJobSize (JNIEnv *env, jclass obj, jlong stream, jint jobSize);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_Zstd_compressUnsafe (JNIEnv *env, jclass obj, jlong dst_buf_ptr, jlong dst_size, jlong src_buf_ptr, jlong src_size, jint level, jboolean checksumFlag);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_chainLogMax (JNIEnv *env, jclass obj);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_setCompressionMagicless (JNIEnv *env, jclass obj, jlong stream, jboolean enabled);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_setCompressionStrategy (JNIEnv *env, jclass obj, jlong stream, jint strategy);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_Zstd_getDictIdFromFrameBuffer (JNIEnv *env, jclass obj, jobject src);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_searchLogMax (JNIEnv *env, jclass obj);
JNIEXPORT jstring JNICALL Java_com_github_luben_zstd_Zstd_getErrorName (JNIEnv *env, jclass obj, jlong code);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_loadFastDictDecompress (JNIEnv *env, jclass obj, jlong stream, jobject dict);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_Zstd_getStubSequenceProducer (JNIEnv *env, jclass obj);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_setSearchForExternalRepcodes (JNIEnv *env, jclass obj, jlong stream, jint searchRepcodes);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_setValidateSequences (JNIEnv *env, jclass obj, jlong stream, jint validateSequences);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_setCompressionWorkers (JNIEnv *env, jclass obj, jlong stream, jint workers);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_windowLogMax (JNIEnv *env, jclass obj);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_Zstd_decompressedDirectByteBufferSize (JNIEnv *env, jclass obj, jobject src_buf, jint src_offset, jint src_size, jboolean magicless);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_Zstd_findFrameCompressedSize0 (JNIEnv *env, jclass obj, jbyteArray src, jint offset, jint limit);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_hashLogMax (JNIEnv *env, jclass obj);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_loadDictDecompress (JNIEnv *env, jclass obj, jlong stream, jbyteArray dict, jint dict_size);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_Zstd_getDictIdFromFrame (JNIEnv *env, jclass obj, jbyteArray src);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_Zstd_getDictIdFromDict (JNIEnv *env, jclass obj, jbyteArray src);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_loadDictCompress (JNIEnv *env, jclass obj, jlong stream, jbyteArray dict, jint dict_size);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_Zstd_getDictIdFromDictDirect (JNIEnv *env, jclass obj, jobject src, jint offset, jint src_size);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_setCompressionWindowLog (JNIEnv *env, jclass obj, jlong stream, jint windowLog);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_setDecompressionLongMax (JNIEnv *env, jclass obj, jlong stream, jint windowLogMax);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_Zstd_getDirectByteBufferFrameContentSize (JNIEnv *env, jclass obj, jobject src_buf, jint src_offset, jint src_size, jboolean magicless);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_setDecompressionMagicless (JNIEnv *env, jclass obj, jlong stream, jboolean enabled);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_setCompressionChecksums (JNIEnv *env, jclass obj, jlong stream, jboolean enabled);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_magicNumber (JNIEnv *env, jclass obj);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_chainLogMin (JNIEnv *env, jclass obj);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_loadFastDictCompress (JNIEnv *env, jclass obj, jlong stream, jobject dict);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_setRefMultipleDDicts (JNIEnv *env, jclass obj, jlong stream, jboolean enabled);
JNIEXPORT jboolean JNICALL Java_com_github_luben_zstd_Zstd_isError (JNIEnv *env, jclass obj, jlong code);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_setCompressionLevel (JNIEnv *env, jclass obj, jlong stream, jint level);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_searchLogMin (JNIEnv *env, jclass obj);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_setCompressionLong (JNIEnv *env, jclass obj, jlong stream, jint windowLog);
JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_Zstd_getFrameContentSize0 (JNIEnv *env, jclass obj, jbyteArray src, jint offset, jint limit, jboolean magicless);
JNIEXPORT jint JNICALL Java_com_github_luben_zstd_Zstd_minCompressionLevel (JNIEnv *env, jclass obj);
// jni_zstd.c defines it like this so we copy it
#define JNI_ZSTD_ERROR(err, name) \
  JNIEXPORT jlong JNICALL Java_com_github_luben_zstd_Zstd_err##name (JNIEnv *env, jclass obj);

JNI_ZSTD_ERROR(no_error,                      NoError)
JNI_ZSTD_ERROR(GENERIC,                       Generic)
JNI_ZSTD_ERROR(prefix_unknown,                PrefixUnknown)
JNI_ZSTD_ERROR(version_unsupported,           VersionUnsupported)
JNI_ZSTD_ERROR(frameParameter_unsupported,    FrameParameterUnsupported)
JNI_ZSTD_ERROR(frameParameter_windowTooLarge, FrameParameterWindowTooLarge)
JNI_ZSTD_ERROR(corruption_detected,           CorruptionDetected)
JNI_ZSTD_ERROR(checksum_wrong,                ChecksumWrong)
JNI_ZSTD_ERROR(dictionary_corrupted,          DictionaryCorrupted)
JNI_ZSTD_ERROR(dictionary_wrong,              DictionaryWrong)
JNI_ZSTD_ERROR(dictionaryCreation_failed,     DictionaryCreationFailed)
JNI_ZSTD_ERROR(parameter_unsupported,         ParameterUnsupported)
JNI_ZSTD_ERROR(parameter_outOfBound,          ParameterOutOfBound)
JNI_ZSTD_ERROR(tableLog_tooLarge,             TableLogTooLarge)
JNI_ZSTD_ERROR(maxSymbolValue_tooLarge,       MaxSymbolValueTooLarge)
JNI_ZSTD_ERROR(maxSymbolValue_tooSmall,       MaxSymbolValueTooSmall)
JNI_ZSTD_ERROR(stage_wrong,                   StageWrong)
JNI_ZSTD_ERROR(init_missing,                  InitMissing)
JNI_ZSTD_ERROR(memory_allocation,             MemoryAllocation)
JNI_ZSTD_ERROR(workSpace_tooSmall,            WorkSpaceTooSmall)
JNI_ZSTD_ERROR(dstSize_tooSmall,              DstSizeTooSmall)
JNI_ZSTD_ERROR(srcSize_wrong,                 SrcSizeWrong)
JNI_ZSTD_ERROR(dstBuffer_null,                DstBufferNull)
