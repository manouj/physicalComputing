/*
   HC-SR04 example sketch

   https://create.arduino.cc/projecthub/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-036380

   by Isaac100
*/
#include <Servo.h>
Servo myservo;
int pos = 0;
int motor = 3;

const int trigPin = 9;
const int echoPin = 10;

float duration, distance;
bool isMugPlaced = false;

int counter = 0;
long pMillis = 0;
int interval = 5000;

long pMillis2 = 0;
int waitPeriod = 1000 ;

bool isStirred = true;

bool armDown = false;
bool canReadMug = true;
bool replacedMug = false;
bool foundMug = false;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motor, OUTPUT);
  myservo.attach(6);
  Serial.begin(9600);
}

void loop() {
  if (canReadMug)
    if (isMugPlaced == false)
    {
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);

      duration = pulseIn(echoPin, HIGH);
      distance = (duration * .0343) / 2;
      Serial.print("Distance: ");
      Serial.println(distance);
      if (distance > 30)
      {
        replacedMug = true;
      }

      if (distance < 10 && replacedMug)
      {
        pMillis2 = millis();
        canReadMug = false;
        replacedMug = false;
        armDown = true;
        foundMug = true;
      }

      delay(100);
    }
  if (foundMug == true)
  {
    if (millis() - pMillis2 >= waitPeriod)
    {
      isMugPlaced = true;
      foundMug = false;
      pMillis2 = millis();
    }
  }
  
  if (isMugPlaced)
  {
    if (armDown)
    {
      for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        if (pos >= 90)
        {
          armDown = false;
          isStirred = false;
          isMugPlaced = false;
          pMillis = millis();
        }
        delay(15);                       // waits 15ms for the servo to reach the position
      }
    }

    if (armDown == false)
    {
      if (isStirred == true) {
        for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(15); // waits 15ms for the servo to reach the position
          if (pos >= 90)
          {
            armDown = true;
            isMugPlaced = false;
            canReadMug = true;
          }
        }
      }
    }
  }



  if (isStirred == false)
  {
    analogWrite(motor, 255);
    if (millis() - pMillis >= interval) {
      isStirred = true;
      analogWrite(motor, 0);
      isMugPlaced = true;
      pMillis = millis();
    }
  }
  Serial.println(isStirred);
}
