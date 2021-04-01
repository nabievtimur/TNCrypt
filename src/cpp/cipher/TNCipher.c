#include "../../../include/TNCipher.h"
#include "../../h/cipher/TNCipher_p.h"

tnStatus tnEncrypt(
	__in	tnCipherAlgorithms eAlgorithm,
	__in	tnCipherMode eMode,
	__in	const void* cvIn,
	__in	size_t sInSize,
	__in	const void* cvKey,
	__in	size_t sKeySize,
	__in	const void* cvIv,
	__in	size_t psIvSize,
	__out	void* vOut,
	__inout	size_t* psOutSize)
{
	return TNStatusNotSupported;
}

tnStatus tnDecrypt(
	__in	tnCipherAlgorithms eAlgorithm,
	__in	tnCipherMode eMode,
	__in	const void* cvIn,
	__in	size_t sInSize,
	__in	const void* cvKey,
	__in	size_t sKeySize,
	__in	const void* cvIv,
	__in	size_t psIvSize,
	__out	void* vOut,
	__inout	size_t* psOutSize)
{
	return TNStatusNotSupported;
}

tnStatus tnEncryptionCtxInit(
	__inout tnEncryptionCtx* sCtx)
{
	return TNStatusNotSupported;
}

tnStatus tnEncryptionCtxFree(
	__in tnEncryptionCtx* sCtx)
{
	return TNStatusNotSupported;
}

tnStatus tnEncryptionSetProperty(
	__inout	tnEncryptionCtx			sCtx,
	__in	tnCipherPropertyName	ePropertyKey,
	__in	const char* strValue)
{
	return TNStatusNotSupported;
}

tnStatus tnEncryptionSetPropertyByteVector(
	__inout	tnEncryptionCtx					sCtx,
	__in	tnCipherPropertyByteVectorName	ePropertyKey,
	__in	const void* cvValue)
{
	return TNStatusNotSupported;
}

tnStatus tnEncryptionUpdate(
	__in	tnEncryptionCtx	sCtx,
	__in	const void* cvIn,
	__in	size_t			sInSize,
	__out	void* vOut,
	__inout	size_t* psOutSize)
{
	return TNStatusNotSupported;
}

tnStatus tnEncryptionFinalUpdate(__in	tnEncryptionCtx sCtx,
	__in	const void* cvIn,
	__in	size_t		sInSize,
	__out	void* vOut,
	__inout	size_t* psOutSize)
{
	return TNStatusNotSupported;
}