#ifndef ADC24_CHANNEL_H__
#define ADC24_CHANNEL_H__

#include "channel.h"
#include "cmds.h"

typedef enum
{
	ADC24_RESET_SETTINGS,



	ADC24_TOTAL_CMDS
} ADC24_CMDs;

extern const can_function adc24_array[];


typedef struct
{
	uint8_t channel_index; //ToDo: Probably unnecessary
	int_least32_t offset;
	int_least32_t thresholds[2];

	Measurement * measurement;

}Adc24_t;

Result_t ADC24_Init( void );
Result_t ADC24_GetData(void *channel, uint8_t *array, uint8_t *length);
uint32_t ADC24_GetStatus(void *channel);

class Adc24_Channel : private Channel {
	public:
		Adc24_Channel(uint8_t id);
		bool ExecCommand(uint8_t channel_id, std::string cmd, ...);
		~Adc24_Channel();
};











#endif
