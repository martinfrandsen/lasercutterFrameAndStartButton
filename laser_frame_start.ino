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
  long now = millis();
  int frameState = digitalRead(buttonFrame);
  int startState = digitalRead(buttonStart);
  if (frameState == LOW) {
    Serial.println(frameState);
    delay(150);
  }
  if (frameState == LOW && buttonFramePrevState == HIGH && lastRun < now) {
    Serial.println("Frame!");
    Serial.println(lastRun);
    Serial.println(now);
    UpdateLastRun();
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press('r');
    Keyboard.releaseAll();
    buttonFramePrevState = LOW;
    delay(150);
  } else {
    buttonFramePrevState = HIGH;
  }
  if (startState == LOW && buttonStartPrevState == HIGH && lastRun < now) {
    Serial.println("Start!");
    UpdateLastRun();
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press('s');
    Keyboard.releaseAll();
    buttonStartPrevState = LOW;
    delay(150);
  } else {
    buttonStartPrevState = HIGH;
  }
}

void DetectPress2()
{
  int frameState = digitalRead(buttonFrame);
  int startState = digitalRead(buttonStart);
  if (frameState == LOW && buttonFramePrevState == HIGH) {
    Serial.println("Frame!");
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press('r');
    Keyboard.releaseAll();
    buttonFramePrevState = LOW;
    delay(1000);
  } else {
    buttonFramePrevState = HIGH;
  }
  if (startState == LOW && buttonStartPrevState == HIGH) {
    Serial.println("Start!");
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press('s');
    Keyboard.releaseAll();
    buttonStartPrevState = LOW;
    delay(1000);
  } else {
    buttonStartPrevState = HIGH;
  }
}

void DetectPress3()
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
  //Serial.println("Lastrun: " + lastRun);
  lastRun = millis() + 1000;
}
void loop() {
  //DetectPress();
  //DetectPress2();
  DetectPress3();
}
