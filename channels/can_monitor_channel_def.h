#ifndef CAN_MONITOR_CHANNEL_DEF_H_
#define CAN_MONITOR_CHANNEL_DEF_H_

#include "cmds.h"

#define CAN_MONITOR_DATA_N_BYTES 6
#define ECR_SIZE 24
#define PSR_SIZE 23

typedef enum
{
	CAN_MONITOR_REFRESH_DIVIDER
} CAN_MONITOR_VARIABLES;


typedef union {
	struct {
		// ---------- Word 0: FDCAN_ECR (0x0040) ----------
		uint32_t TEC   : 8;  // Bits  0–7   - Transmit Error Counter
		uint32_t REC   : 7;  // Bits  8–14  - Receive Error Counter
		uint32_t RP    : 1;  // Bit   15    - Receive Error Passive Flag
		uint32_t CEL   : 8;  // Bits 16–23  - CAN Error Logging
		// ---------- Word 1: FDCAN_PSR (0x0040) ----------
		uint32_t LEC   : 3;  // Bits  0–2   - Last Error Code
		uint32_t ACT   : 2;  // Bits  3–4   - Activity Status
		uint32_t EP    : 1;  // Bit   5     - Error Passive
		uint32_t EW    : 1;  // Bit   6     - Warning Status
		uint32_t BO    : 1;  // Bit   7     - Bus-Off Status
		uint32_t DLEC  : 3;  // Bits  8–10  - Data Phase Last Error Code
		uint32_t RESI  : 1;  // Bit  11     - ESI Flag of Last RX Message
		uint32_t RBRS  : 1;  // Bit  12     - Receive Bus Rate Switching
		uint32_t REDL  : 1;  // Bit  13     - Received FDCAN Message
        uint32_t PXE   : 1;  // Bit  14     - Protocol Exception Event
        uint32_t RES   : 1;  // Bit  14     - Reserved
		uint32_t TDCV  : 7;  // Bits 16–22  - Transmit Delay Compensation Value
	} bits;

	struct {
		uint32_t ecr :ECR_SIZE;  // Raw access to FDCAN_ECR register (offset 0x0040)
		uint32_t psr :PSR_SIZE;  // Raw access to FDCAN_PSR register (offset 0x0044)
	} raw;
} FDCAN_StatusRegisters_t;

typedef enum
{
	CAN_MONITOR_REQ_STATUS = COMMON_REQ_STATUS,					// NO payload
	CAN_MONITOR_RES_STATUS = COMMON_RES_STATUS,					// TODO: some status msg
	CAN_MONITOR_REQ_SET_VARIABLE = COMMON_REQ_SET_VARIABLE,		// SetMsg_t
	CAN_MONITOR_RES_SET_VARIABLE = COMMON_RES_SET_VARIABLE,		// SetMsg_t
	CAN_MONITOR_REQ_GET_VARIABLE = COMMON_REQ_GET_VARIABLE,		// GetMsg_t
	CAN_MONITOR_RES_GET_VARIABLE = COMMON_RES_GET_VARIABLE,		// SetMsg_t

	CAN_MONITOR_TOTAL_CMDS
} CAN_MONITOR_CMDs;

#endif
