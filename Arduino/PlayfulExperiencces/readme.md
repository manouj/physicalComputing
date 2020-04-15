# Playful Experiences
The goal of this project is to create a fun analog interface using arduino and everyday items. 

# Project : Hide and Glow!

## Description
Hide and Glow is a fast paced human vs machine game. In player side of the game, there are five lights and five buttons corresponding to each of the lights. On the machine side, there is a servo powered arm with a light detector at the end of the arm. 
The objective of this game is to have two lights glowing at any point of time and at the same time avoid LEDs/lights from getting detected by the randomly moving light detector(guided by the servo arm). 

### Game mechanics
Press any two buttons together to start the game. This will make the light detector to start moving.

### Challenges
1. At any point, the player should have atleast two LEDs in on state. Failure to have atleast two LEDs will result in game over.
2. When the light detector passes over an LED, that LED should be in OFF state. If the light from that LED is detected, the game is over. 

## Objective of game
The objective of this game is to last as long as possible 
1. with atleast two lights on at any time
2. with no light glowing when the light detector passes over it.

## Final video (With sound)
https://drive.google.com/file/d/19EOtFwsf9OKTORKLSHJlHZHb4tpLmdJS/view?usp=sharing

## Preview gif (Without sound)
![alt text](https://github.com/manouj/physicalComputing/blob/master/Arduino/PlayfulExperiencces/final.gif "FinalGif")


## Components
This gamebox consists of the following components
1. Arduino Uno R3
2. A Servo motor
3. A photo resistor
4. An active buzzer
5. 5 Buttons
6. 5 LEDs
7. A potentiometer
 ![alt text](https://github.com/manouj/physicalComputing/blob/master/Arduino/PlayfulExperiencces/Coll.png "components")

### Functionality demo - Starting game, Servo actions, Reset game when game over
1. Two buttons are required to be held in order to start the game. The servo motor is programmed to go to any of the 5 light spots randomly. The 5 light spots are 18 degrees apart from each other.
2. The game resets whenever less than two buttons are held. The servo goes to position 0 when the game resets. 
3. The speed of the servo was designed to be controlled by the potentiometer, which would inturn control the difficulty of the game. However, due to lack of soldering tools, this functionality was not included (It was difficult to use potentiometer directly on the breadboard).
4.Everytime the game resets, the active buzzer goes off for 100ms. 
![alt text](https://github.com/manouj/physicalComputing/blob/master/Arduino/PlayfulExperiencces/buttonsAndServo.gif "buttonsAndServo")

### Functionality demo - Light detection 
1. The photoresistor is always active, and whenever the light input is higher than the predefined treshhold value, the game resets. 
2. Everytime the game resets, the active buzzer goes off for 100ms. 

![alt text](https://github.com/manouj/physicalComputing/blob/master/Arduino/PlayfulExperiencces/LightDetection.gif "lightDetection")

## Code
 [click here](https://github.com/manouj/physicalComputing/blob/master/Arduino/PlayfulExperiencces/HideAndGlow.ino) for the code


