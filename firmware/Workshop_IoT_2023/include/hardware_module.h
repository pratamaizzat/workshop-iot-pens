#ifndef hardware_module_h
#define hardware_module_h

#include <Arduino.h>

class HARDWARE
{
public:
    const int led[8] = {15, 4, 5, 18, 19, 21, 22, 23};
    const int button_1 = 13;
    const int button_2 = 14;
    const int button_3 = 27;

    void setup_hardware();
    void led_on(int led, int data);
};

#endif
