#include <string.h>

#include <mqtt.h>
#include <ring_buffer.h>
#include <mqtt_message.h>

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <PubSubClient.h>

static WiFiClient espClient;
static PubSubClient client(espClient);
static RingBuffer<MQTTMessage> ring_buffer(5);

static void mqtt_callback(char* topic, byte* payload, unsigned int length);

void mqtt_init(const char* server_url, uint16_t port)
{
  client.setServer(server_url, port);
  client.setCallback(mqtt_callback);
}

void mqtt_connect(const char* clientId)
{
  client.connect(clientId);
}

mqtt_state mqtt_connected(void)
{
  return client.connected() ? MQTT_STATE_CONNECTED : MQTT_STATE_DISCONNECTED;
}

mqtt_rc mqtt_publish(const char* topic, byte* payload, unsigned int payload_len)
{
  return client.publish(topic, payload, payload_len) ? MQTT_RC_OK : MQTT_RC_EXCEPTION;
}

mqtt_rc mqtt_subscribe(const char* topic)
{
  return client.subscribe(topic) ? MQTT_RC_OK : MQTT_RC_EXCEPTION;
}

mqtt_rc mqtt_receive(char* topic, size_t max_topic_len, byte* payload, size_t* payload_len, size_t max_payload_len)
{
  if (!ring_buffer.available())
  {
    return MQTT_RC_EXCEPTION;
  }
  MQTTMessage* msg = ring_buffer.pop_front();

  strncpy(topic, msg->topic_, max_topic_len);
  *payload_len = msg->payload_len_ > max_payload_len ? max_payload_len : msg->payload_len_;
  memcpy(payload, msg->payload_, *payload_len);

  return MQTT_RC_OK;
}

void mqtt_loop(void)
{
  client.loop();
}

static void mqtt_callback(char* topic, byte* payload, unsigned int length)
{
  MQTTMessage msg = MQTTMessage(topic, payload, length);
  ring_buffer.push_back(msg);
}
