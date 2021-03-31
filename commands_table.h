#ifndef INC_COMMANDS_TABLE_H__
#define INC_COMMANDS_TABLE_H__

#include <map>
#include <string>

#include "can_houbolt/generic_cmds.h"
#include "can_houbolt/channels/adc16_channel.h"
#include "can_houbolt/channels/adc24_channel.h"
#include "can_houbolt/channels/digital_out_channel.h"
#include "can_houbolt/channels/servo_channel.h"


std::map<GENERIC_CMDs, std::string> generic_cmds_to_string {
    {GENERIC_RESET_ALL_SETTINGS, "ResetAllSettings"},
	{GENERIC_SYNC_CLOCK, "SyncClock"},
	{GENERIC_NODE_INFO, "GetNodeInfo"},
	{GENERIC_NODE_STATUS, "GetNodeStatus"},
	{GENERIC_CHANNEL_STATUS, "GetChannelStatus"},
	{GENERIC_SEND_DATA, "SendData"},
	{GENERIC_SET_SPEAKER, "SetSpeaker"},
	{GENERIC_SET_REFRESHRATE, "SetRefreshRate"},
	{GENERIC_ENABLE_UART_DEBUGGING, "EnableUartDebugging"}
	
};

std::map<ADC16_CMDs, std::string> adc16_cmds_to_string {
    {ADC16_RESET_SETTINGS, "ResetSettings"},
	{ADC16_SAMPLINGRATE, "SetSamplingRate"},
	{ADC16_MODE, "SetMode"},
	{ADC16_SET_OFFSET, "SetOffset"},

	{ADC16_TOTAL_CMDS, "GetTotalCommands"}

};

std::map<ADC24_CMDs, std::string> adc24_cmds_to_string {
    {ADC24_RESET_SETTINGS, "ResetSettings"},

	{ADC24_TOTAL_CMDS, "GetTotalCommands"}

};

std::map<DIGITAL_OUT_CMDs, std::string> digital_out_cmds_to_string {
    {DIGITAL_OUT_RESET_SETTINGS, "ResetSettings"},
	{DIGITAL_OUT_SET_STATE, "SetState"},

	{DIGITAL_OUT_TOTAL_CMDS, "GetTotalCommands"}

};

std::map<SERVO_CMDs, std::string> servo_cmds_to_string {
    {SERVO_RESET_SETTINGS, "ResetAllSettings"},
	{SERVO_SETPOS, "SetPosition"},
	{SERVO_SETSPEED, "SetSpeed"},
	{SERVO_STATUS, "GetStatus"},
	{SERVO_GET_SETPOINT, "GetSetpoint"},
	{SERVO_SET_SENSORCHANNEL, "SetSensorChannel"},
	{SERVO_SET_PID_PARAMETERS, "SetPID"},

	{SERVO_TOTAL_CMDSs, "GetTotalCommands"}
	
};

//These maps are generated at runnning time, to prevent redundant code, in our case
//they are generated inside CANManager.cpp 
std::map<std::string, GENERIC_CMDs> string_to_generic_cmds;
std::map<std::string, ADC16_CMDs, std::string> string_to_adc16_cmds;
std::map<std::string, ADC24_CMDs, std::string> string_to_adc24_cmds;
std::map<std::string, DIGITAL_OUT_CMDs, std::string> string_to_digital_out_cmds;
std::map<std::string, SERVO_CMDs, std::string> string_to_servo_cmds;

#endif //INC_COMMANDS_TABLE_H__