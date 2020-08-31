#include <RotaryEncoder.h>
#include <Joystick.h>

#define button1 18
#define button2 19
#define button3 20
#define button4 21
#define button5 10
#define button6 14
#define button7 15
#define button8 16
#define button9 8
#define button10 9
#define button11 7
#define button12 6

RotaryEncoder encoder(3,2);
RotaryEncoder encoder2(5,4);

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  16, 0,                  // Button Count, Hat Switch Count
  false, false, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

void setup() {
  // Initialize Button Pins
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);  
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);
  pinMode(button6,INPUT_PULLUP);
  pinMode(button7,INPUT_PULLUP);
  pinMode(button8,INPUT_PULLUP);
  pinMode(button9, INPUT_PULLUP);
  pinMode(button10, INPUT_PULLUP);
  pinMode(button11,INPUT_PULLUP);
  pinMode(button12, INPUT_PULLUP);
 
  digitalWrite(button10,HIGH);
  digitalWrite(button9, HIGH);
  digitalWrite(button5, HIGH);

  Joystick.begin(true);
}

void loop() {
  if (digitalRead(button1) == 0)  Joystick.pressButton(0);  else Joystick.releaseButton(0);
  if (digitalRead(button2) == 0)  Joystick.pressButton(1);  else Joystick.releaseButton(1);
  if (digitalRead(button3) == 0)  Joystick.pressButton(2);  else Joystick.releaseButton(2);
  if (digitalRead(button4) == 0)  Joystick.pressButton(3);  else Joystick.releaseButton(3);
  if (digitalRead(button5) != 0)  Joystick.pressButton(4);  else Joystick.releaseButton(4); //suspect that I got a push to open button here
  if (digitalRead(button6) == 0)  Joystick.pressButton(5);  else Joystick.releaseButton(5);
  if (digitalRead(button7) == 0)  Joystick.pressButton(6);  else Joystick.releaseButton(6);
  if (digitalRead(button8) == 0)  Joystick.pressButton(7);  else Joystick.releaseButton(7);
  if (digitalRead(button9) != 0)  Joystick.pressButton(8);  else Joystick.releaseButton(8); //suspect that I got a push to open button here
  if (digitalRead(button10) == 0) Joystick.pressButton(9);  else Joystick.releaseButton(9);
  if (digitalRead(button11) == 0) Joystick.pressButton(10); else Joystick.releaseButton(10);
  if (digitalRead(button12) == 0) Joystick.pressButton(11); else Joystick.releaseButton(11);

   static int pos = 0;    
   encoder.tick();
  
   int newPos = encoder.getPosition();
   if (pos != newPos) {
    if (newPos < pos) {Joystick.setButton(12,HIGH);delay(80);}
    else if (newPos > pos) {Joystick.setButton(13,HIGH);delay(80);}
    pos = newPos;
  } 
  else {Joystick.releaseButton(12);Joystick.releaseButton(13);}
  
   static int pos2 = 0;
   encoder2.tick();  
   int newPos2 = encoder2.getPosition();
   if (pos2 != newPos2) {
    if (newPos2 < pos2) {Joystick.setButton(14,HIGH);delay(80);}
    else if (newPos2 > pos2) {Joystick.setButton(15,HIGH);delay(80);}
    pos2 = newPos2;    
  } 
  else {Joystick.releaseButton(14);Joystick.releaseButton(15);}
}
