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



## The sculpture
The sculpture consists of the following pieces
1. Two projection tubes made using the Template Marker site. 
2. Two different outlines - illustrated and cut using the cricut paper cutting machine.
3. A box to hold the projection tubes and a screen to create a theater effect.

## Code
Please [click here](https://github.com/manouj/physicalComputing/blob/master/Arduino/horrorEmotion/mylightsculpture.ino) for the code

## Circuit
1. 2 LED lights - One white and one red
2. One push button
3. 2 - 220 ohm resistors
4. 1 - 10K ohm resistor
5. 1 Arduino Uno
