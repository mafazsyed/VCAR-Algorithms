#include <AFMotor.h>
#define Trig 12
#define Echo 13
float cm;
float temp;
int ENA = 5;
int IN1 = 3;
int IN2 = 4;
int ENB = 6;
int IN3 = 2;
int IN4 = 7;
int Sensor1 =A5;
int Sensor2 =A2;
int val1;
int val2;

void setup() {
pinMode(ENA, OUTPUT);
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(ENB, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
pinMode(Sensor1, INPUT);
pinMode(Sensor2, INPUT);
pinMode(Trig, OUTPUT);
pinMode(Echo, INPUT);
Serial.begin(9600);
}

void loop(){
val1 = digitalRead(A5);
val2 = digitalRead(A2);

digitalWrite(Trig, LOW);
delayMicroseconds(2);
digitalWrite(Trig,HIGH);
delayMicroseconds(10);
digitalWrite(Trig, LOW);
temp = float(pulseIn(Echo, HIGH));
cm = (temp * 17 )/1000;

if (val1 == HIGH && val2 == LOW && ( cm >5 && cm <10)) {
right();
}
else if(val1 == LOW && val2 == HIGH && ( cm >5 && cm <10)) {
left();
}
else if(val1 == HIGH && val2 == HIGH && ( cm >15 && cm <25)) {
forward();
}
else if(val1 == HIGH && val2 == HIGH && ( cm >30 || cm <3)) {
stop();
}
else if((val1 == LOW && val2 == LOW) || ( cm <3)) {
back();
}
Serial.print("Echo =");
Serial.print(temp);
Serial.print(" | | Distance = ");
Serial.print(cm);
Serial.println("cm");
delay(100);
}

void left(){
analogWrite(ENA, 160);
analogWrite(ENB, 60);
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
digitalWrite(IN3,LOW);
digitalWrite(IN4,LOW);
Serial.println("left");
}

void right(){
analogWrite(ENA, 60);
analogWrite(ENB, 160);
digitalWrite(IN1, LOW);
digitalWrite(IN2,LOW);
digitalWrite(IN3, HIGH);
digitalWrite(IN4,LOW);
Serial.println("right");
}

void forward(){
analogWrite(ENA, 130);
analogWrite(ENB, 130);
digitalWrite(IN1, HIGH);
digitalWrite(IN2,LOW);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);
Serial.println("run");
}

void stop(){
digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
Serial.println("stop");
}

void back(){
analogWrite(ENA, 110);
analogWrite(ENB, 110);
digitalWrite(IN1, LOW);
digitalWrite(IN2,HIGH);
digitalWrite(IN3,LOW);
digitalWrite(IN4, HIGH);
Serial.println("back");
}
