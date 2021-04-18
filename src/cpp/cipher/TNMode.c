#include "../../h/cipher/TNMode.h"

tnStatus tnECBForBlock(
	const uint8_t* cvIn,
	size_t sInSize,
	const uint8_t* cvKey,
	size_t sKeySize,
	uint8_t* vOut,
	size_t* psOutSize,
	tnStatus (*cipher)(uint8_t* cvIn, uint8_t* cvKey, uint8_t* vOut),
	tnStatus (*padding)(uint8_t* cvIn, size_t sInSize, uint8_t* block, size_t* psBlockSize))
{
	size_t i = 0;
	tnStatus status = TNStatusSuccess;
	size_t psBlockSize = 0;
	if (TNStatusSuccess != (status = padding(NULL, 0, NULL, &psBlockSize)))
	{
		return status;
	}
	if (psBlockSize == 0)
	{
		return TNStatusError;
	}
	while (i + psBlockSize < sInSize)
	{
		if (TNStatusSuccess != (status = cipher(cvIn + i, cvKey, vOut + i)))
		{
			return status;
		}
		i += psBlockSize;
	}
	if (i != sInSize)
	{
		uint8_t* block = (uint8_t*)malloc(psBlockSize);
		if (TNStatusSuccess != (status = padding(block, sInSize - i, block, &psBlockSize)))
		{
			if (block)
			{
				free(block);
			}
			return status;
		}
		if (TNStatusSuccess != (status = cipher(block, cvKey, vOut + i)))
		{
			if (block)
			{
				free(block);
			}
			return status;
		}
	}

	return TNStatusSuccess;
}

tnStatus tnCTRForBlock(
	const uint8_t* cvIn,
	size_t sInSize,
	const uint8_t* cvIv,
	size_t sIvSize,
	const uint8_t* cvKey,
	size_t sKeySize,
	uint8_t* vOut,
	size_t* psOutSize,
	tnStatus(*ivInit)(uint8_t* cvIn, uint8_t* cvKey, uint8_t* iv),
	tnStatus(*cipher)(uint8_t* cvIn, uint8_t* cvKey, uint8_t* vOut),
	tnStatus(*padding)(uint8_t* cvIn, size_t sInSize, uint8_t* block, size_t* psBlockSize))
{
	size_t i = 0;
	tnStatus status = TNStatusSuccess;
	size_t psBlockSize = 0;
	if (TNStatusSuccess != (status = padding(NULL, 0, NULL, &psBlockSize)))
	{
		return status;
	}
	if (psBlockSize == 0)
	{
		return TNStatusError;
	}
	uint8_t* CTR = (uint8_t*)malloc(psBlockSize);
	if (TNStatusSuccess != (status = ivInit(cvIv, sIvSize, CTR)))
	{
		free(CTR);
		return status;
	}
	while (i + psBlockSize < sInSize)
	{
		if (TNStatusSuccess != (status = cipher(CTR, cvKey, vOut + i)))
		{
			return status;
		}
		i += psBlockSize;

	}
	if (i != sInSize)
	{
		uint8_t* block = (uint8_t*)malloc(psBlockSize);
		if (TNStatusSuccess != (status = padding(cvIn + i, sInSize - i, block, NULL)))
		{
			return status;
		}
		return cipher(block, cvKey, vOut + i);
	}
	return TNStatusSuccess;
}