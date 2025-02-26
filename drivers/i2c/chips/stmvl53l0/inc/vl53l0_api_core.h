/*******************************************************************************
Copyright � 2016, STMicroelectronics International N.V.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of STMicroelectronics nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND
NON-INFRINGEMENT OF INTELLECTUAL PROPERTY RIGHTS ARE DISCLAIMED.
IN NO EVENT SHALL STMICROELECTRONICS INTERNATIONAL N.V. BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

#ifndef _VL53L0_API_CORE_H_
#define _VL53L0_API_CORE_H_

#include "vl53l0_def.h"
#include "vl53l0_platform.h"


#ifdef __cplusplus
extern "C" {
#endif


VL53L0_Error VL53L0_reverse_bytes(uint8_t *data, uint32_t size);

VL53L0_Error VL53L0_measurement_poll_for_completion(VL53L0_DEV Dev);

uint8_t VL53L0_encode_vcsel_period(uint8_t vcsel_period_pclks);

uint8_t VL53L0_decode_vcsel_period(uint8_t vcsel_period_reg);

uint32_t VL53L0_isqrt(uint32_t num);

uint32_t VL53L0_quadrature_sum(uint32_t a, uint32_t b);

VL53L0_Error VL53L0_get_info_from_device(VL53L0_DEV Dev, uint8_t option);

VL53L0_Error VL53L0_set_vcsel_pulse_period(VL53L0_DEV Dev,
	VL53L0_VcselPeriod VcselPeriodType, uint8_t VCSELPulsePeriodPCLK);

VL53L0_Error VL53L0_get_vcsel_pulse_period(VL53L0_DEV Dev,
	VL53L0_VcselPeriod VcselPeriodType, uint8_t *pVCSELPulsePeriodPCLK);

uint32_t VL53L0_decode_timeout(uint16_t encoded_timeout);

VL53L0_Error get_sequence_step_timeout(VL53L0_DEV Dev,
			VL53L0_SequenceStepId SequenceStepId,
			uint32_t *pTimeOutMicroSecs);

VL53L0_Error set_sequence_step_timeout(VL53L0_DEV Dev,
			VL53L0_SequenceStepId SequenceStepId,
			uint32_t TimeOutMicroSecs);

VL53L0_Error VL53L0_set_measurement_timing_budget_micro_seconds(VL53L0_DEV Dev,
	uint32_t MeasurementTimingBudgetMicroSeconds);

VL53L0_Error VL53L0_get_measurement_timing_budget_micro_seconds(VL53L0_DEV Dev,
		uint32_t *pMeasurementTimingBudgetMicroSeconds);

VL53L0_Error VL53L0_load_tuning_settings(VL53L0_DEV Dev,
		uint8_t *pTuningSettingBuffer);

VL53L0_Error VL53L0_calc_sigma_estimate(VL53L0_DEV Dev,
		VL53L0_RangingMeasurementData_t *pRangingMeasurementData,
		FixPoint1616_t *pSigmaEstimate);

VL53L0_Error VL53L0_get_pal_range_status(VL53L0_DEV Dev,
		 uint8_t DeviceRangeStatus,
		 FixPoint1616_t SignalRate,
		 uint16_t EffectiveSpadRtnCount,
		 VL53L0_RangingMeasurementData_t *pRangingMeasurementData,
		 uint8_t *pPalRangeStatus);

uint32_t VL53L0_calc_timeout_mclks(VL53L0_DEV Dev,
	uint32_t timeout_period_us, uint8_t vcsel_period_pclks);

uint16_t VL53L0_encode_timeout(uint32_t timeout_macro_clks);

#ifdef __cplusplus
}
#endif

#endif /* _VL53L0_API_CORE_H_ */
