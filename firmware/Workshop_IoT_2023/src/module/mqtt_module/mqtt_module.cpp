#include "../include/mqtt_module.h"
#include "../include/hardware_module.h"

static char msg_pub[MSG_BUFFER_SIZE_PUB];
char data_pub[MSG_BUFFER_SIZE_PUB];
String mqtt_test = "Not Connected";

MQTTClient client(2300);
HARDWARE hardware;
void message_received(String &topic, String &payload)
{
    Serial.print("topic incoming : ");
    Serial.println(topic);
    Serial.print("Payload incoming : ");
    Serial.println(payload);

    if (payload == "00000000")
    {
        hardware.led_all_off();
        Serial.println("kondisi 0");
    }
    else if (payload == "00000001")
    {
        hardware.led_on(hardware.led_1);
        Serial.println("kondisi 1");
    }
    else if (payload == "00000011")
    {
        hardware.led_on(hardware.led_1);
        hardware.led_on(hardware.led_2);
        Serial.println("kondisi 2");
    }
    else if (payload == "00000111")
    {
        hardware.led_on(hardware.led_1);
        hardware.led_on(hardware.led_2);
        hardware.led_on(hardware.led_3);
        Serial.println("kondisi 3");
    }
    else if (payload == "00001111")
    {

        hardware.led_on(hardware.led_1);
        hardware.led_on(hardware.led_2);
        hardware.led_on(hardware.led_3);
        hardware.led_on(hardware.led_4);
        Serial.println("kondisi 4");
    }

    else if (payload == "00011111")
    {

        hardware.led_on(hardware.led_1);
        hardware.led_on(hardware.led_2);
        hardware.led_on(hardware.led_3);
        hardware.led_on(hardware.led_4);
        hardware.led_on(hardware.led_5);
        Serial.println("kondisi 5");
    }

    else if (payload == "00111111")
    {

        hardware.led_on(hardware.led_1);
        hardware.led_on(hardware.led_2);
        hardware.led_on(hardware.led_3);
        hardware.led_on(hardware.led_4);
        hardware.led_on(hardware.led_5);
        hardware.led_on(hardware.led_6);
        Serial.println("kondisi 6");
    }
    else if (payload == "01111111")
    {

        hardware.led_on(hardware.led_1);
        hardware.led_on(hardware.led_2);
        hardware.led_on(hardware.led_3);
        hardware.led_on(hardware.led_4);
        hardware.led_on(hardware.led_5);
        hardware.led_on(hardware.led_6);
        hardware.led_on(hardware.led_7);
        Serial.println("kondisi 7");
    }
    else if (payload == "11111111")
    {
        hardware.led_all_on();
        Serial.println("kondisi 8");
    }
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
