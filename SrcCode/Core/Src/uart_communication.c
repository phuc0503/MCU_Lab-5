/*
 * uart_communication.c
 *
 *  Created on: Dec 13, 2022
 *      Author: DELL
 */


#include "uart_communication.h"

//ADC_HandleTypeDef hadc1;
//UART_HandleTypeDef huart2;

void uart_communication_fsm(){
	char str[50];
	switch (communication_status) {
		case RECEIVE_COMMAND:
			HAL_ADC_Start(&hadc1);
			ADC_Value = HAL_ADC_GetValue(&hadc1);
			HAL_ADC_Stop(&hadc1);
			if (command_flag == 1) {
				uint8_t temp[MAX_BUFFER_SIZE] = "!RST#";
				if (compare(command_data, temp) == 1) {
					communication_status = SEND_ADC;
					setTimer2(1);
				}
				command_flag=0;
			}

			break;
		case SEND_ADC:
			if (command_flag == 1) {
				uint8_t temp[MAX_BUFFER_SIZE] = "!OK#";
				if (compare(command_data, temp) == 1) {
					setTimer2(0);
					communication_status=RECEIVE_COMMAND;
				}
				command_flag = 0;
			}
			if (timer2_flag==1) {

				HAL_UART_Transmit (&huart2 , (void*)str , sprintf (str , "\n%ld\n", ADC_Value), 1000);
				setTimer2(300);
			}

			break;
		default:
			break;
	}
}
