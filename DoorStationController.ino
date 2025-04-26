//Include Libraries

////Arduino
#include <Arduino.h>
////

////DigiUSB
#include <DigiUSB.h>
////

//Define constants

////BELL Button 1 pin
#define BT1_PIN 0
////

////BELL Button 2 pin
#define BT2_PIN 1
////

////Button LED pin
#define LED_PIN 2
////

////DigiUSB delay
#define DIGIUSB_DELAY 10
////

//Setup function
void setup() {
  ////Setup pin modes
  pinMode(BT1_PIN, INPUT);
  pinMode(BT2_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  ////

  ////Setup DigiUSB
  DigiUSB.begin();
  ////
}

//Loop function
void loop() {
  ////Check BT1 & BT2 status
  if (!digitalRead(BT1_PIN)) {
    DigiUSB.println(1);
    digitalWrite(LED_PIN, HIGH);
  } else if (!digitalRead(BT2_PIN)) {
    DigiUSB.println(2);
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  ////

  ////Run DigiUSB
  DigiUSB.delay(DIGIUSB_DELAY);
  ////
}
