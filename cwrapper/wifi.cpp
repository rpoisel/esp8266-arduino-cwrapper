#include "wifi.h"

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#include <wl_definitions.h>

void wifi_soft_ap_start(const char* ssid)
{
  IPAddress local = IPAddress(192, 168, 1, 1);
  IPAddress gateway = IPAddress(192, 168, 1, 254);
  IPAddress subnetmask = IPAddress(255, 255, 255, 0);
  WiFi.softAPConfig(local, gateway, subnetmask);
  WiFi.softAP(ssid);
}

void wifi_setup_client(const char* ssid, const char* password)
{
  WiFi.begin(ssid, password);
}

wifi_connected_t wifi_connected(void)
{
  return WiFi.status() == WL_CONNECTED ? WIFI_CONNECTED : WIFI_DISCONNECTED;
}

ip_address wifi_get_local_ip(void)
{
  ip_address result;
  IPAddress localIP = WiFi.localIP();
  for (int cnt = 0; cnt < 4; cnt++)
  {
    result.octets[cnt] = localIP[cnt];
  }
  return result;
}
