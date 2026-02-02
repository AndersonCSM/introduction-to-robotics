#include <stdio.h>
#include <webots/led.h>
#include <webots/robot.h>

#define TIME_STEP 64

int main(int argc, char *argv[])
{

  wb_robot_init();
  WbDeviceTag led[10];

  led[0] = wb_robot_get_device("led0");
  led[1] = wb_robot_get_device("led1");
  led[2] = wb_robot_get_device("led2");
  led[3] = wb_robot_get_device("led3");
  led[4] = wb_robot_get_device("led4");
  led[5] = wb_robot_get_device("led5");
  led[6] = wb_robot_get_device("led6");
  led[7] = wb_robot_get_device("led7");
  led[8] = wb_robot_get_device("led8");
  led[9] = wb_robot_get_device("led9");
  
  // Verificar se os LEDs foram encontrados
  for (int i = 0; i < 10; i++) {
    if (led[i] == 0) {
      printf("Erro: LED%d não encontrado!\n", i);
    } else {
      printf("LED%d encontrado com sucesso.\n", i);
    }
  }
  
  int turn_on = 0;
  
  while (wb_robot_step(TIME_STEP) != -1)
  {
    if (turn_on){
    wb_led_set(led[0], 255);
    wb_led_set(led[1], 255);
    wb_led_set(led[2], 255);
    wb_led_set(led[3], 255);
    wb_led_set(led[4], 255);
    wb_led_set(led[5], 255);
    wb_led_set(led[6], 255);
    wb_led_set(led[7], 255);
    wb_led_set(led[8], 255);
    wb_led_set(led[9], 255);
    } else {
    wb_led_set(led[0], 0);
    wb_led_set(led[1], 0);
    wb_led_set(led[2], 0);
    wb_led_set(led[3], 0);
    wb_led_set(led[4], 0);
    wb_led_set(led[5], 0);
    wb_led_set(led[6], 0);
    wb_led_set(led[7], 0);
    wb_led_set(led[8], 0);
    wb_led_set(led[9], 0);
    }
    
  };

  wb_robot_cleanup();

  return 0;
}