# Playful Experiences
The goal of this project is to create a fun analog interface. 

# Project : Hide and Glow!

## Description
Hide and Glow is a fast paced human vs machine game. In player side of the game, there are five lights and five buttons corresponding to each of the lights. On the machine side, there is a servo powered arm with a light detector at the end of the arm. 
The objective of this game is to avoid LEDs/lights from getting detected by the randomly moving light detector(guided by the servo arm). 

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
![alt text](https://github.com/manouj/physicalComputing/blob/master/Arduino/PlayfulExperiencces/buttonsAndServo.gif "buttonsAndServo")

### Functionality demo - Light detection 
![alt text](https://github.com/manouj/physicalComputing/blob/master/Arduino/PlayfulExperiencces/LightDetection.gif "lightDetection")

## Code
 [click here](https://github.com/manouj/physicalComputing/blob/master/Arduino/PlayfulExperiencces/HideAndGlow.ino)


