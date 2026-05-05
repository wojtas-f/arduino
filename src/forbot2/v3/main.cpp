#include <Arduino.h>

struct LightConfig
{
  bool red;
  bool yellow;
};

void setup()
{
  pinMode(8, OUTPUT);
}

void loop()
{
}

const LightConfig states[] = {
    {true, false}, // Stan 0: Czerwona
    {false, true}  // Stan 1: Żółta
};

void blink_async()
{
  const unsigned long interval = 1000;
  static unsigned long lastChange = 0;
  static int stateIndex = 0;

  if (millis() - lastChange >= interval)
  {
    lastChange = millis();
    // Przełączamy indeks stanu (0 -> 1 -> 0...)
    stateIndex = (stateIndex + 1) % (sizeof(states) / sizeof(LightConfig));
  }

  // Pobieramy gotową konfigurację z tablicy
  updateLEDs(states[stateIndex]);
}

void updateLEDs(LightConfig config)
{
  digitalWrite(8, config.red ? HIGH : LOW);
  digitalWrite(7, config.yellow ? HIGH : LOW);
}