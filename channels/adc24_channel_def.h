#ifndef ADC24_CHANNEL_DEF_H_
#define ADC24_CHANNEL_DEF_H_

#include "cmds.h"

#define ADC24_DATA_N_BYTES 3

typedef enum
{
	ADC24_,
	ADC24_REFRESH_DIVIDER
} ADC24_VARIABLES;

typedef enum
{
	ADC24_RESET_SETTINGS,		//NO payload
	ADC24_STATUS,				//NO payload
	ADC24_SET_VARIABLE,			//SetMsg_t
	ADC24_GET_VARIABLE,			//GetMsg_t
	ADC24_CALIBRATE,			//NO payload

	ADC24_TOTAL_CMDS
} ADC24_CMDs;






#endif