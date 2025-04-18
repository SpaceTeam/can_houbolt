#ifndef CAN_MONITOR_CHANNEL_DEF_H_
#define CAN_MONITOR_CHANNEL_DEF_H_

#include "cmds.h"

#define CAN_MONITOR_DATA_N_BYTES 6
#define ECR_SIZE 24
#define PSR_SIZE 23

typedef enum {
	CAN_MONITOR_REFRESH_DIVIDER
} CAN_MONITOR_VARIABLES;

#include <cstdint>
#include <cstring>

template <typename T, int Offset, int Width>
struct BitField {
	constexpr T get(const unsigned long long raw) {
		return static_cast<T>((raw >> Offset) & ((1u << Width) - 1));
	}

	constexpr void set(unsigned long long& raw, T value) {
		const uint32_t mask = ((1u << Width) - 1) << Offset;
		raw = (raw & ~mask) | ((static_cast<uint32_t>(value) << Offset) & mask);
	}
};
namespace FDCAN_StatusRegisters {
    namespace ECR_Fields {
        constexpr BitField<uint8_t, 0, 8> TEC;
        constexpr BitField<uint8_t, 8, 7> REC;
        constexpr BitField<bool, 15, 1> RP;
        constexpr BitField<uint8_t, 16, 8> CEL;
    }
    namespace PSR_Fields {
        constexpr BitField<uint8_t, 0, 3> LEC;
        constexpr BitField<uint8_t, 3, 2> ACT;
        constexpr BitField<bool, 5, 1> EP;
        constexpr BitField<bool, 6, 1> EW;
        constexpr BitField<bool, 7, 1> BO;
        constexpr BitField<uint8_t, 8, 3> DLEC;
        constexpr BitField<bool, 11, 1> RESI;
        constexpr BitField<bool, 12, 1> RBRS;
        constexpr BitField<bool, 13, 1> REDL;
        constexpr BitField<bool, 14, 1> PXE;
    }
	constexpr BitField<uint32_t,0,24> ECR;
	constexpr BitField<uint32_t,25,32> PSR;
} // namespace FDCAN

typedef union {
	struct {
		// ---------- Word 0: FDCAN_ECR (0x0040) ----------
		uint32_t TEC:  8;  // Bits  0–7   - Transmit Error Counter
		uint32_t REC:  7;  // Bits  8–14  - Receive Error Counter
		uint32_t RP:   1;   // Bit   15    - Receijkkkkkkkkkkkkkkkkkkkkhjjjjjjjjjjjjjjjgh  ve Error Passive Flag
		uint32_t CEL:  8;  // Bits 16–23  - CAN Error Logging
		// ---------- Word 1: FDCAN_PSR (0x0040) ----------
		uint32_t LEC:  3;  // Bits  0–2   - Last Error Code
		uint32_t ACT:  2;  // Bits  3–4   - Activity Status
		uint32_t EP:   1;   // Bit   5     - Error Passive
		uint32_t EW:   1;   // Bit   6     - Warning Status
		uint32_t BO:   1;   // Bit   7     - Bus-Off Status
		uint32_t DLEC: 3; // Bits  8–10  - Data Phase Last Error Code
		uint32_t RESI: 1; // Bit  11     - ESI Flag of Last RX Message
		uint32_t RBRS: 1; // Bit  12     - Receive Bus Rate Switching
		uint32_t REDL: 1; // Bit  13     - Received FDCAN Message
		uint32_t PXE:  1;  // Bit  14     - Protocol Exception Event
		uint32_t RES:  1;  // Bit  15     - Reserved
		uint32_t TDCV: 7; // Bits 16–22  - Transmit Delay Compensation Value
	} bits;

	struct {
		uint32_t ecr: ECR_SIZE; // Raw access to FDCAN_ECR register (offset 0x0040)
		uint32_t psr: PSR_SIZE; // Raw access to FDCAN_PSR register (offset 0x0044)
	} raw;
} FDCAN_StatusRegisters_t;

typedef enum {
	CAN_MONITOR_REQ_STATUS = COMMON_REQ_STATUS, // NO payload
	CAN_MONITOR_RES_STATUS = COMMON_RES_STATUS, // TODO: some status msg
	CAN_MONITOR_REQ_SET_VARIABLE = COMMON_REQ_SET_VARIABLE, // SetMsg_t
	CAN_MONITOR_RES_SET_VARIABLE = COMMON_RES_SET_VARIABLE, // SetMsg_t
	CAN_MONITOR_REQ_GET_VARIABLE = COMMON_REQ_GET_VARIABLE, // GetMsg_t
	CAN_MONITOR_RES_GET_VARIABLE = COMMON_RES_GET_VARIABLE, // SetMsg_t

	CAN_MONITOR_TOTAL_CMDS
} CAN_MONITOR_CMDs;

#endif
