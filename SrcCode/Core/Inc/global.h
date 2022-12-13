/*
 * global.h
 *
 *  Created on: Dec 13, 2022
 *      Author: DELL
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "stdint.h"
#include "string.h"
#include "main.h"

#define MAX_BUFFER_SIZE	30

extern UART_HandleTypeDef huart2;
extern ADC_HandleTypeDef hadc1;

#define START		 	0
#define	READ_COMMAND 	1
#define	END			 	2

#define RECEIVE_COMMAND	3
#define SEND_ADC		4

extern uint8_t command_flag;
extern uint8_t command_data[30];

extern int status;
extern int communication_status;

extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;

extern long int ADC_Value;

void str_cpy(uint8_t* str1, uint8_t* str2);

uint8_t compare(uint8_t* str1, uint8_t* str2);

#endif /* INC_GLOBAL_H_ */
