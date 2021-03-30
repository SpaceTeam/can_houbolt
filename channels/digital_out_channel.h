#ifndef DIGITAL_OUT_CHANNEL_H__
#define DIGITAL_OUT_CHANNEL_H__

#include "cmds.h"
#include "gpio.h"
#include "measurement.h"

typedef enum
{
	DIGITAL_OUT_RESET_SETTINGS,
	DIGITAL_OUT_SET_STATE,

	DIGITAL_OUT_TOTAL_CMDS
} DIGITAL_OUT_CMDs;



typedef struct __attribute__((__packed__))
{
	uint8_t state;
	uint8_t mode;
}DigialOut_SetStateMsg_t;


extern const can_function digital_out_array[];

typedef struct
{
	uint8_t channel_index; 		//ToDo: Probably unnecessary
	Measurement * measurement;
	uint_least8_t state;
	uint_least8_t mode;
	//GPIO_Pin_t * pin;
}Digital_out_t;


Result_t DigitalOut_Init(void *channel, GPIO_Pin_t * enable, GPIO_Pin_t * input);
Result_t DigitalOut_GetData(void *channel, uint8_t *array, uint8_t *length);
uint32_t DigitalOut_GetStatus(void *channel);

class Digital_Out_Channel : private Channel {
	private:
		uint8_t id;
	public:
		Digital_Out_Channel(uint8_t id);
		bool ExecCommand(uint8_t channel_id, std::string cmd, ...);
		~Digital_Out_Channel();
};


#endif
