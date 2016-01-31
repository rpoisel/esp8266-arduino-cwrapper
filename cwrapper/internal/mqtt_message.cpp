#include "mqtt_message.h"

#include <cstring>

MQTTMessage::MQTTMessage() :
    topic_ { 0 }, payload_ { 0 }, payload_len_(0)
{

}

MQTTMessage::MQTTMessage(const char* topic, byte* payload, unsigned int payload_len)
{
  strncpy(topic_, topic, MQTT_MAX_TOPIC_LEN);
  memcpy(payload_, payload, payload_len);
  payload_len_ = payload_len;
}

MQTTMessage& MQTTMessage::operator=(MQTTMessage other)
{
  strncpy(this->topic_, other.topic_, MQTT_MAX_TOPIC_LEN);
  memcpy(this->payload_, other.payload_, other.payload_len_);
  this->payload_len_ = other.payload_len_;

  return *this;
}
