#ifndef CMDS_H__
#define CMDS_H__

#include <stdint.h>

#define MAX_CHANNELS 32

typedef enum
{
	CHANNEL_TYPE_UNKNOWN,
	CHANNEL_TYPE_NODE_GENERIC,
	CHANNEL_TYPE_NODE_SPECIFIC, //?????? Todo: Implement or probably remove
	CHANNEL_TYPE_ADC16,
	CHANNEL_TYPE_ADC24,
	CHANNEL_TYPE_COMPUTED32,
	CHANNEL_TYPE_DIGITAL_OUT,
	CHANNEL_TYPE_SERVO,

	CHANNEL_TYPE_LAST

} CHANNEL_TYPE;

typedef enum
{
	CHANNEL_STATUS_NOICE, CHANNEL_STATUS_TYPE_UNKNOWN, CHANNEL_STATUS_SENSOR_NOT_CONNECTED, CHANNEL_STATUS_WRONG_READINGS, CHANNEL_STATUS_ERROR, CHANNEL_STATUS_NO_CHANNEL
} CHANNEL_STATUS;

typedef enum
{
	MASTER2NODE_DIRECTION, NODE2MASTER_DIRECTION,
} CAN_MessageDirection_t;

typedef enum
{
	URGENT_PRIORITY, HIGH_PRIORITY, STANDARD_PRIORITY, LOW_PRIORITY
} CAN_MessagePriority_t;

typedef enum
{
	ABORT_SPECIAL_CMD, CLOCK_SYNC_SPECIAL_CMD,							// DIR = MASTER2NODE_DIRECTION
	ERROR_SPECIAL_CMD = CLOCK_SYNC_SPECIAL_CMD, 	// DIR = NODE2MASTER_DIRECTION
	INFO_SPECIAL_CMD,
	STANDARD_SPECIAL_CMD,
} CAN_MessageSpecialCmd_t;

typedef enum
{
	DIRECT_BUFFER, ABSOLUTE_BUFFER, RELATIVE_BUFFER, RESERVED_BUFFER
} CAN_MessageBuffer_t;

typedef union
{
	struct __attribute__((__packed__))
	{
		uint32_t direction :1;		//bit:    0   | CAN_MessageDirection_t
		uint32_t node_id :6;		//bit:  6-1   | Node ID: 0 - 63
		uint32_t buffer :2;			//bit:  8-7   | CAN_MessageBuffer_t
		uint32_t priority :2;		//bit: 10-9   | CAN_MessagePriority_t
	} info;
	uint32_t uint32;
} Can_MessageId_t;

typedef struct __attribute__((__packed__))
{
	uint32_t channel_id :6;					//bit:  5-0   | Channel ID: 0 - 63
	CAN_MessageBuffer_t buffer :2;			//bit:  7-6   | CAN_MessageBuffer_t
} Can_MessageDataInfo_t;

typedef union
{
	struct __attribute__((__packed__))
	{
		Can_MessageDataInfo_t info;
		uint8_t cmd_id;
		uint8_t *data;
	} data;
	uint8_t uint8[CAN_ELMTS_ARRAY_SIZE];
} Can_MessageData_t;

#endif
