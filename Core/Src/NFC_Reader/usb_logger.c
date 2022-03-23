/**
 ******************************************************************************
 * @file    usb_logger.c
 * @author  MMY Application Team
 * @brief   Debug log output utility implementation.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under Ultimate Liberty license
 * SLA0094, the "License"; You may not use this file except in compliance with
 * the License. You may obtain a copy of the License at:
 *                             www.st.com/SLA0094
 *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "usb_logger.h"
#include <string.h>
#include <stdarg.h>
#include <stdio.h>


int logUSB(const char* format, ...)
{
#ifndef STM32L071xx
#define LOG_BUFFER_SIZE 256
char buf[LOG_BUFFER_SIZE];
va_list argptr;
    va_start(argptr, format);
    int cnt = vsnprintf(buf, LOG_BUFFER_SIZE, format, argptr);
    va_end(argptr);  
    CDC_Transmit_FS((uint8_t*)buf, strlen(buf));
    return cnt;
#else
    return 0;
#endif
}

