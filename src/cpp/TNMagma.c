#include "..\h\cipher\TNMagma.h"

uint32_t getRoundKey(uint8_t* key, int round, int reverse)
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

uint32_t swap(uint32_t a)
{
	uint32_t ret = 0;
	ret |= (a & (0xFF000000)) >> (3 * 8);
	ret |= (a & (0x00FF0000)) >> 8;
	ret |= (a & (0x0000FF00)) << 8;
	ret |= (a & (0x000000FF)) << (3 * 8);
	return ret;
}

uint32_t swap(uint8_t* a)
{
	uint32_t ret = 0;
	for (int i = 0; i < 3; i++)
	{
		ret = (ret + *(a + i)) << 8;
	}
	return ret + *(a + 3); 
}

uint32_t T(uint32_t a)
{
	uint32_t ret = 0;

	ret |= s_box[7][(a >> 28) & 0x0000000F];
	ret <<= 4;
	ret |= s_box[6][(a >> 24) & 0x0000000F];
	ret <<= 4;
	ret |= s_box[5][(a >> 20) & 0x0000000F];
	ret <<= 4;
	ret |= s_box[4][(a >> 16) & 0x0000000F];
	ret <<= 4;
	ret |= s_box[3][(a >> 12) & 0x0000000F];
	ret <<= 4;
	ret |= s_box[2][(a >> 8)  & 0x0000000F];
	ret <<= 4;
	ret |= s_box[1][(a >> 4)  & 0x0000000F];
	ret <<= 4;
	ret |= s_box[0][ a        & 0x0000000F];

	return ret;
}

tnStatus crypt(uint8_t* in, uint8_t* key, uint8_t* out, int reverse)
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
	return crypt(in, key, out, 0x00);
}

tnStatus tnDecryptBlockMagma(uint8_t* in, uint8_t* key, uint8_t* out)
{
	return crypt(in, key, out, 0x01);
}