# VCAR - Vacuum Cleaning Autonomous Robot

VCAR is an independent personal project, in progress since April 2022, aimed at designing and manufacturing an autonomous robot. The robot has a built-in mini vacuum cleaner and is capable of obstacle avoidance and line/object-following. 
<img src="https://github.com/mafazsyed/VCAR-Algorithms/assets/120568449/d93e681b-dd87-42d7-aea5-2a57d83b800d" width="800">

## Specifications

- **Obstacle Avoidance:** The robot can navigate around obstacles in its path.
- **Line/Object-Following:** It is capable of following a line or an object.
- **Filtered Vacuum:** The robot houses a filtered vacuum for cleaning purposes.
- **Efficient Debris Disposal:** It is designed for easy and efficient disposal of vacuum-collected debris.
- **User-Serviceable:** The robot's design allows for user servicing.
- **Sustainable:** VCAR is designed with sustainability in mind.

The exploration algorithms of the robot, which are written in C++, are still undergoing optimization to avoid repetitive scans of the same area and to ensure comprehensive environmental coverage. The vacuum cleaning capability is still in the conceptual stage and will be incorporated atop the existing robot structure. 

## Present Status

VCAR is currently under active development. The integration of the vacuuming component is the upcoming key step in the project.

## Components

Key Components Used Thus Far:

- **Arduino Uno & Expansion Boards:** Act as the central processing unit of the robot.
- **TT Motors & Wheels (x4):** Provide essential mobility to the robot.
- **L298 Stepper Motor Modules:** Offer precise control of the motor's speed and direction.
- **HC-SR04 Ultrasonic Sensor:** Used for detecting obstacles and navigating the environment.
- **SG90 180° Servo:** Mounted with the Ultrasonic Sensor for range scanning.
- **Infrared Sensor, Detection, & 4-Way Tracking Module:** Used for object/line-following.
- **18650 Battery Box:** Powers the robot with two 18650 rechargeable batteries.

Additionally, the body of the robot is built with laser-cut acrylic, 3mm thick. A wheel/rotary encoder is used to measure the distance travelled by the robot, which helps produce enhanced algorithms.

Stay tuned for future updates on this project!
