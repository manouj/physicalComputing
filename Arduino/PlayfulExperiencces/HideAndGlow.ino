/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int currentPos = 0;
int lpos[] = {20, 38, 56, 74, 92};
int target = 0;
int buzzerPin = 11;
int counter = 0;

long pMillis = 0;

int interval = 100;

int lightSensorPin = A0;
int analogValue = 0;
int potentioPin = A1;
int difficulty = 0;
int buttonVal = 0;


bool startGame = false;
bool endGame = false;
bool isFirstTime = true;
bool lightOver = false;
const int buttonPin1 = 2;     // the number of the pushbutton pin
const int buttonPin2 = 3;
const int buttonPin3 = 4;
const int buttonPin4 = 5;
const int buttonPin5 = 6;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  target = random(0, 5);
  myservo.write(pos);
  pinMode(buzzerPin,OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
}

void loop()
{
  buttonVal = digitalRead(buttonPin2);
  analogValue = analogRead(lightSensorPin);
  difficulty = analogRead(potentioPin);
  
  Serial.println(analogValue);
  
  if (digitalRead(buttonPin1) + digitalRead(buttonPin2) + digitalRead(buttonPin3) + digitalRead(buttonPin4) + digitalRead(buttonPin5) >= 2)
  {
    if (isFirstTime)
    {
      pos = 0;
      currentPos = 0;
      counter = 0;
      isFirstTime = false;
      
    }
    analogValue = analogRead(lightSensorPin);
    Serial.println(analogValue);
    endGame = false;
  }
  else
  {
    myservo.write(0);

    endGame = true;
    isFirstTime = true;
  }
  if (endGame == false)
  {
    if (currentPos < lpos[target])
    {
      for (pos = currentPos; pos <= lpos[target]; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);
        // tell servo to go to position in variable 'pos'
        buttonVal = digitalRead(buttonPin2);
        Serial.println(analogValue);
        if (digitalRead(buttonPin1) + digitalRead(buttonPin2) + digitalRead(buttonPin3) + digitalRead(buttonPin4) + digitalRead(buttonPin5) >= 2)
        {

          endGame = false;
          analogValue = analogRead(lightSensorPin);
          if (analogValue > 90)
          {
            isFirstTime = true;
            endGame = true;
            tone(buzzerPin, 450);
            delay(200);
            noTone(buzzerPin);
            return;
          }
          
          Serial.println(analogValue);
        }
        else
        {

          isFirstTime = true;
          endGame = true;
          tone(buzzerPin, 100);
          delay(200);
          noTone(buzzerPin);
          return;
        }
        delay(30);                       // waits 15ms for the servo to reach the position
      }

      currentPos = lpos[target];
      pMillis = millis();
    }

    else if (currentPos > lpos[target])
    {
      for (pos = currentPos; pos >= lpos[target]; pos -= 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        buttonVal = digitalRead(buttonPin2);
        Serial.println(analogValue);
        if (digitalRead(buttonPin1) + digitalRead(buttonPin2) + digitalRead(buttonPin3) + digitalRead(buttonPin4) + digitalRead(buttonPin5) >= 2)
        {

          analogValue = analogRead(lightSensorPin);
          if (analogValue > 90)
          {
            isFirstTime = true;
            endGame = true;
            tone(buzzerPin, 450);
            delay(500);
            noTone(buzzerPin);
            return;
          }
          Serial.println(analogValue);
          endGame = false;
        }
        else
        {

          endGame = true;
          isFirstTime = true;

          tone(buzzerPin, 450);
          delay(500);
          noTone(buzzerPin);
          return;
        }
        delay(30);                       // waits 15ms for the servo to reach the position
      }

      
      pMillis = millis();
    }
  }
currentPos = lpos[target];
  if (millis() - pMillis >= interval) {
    target = random(0, 5);
    pMillis = millis();

  }



  //  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
  //    // in steps of 1 degree
  //    myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //    delay(10);                       // waits 15ms for the servo to reach the position
  //  }
  //  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  //    myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //    delay(10);                       // waits 15ms for the servo to reach the position
  //  }
}
