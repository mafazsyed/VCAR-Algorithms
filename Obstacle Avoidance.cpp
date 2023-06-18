#include <Servo.h>
Servo myservo;
int Echo = 13;
int Trig = 12;
int sound = 15;
#define ENA 5
#define ENB 6
#define IN1 3
#define IN2 4
#define IN3 2
#define IN4 7
#define carSpeed 150
int rightDistance = 0, leftDistance = 0, middleDistance = 0;

void forward() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void back() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void right() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stop() {
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
}

int Distance_test() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);
  float Fdistance = pulseIn(Echo, HIGH);
  Fdistance= Fdistance / 58;
  return (int)Fdistance;
}

void setup() {
  myservo.attach(A0,700,2400);
  Serial.begin(9600);
  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  stop();
}

void loop() {
  myservo.write(90);
  delay(500);
  middleDistance = Distance_test();
  if(middleDistance <= 40) {
    stop();
    delay(500);
    myservo.write(10);
    delay(500);
    rightDistance = Distance_test();
    delay(500);
    myservo.write(90);
    delay(500);
    myservo.write(180);
    delay(500);
    leftDistance = Distance_test();
    delay(500);
    myservo.write(90);
    delay(500);
    if(rightDistance > leftDistance) {
      right();
      delay(360);
    }
    else if(rightDistance < leftDistance) {
      left();
      delay(360);
    }
    else if((rightDistance <= 40) || (leftDistance <= 40)) {
      back();
    }
    else {
      forward();
    }
  }
  else {
    forward();
  }
}
