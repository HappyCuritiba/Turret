#include <Servo.h>
#include <HardwareSerial.h>

Servo servoX;
Servo servoY;
Servo servoZ;

const int pinServoX = 9;//*********************///
const int pinServoY = 10;// LIGAÇÃO DOS SERVOS///
const int pinServoZ = 11;//******************////

const int pinX = A0;// ************************///
const int pinY = A1; // ****LIGACAO JOYSTICK***///
const int pinZ = A2;//************************///

// POSIÇÃO INICIAL//
 int angX = 90;
 int angY = 90;

 //PARAMÊTROS DE AJUSTE//

 const int center = 512;
 const int deadzone = 60;
 const int step_min = 1;
 const int step_max = 5;
 const unsigned long interval_ms = 15;

 unsigned long lastTick = 0;


void setup() {

  servoX.attach(pinServoX);
  servoY.attach(pinServoY);
  servoZ.attach(pinServoZ);

  servoX.write(angX);
  servoY.write(angY);
  servoZ.write(0);

  pinMode(pinZ, INPUT_PULLUP);
  Serial.begin(9600);
 
}

int computeStep(int val){
  int dist = abs( val - center) - deadzone;
  if( dist < 0) dist =0;
  int step = map(dist, 0, 512 - deadzone, step_min, step_max);
  if(step < step_min) step =0;
  if (step > step_max) step = step_max;
  return step;
}

void loop() {


if(millis() - lastTick < interval_ms) return;
lastTick = millis();

int x = analogRead(pinX);
int y = analogRead(pinY);

///CONTROLANDO O EIXO X///

if( x > center + deadzone){
  angX += computeStep(x);

} else if(x < center - deadzone){
  angX -= computeStep(x);
}

//CONTROLE DO EIXO Y///
if( y > center + deadzone){
  angY += computeStep(y);

} else if(y < center - deadzone){
  angY -= computeStep(y);
}


angX = constrain(angX, 0, 180);
angY = constrain(angY, 0, 180);

servoX.write(angX);
servoY.write(angY);

////CONTROLE DO EIXO Z/////

if(digitalRead(pinZ) == LOW){
  servoZ.write(180);

} else{
  servoZ.write(0);
}


///DEBUB NO TERMINAL/////

Serial.print("X = "); Serial.print(angX);
Serial.println( "y = "); Serial.print(angY);
Serial.println ("Z = "); Serial.print(digitalRead(pinZ) == LOW ? 180: 0);

}


