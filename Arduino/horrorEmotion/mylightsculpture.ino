int ledPin = 3;
int switchPin = 2;
int switchRead = 0;
int mode = 0;
boolean pressing = false;
int counter = 0;
int reverseCount = 255;
int fastCount = 0;
long pMillis = 0;
long newMillis = 0;
int interval = 100;
int fastInterval = 0.01;
const int ledPin4 = 4;
int ledPin5 = 5;
int ledPin6 = 6;

boolean flipFlop = false;

//Mode 2 Variables


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
}

void loop() {

  switchRead = digitalRead(switchPin);
  //Serial.println(switchRead);

  if (switchRead == 1) {
    pressing = true;
  }

  if (switchRead == 0 && pressing == true) {
    pressing = false;
    //do something
    mode++;
    Serial.println(mode);
  }

  if (mode == 0) {
    //Reset of Off Condition
    counter = 0;
    reverseCount = 0;
    fastCount = 0;
    analogWrite(ledPin, 0);
    analogWrite(ledPin6, 0);
    analogWrite(ledPin5, 0);
    Serial.println("Mode 0");

  }
  else if (mode == 1) {

    if (millis() - pMillis >= interval) {
      pMillis = millis();
      if (counter < 255) {
        counter++;
        //reverseCount++;
      }
    }
    analogWrite(ledPin6, counter);
    analogWrite(ledPin5, 0);
    Serial.println("Mode 1");

  } else if (mode == 2) {

    //run Mode program
    if (millis() - pMillis >= interval) {
      pMillis = millis();
      if (counter > 0) {
        counter--;

      }
      if (reverseCount < 255)
      {
        reverseCount++;
      }

      
    }
    analogWrite(ledPin6, counter);
    analogWrite(ledPin5, reverseCount);
    if (reverseCount >= 50)
      { if (millis() - newMillis >= fastInterval) {
          newMillis = millis();
          if (flipFlop == false) {
            fastCount++;
          } else {
            fastCount--;
          }
          Serial.println(counter);
        }

        analogWrite(ledPin, fastCount);
        if (fastCount >= 255) {
          flipFlop = true;
        }
        if (fastCount <= 0) {
          flipFlop = false;
        }
      }
    Serial.println("Mode 2");

  } else {
    mode = 0;
  }



}
