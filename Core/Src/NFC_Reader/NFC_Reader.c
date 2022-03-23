/*
 * NFC_Reader.c
 *
 *  Created on: Jun 23, 2021
 *      Author: fil
 */
#include "main.h"
#include <stdio.h>

SystemVarDef	SystemVar;



uint8_t	check_card_request(void)
{
	return HAL_GPIO_ReadPin(NFC0_GPIO_Port, NFC0_Pin);
}

void set_card_valid(void)
{
	HAL_GPIO_WritePin(NFC1_GPIO_Port, NFC1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(NFC_CARD_PRESENT_GPIO_Port, NFC_CARD_PRESENT_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(NFC_CARD_DETECTED_GPIO_Port, NFC_CARD_DETECTED_Pin, GPIO_PIN_RESET);
}

void set_card_invalid(void)
{
	HAL_GPIO_WritePin(NFC1_GPIO_Port, NFC1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(NFC_CARD_PRESENT_GPIO_Port, NFC_CARD_PRESENT_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(NFC_CARD_DETECTED_GPIO_Port, NFC_CARD_DETECTED_Pin, GPIO_PIN_SET);
}

void NFC_Init(void)
{

	set_card_invalid();
	SystemVar.version = initializePN532();
	SystemVar.card_number = 1;
	SystemVar.write = 1;
	HAL_Delay(1000);
}


void read_and_dump(void)
{
uint8_t	decode_ret;
	if ( checkCardPresence() == 0 )
	{
		dump_TAGinfo(SystemVar.card_number);
		decode_ret = decode();
		if ( decode_ret == 0 )
			logUSB("No more tries\n\r");
		if ( decode_ret == 255 )
			logUSB("Invalid card\n\r");
		if ( decode_ret < 255 )
			logUSB("%d writes remaining\n\r",decode_ret);
		dump_card();
	}
	else
		logUSB("No card present\n\r");
}

void write_and_dump(uint8_t tries)
{
	if ( checkCardPresence() == 0 )
	{
		encode_and_write(tries);
		read_and_dump();
	}
	else
		logUSB("No card present\n\r");
}

void parse_USB_Cmd(void)
{
int	p0,pnum;
char cmd;

	pnum = sscanf((char *)&SystemVar.usb_packet,"< %c %d",&cmd,&p0);
	if ( pnum == 1 )
	{
		if ( cmd == 'R')
			read_and_dump();
		if ( cmd == 'A')
		{
			NFC_Init();
			logUSB("\n\rCard reader activated\n\r");
		}
		if ( cmd == 'D')
		{
			NFC_HardReset();
			logUSB("\n\rCard reader deactivated\n\r");
		}
	}
	if ( pnum == 2 )
	{
		if ( cmd == 'W')
			write_and_dump(p0);
	}
}

uint8_t pack_USB_cmd(uint8_t rxchar)
{
	if ( SystemVar.usb_header == 0 )
	{
		if ( rxchar == '<' )
		{
			SystemVar.usb_rx_index=0;
			SystemVar.usb_packet[SystemVar.usb_rx_index] = rxchar;
			SystemVar.usb_header ++;
			SystemVar.usb_rx_index ++;
		}
	}
	else
	{
		SystemVar.usb_packet[SystemVar.usb_rx_index] = rxchar;
		SystemVar.usb_rx_index++;
		if ( rxchar == '>')
		{
			SystemVar.usb_header = 0;
			return 0;
		}
	}
	return 1;
}


void head_command(void)
{
uint8_t	decode_ret;

	NFC_Init();
	if ( checkCardPresence() == 0 )
	{
		//dump_TAGinfo(SystemVar.card_number);
		decode_ret = decode();
		if ( decode_ret == 0 )
			logUSB("No more tries\n\r");
		if ( decode_ret == 255 )
			logUSB("Invalid card\n\r");
		if ( decode_ret < 255 )
		{
			logUSB("%d writes remaining\n\r",decode_ret);
		}
		set_card_valid();
		HAL_Delay(1000);
		set_card_invalid();
	}
	else
		set_card_invalid();
	NFC_HardReset();
}

void NFC_Cycle(void)
{
#ifndef STM32L071xx
uint8_t	packed,i;
	if ( SystemVar.version != 0 )
		return;
	if ( SystemVar.usb_packet_ready == 1 )
	{
		for(i=0;i<SystemVar.usb_rxed_byte_count;i++ )
			packed = pack_USB_cmd(SystemVar.usb_rxed_packet[i]);
		if ( packed == 0 )
		{
			parse_USB_Cmd();
		}
		SystemVar.usb_packet_ready = 0;
	}
#endif
	if ( check_card_request() == 1 )
	{
		head_command();
		/*
		NFC_Init();
		if ( checkCardPresence() == 0 )
			write_and_dump(3);
		*/
	}
}
