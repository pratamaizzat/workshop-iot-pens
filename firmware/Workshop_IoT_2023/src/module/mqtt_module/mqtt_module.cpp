#include "../include/mqtt_module.h"

static char msg_pub[MSG_BUFFER_SIZE_PUB];
char data_pub[MSG_BUFFER_SIZE_PUB];
String mqtt_test = "Not Connected";

MQTTClient client(2300);

void message_received(String &topic, String &payload)
{
    Serial.print("topic incoming : ");
    Serial.println(topic);
    Serial.print("Payload incoming : ");
    Serial.println(payload);
}

void IMQTT::setup_mqtt(const char *server, Client &connection)
{
    Serial.println("MQTT Setup");
    client.begin(server, connection);
    // client.onMessage(message_received);
}

void IMQTT::connect_mqtt(const char *sub1)
{
    // generate random id
    String client_id = "WorkshopIoTPens2023-";
    client_id += String(random(0xffff), HEX);

    // try connect to mqtt broker
    Serial.print("\nMQTT Connecting");
    int timeout = 0;
    while (!client.connect(client_id.c_str()))
    {
        Serial.print(".");
        // timeout for break loop
        timeout++;

        delay(1000);

        if (timeout > 3)
        {
            break;
        }
    }
    if (check_mqtt() == true)
    {
        mqtt_test = "Connected";
        Serial.println("\nMQTT Connected!");
    }
    else
    {
        mqtt_test = "Not Connected";
        // hardwares.led_red();
        Serial.println("\nMQTT Not Connected!");
    }

    subscribe_mqtt(sub1);
}

void IMQTT::subscribe_mqtt(const char *subs)
{
    client.subscribe(subs);
}

bool IMQTT::publish_mqtt(const char *topic, String payload)
{
    memset(data_pub, 0, sizeof(data_pub));
    memset(msg_pub, 0, sizeof(msg_pub));
    // delay(5);

    payload.toCharArray(data_pub, (payload.length() + 1));
    snprintf(msg_pub, MSG_BUFFER_SIZE_PUB, "%s", data_pub);
    delay(1);
    return client.publish(topic, msg_pub, true, 0); // max length message 1420
}

void IMQTT::loop_mqtt(const char *sub1)
{
    client.loop();
    client.onMessage(message_received);
    if (!client.connected())
    {
        connect_mqtt(sub1);
    }
}

bool IMQTT::check_mqtt()
{
    return client.connected();
}
