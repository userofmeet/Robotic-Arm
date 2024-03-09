#include <Servo.h>
Servo baseServo;
Servo shoulderServo;
Servo gripperServo;

int joyX = A0; 
int joyY = A1; 
int switchPin = 2;
int xAxisValue;
int yAxisValue;

int switchState = 0;
int lastSwitchState = 0;

void setup() {
  baseServo.attach(9);        
  shoulderServo.attach(10);   
  gripperServo.attach(11);   
  pinMode(switchPin, INPUT);
}

void loop() {
  xAxisValue = analogRead(joyX);
  yAxisValue = analogRead(joyY);

  int baseAngle = map(xAxisValue, 0, 1023, 0, 180);
  int shoulderAngle = map(yAxisValue, 0, 1023, 0, 180);

  switchState = digitalRead(switchPin);
  if (switchState != lastSwitchState) {
    if (switchState == HIGH) {
      gripperServo.write(90); 
    } else {
      gripperServo.write(0); 
    }
    delay(50); 
  }
  baseServo.write(baseAngle);
  shoulderServo.write(shoulderAngle);
  lastSwitchState = switchState;
}
