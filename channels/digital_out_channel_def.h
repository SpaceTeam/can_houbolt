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
	DIGITAL_OUT_REQ_SET_VARIABLE,		// SetMsg_t
	DIGITAL_OUT_RES_SET_VARIABLE,		// SetMsg_t
	DIGITAL_OUT_REQ_GET_VARIABLE,		// GetMsg_t
	DIGITAL_OUT_RES_GET_VARIABLE,		// SetMsg_t
	DIGITAL_OUT_PWM_ENABLE,			// DigitalOutPwmEnableMsg_t

	DIGITAL_OUT_TOTAL_CMDS
} DIGITAL_OUT_CMDs;


typedef struct __attribute__((__packed__))
{
	uint8_t enable;
	uint16_t duty_cycle;
} DigitalOutPwmEnableMsg_t;


#endif
