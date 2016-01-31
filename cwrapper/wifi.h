/*
 * wifi.h
 *
 *  Created on: Jan 30, 2016
 *      Author: rpoisel
 */

#ifndef WIFI_H_
#define WIFI_H_

#include <stdint.h>

typedef uint8_t wifi_connected_t;

#define WIFI_DISCONNECTED 0
#define WIFI_CONNECTED    1

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _ip_address
{
  uint8_t octets[4];
} ip_address;

void wifi_soft_ap_start(const char* ssid);
void wifi_setup_client(const char* ssid, const char* password);
wifi_connected_t wifi_connected(void);
ip_address wifi_get_local_ip(void);

#ifdef __cplusplus
}
#endif

#endif /* WIFI_H_ */
