#ifndef SERVO_CHANNEL_DEF_H_
#define SERVO_CHANNEL_DEF_H_

#include "cmds.h"

#define DATA_SIZE_N_BYTES 4

typedef enum
{
	SERVO_POSITION,
	SERVO_MAX_SPEED,
	SERVO_MAX_TORQUE,
	SERVO_MAX_ACCEL,
	SERVO_SETPOINT,
	SERVO_P_PARAM,
	SERVO_I_PARAM,
	SERVO_D_PARAM,
	SERVO_SENSOR_CHANNEL_ID,
	SERVO_SENSOR_REFRESH_DIVIDER
} SERVO_VARIABLES;

typedef enum
{
	SERVO_RESET_SETTINGS,		//NO payload
	SERVO_STATUS,				//NO payload
	SERVO_SET_VARIABLE,			//SetMsg_t
	SERVO_GET_VARIABLE,			//SetMsg_t
	SERVO_ENABLE_CONTROL_LOOP,	//ServoEnableControlLoopMsg_t
	

	SERVO_TOTAL_CMDS
} SERVO_CMDs;

typedef struct __attribute__((__packed__))
{
	uint8_t enable;
}ServoEnableControlLoopMsg_t;




#endif
