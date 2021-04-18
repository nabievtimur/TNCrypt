#include "TNCipher.h"
#include "TNCipher_p.h"

tnStatus tnEncrypt(
	tnCipherAlgorithms eAlgorithm,
	tnCipherMode eMode,
	const void* cvIn,
	size_t sInSize,
	const void* cvKey,
	size_t sKeySize,
	const void* cvIv,
	size_t psIvSize,
	void* vOut,
	size_t* psOutSize)
{
	if (eMode == tnIdCipherModeECB)
	{

	}
	else if (eMode == tnIdCipherModeCTR)
	{

	}
	else if (eMode == tnIdCipherModeOFB)
	{

	}
	else if (eMode == tnIdCipherModeCFB)
	{

	}
	else if (eMode == tnIdCipherModeCBC)
	{

	}
	else if (eMode == tnIdCipherModeMAC)
	{

	}
	return TNStatusNotSupported;
}

tnStatus tnDecrypt(
	tnCipherAlgorithms eAlgorithm,
	tnCipherMode eMode,
	const void* cvIn,
	size_t sInSize,
	const void* cvKey,
	size_t sKeySize,
	const void* cvIv,
	size_t psIvSize,
	void* vOut,
	size_t* psOutSize)
{
	return TNStatusNotSupported;
}

tnStatus tnEncryptionCtxInit(
	tnEncryptionCtx* sCtx)
{
	return TNStatusNotSupported;
}

tnStatus tnEncryptionCtxFree(
	tnEncryptionCtx* sCtx)
{
	return TNStatusNotSupported;
}

tnStatus tnEncryptionSetProperty(
	tnEncryptionCtx			sCtx,
	tnCipherPropertyName	ePropertyKey,
	const char* strValue)
{
	return TNStatusNotSupported;
}

tnStatus tnEncryptionSetPropertyByteVector(
	tnEncryptionCtx					sCtx,
	tnCipherPropertyByteVectorName	ePropertyKey,
	const void* cvValue,
	size_t							sValueSize)
{
	return TNStatusNotSupported;
}

tnStatus tnEncryptionUpdate(
	tnEncryptionCtx	sCtx,
	const void* cvIn,
	size_t			sInSize,
	void* vOut,
	size_t* psOutSize)
{
	return TNStatusNotSupported;
}

tnStatus tnEncryptionFinalUpdate(
	tnEncryptionCtx sCtx,
	const void* cvIn,
	size_t		sInSize,
	void* vOut,
	size_t* psOutSize)
{
	return TNStatusNotSupported;
}