#ifndef ENVIRONMENTAL_H
#define ENVIRONMENTAL_H

// Environmental sensors module header
// Consolidates light, ground and camera

// ============== Camera ==============
void camera_init(void);
void camera_capture(void);
void camera_process(void);
void camera_update(void);
void camera_cleanup(void);

// ============== Light Sensor ==============
void light_init(void);
void light_read(double *light_value);
void light_update(void);
void light_cleanup(void);

// ============== Ground Sensor ==============
void ground_init(void);
void ground_read(double *ground_value);
void ground_update(void);
void ground_cleanup(void);

#endif // ENVIRONMENTAL_H
