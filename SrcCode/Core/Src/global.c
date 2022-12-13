/*
 * global.c
 *
 *  Created on: Dec 13, 2022
 *      Author: DELL
 */

#include "global.h"


uint8_t command_flag = 1;
uint8_t command_data[30];

int status = START;
int communication_status=RECEIVE_COMMAND;

uint8_t temp = 0;
uint8_t buffer[ MAX_BUFFER_SIZE ];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;
long int ADC_Value = 0;


void str_cpy(uint8_t* str1, uint8_t* str2)
{
	for (int i=0; i < MAX_BUFFER_SIZE; i++)
	{
		str1[i] = str2[i];
	}
}

uint8_t compare(uint8_t* str1, uint8_t* str2)
{
	for (int i=0; i < MAX_BUFFER_SIZE; i++)
	{
		if (str1[i] != str2[i]) return 0;
		if (str1[i] == '#') return 1;
	}
	return 1;
}
