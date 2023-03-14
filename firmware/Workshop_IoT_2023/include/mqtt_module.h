#ifndef mqtt_module_h
#define mqtt_module_h

#include "MQTTClient.h"
#include "../include/mqtt_module.h"
#include "MQTT.h"
#define MSG_BUFFER_SIZE_PUB (2300)

class IMQTT
{
private:
public:
    /**
     * @brief setup untu mqtt server
     *
     * @param server server yang dipakai untuk mqtt
     * @param connection connection client
     */
    void setup_mqtt(const char *server, Client &connection);
    void connect_mqtt(const char *sub1);
    bool publish_mqtt(const char *topic, String payload);
    void loop_mqtt(const char *sub1);
    bool check_mqtt();
    void subscribe_mqtt(const char *subs);
};

#endif
