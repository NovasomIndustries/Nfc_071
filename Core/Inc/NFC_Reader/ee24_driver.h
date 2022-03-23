/*
 * ee24_driver.h
 *
 *  Created on: Jun 23, 2021
 *      Author: fil
 */

#ifndef INC_NFC_READER_EE24_DRIVER_H_
#define INC_NFC_READER_EE24_DRIVER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define		EEPROM_ADDRESS               0xA0
#define		EEPROM_USE_WP_PIN            0

void    ee24_write(uint16_t address, uint8_t *data, size_t lenInBytes, uint32_t timeout);
void    ee24_read(uint16_t address, uint8_t *data, size_t lenInBytes, uint32_t timeout);
void    ee24_eraseChip(void);

#ifdef __cplusplus
}
#endif


#endif /* INC_NFC_READER_EE24_DRIVER_H_ */
