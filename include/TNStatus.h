#ifndef TNSTATUS_H
#define TNSTATUS_H

typedef enum tnStatus_t 
{
	TNStatusSuccess					= 0x00000000,
	TNStatusEroor					= 0x80000000,
	TNStatusInvalidParameter		= 0x80000001

} tnStatus;

#endif //!TNSTATUS_H