#ifndef ADC16_CHANNEL_H__
#define ADC16_CHANNEL_H__

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
	ADC16_SET_VARIABLE,			//Adc16SetMsg_t
	ADC16_GET_VARIABLE,			//Adc16GetMsg_t
	

	ADC16_TOTAL_CMDS
} ADC16_CMDs;


typedef struct __attribute__((__packed__))
{
	ADC16_VARIABLES variable_id;
	uint32_t value;
}Adc16SetMsg_t;

typedef struct __attribute__((__packed__))
{
	ADC16_VARIABLES variable_id;
}Adc16GetMsg_t;



#endif
