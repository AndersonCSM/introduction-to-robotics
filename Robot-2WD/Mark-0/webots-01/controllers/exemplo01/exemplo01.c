// o uso <> é para buscar bibliotecas padrões do sistema

#include <webots/robot.h>
#include <stdio.h>
#include <webots/motor.h>
#include <stdlib.h>

static WbDeviceTag left_motor, right_motor; /* Static é um modificador de armazenamento que por ter sido usado em uma variável global, serve
para dizer que ela funciona apenas para esse arquivo, como não temos outros arquivos podemos apagar o "static" para não confundir. Já o WbDeviceTag 
é um tipo de variável usado para identificar um dispositivo no código do controlador, no caso o motor da esquerda e o da direita. */

int main(){  // Esta é a função principal.



 wb_robot_init(); // Função que inicia o robô.
  
  left_motor = wb_robot_get_device("left wheel motor"); // Pega o motor esquerdo (left) e armazena na variável "left_motor".
  right_motor = wb_robot_get_device("right wheel motor"); // Pega o motor direito (right) e armazena na variável "right_motor".

void andar_frente(void)
{
     wb_motor_set_position(left_motor, INFINITY);
     wb_motor_set_position(right_motor, INFINITY);
    
      wb_motor_set_velocity(left_motor, 3.0); 
      wb_motor_set_velocity(right_motor, 3.0);
}

void andar_tras(void)
{
     wb_motor_set_position(left_motor, INFINITY);
     wb_motor_set_position(right_motor, INFINITY);
    
      wb_motor_set_velocity(left_motor, -3.0); 
      wb_motor_set_velocity(right_motor, -3.0);
}

 void curva_longa_direita(void)
{
     wb_motor_set_position(left_motor, INFINITY);
     wb_motor_set_position(right_motor, INFINITY);
    
      wb_motor_set_velocity(left_motor, 3.0); 
      wb_motor_set_velocity(right_motor, 2.7);
}

 void curva_longa_esquerda(void)
{
     wb_motor_set_position(left_motor, INFINITY);
     wb_motor_set_position(right_motor, INFINITY);
    
      wb_motor_set_velocity(left_motor, 2.7); 
      wb_motor_set_velocity(right_motor, 3.0);
}

 void curva_fechada_esquerda(void)
{
     wb_motor_set_position(left_motor, INFINITY);
     wb_motor_set_position(right_motor, INFINITY);
    
      wb_motor_set_velocity(left_motor, 2.0); 
      wb_motor_set_velocity(right_motor, 4.0);
}

 void curva_fechada_direita(void)
{
     wb_motor_set_position(left_motor, INFINITY);
     wb_motor_set_position(right_motor, INFINITY);
    
      wb_motor_set_velocity(left_motor, 4.0); 
      wb_motor_set_velocity(right_motor, 2.0);
}
 

// A função wb_robot_step é responsável por alterar
// o estado da simulação, ela que garante a simulação rodando 
while (wb_robot_step(64) != -1) {

 int x = 5;
   
 if(x == 1)
{
 
   andar_frente();
}

  else if(x == 2)
{
   andar_tras();
}

 else if(x == 3)
{
   curva_longa_direita();
}

 else if(x == 4)
{
   curva_longa_esquerda();
}

 else if(x == 5)
{
   curva_fechada_direita();
}

 else if(x == 6)
{
   curva_fechada_esquerda();
}

}
  wb_robot_cleanup(); // Função que finaliza o robô.
 
return 0;
}