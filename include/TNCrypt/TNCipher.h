#ifndef TNCIPHER_H
#define TNCIPHER_H

/** @brief ��������� ���������� */
typedef enum tnCipherAlgorithms_t {
	tnIdCipherAlgorithmMagma,
	tnIdCipherAlgorithmKyznechik
} tnCipherAlgorithms;

/** @brief ������ ���������� */
typedef enum tnCipherMode_t {
	tnIdCipherModeECB,
	tnIdCipherModeCTR,
	tnIdCipherModeOFB,
	tnIdCipherModeCBC,
	tnIdCipherModeCFB,
	tnIdCipherModeMAC
} tnCipherMode;

#include "Source.h"

/** @brief ���������� �������� �������� ������� "vIn" ������� "sInSize", 
*		��������� ��������� � �������� ������ "vOut" ��� ����������� ������� ��������� � "psOutSize".
*		�������� � ����� ���������� ����������� � ���������� "eAlgorithm", "eMode" ��������������.
*		��� ��������� ������� ���������� ���������� �������� ������ ������������� � "cvIv" �������� "psIvSize".
*		���� �������� "vOut" = null, �� � ��������� "psOutSize" ����� ������ ����������� ������ ������ ��� ���������� ������� "cvIn".
*		������� ������� � "psOutSize" ����������� ����������� ������������� ����.
* 
*	@param[in]		eAlgorithm	�������� ����������
*	@param[in]		eMode		����� ����������
*	@param[in]		cvIn		������� ������� ������
*	@param[in]		sInSize		������ �������� ������� (� ������)
*	@param[in]		cvKey		�������� ������� ������
*	@param[in]		sKeySize	������ ��������� ������� (� ������)
*	@param[in]		cvIv		������� ������ � �������� �������������
*	@param[in]		psIvSize	������ ������� ������������� (� ������)
*	@param[out]		vOut		�������� ������� ������
*	@param[in_out]	psOutSize	������ ��������� ������� (� ������)
*	@return ������ ��������
*/
tnStatus tnEncrypt(
	__in	tnCipherAlgorithms	eAlgorithm,
	__in	tnCipherMode		eMode,
	__in	const void*			cvIn,
	__in	size_t				sInSize,
	__in	const void*			cvKey,
	__in	size_t				sKeySize,
	__in	const void*			cvIv,
	__in	size_t				psIvSize,
	__out	void*				vOut,
	__inout	size_t*				psOutSize);

/** @brief ����������� �������� �������� ������� "vIn" ������� "sInSize",
*		��������� ��������� � �������� ������ "vOut" ��� ����������� ������� ��������� � "psOutSize".
*		�������� � ����� ���������� ����������� � ���������� "eAlgorithm", "eMode" ��������������.
*		��� ��������� ������� ���������� ���������� �������� ������ ������������� � "cvIv" �������� "psIvSize".
*		���� �������� "vOut" = null, �� � ��������� "psOutSize" ����� ������ ����������� ������ ������ ��� ���������� ������� "cvIn".
*
*	@param[in]		eAlgorithm	�������� ����������
*	@param[in]		eMode		����� ����������
*	@param[in]		cvIn		������� ������� ������
*	@param[in]		sInSize		������ �������� ������� (� ������)
*	@param[in]		cvKey		�������� ������� ������
*	@param[in]		sKeySize	������ ��������� ������� (� ������)
*	@param[in]		cvIv		������� ������ � �������� �������������
*	@param[in]		psIvSize	������ ������� ������������� (� ������)
*	@param[out]		vOut		�������� ������� ������
*	@param[in_out]	psOutSize	������ ��������� ������� (� ������)
*	@return ������ ��������
*/
tnStatus tnDecrypt(
	__in	tnCipherAlgorithms	eAlgorithm,
	__in	tnCipherMode		eMode,
	__in	const void*			cvIn,
	__in	size_t				sInSize,
	__in	const void*			cvKey,
	__in	size_t				sKeySize,
	__in	const void*			cvIv,
	__in	size_t				psIvSize,
	__out	void*				vOut,
	__inout	size_t*				psOutSize);

#include "TNCipher_p.h"

/** @brief ��������� ��� �������� ��������� ���������� */
typedef struct tnEncryptionCtx_t tnEncryptionCtx;

/** @brief ������������� ��������� ��� ��������� ����������
*
*	@param[in_out]	sCtx	�������� ����������
*	@return ������ ��������
*/
tnStatus tnEncryptionCtxInit(
	__inout tnEncryptionCtx* sCtx);

/** @brief ������� ��������� ����������
*
*	@param[in_out]	sCtx	�������� ����������
*	@return ������ ��������
*/
tnStatus tnEncryptionCtxFree(
	__in tnEncryptionCtx* sCtx);

/** @brief ����� ���������� (����������� ���������� ��������)*/
typedef enum tnCipherPropertyName_t {
	tnCipherPropertyAlgorithm,
	tnCipherPropertyMode
} tnCipherPropertyName;

/** @brief ��������� ���������� � ��������
*
*	@param[in_out]	sCtx			��������
*	@param[in]		ePropertyKey	���� ���������
*	@param[in]		strValue		������������� �������� ���������
*	@return ������ ��������
*/

#define TN_ID_PROPERTY_CIPHER_MODE_ECB "Crypt_mode_ecb"
#define TN_ID_PROPERTY_CIPHER_ALGORITHM_MAGMA "Crypt_algorithm_magma"
#define TN_ID_PROPERTY_CIPHER_ALGORITHM_KYZ "Crypt_algorithm_kyznechik"

tnStatus tnEncryptionSetProperty(
	__inout	tnEncryptionCtx			sCtx, 
	__in	tnCipherPropertyName	ePropertyKey,
	__in	const char*				strValue);

/** @brief ����� ���������� (������� �������) */
typedef enum tnCipherPropertyByteVectorName_t {
	tnCipherPropertyIV,
	tnCipherPropertyKey
} tnCipherPropertyByteVectorName;

/** @brief ��������� ���������� � ��������
*
*	@param[in_out]	sCtx			��������
*	@param[in]		ePropertyKey	���� ���������
*	@param[in]		cvValue			������� ������ - �������� ���������
*	@return ������ ��������
*/
tnStatus tnEncryptionSetPropertyByteVector(
	__inout	tnEncryptionCtx					sCtx,
	__in	tnCipherPropertyByteVectorName	ePropertyKey,
	__in	const void*						cvValue,
	__in	size_t							sValueSize);

/** @brief �������� ���������� �������� ����� "cvIn", ���������� ���������� ����� �������������� �� �����.
*		���� ����� ������� � �������� � ��������� ������� ����������� �� ���������� tnEncryptionUpdate().
*		���� �������� "vOut"=null, � �������� "psOutSize" ����� ������� ������ ������� ����������� ��� ��������� ��������� ��������.
*		������� ���������� � "psOutSize" ����������� ����������� ������������� ����.
* 
*	@param[in]		sCtx		�������� ����������
*	@param[in]		cvIn		������� ������� ������
*	@param[in]		sInSize		������ �������� ������� (� ������)
*	@param[out]		vOut		�������� ������� ������
*	@param[in_out]	psOutSize	������ ��������� ������� (� ������)
*	@return ������ ��������
*/
tnStatus tnEncryptionUpdate(
	__in	tnEncryptionCtx	sCtx,
	__in	const void*		cvIn,
	__in	size_t			sInSize,
	__out	void*			vOut,
	__inout	size_t*			psOutSize);

/** @brief ����������� Update ��������� ����������. ��������� ���� ����� �� ������������� �������� �� ������� ����� � ����������.
*		���� �������� "vOut"=null, � �������� "psOutSize" ����� ������� ������ ������� ����������� ��� ��������� ��������� ��������.
*		������� ���������� � "psOutSize" ����������� ����������� ������������� ����.
*
*	@param[in]		sCtx		�������� ����������
*	@param[in]		cvIn		������� ������� ������
*	@param[in]		sInSize		������ �������� ������� (� ������)
*	@param[out]		vOut		�������� ������� ������
*	@param[in_out]	psOutSize	������ ��������� ������� (� ������)
*	@return ������ ��������
*/
tnStatus tnEncryptionFinalUpdate(__in	tnEncryptionCtx sCtx,
	__in	const void*	cvIn,
	__in	size_t		sInSize,
	__out	void*		vOut,
	__inout	size_t*		psOutSize);

#endif //!TNCIPHER_H