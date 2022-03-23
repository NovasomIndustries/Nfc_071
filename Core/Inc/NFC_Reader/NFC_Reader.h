/*
 * NFC_Reader.h
 *
 *  Created on: Jun 23, 2021
 *      Author: fil
 */

#ifndef INC_NFC_READER_NFC_READER_H_
#define INC_NFC_READER_NFC_READER_H_

extern	I2C_HandleTypeDef hi2c1;

#define	USB_BUFLEN					256
#define	CMD_BUFLEN					8
#define	MIFARE_UID_LEN				4
#define	MIFARE_ULTRALIGHT_UID_LEN	7

typedef struct _SystemVarDef
{
	uint32_t 				usb_rxed_byte_count;
	uint8_t 				usb_packet_ready;
	uint8_t 				usb_header;
	uint8_t 				usb_rx_index;
	uint8_t 				usb_rxed_packet[CMD_BUFLEN];
	uint8_t 				usb_packet[CMD_BUFLEN];
	uint8_t					version;
	uint8_t					card_data[16];
	uint8_t 				card_number;
	uint8_t					uid[MIFARE_ULTRALIGHT_UID_LEN];
	uint8_t					uidLength;
	uint8_t 				write;

}SystemVarDef;

extern	SystemVarDef	SystemVar;
extern	void NFC_Init(void);
extern	void NFC_Cycle(void);

extern	uint8_t CDC_Transmit_FS(uint8_t* Buf, uint16_t Len);
#endif /* INC_NFC_READER_NFC_READER_H_ */
