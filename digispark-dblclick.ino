#include "DigiMouse.h"

#define LED 1
#define BUTTON 2

// https://github.com/digistump/DigisparkArduinoIntegration/blob/master/libraries/DigisparkMouse/examples/Mouse/Mouse.ino
// https://www.logiqbit.com/perfect-arduino-button-presses

bool button_debounce = false; 
bool active = false;
int counter = 0;

void blink() { 
  digitalWrite(LED, HIGH);
  DigiMouse.delay(100);
  digitalWrite(LED, LOW); 
}

void setup() {
  DigiMouse.begin();
  pinMode(LED, OUTPUT); // LED
  pinMode(BUTTON, INPUT); // Button
  blink();
}

void loop() {
  if (digitalRead(BUTTON) == LOW && button_debounce == false) {
    button_debounce = true;
    active = !active;
    counter = 0;
    DigiMouse.setButtons(0);
    DigiMouse.delay(100);
  }
  if (digitalRead(BUTTON) == HIGH && button_debounce == true) {
    button_debounce = false;  // this will prevent subsequent presses
  }
  digitalWrite(LED, active ? HIGH : LOW);
  if (active) {
    counter = counter < 10 ? counter + 1 : 0;
    DigiMouse.setButtons(counter < 5 ? 1<<0 : 0);
  }
  DigiMouse.delay(10);
}
