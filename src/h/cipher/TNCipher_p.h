#ifndef TNPCIPHER_H
#define TNPCIPHER_H

#include "../Source.h"
#include "../../../include/TNStatus.h"

struct tnEncryptionCtx_t {
	uint8_t* initializationVector;
	size_t initializationVectorSize;
};

#endif //!TNPCIPHER_H