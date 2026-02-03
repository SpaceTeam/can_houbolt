#ifndef FLIGHT_CONTROL_CHANNEL_DEF_H_
#define FLIGHT_CONTROL_CHANNEL_DEF_H_

#include "cmds.h"

#define FLIGHT_DATA_N_BYTES 2

typedef enum
{
	FLIGHT_STATE_REFRESH_DIVIDER,
	FLIGHT_SENSOR_SLOPE,
	FLIGHT_SENSOR_OFFSET
} FLIGHT_VARIABLES;

typedef enum
{
	FLIGHT_REQ_RESET_SETTINGS = COMMON_REQ_RESET_SETTINGS,	// NO payload
	FLIGHT_RES_RESET_SETTINGS = COMMON_RES_RESET_SETTINGS,	// NO payload
	FLIGHT_REQ_STATUS = COMMON_REQ_STATUS,					// NO payload
	FLIGHT_RES_STATUS = COMMON_RES_STATUS,					// TODO: some status msg
	FLIGHT_REQ_SET_VARIABLE = COMMON_REQ_SET_VARIABLE,		// SetMsg_t
	FLIGHT_RES_SET_VARIABLE = COMMON_RES_SET_VARIABLE,		// SetMsg_t
	FLIGHT_REQ_GET_VARIABLE = COMMON_REQ_GET_VARIABLE,		// GetMsg_t
	FLIGHT_RES_GET_VARIABLE = COMMON_RES_GET_VARIABLE,		// SetMsg_t
	FLIGHT_REQ_SET_FLIGHT_STATE = COMMON_TOTAL_CMDS,		// RocketStateMsg_t
	FLIGHT_RES_SET_FLIGHT_STATE,							// RocketStateMsg_t
	FLIGHT_REQ_GET_FLIGHT_STATE,							// NO payload
	FLIGHT_RES_GET_FLIGHT_STATE,							// RocketStateMsg_t
	FLIGHT_REQ_INTERNAL_CONTROL,							// NO payload
	FLIGHT_RES_INTERNAL_CONTROL,							// NO payload
	FLIGHT_REQ_ABORT,										// NO payload
	FLIGHT_RES_ABORT,										// NO payload
	FLIGHT_REQ_END_OF_FLIGHT,								// NO payload
	FLIGHT_RES_END_OF_FLIGHT,								// NO payload
	FLIGHT_REQ_AUTO_CHECK,									// NO payload
	FLIGHT_RES_AUTO_CHECK,									// NO payload
	FLIGHT_TOTAL_CMDS
} FLIGHT_CMDs;

// Keep in sync with ECUI!
typedef enum
{
	INIT,
	UNCHANGED,
	PAD,
	BOOST,
	COAST,
	DESCEND_DROGUE,
	DESCEND_MAIN,
	DESCEND_NO_MAIN,
	LANDED
} FLIGHT_STATE;

typedef enum
{
	FLIGHT_WRITE_SUCCESS, //returns when set state was successful
	FLIGHT_FAILURE_WRITE_PROTECTED, //returns when set state but write protected
	FLIGHT_WRITABLE, //returns on get state when writable
	FLIGHT_WRITE_PROTECTED //returns on get state when write protected
} FLIGHT_STATE_STATUS;

typedef struct __attribute__((__packed__))
{
	uint32_t state; //ROCKET_STATE
} FlightStateReqMsg_t;

typedef struct __attribute__((__packed__))
{
	uint32_t state;
	uint32_t status;
} FlightStateResMsg_t;

#endif
