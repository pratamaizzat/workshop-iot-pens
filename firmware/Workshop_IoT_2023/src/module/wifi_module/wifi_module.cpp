#include "wifi_module.h"

class iWiFi
{
public:
    iWiFi() {}

    WiFiClient client;

    void connect_wifi(const char *wifi_ssid, const char *wifi_password)
    {
        WiFi.disconnect();
        WiFi.begin(wifi_ssid, wifi_password);
        Serial.print("Wifi connecting.. (");
        Serial.print(wifi_ssid);
        Serial.print(" | ");
        Serial.print(wifi_password);
        Serial.println(")");
        int cnt = 0;
        while (WiFi.status() != WL_CONNECTED)
        {
            cnt++;
            delay(1000);
            if (cnt > 10)
            {
                ESP.restart();
            }
        }

        Serial.println("");
        Serial.println("WiFi connected");
        Serial.println("IP address: ");
        Serial.println(WiFi.localIP());
    }

    void disconnect_wifi()
    {
        WiFi.disconnect();
        Serial.println("Wifi Disconnect!");
    }

    void reconnect_wifi()
    {
        int timeout = 0;
        WiFi.disconnect();
        WiFi.reconnect();
        while (WiFi.status() != WL_CONNECTED)
        {
            Serial.println("Wifi Reconnect!");
            timeout++;
            delay(1000);
            if (timeout > 10)
            {
                ESP.restart();
            }
        }
    }

    bool connection_wifi_check()
    {
        // bool status = false;
        if (WiFi.status() == WL_CONNECTED)
        {
            return true;
        }
        else
            return false;
    }
};
