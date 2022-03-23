/*
 * NFC_EncDec.c
 *
 *  Created on: Apr 28, 2021
 *      Author: fil
 */
#include "main.h"
#include <stdio.h>
#include <string.h>

#define UID_SIZE    4
#define SHIFT_01    7
#define TRY         6

void encode_and_write(uint8_t tries)
{
uint8_t buffer[16];
uint32_t j;
#ifndef STM32L071xx
uint32_t random_number,j;
#endif
	for(j=0;j<16;j++)
		buffer[j] = 0;
	sprintf((char *)buffer,"Sintmate");
	authenticateAndWrite(CARD1_ID,NFC_1STBUFBLK,buffer);
	authenticateAndRead(CARD1_ID,NFC_1STBUFBLK,buffer);
#ifndef STM32L071xx
	/*
	for(j=0;j<4;j++)
	{
		HAL_RNG_GenerateRandomNumber(&hrng, &random_number);
		buffer[j*4] 		= (random_number>>24) & 0xff;
		buffer[(j*4)+1] 	= (random_number>>16) & 0xff;
		buffer[(j*4)+2] 	= (random_number>>8)  & 0xff;
		buffer[(j*4)+3] 	=  random_number      & 0xff;
	}
	*/
#endif
	buffer[0x0c] = tries;
	buffer[0x08] = tries*2;
	buffer[0x04] = tries*3;
	buffer[0x00] = tries*4;
	authenticateAndWrite(CARD1_ID,NFC_2NDBUFBLK,buffer);
	authenticateAndRead(CARD1_ID,NFC_2NDBUFBLK,buffer);
}

uint8_t decode(void)
{
uint8_t buffer[16], xval=0;

	authenticateAndRead(CARD1_ID,NFC_1STBUFBLK,buffer);

	if ( strcmp((char *)buffer,"Sintmate") != 0 )
		return 255;
	authenticateAndRead(CARD1_ID,NFC_2NDBUFBLK,buffer);
	xval ^= buffer[0x0c];
	xval ^= buffer[0x08]/2;
	xval ^= buffer[0x04]/3;
	xval ^= buffer[0x00]/4;
	if ( xval == 0 )
		return buffer[0x0c];
	return 0;
}

void dump_buffer(uint8_t page,uint8_t *buffer)
{
uint8_t	i;
	logUSB("%02x : ", page);
    HAL_Delay(10);
	for(i=0;i<MIFARE_CLASSIC_PAGE_SIZE;i++)
	{
		logUSB("%02x ", buffer[i]);
	    HAL_Delay(10);
	}
	logUSB("\r\n");
}

void dump_card(void)
{
uint8_t buffer[16];

	authenticateAndRead(CARD1_ID, NFC_1STBUFBLK, buffer);
	dump_buffer(NFC_1STBUFBLK,buffer);
	authenticateAndRead(CARD1_ID, NFC_2NDBUFBLK, buffer);
	dump_buffer(NFC_2NDBUFBLK,buffer);
}




