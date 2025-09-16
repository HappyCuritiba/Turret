#include <Arduino.h>
#include <Servo.h>
#include <Button.h>

#define pot_x_pin A0
#define pot_y_pin A1
#define but_pin 13
#define laser_pin 8

#define servo_x_pin 9
#define Servo_y_pin 10
#define Servo_fire_pin 11

Servo servo_x;
Servo servo_y;
Servo servo_fire;

Button fire_in_the_hole(but_pin);

int pos_x = 0;
int pos_y = 0;
int pos_fire_trig = 90;
int pos_fire_fire = 180;

void setup()
{
  Serial.begin(9600);
  pinMode(pot_x_pin, INPUT);
  pinMode(pot_y_pin, INPUT);

  servo_x.attach(servo_x_pin);
  servo_y.attach(Servo_y_pin);

  servo_fire.attach(Servo_fire_pin);
  servo_fire.write(pos_fire_trig);

  pinMode(laser_pin, OUTPUT);
  digitalWrite(laser_pin, HIGH);

  fire_in_the_hole.begin();
}

void loop()
{
  pos_x = analogRead(pot_x_pin);
  pos_y = analogRead(pot_y_pin);

  Serial.print("X: ");
  Serial.print(pos_x);
  Serial.print(" y: ");
  Serial.print(pos_y);

  Serial.println("");

  pos_x = map(pos_x, 0, 1023, 30, 150);
  pos_y = map(pos_y, 0, 1023, 0, 180);

  servo_x.write(pos_x);
  servo_y.write(pos_y);

  if (fire_in_the_hole.pressed())
  {
    Serial.println("-----------FIRE ------------");
    servo_fire.write(pos_fire_fire);
    delay(300);
    servo_fire.write(pos_fire_trig);
  }
}
