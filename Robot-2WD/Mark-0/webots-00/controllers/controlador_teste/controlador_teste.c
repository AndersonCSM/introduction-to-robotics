// bibliotecas do simulador, MAKE versão para robô físico
#include <webots/robot.h>
// controle do motor para girar pra frente ou para trás
#include <webots/motor.h>
// biblioteca C para I/O
#include <stdio.h>

// definindo variáveis para os motores
static WbDeviceTag left_motor, right_motor;

int main(){

wb_robot_init(); // inicializador do robo para simulador

/* motor da esquerda recebe "left wheel motor" que 
o nome do motor no projeto físico
*/
left_motor = wb_robot_get_device("left wheel motor");
right_motor = wb_robot_get_device("right wheel motor");
 
/*
Definindo para os motores rodarem infinitamentes
*/
wb_motor_set_position(left_motor, INFINITY);
wb_motor_set_position(right_motor, INFINITY);

/*
Definindo a velocidade dos motores
*/
wb_motor_set_velocity(left_motor, 2.0);
wb_motor_set_velocity(right_motor, 2.0);  

wb_robot_cleanup(); // finaliza o robo

/* FUNCOES
1. wb_robot_step() é ela que atualiza a leitura dos sensores.

2. TIME_STEP é usado para calcular o tempo de simulação no simulador

*/
return 0;
}