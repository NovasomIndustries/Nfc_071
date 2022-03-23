/*
 * pn532_driver.h
 *
 *  Created on: May 3, 2021
 *      Author: fil
 */

#ifndef INC_NFC_READER_PN532_DRIVER_H_
#define INC_NFC_READER_PN532_DRIVER_H_

/*
extern	RNG_HandleTypeDef 	hrng;
*/
extern	SPI_HandleTypeDef 	hspi1;
extern	TIM_HandleTypeDef 	htim6;

#define SPI_TIMEOUT		30
#define BUF_SIZE		32
#define CARD1_ID		1

#define	PN532_PREAMBLE		0x00
#define	PN532_STARTCODE1	0x00
#define	PN532_STARTCODE2	0xFF
#define	PN532_POSTAMBLE		0x00
#define	PN532_HOSTTOPN532	0xD4
#define	PN532_PN532TOHOST	0xD5

#define	PN532_COMMAND_GETFIRMWAREVERSION	0x02
#define	PN532_COMMAND_RFCONFIGURATION       0x32
#define	PN532_COMMAND_INLISTPASSIVETARGET   0x4A
#define	PN532_COMMAND_SAMCONFIGURATION		0x14
#define	PN532_COMMAND_INAUTOPOLL			0x60
#define	PN532_SPI_DATAWRITE					0x01
#define	PN532_SPI_DATAREAD					0x03

#define	PN532_COMMAND_INDATAEXCHANGE		0x40
#define	PN532_RESPONSE_INDATAEXCHANGE		0x41
#define	PN532_PAGE_SIZE						26
#define	TAG_ACCESS_OK						0
#define	TAG_ERROR							1
#define	TAG_TIMEOUT							2
#define	TAG_AUTHENTICATION_FAILED			3
#define	TAG_INVALID							4
#define	MIFARE_CLASSIC_PAGE_SIZE			16
#define	MIFARE_ULTRALIGHT_PAGE_SIZE			4

// Mifare Commands and replies
#define	MIFARE_RESPONSE_AUTHORIZED			0x00
#define	PN532_MIFARE_ISO14443A				0x00

#define	MIFARE_AUTHENTICATED				0x00
#define	MIFARE_NOT_AUTHENTICATED			0x01

#define MIFARE_CMD_AUTH_A                   0x60
#define MIFARE_CMD_AUTH_B                   0x61
#define MIFARE_CMD_READ                     0x30
#define MIFARE_CMD_WRITE                    0xA0
#define MIFARE_CMD_TRANSFER                 0xB0
#define MIFARE_CMD_DECREMENT                0xC0
#define MIFARE_CMD_INCREMENT                0xC1
#define MIFARE_CMD_STORE                    0xC2
#define MIFARE_ULTRALIGHT_CMD_READ          0x30
#define MIFARE_ULTRALIGHT_CMD_WRITE         0xA2


extern	uint8_t initializePN532(void);
extern	uint8_t checkCardPresence(void);
extern	uint8_t authenticateAndRead(uint8_t card_number, uint8_t page, uint8_t *buffer);
extern	uint8_t authenticateAndWrite(uint8_t card_number, uint8_t page, uint8_t *buffer);
extern	void dump_buffer(uint8_t page,uint8_t *buffer);
extern	void dump_TAGinfo(uint8_t card_number);
extern	uint8_t	checkForIrq(void);
extern	void dump_card(void);
extern	void NFC_HardReset(void);

#endif /* INC_NFC_READER_PN532_DRIVER_H_ */
