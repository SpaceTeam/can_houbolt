#ifndef ADC24_CHANNEL_H__
#define ADC24_CHANNEL_H__

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
	ADC24_SET_VARIABLE,			//Adc24SetMsg_t
	ADC24_GET_VARIABLE,			//Adc24GetMsg_t
	

	ADC24_TOTAL_CMDS
} ADC24_CMDs;


typedef struct __attribute__((__packed__))
{
	ADC24_VARIABLES variable_id;
	uint32_t value;
}Adc24SetMsg_t;

typedef struct __attribute__((__packed__))
{
	ADC24_VARIABLES variable_id;
}Adc24GetMsg_t;





#endif
