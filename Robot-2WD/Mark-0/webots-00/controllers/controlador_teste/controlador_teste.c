#include <webots/robot.h>
#include <stdio.h>

int main(){

wb_robot_init();

printf("Ola mundo \n");

wb_robot_cleanup();

return 0;
}