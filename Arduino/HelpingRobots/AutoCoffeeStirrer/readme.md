# Helping Robots
The goal for this project is to make a helpful or not helpful robot.

# Project : Coffee Stirring machine!

## Description
For many including me, a coffee in the morning is mandatory to drive them through the day. One of the steps in making any good coffee is giving it a good stir. Taking inspiration from inventor Simone Giertz, I wanted to create a coffee stirring machine. This simple machine will stir your coffee when you place your cup on it.


### Working
1. Place you cup on the marked location.
2. The machine does its job.
3. Take out the cup. Enjoy your perfectly stirred coffee!

### Challenges
1. Due to the limited availability of resources, the scale of the project was affected.

## Prototype [Sped up]
![alt text](https://github.com/manouj/physicalComputing/blob/master/Arduino/HelpingRobots/AutoCoffeeStirrer/giphy%20(1).gif "FinalGif")


## Components
1. Arduino Uno R3
2. A Servo motor
3. An ultrasonic sensor
4. A DC motor
5. Wires, npn transistor, diode and resistors

## Functional description
1. The Ultrosonic sensor detects the mug placement and it is programmatically designed to trigger the servo after two seconds of wait period.
2. The Servo motor then rotates 90 degrees to lower the servo arm.
3. The DC motor at the servo motor rotates at highest speed (255) which in turn rotates the stirrers for 5 seconds.
4. After 5 seconds, the servo motor returns back to its original position.
5. The ultra sonic sensor detects the removal of the mug. Then it resets to its original state to read new mugs.


## Code
 [click here](https://github.com/manouj/physicalComputing/blob/master/Arduino/HelpingRobots/AutoCoffeeStirrer/CoffeeStirrer.ino) for the code


