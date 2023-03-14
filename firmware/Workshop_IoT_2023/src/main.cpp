#include <Arduino.h>
#include "../include/mqtt_module.h"
#include "../include/wifi_module.h"
#include "../include/tool.h"

/**
 * @brief  untuk mengatur topic mqtt PUBLISH
 *
 */
const char *publisher = "/test/device";

char server[VAR_BUFFER_SIZE];
char subscriber[VAR_BUFFER_SIZE];
char ssid[VAR_BUFFER_SIZE];
char password[VAR_BUFFER_SIZE];

String payload_data_mqtt;

IMQTT mqtt;
TOOL tool;
IWiFi wifi;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);

  // Alamat topic subcriber
  String subs_conf = "/test/device";
  tool.convert_string_to_char(subs_conf, subscriber);

  // Alamat server mqtt
  String serv = "mqtt.dinojantan.com";
  tool.convert_string_to_char(serv, server);

  // REWRITE SSID
  String sid = "i-connect";
  tool.convert_string_to_char(sid, ssid);

  // REWRITE PASS
  String sid_pass = "interadsjoss";
  tool.convert_string_to_char(sid_pass, password);

  wifi.connect_wifi(ssid, password);

  // MQTT CONNECT
  mqtt.setup_mqtt(server, wifi.client_wifi);
  mqtt.connect_mqtt(subscriber);
  mqtt.publish_mqtt(publisher, "0000000");
}

void loop()
{
  // put your main code here, to run repeatedly:

  mqtt.loop_mqtt(subscriber);
  delay(30);
}