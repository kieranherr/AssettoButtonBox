#include "Keyboard.h"

const int buttonPin[] = {2, 3, 4, 5, 6, 7, 8, 9};
int buttonState[] = {0, 0, 0, 0, 0, 0, 0, 0};
int prevButtonState[] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};
long lastDebounceTime[] = {0, 0, 0, 0, 0, 0, 0, 0};
int pinCount = 8;

long debounceDelay = 25;

void setup() {
  for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--){
    pinMode(buttonPin, INPUT_PULLUP);
  digitalWrite(buttonPin, HIGH);
  }
  Keyboard.begin();
}
int outputAction(int currentButton) {
    if (currentButton == 1) {
      Keyboard.press('8');
      delay(200);
      Keyboard.releaseAll();
    }
    if (currentButton + 1 == 2) {
      Keyboard.press('7');
      delay(200);
      Keyboard.releaseAll();
    }
    if (currentButton + 2 == 3) {
      Keyboard.press('6');
      delay(200);
      Keyboard.releaseAll();
    }
    if (currentButton + 3 == 4) {
      Keyboard.press('5');
      delay(200);
      Keyboard.releaseAll();
    }
    if (currentButton + 4 == 5) {
      Keyboard.press('4');
      delay(200);
      Keyboard.releaseAll();
    }
    if (currentButton + 5 == 6) {
      Keyboard.press('3');
      delay(200);
      Keyboard.releaseAll();
    }
    if (currentButton + 6 == 7) {
      Keyboard.press('2');
      delay(200);
      Keyboard.releaseAll();
    }
    if (currentButton + 7 == 8) {
      Keyboard.press('1');
      delay(200);
      Keyboard.releaseAll();
    }
}
void loop() {
   for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) {
    buttonState[thisPin] = digitalRead(buttonPin[thisPin]);

    if ((buttonState[thisPin] != prevButtonState[thisPin]) && (buttonState[thisPin] == HIGH)) {
      if ((millis() - lastDebounceTime[thisPin]) > debounceDelay) {
        outputAction(thisPin);
        lastDebounceTime[thisPin] = millis();
      }
    }

    prevButtonState[thisPin] = buttonState[thisPin];
  }
}
