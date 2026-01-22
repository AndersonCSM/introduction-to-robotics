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

  while (wb_robot_step(TIME_STEP) != -1)
  {
    wb_led_set(led[0], 1);
    wb_led_set(led[1], 1);
    wb_led_set(led[2], 1);
    wb_led_set(led[3], 1);
    wb_led_set(led[4], 1);
    wb_led_set(led[5], 1);
    wb_led_set(led[6], 1);
    wb_led_set(led[7], 1);
    wb_led_set(led[8], 1);
    wb_led_set(led[9], 1);
  };

  wb_robot_cleanup();

  return 0;
}