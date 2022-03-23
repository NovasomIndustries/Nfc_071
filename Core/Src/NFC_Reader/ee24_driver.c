/*
 * ee24_driver.c
 *
 *  Created on: Jun 23, 2021
 *      Author: fil
 */



#include "main.h"
#define ee24_delay(x)   HAL_Delay(x)

#if (_EEPROM_SIZE_KBIT == 1) || (_EEPROM_SIZE_KBIT == 2)
#define _EEPROM_PSIZE     8
#elif (_EEPROM_SIZE_KBIT == 4) || (_EEPROM_SIZE_KBIT == 8) || (_EEPROM_SIZE_KBIT == 16)
#define _EEPROM_PSIZE     16
#else
#define _EEPROM_PSIZE     32
#endif

uint8_t ee24_lock = 0;

void ee24_write(uint16_t address, uint8_t *data, size_t len, uint32_t timeout)
{
	HAL_I2C_Master_Transmit(&hi2c1,EEPROM_ADDRESS,data,len,timeout);
}

void ee24_read(uint16_t address, uint8_t *data, size_t len, uint32_t timeout)
{
	HAL_I2C_Master_Receive(&hi2c1, EEPROM_ADDRESS, data, len,timeout);
}

void ee24_eraseChip(void)
{
  return;
}
//################################################################################################################
