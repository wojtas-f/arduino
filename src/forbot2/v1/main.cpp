#include <Arduino.h>

void setup()
{
    pinMode(8, OUTPUT);
}

void loop()
{
    blink(8);
    blink(7);
}

void blink(int pinIndex)
{
    digitalWrite(pinIndex, HIGH);
    delay(1000);
    digitalWrite(pinIndex, LOW);
    delay(1000);
}
