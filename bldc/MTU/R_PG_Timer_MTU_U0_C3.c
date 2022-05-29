/******************************************************************************
* DISCLAIMER

* This software is supplied by Renesas Electronics Corporation and is only 
* intended for use with Renesas products. No other uses are authorized.

* This software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws.

* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES
* REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, 
* INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
* PARTICULAR PURPOSE AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY 
* DISCLAIMED.

* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS 
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE 
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES 
* FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS 
* AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.

* Renesas reserves the right, without notice, to make changes to this 
* software and to discontinue the availability of this software.  
* By using this software, you agree to the additional terms and 
* conditions found by accessing the following link:
* http://www.renesas.com/disclaimer
******************************************************************************
* Copyright (C) 2010 Renesas Electronics Corporation.
* and Renesas Solutions Corporation. All rights reserved.
******************************************************************************
* File Name    : R_PG_Timer_MTU_U0_C3.c
* Version      : 1.00
* Device(s)    : 
* Tool-Chain   : 
* H/W Platform : 
* Description  : 
* Limitations  : 
******************************************************************************
* History : 28.05.2022 Version Description
*         :   
******************************************************************************/


/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "R_PG_Timer_MTU_U0_C3.h"


/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_Set_MTU_U0_C3_C4(void)
*
* Function Name: R_PG_Timer_Set_MTU_U0_C3_C4
*
* Description  : Set up the MTU
*
* Arguments    : None
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_MTU3_ControlUnit
*                   : R_MTU3_ControlUnit_load_defaults
*                   : R_MTU3_Create
*                   : R_MTU3_Create_load_defaults
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_Set_MTU_U0_C3_C4(void)
{
	bool res;
	R_MTU3_Create_structure create_params_1;
	R_MTU3_Create_structure create_params_2;
	R_MTU3_ControlUnit_structure control_params;

	R_MTU3_Create_load_defaults( &create_params_1 );

	create_params_1.data2 = PDL_MTU3_MODE_PWM_COMP3;
	create_params_1.data3 = PDL_MTU3_CLK_ICLK_DIV_1 | PDL_MTU3_CLK_RISING;
	create_params_1.data5 = PDL_MTU3_BUFFER_AC_ENABLE | PDL_MTU3_BUFFER_BD_ENABLE;
	create_params_1.data9 = 32;
	create_params_1.data10 = 1632;
	create_params_1.data11 = 3000;
	create_params_1.data12 = 1632;
	create_params_1.data13 = 3000;

	R_MTU3_Create_load_defaults( &create_params_2 );

	create_params_2.data2 = PDL_MTU3_MODE_NORMAL;
	create_params_2.data3 = PDL_MTU3_CLK_ICLK_DIV_1 | PDL_MTU3_CLK_RISING;
	create_params_2.data10 = 3000;
	create_params_2.data11 = 3000;
	create_params_2.data12 = 3000;
	create_params_2.data13 = 3000;
	create_params_2.func7 = Mtu4IntFunc_V;
	create_params_2.data21 = 15;

	R_MTU3_ControlUnit_load_defaults( &control_params );

	control_params.data3 = PDL_MTU3_CONTROL_CH_34 | PDL_MTU3_DEAD_TIME_ENABLE | PDL_MTU3_PWM_RS_COMP_ENABLE | PDL_MTU3_REGISTER_DEAD_TIME | PDL_MTU3_REGISTER_CYCLE_DATA | PDL_MTU3_REGISTER_CYCLE_BUFFER;
	control_params.data5 = PDL_MTU3_OUT_P_PHASE_ALL_DISABLE | PDL_MTU3_OUT_N_PHASE_ALL_DISABLE | PDL_MTU3_OUT_P_PHASE_1_LOW_HIGH | PDL_MTU3_OUT_N_PHASE_1_LOW_HIGH | PDL_MTU3_OUT_P_PHASE_2_LOW_HIGH | PDL_MTU3_OUT_N_PHASE_2_LOW_HIGH | PDL_MTU3_OUT_P_PHASE_3_LOW_HIGH | PDL_MTU3_OUT_N_PHASE_3_LOW_HIGH;
	control_params.data6 = PDL_MTU3_OUT_BUFFER_P_PHASE_1_HIGH | PDL_MTU3_OUT_BUFFER_N_PHASE_1_HIGH | PDL_MTU3_OUT_BUFFER_P_PHASE_2_HIGH | PDL_MTU3_OUT_BUFFER_N_PHASE_2_HIGH | PDL_MTU3_OUT_BUFFER_P_PHASE_3_HIGH | PDL_MTU3_OUT_BUFFER_N_PHASE_3_HIGH | PDL_MTU3_OUT_BUFFER_TRANSFER_BOTH;
	control_params.data8 = 32;
	control_params.data9 = 1600;
	control_params.data10 = 1600;

	res = R_MTU3_Create(
		3,
		&create_params_1
	);

	if( !res ){
		return res;
	}

	res = R_MTU3_Create(
		4,
		&create_params_2
	);

	if( !res ){
		return res;
	}

	return R_MTU3_ControlUnit(
		0,
		&control_params
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_StartCount_MTU_U0_C3(void)
*
* Function Name: R_PG_Timer_StartCount_MTU_U0_C3
*
* Description  : Start the MTU count
*
* Arguments    : None
*
* Return Value : true  : Resuming count succeeded.
*              : false : Resuming count failed.
*
* Calling Functions : R_MTU3_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_StartCount_MTU_U0_C3(void)
{
	R_MTU3_ControlChannel_structure parameters;

	parameters.data2 = PDL_MTU3_START;
	parameters.data3 = PDL_NO_DATA;
	parameters.data4 = PDL_NO_DATA;
	parameters.data5 = PDL_NO_DATA;
	parameters.data6 = PDL_NO_DATA;
	parameters.data7 = PDL_NO_DATA;
	parameters.data8 = PDL_NO_DATA;
	parameters.data9 = PDL_NO_DATA;
	parameters.data10 = PDL_NO_DATA;
	parameters.data11 = PDL_NO_DATA;
	parameters.data12 = PDL_NO_DATA;

	return R_MTU3_ControlChannel(
		3,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_StartCount_MTU_U0_C4(void)
*
* Function Name: R_PG_Timer_StartCount_MTU_U0_C4
*
* Description  : Start the MTU count
*
* Arguments    : None
*
* Return Value : true  : Resuming count succeeded.
*              : false : Resuming count failed.
*
* Calling Functions : R_MTU3_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_StartCount_MTU_U0_C4(void)
{
	R_MTU3_ControlChannel_structure parameters;

	parameters.data2 = PDL_MTU3_START;
	parameters.data3 = PDL_NO_DATA;
	parameters.data4 = PDL_NO_DATA;
	parameters.data5 = PDL_NO_DATA;
	parameters.data6 = PDL_NO_DATA;
	parameters.data7 = PDL_NO_DATA;
	parameters.data8 = PDL_NO_DATA;
	parameters.data9 = PDL_NO_DATA;
	parameters.data10 = PDL_NO_DATA;
	parameters.data11 = PDL_NO_DATA;
	parameters.data12 = PDL_NO_DATA;

	return R_MTU3_ControlChannel(
		4,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_HaltCount_MTU_U0_C3(void)
*
* Function Name: R_PG_Timer_HaltCount_MTU_U0_C3
*
* Description  : Halt the MTU count
*
* Arguments    : None
*
* Return Value : true  : Halting succeeded.
*              : false : Halting failed.
*
* Calling Functions : R_MTU3_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_HaltCount_MTU_U0_C3(void)
{
	R_MTU3_ControlChannel_structure parameters;

	parameters.data2 = PDL_MTU3_STOP;
	parameters.data3 = PDL_NO_DATA;
	parameters.data4 = PDL_NO_DATA;
	parameters.data5 = PDL_NO_DATA;
	parameters.data6 = PDL_NO_DATA;
	parameters.data7 = PDL_NO_DATA;
	parameters.data8 = PDL_NO_DATA;
	parameters.data9 = PDL_NO_DATA;
	parameters.data10 = PDL_NO_DATA;
	parameters.data11 = PDL_NO_DATA;
	parameters.data12 = PDL_NO_DATA;

	return R_MTU3_ControlChannel(
		3,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_HaltCount_MTU_U0_C4(void)
*
* Function Name: R_PG_Timer_HaltCount_MTU_U0_C4
*
* Description  : Halt the MTU count
*
* Arguments    : None
*
* Return Value : true  : Halting succeeded.
*              : false : Halting failed.
*
* Calling Functions : R_MTU3_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_HaltCount_MTU_U0_C4(void)
{
	R_MTU3_ControlChannel_structure parameters;

	parameters.data2 = PDL_MTU3_STOP;
	parameters.data3 = PDL_NO_DATA;
	parameters.data4 = PDL_NO_DATA;
	parameters.data5 = PDL_NO_DATA;
	parameters.data6 = PDL_NO_DATA;
	parameters.data7 = PDL_NO_DATA;
	parameters.data8 = PDL_NO_DATA;
	parameters.data9 = PDL_NO_DATA;
	parameters.data10 = PDL_NO_DATA;
	parameters.data11 = PDL_NO_DATA;
	parameters.data12 = PDL_NO_DATA;

	return R_MTU3_ControlChannel(
		4,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_GetCounterValue_MTU_U0_C3(uint16_t * counter_val)
*
* Function Name: R_PG_Timer_GetCounterValue_MTU_U0_C3
*
* Description  : Acquire the MTU counter value
*
* Arguments    : uint16_t * counter_val : The address of storage area for the counter value
*
* Return Value : true  : Acquisition succeeded.
*              : false : Acquisition failed.
*
* Calling Functions : R_MTU3_ReadChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_GetCounterValue_MTU_U0_C3(uint16_t * counter_val)
{
	if( counter_val == 0 ){ return false; }

	return R_MTU3_ReadChannel(
		3,
		PDL_NO_PTR,
		counter_val,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_GetCounterValue_MTU_U0_C4(uint16_t * counter_val)
*
* Function Name: R_PG_Timer_GetCounterValue_MTU_U0_C4
*
* Description  : Acquire the MTU counter value
*
* Arguments    : uint16_t * counter_val : The address of storage area for the counter value
*
* Return Value : true  : Acquisition succeeded.
*              : false : Acquisition failed.
*
* Calling Functions : R_MTU3_ReadChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_GetCounterValue_MTU_U0_C4(uint16_t * counter_val)
{
	if( counter_val == 0 ){ return false; }

	return R_MTU3_ReadChannel(
		4,
		PDL_NO_PTR,
		counter_val,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetCounterValue_MTU_U0_C3(uint16_t counter_val)
*
* Function Name: R_PG_Timer_SetCounterValue_MTU_U0_C3
*
* Description  : Set the MTU counter value
*
* Arguments    : uint16_t counter_val : Value to be set to the counter.
*
* Return Value : true  : Setting of the counter value succeeded.
*              : false : Setting of the counter value failed.
*
* Calling Functions : R_MTU3_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SetCounterValue_MTU_U0_C3(uint16_t counter_val)
{
	R_MTU3_ControlChannel_structure parameters;

	parameters.data2 = PDL_NO_DATA;
	parameters.data3 = PDL_MTU3_REGISTER_COUNTER;
	parameters.data4 = counter_val;
	parameters.data5 = PDL_NO_DATA;
	parameters.data6 = PDL_NO_DATA;
	parameters.data7 = PDL_NO_DATA;
	parameters.data8 = PDL_NO_DATA;
	parameters.data9 = PDL_NO_DATA;
	parameters.data10 = PDL_NO_DATA;
	parameters.data11 = PDL_NO_DATA;
	parameters.data12 = PDL_NO_DATA;

	return R_MTU3_ControlChannel(
		3,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetCounterValue_MTU_U0_C4(uint16_t counter_val)
*
* Function Name: R_PG_Timer_SetCounterValue_MTU_U0_C4
*
* Description  : Set the MTU counter value
*
* Arguments    : uint16_t counter_val : Value to be set to the counter.
*
* Return Value : true  : Setting of the counter value succeeded.
*              : false : Setting of the counter value failed.
*
* Calling Functions : R_MTU3_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SetCounterValue_MTU_U0_C4(uint16_t counter_val)
{
	R_MTU3_ControlChannel_structure parameters;

	parameters.data2 = PDL_NO_DATA;
	parameters.data3 = PDL_MTU3_REGISTER_COUNTER;
	parameters.data4 = counter_val;
	parameters.data5 = PDL_NO_DATA;
	parameters.data6 = PDL_NO_DATA;
	parameters.data7 = PDL_NO_DATA;
	parameters.data8 = PDL_NO_DATA;
	parameters.data9 = PDL_NO_DATA;
	parameters.data10 = PDL_NO_DATA;
	parameters.data11 = PDL_NO_DATA;
	parameters.data12 = PDL_NO_DATA;

	return R_MTU3_ControlChannel(
		4,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_GetTGR_MTU_U0_C3(uint16_t * tgr_a_val, uint16_t * tgr_b_val, uint16_t * tgr_c_val, uint16_t * tgr_d_val, uint16_t * tgr_e_val, uint16_t * tgr_f_val)
*
* Function Name: R_PG_Timer_GetTGR_MTU_U0_C3
*
* Description  : Acquire the MTU general register value
*
* Arguments    : uint16_t * tgr_a_val : The address of storage area for the general register A value
*              : uint16_t * tgr_b_val : The address of storage area for the general register B value
*              : uint16_t * tgr_c_val : The address of storage area for the general register C value
*              : uint16_t * tgr_d_val : The address of storage area for the general register D value
*              : uint16_t * tgr_e_val : The address of storage area for the general register E value
*              : uint16_t * tgr_f_val : The address of storage area for the general register F value
*
* Return Value : true  : Acquisition succeeded.
*              : false : Acquisition failed.
*
* Calling Functions : R_MTU3_ReadChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_GetTGR_MTU_U0_C3(uint16_t * tgr_a_val, uint16_t * tgr_b_val, uint16_t * tgr_c_val, uint16_t * tgr_d_val, uint16_t * tgr_e_val, uint16_t * tgr_f_val)
{
	uint16_t * local_a = PDL_NO_PTR;
	uint16_t * local_b = PDL_NO_PTR;
	uint16_t * local_c = PDL_NO_PTR;
	uint16_t * local_d = PDL_NO_PTR;
	uint16_t * local_e = PDL_NO_PTR;

	if( tgr_a_val ){
		local_a = tgr_a_val;
	}
	if( tgr_b_val ){
		local_b = tgr_b_val;
	}
	if( tgr_c_val ){
		local_c = tgr_c_val;
	}
	if( tgr_d_val ){
		local_d = tgr_d_val;
	}
	if( tgr_e_val ){
		local_e = tgr_e_val;
	}

	return R_MTU3_ReadChannel(
		3,
		PDL_NO_PTR,
		PDL_NO_PTR,
		local_a,
		local_b,
		local_c,
		local_d,
		local_e,
		PDL_NO_PTR
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_GetTGR_MTU_U0_C4(uint16_t * tgr_a_val, uint16_t * tgr_b_val, uint16_t * tgr_c_val, uint16_t * tgr_d_val, uint16_t * tgr_e_val, uint16_t * tgr_f_val)
*
* Function Name: R_PG_Timer_GetTGR_MTU_U0_C4
*
* Description  : Acquire the MTU general register value
*
* Arguments    : uint16_t * tgr_a_val : The address of storage area for the general register A value
*              : uint16_t * tgr_b_val : The address of storage area for the general register B value
*              : uint16_t * tgr_c_val : The address of storage area for the general register C value
*              : uint16_t * tgr_d_val : The address of storage area for the general register D value
*              : uint16_t * tgr_e_val : The address of storage area for the general register E value
*              : uint16_t * tgr_f_val : The address of storage area for the general register F value
*
* Return Value : true  : Acquisition succeeded.
*              : false : Acquisition failed.
*
* Calling Functions : R_MTU3_ReadChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_GetTGR_MTU_U0_C4(uint16_t * tgr_a_val, uint16_t * tgr_b_val, uint16_t * tgr_c_val, uint16_t * tgr_d_val, uint16_t * tgr_e_val, uint16_t * tgr_f_val)
{
	uint16_t * local_a = PDL_NO_PTR;
	uint16_t * local_b = PDL_NO_PTR;
	uint16_t * local_c = PDL_NO_PTR;
	uint16_t * local_d = PDL_NO_PTR;
	uint16_t * local_e = PDL_NO_PTR;
	uint16_t * local_f = PDL_NO_PTR;

	if( tgr_a_val ){
		local_a = tgr_a_val;
	}
	if( tgr_b_val ){
		local_b = tgr_b_val;
	}
	if( tgr_c_val ){
		local_c = tgr_c_val;
	}
	if( tgr_d_val ){
		local_d = tgr_d_val;
	}
	if( tgr_e_val ){
		local_e = tgr_e_val;
	}
	if( tgr_f_val ){
		local_f = tgr_f_val;
	}

	return R_MTU3_ReadChannel(
		4,
		PDL_NO_PTR,
		PDL_NO_PTR,
		local_a,
		local_b,
		local_c,
		local_d,
		local_e,
		local_f
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetTGR_A_MTU_U0_C3(uint16_t tgr_a_val)
*
* Function Name: R_PG_Timer_SetTGR_A_MTU_U0_C3
*
* Description  : Set the MTU general register value (TGRA)
*
* Arguments    : uint16_t tgr_a_val : Value to be set to the general register
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_MTU3_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SetTGR_A_MTU_U0_C3(uint16_t tgr_a_val)
{
	R_MTU3_ControlChannel_structure parameters;

	parameters.data2 = PDL_NO_DATA;
	parameters.data3 = PDL_MTU3_REGISTER_TGRA;
	parameters.data4 = PDL_NO_DATA;
	parameters.data5 = tgr_a_val;
	parameters.data6 = PDL_NO_DATA;
	parameters.data7 = PDL_NO_DATA;
	parameters.data8 = PDL_NO_DATA;
	parameters.data9 = PDL_NO_DATA;
	parameters.data10 = PDL_NO_DATA;
	parameters.data11 = PDL_NO_DATA;
	parameters.data12 = PDL_NO_DATA;

	return R_MTU3_ControlChannel(
		3,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetTGR_A_MTU_U0_C4(uint16_t tgr_a_val)
*
* Function Name: R_PG_Timer_SetTGR_A_MTU_U0_C4
*
* Description  : Set the MTU general register value (TGRA)
*
* Arguments    : uint16_t tgr_a_val : Value to be set to the general register
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_MTU3_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SetTGR_A_MTU_U0_C4(uint16_t tgr_a_val)
{
	R_MTU3_ControlChannel_structure parameters;

	parameters.data2 = PDL_NO_DATA;
	parameters.data3 = PDL_MTU3_REGISTER_TGRA;
	parameters.data4 = PDL_NO_DATA;
	parameters.data5 = tgr_a_val;
	parameters.data6 = PDL_NO_DATA;
	parameters.data7 = PDL_NO_DATA;
	parameters.data8 = PDL_NO_DATA;
	parameters.data9 = PDL_NO_DATA;
	parameters.data10 = PDL_NO_DATA;
	parameters.data11 = PDL_NO_DATA;
	parameters.data12 = PDL_NO_DATA;

	return R_MTU3_ControlChannel(
		4,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetTGR_B_MTU_U0_C3(uint16_t tgr_b_val)
*
* Function Name: R_PG_Timer_SetTGR_B_MTU_U0_C3
*
* Description  : Set the MTU general register value (TGRB)
*
* Arguments    : uint16_t tgr_b_val : Value to be set to the general register
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_MTU3_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SetTGR_B_MTU_U0_C3(uint16_t tgr_b_val)
{
	R_MTU3_ControlChannel_structure parameters;

	parameters.data2 = PDL_NO_DATA;
	parameters.data3 = PDL_MTU3_REGISTER_TGRB;
	parameters.data4 = PDL_NO_DATA;
	parameters.data5 = PDL_NO_DATA;
	parameters.data6 = tgr_b_val;
	parameters.data7 = PDL_NO_DATA;
	parameters.data8 = PDL_NO_DATA;
	parameters.data9 = PDL_NO_DATA;
	parameters.data10 = PDL_NO_DATA;
	parameters.data11 = PDL_NO_DATA;
	parameters.data12 = PDL_NO_DATA;

	return R_MTU3_ControlChannel(
		3,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetTGR_B_MTU_U0_C4(uint16_t tgr_b_val)
*
* Function Name: R_PG_Timer_SetTGR_B_MTU_U0_C4
*
* Description  : Set the MTU general register value (TGRB)
*
* Arguments    : uint16_t tgr_b_val : Value to be set to the general register
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_MTU3_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SetTGR_B_MTU_U0_C4(uint16_t tgr_b_val)
{
	R_MTU3_ControlChannel_structure parameters;

	parameters.data2 = PDL_NO_DATA;
	parameters.data3 = PDL_MTU3_REGISTER_TGRB;
	parameters.data4 = PDL_NO_DATA;
	parameters.data5 = PDL_NO_DATA;
	parameters.data6 = tgr_b_val;
	parameters.data7 = PDL_NO_DATA;
	parameters.data8 = PDL_NO_DATA;
	parameters.data9 = PDL_NO_DATA;
	parameters.data10 = PDL_NO_DATA;
	parameters.data11 = PDL_NO_DATA;
	parameters.data12 = PDL_NO_DATA;

	return R_MTU3_ControlChannel(
		4,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetTGR_C_MTU_U0_C3(uint16_t tgr_c_val)
*
* Function Name: R_PG_Timer_SetTGR_C_MTU_U0_C3
*
* Description  : Set the MTU general register value (TGRC)
*
* Arguments    : uint16_t tgr_c_val : Value to be set to the general register
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_MTU3_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SetTGR_C_MTU_U0_C3(uint16_t tgr_c_val)
{
	R_MTU3_ControlChannel_structure parameters;

	parameters.data2 = PDL_NO_DATA;
	parameters.data3 = PDL_MTU3_REGISTER_TGRC;
	parameters.data4 = PDL_NO_DATA;
	parameters.data5 = PDL_NO_DATA;
	parameters.data6 = PDL_NO_DATA;
	parameters.data7 = tgr_c_val;
	parameters.data8 = PDL_NO_DATA;
	parameters.data9 = PDL_NO_DATA;
	parameters.data10 = PDL_NO_DATA;
	parameters.data11 = PDL_NO_DATA;
	parameters.data12 = PDL_NO_DATA;

	return R_MTU3_ControlChannel(
		3,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetTGR_C_MTU_U0_C4(uint16_t tgr_c_val)
*
* Function Name: R_PG_Timer_SetTGR_C_MTU_U0_C4
*
* Description  : Set the MTU general register value (TGRC)
*
* Arguments    : uint16_t tgr_c_val : Value to be set to the general register
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_MTU3_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SetTGR_C_MTU_U0_C4(uint16_t tgr_c_val)
{
	R_MTU3_ControlChannel_structure parameters;

	parameters.data2 = PDL_NO_DATA;
	parameters.data3 = PDL_MTU3_REGISTER_TGRC;
	parameters.data4 = PDL_NO_DATA;
	parameters.data5 = PDL_NO_DATA;
	parameters.data6 = PDL_NO_DATA;
	parameters.data7 = tgr_c_val;
	parameters.data8 = PDL_NO_DATA;
	parameters.data9 = PDL_NO_DATA;
	parameters.data10 = PDL_NO_DATA;
	parameters.data11 = PDL_NO_DATA;
	parameters.data12 = PDL_NO_DATA;

	return R_MTU3_ControlChannel(
		4,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetTGR_D_MTU_U0_C3(uint16_t tgr_d_val)
*
* Function Name: R_PG_Timer_SetTGR_D_MTU_U0_C3
*
* Description  : Set the MTU general register value (TGRD)
*
* Arguments    : uint16_t tgr_d_val : Value to be set to the general register
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_MTU3_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SetTGR_D_MTU_U0_C3(uint16_t tgr_d_val)
{
	R_MTU3_ControlChannel_structure parameters;

	parameters.data2 = PDL_NO_DATA;
	parameters.data3 = PDL_MTU3_REGISTER_TGRD;
	parameters.data4 = PDL_NO_DATA;
	parameters.data5 = PDL_NO_DATA;
	parameters.data6 = PDL_NO_DATA;
	parameters.data7 = PDL_NO_DATA;
	parameters.data8 = tgr_d_val;
	parameters.data9 = PDL_NO_DATA;
	parameters.data10 = PDL_NO_DATA;
	parameters.data11 = PDL_NO_DATA;
	parameters.data12 = PDL_NO_DATA;

	return R_MTU3_ControlChannel(
		3,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetTGR_D_MTU_U0_C4(uint16_t tgr_d_val)
*
* Function Name: R_PG_Timer_SetTGR_D_MTU_U0_C4
*
* Description  : Set the MTU general register value (TGRD)
*
* Arguments    : uint16_t tgr_d_val : Value to be set to the general register
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_MTU3_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SetTGR_D_MTU_U0_C4(uint16_t tgr_d_val)
{
	R_MTU3_ControlChannel_structure parameters;

	parameters.data2 = PDL_NO_DATA;
	parameters.data3 = PDL_MTU3_REGISTER_TGRD;
	parameters.data4 = PDL_NO_DATA;
	parameters.data5 = PDL_NO_DATA;
	parameters.data6 = PDL_NO_DATA;
	parameters.data7 = PDL_NO_DATA;
	parameters.data8 = tgr_d_val;
	parameters.data9 = PDL_NO_DATA;
	parameters.data10 = PDL_NO_DATA;
	parameters.data11 = PDL_NO_DATA;
	parameters.data12 = PDL_NO_DATA;

	return R_MTU3_ControlChannel(
		4,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetBuffer_CycleData_MTU_U0_C3_C4(uint16_t tcbr_val)
*
* Function Name: R_PG_Timer_SetBuffer_CycleData_MTU_U0_C3_C4
*
* Description  : Set the MTU cycle buffer register value
*
* Arguments    : uint16_t tcbr_val : Value to be set to TCBRA/TCBRB
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_MTU3_ControlUnit
*                   : R_MTU3_ControlUnit_load_defaults
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SetBuffer_CycleData_MTU_U0_C3_C4(uint16_t tcbr_val)
{
	R_MTU3_ControlUnit_structure parameters;

	R_MTU3_ControlUnit_load_defaults( &parameters );

	parameters.data3 = PDL_MTU3_CONTROL_CH_34 | PDL_MTU3_REGISTER_CYCLE_BUFFER;
	parameters.data10 = tcbr_val;

	return R_MTU3_ControlUnit(
		0,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_GetRequestFlag_MTU_U0_C3(bool * cm_ic_a, bool * cm_ic_b, bool * cm_ic_c, bool * cm_ic_d, bool * cm_e, bool * cm_f, bool * ov, bool * un)
*
* Function Name: R_PG_Timer_GetRequestFlag_MTU_U0_C3
*
* Description  : Acquire and clear the MTU interrupt flag
*
* Arguments    : bool * cm_ic_a : The address of storage area for the compare match/input capture A flag.
*              : bool * cm_ic_b : The address of storage area for the compare match/input capture B flag.
*              : bool * cm_ic_c : The address of storage area for the compare match/input capture C flag.
*              : bool * cm_ic_d : The address of storage area for the compare match/input capture D flag.
*              : bool * cm_e : The address of storage area for the compare match/input capture E flag.
*              : bool * cm_f : The address of storage area for the compare match/input capture F flag.
*              : bool * ov : The address of storage area for the overflow flag.
*              : bool * un : The address of storage area for the underflow flag.
*
* Return Value : true  : Acquisition succeeded.
*              : false : Acquisition failed.
*
* Calling Functions : R_MTU3_ReadChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_GetRequestFlag_MTU_U0_C3(bool * cm_ic_a, bool * cm_ic_b, bool * cm_ic_c, bool * cm_ic_d, bool * cm_e, bool * cm_f, bool * ov, bool * un)
{
	uint8_t data;
	bool res;

	res = R_MTU3_ReadChannel(
		3,
		&data,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR
	);

	if( cm_ic_a ){
		*cm_ic_a = data & 0x01;
	}
	if( cm_ic_b ){
		*cm_ic_b = (data >> 1) & 0x01;
	}
	if( cm_ic_c ){
		*cm_ic_c = 0x00;
	}
	if( cm_ic_d ){
		*cm_ic_d = 0x00;
	}
	if( cm_e ){
		*cm_e = 0x00;
	}
	if( cm_f ){
		*cm_f = 0x00;
	}
	if( ov ){
		*ov = 0x00;
	}
	if( un ){
		*un = 0x00;
	}

	return res;
}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_GetRequestFlag_MTU_U0_C4(bool * cm_ic_a, bool * cm_ic_b, bool * cm_ic_c, bool * cm_ic_d, bool * cm_e, bool * cm_f, bool * ov, bool * un)
*
* Function Name: R_PG_Timer_GetRequestFlag_MTU_U0_C4
*
* Description  : Acquire and clear the MTU interrupt flag
*
* Arguments    : bool * cm_ic_a : The address of storage area for the compare match/input capture A flag.
*              : bool * cm_ic_b : The address of storage area for the compare match/input capture B flag.
*              : bool * cm_ic_c : The address of storage area for the compare match/input capture C flag.
*              : bool * cm_ic_d : The address of storage area for the compare match/input capture D flag.
*              : bool * cm_e : The address of storage area for the compare match/input capture E flag.
*              : bool * cm_f : The address of storage area for the compare match/input capture F flag.
*              : bool * ov : The address of storage area for the overflow flag.
*              : bool * un : The address of storage area for the underflow flag.
*
* Return Value : true  : Acquisition succeeded.
*              : false : Acquisition failed.
*
* Calling Functions : R_MTU3_ReadChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_GetRequestFlag_MTU_U0_C4(bool * cm_ic_a, bool * cm_ic_b, bool * cm_ic_c, bool * cm_ic_d, bool * cm_e, bool * cm_f, bool * ov, bool * un)
{
	uint8_t data;
	bool res;

	res = R_MTU3_ReadChannel(
		4,
		&data,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR
	);

	if( cm_ic_a ){
		*cm_ic_a = data & 0x01;
	}
	if( cm_ic_b ){
		*cm_ic_b = (data >> 1) & 0x01;
	}
	if( cm_ic_c ){
		*cm_ic_c = 0x00;
	}
	if( cm_ic_d ){
		*cm_ic_d = 0x00;
	}
	if( cm_e ){
		*cm_e = 0x00;
	}
	if( cm_f ){
		*cm_f = 0x00;
	}
	if( ov ){
		*ov = 0x00;
	}
	if( un ){
		*un = (data >> 6) &0x01;
	}

	return res;
}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_ControlOutputPin_MTU_U0_C3_C4(bool p1_enable, bool n1_enable, bool p2_enable, bool n2_enable, bool p3_enable, bool n3_enable)
*
* Function Name: R_PG_Timer_ControlOutputPin_MTU_U0_C3_C4
*
* Description  : Enable/Disable output pins
*
* Arguments    : bool p1_enable : Output setting for MTIOC3B/MTIOC6B (1: output is enabled  0: output is disabled)
*              : bool n1_enable : Output setting for MTIOC3D/MTIOC6D (1: output is enabled  0: output is disabled)
*              : bool p2_enable : Output setting for MTIOC4A/MTIOC7A (1: output is enabled  0: output is disabled)
*              : bool n2_enable : Output setting for MTIOC4C/MTIOC7C (1: output is enabled  0: output is disabled)
*              : bool p3_enable : Output setting for MTIOC4B/MTIOC7B (1: output is enabled  0: output is disabled)
*              : bool n3_enable : Output setting for MTIOC4D/MTIOC7D (1: output is enabled  0: output is disabled)
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_MTU3_ControlUnit
*                   : R_MTU3_ControlUnit_load_defaults
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_ControlOutputPin_MTU_U0_C3_C4(bool p1_enable, bool n1_enable, bool p2_enable, bool n2_enable, bool p3_enable, bool n3_enable)
{
	R_MTU3_ControlUnit_structure parameters;

	R_MTU3_ControlUnit_load_defaults( &parameters );

	parameters.data3 = PDL_MTU3_CONTROL_CH_34;

	if( p1_enable ){
		parameters.data5 = PDL_MTU3_OUT_P_PHASE_1_ENABLE;
	}
	else{
		parameters.data5 = PDL_MTU3_OUT_P_PHASE_1_DISABLE;
	}
	if( n1_enable ){
		parameters.data5 |= PDL_MTU3_OUT_N_PHASE_1_ENABLE;
	}
	else{
		parameters.data5 |= PDL_MTU3_OUT_N_PHASE_1_DISABLE;
	}
	
	if( p2_enable ){
		parameters.data5 |= PDL_MTU3_OUT_P_PHASE_2_ENABLE;
	}
	else{
		parameters.data5 |= PDL_MTU3_OUT_P_PHASE_2_DISABLE;
	}
	if( n2_enable ){
		parameters.data5 |= PDL_MTU3_OUT_N_PHASE_2_ENABLE;
	}
	else{
		parameters.data5 |= PDL_MTU3_OUT_N_PHASE_2_DISABLE;
	}
	
	if( p3_enable ){
		parameters.data5 |= PDL_MTU3_OUT_P_PHASE_3_ENABLE;
	}
	else{
		parameters.data5 |= PDL_MTU3_OUT_P_PHASE_3_DISABLE;
	}
	if( n3_enable ){
		parameters.data5 |= PDL_MTU3_OUT_N_PHASE_3_ENABLE;
	}
	else{
		parameters.data5 |= PDL_MTU3_OUT_N_PHASE_3_DISABLE;
	}

	return R_MTU3_ControlUnit(
		0,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetBuffer_PWMOutputLevel_MTU_U0_C3_C4(bool p1_high, bool n1_high, bool p2_high, bool n2_high, bool p3_high, bool n3_high)
*
* Function Name: R_PG_Timer_SetBuffer_PWMOutputLevel_MTU_U0_C3_C4
*
* Description  : Set the PWM output level in the buffer register
*
* Arguments    : bool p1_high : Output level on MTIOC3B/MTIOC6B (1: Initial Output/H Active Level/L  0: Initial Output/L Active Level/H)
*              : bool n1_high : Output level on MTIOC3D/MTIOC6D (1: Initial Output/H Active Level/L  0: Initial Output/L Active Level/H)
*              : bool p2_high : Output level on MTIOC4A/MTIOC7A (1: Initial Output/H Active Level/L  0: Initial Output/L Active Level/H)
*              : bool n2_high : Output level on MTIOC4C/MTIOC7C (1: Initial Output/H Active Level/L  0: Initial Output/L Active Level/H)
*              : bool p3_high : Output level on MTIOC4B/MTIOC7B (1: Initial Output/H Active Level/L  0: Initial Output/L Active Level/H)
*              : bool n3_high : Output level on MTIOC4D/MTIOC7D (1: Initial Output/H Active Level/L  0: Initial Output/L Active Level/H)
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_MTU3_ControlUnit
*                   : R_MTU3_ControlUnit_load_defaults
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SetBuffer_PWMOutputLevel_MTU_U0_C3_C4(bool p1_high, bool n1_high, bool p2_high, bool n2_high, bool p3_high, bool n3_high)
{
	R_MTU3_ControlUnit_structure parameters;

	R_MTU3_ControlUnit_load_defaults( &parameters );

	parameters.data3 = PDL_MTU3_CONTROL_CH_34;

	if( p1_high ){
		parameters.data6 = PDL_MTU3_OUT_BUFFER_P_PHASE_1_HIGH;
	}
	else{
		parameters.data6 = PDL_MTU3_OUT_BUFFER_P_PHASE_1_LOW;
	}
	if( n1_high ){
		parameters.data6 |= PDL_MTU3_OUT_BUFFER_N_PHASE_1_HIGH;
	}
	else{
		parameters.data6 |= PDL_MTU3_OUT_BUFFER_N_PHASE_1_LOW;
	}
	
	if( p2_high ){
		parameters.data6 |= PDL_MTU3_OUT_BUFFER_P_PHASE_2_HIGH;
	}
	else{
		parameters.data6 |= PDL_MTU3_OUT_BUFFER_P_PHASE_2_LOW;
	}
	if( n2_high ){
		parameters.data6 |= PDL_MTU3_OUT_BUFFER_N_PHASE_2_HIGH;
	}
	else{
		parameters.data6 |= PDL_MTU3_OUT_BUFFER_N_PHASE_2_LOW;
	}
	
	if( p3_high ){
		parameters.data6 |= PDL_MTU3_OUT_BUFFER_P_PHASE_3_HIGH;
	}
	else{
		parameters.data6 |= PDL_MTU3_OUT_BUFFER_P_PHASE_3_LOW;
	}
	if( n3_high ){
		parameters.data6 |= PDL_MTU3_OUT_BUFFER_N_PHASE_3_HIGH;
	}
	else{
		parameters.data6 |= PDL_MTU3_OUT_BUFFER_N_PHASE_3_LOW;
	}

	return R_MTU3_ControlUnit(
		0,
		&parameters
	);

}



