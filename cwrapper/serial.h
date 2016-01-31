/*
 * serial..h
 *
 *  Created on: Jan 30, 2016
 *      Author: rpoisel
 */

#ifndef SERIAL_H_
#define SERIAL_H_

#include <stddef.h>

#include "wifi.h"

#ifdef __cplusplus
extern "C" {
#endif

void serial_begin(int baudrate);
size_t serial_print_cstr(const char* message);
size_t serial_print_unsigned_int(unsigned int num);
size_t serial_print_ip_address(ip_address* address);
size_t serial_println(void);

#ifdef __cplusplus
}
#endif


#endif /* SERIAL_H_ */
