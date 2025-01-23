#include "it_handlers.h"
#include "main.h"
#include "init.h"

volatile uint8_t flag1, flag2, flag3, flag4, flag5, flag6, LedState;
volatile uint8_t flag1ON, flag2ON, flag3ON, flag4ON, flag5ON, flag6ON;
volatile uint8_t BtnCount1, BtnCount2, BtnCount3;
volatile uint16_t ledTime1, ledTime2, ledTime3, ledTime4, ledTime5, ledTime6;

volatile uint16_t GlobalTickCount;
volatile uint16_t dtime, cycleTime;
volatile uint8_t Button1Type;


void SysTick_Handler(void)
{

}
void EXTI4_IRQHandler(void)
{
    if (EXTI->PR & EXTI_PR_PR4) {
        EXTI->PR = EXTI_PR_PR4;
        Button1Type != Button1Type;
    }
}

void EXTI9_5_IRQHandler(void)
{
    if (EXTI->PR & EXTI_PR_PR5) {
        EXTI->PR = EXTI_PR_PR5;
    }

    if (EXTI->PR & EXTI_PR_PR6) {
        EXTI->PR = EXTI_PR_PR6;
    }
}
void User_Delay(uint32_t delay)
{

}