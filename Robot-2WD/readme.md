# 2WD Robot Description

Robot iterations follow the "mark N" naming, where each mark builds on a base platform and introduces new objectives, sensors, and actuators.

* **Objective:** what the robot version is designed to accomplish.
* **Sensors and actuators:** the components used in the build.

## Mark 0

**Description:** baseline 2WD robot used as the foundational platform for all subsequent versions; commonly sold as an entry-level kit.

**Components:**

1. 2x DC motors;
2. Acrylic chassis;
3. Battery case with on/off switch;
4. L298N motor driver;
5. esp32 WROOM-32 controller with pin-extension shield;
6. HC-SR04 Ultrasonic sensor.

**Base platform:** dedicated [Mark 0 base](Mark-0/).

**Objectives:**

* Achieve motion with three DoF in the plane: position $(x, y)$ and orientation $\\Theta$ (theta);
* Complete predefined navigation paths.

**Sensors:** ultrasonic.

**Actuators:** 2x DC motors for locomotion.

**Controller:** 1x esp32 WROOM-32.

## Mark 1

**Description:** line-following variant of the base 2WD platform.

**Components:**

1. Same as Mark 0;
2. Line follower sensor array (IR).

**Base platform:** [Mark 0](Mark-0/)

**Objectives:**

* Follow a line from point A to point B.

**Sensors:** line follower.

**Actuators:** none (locomotion uses the Mark 0 drive).

**Controller:** 1x esp32 WROOM-32.

## Mark 2

**Description:** 2WD platform with front loader attachment.

**Components:**

1. Same as Mark 1;
2. Front loader mechanism;
3. 2x micro servos for loader DoF.

**Base platform:** Mark 1

**Objectives:**

* Emulate front-loader tractor behavior.

**Sensors:** none.

**Actuators:** front loader with 2 degrees of freedom powered by 2 servos.

**Controller:** 1x esp32 WROOM-32.

## Mark 3

**Description:** articulated robotic arm mounted on 2WD platform.

**Components:**

1. Same as Mark 1;
2. Robotic arm structure;
3. 4x micro servos for arm DoF.

**Base platform:** Mark 1

**Objectives:**

* Emulate excavator-like articulated arm motions.

**Sensors:** none.

**Actuators:** robotic arm with 4 degrees of freedom driven by 4 servos.

**Controller:** 1x esp32 WROOM-32.

## Mark 4

**Description:** computer-vision-enabled 2WD platform.

**Components:**

1. Same as Mark 3;
2. Camera module.

**Base platform:** Mark 3

**Objectives:**

* Perform computer vision tasks.

**Sensors:** camera.

**Actuators:** none.

**Controller:** 1x esp32 WROOM-32.
