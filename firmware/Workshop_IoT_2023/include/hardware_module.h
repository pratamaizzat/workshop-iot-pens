#ifndef hardware_module_h
#define hardware_module_h

#include <Arduino.h>

class HARDWARE
{
public:
    const int led_1 = 15;
    const int led_2 = 4;
    const int led_3 = 5;
    const int led_4 = 18;
    const int led_5 = 19;
    const int led_6 = 21;
    const int led_7 = 22;
    const int led_8 = 23;

    const int button_1 = 13;
    const int button_2 = 14;
    const int button_3 = 27;

    void setup_hardware();
    void led_on(const int led);
    void led_off(const int led);
    void led_all_on();
    void led_all_off();
};

#endif
