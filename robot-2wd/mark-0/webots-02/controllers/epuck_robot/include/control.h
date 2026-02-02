#ifndef CONTROL_H
#define CONTROL_H

// Control module header
// This module handles the main control logic for the robot

void control_init(void);
void control_update(void);
void control_cleanup(void);

void reset_actuator_values(void);
void get_sensor_input(void);
void blink_leds(void);
bool cliff_detected(void);
void run_braitenberg(void);
void go_backwards(void);
void turn_left(void);
void set_actuators(void);

#endif // CONTROL_H
