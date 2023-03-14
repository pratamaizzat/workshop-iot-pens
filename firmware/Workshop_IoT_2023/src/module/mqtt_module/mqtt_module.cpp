#include "mqtt_module.h"

MQTTClient client(2300);
#define MSG_BUFFER_SIZE_PUB (2300)
#define VAR_BUFFER_SIZE (50)
char subscriber[VAR_BUFFER_SIZE];
String mqtt_test = "Not Connected";

static char msg_pub[MSG_BUFFER_SIZE_PUB];
char data_pub[MSG_BUFFER_SIZE_PUB];

void message_received(String &topic, String &payload)
{
}

class iMQTT
{

public:
    iMQTT() {}

    void setup_mqtt(const char *server, Client &connection)
    {
        Serial.println("MQTT Setup");
        client.begin(server, connection);
        client.onMessage(message_received);
    }

    void connect_mqtt(const char *sub1)
    {
        // generate random id
        String client_id = "BreakerClient-";
        client_id += String(random(0xffff), HEX);

        // try connect to mqtt broker
        Serial.print("\nMQTT Connecting");
        int timeout = 0;
        while (!client.connect(client_id.c_str(), "admin01", "zJJ9M7sKCW"))
        {
            Serial.print(".");
            // timeout for break loop
            timeout++;

            delay(100);

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

    void subscribe_mqtt(const char *subs)
    {
        client.subscribe(subs);
    }

    bool publish_mqtt(const char *topic, String payload)
    {
        memset(data_pub, 0, sizeof(data_pub));
        memset(msg_pub, 0, sizeof(msg_pub));
        // delay(5);

        payload.toCharArray(data_pub, (payload.length() + 1));
        snprintf(msg_pub, MSG_BUFFER_SIZE_PUB, "%s", data_pub);
        delay(1);
        return client.publish(topic, msg_pub, true, 0); // max length message 1420
    }

    void loop_mqtt(const char *sub1)
    {
        client.loop();
        // Serial.print("MQTT Connection - ");
        // Serial.println(client.connected());
        if (!client.connected())
        {
            connect_mqtt(sub1);
        }
    }

    bool check_mqtt()
    {
        return client.connected();
    }

    void convert_string_to_char(String mess, char *variable)
    {
        static char dt[VAR_BUFFER_SIZE];
        mess.toCharArray(dt, (mess.length() + 1));
        snprintf(variable, VAR_BUFFER_SIZE, "%s", dt);
    }
};