#include "webserver.h"

#include <string.h>

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#define WEBSERVER_DATA_LEN 1024

static void root_handler(void);
static ESP8266WebServer server(80);
static char webserver_data[WEBSERVER_DATA_LEN] = { 0 };

void webserver_start(void)
{
  server.on("/", root_handler);
  server.begin();
}

void webserver_set_root_data(const char* data)
{
  strncpy(webserver_data, data, WEBSERVER_DATA_LEN);
  webserver_data[WEBSERVER_DATA_LEN - 1] = 0;
}

void webserver_loop(void)
{
  server.handleClient();
}

static void root_handler(void)
{
  server.send(200, "text/html", webserver_data);
}
