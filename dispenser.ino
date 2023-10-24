#include <Servo.h>

Servo servo;
int cm = 0;
int pos = 0;

long readUltrasonicDistance(int triggerPin = 5, int echoPin = 4)
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  servo.attach(6, 0, 180);
}

void loop()
{
  cm = 0.01723 * readUltrasonicDistance(5, 4);
  Serial.print(cm);
  Serial.println("cm");
  delay(100);
  if(cm > 3 && cm < 10){
      for (pos = 0; pos <= 90; pos += 1) {
      servo.write(pos);
      delay(5);
    }
    for (pos = 90; pos >= 0; pos -= 1) {
      servo.write(pos);
      delay(5);
    }

  delay(1500);
  }
  else{
    servo.write(0);
  }
}