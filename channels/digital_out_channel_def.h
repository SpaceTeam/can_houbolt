#ifndef DIGITAL_OUT_CHANNEL_DEF_H_
#define DIGITAL_OUT_CHANNEL_DEF_H_

#include "cmds.h"

#define DIGITAL_OUT_DATA_N_BYTES 2

typedef enum
{
	DIGITAL_OUT_STATE,
	DIGITAL_OUT_SENSOR_REFRESH_DIVIDER,
} DIGITAL_OUT_VARIABLES;

typedef enum
{
	DIGITAL_OUT_RESET_SETTINGS,		// NO payload
	DIGITAL_OUT_STATUS,				// NO payload
	DIGITAL_OUT_SET_VARIABLE,		// DigitalOutSetMsg_t
	DIGITAL_OUT_GET_VARIABLE,		// DigitalOutGetMsg_t
	DIGITAL_OUT_PWM_ENABLE,			// DigitalOutPwmEnableMsg_t

	DIGITAL_OUT_TOTAL_CMDS
} DIGITAL_OUT_CMDs;



typedef struct __attribute__((__packed__))
{
	DIGITAL_OUT_VARIABLES variable_id;
	uint32_t value;
}DigitalOutSetMsg_t;

typedef struct __attribute__((__packed__))
{
	DIGITAL_OUT_VARIABLES variable_id;
}DigitalOutGetMsg_t;

typedef struct __attribute__((__packed__))
{
	uint8_t enable;
	uint16_t duty_cycle;
}DigitalOutPwmEnableMsg_t;


#endif
