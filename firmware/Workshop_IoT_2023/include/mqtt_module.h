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
     * @brief setup untuk mqtt server
     *
     * @param server server yang dipakai untuk mqtt
     * @param connection connection client
     */
    void setup_mqtt(const char *server, Client &connection);

    /**
     * @brief untuk membuat koneksi dengan server mqtt
     *
     * @param sub1 alamat topic untuk disubcribe
     */
    void connect_mqtt(const char *sub1);

    /**
     * @brief fungsi untuk publish data ke server mqtt
     *
     * @param topic alamat topic untuk publish data
     * @param payload isi data yang ingin di publish bentuk string
     * @return true  terkirim
     * @return false  gagal kirim
     */
    bool publish_mqtt(const char *topic, String payload);

    /**
     * @brief fungsi agar mqtt stanby dan menerima publish dari server
     *
     * @param sub1 alamat topic untuk disubcribe
     */
    void loop_mqtt(const char *sub1);

    /**
     * @brief  fungsi untuk mengecek apakah mqtt terhubung ke server
     *
     * @return true terhubung
     * @return false putus
     */
    bool check_mqtt();

    /**
     * @brief fungsi untuk subscribe ke alamat topic mqtt
     *
     * @param subs alamat topic mqtt yang mau disubscribe
     */
    void subscribe_mqtt(const char *subs);
};

#endif
