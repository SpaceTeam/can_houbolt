#ifndef ADC16_CHANNEL_DEF_H_
#define ADC16_CHANNEL_DEF_H_

#include "cmds.h"

#define ADC16_DATA_N_BYTES 2

typedef enum
{
	ADC16_,
	ADC16_REFRESH_DIVIDER
} ADC16_VARIABLES;

typedef enum
{
	ADC16_RESET_SETTINGS,		//NO payload
	ADC16_STATUS,				//NO payload
	ADC16_SET_VARIABLE,			//SetMsg_t
	ADC16_GET_VARIABLE,			//GetMsg_t
	ADC16_CALIBRATE,			//NO payload
	ADC16_TOTAL_CMDS
} ADC16_CMDs;

#endif
