#ifndef SERVO_CHANNEL_DEF_H_
#define SERVO_CHANNEL_DEF_H_

#include "cmds.h"

#define SERVO_DATA_N_BYTES 4

typedef enum
{
	SERVO_POSITION,
	SERVO_TARGET_POSITION,
	SERVO_TARGET_PRESSURE,
	SERVO_MAX_SPEED,
	SERVO_MAX_ACCEL,
	SERVO_MAX_TORQUE,
	SERVO_P_PARAM,
	SERVO_I_PARAM,
	SERVO_D_PARAM,
	SERVO_SENSOR_CHANNEL_ID, // TODO remove
	SERVO_POSITION_STARTPOINT,
	SERVO_POSITION_ENDPOINT,
	SERVO_PWM_ENABLED,
	SERVO_SENSOR_REFRESH_DIVIDER,
	SERVO_PRESSURE_CONTROL_ENABLED,
	SERVO_POS_P_PARAM,
	SERVO_POS_I_PARAM,
	SERVO_VEL_P_PARAM,
	SERVO_VEL_I_PARAM,
	SERVO_TORQ_P_PARAM,
	SERVO_TORQ_I_PARAM
} SERVO_VARIABLES;

typedef enum
{
	SERVO_REQ_RESET_SETTINGS = COMMON_REQ_RESET_SETTINGS,	// NO payload
	SERVO_RES_RESET_SETTINGS = COMMON_RES_RESET_SETTINGS,	// NO payload
	SERVO_REQ_STATUS = COMMON_REQ_STATUS,					// NO payload
	SERVO_RES_STATUS = COMMON_RES_STATUS,					// TODO: some status msg
	SERVO_REQ_SET_VARIABLE = COMMON_REQ_SET_VARIABLE,		// SetMsg_t
	SERVO_RES_SET_VARIABLE = COMMON_RES_SET_VARIABLE,		// SetMsg_t
	SERVO_REQ_GET_VARIABLE = COMMON_REQ_GET_VARIABLE,		// GetMsg_t
	SERVO_RES_GET_VARIABLE = COMMON_RES_GET_VARIABLE,		// SetMsg_t
	SERVO_REQ_MOVE = COMMON_TOTAL_CMDS,	                	//ServoMoveMsg_t
	SERVO_REQ_SAVE_SETTINGS,								// NO payload
	SERVO_RES_SAVE_SETTINGS,								// NO payload

	SERVO_TOTAL_CMDS
} SERVO_CMDs;

typedef struct __attribute__((__packed__))
{
	uint32_t position;
	uint32_t interval;	//in ms
} ServoMoveMsg_t;

#endif
