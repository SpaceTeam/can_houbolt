#ifndef ROCKET_CHANNEL_DEF_H_
#define ROCKET_CHANNEL_DEF_H_

#include "cmds.h"

#define ROCKET_DATA_N_BYTES 2

typedef enum
{
	ROCKET_MINIMUM_CHAMBER_PRESSURE,
	ROCKET_MINIMUM_FUEL_PRESSURE,
	ROCKET_MINIMUM_OX_PRESSURE,
	ROCKET_HOLDDOWN_TIMEOUT,
	ROCKET_STATE_REFRESH_DIVIDER,
	ROCKET_SENSOR_SLOPE,
	ROCKET_SENSOR_OFFSET
} ROCKET_VARIABLES;

typedef enum
{
	ROCKET_REQ_RESET_SETTINGS = COMMON_REQ_RESET_SETTINGS,	// NO payload
	ROCKET_RES_RESET_SETTINGS = COMMON_RES_RESET_SETTINGS,	// NO payload
	ROCKET_REQ_STATUS = COMMON_REQ_STATUS,					// NO payload
	ROCKET_RES_STATUS = COMMON_RES_STATUS,					// TODO: some status msg
	ROCKET_REQ_SET_VARIABLE = COMMON_REQ_SET_VARIABLE,		// SetMsg_t
	ROCKET_RES_SET_VARIABLE = COMMON_RES_SET_VARIABLE,		// SetMsg_t
	ROCKET_REQ_GET_VARIABLE = COMMON_REQ_GET_VARIABLE,		// GetMsg_t
	ROCKET_RES_GET_VARIABLE = COMMON_RES_GET_VARIABLE,		// SetMsg_t
	ROCKET_REQ_SET_ROCKET_STATE = COMMON_TOTAL_CMDS,		// RocketStateMsg_t
	ROCKET_RES_SET_ROCKET_STATE,							// RocketStateMsg_t
	ROCKET_REQ_GET_ROCKET_STATE,							// NO payload
	ROCKET_RES_GET_ROCKET_STATE,							// RocketStateMsg_t
	ROCKET_REQ_INTERNAL_CONTROL,							// NO payload
	ROCKET_RES_INTERNAL_CONTROL,							// NO payload
	ROCKET_REQ_ABORT,										// NO payload
	ROCKET_RES_ABORT,										// NO payload
	ROCKET_REQ_END_OF_FLIGHT,								// NO payload
	ROCKET_RES_END_OF_FLIGHT,								// NO payload
	ROCKET_REQ_AUTO_CHECK,									// NO payload
	ROCKET_RES_AUTO_CHECK,									// NO payload
	ROCKET_TOTAL_CMDS
} ROCKET_CMDs;

typedef enum
{
	PAD_IDLE,
	AUTO_CHECK,
	IGNITION_SEQUENCE,
	HOLD_DOWN,
	POWERED_ASCENT,
	UNPOWERED_ASCENT,
	DEPRESS,
	ABORT,
	PRESSURIZE_TANKS
} ROCKET_STATE;

typedef enum
{
	WRITE_SUCCESS, //returns when set state was successful
	FAILURE_WRITE_PROTECTED, //returns when set state but write protected
	WRITABLE, //returns on get state when writable
	WRITE_PROTECTED //returns on get state when write protected
} ROCKET_STATE_STATUS;

typedef struct __attribute__((__packed__))
{
	uint32_t state; //ROCKET_STATE
} RocketStateReqMsg_t;

typedef struct __attribute__((__packed__))
{
	uint32_t state; //ROCKET_STATE
	uint32_t status;	//ROCKET_STATE_STATUS
} RocketStateResMsg_t;

#endif
