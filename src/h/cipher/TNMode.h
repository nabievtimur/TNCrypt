#ifndef TNCIPHERMODE_H
#define TNCIPHERMODE_H

#include "Source.h"

tnStatus tnECBForBlock(
	const uint8_t* cvIn,
	size_t sInSize,
	const uint8_t* cvKey,
	size_t sKeySize,
	uint8_t* vOut,
	size_t* psOutSize,
	tnStatus(*cipher)(uint8_t* cvIn, uint8_t* cvKey, uint8_t* vOut),
	tnStatus(*padding)(uint8_t* cvIn, size_t sInSize, uint8_t* block, size_t* psBlockSize));

tnStatus tnCTRForBlock(
	const uint8_t* cvIn,
	size_t sInSize,
	const uint8_t* cvIv,
	size_t sIvSize,
	const uint8_t* cvKey,
	size_t sKeySize,
	uint8_t* vOut,
	size_t* psOutSize,
	tnStatus(*cipher)(uint8_t* cvIn, uint8_t* cvKey, uint8_t* vOut),
	tnStatus(*padding)(uint8_t* cvIn, size_t sInSize, uint8_t* block, size_t* psBlockSize));

#endif //!TNCIPHERMODE_H