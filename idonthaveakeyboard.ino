#include "Keyboard.h"
// #define DEBUG

void pressArrow(char key) {
  switch (key) {
  case 0x41:
    Keyboard.write(KEY_UP_ARROW);
    break;
  case 0x42:
    Keyboard.write(KEY_DOWN_ARROW);
    break;
  case 0x43:
    Keyboard.write(KEY_RIGHT_ARROW);
    break;
  case 0x44:
    Keyboard.write(KEY_LEFT_ARROW);
    break;
  }
}

void setup() {
  Serial1.begin(9600);
  Keyboard.begin();
}

bool isESC = false;
bool isArrow = false;

void loop() {
  if (Serial1.available() > 0) {
    char rcv_char = Serial1.read();

    if (isESC == true && rcv_char == 0x5B) {
      isArrow = true;
      isESC = false;
    } else if (isArrow == true) {
      pressArrow(rcv_char);
      isArrow = false;
    } else if (rcv_char == 0x1B) {
      isESC = true;
    } else if (rcv_char == 0x7F) {
      Keyboard.write(KEY_BACKSPACE);
    } else if (rcv_char == '\r') {
      Keyboard.write(KEY_RETURN);
    } else {
      Keyboard.write(rcv_char);
    }

    #ifdef DEBUG    
    Serial1.println(rcv_char, HEX);
    #endif
  }
}
