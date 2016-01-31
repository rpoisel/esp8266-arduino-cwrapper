/*
 * mqtt.h
 *
 *  Created on: Jan 30, 2016
 *      Author: rpoisel
 */

#ifndef MQTT_H_
#define MQTT_H_

#include <stdint.h>
#include <stddef.h>

#define MQTT_STATE_DISCONNECTED 0
#define MQTT_STATE_CONNECTED 1

#define MQTT_RC_OK 0
#define MQTT_RC_EXCEPTION 1

#define MQTT_MAX_TOPIC_LEN 64
#define MQTT_MAX_PAYLOAD_LEN 64

typedef uint8_t byte;
typedef uint8_t mqtt_state;
typedef uint8_t mqtt_rc;

#ifdef __cplusplus
extern "C"
{
#endif

void mqtt_init(const char* server_url, uint16_t port);
void mqtt_connect(const char* clientId);
mqtt_state mqtt_connected(void);
mqtt_rc mqtt_publish(const char* topic, byte* payload, size_t payload_len);
mqtt_rc mqtt_subscribe(const char* topic);
mqtt_rc mqtt_receive(char* topic, size_t max_topic_len, byte* payload, size_t* payload_len, size_t max_payload_len);
void mqtt_loop(void);

#ifdef __cplusplus
}
#endif

#endif /* MQTT_H_ */
