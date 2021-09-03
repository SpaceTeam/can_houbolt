#ifndef PNEUMATIC_VALVE_CHANNEL_DEF_H_
#define PNEUMATIC_VALVE_CHANNEL_DEF_H_

#include "cmds.h"

#define PNEUMATIC_VALVE_DATA_N_BYTES 2

typedef enum
{
	PNEUMATIC_VALVE_POSITION,
	PNEUMATIC_VALVE_TARGET_POSITION,
	PNEUMATIC_VALVE_P_PARAM,
	PNEUMATIC_VALVE_I_PARAM,
	PNEUMATIC_VALVE_D_PARAM,
	PNEUMATIC_VALVE_ON_CHANNEL_ID,
	PNEUMATIC_VALVE_OFF_CHANNEL_ID,
	PNEUMATIC_VALVE_POS_CHANNEL_ID,
	PNEUMATIC_VALVE_POS_REFRESH_DIVIDER
} PNEUMATIC_VALVE_VARIABLES;

typedef enum
{
	PNEUMATIC_VALVE_REQ_RESET_SETTINGS,		//NO payload
	PNEUMATIC_VALVE_RES_RESET_SETTINGS,		//NO payload
	PNEUMATIC_VALVE_REQ_STATUS,				//NO payload
	PNEUMATIC_VALVE_RES_STATUS,				// TODO: some status msg
	PNEUMATIC_VALVE_REQ_SET_VARIABLE,			//SetMsg_t
	PNEUMATIC_VALVE_RES_SET_VARIABLE,			//SetMsg_t
	PNEUMATIC_VALVE_REQ_GET_VARIABLE,			//GetMsg_t
	PNEUMATIC_VALVE_RES_GET_VARIABLE,			//SetMsg_t
	PNEUMATIC_VALVE_REQ_MOVE,	                //PneumaticValveMoveMsg_t

	PNEUMATIC_VALVE_TOTAL_CMDS
} PNEUMATIC_VALVE_CMDs;

typedef struct __attribute__((__packed__))
{
	uint32_t position;
	uint32_t interval;	//in ms
} PneumaticValveMoveMsg_t;

#endif
