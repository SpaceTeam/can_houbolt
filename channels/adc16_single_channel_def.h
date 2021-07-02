#ifndef ADC16_SINGLE_CHANNEL_DEF_H_
#define ADC16_SINGLE_CHANNEL_DEF_H_

#include "cmds.h"

#define ADC16_SINGLE_DATA_N_BYTES 2

typedef enum
{
	ADC16_SINGLE_MEASUREMENT,
	ADC16_SINGLE_DATA,
	ADC16_SINGLE_REFRESH_DIVIDER
} ADC16_SINGLE_VARIABLES;

typedef enum
{
	ADC16_SINGLE_REQ_RESET_SETTINGS,		// NO payload
	ADC16_SINGLE_RES_RESET_SETTINGS,		// NO payload
	ADC16_SINGLE_REQ_STATUS,				// NO payload
	ADC16_SINGLE_RES_STATUS,				// TODO: some status msg
	ADC16_SINGLE_REQ_SET_VARIABLE,			// SetMsg_t
	ADC16_SINGLE_RES_SET_VARIABLE,			// SetMsg_t
	ADC16_SINGLE_REQ_GET_VARIABLE,			// GetMsg_t
	ADC16_SINGLE_RES_GET_VARIABLE,			// SetMsg_t
	ADC16_SINGLE_REQ_CALIBRATE,			// NO payload
	ADC16_SINGLE_RES_CALIBRATE,            // NO payload

	ADC16_SINGLE_TOTAL_CMDS
} ADC16_SINGLE_CMDs;

#endif
