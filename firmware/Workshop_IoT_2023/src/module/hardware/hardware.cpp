#include "../include/hardware_module.h"

void HARDWARE::setup_hardware()
{
    pinMode(led_1, OUTPUT);
    pinMode(led_2, OUTPUT);
    pinMode(led_3, OUTPUT);
    pinMode(led_4, OUTPUT);
    pinMode(led_5, OUTPUT);
    pinMode(led_6, OUTPUT);
    pinMode(led_7, OUTPUT);
    pinMode(led_8, OUTPUT);

    pinMode(button_1, INPUT);
    pinMode(button_2, INPUT);
    pinMode(button_3, INPUT);
}

void HARDWARE::led_on(const int led)
{
    digitalWrite(led, HIGH);
}
void HARDWARE::led_off(const int led)
{
    digitalWrite(led, LOW);
}

void HARDWARE ::led_all_on()
{
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH);
    digitalWrite(led_4, HIGH);
    digitalWrite(led_5, HIGH);
    digitalWrite(led_6, HIGH);
    digitalWrite(led_7, HIGH);
    digitalWrite(led_8, HIGH);
}
void HARDWARE::led_all_off()
{
    digitalWrite(led_1, LOW);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, LOW);
    digitalWrite(led_4, LOW);
    digitalWrite(led_5, LOW);
    digitalWrite(led_6, LOW);
    digitalWrite(led_7, LOW);
    digitalWrite(led_8, LOW);
}
