#include "sensors.h"

// ============== Sensors Control Hub ==============

void sensors_init(void)
{
    // Initialize motion and proximity sensors
    distance_init();
    infra_red_init();
    accelerometer_init();
    position_init();

    // Initialize environmental sensors
    camera_init();
    light_init();
    ground_init();
}

void sensors_update(void)
{
    // Update motion and proximity sensors
    distance_update();
    infra_red_update();
    accelerometer_update();
    position_update();

    // Update environmental sensors
    camera_update();
    light_update();
    ground_update();
}

void sensors_read(void)
{
    // Read all sensor values
    double distance_values[8];
    double ir_values[8];
    double accel_xyz[3];
    double position_xyz[3];
    double ground_values[3];
    double light_value;

    distance_read(distance_values);
    infra_red_read(ir_values);
    accelerometer_read(&accel_xyz[0], &accel_xyz[1], &accel_xyz[2]);
    position_read(&position_xyz[0], &position_xyz[1], &position_xyz[2]);
    ground_read(ground_values);
    light_read(&light_value);
    camera_capture();
    camera_process();
}

void sensors_cleanup(void)
{
    // Cleanup motion and proximity sensors
    distance_cleanup();
    infra_red_cleanup();
    accelerometer_cleanup();
    position_cleanup();

    // Cleanup environmental sensors
    camera_cleanup();
    light_cleanup();
    ground_cleanup();
}
