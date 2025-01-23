#include "it_handlers.h"
#include "main.h"
#include "init.h"


void SysTick_Handler(void)
{

}
void EXTI4_IRQHandler(void)
{
    if (EXTI->PR & EXTI_PR_PR4) {
        EXTI->PR = EXTI_PR_PR4;
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
    while (DelayTickCount < delay)
    {
    }
    if (DelayTickCount >= delay)
        DelayTickCount = 0;
}