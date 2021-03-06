#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include "common.h"

#define EAST 0x1
#define N_EAST 0x2
#define NORTH 0x4
#define WEST 0x8
#define S_WEST 0x10
#define SOUTH 0x20

#define CORE(n) (1<< (n+6))


#define MGMT_BIT 0x400
#define EVDS1_XY 0x43
#define EVDS1_ENABLE 0x45
#define MOTORS_KEY ((252 << 24) | (255 << 16))

#define MOTOR_MIN 1500
#define MOTOR_MAX 2500
#define MOTOR_DELTA ((MOTOR_MAX - MOTOR_MIN) / 2)

#define MOTOR_X_CENTER	2150
#define MOTOR_Y_CENTER	2000



void sendNormMotorCommand(float x, float y);
void sendMotorCommand(uint motor_x, uint motor_y);

#endif
