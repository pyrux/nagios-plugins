/*****************************************************************************
* 
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
* 
* $Id$
* 
*****************************************************************************/

#include "common.h"
#include "gl/base64.h"
#include "tap.h"

int
main (int argc, char **argv)
{
#if 0  /* The current base64 function doesn't work on 8bit data */
	char random[1024] = {
	0x8b,0xb0,0xc4,0xe2,0xfc,0x22,0x9f,0x0d,0x85,0xe7,0x2c,0xaa,0x39,0xa1,0x46,0x88,
	0x50,0xe6,0x34,0x37,0x0b,0x45,0x4b,0xb8,0xb2,0x86,0x7a,0x3e,0x7f,0x0c,0x40,0x18,
	0x6b,0xad,0xe0,0x4c,0x60,0x8c,0xa3,0xc3,0x3b,0x3e,0x9b,0x16,0x84,0xc6,0xd8,0x3f,
	0x40,0xea,0x91,0x85,0xe3,0x71,0x94,0xb5,0xc7,0xf9,0x13,0xef,0x6b,0xa7,0x18,0x5b,
	0x48,0xa7,0xbe,0xef,0x95,0xb3,0xcf,0xbe,0x5e,0x51,0xf3,0x68,0x25,0x8f,0x06,0x5b,
	0xfc,0xf2,0xf5,0x3e,0x3f,0x1b,0x5c,0x6d,0xea,0x39,0xfc,0xe3,0xe3,0xe0,0xec,0xfa,
	0xb3,0x76,0x52,0x13,0xa5,0x33,0xfd,0x65,0xa3,0xa7,0x91,0x86,0x06,0xc7,0x71,0x9e,
	0x14,0x74,0x63,0x70,0xad,0x15,0xa7,0x18,0xd1,0x06,0x85,0x33,0x91,0x2c,0x6b,0x80,
	0x2d,0xf7,0x20,0xc8,0x8d,0xf3,0x51,0x45,0xa5,0x7f,0x7f,0xb5,0xa6,0xae,0x26,0x53,
	0xa4,0x68,0x1e,0x0e,0xd8,0x3a,0x59,0x50,0xd6,0xb7,0x5f,0xe6,0x01,0x4c,0xda,0xe4,
	0x32,0xd0,0xfb,0xea,0xa0,0x72,0x2b,0x9d,0x7e,0x43,0xfb,0xe1,0x42,0x0b,0xe1,0x73,
	0xa4,0xf9,0x3a,0x6b,0x4a,0xf9,0x6e,0x89,0x0f,0xa7,0xad,0x8c,0xde,0x32,0x4b,0x0d,
	0x79,0xc6,0x39,0xa1,0x0a,0x26,0xdf,0x3a,0x80,0x26,0x3f,0x13,0xae,0xfe,0x50,0x2b,
	0xe7,0xc6,0xf2,0x3f,0xbb,0x01,0xc6,0x9b,0x0b,0x35,0xc9,0xb9,0x99,0xf0,0x3d,0x82,
	0x41,0x8e,0x38,0x85,0xf6,0x65,0xcf,0xb1,0x6c,0xde,0x97,0x04,0x15,0x36,0xa6,0x64,
	0xb4,0x94,0x17,0xfc,0x0e,0x0b,0xdb,0x55,0xd3,0x6b,0x80,0x42,0x41,0xcf,0x82,0x5c,
	0x13,0x8a,0x2c,0xac,0x3e,0x90,0x94,0xb3,0x45,0xfc,0xfa,0xda,0xb1,0xe1,0xb9,0x88,
	0xa2,0xea,0x9e,0x0f,0xef,0x9b,0x6c,0x13,0xde,0x79,0xa0,0xf9,0xd0,0xe2,0x06,0xac,
	0xf6,0x97,0x04,0xab,0xaa,0xf5,0x9f,0x8c,0x37,0xce,0x8f,0xfb,0x2d,0x34,0x75,0xe0,
	0x31,0xf4,0xae,0x8a,0x4a,0x11,0xec,0xc9,0xa5,0x81,0x3a,0x3d,0xa2,0x9e,0xed,0x18,
	0x51,0x78,0xad,0xe2,0x31,0xcc,0x50,0x40,0x97,0xcb,0x6f,0xa2,0x80,0x7f,0xe1,0x2a,
	0x34,0xbe,0x00,0x5f,0x2f,0x5f,0xaf,0x94,0x2a,0xd5,0x27,0x9f,0x46,0x9f,0x92,0x46,
	0x5e,0x1e,0x0c,0x7c,0xb8,0x81,0xe1,0xe4,0xf6,0x22,0x6e,0x08,0x20,0xb8,0x4f,0x73,
	0x72,0x55,0x92,0xc2,0x99,0x50,0xe1,0xc3,0xf7,0x7d,0xc1,0xae,0x35,0x4f,0xbd,0xb1,
	0x28,0xd8,0x67,0x9b,0x03,0xd1,0xa0,0xb2,0x9c,0x88,0xee,0x37,0xf5,0xb7,0x44,0xcf,
	0x68,0x19,0x87,0x64,0x14,0xa8,0x25,0xab,0x69,0xb5,0x98,0x27,0x26,0x14,0x93,0xf0,
	0x42,0x19,0x12,0x75,0x3e,0x02,0x5d,0x7c,0x93,0x9f,0x96,0xd3,0xbb,0x74,0xc8,0xbc,
	0xde,0xb9,0x6c,0x9c,0x9c,0xf4,0xb9,0x9f,0x80,0x9b,0x06,0x8a,0xe8,0xbb,0xd2,0x4f,
	0x9e,0xee,0xbc,0x35,0x8c,0xb8,0x0e,0x0b,0xbb,0x9a,0xf6,0x23,0xa9,0xd3,0x9e,0xdf,
	0xc1,0x0c,0x4b,0x0a,0x65,0xa8,0x78,0x67,0x48,0x59,0xa6,0x6d,0xb1,0xf6,0xa3,0x70,
	0xe1,0x64,0x3b,0xb8,0x79,0x66,0xf4,0xd3,0xac,0x64,0xe4,0x54,0x83,0x54,0x65,0xc4,
	0x4c,0x98,0xcf,0x48,0x20,0x4f,0xf2,0x90,0xbf,0x8c,0x52,0x2d,0x03,0x14,0x83,0xd1,
	0x42,0x90,0x77,0xea,0x34,0x06,0x32,0x83,0xf2,0x14,0xfc,0x88,0x5d,0xd2,0x9a,0xe2,
	0x7c,0x3e,0x30,0xfe,0x5f,0x7f,0xd4,0x0f,0x44,0x49,0x5d,0x5e,0x90,0x6a,0x86,0x2b,
	0x86,0xd3,0x90,0x39,0xb7,0x32,0x4a,0x4e,0x3d,0x2b,0xe5,0xb8,0x39,0x87,0x72,0xd4,
	0xe4,0x4d,0xd6,0x6a,0x03,0xa2,0x70,0xfb,0x5f,0xe0,0x8b,0xaa,0x8b,0x6b,0x10,0x64,
	0x94,0x85,0x22,0x80,0x73,0xc0,0x23,0xdb,0xd1,0x9f,0x2b,0x9a,0xdd,0xe9,0xfa,0xc6,
	0x0c,0x5f,0xb2,0xcb,0xca,0x28,0xd2,0xf9,0x5b,0x92,0x42,0x98,0x80,0xdd,0x27,0xb1,
	0xd3,0x3c,0x4c,0xb6,0x4e,0x38,0x3f,0x72,0x83,0x71,0x02,0x5b,0xb6,0xd9,0xff,0x75,
	0xee,0x88,0xd4,0x8d,0xb4,0x1c,0x34,0xd7,0xdd,0xe9,0x48,0x80,0x3b,0x85,0x07,0xee,
	0x27,0xe5,0x6e,0xc0,0xbd,0x3a,0xcf,0xf2,0x5d,0xb9,0x16,0x0f,0xe3,0x92,0x92,0x15,
	0x3a,0x70,0x0d,0x57,0x98,0x8d,0xde,0xbd,0xa2,0x68,0x68,0x7c,0x6d,0x4f,0x8c,0xfb,
	0x89,0x2d,0x4a,0x73,0xa0,0x47,0x07,0xd7,0x75,0x5d,0x53,0x70,0x34,0x21,0x40,0x57,
	0x51,0xde,0xc9,0xc4,0x80,0xd4,0x27,0x84,0x68,0xfe,0x59,0x56,0xd8,0xf4,0x14,0xbc,
	0x96,0xb3,0x41,0x96,0x4b,0xaf,0x49,0x37,0x0a,0x54,0x88,0x08,0x1f,0x39,0x67,0xf6,
	0xa8,0xa8,0x87,0x9d,0xe1,0xc7,0xd1,0x4d,0x75,0x26,0xd2,0xc7,0xc7,0x8c,0x57,0xd8,
	0x74,0x3e,0xe2,0xec,0xd8,0xba,0xc4,0x9e,0x96,0xae,0xa1,0x1c,0x73,0xc5,0x67,0x74,
	0x4f,0x33,0xe6,0x0e,0x74,0xe6,0x26,0x1f,0x2e,0x38,0xc4,0x40,0x7e,0xaa,0xd0,0x52,
	0xde,0xc3,0x81,0x7a,0xb8,0x49,0xbc,0x55,0x4d,0x5a,0xc4,0x08,0x26,0x59,0xcd,0x45,
	0x8b,0x48,0x0a,0x33,0xde,0xca,0xcd,0x75,0x16,0x97,0xe3,0xc6,0x81,0x2a,0xd5,0xfb,
	0x8f,0x82,0xf3,0x6a,0x4b,0xff,0xf5,0x65,0xbc,0x4c,0xb3,0x39,0xec,0xf4,0x85,0x60,
	0x0f,0xff,0x2d,0x41,0x4d,0x4d,0xc6,0xf1,0x89,0x6f,0x4f,0xe0,0x15,0x0f,0x46,0xf3,
	0xe3,0xcc,0xde,0x74,0x30,0x8d,0x28,0x43,0x88,0x72,0xb2,0x04,0xae,0x31,0x29,0xa7,
	0x44,0x6d,0x93,0x97,0xc8,0x8f,0x49,0x52,0x10,0x93,0x7f,0x97,0x96,0xe2,0x79,0x35,
	0x78,0xbe,0x81,0x7c,0xae,0x0f,0x76,0xbe,0x5e,0x53,0x6c,0x5b,0x5f,0x7c,0x99,0x41,
	0x82,0xaf,0x97,0x64,0x41,0x75,0x90,0x04,0x47,0xfc,0xbd,0x4b,0xd2,0x80,0x10,0x5d,
	0x51,0x4e,0x7a,0xa7,0x25,0xd5,0xc0,0x12,0x35,0x60,0x05,0x1b,0x34,0xad,0x84,0x7a,
	0x6a,0x69,0x82,0x79,0x83,0xba,0x2f,0x06,0x8a,0x79,0x7b,0x12,0x5d,0x7c,0x52,0xa9,
	0xc7,0xd8,0x12,0x73,0x3f,0x27,0xd6,0x05,0x8c,0x48,0xb2,0x58,0xeb,0x57,0xdc,0x83,
	0x64,0xd6,0x91,0xd2,0x7a,0xb0,0xb6,0x29,0x17,0x3b,0x68,0xfa,0xfc,0x85,0x6b,0xeb,
	0x13,0xea,0xa4,0x5c,0x68,0x42,0x98,0xb2,0x83,0xf3,0xee,0x84,0x21,0xae,0x81,0x84,
	0xe3,0x7d,0x44,0xc1,0x12,0xb1,0x0b,0x95,0x9f,0x70,0x80,0xae,0xe6,0x94,0x3c,0x7f,
	0xab,0x00,0x9f,0x0c,0xa8,0x59,0x0a,0x96,0xc9,0x5a,0x5c,0xe4,0xe5,0xcb,0x91,0x29,
	0x15,0xb6,0x5a,0xe5,0x19,0xcf,0x60,0x23,0xba,0x3a,0x93,0x25,0x02,0x78,0xcc,0x54
	};

	char b64_known[1368] = {
	0x69,0x37,0x44,0x45,0x34,0x76,0x77,0x69,0x6e,0x77,0x32,0x46,0x35,0x79,0x79,0x71,
	0x4f,0x61,0x46,0x47,0x69,0x46,0x44,0x6d,0x4e,0x44,0x63,0x4c,0x52,0x55,0x75,0x34,
	0x73,0x6f,0x5a,0x36,0x50,0x6e,0x38,0x4d,0x51,0x42,0x68,0x72,0x72,0x65,0x42,0x4d,
	0x59,0x49,0x79,0x6a,0x77,0x7a,0x73,0x2b,0x6d,0x78,0x61,0x45,0x78,0x74,0x67,0x2f,
	0x51,0x4f,0x71,0x52,0x68,0x65,0x4e,0x78,0x6c,0x4c,0x58,0x48,0x2b,0x52,0x50,0x76,
	0x61,0x36,0x63,0x59,0x57,0x30,0x69,0x6e,0x76,0x75,0x2b,0x56,0x73,0x38,0x2b,0x2b,
	0x58,0x6c,0x48,0x7a,0x61,0x43,0x57,0x50,0x42,0x6c,0x76,0x38,0x38,0x76,0x55,0x2b,
	0x50,0x78,0x74,0x63,0x62,0x65,0x6f,0x35,0x2f,0x4f,0x50,0x6a,0x34,0x4f,0x7a,0x36,
	0x73,0x33,0x5a,0x53,0x45,0x36,0x55,0x7a,0x2f,0x57,0x57,0x6a,0x70,0x35,0x47,0x47,
	0x42,0x73,0x64,0x78,0x6e,0x68,0x52,0x30,0x59,0x33,0x43,0x74,0x46,0x61,0x63,0x59,
	0x30,0x51,0x61,0x46,0x4d,0x35,0x45,0x73,0x61,0x34,0x41,0x74,0x39,0x79,0x44,0x49,
	0x6a,0x66,0x4e,0x52,0x52,0x61,0x56,0x2f,0x66,0x37,0x57,0x6d,0x72,0x69,0x5a,0x54,
	0x70,0x47,0x67,0x65,0x44,0x74,0x67,0x36,0x57,0x56,0x44,0x57,0x74,0x31,0x2f,0x6d,
	0x41,0x55,0x7a,0x61,0x35,0x44,0x4c,0x51,0x2b,0x2b,0x71,0x67,0x63,0x69,0x75,0x64,
	0x66,0x6b,0x50,0x37,0x34,0x55,0x49,0x4c,0x34,0x58,0x4f,0x6b,0x2b,0x54,0x70,0x72,
	0x53,0x76,0x6c,0x75,0x69,0x51,0x2b,0x6e,0x72,0x59,0x7a,0x65,0x4d,0x6b,0x73,0x4e,
	0x65,0x63,0x59,0x35,0x6f,0x51,0x6f,0x6d,0x33,0x7a,0x71,0x41,0x4a,0x6a,0x38,0x54,
	0x72,0x76,0x35,0x51,0x4b,0x2b,0x66,0x47,0x38,0x6a,0x2b,0x37,0x41,0x63,0x61,0x62,
	0x43,0x7a,0x58,0x4a,0x75,0x5a,0x6e,0x77,0x50,0x59,0x4a,0x42,0x6a,0x6a,0x69,0x46,
	0x39,0x6d,0x58,0x50,0x73,0x57,0x7a,0x65,0x6c,0x77,0x51,0x56,0x4e,0x71,0x5a,0x6b,
	0x74,0x4a,0x51,0x58,0x2f,0x41,0x34,0x4c,0x32,0x31,0x58,0x54,0x61,0x34,0x42,0x43,
	0x51,0x63,0x2b,0x43,0x58,0x42,0x4f,0x4b,0x4c,0x4b,0x77,0x2b,0x6b,0x4a,0x53,0x7a,
	0x52,0x66,0x7a,0x36,0x32,0x72,0x48,0x68,0x75,0x59,0x69,0x69,0x36,0x70,0x34,0x50,
	0x37,0x35,0x74,0x73,0x45,0x39,0x35,0x35,0x6f,0x50,0x6e,0x51,0x34,0x67,0x61,0x73,
	0x39,0x70,0x63,0x45,0x71,0x36,0x72,0x31,0x6e,0x34,0x77,0x33,0x7a,0x6f,0x2f,0x37,
	0x4c,0x54,0x52,0x31,0x34,0x44,0x48,0x30,0x72,0x6f,0x70,0x4b,0x45,0x65,0x7a,0x4a,
	0x70,0x59,0x45,0x36,0x50,0x61,0x4b,0x65,0x37,0x52,0x68,0x52,0x65,0x4b,0x33,0x69,
	0x4d,0x63,0x78,0x51,0x51,0x4a,0x66,0x4c,0x62,0x36,0x4b,0x41,0x66,0x2b,0x45,0x71,
	0x4e,0x4c,0x34,0x41,0x58,0x79,0x39,0x66,0x72,0x35,0x51,0x71,0x31,0x53,0x65,0x66,
	0x52,0x70,0x2b,0x53,0x52,0x6c,0x34,0x65,0x44,0x48,0x79,0x34,0x67,0x65,0x48,0x6b,
	0x39,0x69,0x4a,0x75,0x43,0x43,0x43,0x34,0x54,0x33,0x4e,0x79,0x56,0x5a,0x4c,0x43,
	0x6d,0x56,0x44,0x68,0x77,0x2f,0x64,0x39,0x77,0x61,0x34,0x31,0x54,0x37,0x32,0x78,
	0x4b,0x4e,0x68,0x6e,0x6d,0x77,0x50,0x52,0x6f,0x4c,0x4b,0x63,0x69,0x4f,0x34,0x33,
	0x39,0x62,0x64,0x45,0x7a,0x32,0x67,0x5a,0x68,0x32,0x51,0x55,0x71,0x43,0x57,0x72,
	0x61,0x62,0x57,0x59,0x4a,0x79,0x59,0x55,0x6b,0x2f,0x42,0x43,0x47,0x52,0x4a,0x31,
	0x50,0x67,0x4a,0x64,0x66,0x4a,0x4f,0x66,0x6c,0x74,0x4f,0x37,0x64,0x4d,0x69,0x38,
	0x33,0x72,0x6c,0x73,0x6e,0x4a,0x7a,0x30,0x75,0x5a,0x2b,0x41,0x6d,0x77,0x61,0x4b,
	0x36,0x4c,0x76,0x53,0x54,0x35,0x37,0x75,0x76,0x44,0x57,0x4d,0x75,0x41,0x34,0x4c,
	0x75,0x35,0x72,0x32,0x49,0x36,0x6e,0x54,0x6e,0x74,0x2f,0x42,0x44,0x45,0x73,0x4b,
	0x5a,0x61,0x68,0x34,0x5a,0x30,0x68,0x5a,0x70,0x6d,0x32,0x78,0x39,0x71,0x4e,0x77,
	0x34,0x57,0x51,0x37,0x75,0x48,0x6c,0x6d,0x39,0x4e,0x4f,0x73,0x5a,0x4f,0x52,0x55,
	0x67,0x31,0x52,0x6c,0x78,0x45,0x79,0x59,0x7a,0x30,0x67,0x67,0x54,0x2f,0x4b,0x51,
	0x76,0x34,0x78,0x53,0x4c,0x51,0x4d,0x55,0x67,0x39,0x46,0x43,0x6b,0x48,0x66,0x71,
	0x4e,0x41,0x59,0x79,0x67,0x2f,0x49,0x55,0x2f,0x49,0x68,0x64,0x30,0x70,0x72,0x69,
	0x66,0x44,0x34,0x77,0x2f,0x6c,0x39,0x2f,0x31,0x41,0x39,0x45,0x53,0x56,0x31,0x65,
	0x6b,0x47,0x71,0x47,0x4b,0x34,0x62,0x54,0x6b,0x44,0x6d,0x33,0x4d,0x6b,0x70,0x4f,
	0x50,0x53,0x76,0x6c,0x75,0x44,0x6d,0x48,0x63,0x74,0x54,0x6b,0x54,0x64,0x5a,0x71,
	0x41,0x36,0x4a,0x77,0x2b,0x31,0x2f,0x67,0x69,0x36,0x71,0x4c,0x61,0x78,0x42,0x6b,
	0x6c,0x49,0x55,0x69,0x67,0x48,0x50,0x41,0x49,0x39,0x76,0x52,0x6e,0x79,0x75,0x61,
	0x33,0x65,0x6e,0x36,0x78,0x67,0x78,0x66,0x73,0x73,0x76,0x4b,0x4b,0x4e,0x4c,0x35,
	0x57,0x35,0x4a,0x43,0x6d,0x49,0x44,0x64,0x4a,0x37,0x48,0x54,0x50,0x45,0x79,0x32,
	0x54,0x6a,0x67,0x2f,0x63,0x6f,0x4e,0x78,0x41,0x6c,0x75,0x32,0x32,0x66,0x39,0x31,
	0x37,0x6f,0x6a,0x55,0x6a,0x62,0x51,0x63,0x4e,0x4e,0x66,0x64,0x36,0x55,0x69,0x41,
	0x4f,0x34,0x55,0x48,0x37,0x69,0x66,0x6c,0x62,0x73,0x43,0x39,0x4f,0x73,0x2f,0x79,
	0x58,0x62,0x6b,0x57,0x44,0x2b,0x4f,0x53,0x6b,0x68,0x55,0x36,0x63,0x41,0x31,0x58,
	0x6d,0x49,0x33,0x65,0x76,0x61,0x4a,0x6f,0x61,0x48,0x78,0x74,0x54,0x34,0x7a,0x37,
	0x69,0x53,0x31,0x4b,0x63,0x36,0x42,0x48,0x42,0x39,0x64,0x31,0x58,0x56,0x4e,0x77,
	0x4e,0x43,0x46,0x41,0x56,0x31,0x48,0x65,0x79,0x63,0x53,0x41,0x31,0x43,0x65,0x45,
	0x61,0x50,0x35,0x5a,0x56,0x74,0x6a,0x30,0x46,0x4c,0x79,0x57,0x73,0x30,0x47,0x57,
	0x53,0x36,0x39,0x4a,0x4e,0x77,0x70,0x55,0x69,0x41,0x67,0x66,0x4f,0x57,0x66,0x32,
	0x71,0x4b,0x69,0x48,0x6e,0x65,0x48,0x48,0x30,0x55,0x31,0x31,0x4a,0x74,0x4c,0x48,
	0x78,0x34,0x78,0x58,0x32,0x48,0x51,0x2b,0x34,0x75,0x7a,0x59,0x75,0x73,0x53,0x65,
	0x6c,0x71,0x36,0x68,0x48,0x48,0x50,0x46,0x5a,0x33,0x52,0x50,0x4d,0x2b,0x59,0x4f,
	0x64,0x4f,0x59,0x6d,0x48,0x79,0x34,0x34,0x78,0x45,0x42,0x2b,0x71,0x74,0x42,0x53,
	0x33,0x73,0x4f,0x42,0x65,0x72,0x68,0x4a,0x76,0x46,0x56,0x4e,0x57,0x73,0x51,0x49,
	0x4a,0x6c,0x6e,0x4e,0x52,0x59,0x74,0x49,0x43,0x6a,0x50,0x65,0x79,0x73,0x31,0x31,
	0x46,0x70,0x66,0x6a,0x78,0x6f,0x45,0x71,0x31,0x66,0x75,0x50,0x67,0x76,0x4e,0x71,
	0x53,0x2f,0x2f,0x31,0x5a,0x62,0x78,0x4d,0x73,0x7a,0x6e,0x73,0x39,0x49,0x56,0x67,
	0x44,0x2f,0x38,0x74,0x51,0x55,0x31,0x4e,0x78,0x76,0x47,0x4a,0x62,0x30,0x2f,0x67,
	0x46,0x51,0x39,0x47,0x38,0x2b,0x50,0x4d,0x33,0x6e,0x51,0x77,0x6a,0x53,0x68,0x44,
	0x69,0x48,0x4b,0x79,0x42,0x4b,0x34,0x78,0x4b,0x61,0x64,0x45,0x62,0x5a,0x4f,0x58,
	0x79,0x49,0x39,0x4a,0x55,0x68,0x43,0x54,0x66,0x35,0x65,0x57,0x34,0x6e,0x6b,0x31,
	0x65,0x4c,0x36,0x42,0x66,0x4b,0x34,0x50,0x64,0x72,0x35,0x65,0x55,0x32,0x78,0x62,
	0x58,0x33,0x79,0x5a,0x51,0x59,0x4b,0x76,0x6c,0x32,0x52,0x42,0x64,0x5a,0x41,0x45,
	0x52,0x2f,0x79,0x39,0x53,0x39,0x4b,0x41,0x45,0x46,0x31,0x52,0x54,0x6e,0x71,0x6e,
	0x4a,0x64,0x58,0x41,0x45,0x6a,0x56,0x67,0x42,0x52,0x73,0x30,0x72,0x59,0x52,0x36,
	0x61,0x6d,0x6d,0x43,0x65,0x59,0x4f,0x36,0x4c,0x77,0x61,0x4b,0x65,0x58,0x73,0x53,
	0x58,0x58,0x78,0x53,0x71,0x63,0x66,0x59,0x45,0x6e,0x4d,0x2f,0x4a,0x39,0x59,0x46,
	0x6a,0x45,0x69,0x79,0x57,0x4f,0x74,0x58,0x33,0x49,0x4e,0x6b,0x31,0x70,0x48,0x53,
	0x65,0x72,0x43,0x32,0x4b,0x52,0x63,0x37,0x61,0x50,0x72,0x38,0x68,0x57,0x76,0x72,
	0x45,0x2b,0x71,0x6b,0x58,0x47,0x68,0x43,0x6d,0x4c,0x4b,0x44,0x38,0x2b,0x36,0x45,
	0x49,0x61,0x36,0x42,0x68,0x4f,0x4e,0x39,0x52,0x4d,0x45,0x53,0x73,0x51,0x75,0x56,
	0x6e,0x33,0x43,0x41,0x72,0x75,0x61,0x55,0x50,0x48,0x2b,0x72,0x41,0x4a,0x38,0x4d,
	0x71,0x46,0x6b,0x4b,0x6c,0x73,0x6c,0x61,0x58,0x4f,0x54,0x6c,0x79,0x35,0x45,0x70,
	0x46,0x62,0x5a,0x61,0x35,0x52,0x6e,0x50,0x59,0x43,0x4f,0x36,0x4f,0x70,0x4d,0x6c,
	0x41,0x6e,0x6a,0x4d,0x56,0x41,0x3d,0x3d
	};
#endif

	char random[1024] = {
	0x0b,0x30,0x44,0x62,0x7c,0x22,0x1f,0x0d,0x05,0x67,0x2c,0x2a,0x39,0x21,0x46,0x08,
	0x50,0x66,0x34,0x37,0x0b,0x45,0x4b,0x38,0x32,0x06,0x7a,0x3e,0x7f,0x0c,0x40,0x18,
	0x6b,0x2d,0x60,0x4c,0x60,0x0c,0x23,0x43,0x3b,0x3e,0x1b,0x16,0x04,0x46,0x58,0x3f,
	0x40,0x6a,0x11,0x05,0x63,0x71,0x14,0x35,0x47,0x79,0x13,0x6f,0x6b,0x27,0x18,0x5b,
	0x48,0x27,0x3e,0x6f,0x15,0x33,0x4f,0x3e,0x5e,0x51,0x73,0x68,0x25,0x0f,0x06,0x5b,
	0x7c,0x72,0x75,0x3e,0x3f,0x1b,0x5c,0x6d,0x6a,0x39,0x7c,0x63,0x63,0x60,0x6c,0x7a,
	0x33,0x76,0x52,0x13,0x25,0x33,0x7d,0x65,0x23,0x27,0x11,0x06,0x06,0x47,0x71,0x1e,
	0x14,0x74,0x63,0x70,0x2d,0x15,0x27,0x18,0x51,0x06,0x05,0x33,0x11,0x2c,0x6b,0x00,
	0x2d,0x77,0x20,0x48,0x0d,0x73,0x51,0x45,0x25,0x7f,0x7f,0x35,0x26,0x2e,0x26,0x53,
	0x24,0x68,0x1e,0x0e,0x58,0x3a,0x59,0x50,0x56,0x37,0x5f,0x66,0x01,0x4c,0x5a,0x64,
	0x32,0x50,0x7b,0x6a,0x20,0x72,0x2b,0x1d,0x7e,0x43,0x7b,0x61,0x42,0x0b,0x61,0x73,
	0x24,0x79,0x3a,0x6b,0x4a,0x79,0x6e,0x09,0x0f,0x27,0x2d,0x0c,0x5e,0x32,0x4b,0x0d,
	0x79,0x46,0x39,0x21,0x0a,0x26,0x5f,0x3a,0x00,0x26,0x3f,0x13,0x2e,0x7e,0x50,0x2b,
	0x67,0x46,0x72,0x3f,0x3b,0x01,0x46,0x1b,0x0b,0x35,0x49,0x39,0x19,0x70,0x3d,0x02,
	0x41,0x0e,0x38,0x05,0x76,0x65,0x4f,0x31,0x6c,0x5e,0x17,0x04,0x15,0x36,0x26,0x64,
	0x34,0x14,0x17,0x7c,0x0e,0x0b,0x5b,0x55,0x53,0x6b,0x00,0x42,0x41,0x4f,0x02,0x5c,
	0x13,0x0a,0x2c,0x2c,0x3e,0x10,0x14,0x33,0x45,0x7c,0x7a,0x5a,0x31,0x61,0x39,0x08,
	0x22,0x6a,0x1e,0x0f,0x6f,0x1b,0x6c,0x13,0x5e,0x79,0x20,0x79,0x50,0x62,0x06,0x2c,
	0x76,0x17,0x04,0x2b,0x2a,0x75,0x1f,0x0c,0x37,0x4e,0x0f,0x7b,0x2d,0x34,0x75,0x60,
	0x31,0x74,0x2e,0x0a,0x4a,0x11,0x6c,0x49,0x25,0x01,0x3a,0x3d,0x22,0x1e,0x6d,0x18,
	0x51,0x78,0x2d,0x62,0x31,0x4c,0x50,0x40,0x17,0x4b,0x6f,0x22,0x00,0x7f,0x61,0x2a,
	0x34,0x3e,0x00,0x5f,0x2f,0x5f,0x2f,0x14,0x2a,0x55,0x27,0x1f,0x46,0x1f,0x12,0x46,
	0x5e,0x1e,0x0c,0x7c,0x38,0x01,0x61,0x64,0x76,0x22,0x6e,0x08,0x20,0x38,0x4f,0x73,
	0x72,0x55,0x12,0x42,0x19,0x50,0x61,0x43,0x77,0x7d,0x41,0x2e,0x35,0x4f,0x3d,0x31,
	0x28,0x58,0x67,0x1b,0x03,0x51,0x20,0x32,0x1c,0x08,0x6e,0x37,0x75,0x37,0x44,0x4f,
	0x68,0x19,0x07,0x64,0x14,0x28,0x25,0x2b,0x69,0x35,0x18,0x27,0x26,0x14,0x13,0x70,
	0x42,0x19,0x12,0x75,0x3e,0x02,0x5d,0x7c,0x13,0x1f,0x16,0x53,0x3b,0x74,0x48,0x3c,
	0x5e,0x39,0x6c,0x1c,0x1c,0x74,0x39,0x1f,0x00,0x1b,0x06,0x0a,0x68,0x3b,0x52,0x4f,
	0x1e,0x6e,0x3c,0x35,0x0c,0x38,0x0e,0x0b,0x3b,0x1a,0x76,0x23,0x29,0x53,0x1e,0x5f,
	0x41,0x0c,0x4b,0x0a,0x65,0x28,0x78,0x67,0x48,0x59,0x26,0x6d,0x31,0x76,0x23,0x70,
	0x61,0x64,0x3b,0x38,0x79,0x66,0x74,0x53,0x2c,0x64,0x64,0x54,0x03,0x54,0x65,0x44,
	0x4c,0x18,0x4f,0x48,0x20,0x4f,0x72,0x10,0x3f,0x0c,0x52,0x2d,0x03,0x14,0x03,0x51,
	0x42,0x10,0x77,0x6a,0x34,0x06,0x32,0x03,0x72,0x14,0x7c,0x08,0x5d,0x52,0x1a,0x62,
	0x7c,0x3e,0x30,0x7e,0x5f,0x7f,0x54,0x0f,0x44,0x49,0x5d,0x5e,0x10,0x6a,0x06,0x2b,
	0x06,0x53,0x10,0x39,0x37,0x32,0x4a,0x4e,0x3d,0x2b,0x65,0x38,0x39,0x07,0x72,0x54,
	0x64,0x4d,0x56,0x6a,0x03,0x22,0x70,0x7b,0x5f,0x60,0x0b,0x2a,0x0b,0x6b,0x10,0x64,
	0x14,0x05,0x22,0x00,0x73,0x40,0x23,0x5b,0x51,0x1f,0x2b,0x1a,0x5d,0x69,0x7a,0x46,
	0x0c,0x5f,0x32,0x4b,0x4a,0x28,0x52,0x79,0x5b,0x12,0x42,0x18,0x00,0x5d,0x27,0x31,
	0x53,0x3c,0x4c,0x36,0x4e,0x38,0x3f,0x72,0x03,0x71,0x02,0x5b,0x36,0x59,0x7f,0x75,
	0x6e,0x08,0x54,0x0d,0x34,0x1c,0x34,0x57,0x5d,0x69,0x48,0x00,0x3b,0x05,0x07,0x6e,
	0x27,0x65,0x6e,0x40,0x3d,0x3a,0x4f,0x72,0x5d,0x39,0x16,0x0f,0x63,0x12,0x12,0x15,
	0x3a,0x70,0x0d,0x57,0x18,0x0d,0x5e,0x3d,0x22,0x68,0x68,0x7c,0x6d,0x4f,0x0c,0x7b,
	0x09,0x2d,0x4a,0x73,0x20,0x47,0x07,0x57,0x75,0x5d,0x53,0x70,0x34,0x21,0x40,0x57,
	0x51,0x5e,0x49,0x44,0x00,0x54,0x27,0x04,0x68,0x7e,0x59,0x56,0x58,0x74,0x14,0x3c,
	0x16,0x33,0x41,0x16,0x4b,0x2f,0x49,0x37,0x0a,0x54,0x08,0x08,0x1f,0x39,0x67,0x76,
	0x28,0x28,0x07,0x1d,0x61,0x47,0x51,0x4d,0x75,0x26,0x52,0x47,0x47,0x0c,0x57,0x58,
	0x74,0x3e,0x62,0x6c,0x58,0x3a,0x44,0x1e,0x16,0x2e,0x21,0x1c,0x73,0x45,0x67,0x74,
	0x4f,0x33,0x66,0x0e,0x74,0x66,0x26,0x1f,0x2e,0x38,0x44,0x40,0x7e,0x2a,0x50,0x52,
	0x5e,0x43,0x01,0x7a,0x38,0x49,0x3c,0x55,0x4d,0x5a,0x44,0x08,0x26,0x59,0x4d,0x45,
	0x0b,0x48,0x0a,0x33,0x5e,0x4a,0x4d,0x75,0x16,0x17,0x63,0x46,0x01,0x2a,0x55,0x7b,
	0x0f,0x02,0x73,0x6a,0x4b,0x7f,0x75,0x65,0x3c,0x4c,0x33,0x39,0x6c,0x74,0x05,0x60,
	0x0f,0x7f,0x2d,0x41,0x4d,0x4d,0x46,0x71,0x09,0x6f,0x4f,0x60,0x15,0x0f,0x46,0x73,
	0x63,0x4c,0x5e,0x74,0x30,0x0d,0x28,0x43,0x08,0x72,0x32,0x04,0x2e,0x31,0x29,0x27,
	0x44,0x6d,0x13,0x17,0x48,0x0f,0x49,0x52,0x10,0x13,0x7f,0x17,0x16,0x62,0x79,0x35,
	0x78,0x3e,0x01,0x7c,0x2e,0x0f,0x76,0x3e,0x5e,0x53,0x6c,0x5b,0x5f,0x7c,0x19,0x41,
	0x02,0x2f,0x17,0x64,0x41,0x75,0x10,0x04,0x47,0x7c,0x3d,0x4b,0x52,0x00,0x10,0x5d,
	0x51,0x4e,0x7a,0x27,0x25,0x55,0x40,0x12,0x35,0x60,0x05,0x1b,0x34,0x2d,0x04,0x7a,
	0x6a,0x69,0x02,0x79,0x03,0x3a,0x2f,0x06,0x0a,0x79,0x7b,0x12,0x5d,0x7c,0x52,0x29,
	0x47,0x58,0x12,0x73,0x3f,0x27,0x56,0x05,0x0c,0x48,0x32,0x58,0x6b,0x57,0x5c,0x03,
	0x64,0x56,0x11,0x52,0x7a,0x30,0x36,0x29,0x17,0x3b,0x68,0x7a,0x7c,0x05,0x6b,0x6b,
	0x13,0x6a,0x24,0x5c,0x68,0x42,0x18,0x32,0x03,0x73,0x6e,0x04,0x21,0x2e,0x01,0x04,
	0x63,0x7d,0x44,0x41,0x12,0x31,0x0b,0x15,0x1f,0x70,0x00,0x2e,0x66,0x14,0x3c,0x7f,
	0x2b,0x00,0x1f,0x0c,0x28,0x59,0x0a,0x16,0x49,0x5a,0x5c,0x64,0x65,0x4b,0x11,0x29,
	0x15,0x36,0x5a,0x65,0x19,0x4f,0x60,0x23,0x3a,0x3a,0x13,0x25,0x02,0x78,0x4c,0x54
	};
  char b64_known[1369] = {
	0x43,0x7a,0x42,0x45,0x59,0x6e,0x77,0x69,0x48,0x77,0x30,0x46,0x5a,0x79,0x77,0x71,
	0x4f,0x53,0x46,0x47,0x43,0x46,0x42,0x6d,0x4e,0x44,0x63,0x4c,0x52,0x55,0x73,0x34,
	0x4d,0x67,0x5a,0x36,0x50,0x6e,0x38,0x4d,0x51,0x42,0x68,0x72,0x4c,0x57,0x42,0x4d,
	0x59,0x41,0x77,0x6a,0x51,0x7a,0x73,0x2b,0x47,0x78,0x59,0x45,0x52,0x6c,0x67,0x2f,
	0x51,0x47,0x6f,0x52,0x42,0x57,0x4e,0x78,0x46,0x44,0x56,0x48,0x65,0x52,0x4e,0x76,
	0x61,0x79,0x63,0x59,0x57,0x30,0x67,0x6e,0x50,0x6d,0x38,0x56,0x4d,0x30,0x38,0x2b,
	0x58,0x6c,0x46,0x7a,0x61,0x43,0x55,0x50,0x42,0x6c,0x74,0x38,0x63,0x6e,0x55,0x2b,
	0x50,0x78,0x74,0x63,0x62,0x57,0x6f,0x35,0x66,0x47,0x4e,0x6a,0x59,0x47,0x78,0x36,
	0x4d,0x33,0x5a,0x53,0x45,0x79,0x55,0x7a,0x66,0x57,0x55,0x6a,0x4a,0x78,0x45,0x47,
	0x42,0x6b,0x64,0x78,0x48,0x68,0x52,0x30,0x59,0x33,0x41,0x74,0x46,0x53,0x63,0x59,
	0x55,0x51,0x59,0x46,0x4d,0x78,0x45,0x73,0x61,0x77,0x41,0x74,0x64,0x79,0x42,0x49,
	0x44,0x58,0x4e,0x52,0x52,0x53,0x56,0x2f,0x66,0x7a,0x55,0x6d,0x4c,0x69,0x5a,0x54,
	0x4a,0x47,0x67,0x65,0x44,0x6c,0x67,0x36,0x57,0x56,0x42,0x57,0x4e,0x31,0x39,0x6d,
	0x41,0x55,0x78,0x61,0x5a,0x44,0x4a,0x51,0x65,0x32,0x6f,0x67,0x63,0x69,0x73,0x64,
	0x66,0x6b,0x4e,0x37,0x59,0x55,0x49,0x4c,0x59,0x58,0x4d,0x6b,0x65,0x54,0x70,0x72,
	0x53,0x6e,0x6c,0x75,0x43,0x51,0x38,0x6e,0x4c,0x51,0x78,0x65,0x4d,0x6b,0x73,0x4e,
	0x65,0x55,0x59,0x35,0x49,0x51,0x6f,0x6d,0x58,0x7a,0x6f,0x41,0x4a,0x6a,0x38,0x54,
	0x4c,0x6e,0x35,0x51,0x4b,0x32,0x64,0x47,0x63,0x6a,0x38,0x37,0x41,0x55,0x59,0x62,
	0x43,0x7a,0x56,0x4a,0x4f,0x52,0x6c,0x77,0x50,0x51,0x4a,0x42,0x44,0x6a,0x67,0x46,
	0x64,0x6d,0x56,0x50,0x4d,0x57,0x78,0x65,0x46,0x77,0x51,0x56,0x4e,0x69,0x5a,0x6b,
	0x4e,0x42,0x51,0x58,0x66,0x41,0x34,0x4c,0x57,0x31,0x56,0x54,0x61,0x77,0x42,0x43,
	0x51,0x55,0x38,0x43,0x58,0x42,0x4d,0x4b,0x4c,0x43,0x77,0x2b,0x45,0x42,0x51,0x7a,
	0x52,0x58,0x78,0x36,0x57,0x6a,0x46,0x68,0x4f,0x51,0x67,0x69,0x61,0x68,0x34,0x50,
	0x62,0x78,0x74,0x73,0x45,0x31,0x35,0x35,0x49,0x48,0x6c,0x51,0x59,0x67,0x59,0x73,
	0x64,0x68,0x63,0x45,0x4b,0x79,0x70,0x31,0x48,0x77,0x77,0x33,0x54,0x67,0x39,0x37,
	0x4c,0x54,0x52,0x31,0x59,0x44,0x46,0x30,0x4c,0x67,0x70,0x4b,0x45,0x57,0x78,0x4a,
	0x4a,0x51,0x45,0x36,0x50,0x53,0x49,0x65,0x62,0x52,0x68,0x52,0x65,0x43,0x31,0x69,
	0x4d,0x55,0x78,0x51,0x51,0x42,0x64,0x4c,0x62,0x79,0x49,0x41,0x66,0x32,0x45,0x71,
	0x4e,0x44,0x34,0x41,0x58,0x79,0x39,0x66,0x4c,0x78,0x51,0x71,0x56,0x53,0x63,0x66,
	0x52,0x68,0x38,0x53,0x52,0x6c,0x34,0x65,0x44,0x48,0x77,0x34,0x41,0x57,0x46,0x6b,
	0x64,0x69,0x4a,0x75,0x43,0x43,0x41,0x34,0x54,0x33,0x4e,0x79,0x56,0x52,0x4a,0x43,
	0x47,0x56,0x42,0x68,0x51,0x33,0x64,0x39,0x51,0x53,0x34,0x31,0x54,0x7a,0x30,0x78,
	0x4b,0x46,0x68,0x6e,0x47,0x77,0x4e,0x52,0x49,0x44,0x49,0x63,0x43,0x47,0x34,0x33,
	0x64,0x54,0x64,0x45,0x54,0x32,0x67,0x5a,0x42,0x32,0x51,0x55,0x4b,0x43,0x55,0x72,
	0x61,0x54,0x55,0x59,0x4a,0x79,0x59,0x55,0x45,0x33,0x42,0x43,0x47,0x52,0x4a,0x31,
	0x50,0x67,0x4a,0x64,0x66,0x42,0x4d,0x66,0x46,0x6c,0x4d,0x37,0x64,0x45,0x67,0x38,
	0x58,0x6a,0x6c,0x73,0x48,0x42,0x78,0x30,0x4f,0x52,0x38,0x41,0x47,0x77,0x59,0x4b,
	0x61,0x44,0x74,0x53,0x54,0x78,0x35,0x75,0x50,0x44,0x55,0x4d,0x4f,0x41,0x34,0x4c,
	0x4f,0x78,0x70,0x32,0x49,0x79,0x6c,0x54,0x48,0x6c,0x39,0x42,0x44,0x45,0x73,0x4b,
	0x5a,0x53,0x68,0x34,0x5a,0x30,0x68,0x5a,0x4a,0x6d,0x30,0x78,0x64,0x69,0x4e,0x77,
	0x59,0x57,0x51,0x37,0x4f,0x48,0x6c,0x6d,0x64,0x46,0x4d,0x73,0x5a,0x47,0x52,0x55,
	0x41,0x31,0x52,0x6c,0x52,0x45,0x77,0x59,0x54,0x30,0x67,0x67,0x54,0x33,0x49,0x51,
	0x50,0x77,0x78,0x53,0x4c,0x51,0x4d,0x55,0x41,0x31,0x46,0x43,0x45,0x48,0x64,0x71,
	0x4e,0x41,0x59,0x79,0x41,0x33,0x49,0x55,0x66,0x41,0x68,0x64,0x55,0x68,0x70,0x69,
	0x66,0x44,0x34,0x77,0x66,0x6c,0x39,0x2f,0x56,0x41,0x39,0x45,0x53,0x56,0x31,0x65,
	0x45,0x47,0x6f,0x47,0x4b,0x77,0x5a,0x54,0x45,0x44,0x6b,0x33,0x4d,0x6b,0x70,0x4f,
	0x50,0x53,0x74,0x6c,0x4f,0x44,0x6b,0x48,0x63,0x6c,0x52,0x6b,0x54,0x56,0x5a,0x71,
	0x41,0x79,0x4a,0x77,0x65,0x31,0x39,0x67,0x43,0x79,0x6f,0x4c,0x61,0x78,0x42,0x6b,
	0x46,0x41,0x55,0x69,0x41,0x48,0x4e,0x41,0x49,0x31,0x74,0x52,0x48,0x79,0x73,0x61,
	0x58,0x57,0x6c,0x36,0x52,0x67,0x78,0x66,0x4d,0x6b,0x74,0x4b,0x4b,0x46,0x4a,0x35,
	0x57,0x78,0x4a,0x43,0x47,0x41,0x42,0x64,0x4a,0x7a,0x46,0x54,0x50,0x45,0x77,0x32,
	0x54,0x6a,0x67,0x2f,0x63,0x67,0x4e,0x78,0x41,0x6c,0x73,0x32,0x57,0x58,0x39,0x31,
	0x62,0x67,0x68,0x55,0x44,0x54,0x51,0x63,0x4e,0x46,0x64,0x64,0x61,0x55,0x67,0x41,
	0x4f,0x77,0x55,0x48,0x62,0x69,0x64,0x6c,0x62,0x6b,0x41,0x39,0x4f,0x6b,0x39,0x79,
	0x58,0x54,0x6b,0x57,0x44,0x32,0x4d,0x53,0x45,0x68,0x55,0x36,0x63,0x41,0x31,0x58,
	0x47,0x41,0x31,0x65,0x50,0x53,0x4a,0x6f,0x61,0x48,0x78,0x74,0x54,0x77,0x78,0x37,
	0x43,0x53,0x31,0x4b,0x63,0x79,0x42,0x48,0x42,0x31,0x64,0x31,0x58,0x56,0x4e,0x77,
	0x4e,0x43,0x46,0x41,0x56,0x31,0x46,0x65,0x53,0x55,0x51,0x41,0x56,0x43,0x63,0x45,
	0x61,0x48,0x35,0x5a,0x56,0x6c,0x68,0x30,0x46,0x44,0x77,0x57,0x4d,0x30,0x45,0x57,
	0x53,0x79,0x39,0x4a,0x4e,0x77,0x70,0x55,0x43,0x41,0x67,0x66,0x4f,0x57,0x64,0x32,
	0x4b,0x43,0x67,0x48,0x48,0x57,0x46,0x48,0x55,0x55,0x31,0x31,0x4a,0x6c,0x4a,0x48,
	0x52,0x77,0x78,0x58,0x57,0x48,0x51,0x2b,0x59,0x6d,0x78,0x59,0x4f,0x6b,0x51,0x65,
	0x46,0x69,0x34,0x68,0x48,0x48,0x4e,0x46,0x5a,0x33,0x52,0x50,0x4d,0x32,0x59,0x4f,
	0x64,0x47,0x59,0x6d,0x48,0x79,0x34,0x34,0x52,0x45,0x42,0x2b,0x4b,0x6c,0x42,0x53,
	0x58,0x6b,0x4d,0x42,0x65,0x6a,0x68,0x4a,0x50,0x46,0x56,0x4e,0x57,0x6b,0x51,0x49,
	0x4a,0x6c,0x6c,0x4e,0x52,0x51,0x74,0x49,0x43,0x6a,0x4e,0x65,0x53,0x6b,0x31,0x31,
	0x46,0x68,0x64,0x6a,0x52,0x67,0x45,0x71,0x56,0x58,0x73,0x50,0x41,0x6e,0x4e,0x71,
	0x53,0x33,0x39,0x31,0x5a,0x54,0x78,0x4d,0x4d,0x7a,0x6c,0x73,0x64,0x41,0x56,0x67,
	0x44,0x33,0x38,0x74,0x51,0x55,0x31,0x4e,0x52,0x6e,0x45,0x4a,0x62,0x30,0x39,0x67,
	0x46,0x51,0x39,0x47,0x63,0x32,0x4e,0x4d,0x58,0x6e,0x51,0x77,0x44,0x53,0x68,0x44,
	0x43,0x48,0x49,0x79,0x42,0x43,0x34,0x78,0x4b,0x53,0x64,0x45,0x62,0x52,0x4d,0x58,
	0x53,0x41,0x39,0x4a,0x55,0x68,0x41,0x54,0x66,0x78,0x63,0x57,0x59,0x6e,0x6b,0x31,
	0x65,0x44,0x34,0x42,0x66,0x43,0x34,0x50,0x64,0x6a,0x35,0x65,0x55,0x32,0x78,0x62,
	0x58,0x33,0x77,0x5a,0x51,0x51,0x49,0x76,0x46,0x32,0x52,0x42,0x64,0x52,0x41,0x45,
	0x52,0x33,0x77,0x39,0x53,0x31,0x49,0x41,0x45,0x46,0x31,0x52,0x54,0x6e,0x6f,0x6e,
	0x4a,0x56,0x56,0x41,0x45,0x6a,0x56,0x67,0x42,0x52,0x73,0x30,0x4c,0x51,0x52,0x36,
	0x61,0x6d,0x6b,0x43,0x65,0x51,0x4d,0x36,0x4c,0x77,0x59,0x4b,0x65,0x58,0x73,0x53,
	0x58,0x58,0x78,0x53,0x4b,0x55,0x64,0x59,0x45,0x6e,0x4d,0x2f,0x4a,0x31,0x59,0x46,
	0x44,0x45,0x67,0x79,0x57,0x47,0x74,0x58,0x58,0x41,0x4e,0x6b,0x56,0x68,0x46,0x53,
	0x65,0x6a,0x41,0x32,0x4b,0x52,0x63,0x37,0x61,0x48,0x70,0x38,0x42,0x57,0x74,0x72,
	0x45,0x32,0x6f,0x6b,0x58,0x47,0x68,0x43,0x47,0x44,0x49,0x44,0x63,0x32,0x34,0x45,
	0x49,0x53,0x34,0x42,0x42,0x47,0x4e,0x39,0x52,0x45,0x45,0x53,0x4d,0x51,0x73,0x56,
	0x48,0x33,0x41,0x41,0x4c,0x6d,0x59,0x55,0x50,0x48,0x38,0x72,0x41,0x42,0x38,0x4d,
	0x4b,0x46,0x6b,0x4b,0x46,0x6b,0x6c,0x61,0x58,0x47,0x52,0x6c,0x53,0x78,0x45,0x70,
	0x46,0x54,0x5a,0x61,0x5a,0x52,0x6c,0x50,0x59,0x43,0x4d,0x36,0x4f,0x68,0x4d,0x6c,
	0x41,0x6e,0x68,0x4d,0x56,0x41,0x3d,0x3d,0x00
	};
	char *b64_test;

	plan_tests(1);

	base64_encode_alloc (random, 1024, &b64_test);

	ok(strcmp(b64_known, b64_test) == 0,
	   "Test matching a base64 encoded 1024 bytes random string");

	return exit_status();
}

