#ifndef GENERIC_CMDS_H__
#define GENERIC_CMDS_H__

#include "cmds.h"


#define GENERIC_NODE_CHANNEL_ID 0x3F

#define MAX_CHANNEL_NUMBER 32


typedef enum
{
	GENERIC_BUS1_VOLTAGE,
	GENERIC_BUS2_VOLTAGE,
	GENERIC_PWR_VOLTAGE,
	GENERIC_PWR_CURRENT,
	GENERIC_REFRESH_DIVIDER,
	GENERIC_REFRESH_RATE
} GENERIC_VARIABLES;

typedef enum
{
	GENERIC_RESET_ALL_SETTINGS,		// NO payload
	GENERIC_STATUS,					// NO payload
	GENERIC_DATA,					// TODO data stuff
	GENERIC_SET_VARIABLE,			// GenericSetMsg_t
	GENERIC_GET_VARIABLE,			// GenericGetMsg_t
	GENERIC_SYNC_CLOCK,				// NO FUCKING IDEA
	GENERIC_NODE_INFO,				// NodeInfoMsg_t
	GENERIC_NODE_STATUS,			// NodeStatusMsg_t
	GENERIC_SPEAKER,				// SpeakerMsg_t
	GENERIC_ENABLE_UART_DEBUGGING,	// NO payload

	GENERIC_TOTAL_CMDS
} GENERIC_CMDs;


typedef enum
{
	ERROR_FLAG_CAN_COMM1,
	ERROR_FLAG_CAN_COMM2,
	ERROR_FLAG_PWR_BUS1,
	ERROR_FLAG_PWR_BUS2,
	ERROR_FLAG_OVERCURRENT_THLD1,
	ERROR_FLAG_RESERVED
} ERROR_FLAG_INDEX;

typedef struct __attribute__((__packed__))
{
	uint32_t firmware_version;
	uint32_t channel_mask;
	uint8_t channel_type[MAX_CHANNEL_NUMBER];
}NodeInfoMsg_t;

typedef struct __attribute__((__packed__))
{
	uint32_t node_error_flags;	
	uint32_t channels_error;	
}NodeStatusMsg_t;

typedef struct __attribute__((__packed__))
{
	uint16_t tone_frequency;	// in Hz
	uint16_t on_time;			// in ms
	uint16_t off_time;			// in ms
	uint8_t count;				// number of beeps
}SpeakerMsg_t;



typedef struct __attribute__((__packed__))
{
	GENERIC_VARIABLES variable_id;
	uint32_t value;
}GenericSetMsg_t;

typedef struct __attribute__((__packed__))
{
	GENERIC_VARIABLES variable_id;
}GenericGetMsg_t;


#endif