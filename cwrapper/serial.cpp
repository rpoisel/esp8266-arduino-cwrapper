#include "serial.h"

#include <Arduino.h>

void serial_begin(int baudrate)
{
  Serial.begin(baudrate);
}

size_t serial_print_cstr(const char* message)
{
  return Serial.print(message);
}

size_t serial_print_unsigned_int(unsigned int num)
{
  return Serial.print(num);
}

size_t serial_print_ip_address(ip_address* address)
{
  return Serial.printf("%d.%d.%d.%d",
      address->octets[0],
      address->octets[1],
      address->octets[2],
      address->octets[3]
      );
}

size_t serial_println(void)
{
  return Serial.println();
}

