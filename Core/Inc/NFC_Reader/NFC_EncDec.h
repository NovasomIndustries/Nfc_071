/*
 * NFC_EncDec.h
 *
 *  Created on: Apr 28, 2021
 *      Author: fil
 */

#ifndef INC_SINTNFC_NFC_ENCDEC_H_
#define INC_SINTNFC_NFC_ENCDEC_H_

#define	NFC_NUMBUFS		3
#define	NFC_SIZEBUFS	16

#define	NFC_0BUFBLK		0
#define	NFC_1STBUFBLK	1
#define	NFC_2NDBUFBLK	2
#define	NFC_3RDBUFBLK	3

extern	void encode_and_write(uint8_t tries);
extern	uint8_t decode(void);



#endif /* INC_SINTNFC_NFC_ENCDEC_H_ */
