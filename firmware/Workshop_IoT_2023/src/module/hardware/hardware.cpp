#include "../include/hardware_module.h"

void HARDWARE::setup_hardware()
{
    pinMode(led[0], OUTPUT);
    pinMode(led[1], OUTPUT);
    pinMode(led[2], OUTPUT);
    pinMode(led[3], OUTPUT);
    pinMode(led[4], OUTPUT);
    pinMode(led[5], OUTPUT);
    pinMode(led[6], OUTPUT);
    pinMode(led[7], OUTPUT);

    pinMode(button_1, INPUT);
    pinMode(button_2, INPUT);
    pinMode(button_3, INPUT);
}

void HARDWARE::led_on(const int led, int data)
{
    if (data == 1)
    {
        digitalWrite(led, LOW);
    }
    else
        digitalWrite(led, HIGH);
}
