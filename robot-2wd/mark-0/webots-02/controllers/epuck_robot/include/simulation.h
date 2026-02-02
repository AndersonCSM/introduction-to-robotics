#ifndef SIMULATION_H
#define SIMULATION_H

// Simulation module header
// This module handles simulation-specific initialization and management

void simulation_init(void);
void simulation_update(void);
void simulation_cleanup(void);
int simulation_get_time_step(void);
void step(void);
void passive_wait(double sec);

#endif // SIMULATION_H
