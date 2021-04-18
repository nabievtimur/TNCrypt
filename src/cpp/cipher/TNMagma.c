#include "..\h\cipher\TNMagma.h"

uint32_t getRoundKey(uint8_t* key, int round, bool reverse)
{
	if (round >= 0 && round < 24)
	{
		return swap(key + sizeof(uint32_t) * (reverse ? (round % 8) : (7 - (round % 8))));
	}
	else if (round < 32)
	{
		return swap(key + sizeof(uint32_t) * (reverse ? (7 - (round % 8)) : (round % 8)));
	}
	return 0;
}

void round(uint64_t* block, uint32_t key, bool last)
{
	uint32_t L = *block >> 32;
	uint32_t R = *block;
	R += key;
	R = T(R);
	R = (R << 11) | (R >> 21);
	if (last)
	{
		*block <<= 32;
		*block |= R ^ L;
	}
	else
	{
		*block ^= (uint64_t)R << 32;
	}
}

//uint32_t swap(uint32_t a)
//{
//	uint32_t ret = 0;
//	ret |= (a & (0xFF000000)) >> (3 * 8);
//	ret |= (a & (0x00FF0000)) >> 8;
//	ret |= (a & (0x0000FF00)) << 8;
//	ret |= (a & (0x000000FF)) << (3 * 8);
//	return ret;
//}

uint32_t swap(uint8_t* a)
{
	uint32_t ret = 0;
	for (int i = 0; i < 3; i++)
	{
		ret = (ret + *(a + i)) << 8;
	}
	return ret + *(a + 3); 
}

const uint8_t tnMagmaSBox[8][16] = {
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

uint32_t T(uint32_t a)
{
	uint32_t ret = 0;

	ret |= tnMagmaSBox[7][(a >> 28) & 0x0000000F];
	ret <<= 4;
	ret |= tnMagmaSBox[6][(a >> 24) & 0x0000000F];
	ret <<= 4;
	ret |= tnMagmaSBox[5][(a >> 20) & 0x0000000F];
	ret <<= 4;
	ret |= tnMagmaSBox[4][(a >> 16) & 0x0000000F];
	ret <<= 4;
	ret |= tnMagmaSBox[3][(a >> 12) & 0x0000000F];
	ret <<= 4;
	ret |= tnMagmaSBox[2][(a >> 8)  & 0x0000000F];
	ret <<= 4;
	ret |= tnMagmaSBox[1][(a >> 4)  & 0x0000000F];
	ret <<= 4;
	ret |= tnMagmaSBox[0][ a        & 0x0000000F];

	return ret;
}

tnStatus crypt(uint8_t* in, uint8_t* key, uint8_t* out, bool reverse)
{
	if ((in == NULL) || (key == NULL) || (out == NULL))
	{
		return TNStatusInvalidParameter;
	}

	for (int i = 0; i < 32; i++)
	{
		round(in, getRoundKey(key, i, reverse), i == 31 ? 0x00 : 0x01);
	}
}

tnStatus tnEncryptBlockMagma(uint8_t* in, uint8_t* key, uint8_t* out)
{
	return crypt(in, key, out, false);
}

tnStatus tnDecryptBlockMagma(uint8_t* in, uint8_t* key, uint8_t* out)
{
	return crypt(in, key, out, true);
}