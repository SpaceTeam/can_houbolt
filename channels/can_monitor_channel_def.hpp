#ifndef CAN_MONITOR_CHANNEL_DEF_H_
#define CAN_MONITOR_CHANNEL_DEF_H_

#include <type_traits>

#include "cmds.h"

#define CAN_MONITOR_DATA_N_BYTES 6
#define ECR_SIZE 24
#define PSR_SIZE 23

typedef enum {
	CAN_MONITOR_REFRESH_DIVIDER
} CAN_MONITOR_VARIABLES;

template <typename T, int Offset, uint8_t Width>
struct BitField {
	static_assert(std::is_integral_v<T>, "BitField can only be used with integral types");
	static_assert(Width < 64, "BitField width must be less than or equal to 32");
	static_assert(Width < 64, "BitField width must be less than or equal to 32");
	static_assert(Offset + Width <= 64, "BitField offset and width must fit within 64 bits");

	constexpr T get(const uint64_t raw) const{
		return static_cast<T>((raw >> Offset)
		                      & ((static_cast<uint64_t>(1) << Width) - 1));
	}

	constexpr void set(uint64_t& raw, T value) const {
		const uint64_t mask = ((static_cast<uint64_t>(1) << Width) - 1) << Offset;
		raw = (raw & ~mask) | ((static_cast<uint64_t>(value) << Offset) & mask);
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
		constexpr BitField<uint8_t, 24, 3> LEC;
		constexpr BitField<uint8_t, 27, 2> ACT;
		constexpr BitField<bool, 29, 1> EP;
		constexpr BitField<bool, 30, 1> EW;
		constexpr BitField<bool, 31, 1> BO;
		constexpr BitField<uint8_t, 32, 3> DLEC;
		constexpr BitField<bool, 35, 1> RESI;
		constexpr BitField<bool, 36, 1> RBRS;
		constexpr BitField<bool, 37, 1> REDL;
		constexpr BitField<bool, 38, 1> PXE;
		constexpr BitField<bool, 40, 7> TDCV; // 1 difference here because the 15th bit of the PCR reg is not used
	}
	constexpr BitField<uint32_t,0,ECR_SIZE> ECR;
	constexpr BitField<uint32_t,ECR_SIZE+1,PSR_SIZE> PSR;
}

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
