#include <Keyboard.h>

long lastRun = millis();
int previousButtonState = HIGH;
int buttonFrame = 2;
int buttonStart = 3;
int buttonFramePrevState = HIGH;
int buttonStartPrevState = HIGH;
bool isDebug = true;

void setup() {
  delay(300);
  //declare the buttons as input_pullup
  pinMode(buttonFrame, INPUT_PULLUP);
  pinMode(buttonStart, INPUT_PULLUP);
  UpdateLastRun();
  Keyboard.begin();
}

void DetectPress()
{
  int frameState = digitalRead(buttonFrame);
  int startState = digitalRead(buttonStart);
  if (frameState == LOW) {
    delay(30);
    frameState = digitalRead(buttonFrame);
    if (frameState == LOW) {
      FramePressed();
    }
  }
  if (startState == LOW) {
    delay(30);
    frameState = digitalRead(buttonStart);
    if (startState == LOW) {
      StartPressed();
    }
  }
}
void FramePressed() {
  Serial.println("Frame!");
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(1500);
}
void StartPressed() {
  Serial.println("Start!");
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('s');
  Keyboard.releaseAll();
  delay(1500);
}

void PrintString(String text) {
  for (char& c : text) {
    Keyboard.write(c);
  }
}

void UpdateLastRun() {
  lastRun = millis() + 1000;
}
void loop() {
  DetectPress();
}
