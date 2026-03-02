#include <jni.h>
#include <jni_bufferdecompress_zstd.h>
#include <jni_directbuffercompress_zstd.h>
#include <jni_directbufferdecompress_zstd.h>
#include <jni_fast_zstd.h>
#include <jni_inputstream_zstd.h>
#include <jni_outputstream_zstd.h>
#include <jni_zdict.h>
#include <jni_zstd.h>
// Forwards DH renamed functions back to zstd-jni ones.
// Used because DH 2.4.4 uses the normal zstd-jni ones, newer ones rename to dhcomgithubluben.
#define FORWARD_TO_DH_NOJNI(ret, name, decl, call) \
    JNIEXPORT ret Java_dhcomgithubluben_##name decl { \
        return Java_com_github_luben_##name call; \
    }
#define FORWARD_TO_DH(ret, name, decl, call) \
    JNIEXPORT ret JNICALL Java_dhcomgithubluben_##name decl { \
        return Java_com_github_luben_##name call; \
    }

// jni_bufferdecompress_zstd.c
FORWARD_TO_DH(jlong, zstd_ZstdBufferDecompressingStreamNoFinalizer_decompressStreamNative, (JNIEnv *env, jclass obj, jlong stream, jbyteArray dst, jint dst_offset, jint dst_size, jbyteArray src, jint src_offset, jint src_size), (env, obj, stream, dst, dst_offset, dst_size, src, src_offset, src_size))
FORWARD_TO_DH(jlong, zstd_ZstdBufferDecompressingStreamNoFinalizer_freeDStreamNative, (JNIEnv *env, jclass obj, jlong stream), (env, obj, stream))
FORWARD_TO_DH(jlong, zstd_ZstdBufferDecompressingStreamNoFinalizer_createDStreamNative, (JNIEnv *env, jclass obj), (env, obj))
FORWARD_TO_DH(jlong, zstd_ZstdBufferDecompressingStreamNoFinalizer_recommendedDOutSizeNative, (JNIEnv *env, jclass obj), (env, obj))
FORWARD_TO_DH(jlong, zstd_ZstdBufferDecompressingStreamNoFinalizer_initDStreamNative, (JNIEnv *env, jclass obj, jlong stream), (env, obj, stream))

// jni_directbuffercompress_zstd.c
FORWARD_TO_DH(jlong, zstd_ZstdDirectBufferCompressingStreamNoFinalizer_initCStreamWithFastDict, (JNIEnv *env, jclass obj, jlong stream, jobject dict), (env, obj, stream, dict))
FORWARD_TO_DH(jlong, zstd_ZstdDirectBufferCompressingStreamNoFinalizer_freeCStream, (JNIEnv *env, jclass obj, jlong stream), (env, obj, stream))
FORWARD_TO_DH(jlong, zstd_ZstdDirectBufferCompressingStreamNoFinalizer_compressDirectByteBuffer, (JNIEnv *env, jclass obj, jlong stream, jobject dst_buf, jint dst_offset, jint dst_size, jobject src_buf, jint src_offset, jint src_size), (env, obj, stream, dst_buf, dst_offset, dst_size, src_buf, src_offset, src_size))
FORWARD_TO_DH(jlong, zstd_ZstdDirectBufferCompressingStreamNoFinalizer_recommendedCOutSize, (JNIEnv *env, jclass obj), (env, obj))
FORWARD_TO_DH(jlong, zstd_ZstdDirectBufferCompressingStreamNoFinalizer_initCStream, (JNIEnv *env, jclass obj, jlong stream, jint level), (env, obj, stream, level))
FORWARD_TO_DH(jlong, zstd_ZstdDirectBufferCompressingStreamNoFinalizer_initCStreamWithDict, (JNIEnv *env, jclass obj, jlong stream, jbyteArray dict, jint dict_size, jint level), (env, obj, stream, dict, dict_size, level))
FORWARD_TO_DH(jlong, zstd_ZstdDirectBufferCompressingStreamNoFinalizer_endStream, (JNIEnv *env, jclass obj, jlong stream, jobject dst_buf, jint dst_offset, jint dst_size), (env, obj, stream, dst_buf, dst_offset, dst_size))
FORWARD_TO_DH(jlong, zstd_ZstdDirectBufferCompressingStreamNoFinalizer_createCStream, (JNIEnv *env, jclass obj), (env, obj))
FORWARD_TO_DH(jlong, zstd_ZstdDirectBufferCompressingStreamNoFinalizer_flushStream, (JNIEnv *env, jclass obj, jlong stream, jobject dst_buf, jint dst_offset, jint dst_size), (env, obj, stream, dst_buf, dst_offset, dst_size))

// jni_directbufferdecompress_zstd.c
FORWARD_TO_DH(jlong, zstd_ZstdDirectBufferDecompressingStreamNoFinalizer_freeDStreamNative, (JNIEnv *env, jclass obj, jlong stream), (env, obj, stream))
FORWARD_TO_DH(jlong, zstd_ZstdDirectBufferDecompressingStreamNoFinalizer_initDStreamNative, (JNIEnv *env, jclass obj, jlong stream), (env, obj, stream))
FORWARD_TO_DH(jlong, zstd_ZstdDirectBufferDecompressingStreamNoFinalizer_recommendedDOutSizeNative, (JNIEnv *env, jclass obj), (env, obj))
FORWARD_TO_DH(jlong, zstd_ZstdDirectBufferDecompressingStreamNoFinalizer_decompressStreamNative, (JNIEnv *env, jclass obj, jlong stream, jobject dst_buf, jint dst_offset, jint dst_size, jobject src_buf, jint src_offset, jint src_size), (env, obj, stream, dst_buf, dst_offset, dst_size, src_buf, src_offset, src_size))
FORWARD_TO_DH(jlong, zstd_ZstdDirectBufferDecompressingStreamNoFinalizer_createDStreamNative, (JNIEnv *env, jclass obj), (env, obj))

// jni_fast_zstd.c
FORWARD_TO_DH(jlong, zstd_ZstdCompressCtx_init, (JNIEnv *env, jclass clazz), (env, clazz))
FORWARD_TO_DH(jlong, zstd_ZstdCompressCtx_loadCDictFast0, (JNIEnv *env, jclass clazz, jlong ptr, jobject dict), (env, clazz, ptr, dict))
FORWARD_TO_DH(void, zstd_ZstdCompressCtx_setLevel0, (JNIEnv *env, jclass clazz, jlong ptr, jint level), (env, clazz, ptr, level))
FORWARD_TO_DH(jlong, zstd_ZstdCompressCtx_loadCDict0, (JNIEnv *env, jclass clazz, jlong ptr, jbyteArray dict), (env, clazz, ptr, dict))
FORWARD_TO_DH(jlong, zstd_ZstdCompressCtx_setPledgedSrcSize0, (JNIEnv *env, jclass jctx, jlong ptr, jlong src_size), (env, jctx, ptr, src_size))
FORWARD_TO_DH(jlong, zstd_ZstdCompressCtx_compressByteArray0, (JNIEnv *env, jclass jctx, jlong ptr, jbyteArray dst, jint dst_offset, jint dst_size, jbyteArray src, jint src_offset, jint src_size), (env, jctx, ptr, dst, dst_offset, dst_size, src, src_offset, src_size))
FORWARD_TO_DH(void, zstd_ZstdCompressCtx_free, (JNIEnv *env, jclass clazz, jlong ptr), (env, clazz, ptr))
FORWARD_TO_DH(void, zstd_ZstdCompressCtx_setChecksum0, (JNIEnv *env, jclass clazz, jlong ptr, jboolean checksumFlag), (env, clazz, ptr, checksumFlag))
FORWARD_TO_DH(jlong, zstd_ZstdCompressCtx_compressDirectByteBuffer0, (JNIEnv *env, jclass jctx, jlong ptr, jobject dst, jint dst_offset, jint dst_size, jobject src, jint src_offset, jint src_size), (env, jctx, ptr, dst, dst_offset, dst_size, src, src_offset, src_size))
FORWARD_TO_DH(void, zstd_ZstdCompressCtx_setContentSize0, (JNIEnv *env, jclass clazz, jlong ptr, jboolean contentSizeFlag), (env, clazz, ptr, contentSizeFlag))
FORWARD_TO_DH(jlong, zstd_ZstdCompressCtx_compressDirectByteBufferStream0, (JNIEnv *env, jclass jctx, jlong ptr, jobject dst, jint dst_offset, jint dst_size, jobject src, jint src_offset, jint src_size, jint end_op), (env, jctx, ptr, dst, dst_offset, dst_size, src, src_offset, src_size, end_op))
FORWARD_TO_DH(void, zstd_ZstdCompressCtx_setDictID0, (JNIEnv *env, jclass clazz, jlong ptr, jboolean dictIDFlag), (env, clazz, ptr, dictIDFlag))
FORWARD_TO_DH(jobject, zstd_ZstdCompressCtx_getFrameProgression0, (JNIEnv *env, jclass jctx, jlong ptr), (env, jctx, ptr))
FORWARD_TO_DH(jlong, zstd_ZstdCompressCtx_reset0, (JNIEnv *env, jclass jctx, jlong ptr), (env, jctx, ptr))
FORWARD_TO_DH(void, zstd_ZstdDictDecompress_free, (JNIEnv *env, jobject obj), (env, obj))
FORWARD_TO_DH(void, zstd_ZstdDictCompress_init, (JNIEnv *env, jobject obj, jbyteArray dict, jint dict_offset, jint dict_size, jint level), (env, obj, dict, dict_offset, dict_size, level))
FORWARD_TO_DH(void, zstd_ZstdDictCompress_free, (JNIEnv *env, jobject obj), (env, obj))
FORWARD_TO_DH(void, zstd_ZstdDictDecompress_init, (JNIEnv *env, jobject obj, jbyteArray dict, jint dict_offset, jint dict_size), (env, obj, dict, dict_offset, dict_size))
FORWARD_TO_DH(void, zstd_ZstdDictCompress_initDirect, (JNIEnv *env, jobject obj, jobject dict, jint dict_offset, jint dict_size, jint level, jint byReference), (env, obj, dict, dict_offset, dict_size, level, byReference))
FORWARD_TO_DH(void, zstd_ZstdDictDecompress_initDirect, (JNIEnv *env, jobject obj, jobject dict, jint dict_offset, jint dict_size, jint byReference), (env, obj, dict, dict_offset, dict_size, byReference))
FORWARD_TO_DH(jlong, zstd_ZstdDecompressCtx_decompressDirectByteBufferToByteArray0, (JNIEnv *env, jclass jclazz, jlong ptr, jbyteArray dst, jint dst_offset, jint dst_size, jobject src, jint src_offset, jint src_size), (env, jclazz, ptr, dst, dst_offset, dst_size, src, src_offset, src_size))
FORWARD_TO_DH(void, zstd_ZstdDecompressCtx_free, (JNIEnv *env, jclass clazz, jlong ptr), (env, clazz, ptr))
FORWARD_TO_DH(jlong, zstd_ZstdDecompressCtx_loadDDict0, (JNIEnv *env, jclass clazz, jlong ptr, jbyteArray dict), (env, clazz, ptr, dict))
FORWARD_TO_DH(jlong, zstd_ZstdDecompressCtx_reset0, (JNIEnv *env, jclass clazz, jlong ptr), (env, clazz, ptr))
FORWARD_TO_DH(jlong, zstd_ZstdDecompressCtx_decompressByteArrayToDirectByteBuffer0, (JNIEnv *env, jclass jclazz, jlong ptr, jobject dst, jint dst_offset, jint dst_size, jbyteArray src, jint src_offset, jint src_size), (env, jclazz, ptr, dst, dst_offset, dst_size, src, src_offset, src_size))
FORWARD_TO_DH(jlong, zstd_ZstdDecompressCtx_decompressByteArray0, (JNIEnv *env, jclass jclazz, jlong ptr, jbyteArray dst, jint dst_offset, jint dst_size, jbyteArray src, jint src_offset, jint src_size), (env, jclazz, ptr, dst, dst_offset, dst_size, src, src_offset, src_size))
FORWARD_TO_DH(jlong, zstd_ZstdDecompressCtx_decompressDirectByteBufferStream0, (JNIEnv *env, jclass jclazz, jlong ptr, jobject dst, jint dst_offset, jint dst_size, jobject src, jint src_offset, jint src_size), (env, jclazz, ptr, dst, dst_offset, dst_size, src, src_offset, src_size))
FORWARD_TO_DH(jlong, zstd_ZstdDecompressCtx_decompressDirectByteBuffer0, (JNIEnv *env, jclass jclazz, jlong ptr, jobject dst, jint dst_offset, jint dst_size, jobject src, jint src_offset, jint src_size), (env, jclazz, ptr, dst, dst_offset, dst_size, src, src_offset, src_size))
FORWARD_TO_DH(jlong, zstd_ZstdDecompressCtx_loadDDictFast0, (JNIEnv *env, jclass clazz, jlong ptr, jobject dict), (env, clazz, ptr, dict))
FORWARD_TO_DH(jlong, zstd_ZstdDecompressCtx_init, (JNIEnv *env, jclass clazz), (env, clazz))
FORWARD_TO_DH(jlong, zstd_Zstd_compressFastDict0, (JNIEnv *env, jclass obj, jbyteArray dst, jint dst_offset, jbyteArray src, jint src_offset, jint src_length, jobject dict), (env, obj, dst, dst_offset, src, src_offset, src_length, dict))
FORWARD_TO_DH(jlong, zstd_Zstd_decompressDirectByteBufferFastDict0, (JNIEnv *env, jclass obj, jobject dst, jint dst_offset, jint dst_size, jobject src, jint src_offset, jint src_size, jobject dict), (env, obj, dst, dst_offset, dst_size, src, src_offset, src_size, dict))
FORWARD_TO_DH(jlong, zstd_Zstd_decompressFastDict0, (JNIEnv *env, jclass obj, jbyteArray dst, jint dst_offset, jbyteArray src, jint src_offset, jint src_length, jobject dict), (env, obj, dst, dst_offset, src, src_offset, src_length, dict))
FORWARD_TO_DH(jlong, zstd_Zstd_compressDirectByteBufferFastDict0, (JNIEnv *env, jclass obj, jobject dst, jint dst_offset, jint dst_size, jobject src, jint src_offset, jint src_size, jobject dict), (env, obj, dst, dst_offset, dst_size, src, src_offset, src_size, dict))

// jni_inputstream_zstd.h
FORWARD_TO_DH(jint, zstd_ZstdInputStreamNoFinalizer_freeDStream, (JNIEnv *env, jclass obj, jlong stream), (env, obj, stream))
FORWARD_TO_DH(jint, zstd_ZstdInputStreamNoFinalizer_decompressStream, (JNIEnv *env, jclass obj, jlong stream, jbyteArray dst, jint dst_size, jbyteArray src, jint src_size), (env, obj, stream, dst, dst_size, src, src_size))
FORWARD_TO_DH(jint, zstd_ZstdInputStreamNoFinalizer_initDStream, (JNIEnv *env, jclass obj, jlong stream), (env, obj, stream))
FORWARD_TO_DH(jlong, zstd_ZstdInputStreamNoFinalizer_recommendedDOutSize, (JNIEnv *env, jclass obj), (env, obj))
FORWARD_TO_DH(jlong, zstd_ZstdInputStreamNoFinalizer_recommendedDInSize, (JNIEnv *env, jclass obj), (env, obj))
FORWARD_TO_DH(jlong, zstd_ZstdInputStreamNoFinalizer_createDStream, (JNIEnv *env, jclass obj), (env, obj))

// jni_outputstream_zstd.h
FORWARD_TO_DH(jint, zstd_ZstdOutputStreamNoFinalizer_resetCStream, (JNIEnv *env, jclass obj, jlong stream), (env, obj, stream))
FORWARD_TO_DH(jlong, zstd_ZstdOutputStreamNoFinalizer_createCStream, (JNIEnv *env, jclass obj), (env, obj))
FORWARD_TO_DH(jint, zstd_ZstdOutputStreamNoFinalizer_flushStream, (JNIEnv *env, jclass obj, jlong stream, jbyteArray dst, jint dst_size), (env, obj, stream, dst, dst_size))
FORWARD_TO_DH(jint, zstd_ZstdOutputStreamNoFinalizer_endStream, (JNIEnv *env, jclass obj, jlong stream, jbyteArray dst, jint dst_size), (env, obj, stream, dst, dst_size))
FORWARD_TO_DH(jint, zstd_ZstdOutputStreamNoFinalizer_freeCStream, (JNIEnv *env, jclass obj, jlong stream), (env, obj, stream))
FORWARD_TO_DH(jint, zstd_ZstdOutputStreamNoFinalizer_compressStream, (JNIEnv *env, jclass obj, jlong stream, jbyteArray dst, jint dst_size, jbyteArray src, jint src_size), (env, obj, stream, dst, dst_size, src, src_size))
FORWARD_TO_DH(jlong, zstd_ZstdOutputStreamNoFinalizer_recommendedCOutSize, (JNIEnv *env, jclass obj), (env, obj))

// jni_zdict.h
FORWARD_TO_DH_NOJNI(jlong, zstd_Zstd_trainFromBufferDirect0, (JNIEnv *env, jclass obj, jobject samples, jintArray sampleSizes, jobject dictBuffer, jboolean legacy, jint compressionLevel), (env, obj, samples, sampleSizes, dictBuffer, legacy, compressionLevel))
FORWARD_TO_DH_NOJNI(jlong, zstd_Zstd_trainFromBuffer0, (JNIEnv *env, jclass obj, jobjectArray samples, jbyteArray dictBuffer, jboolean legacy, jint compressionLevel), (env, obj, samples, dictBuffer, legacy, compressionLevel))

// jni_zstd.h
FORWARD_TO_DH(jint, zstd_Zstd_setSequenceProducerFallback, (JNIEnv *env, jclass obj, jlong stream, jboolean fallbackFlag), (env, obj, stream, fallbackFlag))
FORWARD_TO_DH(jint, zstd_Zstd_setCompressionTargetLength, (JNIEnv *env, jclass obj, jlong stream, jint targetLength), (env, obj, stream, targetLength))
FORWARD_TO_DH(jint, zstd_Zstd_windowLogMin, (JNIEnv *env, jclass obj), (env, obj))
FORWARD_TO_DH(jint, zstd_Zstd_blockSizeMax, (JNIEnv *env, jclass obj), (env, obj))
FORWARD_TO_DH(jlong, zstd_Zstd_compressBound, (JNIEnv *env, jclass obj, jlong size), (env, obj, size))
FORWARD_TO_DH(jint, zstd_Zstd_hashLogMin, (JNIEnv *env, jclass obj), (env, obj))
FORWARD_TO_DH(jint, zstd_Zstd_setCompressionOverlapLog, (JNIEnv *env, jclass obj, jlong stream, jint overlapLog), (env, obj, stream, overlapLog))
FORWARD_TO_DH(jlong, zstd_Zstd_decompressUnsafe, (JNIEnv *env, jclass obj, jlong dst_buf_ptr, jlong dst_size, jlong src_buf_ptr, jlong src_size), (env, obj, dst_buf_ptr, dst_size, src_buf_ptr, src_size))
FORWARD_TO_DH(jlong, zstd_Zstd_findDirectByteBufferFrameCompressedSize, (JNIEnv *env, jclass obj, jobject src_buf, jint src_offset, jint src_size), (env, obj, src_buf, src_offset, src_size))
FORWARD_TO_DH(jint, zstd_Zstd_maxCompressionLevel, (JNIEnv *env, jclass obj), (env, obj))
FORWARD_TO_DH(jlong, zstd_Zstd_getBuiltinSequenceProducer, (JNIEnv *env, jclass obj), (env, obj))
FORWARD_TO_DH(void, zstd_Zstd_registerSequenceProducer, (JNIEnv *env, jclass obj, jlong stream, jlong seqProdState, jlong seqProdFunction), (env, obj, stream, seqProdState, seqProdFunction))
FORWARD_TO_DH(jint, zstd_Zstd_setCompressionSearchLog, (JNIEnv *env, jclass obj, jlong stream, jint searchLog), (env, obj, stream, searchLog))
FORWARD_TO_DH(jint, zstd_Zstd_setCompressionChainLog, (JNIEnv *env, jclass obj, jlong stream, jint chainLog), (env, obj, stream, chainLog))
FORWARD_TO_DH(jint, zstd_Zstd_setCompressionHashLog, (JNIEnv *env, jclass obj, jlong stream, jint hashLog), (env, obj, stream, hashLog))
FORWARD_TO_DH(jint, zstd_Zstd_setEnableLongDistanceMatching, (JNIEnv *env, jclass obj, jlong stream, jint enableLDM), (env, obj, stream, enableLDM))
FORWARD_TO_DH(jint, zstd_Zstd_defaultCompressionLevel, (JNIEnv *env, jclass obj), (env, obj))
FORWARD_TO_DH(jint, zstd_Zstd_setCompressionMinMatch, (JNIEnv *env, jclass obj, jlong stream, jint minMatch), (env, obj, stream, minMatch))
FORWARD_TO_DH(jlong, zstd_Zstd_getErrorCode, (JNIEnv *env, jclass obj, jlong code), (env, obj, code))
FORWARD_TO_DH(jlong, zstd_Zstd_decompressedSize0, (JNIEnv *env, jclass obj, jbyteArray src, jint offset, jint limit, jboolean magicless), (env, obj, src, offset, limit, magicless))
FORWARD_TO_DH(jint, zstd_Zstd_setCompressionJobSize, (JNIEnv *env, jclass obj, jlong stream, jint jobSize), (env, obj, stream, jobSize))
FORWARD_TO_DH(jlong, zstd_Zstd_compressUnsafe, (JNIEnv *env, jclass obj, jlong dst_buf_ptr, jlong dst_size, jlong src_buf_ptr, jlong src_size, jint level, jboolean checksumFlag), (env, obj, dst_buf_ptr, dst_size, src_buf_ptr, src_size, level, checksumFlag))
FORWARD_TO_DH(jint, zstd_Zstd_chainLogMax, (JNIEnv *env, jclass obj), (env, obj))
FORWARD_TO_DH(jint, zstd_Zstd_setCompressionMagicless, (JNIEnv *env, jclass obj, jlong stream, jboolean enabled), (env, obj, stream, enabled))
FORWARD_TO_DH(jint, zstd_Zstd_setCompressionStrategy, (JNIEnv *env, jclass obj, jlong stream, jint strategy), (env, obj, stream, strategy))
FORWARD_TO_DH(jlong, zstd_Zstd_getDictIdFromFrameBuffer, (JNIEnv *env, jclass obj, jobject src), (env, obj, src))
FORWARD_TO_DH(jint, zstd_Zstd_searchLogMax, (JNIEnv *env, jclass obj), (env, obj))
FORWARD_TO_DH(jstring, zstd_Zstd_getErrorName, (JNIEnv *env, jclass obj, jlong code), (env, obj, code))
FORWARD_TO_DH(jint, zstd_Zstd_loadFastDictDecompress, (JNIEnv *env, jclass obj, jlong stream, jobject dict), (env, obj, stream, dict))
FORWARD_TO_DH(jlong, zstd_Zstd_getStubSequenceProducer, (JNIEnv *env, jclass obj), (env, obj))
FORWARD_TO_DH(jint, zstd_Zstd_setSearchForExternalRepcodes, (JNIEnv *env, jclass obj, jlong stream, jint searchRepcodes), (env, obj, stream, searchRepcodes))
FORWARD_TO_DH(jint, zstd_Zstd_setValidateSequences, (JNIEnv *env, jclass obj, jlong stream, jint validateSequences), (env, obj, stream, validateSequences))
FORWARD_TO_DH(jint, zstd_Zstd_setCompressionWorkers, (JNIEnv *env, jclass obj, jlong stream, jint workers), (env, obj, stream, workers))
FORWARD_TO_DH(jint, zstd_Zstd_windowLogMax, (JNIEnv *env, jclass obj), (env, obj))
FORWARD_TO_DH(jlong, zstd_Zstd_decompressedDirectByteBufferSize, (JNIEnv *env, jclass obj, jobject src_buf, jint src_offset, jint src_size, jboolean magicless), (env, obj, src_buf, src_offset, src_size, magicless))
FORWARD_TO_DH(jlong, zstd_Zstd_findFrameCompressedSize0, (JNIEnv *env, jclass obj, jbyteArray src, jint offset, jint limit), (env, obj, src, offset, limit))
FORWARD_TO_DH(jint, zstd_Zstd_hashLogMax, (JNIEnv *env, jclass obj), (env, obj))
FORWARD_TO_DH(jint, zstd_Zstd_loadDictDecompress, (JNIEnv *env, jclass obj, jlong stream, jbyteArray dict, jint dict_size), (env, obj, stream, dict, dict_size))
FORWARD_TO_DH(jlong, zstd_Zstd_getDictIdFromFrame, (JNIEnv *env, jclass obj, jbyteArray src), (env, obj, src))
FORWARD_TO_DH(jlong, zstd_Zstd_getDictIdFromDict, (JNIEnv *env, jclass obj, jbyteArray src), (env, obj, src))
FORWARD_TO_DH(jint, zstd_Zstd_loadDictCompress, (JNIEnv *env, jclass obj, jlong stream, jbyteArray dict, jint dict_size), (env, obj, stream, dict, dict_size))
FORWARD_TO_DH(jlong, zstd_Zstd_getDictIdFromDictDirect, (JNIEnv *env, jclass obj, jobject src, jint offset, jint src_size), (env, obj, src, offset, src_size))
FORWARD_TO_DH(jint, zstd_Zstd_setCompressionWindowLog, (JNIEnv *env, jclass obj, jlong stream, jint windowLog), (env, obj, stream, windowLog))
FORWARD_TO_DH(jint, zstd_Zstd_setDecompressionLongMax, (JNIEnv *env, jclass obj, jlong stream, jint windowLogMax), (env, obj, stream, windowLogMax))
FORWARD_TO_DH(jlong, zstd_Zstd_getDirectByteBufferFrameContentSize, (JNIEnv *env, jclass obj, jobject src_buf, jint src_offset, jint src_size, jboolean magicless), (env, obj, src_buf, src_offset, src_size, magicless))
FORWARD_TO_DH(jint, zstd_Zstd_setDecompressionMagicless, (JNIEnv *env, jclass obj, jlong stream, jboolean enabled), (env, obj, stream, enabled))
FORWARD_TO_DH(jint, zstd_Zstd_setCompressionChecksums, (JNIEnv *env, jclass obj, jlong stream, jboolean enabled), (env, obj, stream, enabled))
FORWARD_TO_DH(jint, zstd_Zstd_magicNumber, (JNIEnv *env, jclass obj), (env, obj))
FORWARD_TO_DH(jint, zstd_Zstd_chainLogMin, (JNIEnv *env, jclass obj), (env, obj))
FORWARD_TO_DH(jint, zstd_Zstd_loadFastDictCompress, (JNIEnv *env, jclass obj, jlong stream, jobject dict), (env, obj, stream, dict))
FORWARD_TO_DH(jint, zstd_Zstd_setRefMultipleDDicts, (JNIEnv *env, jclass obj, jlong stream, jboolean enabled), (env, obj, stream, enabled))
FORWARD_TO_DH(jboolean, zstd_Zstd_isError, (JNIEnv *env, jclass obj, jlong code), (env, obj, code))
FORWARD_TO_DH(jint, zstd_Zstd_setCompressionLevel, (JNIEnv *env, jclass obj, jlong stream, jint level), (env, obj, stream, level))
FORWARD_TO_DH(jint, zstd_Zstd_searchLogMin, (JNIEnv *env, jclass obj), (env, obj))
FORWARD_TO_DH(jint, zstd_Zstd_setCompressionLong, (JNIEnv *env, jclass obj, jlong stream, jint windowLog), (env, obj, stream, windowLog))
FORWARD_TO_DH(jlong, zstd_Zstd_getFrameContentSize0, (JNIEnv *env, jclass obj, jbyteArray src, jint offset, jint limit, jboolean magicless), (env, obj, src, offset, limit, magicless))
FORWARD_TO_DH(jint, zstd_Zstd_minCompressionLevel, (JNIEnv *env, jclass obj), (env, obj))
#define JNI_ZSTD_ERROR_FORWARD(err, name) \
  JNIEXPORT jlong JNICALL Java_dhcomgithubluben_zstd_Zstd_err##name \
    (JNIEnv *env, jclass obj) { \
      return Java_com_github_luben_zstd_Zstd_err##name (env, obj); \
  }
// Yes I know err goes unused but this is the syntax that zstd source uses for errors so doing this makes it easier to copy paste it in case of update.
JNI_ZSTD_ERROR_FORWARD(no_error,                      NoError)
JNI_ZSTD_ERROR_FORWARD(GENERIC,                       Generic)
JNI_ZSTD_ERROR_FORWARD(prefix_unknown,                PrefixUnknown)
JNI_ZSTD_ERROR_FORWARD(version_unsupported,           VersionUnsupported)
JNI_ZSTD_ERROR_FORWARD(frameParameter_unsupported,    FrameParameterUnsupported)
JNI_ZSTD_ERROR_FORWARD(frameParameter_windowTooLarge, FrameParameterWindowTooLarge)
JNI_ZSTD_ERROR_FORWARD(corruption_detected,           CorruptionDetected)
JNI_ZSTD_ERROR_FORWARD(checksum_wrong,                ChecksumWrong)
JNI_ZSTD_ERROR_FORWARD(dictionary_corrupted,          DictionaryCorrupted)
JNI_ZSTD_ERROR_FORWARD(dictionary_wrong,              DictionaryWrong)
JNI_ZSTD_ERROR_FORWARD(dictionaryCreation_failed,     DictionaryCreationFailed)
JNI_ZSTD_ERROR_FORWARD(parameter_unsupported,         ParameterUnsupported)
JNI_ZSTD_ERROR_FORWARD(parameter_outOfBound,          ParameterOutOfBound)
JNI_ZSTD_ERROR_FORWARD(tableLog_tooLarge,             TableLogTooLarge)
JNI_ZSTD_ERROR_FORWARD(maxSymbolValue_tooLarge,       MaxSymbolValueTooLarge)
JNI_ZSTD_ERROR_FORWARD(maxSymbolValue_tooSmall,       MaxSymbolValueTooSmall)
JNI_ZSTD_ERROR_FORWARD(stage_wrong,                   StageWrong)
JNI_ZSTD_ERROR_FORWARD(init_missing,                  InitMissing)
JNI_ZSTD_ERROR_FORWARD(memory_allocation,             MemoryAllocation)
JNI_ZSTD_ERROR_FORWARD(workSpace_tooSmall,            WorkSpaceTooSmall)
JNI_ZSTD_ERROR_FORWARD(dstSize_tooSmall,              DstSizeTooSmall)
JNI_ZSTD_ERROR_FORWARD(srcSize_wrong,                 SrcSizeWrong)
JNI_ZSTD_ERROR_FORWARD(dstBuffer_null,                DstBufferNull)
