/***********************************************************************/
/*                                                                     */
/*  FILE        :180degree.c                                           */
/*  DATE        :Fri, May 27, 2022                                     */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :RX62T                                                 */
/*                                                                     */
/*  This file is generated by Renesas Project Generator (Ver.4.51).    */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/

#include <stdbool.h>
#include <stdint.h>
//#include "typedefine.h"
#ifdef __cplusplus
//#include <ios>                        // Remove the comment when you use ios
//_SINT ios_base::Init::init_cnt;       // Remove the comment when you use ios
#endif

void main(void);
#ifdef __cplusplus
extern "C"
{
    void abort(void);
}
#endif

// typedef union
// {
//     uint8_t b;
//     struct
//     {
//         unsigned h1 : 1;
//         unsigned h2 : 1;
//         unsigned h3 : 1;
//     };
// } test;
// test t;



bool temp;

int count = 0, state = 0, step = 0, time = 500, init_step[6] = {1, 3, 2, 5, 0, 4}, init_flag = 0, step_count = 0, frflag = 1;

uint8_t hall, h;

unsigned short duty = 800;

unsigned short duty_U[6] = {800, 800, 800, 1632, 1632, 1632},
               duty_V[6] = {1632, 1632, 800, 800, 800, 1632},
               duty_W[6] = {800, 1632, 1632, 1632, 800, 800};

void initmotor(void)
{
    init_flag = 0;
    time = 125;
    state = 1;
    R_PG_Timer_Start_CMT_U0_C0();
}

void forward(int target_time, int target_step)
{
    step_count = 0;
    frflag = 1;
    initmotor();
    while(!init_flag);
    state = 2;
    // for(step_count = 0; step_count < target_step; step_count++)
}

void main(void)
{
    R_PG_Clock_Set();
    R_PG_IO_PORT_Set_PA();
    R_PG_Timer_Set_MTU_U0_C3_C4();
    R_PG_Timer_ControlOutputPin_MTU_U0_C3_C4(1, 1, 1, 1, 1, 1);
    R_PG_Timer_SynchronouslyStartCount_MTU_U0(0, 0, 0, 1, 1, 0, 0);
    while (1)
    {
        R_PG_IO_PORT_Read_PA(&h);
        hall = ((h >> 2) & 0x07) - 1;
    }
}

void Mtu4IntFunc_V(void)
{
    R_PG_Timer_GetRequestFlag_MTU_U0_C3(0, 0, 0, 0, 0, 0, 0, 0);
    R_PG_Timer_GetRequestFlag_MTU_U0_C4(0, 0, 0, 0, 0, 0, 0, 0);

    count = (count < time) * count;
    step += (count >= (time - 1)) * frflag;         //frflag: forward = 1, reverse = -1
    step_count += (count >= (time - 1));
    step = (step <= 5) * (step >= 0) * step + (step < 0) * 5;        //step in 0 ~ 5

    if (state == 1)
    {
        R_PG_Timer_SetTGR_D_MTU_U0_C3(duty_U[init_step[hall]]);
        R_PG_Timer_SetTGR_C_MTU_U0_C4(duty_V[init_step[hall]]);
        R_PG_Timer_SetTGR_D_MTU_U0_C4(duty_W[init_step[hall]]);
		step = init_step[hall];
    }
    else if (state == 2)
    {
        count++;
        R_PG_Timer_SetTGR_D_MTU_U0_C3(duty_U[step]);
        R_PG_Timer_SetTGR_C_MTU_U0_C4(duty_V[step]);
        R_PG_Timer_SetTGR_D_MTU_U0_C4(duty_W[step]);
    }
    else
    {
        R_PG_Timer_SetTGR_D_MTU_U0_C3(1632);
        R_PG_Timer_SetTGR_C_MTU_U0_C4(1632);
        R_PG_Timer_SetTGR_D_MTU_U0_C4(1632);
    }
}

void Cmt0IntFunc(void)
{
    R_PG_Timer_HaltCount_CMT_U0_C0();
    init_flag = 1;
}

#ifdef __cplusplus
void abort(void)
{
}
#endif
