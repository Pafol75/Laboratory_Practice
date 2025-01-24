#include "it_handlers.h"
#include "main.h"
#include "init.h"

volatile uint8_t Button1Type = 0, Button2Type = 0, Button3Type = 0;
volatile uint32_t initTime = 0, pastTime1 = 0, pastTime2 = 0, pastTime3 = 0;

void SysTick_Handler(void)
{
    initTime++;
}

void EXTI9_5_IRQHandler(void)
{
    if (EXTI->PR & EXTI_PR_PR5) {
        SET_BIT(EXTI->PR, EXTI_PR_PR5);

        if (initTime - pastTime1 > 200) {
            Button1Type++;
            if (Button1Type >= 3) {
                Button1Type = 0;
            }
            mode = Button1Type;
        }
        pastTime1 = initTime;
    }

    if (EXTI->PR & EXTI_PR_PR6) {
        SET_BIT(EXTI->PR, EXTI_PR_PR6);
        if (initTime - pastTime2 > 200) {
            Button2Type++;
            if (Button2Type >= 3) {
                Button2Type = 0;
            }
            if (mode == 0) {
                blinkFrequency = Button2Type;
            } else {
                blinkFrequencies[currentLED] = Button2Type;
            }
        }
        pastTime2 = initTime;
    }

    if (EXTI->PR & EXTI_PR_PR7) {
        SET_BIT(EXTI->PR, EXTI_PR_PR7);

        if (initTime - pastTime3 > 200) {
            Button3Type++;
            if (Button3Type >= 6) {
                Button3Type = 0;
            }
            currentLED = Button3Type;
        }
        pastTime3 = initTime;
    }
}