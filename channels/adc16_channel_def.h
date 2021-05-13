#ifndef ADC16_CHANNEL_DEF_H_
#define ADC16_CHANNEL_DEF_H_

#include "cmds.h"

#define ADC16_DATA_N_BYTES 2

typedef enum
{
	ADC16_REFRESH_DIVIDER
} ADC16_VARIABLES;

typedef enum
{
	ADC16_REQ_RESET_SETTINGS,		// NO payload
	ADC16_RES_RESET_SETTINGS,		// NO payload
	ADC16_REQ_STATUS,				// NO payload
	ADC16_RES_STATUS,				// TODO: some status msg
	ADC16_REQ_SET_VARIABLE,			// SetMsg_t
	ADC16_RES_SET_VARIABLE,			// SetMsg_t
	ADC16_REQ_GET_VARIABLE,			// GetMsg_t
	ADC16_RES_GET_VARIABLE,			// SetMsg_t
	ADC16_REQ_CALIBRATE,			// NO payload
	ADC16_RES_CALIBRATE,            // NO payload

	ADC16_TOTAL_CMDS
} ADC16_CMDs;

#endif
