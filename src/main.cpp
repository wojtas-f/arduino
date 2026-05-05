#include <Arduino.h>

// put function declarations here:
// void blink(int pinIndex);
// void toggleDiodeOnSwitch();
void handleRoadLight();

void setup()
{
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);

  pinMode(7, INPUT_PULLUP);

  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);

  // Task 1.1
  // pinMode(8, OUTPUT); // define if the pin is input or output
  // pinMode(7, OUTPUT); // define if the pin is input or output

  // pinMode(8, OUTPUT);
  // pinMode(7, INPUT_PULLUP);
  // digitalWrite(8, LOW);
}

void loop()
{
  // put your main code here, to run repeatedly:

  // Task 1.1
  // blink(8);
  // blink(7);
  // toggleDiodeOnSwitch();
  // handleRoadLight();
}

void handleRoadLight()
{
  static int state = 0;
  const int lastState = 2;

  if (digitalRead(7) == LOW)
  {
    if (state == 0)
    {
      digitalWrite(10, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(8, LOW);
    }

    if (state == 1)
    {
      digitalWrite(10, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(8, LOW);
    }

    if (state == 2)
    {
      digitalWrite(10, LOW);
      digitalWrite(9, LOW);
      digitalWrite(8, HIGH);
    }

    state = (state + 1);
    if (state > lastState)
    {
      state = 0;
    }
    delay(1000);
  }
}

// void toggleDiodeOnSwitch()
// {
//   if (digitalRead(7) == LOW)
//   {
//     digitalWrite(8, HIGH);
//     delay(10000);
//     digitalWrite(8, LOW);
//   }
// }

// // put function definitions here:
// void blink(int pinIndex)
// {
//   digitalWrite(pinIndex, HIGH);
//   delay(1000);
//   digitalWrite(pinIndex, LOW);
//   delay(1000);
// }