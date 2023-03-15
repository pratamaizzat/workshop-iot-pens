#ifndef wifi_module_h
#define wifi_module_h

#include "../include/wifi_module.h"
#include "WiFi.h"
#include "WiFiClient.h"

class IWiFi
{
public:
    WiFiClient client_wifi;
    /**
     * @brief fungsi untuk melakukan koneksi menggunakan wifi
     *
     * @param wifi_ssid  SSID dari wifi yang akan digunakan
     * @param wifi_password Password dari wifi yang akan digunakan
     */
    void connect_wifi(const char *wifi_ssid, const char *wifi_password);

    /**
     * @brief fungsi untuk memutuskan koneksi wifi
     *
     */
    void disconnect_wifi();

    /**
     * @brief fungsi untuk melakukan reconnect dengan wifi
     *
     */
    void reconnect_wifi();

    /**
     * @brief fungsi untuk mengecek koneksi wifi
     *
     * @return true terhubung
     * @return false  terputus
     */
    bool connection_wifi_check();
};

#endif
