#include <Arduino.h>

struct light
{

    boolean redDiode;
    boolean yellowDiode;
};

void setup()
{
    pinMode(8, OUTPUT);
    pinMode(7, OUTPUT);
}

void loop()
{
    blink(8);
    blink(7);
}

void blink(int pinIndex)
{
    blink_async();
}

void blink_async()
{
    int changeTime = 1000;
    enum LightState
    {
        RED,
        YELLOW
    };
    static LightState currentColor = RED;
    static unsigned long lastChange = 0;

    if (millis() - lastChange > changeTime)
    {
        if (currentColor == RED)
            currentColor = YELLOW;
        else
            currentColor = RED;
        lastChange = millis();
    }

    light diodes;
    switch (currentColor)
    {
    case RED:
        diodes.redDiode = true;
        diodes.yellowDiode = false;
        break;
    case YELLOW:
        diodes.redDiode = false;
        diodes.yellowDiode = true;
        break;
    }

    updateLEDs(diodes);
}

void updateLEDs(light diodes)
{
    digitalWrite(8, diodes.redDiode ? HIGH : LOW);
    digitalWrite(7, diodes.yellowDiode ? HIGH : LOW);
}
