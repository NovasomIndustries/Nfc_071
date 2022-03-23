/**
 ******************************************************************************
 * @file    usb_logger.h
 * @brief   Header for logger module
 ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef USB_LOGGER_H
#define USB_LOGGER_H

/* Includes ------------------------------------------------------------------*/
#include "main.h"
//#define	USE_LOGGER	1

extern int logUSB(const char* format, ...);
extern char* hex2Str(unsigned char * data, size_t dataLen);

#endif /* USB_LOGGER_H */
