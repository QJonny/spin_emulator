#include "communication.h"






void sendMotorCommand(uint motor_x, uint motor_y) {
	spin_devin_send_motor(motor_y | (motor_x << 16 ));
}


void sendNormMotorCommand(float x, float y) {
	sendMotorCommand((int)(x*MOTOR_DELTA) + MOTOR_X_CENTER, (int)(y*MOTOR_DELTA) + MOTOR_Y_CENTER);
}






