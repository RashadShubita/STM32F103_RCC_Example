/*******************************************************************************
 * @file    main.c
 * @author  Rashad Shubita
 * @email   shubitarashad@gmail.com
 * @date    20.01.2019
 *
 * @brief   main application called after startup
 * @note
 *
@verbatim
Copyright (C) 2019, Rashad Shubita

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or any later version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program.  If not, see <http://www.gnu.org/licenses/>.
@endverbatim
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "nvic.h"
#include "SysTick.h"
#include "gpio.h"
#include "exti.h"
#include "rcc.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
int main(void)
{
	SysTick_Init();
	NVIC_Init();

    GPIO_OnBoard_Init_LED();
    GPIO_External_LED_Init();
    GPIO_Init_PB();
    EXTI_Init_PB();
    RCC_ClockOut_Setup();


    /* Clear PRIMASK, enable IRQs */
    __enable_irq();

    /* Detect reset source */
    RCC_DetectResetSource();


 /* Infinite loop */
 while(1)
 {
	 RCC_ProcessReset();
 }

}


