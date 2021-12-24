/*
 * This file is part of Cleanflight and Betaflight.
 *
 * Cleanflight and Betaflight are free software. You can redistribute
 * this software and/or modify this software under the terms of the
 * GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Cleanflight and Betaflight are distributed in the hope that they
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define MSP_TLM_INBUF_SIZE 128
#define MSP_TLM_OUTBUF_SIZE 128

// type of function to send MSP response chunk over telemetry.
typedef void (*mspResponseFnPtr)(uint8_t *payload, const uint8_t payloadSize);

void initSharedMsp(void);

// receives telemetry payload with msp and handles it.
bool handleMspFrame(uint8_t *const payload, uint8_t const payloadLength, uint8_t *const skipsBeforeResponse);

// sends MSP reply from previously handled msp-request over telemetry
bool sendMspReply(const uint8_t payloadSize_max, mspResponseFnPtr responseFn);
