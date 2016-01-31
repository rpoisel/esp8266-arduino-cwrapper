#ifndef MQTT_MESSAGE_H
#define MQTT_MESSAGE_H

#include <mqtt.h>

struct MQTTMessage
{
  MQTTMessage();
  MQTTMessage(const char* topic, byte* payload, unsigned int payload_len);
  MQTTMessage& operator=(MQTTMessage other);
  char topic_[MQTT_MAX_TOPIC_LEN];
  byte payload_[MQTT_MAX_PAYLOAD_LEN];
  size_t payload_len_;
};

#endif /* MQTT_MESSAGE_H */
