#include <Arduino.h>
#include "wrapper.h"

void setup();
void loop();

static unsigned long period = 200;
static uint8_t pin = 12;

void setup() {
  for (uint8_t p = 12; p <= 15; p++)
  {
    pinMode(p, OUTPUT);
  }
  serial_begin(115200);
  serial_println("setup");
}

void loop() {
  serial_println("loop");
  digitalWrite(pin, HIGH);
  delay(period);
  pin = pin > 15 ? 12 : pin + 1;
  digitalWrite(pin, LOW);
  delay(period);
}


