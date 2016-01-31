#include <Arduino.h>
#include "cwrapper.h"

#include <stdint.h>
#include <stdio.h>

#define LED_PIN 16
#define CNT_CSTR_BUFLEN 32
#define WIFI_SSID "..."
#define WIFI_PASSWORD "..."
#define MQTT_BROKER "lamaquina"
#define MQTT_BROKER_PORT 1883

static void generated_code();
static void serial_println_mqtt_message(const char* mqtt_topic, const char* payload);

void setup()
{
  serial_begin(115200);
  serial_print_cstr("setup");
  serial_println();
}

void loop()
{
  generated_code();

  webserver_loop();
  mqtt_loop();

}

static void generated_code()
{
  static unsigned cnt = 0;
  static uint8_t subscribed = 0;
  static uint8_t init = 1;

  char buf[CNT_CSTR_BUFLEN];
  ip_address localIP;
  char mqtt_topic[64];
  uint8_t payload[64];
  size_t payload_len = 0;

  /* the generated code is only executed in the loop() method, therefore we have to init here */
  if (init)
  {
    pinMode(LED_PIN, OUTPUT);
    wifi_setup_client(WIFI_SSID, WIFI_PASSWORD);
    webserver_start();
    mqtt_init(MQTT_BROKER, MQTT_BROKER_PORT);

    init = 0;
  }

  if (!wifi_connected())
  {
    return;
  }

  snprintf(buf, CNT_CSTR_BUFLEN, "%d\n", cnt);
  webserver_set_root_data(buf);

  if (!mqtt_connected())
  {
    /* mqtt_connect() is a blocking function */
    mqtt_connect("logi.RTS");
  }
  else
  {
    if (!subscribed)
    {
      mqtt_subscribe("logi.TOPIC");
      subscribed = 1;
    }
    if (mqtt_receive(mqtt_topic, 64, payload, &payload_len, 64) == MQTT_RC_OK)
    {
      payload[payload_len] = 0;
      serial_println_mqtt_message(mqtt_topic, payload);
      if (strcmp(payload, "on") == 0)
      {
        digitalWrite(LED_PIN, HIGH);
      }
      else if (strcmp(payload, "off") == 0)
      {
        digitalWrite(LED_PIN, LOW);
      }
    }
  }
  cnt += 1;
}

static void serial_println_mqtt_message(const char* mqtt_topic, const char* payload)
{
  serial_print_cstr(mqtt_topic);
  serial_print_cstr(": \"");
  serial_print_cstr(payload);
  serial_print_cstr("\"");
  serial_println();
}
