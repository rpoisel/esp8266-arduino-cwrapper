#include <Arduino.h>
#include "wrapper.h"

void serial_begin(int baudrate)
{
    Serial.begin(baudrate);
}

void serial_println(const char* message)
{
    Serial.println(message);
}
