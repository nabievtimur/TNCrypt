#ifndef TNPMAGMA_H
#define TNPMAGMA_H

#include <stdint.h>
#include "..\..\include\TNStatus.h"

const uint8_t s_box[8][16] = {
	{ 0x0c, 0x04, 0x06, 0x02, 0x0a, 0x05, 0x0b, 0x09,
	  0x0e, 0x08, 0x0d, 0x07, 0x00, 0x03, 0x0f, 0x01 },
	{ 0x06, 0x08, 0x02, 0x03, 0x09, 0x0a, 0x05, 0x0c,
	  0x01, 0x0e, 0x04, 0x07, 0x0b, 0x0d, 0x00, 0x0f },
	{ 0x0b, 0x03, 0x05, 0x08, 0x02, 0x0f, 0x0a, 0x0d,
	  0x0e, 0x01, 0x07, 0x04, 0x0c, 0x09, 0x06, 0x00 },
	{ 0x0c, 0x08, 0x02, 0x01, 0x0d, 0x04, 0x0f, 0x06,
	  0x07, 0x00, 0x0a, 0x05, 0x03, 0x0e, 0x09, 0x0b },
	{ 0x07, 0x0f, 0x05, 0x0a, 0x08, 0x01, 0x06, 0x0d,
	  0x00, 0x09, 0x03, 0x0e, 0x0b, 0x04, 0x02, 0x0c },
	{ 0x05, 0x0d, 0x0f, 0x06, 0x09, 0x02, 0x0c, 0x0a,
	  0x0b, 0x07, 0x08, 0x01, 0x04, 0x03, 0x0e, 0x00 },
	{ 0x08, 0x0e, 0x02, 0x05, 0x06, 0x09, 0x01, 0x0c,
	  0x0f, 0x04, 0x0b, 0x00, 0x0d, 0x0a, 0x03, 0x07 },
	{ 0x01, 0x07, 0x0e, 0x0d, 0x00, 0x05, 0x08, 0x03,
	  0x04, 0x0f, 0x0a, 0x06, 0x09, 0x0c, 0x0b, 0x02 } };

#endif //!TNPMAGMA_H