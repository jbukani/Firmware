/****************************************************************************
 *
 *   Copyright (c) 2019 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file ST_ISM330DLC_registers.hpp
 *
 * ST ISM330DLC registers.
 *
 */

#pragma once

#include <cstdint>

// TODO: move to a central header
static constexpr uint8_t Bit0 = (1 << 0);
static constexpr uint8_t Bit1 = (1 << 1);
static constexpr uint8_t Bit2 = (1 << 2);
static constexpr uint8_t Bit3 = (1 << 3);
static constexpr uint8_t Bit4 = (1 << 4);
static constexpr uint8_t Bit5 = (1 << 5);
static constexpr uint8_t Bit6 = (1 << 6);
static constexpr uint8_t Bit7 = (1 << 7);

namespace ST_ISM330DLC
{
static constexpr uint32_t SPI_SPEED = 10 * 1000 * 1000; // 10MHz SPI serial interface
static constexpr uint8_t DIR_READ = 0x80;

static constexpr uint8_t WHOAMI = 0x6A; // Who I am ID

static constexpr uint32_t LA_ODR = 6664; // Linear acceleration output data rate
static constexpr uint32_t G_ODR  = 6664; // Angular rate output data rate

//static constexpr float TEMPERATURE_SENSITIVITY = 326.8f; // LSB/C
//static constexpr float ROOM_TEMPERATURE_OFFSET = 25.f; // C

enum class Register : uint8_t {
	FIFO_CTRL1	= 0x06,	// FIFO threshold level setting.
	FIFO_CTRL2      = 0x07,
	FIFO_CTRL3	= 0x08,	// FIFO control register (r/w).

	FIFO_CTRL5	= 0x0A,

	INT1_CTRL	= 0x0D,

	WHO_AM_I	= 0x0F,

	CTRL1_XL	= 0x10,	// Linear acceleration sensor control register 1 (r/w).
	CTRL2_G		= 0x11,	// Angular rate sensor control register 2 (r/w).
	CTRL3_C		= 0x12,	// Control register 3 (r/w).
	CTRL4_C		= 0x13,
	CTRL5_C		= 0x14, // Control register 5 (r/w).

	CTRL8_XL        = 0x17, // Linear acceleration sensor control register 8 (r/w).

	OUT_TEMP_L	= 0x20,
	OUT_TEMP_H	= 0x21,

	FIFO_STATUS1	= 0x3A,	// FIFO status control register (r)
	FIFO_STATUS2	= 0x3B,	// FIFO status control register (r)
	FIFO_STATUS3	= 0x3C,	// FIFO status control register (r)
	FIFO_STATUS4	= 0x3D,	// FIFO status control register (r)

	FIFO_DATA_OUT_L	= 0x3E,	// FIFO data output (first byte)
	FIFO_DATA_OUT_H	= 0x3F,	// FIFO data output (second byte)
};


// FIFO_CTRL3
enum FIFO_CTRL3_BIT : uint8_t {
	DEC_FIFO_GYRO = Bit3, // Gyro no decimation
	DEC_FIFO_XL   = Bit0, // Accel no decimation
};

// FIFO_CTRL5
enum FIFO_CTRL5_BIT : uint8_t {
	ODR_FIFO_6_66_KHZ = Bit6 | Bit4, // FIFO ODR is set to 6.66 kHz
	FIFO_MODE         = Bit0,        // FIFO mode. Stops collecting data when FIFO is full.
};

// INT1_CTRL
enum INT1_CTRL_BIT : uint8_t {
	INT1_FULL_FLAG = Bit5,
	INT1_FIFO_OVR  = Bit4,
	INT1_FTH       = Bit3,
};

// CTRL1_XL
enum CTRL1_XL_BIT : uint8_t {
	ODR_XL_6_66KHZ = Bit7 | Bit5, // 6.66 kHz (high performance)

	FS_XL_16       = Bit2,        // FS_XL 01: ±16 g
};

// CTRL2_G
enum CTRL2_G_BIT : uint8_t {
	ODR_G_6_66KHZ = Bit7 | Bit5, // 6.66 kHz (high performance)
	FS_G_2000     = Bit3 | Bit2, // ±2000 dps
};

// CTRL3_C
enum CTRL3_C_BIT : uint8_t {
	BDU       = Bit6,
	H_LACTIVE = Bit5,
	IF_INC    = Bit2,
	SW_RESET  = Bit0
};

// CTRL4_C
enum CTRL4_C_BIT : uint8_t {
	I2C_disable = Bit2,
	LPF1_SEL_G  = Bit1, // Enable gyroscope digital LPF1
};

// CTRL5_C
enum CTRL5_C_BIT : uint8_t {
	ROUNDING_GYRO_ACCEL = Bit1 | Bit0, // ROUNDING[2:0] - 011 Gyroscope + accelerometer
};

// CTRL8_XL
enum CTRL8_XL_BIT : uint8_t {
	LPF2_XL_EN = Bit7, // Accelerometer low-pass filter LPF2 selection
};

// FIFO_STATUS2
enum FIFO_STATUS2_BIT : uint8_t {
	WaterM     = Bit7, // 1: FIFO filling is equal to or higher than the watermark level
	OVER_RUN   = Bit6, // 1: FIFO is completely filled

	FIFO_EMPTY = Bit4,
};


namespace FIFO
{
static constexpr size_t SIZE = 4096;

// Saving data in the FIFO buffer is organized in four FIFO data sets consisting of 6 bytes each
// each FIFO sample is composed of 16 bits
struct DATA {
	uint8_t OUTX_L_G;
	uint8_t OUTX_H_G;
	uint8_t OUTY_L_G;
	uint8_t OUTY_H_G;
	uint8_t OUTZ_L_G;
	uint8_t OUTZ_H_G;
	uint8_t OUTX_L_XL;
	uint8_t OUTX_H_XL;
	uint8_t OUTY_L_XL;
	uint8_t OUTY_H_XL;
	uint8_t OUTZ_L_XL;
	uint8_t OUTZ_H_XL;
};
}

} // namespace ST_ISM330DLC
