#ifndef SENSORS_H
#define SENSORS_H

// Sensors module main header
// Consolidated control hub for all robot sensors

// ============== Motion & Proximity Sensors ==============
// Distance Sensor (Proximity)
void distance_init(void);
void distance_read(double *distance_value);
void distance_update(void);
void distance_cleanup(void);

// Infrared Sensor
void infra_red_init(void);
void infra_red_read(double *ir_value);
void infra_red_update(void);
void infra_red_cleanup(void);

// Accelerometer
void accelerometer_init(void);
void accelerometer_read(double *x, double *y, double *z);
void accelerometer_update(void);
void accelerometer_cleanup(void);

// Position Sensor
void position_init(void);
void position_read(double *x, double *y, double *z);
void position_update(void);
void position_cleanup(void);

// ============== Environmental Sensors ==============
// Camera
void camera_init(void);
void camera_capture(void);
void camera_process(void);
void camera_update(void);
void camera_cleanup(void);

// Light Sensor
void light_init(void);
void light_read(double *light_value);
void light_update(void);
void light_cleanup(void);

// Ground Sensor
void ground_init(void);
void ground_read(double *ground_value);
void ground_update(void);
void ground_cleanup(void);

// ============== Sensors Control Hub ==============
void sensors_init(void);
void sensors_update(void);
void sensors_read(void);
void sensors_cleanup(void);

#endif // SENSORS_H
