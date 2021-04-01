#ifndef TNCIPHER_H
#define TNCIPHER_H

#include "../src/h/cipher/TNCipher_p.h"

/** @brief Алгоритмы шифрования */
typedef enum tnCipherAlgorithms_t {
	tnIdCipherAlgorithmMagma,
	tnIdCipherAlgorithmKyznechik
} tnCipherAlgorithms;

/** @brief Режимы шифрования */
typedef enum tnCipherMode_t {
	tnIdCipherModeECB,
	tnIdCipherModeCTR,
	tnIdCipherModeOFB,
	tnIdCipherModeCBC,
	tnIdCipherModeCFB,
	tnIdCipherModeMAC
} tnCipherMode;

/** @brief Шифрование входного битового вектора "vIn" размера "sInSize", 
*		результат запишется в выходной буффер "vOut" при достаточном размере указанном в "psOutSize".
*		Алгоритм и режим шифрования указывается в параметрах "eAlgorithm", "eMode" соответственно.
*		Для некоторых режимов шифрования необходимо передать вектор инициализации в "cvIv" размером "psIvSize".
*		Если параметр "vOut" = null, то в параметре "psOutSize" будет указан необходимый размер буфера для шифрования вектора "cvIn".
*		Фукнция запишет в "psOutSize" фактическое колличество зашифрованных байт.
* 
*	@param[in]		eAlgorithm	Алгоритм шифрования
*	@param[in]		eMode		Режим шифрования
*	@param[in]		cvIn		Входной битовый вектор
*	@param[in]		sInSize		Размер входного вектора (в байтах)
*	@param[in]		cvKey		Ключевой битовый вектор
*	@param[in]		sKeySize	Размер ключевого вектора (в байтах)
*	@param[in]		cvIv		Битовый вектор с вектором инициализации
*	@param[in]		psIvSize	Размер вектора инициализации (в байтах)
*	@param[out]		vOut		Выходной битовый вектор
*	@param[in_out]	psOutSize	Размер выходного вектора (в байтах)
*	@return Статус операции
*/
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
	__inout	size_t* psOutSize);

/** @brief Расфрование входного битового вектора "vIn" размера "sInSize",
*		результат запишется в выходной буффер "vOut" при достаточном размере указанном в "psOutSize".
*		Алгоритм и режим шифрования указывается в параметрах "eAlgorithm", "eMode" соответственно.
*		Для некоторых режимов шифрования необходимо передать вектор инициализации в "cvIv" размером "psIvSize".
*		Если параметр "vOut" = null, то в параметре "psOutSize" будет указан необходимый размер буфера для шифрования вектора "cvIn".
*
*	@param[in]		eAlgorithm	Алгоритм шифрования
*	@param[in]		eMode		Режим шифрования
*	@param[in]		cvIn		Входной битовый вектор
*	@param[in]		sInSize		Размер входного вектора (в байтах)
*	@param[in]		cvKey		Ключевой битовый вектор
*	@param[in]		sKeySize	Размер ключевого вектора (в байтах)
*	@param[in]		cvIv		Битовый вектор с вектором инициализации
*	@param[in]		psIvSize	Размер вектора инициализации (в байтах)
*	@param[out]		vOut		Выходной битовый вектор
*	@param[in_out]	psOutSize	Размер выходного вектора (в байтах)
*	@return Статус операции
*/
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
	__inout	size_t* psOutSize);

/** @brief Структура для хранения контекста шифрования */
typedef struct tnEncryptionCtx_t tnEncryptionCtx;

/** @brief Инициализация контекста для поточного шифрования
*
*	@param[in_out]	sCtx	Контекст шифрования
*	@return Статус операции
*/
tnStatus tnEncryptionCtxInit(
	__inout tnEncryptionCtx* sCtx);

/** @brief Очистка контекста шифрования
*
*	@param[in_out]	sCtx	Контекст шифрования
*	@return Статус операции
*/
tnStatus tnEncryptionCtxFree(
	__in tnEncryptionCtx* sCtx);

/** @brief Ключи параметров (Принимающих конктерное значение)*/
typedef enum tnCipherPropertyName_t {
	tnCipherPropertyAlgorithm,
	tnCipherPropertyMode
} tnCipherPropertyName;

/** @brief Установка параметров в контекст
*
*	@param[in_out]	sCtx			Контекст
*	@param[in]		ePropertyKey	Ключ параметра
*	@param[in]		strValue		Идентификатор значения параметра
*	@return Статус операции
*/
tnStatus tnEncryptionSetProperty(
	__inout	tnEncryptionCtx			sCtx, 
	__in	tnCipherPropertyName	ePropertyKey,
	__in	const char*				strValue);

/** @brief Ключи параметров (Битовые вектора) */
typedef enum tnCipherPropertyByteVectorName_t {
	tnCipherPropertyIV,
	tnCipherPropertyKey
} tnCipherPropertyByteVectorName;

/** @brief Установка параметров в контекст
*
*	@param[in_out]	sCtx			Контекст
*	@param[in]		ePropertyKey	Ключ параметра
*	@param[in]		cvValue			Битовый вектор - значение параметра
*	@return Статус операции
*/
tnStatus tnEncryptionSetPropertyByteVector(
	__inout	tnEncryptionCtx					sCtx,
	__in	tnCipherPropertyByteVectorName	ePropertyKey,
	__in	const void*						cvValue);

/** @brief Поточное шифрование входного блока "cvIn", дополнение последнего блока осуществляться не будет.
*		Блок будет сохранён и добавлен к следующем вектору полученному из следующего tnEncryptionUpdate().
*		Если параметр "vOut"=null, в параметр "psOutSize" будет записан размер массива необходимый для получения выходного значения.
*		Функция записывает в "psOutSize" фактическое колличество зашифрованных байт.
* 
*	@param[in]		sCtx		Контекст шифрования
*	@param[in]		cvIn		Входной битовый вектор
*	@param[in]		sInSize		Размер входного вектора (в байтах)
*	@param[out]		vOut		Выходной битовый вектор
*	@param[in_out]	psOutSize	Размер выходного вектора (в байтах)
*	@return Статус операции
*/
tnStatus tnEncryptionUpdate(
	__in	tnEncryptionCtx	sCtx,
	__in	const void*		cvIn,
	__in	size_t			sInSize,
	__out	void*			vOut,
	__inout	size_t*			psOutSize);

/** @brief Завершаюший Update поточного шифрования. Последний блок будет по необходимости дополнен до полного блока и зашифрован.
*		Если параметр "vOut"=null, в параметр "psOutSize" будет записан размер массива необходимый для получения выходного значения.
*		Функция записывает в "psOutSize" фактическое колличество зашифрованных байт.
*
*	@param[in]		sCtx		Контекст шифрования
*	@param[in]		cvIn		Входной битовый вектор
*	@param[in]		sInSize		Размер входного вектора (в байтах)
*	@param[out]		vOut		Выходной битовый вектор
*	@param[in_out]	psOutSize	Размер выходного вектора (в байтах)
*	@return Статус операции
*/
tnStatus tnEncryptionFinalUpdate(__in	tnEncryptionCtx sCtx,
	__in	const void*	cvIn,
	__in	size_t		sInSize,
	__out	void*		vOut,
	__inout	size_t*		psOutSize);

#endif //!TNCIPHER_H