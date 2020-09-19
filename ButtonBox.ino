#include <RotaryEncoder.h>
#include <Joystick.h>

//Buttons
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
#define button11 6
#define button12 7
//Rotary Encoders
#define rotIntPin0 0
#define rotIntPin1 1
#define rotIntPin2 2
#define rotIntPin3 3

//Define Encoders
RotaryEncoder encoder(rotIntPin0,rotIntPin1);
RotaryEncoder encoder2(rotIntPin3,rotIntPin2);

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

  Joystick.begin(false);
  attachInterrupt(digitalPinToInterrupt(rotIntPin0), getTick1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(rotIntPin1), getTick1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(rotIntPin2), getTick2, CHANGE);
  attachInterrupt(digitalPinToInterrupt(rotIntPin3), getTick2, CHANGE); 
}

void getTick1(){
  encoder.tick();    
}
void getTick2(){
  encoder2.tick();
}

void loop() {
  
  if (digitalRead(button1) == 0)  Joystick.pressButton(0); 
  if (digitalRead(button2) == 0)  Joystick.pressButton(1); 
  if (digitalRead(button3) == 0)  Joystick.pressButton(2);  
  if (digitalRead(button4) == 0)  Joystick.pressButton(3); 
  if (digitalRead(button5) != 0)  Joystick.pressButton(4); //suspect that I got a push to open button here
  if (digitalRead(button6) == 0)  Joystick.pressButton(5); 
  if (digitalRead(button7) == 0)  Joystick.pressButton(6); 
  if (digitalRead(button8) == 0)  Joystick.pressButton(7); 
  if (digitalRead(button9) != 0)  Joystick.pressButton(8); //suspect that I got a push to open button here
  if (digitalRead(button10) == 0) Joystick.pressButton(9); 
  if (digitalRead(button11) == 0) Joystick.pressButton(10);
  if (digitalRead(button12) == 0) Joystick.pressButton(13);
  
   static int pos = 0;  
   static int pos2 = 0;  
    
   int newPos = encoder.getPosition();
   int newPos2 = encoder2.getPosition();
   
   if (pos != newPos) {
    if (newPos < pos) Joystick.pressButton(11);//;delay(80);}
    else if (newPos > pos) Joystick.pressButton(12);//delay(80);}
    pos = newPos;
   }   
   
   if (pos2 != newPos2) {
    if (newPos2 < pos2) Joystick.pressButton(14);//delay(80);}
    else if (newPos2 > pos2) Joystick.pressButton(15);//delay(80);}
    pos2 = newPos2;    
   } 
  
  Joystick.sendState();//send state 1st before we clear the button states
  ClearButtons();
}

void ClearButtons()
{
  Joystick.releaseButton(0);
  Joystick.releaseButton(1);
  Joystick.releaseButton(2);
  Joystick.releaseButton(3);
  Joystick.releaseButton(4);
  Joystick.releaseButton(5);
  Joystick.releaseButton(6);
  Joystick.releaseButton(7);
  Joystick.releaseButton(8);
  Joystick.releaseButton(9);
  Joystick.releaseButton(10);
  Joystick.releaseButton(13);
  delay(150);// adding the delay to keep the rotary button lit just a bit longer
  Joystick.releaseButton(12);
  Joystick.releaseButton(11);
  Joystick.releaseButton(14);
  Joystick.releaseButton(15);   
}
