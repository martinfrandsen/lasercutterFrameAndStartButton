#include <Keyboard.h>

int buttonFrame = 2;
int buttonStart = 3;

void setup() {
  //start serial connection
  Serial.begin(9600);
  //declare the buttons as input_pullup
  pinMode(buttonFrame, INPUT_PULLUP);
  pinMode(buttonStart, INPUT_PULLUP);
  Keyboard.begin();
}
void loop() {
  DetectPress();
}

void DetectPress()
{
  // read frame button state
  int frameState = digitalRead(buttonFrame);
  // read start button state
  int startState = digitalRead(buttonStart);
  // if frame button is pressed enter if statement
  if (frameState == LOW) {
    // ghost call prevention, wait for 30 ms
    delay(30);
    // read frame button state
    frameState = digitalRead(buttonFrame);
    // if frame button continues to be pressed, then call FramePressed function
    if (frameState == LOW) {
      FramePressed();
    }
  }
  // if start button is pressed enter if statement
  if (startState == LOW) {
    // ghost call prevention, wait for 30 ms
    delay(30);
    // read start button state again
    frameState = digitalRead(buttonStart);
    // if start button continues to be pressed, then call StartPressed function
    if (startState == LOW) {
      StartPressed();
    }
  }
}

void FramePressed() {
  // presses left ALT key
  Keyboard.press(KEY_LEFT_ALT);
  // presses r key
  Keyboard.press('r');
  // releases all keys pressed
  Keyboard.releaseAll();
  // pauses for 1.5 seconds
  DelayAfterButtonPressed();
}
void StartPressed() {
  // presses left ALT key
  Keyboard.press(KEY_LEFT_ALT);
  // presses s key
  Keyboard.press('s');
  // releases all keys pressed
  Keyboard.releaseAll();
  // pauses for 1.5 seconds
  DelayAfterButtonPressed();
}
void DelayAfterButtonPressed() {
  delay(1500);
}
// will write what ever text given to the method. ie: PrintString("This is a test string");
void PrintString(String text) {
  for (char& c : text) {
    Keyboard.write(c);
  }
}
