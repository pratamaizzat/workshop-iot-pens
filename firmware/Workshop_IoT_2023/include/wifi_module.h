#ifndef wifi_module_h
#define wifi_module_h

#include "../include/wifi_module.h"
#include "WiFi.h"
#include "WiFiClient.h"

class IWiFi
{
public:
    WiFiClient client_wifi;
    void connect_wifi(const char *wifi_ssid, const char *wifi_password);
    void disconnect_wifi();
    void reconnect_wifi();
    bool connection_wifi_check();
};

#endif
