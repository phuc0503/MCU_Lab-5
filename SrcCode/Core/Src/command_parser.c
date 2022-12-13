/*
 * command_parser.c
 *
 *  Created on: Dec 13, 2022
 *      Author: DELL
 */

#include "command_parser.h"

void command_parser_fsm(){
	switch (status) {
		case START:
			if (buffer[index_buffer - 1] == '!') {
				status = READ_COMMAND;
			}
			else {
				status = START;
				index_buffer = 0;
			}
			break;
		case READ_COMMAND:
			if (index_buffer > MAX_BUFFER_SIZE - 1) {
				status = START;
				index_buffer = 0;
			}
			if (buffer[index_buffer - 1] == '#') {
				str_cpy(command_data, buffer);
				command_flag = 1;
				status = START;
				index_buffer = 0;
			}
			break;
		default:
			break;
	}
}
