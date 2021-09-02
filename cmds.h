#ifndef CMDS_H__
#define CMDS_H__

#include <stdint.h>

#include "can_cmds.h"


typedef enum
{
	CHANNEL_TYPE_UNKNOWN,
	CHANNEL_TYPE_NODE_GENERIC,
	CHANNEL_TYPE_NODE_SPECIFIC, //?????? Todo: Implement or probably remove
	CHANNEL_TYPE_ADC16,
	CHANNEL_TYPE_ADC16_SINGLE,
	CHANNEL_TYPE_ADC24,
	CHANNEL_TYPE_COMPUTED32,
	CHANNEL_TYPE_DIGITAL_OUT,
	CHANNEL_TYPE_SERVO,
	CHANNEL_TYPE_PNEUMATIC_VALVE,

	CHANNEL_TYPE_LAST

} CHANNEL_TYPE;

typedef enum
{
	CHANNEL_STATUS_NOICE, CHANNEL_STATUS_TYPE_UNKNOWN, CHANNEL_STATUS_SENSOR_NOT_CONNECTED, CHANNEL_STATUS_WRONG_READINGS, CHANNEL_STATUS_ERROR, CHANNEL_STATUS_NO_CHANNEL
} CHANNEL_STATUS;

typedef uint8_t ChannelStatus_t;

typedef struct __attribute__((__packed__))
{
	uint8_t variable_id;
	int32_t value;
}SetMsg_t;

typedef struct __attribute__((__packed__))
{
	uint8_t variable_id;
}GetMsg_t;


#endif
