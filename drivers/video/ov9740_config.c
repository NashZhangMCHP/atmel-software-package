/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2015, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/**
 * \file
 */

/*------------------------------------------------------------------------------
 *         Headers
 *------------------------------------------------------------------------------*/

#include "chip.h"
#include "video/image_sensor_inf.h"

/*------------------------------------------------------------------------------
 *         Definitions
 *------------------------------------------------------------------------------*/

#define OV9740_SLAVE_ADDRESS   0x10
#define OV9740_PIDH_ADDRESS    0x300A
#define OV9740_PIDL_ADDRESS    0x300B
#define OV9740_PIDH            0x97
#define OV9740_PIDL            0x40
#define OV9740_PID_VER_MASK    0xFFF0

/*------------------------------------------------------------------------------
 *         Local Variables
 *------------------------------------------------------------------------------*/

static const sensor_reg_t ov9740_yuv_vga[] = {
	/* VGA 640x360 bin YUV DVP 60FPS (Full speed) */
	{0x0103, 0x01},
	{0x3026, 0x00},
	{0x3027, 0x00},
	{0x3002, 0xe8},
	{0x3004, 0x03},
	{0x3005, 0xff},
	{0x3703, 0x42},
	{0x3704, 0x10},
	{0x3705, 0x45},
	{0x3603, 0xaa},
	{0x3632, 0x27},
	{0x3620, 0x66},
	{0x3621, 0xc0},
	{0x0202, 0x03},
	{0x0203, 0x43},
	{0x3833, 0x04},
	{0x3835, 0x02},
	{0x4702, 0x04},
	{0x4704, 0x00},
	{0x4706, 0x08},
	{0x3819, 0x6e},
	{0x3817, 0x94},
	{0x3a18, 0x00},
	{0x3a19, 0x7f},
	{0x5003, 0xa7},
	{0x3631, 0x5e},
	{0x3633, 0x50},
	{0x3630, 0xd2},
	{0x3604, 0x0c},
	{0x3601, 0x40},
	{0x3602, 0x16},
	{0x3610, 0xa1},
	{0x3612, 0x24},
	{0x034a, 0x02},
	{0x034b, 0xd3},
	{0x034c, 0x02},
	{0x034d, 0x80},
	{0x034e, 0x01},
	{0x034f, 0x68},
	{0x0202, 0x01},
	{0x0203, 0x9e},
	{0x381a, 0x44},
	{0x3707, 0x14},
	{0x3622, 0x9f},
	{0x5841, 0x04},
	{0x4002, 0x45},
	{0x5000, 0x01},
	{0x5001, 0x00},
	{0x3406, 0x00},
	{0x5000, 0xff},
	{0x5001, 0xef},
	{0x5003, 0xff},
	{0x4005, 0x18},
	{0x3503, 0x10},
	{0x3a11, 0xa0},
	{0x3a1b, 0x50},
	{0x3a0f, 0x50},
	{0x3a10, 0x4c},
	{0x3a1e, 0x4c},
	{0x3a1f, 0x26},
	{0x3104, 0x20},
	{0x0305, 0x03},
	{0x0307, 0x5f},
	{0x0303, 0x01},
	{0x0301, 0x0a},
	{0x3010, 0x01},
	{0x300c, 0x02},
	{0x0340, 0x02},
	{0x0341, 0x08},
	{0x0342, 0x04},
	{0x0343, 0xc0},
	{0x0101, 0x01},
	{0x3a08, 0x01},
	{0x3a09, 0x38},
	{0x3a0e, 0x01},
	{0x3a14, 0x09},
	{0x3a15, 0xc0},
	{0x3a0a, 0x01},
	{0x3a0b, 0x02},
	{0x3a0d, 0x02},
	{0x3a02, 0x10},
	{0x3a03, 0x30},
	{0x3c0a, 0x9c},
	{0x3c0b, 0x3f},
	{0x529a, 0x1},
	{0x529b, 0x2},
	{0x529c, 0x3},
	{0x529d, 0x5},
	{0x529e, 0x5},
	{0x529f, 0x28},
	{0x52a0, 0x32},
	{0x52a2, 0x0},
	{0x52a3, 0x2},
	{0x52a4, 0x0},
	{0x52a5, 0x4},
	{0x52a6, 0x0},
	{0x52a7, 0x8},
	{0x52a8, 0x0},
	{0x52a9, 0x10},
	{0x52aa, 0x0},
	{0x52ab, 0x38},
	{0x52ac, 0x0},
	{0x52ad, 0x3c},
	{0x52ae, 0x0},
	{0x52af, 0x4c},
	{0x5842, 0x02},
	{0x5843, 0x5e},
	{0x5844, 0x04},
	{0x5845, 0x32},
	{0x5846, 0x03},
	{0x5847, 0x29},
	{0x5848, 0x02},
	{0x5849, 0xcc},
	{0x5800, 0x22},
	{0x5801, 0x1e},
	{0x5802, 0x1a},
	{0x5803, 0x1a},
	{0x5804, 0x1f},
	{0x5805, 0x26},
	{0x5806, 0xe},
	{0x5807, 0x9},
	{0x5808, 0x7},
	{0x5809, 0x8},
	{0x580a, 0xb},
	{0x580b, 0x11},
	{0x580c, 0x5},
	{0x580d, 0x2},
	{0x580e, 0x0},
	{0x580f, 0x0},
	{0x5810, 0x3},
	{0x5811, 0x7},
	{0x5812, 0x4},
	{0x5813, 0x1},
	{0x5814, 0x0},
	{0x5815, 0x0},
	{0x5816, 0x3},
	{0x5817, 0x7},
	{0x5818, 0xc},
	{0x5819, 0x8},
	{0x581a, 0x6},
	{0x581b, 0x6},
	{0x581c, 0x9},
	{0x581d, 0x10},
	{0x581e, 0x20},
	{0x581f, 0x1b},
	{0x5820, 0x17},
	{0x5821, 0x18},
	{0x5822, 0x1d},
	{0x5823, 0x23},
	{0x5824, 0x5b},
	{0x5825, 0x6e},
	{0x5826, 0x6e},
	{0x5827, 0x7e},
	{0x5828, 0xab},
	{0x5829, 0x5e},
	{0x582a, 0x8a},
	{0x582b, 0x8a},
	{0x582c, 0x8a},
	{0x582d, 0x9d},
	{0x582e, 0x5b},
	{0x582f, 0x88},
	{0x5830, 0x88},
	{0x5831, 0x98},
	{0x5832, 0x9a},
	{0x5833, 0x4e},
	{0x5834, 0x8a},
	{0x5835, 0x79},
	{0x5836, 0x7a},
	{0x5837, 0xad},
	{0x5838, 0x9b},
	{0x5839, 0x9d},
	{0x583a, 0xad},
	{0x583b, 0x8e},
	{0x583c, 0x5c},
	{0x583e, 0x08},
	{0x583f, 0x04},
	{0x5840, 0x10},
	{0x5480, 0x07},
	{0x5481, 0x16},
	{0x5482, 0x2c},
	{0x5483, 0x4d},
	{0x5484, 0x59},
	{0x5485, 0x64},
	{0x5486, 0x6e},
	{0x5487, 0x76},
	{0x5488, 0x7f},
	{0x5489, 0x86},
	{0x548a, 0x94},
	{0x548b, 0xa3},
	{0x548c, 0xba},
	{0x548d, 0xd2},
	{0x548e, 0xe9},
	{0x548f, 0x1e},
	{0x5490, 0x0f},
	{0x5491, 0xff},
	{0x5492, 0x0e},
	{0x5493, 0x34},
	{0x5494, 0x07},
	{0x5495, 0x1a},
	{0x5496, 0x04},
	{0x5497, 0x0e},
	{0x5498, 0x03},
	{0x5499, 0x82},
	{0x549a, 0x03},
	{0x549b, 0x20},
	{0x549c, 0x02},
	{0x549d, 0xd7},
	{0x549e, 0x02},
	{0x549f, 0xa5},
	{0x54a0, 0x02},
	{0x54a1, 0x75},
	{0x54a2, 0x02},
	{0x54a3, 0x55},
	{0x54a4, 0x02},
	{0x54a5, 0x1c},
	{0x54a6, 0x01},
	{0x54a7, 0xea},
	{0x54a8, 0x01},
	{0x54a9, 0xae},
	{0x54aa, 0x01},
	{0x54ab, 0x7c},
	{0x54ac, 0x01},
	{0x54ad, 0x57},
	{0x5180, 0xf0},
	{0x5181, 0x00},
	{0x5182, 0x41},
	{0x5183, 0x42},
	{0x5184, 0x8f},
	{0x5185, 0x63},
	{0x5186, 0xce},
	{0x5187, 0xa8},
	{0x5188, 0x17},
	{0x5189, 0x1f},
	{0x518a, 0x27},
	{0x518b, 0x41},
	{0x518c, 0x34},
	{0x518d, 0xf0},
	{0x518e, 0x10},
	{0x518f, 0xff},
	{0x5190, 0x00},
	{0x5191, 0xff},
	{0x5192, 0x00},
	{0x5193, 0xff},
	{0x5194, 0x00},
	{0x5380, 0x1},
	{0x5381, 0x0},
	{0x5382, 0x0},
	{0x5383, 0x17},
	{0x5384, 0x0},
	{0x5385, 0x1},
	{0x5386, 0x0},
	{0x5387, 0x0},
	{0x5388, 0x0},
	{0x5389, 0xad},
	{0x538a, 0x0},
	{0x538b, 0x11},
	{0x538c, 0x0},
	{0x538d, 0x0},
	{0x538e, 0x0},
	{0x538f, 0x7},
	{0x5390, 0x0},
	{0x5391, 0x80},
	{0x5392, 0x0},
	{0x5393, 0xa0},
	{0x5394, 0x18},
	{0x3c0a, 0x9c},
	{0x3c0b, 0x3f},
	{0x5501, 0x14},
	{0x5502, 0x00},
	{0x5503, 0x40},
	{0x5504, 0x00},
	{0x5505, 0x80},
	{0x0100, 0x01},
	{0xFF, 0xFF}
};

static const sensor_reg_t ov9740_yuv_wxga[] = {
	/* WXGA 1280x720 YUV DVP 15FPS for card reader */
	{0x0103, 0x01},
	{0x3026, 0x00},
	{0x3027, 0x00},
	{0x3002, 0xe8},
	{0x3004, 0x03},
	{0x3005, 0xff},
	{0x3406, 0x00},
	{0x3603, 0xaa},
	{0x3632, 0x27},
	{0x3620, 0x66},
	{0x3621, 0xc0},
	{0x3631, 0x5e},
	{0x3633, 0x50},
	{0x3630, 0xd2},
	{0x3604, 0x0c},
	{0x3601, 0x40},
	{0x3602, 0x16},
	{0x3610, 0xa1},
	{0x3612, 0x24},
	{0x3622, 0x9f},
	{0x3703, 0x42},
	{0x3704, 0x10},
	{0x3705, 0x45},
	{0x3707, 0x14},
	{0x3833, 0x04},
	{0x3835, 0x03},
	{0x3819, 0x6e},
	{0x3817, 0x94},
	{0x3503, 0x10},
	{0x3a18, 0x00},
	{0x3a19, 0x7f},
	{0x3a11, 0xa0},
	{0x3a1a, 0x05},
	{0x3a1b, 0x50},
	{0x3a0f, 0x50},
	{0x3a10, 0x4c},
	{0x3a1e, 0x4c},
	{0x3a1f, 0x26},
	{0x4002, 0x45},
	{0x4005, 0x18},
	{0x4702, 0x04},
	{0x4704, 0x00},
	{0x4706, 0x08},
	{0x5000, 0xff},
	{0x5001, 0xef},
	{0x5003, 0xff},

	{0x3104, 0x20},
	{0x0305, 0x03},
	{0x0307, 0x4c},
	{0x0303, 0x01},
	{0x0301, 0x08},
	{0x3010, 0x01},
	{0x300c, 0x03},

	{0x0340, 0x03},
	{0x0341, 0x07},
	{0x0342, 0x06},
	{0x0343, 0x62},
	{0x034b, 0xd1},
	{0x034c, 0x05},
	{0x034d, 0x00},
	{0x034e, 0x02},
	{0x034f, 0xd0},
	{0x0101, 0x01},
	{0x3a08, 0x00},
	{0x3a09, 0xe8},
	{0x3a0e, 0x03},
	{0x3a14, 0x15},
	{0x3a15, 0xc6},
	{0x3a0a, 0x00},
	{0x3a0b, 0xc0},
	{0x3a0d, 0x04},
	{0x3a02, 0x18},
	{0x3a03, 0x20},
	{0x3c0a, 0x9c},
	{0x3c0b, 0x3f},
	{0x529a, 0x1},
	{0x529b, 0x2},
	{0x529c, 0x3},
	{0x529d, 0x5},
	{0x529e, 0x5},
	{0x529f, 0x28},
	{0x52a0, 0x32},
	{0x52a2, 0x0},
	{0x52a3, 0x2},
	{0x52a4, 0x0},
	{0x52a5, 0x4},
	{0x52a6, 0x0},
	{0x52a7, 0x8},
	{0x52a8, 0x0},
	{0x52a9, 0x10},
	{0x52aa, 0x0},
	{0x52ab, 0x38},
	{0x52ac, 0x0},
	{0x52ad, 0x3c},
	{0x52ae, 0x0},
	{0x52af, 0x4c},
	{0x5842, 0x02},
	{0x5843, 0x5e},
	{0x5844, 0x04},
	{0x5845, 0x32},
	{0x5846, 0x03},
	{0x5847, 0x29},
	{0x5848, 0x02},
	{0x5849, 0xcc},
	{0x5800, 0x22},
	{0x5801, 0x1e},
	{0x5802, 0x1a},
	{0x5803, 0x1a},
	{0x5804, 0x1f},
	{0x5805, 0x26},
	{0x5806, 0xe},
	{0x5807, 0x9},
	{0x5808, 0x7},
	{0x5809, 0x8},
	{0x580a, 0xb},
	{0x580b, 0x11},
	{0x580c, 0x5},
	{0x580d, 0x2},
	{0x580e, 0x0},
	{0x580f, 0x0},
	{0x5810, 0x3},
	{0x5811, 0x7},
	{0x5812, 0x4},
	{0x5813, 0x1},
	{0x5814, 0x0},
	{0x5815, 0x0},
	{0x5816, 0x3},
	{0x5817, 0x7},
	{0x5818, 0xc},
	{0x5819, 0x8},
	{0x581a, 0x6},
	{0x581b, 0x6},
	{0x581c, 0x9},
	{0x581d, 0x10},
	{0x581e, 0x20},
	{0x581f, 0x1b},
	{0x5820, 0x17},
	{0x5821, 0x18},
	{0x5822, 0x1d},
	{0x5823, 0x23},
	{0x5824, 0x5b},
	{0x5825, 0x6e},
	{0x5826, 0x6e},
	{0x5827, 0x7e},
	{0x5828, 0xab},
	{0x5829, 0x5e},
	{0x582a, 0x8a},
	{0x582b, 0x8a},
	{0x582c, 0x8a},
	{0x582d, 0x9d},
	{0x582e, 0x5b},
	{0x582f, 0x88},
	{0x5830, 0x88},
	{0x5831, 0x98},
	{0x5832, 0x9a},
	{0x5833, 0x4e},
	{0x5834, 0x8a},
	{0x5835, 0x79},
	{0x5836, 0x7a},
	{0x5837, 0xad},
	{0x5838, 0x9b},
	{0x5839, 0x9d},
	{0x583a, 0xad},
	{0x583b, 0x8e},
	{0x583c, 0x5c},
	{0x583e, 0x08},
	{0x583f, 0x04},
	{0x5840, 0x10},
	{0x5480, 0x07},
	{0x5481, 0x16},
	{0x5482, 0x2c},
	{0x5483, 0x4d},
	{0x5484, 0x59},
	{0x5485, 0x64},
	{0x5486, 0x6e},
	{0x5487, 0x76},
	{0x5488, 0x7f},
	{0x5489, 0x86},
	{0x548a, 0x94},
	{0x548b, 0xa3},
	{0x548c, 0xba},
	{0x548d, 0xd2},
	{0x548e, 0xe9},
	{0x548f, 0x1e},
	{0x5490, 0x0f},
	{0x5491, 0xff},
	{0x5492, 0x0e},
	{0x5493, 0x34},
	{0x5494, 0x07},
	{0x5495, 0x1a},
	{0x5496, 0x04},
	{0x5497, 0x0e},
	{0x5498, 0x03},
	{0x5499, 0x82},
	{0x549a, 0x03},
	{0x549b, 0x20},
	{0x549c, 0x02},
	{0x549d, 0xd7},
	{0x549e, 0x02},
	{0x549f, 0xa5},
	{0x54a0, 0x02},
	{0x54a1, 0x75},
	{0x54a2, 0x02},
	{0x54a3, 0x55},
	{0x54a4, 0x02},
	{0x54a5, 0x1c},
	{0x54a6, 0x01},
	{0x54a7, 0xea},
	{0x54a8, 0x01},
	{0x54a9, 0xae},
	{0x54aa, 0x01},
	{0x54ab, 0x7c},
	{0x54ac, 0x01},
	{0x54ad, 0x57},
	{0x5180, 0xf0},
	{0x5181, 0x00},
	{0x5182, 0x41},
	{0x5183, 0x42},
	{0x5184, 0x8f},
	{0x5185, 0x63},
	{0x5186, 0xce},
	{0x5187, 0xa8},
	{0x5188, 0x17},
	{0x5189, 0x1f},
	{0x518a, 0x27},
	{0x518b, 0x41},
	{0x518c, 0x34},
	{0x518d, 0xf0},
	{0x518e, 0x10},
	{0x518f, 0xff},
	{0x5190, 0x00},
	{0x5191, 0xff},
	{0x5192, 0x00},
	{0x5193, 0xff},
	{0x5194, 0x00},
	{0x5380, 0x1},
	{0x5381, 0x0},
	{0x5382, 0x0},
	{0x5383, 0x17},
	{0x5384, 0x0},
	{0x5385, 0x1},
	{0x5386, 0x0},
	{0x5387, 0x0},
	{0x5388, 0x0},
	{0x5389, 0xad},
	{0x538a, 0x0},
	{0x538b, 0x11},
	{0x538c, 0x0},
	{0x538d, 0x0},
	{0x538e, 0x0},
	{0x538f, 0x7},
	{0x5390, 0x0},
	{0x5391, 0x80},
	{0x5392, 0x0},
	{0x5393, 0xa0},
	{0x5394, 0x18},
	{0x3c0a, 0x9c},
	{0x3c0b, 0x3f},
	{0x5501, 0x14},
	{0x5502, 0x00},
	{0x5503, 0x40},
	{0x5504, 0x00},
	{0x5505, 0x80},
	{0x5308, 0x40},
	{0x5309, 0x60},
	{0x3a11, 0xd0},
	{0x3a1b, 0x78},
	{0x3a0f, 0x78},
	{0x3a10, 0x68},
	{0x3a1e, 0x68},
	{0x3a1f, 0x40},
	{0x0100, 0x01},
	{0xFF, 0xFF}
};

static const sensor_reg_t ov9740_raw_qvga[] = {

	/* Software RESET */
	{0x0103, 0x01},

	/* Orientation */
	{0x0101, 0x01},

	/* PLL setting */
	/* PLL mode control */
	{0x3104, 0x20},
	/* PLL control */
	{0x0305, 0x03},
	{0x0307, 0x62},
	{0x0303, 0x01},
	{0x0301, 0x0a},
	{0x3010, 0x01},
	{0x300e, 0x11},
	{0x300c, 0x02},
	{0x300d, 0x13},

	/* Timing setting */
	/* VTS */
	{0x0340, 0x03},
	/* VTS */
	{0x0341, 0x07},
	/* HTS */
	{0x0342, 0x06},
	/* HTS */
	{0x0343, 0x62},
	/* X start */
	{0x0344, 0x00},
	/* X start */
	{0x0345, 0xa8},
	/* Y start */
	{0x0346, 0x00},
	/* Y start */
	{0x0347, 0x04},
	/* X end */
	{0x0348, 0x04},
	/* X end */
	{0x0349, 0x67},
	/* Y end */
	{0x034a, 0x02},
	/* Y end */
	{0x034b, 0xd8},
	/* H output size */
	{0x034c, 0x01},
	/* H output size */
	{0x034d, 0x40},
	/* V output size */
	{0x034e, 0x00},
	/* V output size */
	{0x034f, 0xf0},

	/* Output select */
	{0x3026, 0x00},
	{0x3027, 0x00},
	/* IO control */
	{0x3002, 0xe8},
	{0x3004, 0x03},
	{0x3005, 0xff},

	/* Analog control */
	{0x3601, 0x40},
	{0x3602, 0x16},
	{0x3603, 0xaa},
	{0x3604, 0x0c},
	{0x3610, 0xa1},
	{0x3612, 0x24},
	{0x3620, 0x66},
	{0x3621, 0xc0},
	{0x3622, 0x9f},
	{0x3630, 0xd2},
	{0x3631, 0x5e},
	{0x3632, 0x27},
	{0x3633, 0x50},

	/* Sensor control */
	{0x3703, 0x42},
	{0x3704, 0x10},
	{0x3705, 0x45},
	{0x3707, 0x11},

	/* Internal timing control */
	{0x3833, 0x04},
	{0x3835, 0x04},
	{0x3819, 0x6e},
	{0x3817, 0x94},
	{0x3831, 0x40},
	{0x381a, 0x44},

	/* AEC/AGC control */
	{0x3503, 0x10},
	/* Gain ceiling */
	{0x3a18, 0x01},
	/* Gain ceiling */
	{0x3a19, 0xB5},
	/* Max diff */
	{0x3a1a, 0x05},
	/* High threshold */
	{0x3a11, 0x90},
	/* WPT 2  */
	{0x3a1b, 0x4a},
	/* WPT  */
	{0x3a0f, 0x48},
	/* BPT  */
	{0x3a10, 0x44},
	/* BPT 2  */
	{0x3a1e, 0x42},
	/* Low threshold  */
	{0x3a1f, 0x22},

	/* Banding filter  */
	/* 50Hz banding step */
	{0x3a08, 0x00},
	/* 50Hz banding step */
	{0x3a09, 0xe8},
	/* 50Hz banding Max */
	{0x3a0e, 0x03},
	/* 50Hz Max exposure */
	{0x3a14, 0x15},
	/* 50Hz Max exposure */
	{0x3a15, 0xc6},
	/* 60Hz banding step */
	{0x3a0a, 0x00},
	/* 60Hz banding step */
	{0x3a0b, 0xc0},
	/* 60Hz banding Max */
	{0x3a0d, 0x04},
	/* 60Hz Max exposure */
	{0x3a02, 0x18},
	/* 60Hz Max exposure */
	{0x3a03, 0x20},

	/* 50/60 detection */
	/* Number of samples */
	{0x3c0a, 0x9c},
	/* Number of samples */
	{0x3c0b, 0x3f},

	/* BLC control*/
	/* BLC auto enable */
	{0x4002, 0x45},
	/* BLC mode */
	{0x4005, 0x18},

	/* VFIFO */
	{0x4608, 0x02},
	{0x4609, 0x70},

	/* DVP control */
	/* Vsync control */
	{0x4702, 0x04},
	/* Vsync mode  */
	{0x4704, 0x00},
	/* Vsync control */
	{0x4706, 0x08},

	/* ISP control*/
	/* [7]LC [6]Gamma [3]DNS [2]BPC [1]WPC [0]CIP */
	{0x5000, 0xff},
	/* [7]SDE [6]UV adjust [4]scale [3]contrast [2]UV average [1]CMX [0]AWB */
	{0x5001, 0xff},
	/* [7]PAD [5]Buffer [3]Vario [1]BLC [0]AWB gain */
	{0x5003, 0xff},

	/* Scale X input */
	{0x501e, 0x03},
	/* Scale X input */
	{0x501f, 0xc0},
	/* Scale Y input */
	{0x5020, 0x02},
	/*  Scale Y input */
	{0x5021, 0xd0},

	/* AWB setting */
	{0x5180, 0xf0},
	{0x5181, 0x00},
	{0x5182, 0x41},
	{0x5183, 0x42},
	{0x5184, 0x80},
	{0x5185, 0x68},
	{0x5186, 0x93},
	{0x5187, 0xa8},
	{0x5188, 0x17},
	{0x5189, 0x45},
	{0x518a, 0x27},
	{0x518b, 0x41},
	{0x518c, 0x2d},
	{0x518d, 0xf0},
	{0x518e, 0x10},
	{0x518f, 0xff},
	{0x5190, 0x0 },
	{0x5191, 0xff},
	{0x5192, 0x00},
	{0x5193, 0xff},
	{0x5194, 0x00},

	/* DNS setting */
	{0x529a, 0x02},
	{0x529b, 0x08},
	{0x529c, 0x0a},
	{0x529d, 0x10},
	{0x529e, 0x10},
	{0x529f, 0x28},
	{0x52a0, 0x32},
	{0x52a2, 0x00},
	{0x52a3, 0x02},
	{0x52a4, 0x00},
	{0x52a5, 0x04},
	{0x52a6, 0x00},
	{0x52a7, 0x08},
	{0x52a8, 0x00},
	{0x52a9, 0x10},
	{0x52aa, 0x00},
	{0x52ab, 0x38},
	{0x52ac, 0x00},
	{0x52ad, 0x3c},
	{0x52ae, 0x00},
	{0x52af, 0x4c},

	/*  CIP setting */
	{0x530d, 0x06},

	/*  CMX setting */
	{0x5380, 0x01},
	{0x5381, 0x00},
	{0x5382, 0x00},
	{0x5383, 0x0d},
	{0x5384, 0x00},
	{0x5385, 0x2f},
	{0x5386, 0x00},
	{0x5387, 0x00},
	{0x5388, 0x00},
	{0x5389, 0xd3},
	{0x538a, 0x00},
	{0x538b, 0x0f},
	{0x538c, 0x00},
	{0x538d, 0x00},
	{0x538e, 0x00},
	{0x538f, 0x32},
	{0x5390, 0x00},
	{0x5391, 0x94},
	{0x5392, 0x00},
	{0x5393, 0xa4},
	{0x5394, 0x18},

	/* Contrast setting */
	{0x5401, 0x2c},
	{0x5403, 0x28},
	{0x5404, 0x06},
	{0x5405, 0xe0},

	/*  Y Gamma setting   */
	{0x5480, 0x04},
	{0x5481, 0x12},
	{0x5482, 0x27},
	{0x5483, 0x49},
	{0x5484, 0x57},
	{0x5485, 0x66},
	{0x5486, 0x75},
	{0x5487, 0x81},
	{0x5488, 0x8c},
	{0x5489, 0x95},
	{0x548a, 0xa5},
	{0x548b, 0xb2},
	{0x548c, 0xc8},
	{0x548d, 0xd9},
	{0x548e, 0xec},

	/* UV Gamma setting */
	{0x5490, 0x01},
	{0x5491, 0xc0},
	{0x5492, 0x03},
	{0x5493, 0x00},
	{0x5494, 0x03},
	{0x5495, 0xe0},
	{0x5496, 0x03},
	{0x5497, 0x10},
	{0x5498, 0x02},
	{0x5499, 0xac},
	{0x549a, 0x02},
	{0x549b, 0x75},
	{0x549c, 0x02},
	{0x549d, 0x44},
	{0x549e, 0x02},
	{0x549f, 0x20},
	{0x54a0, 0x02},
	{0x54a1, 0x07},
	{0x54a2, 0x01},
	{0x54a3, 0xec},
	{0x54a4, 0x01},
	{0x54a5, 0xc0},
	{0x54a6, 0x01},
	{0x54a7, 0x9b},
	{0x54a8, 0x01},
	{0x54a9, 0x63},
	{0x54aa, 0x01},
	{0x54ab, 0x2b},
	{0x54ac, 0x01},
	{0x54ad, 0x22},

	/* UV adjust */
	{0x5501, 0x1c},
	{0x5502, 0x00},
	{0x5503, 0x40},
	{0x5504, 0x00},
	{0x5505, 0x80},

	/* Lens correction */
	{0x5800, 0x1c},
	{0x5801, 0x16},
	{0x5802, 0x15},
	{0x5803, 0x16},
	{0x5804, 0x18},
	{0x5805, 0x1a},
	{0x5806, 0x0c},
	{0x5807, 0x0a},
	{0x5808, 0x08},
	{0x5809, 0x08},
	{0x580a, 0x0a},
	{0x580b, 0x0b},
	{0x580c, 0x05},
	{0x580d, 0x02},
	{0x580e, 0x00},
	{0x580f, 0x00},
	{0x5810, 0x02},
	{0x5811, 0x05},
	{0x5812, 0x04},
	{0x5813, 0x01},
	{0x5814, 0x00},
	{0x5815, 0x00},
	{0x5816, 0x02},
	{0x5817, 0x03},
	{0x5818, 0x0a},
	{0x5819, 0x07},
	{0x581a, 0x05},
	{0x581b, 0x05},
	{0x581c, 0x08},
	{0x581d, 0x0b},
	{0x581e, 0x15},
	{0x581f, 0x14},
	{0x5820, 0x14},
	{0x5821, 0x13},
	{0x5822, 0x17},
	{0x5823, 0x16},
	{0x5824, 0x46},
	{0x5825, 0x4c},
	{0x5826, 0x6c},
	{0x5827, 0x4c},
	{0x5828, 0x80},
	{0x5829, 0x2e},
	{0x582a, 0x48},
	{0x582b, 0x46},
	{0x582c, 0x2a},
	{0x582d, 0x68},
	{0x582e, 0x08},
	{0x582f, 0x26},
	{0x5830, 0x44},
	{0x5831, 0x46},
	{0x5832, 0x62},
	{0x5833, 0x0c},
	{0x5834, 0x28},
	{0x5835, 0x46},
	{0x5836, 0x28},
	{0x5837, 0x88},
	{0x5838, 0x0e},
	{0x5839, 0x0e},
	{0x583a, 0x2c},
	{0x583b, 0x2e},
	{0x583c, 0x46},
	{0x583d, 0xca},
	{0x583e, 0xf0},
	{0x5842, 0x02},
	{0x5843, 0x5e},
	{0x5844, 0x04},
	{0x5845, 0x32},
	{0x5846, 0x03},
	{0x5847, 0x29},
	{0x5848, 0x02},
	{0x5849, 0xcc},

	{0x3026, 0x0 },
	{0x3027, 0x0 },
	{0x3002, 0xe8},
	{0x3004, 0x3 },
	{0x3005, 0xff},
	{0x3703, 0x42},
	{0x3704, 0x10},
	{0x3705, 0x45},
	{0x3603, 0xaa},
	{0x3632, 0x27},
	{0x3620, 0x66},
	{0x3621, 0xc0},
	{0x0340, 0x3 },
	{0x0341, 0x48},
	{0x0342, 0x6 },
	{0x0343, 0x80},
	{0x0202, 0x3 },
	{0x0203, 0x43},
	{0x3833, 0x4 },
	{0x3835, 0x2 },
	{0x4702, 0x4 },
	{0x4704, 0x0 },
	{0x4706, 0x8 },
	{0x3819, 0x6e},
	{0x3817, 0x94},
	{0x3a18, 0x0 },
	{0x3a19, 0x7f},
	{0x5003, 0xa7},
	{0x3631, 0x5e},
	{0x3633, 0x50},
	{0x3630, 0xd2},
	{0x3604, 0xc },
	{0x3601, 0x40},
	{0x3602, 0x16},
	{0x3610, 0xa1},
	{0x3612, 0x24},

	{0x3a14, 0x17},
	{0x3a15, 0xa0},
	{0x3a0a, 0x0 },
	{0x3a0b, 0xd2},
	{0x3a0d, 0x4 },
	{0x3a02, 0x1a},
	{0x3a03, 0x40},
	{0x0303, 0x1 },
	{0x5004, 0x0 },
	{0x4300, 0xf8},
	{0x0101, 0x1 },
	{0x3707, 0x11},
	{0x3622, 0x9f},
	{0x4002, 0x45},
	{0x5000, 0x1 },
	{0x5001, 0x0 },
	{0x3406, 0x1 },
	{0x3503, 0x10},
	{0x3a1a, 0x5 },
	{0x4005, 0x48},
	{0x0345, 0x01},
	{0x0100, 0x1 },

	{0xFF, 0xFF}
};


static const sensor_reg_t ov9740_yuv_qvga[] = {

	/* Software RESET */
	{0x0103, 0x01},

	/* Orientation */
	{0x0101, 0x01},

	/* PLL setting */
	/* PLL mode control */
	{0x3104, 0x20},
	/* PLL control */
	{0x0305, 0x03},
	{0x0307, 0x62},
	{0x0303, 0x01},
	{0x0301, 0x0a},
	{0x3010, 0x01},
	{0x300e, 0x11},
	{0x300c, 0x02},
	{0x300d, 0x13},

	/* Timing setting */
	{0x0340, 0x03},
	{0x0341, 0x07},
	{0x0342, 0x06},
	{0x0343, 0x62},
	{0x0344, 0x00},
	{0x0345, 0xa8},
	{0x0346, 0x00},
	{0x0347, 0x04},
	{0x0348, 0x04},
	{0x0349, 0x67},
	{0x034a, 0x02},
	{0x034b, 0xd8},
	{0x034c, 0x01},
	{0x034d, 0x40},
	{0x034e, 0x00},
	{0x034f, 0xf0},

	/* Output select */
	{0x3026, 0x00},
	{0x3027, 0x00},

	/* IO control */
	{0x3002, 0xe8},
	{0x3004, 0x03},
	{0x3005, 0xff},

	/* Analog control */
	{0x3601, 0x40},
	{0x3602, 0x16},
	{0x3603, 0xaa},
	{0x3604, 0x0c},
	{0x3610, 0xa1},
	{0x3612, 0x24},
	{0x3620, 0x66},
	{0x3621, 0xc0},
	{0x3622, 0x9f},
	{0x3630, 0xd2},
	{0x3631, 0x5e},
	{0x3632, 0x27},
	{0x3633, 0x50},

	/* Sensor control */
	{0x3703, 0x42},
	{0x3704, 0x10},
	{0x3705, 0x45},
	{0x3707, 0x11},

	/*  Internal timing control */
	{0x3833, 0x04},
	{0x3835, 0x04},
	{0x3819, 0x6e},
	{0x3817, 0x94},
	{0x3831, 0x40},

	/* AEC/AGC control */
	{0x3503, 0x10},
	/* Gain ceiling */
	{0x3a18, 0x01},
	/* Gain ceiling */
	{0x3a19, 0xB5},
	/* Max diff */
	{0x3a1a, 0x05},
	/* High threshold */
	{0x3a11, 0x90},
	/* WPT 2 */
	{0x3a1b, 0x4a},
	/* WPT */
	{0x3a0f, 0x48},
	/* BPT  */
	{0x3a10, 0x44},
	/* BPT 2 */
	{0x3a1e, 0x42},
	/* Low threshold  */
	{0x3a1f, 0x22},

	/* Banding filter */
	/* 50Hz banding step  */
	{0x3a08, 0x00},
	{0x3a09, 0xe8},
	/* 50Hz banding Max */
	{0x3a0e, 0x03},
	/* 50Hz Max exposure */
	{0x3a14, 0x15},
	/*  50Hz Max exposure */
	{0x3a15, 0xc6},
	/* 60Hz banding step */
	{0x3a0a, 0x00},
	/* 60Hz banding step */
	{0x3a0b, 0xc0},
	/* 60Hz banding Max */
	{0x3a0d, 0x04},
	/* 60Hz Max exposure */
	{0x3a02, 0x18},
	{0x3a03, 0x20},

	/* 50/60 detection */
	/* Number of samples */
	{0x3c0a, 0x9c},
	/* Number of samples */
	{0x3c0b, 0x3f},

	/* BLC control */
	/* BLC auto enable*/
	{0x4002, 0x45},
	/* BLC mode */
	{0x4005, 0x18},

	/* VFIFO */
	{0x4608, 0x02},
	{0x4609, 0x70},

	/* DVP control */
	/* Vsync control */
	{0x4702, 0x04},
	/* Vsync mode  */
	{0x4704, 0x00},
	/* Vsync control */
	{0x4706, 0x08},

	/* ISP control */
	/* [7]LC [6]Gamma [3]DNS [2]BPC [1]WPC [0]CIP */
	{0x5000, 0xff},
	/* [7]SDE [6]UV adjust [4]scale [3]contrast [2]UV average [1]CMX [0]AWB */
	{0x5001, 0xff},
	/* [7]PAD [5]Buffer [3]Vario [1]BLC [0]AWB gain */
	{0x5003, 0xff},

	/* Scale X input */
	{0x501e, 0x03},
	/* Scale X input */
	{0x501f, 0xc0},
	/* Scale Y input */
	{0x5020, 0x02},
	/* Scale Y input */
	{0x5021, 0xd0},

	/* AWB setting */
	{0x5180, 0xf0},
	{0x5181, 0x00},
	{0x5182, 0x41},
	{0x5183, 0x42},
	{0x5184, 0x80},
	{0x5185, 0x68},
	{0x5186, 0x93},
	{0x5187, 0xa8},
	{0x5188, 0x17},
	{0x5189, 0x45},
	{0x518a, 0x27},
	{0x518b, 0x41},
	{0x518c, 0x2d},
	{0x518d, 0xf0},
	{0x518e, 0x10},
	{0x518f, 0xff},
	{0x5190, 0x0 },
	{0x5191, 0xff},
	{0x5192, 0x00},
	{0x5193, 0xff},
	{0x5194, 0x00},

	/* DNS setting */
	{0x529a, 0x02},
	{0x529b, 0x08},
	{0x529c, 0x0a},
	{0x529d, 0x10},
	{0x529e, 0x10},
	{0x529f, 0x28},
	{0x52a0, 0x32},
	{0x52a2, 0x00},
	{0x52a3, 0x02},
	{0x52a4, 0x00},
	{0x52a5, 0x04},
	{0x52a6, 0x00},
	{0x52a7, 0x08},
	{0x52a8, 0x00},
	{0x52a9, 0x10},
	{0x52aa, 0x00},
	{0x52ab, 0x38},
	{0x52ac, 0x00},
	{0x52ad, 0x3c},
	{0x52ae, 0x00},
	{0x52af, 0x4c},

	/* CIP setting */
	{0x530d, 0x06},

	/* CMX setting */
	{0x5380, 0x01},
	{0x5381, 0x00},
	{0x5382, 0x00},
	{0x5383, 0x0d},
	{0x5384, 0x00},
	{0x5385, 0x2f},
	{0x5386, 0x00},
	{0x5387, 0x00},
	{0x5388, 0x00},
	{0x5389, 0xd3},
	{0x538a, 0x00},
	{0x538b, 0x0f},
	{0x538c, 0x00},
	{0x538d, 0x00},
	{0x538e, 0x00},
	{0x538f, 0x32},
	{0x5390, 0x00},
	{0x5391, 0x94},
	{0x5392, 0x00},
	{0x5393, 0xa4},
	{0x5394, 0x18},

	/* Contrast setting */
	{0x5401, 0x2c},
	{0x5403, 0x28},
	{0x5404, 0x06},
	{0x5405, 0xe0},

	/* Y Gamma setting  */
	{0x5480, 0x04},
	{0x5481, 0x12},
	{0x5482, 0x27},
	{0x5483, 0x49},
	{0x5484, 0x57},
	{0x5485, 0x66},
	{0x5486, 0x75},
	{0x5487, 0x81},
	{0x5488, 0x8c},
	{0x5489, 0x95},
	{0x548a, 0xa5},
	{0x548b, 0xb2},
	{0x548c, 0xc8},
	{0x548d, 0xd9},
	{0x548e, 0xec},

	/* UV Gamma setting */
	{0x5490, 0x01},
	{0x5491, 0xc0},
	{0x5492, 0x03},
	{0x5493, 0x00},
	{0x5494, 0x03},
	{0x5495, 0xe0},
	{0x5496, 0x03},
	{0x5497, 0x10},
	{0x5498, 0x02},
	{0x5499, 0xac},
	{0x549a, 0x02},
	{0x549b, 0x75},
	{0x549c, 0x02},
	{0x549d, 0x44},
	{0x549e, 0x02},
	{0x549f, 0x20},
	{0x54a0, 0x02},
	{0x54a1, 0x07},
	{0x54a2, 0x01},
	{0x54a3, 0xec},
	{0x54a4, 0x01},
	{0x54a5, 0xc0},
	{0x54a6, 0x01},
	{0x54a7, 0x9b},
	{0x54a8, 0x01},
	{0x54a9, 0x63},
	{0x54aa, 0x01},
	{0x54ab, 0x2b},
	{0x54ac, 0x01},
	{0x54ad, 0x22},

	/* UV adjust */
	{0x5501, 0x1c},
	{0x5502, 0x00},
	{0x5503, 0x40},
	{0x5504, 0x00},
	{0x5505, 0x80},

	/* Lens correction */
	{0x5800, 0x1c},
	{0x5801, 0x16},
	{0x5802, 0x15},
	{0x5803, 0x16},
	{0x5804, 0x18},
	{0x5805, 0x1a},
	{0x5806, 0x0c},
	{0x5807, 0x0a},
	{0x5808, 0x08},
	{0x5809, 0x08},
	{0x580a, 0x0a},
	{0x580b, 0x0b},
	{0x580c, 0x05},
	{0x580d, 0x02},
	{0x580e, 0x00},
	{0x580f, 0x00},
	{0x5810, 0x02},
	{0x5811, 0x05},
	{0x5812, 0x04},
	{0x5813, 0x01},
	{0x5814, 0x00},
	{0x5815, 0x00},
	{0x5816, 0x02},
	{0x5817, 0x03},
	{0x5818, 0x0a},
	{0x5819, 0x07},
	{0x581a, 0x05},
	{0x581b, 0x05},
	{0x581c, 0x08},
	{0x581d, 0x0b},
	{0x581e, 0x15},
	{0x581f, 0x14},
	{0x5820, 0x14},
	{0x5821, 0x13},
	{0x5822, 0x17},
	{0x5823, 0x16},
	{0x5824, 0x46},
	{0x5825, 0x4c},
	{0x5826, 0x6c},
	{0x5827, 0x4c},
	{0x5828, 0x80},
	{0x5829, 0x2e},
	{0x582a, 0x48},
	{0x582b, 0x46},
	{0x582c, 0x2a},
	{0x582d, 0x68},
	{0x582e, 0x08},
	{0x582f, 0x26},
	{0x5830, 0x44},
	{0x5831, 0x46},
	{0x5832, 0x62},
	{0x5833, 0x0c},
	{0x5834, 0x28},
	{0x5835, 0x46},
	{0x5836, 0x28},
	{0x5837, 0x88},
	{0x5838, 0x0e},
	{0x5839, 0x0e},
	{0x583a, 0x2c},
	{0x583b, 0x2e},
	{0x583c, 0x46},
	{0x583d, 0xca},
	{0x583e, 0xf0},
	{0x5842, 0x02},
	{0x5843, 0x5e},
	{0x5844, 0x04},
	{0x5845, 0x32},
	{0x5846, 0x03},
	{0x5847, 0x29},
	{0x5848, 0x02},
	{0x5849, 0xcc},

	/* Start streaming */
	{0x0100, 0x01},
	{0xFF, 0xFF}
};

static const sensor_output_t ov9740_output_vga =
{ 0, VGA, YUV_422, BIT_8, 1, 640, 360, ov9740_yuv_vga };

static const sensor_output_t ov9740_output_wxga =
{ 0, WXGA, YUV_422, BIT_8, 1, 1280, 720, ov9740_yuv_wxga };

static const sensor_output_t ov9740_output_qvga_raw =
{ 0, QVGA, RAW_BAYER, BIT_10, 1, 320, 240, ov9740_raw_qvga };

static const sensor_output_t ov9740_output_qvga_yuv =
{ 0, QVGA, YUV_422, BIT_8, 1, 320, 240, ov9740_yuv_qvga };

const sensor_profile_t ov9740_profile =
{
	"OV9740",
	SENSOR_COMS,                     /* Sensor type for CMOS sensor or CCD */
	SENSOR_TWI_REG_2BYTE_DATA_BYTE,  /* TWI interface mode  */
	OV9740_SLAVE_ADDRESS,            /* TWI slave address */
	OV9740_PIDH_ADDRESS,             /* Register address for product ID high byte */
	OV9740_PIDL_ADDRESS,             /* Register address for product ID low byte*/
	OV9740_PIDH,                     /* product ID high byte */
	OV9740_PIDL,                     /* product ID low byte */
	OV9740_PID_VER_MASK,             /* version mask */
	{
		&ov9740_output_vga,
		&ov9740_output_wxga,
		&ov9740_output_qvga_raw,
		&ov9740_output_qvga_yuv,
		0,
		0,
		0
	}
};
