#include "DigiMouse.h"

#define DELAY 250

// https://github.com/digistump/DigisparkArduinoIntegration/blob/master/libraries/DigisparkMouse/examples/Mouse/Mouse.ino

bool active = false;

void blink() { 
  pinMode(1, OUTPUT); // LED
  pinMode(2, INPUT); // Button
  digitalWrite(1, HIGH);
  DigiMouse.delay(500);
  digitalWrite(1, LOW); 
}

void setup() {
  pinMode(1, OUTPUT); // LED
  DigiMouse.begin();
  blink();
}

void loop() {
  if (digitalRead(2) == LOW) {
    blink();
    active = !active;
  }
  if (active) {
    DigiMouse.leftClick();
  }
  DigiMouse.delay(DELAY);
}
