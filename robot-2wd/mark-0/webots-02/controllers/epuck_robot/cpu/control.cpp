#include <stdbool.h>

#include "control.h"
#include "features.h"
#include "sensors.h"
#include "simulation.h"

#define LEFT 0
#define RIGHT 1

#define LEDS_NUMBER 10
#define DISTANCE_SENSORS_NUMBER 8
#define GROUND_SENSORS_NUMBER 3

#define MAX_SPEED 6.28

static double speeds[2] = {0.0, 0.0};
static double distance_values[DISTANCE_SENSORS_NUMBER] = {0.0};
static double ground_values[GROUND_SENSORS_NUMBER] = {0.0};

static double weights[DISTANCE_SENSORS_NUMBER][2] = {
    {-1.3, -1.0}, {-1.3, -1.0}, {-0.5, 0.5}, {0.0, 0.0},
    {0.0, 0.0}, {0.05, -0.5}, {-0.75, 0}, {-0.75, 0}};

static double offsets[2] = {0.5 * MAX_SPEED, 0.5 * MAX_SPEED};

void control_init(void)
{
    reset_actuator_values();
}

void control_update(void)
{
    // No-op for now (control logic handled in main loop)
}

void control_cleanup(void)
{
    // No-op
}

void reset_actuator_values(void)
{
    for (int i = 0; i < LEDS_NUMBER; i++)
        leds_set(i, 0);
    speeds[LEFT] = 0.0;
    speeds[RIGHT] = 0.0;
}

void get_sensor_input(void)
{
    distance_read(distance_values);
    ground_read(ground_values);
}

void blink_leds(void)
{
    static int counter = 0;
    int led = (counter / 10) % LEDS_NUMBER;
    for (int i = 0; i < LEDS_NUMBER; i++)
        leds_set(i, i == led ? 1 : 0);
    counter++;
}

bool cliff_detected(void)
{
    for (int i = 0; i < GROUND_SENSORS_NUMBER; i++)
    {
        if (ground_values[i] < 500.0)
            return true;
    }
    return false;
}

void run_braitenberg(void)
{
    for (int i = 0; i < 2; i++)
    {
        speeds[i] = 0.0;
        for (int j = 0; j < DISTANCE_SENSORS_NUMBER; j++)
            speeds[i] += distance_values[j] * weights[j][i];

        speeds[i] = offsets[i] + speeds[i] * MAX_SPEED;
        if (speeds[i] > MAX_SPEED)
            speeds[i] = MAX_SPEED;
        else if (speeds[i] < -MAX_SPEED)
            speeds[i] = -MAX_SPEED;
    }
}

void go_backwards(void)
{
    locomotion_set_velocity(-MAX_SPEED, -MAX_SPEED);
    locomotion_update();
    passive_wait(0.2);
}

void turn_left(void)
{
    locomotion_set_velocity(-MAX_SPEED, MAX_SPEED);
    locomotion_update();
    passive_wait(0.2);
}

void set_actuators(void)
{
    locomotion_set_velocity(speeds[LEFT], speeds[RIGHT]);
}
