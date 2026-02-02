// Bibliotecas do c
#include <stdio.h> // biblioteca de input e outputs
#include <stdlib.h>
#include <string.h> // biblioteca de string

// Main module headers
#include "simulation.h" // headers para recursos simulacao
#include "control.h"  // headers para recursos do controle
#include "datapath.h"  // headers para recursos do datapath

// Feature and sensor module headers
#include "features.h"  // header para recursos extras do robo
#include "sensors.h"  // header para recursos dos sensores

// Main program entry point
int main(int argc, char *argv[])
{
    // Initialize all modules
    simulation_init(); // inicializa recursos da simulacao

    control_init();  // recursos do controle
    datapath_init();  // recursos do datapath
    features_init(); // recursos extras do robo
    sensors_init();  // sensores do robo

    // Main control loop - modificar posteriormente (adicionar paralelismo)
    while (1)
    {
        reset_actuator_values();
        get_sensor_input();
        blink_leds();

        if (cliff_detected())
        {
            go_backwards();
            turn_left();
        }
        else
        {
            run_braitenberg();
        }
        set_actuators();
        step();

        // Read sensor data
        sensors_read();
        sensors_update();

        // Update control logic
        control_update();
        datapath_update();

        // Update features
        features_update();

        // Update simulation
        simulation_update();
    }

    // Cleanup (if main loop exits)
    sensors_cleanup(); // desaloca os recursos de sensores
    features_cleanup();  // desaloca recursos extras do robo
    control_cleanup();  // desaloca os recursos do controle
    datapath_cleanup(); // desaloca os recursos do datapath
    
    simulation_cleanup();  // finaliza a simulacao

    return EXIT_SUCCESS;  // finaliza o programa
}